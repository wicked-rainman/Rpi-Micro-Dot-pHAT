//-------------------------------------------------------------
// Code to write simple strings (maximum length of 6) to the
// micro dot Phat
//
// Results from i2cdetect -y 1
//     0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f
//00:          -- -- -- -- -- -- -- -- -- -- -- -- --
//10: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
//20: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
//30: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
//40: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
//50: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
//60: -- 61 62 63 -- -- -- -- -- -- -- -- -- -- -- --
//70: -- -- -- -- -- -- -- --
//
// Three IS31FL3730 chips, with two 5x7 LED arrays attached to
// each (i.e, 6 led Matrix in all)..
//-------------------------------------------------------------
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include "funcs.h"

int main() {
        int fd;
        fd = open("/dev/i2c-1", O_RDWR);
        if(fd<0) {
                fprintf(stderr,"Could not open the I2C device\n");
                exit(EXIT_FAILURE);
        }
        reset(fd);
	bright(fd,7);
        printstr(fd,"Wicked");
	update(fd);
        close(fd);
        exit(EXIT_SUCCESS);
}
