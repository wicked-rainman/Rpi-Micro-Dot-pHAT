void printchar(int fd, int x, int chr) {

        int i, y, z;
        char buf[7], reg;
        uint8_t cmd[2];
        uint8_t matrix;
        if(fd<0) return;
        reg = x % 2 ? 0x0e : 0x01;
        matrix=0x61+x/2;
        ioctl(fd, I2C_SLAVE,matrix);
        if(chr<33 || chr>126) return;
        chr=chr-33;
        if (x % 2) {
                // Odd numbered character out of the string
                for (i = 0, y = 7; i < 7; i++, y--)
                        buf[i] = 0;

                for (i = 0; i < 8; i++)
                        for (y = 0; y < 7; y++)
                                buf[i] |= font[chr][y] & (1 << i) ? 1 << y : 0;

                for (i = 0; i < 7; i++) {
                        cmd[0]=reg+i;
                        cmd[1]=buf[i];
                        write(fd, cmd, 2);
                }
        }
        else {
                // Even numbered character out of the string
                for (i = 0; i < 7; i++) {
                        cmd[0]=reg+i;
                        cmd[1]=font[chr][i];
                        write(fd, cmd, 2);
                }
        }
}
