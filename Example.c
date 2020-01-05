//-------------------------------------------------------------
// Code to write simple string (maximum length of 6) to the
// micro dot Phat. Anything after the 6th char in the string
// gets dropped.
//
// FYI Results from i2cdetect -y 1
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
//
// WR
//-------------------------------------------------------------
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include "funcs.h"

int main(int argc, char **argv) {
        int fd;
        //Open the display
        fd = open("/dev/i2c-1", O_RDWR);
        if(fd>=0) {
                //Reset the display to it's default state.
                reset(fd);
                //Set LED brightness, pwm=4, current=7
                bright(fd,4,7);
                //If argument not suppled, write default string
                if(argc ==1) {
                        printstr(fd,"Wicked");
                }
                //else write supplied string
                else {
                        printstr(fd,argv[1]);
                }
                //Update the display
                update(fd);
                //Close the display
                close(fd);
                exit(EXIT_SUCCESS);
        }
        else {
                fprintf(stderr,"Could not open the I2C device\n");
                exit(EXIT_FAILURE);
        }
}
