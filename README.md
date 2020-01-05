# Rpi-Micro-Dot-pHAT
Example code for driving the Pimoroni Micro Dot pHAT using C.

See https://shop.pimoroni.com/products/microdot-phat?variant=25454635591

Provides the following:

reset(int f_discriptor)
Resets the display and puts it back into default mode.

update(int f_discriptor)
Updates the display with any characters that have been sent

bright(int f_discriptor, int display_current, int display_pwm)
Sets the LED brightness of the display

printstr(int f_discriptor, char *string)
Sends a string to the display for printing

printchar(int f_discriptor, int position, int char)
Sends a character to one of the 6 matrix displays
