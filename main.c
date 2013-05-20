/*
 * Ell-touch sample program. See README.md for more information.
 *
 * This program will loop for ever just reading a single capacitor
 * sensor as a a binary "is a touch present or not" mode and 
 * writing this status to a single binary output IO pin.
 *
 */


/*
 * Initialize the chip, set up the pins and so on
 *
 * Most of the really interesting stuff is in the standard library, CMSIS
 * so this is simple, calling the init routine with some select values
 * and naming our pins instead of using their standard names.
 *
 */
init();                                            /* From CMSIS I hope */
int_32t SENSOR_PIN;                                /* analog input */
int_32t OUTPUT_PIN;                                /* binary output */
int_32t DEBUG_PIN;                                 /* binary output */
int_32t debug_status = TRUE;                       /* toggle */
int_32t touch_input;                               /* */
int_32t touch_status;                              /* */
int_32t touch_level;                               /* */

/*
 * Loop for ever
 *
 * Note that this might end up rapidly changing the output pin
 * on and off as we have no hysteresis or history processing.
 *
 * DEBUG_PIN is purposefully being switched on and off every cycle
 * to facilitate debugging with an oscilloscope or logic analyser.
 *
 */
while (1) {
    /* Read from the sensor */
    touch_input = detect_touch(SENSOR_PIN);

    /* Determine whether this was a touch or not */
    if (touch_input < touch_level) {
        touch_status = 0;
    } else {
        touch_status = 1;
    }

    /* Switch the cycle indicator pin the other way */
    debug_status != debug_status;
    pin_out(DEBUG_PIN, debug_status);

    /* Write the result to the output pin */
    pin_out(OUTPUT_PIN, touch_status);
}
