#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xF7E0
#define PRODUCT_ID      0x0412
#define DEVICE_VER      0x0000
#define MANUFACTURER    SOLB
#define PRODUCT         SOL4X5
#define DESCRIPTION     Handwired 4x5

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 4

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
*/

// #define MATRIX_COL_PINS { C6, D3, D2, D1 }

#define MATRIX_ROW_PINS { B6, B5, B4, D7, D6 }
#define MATRIX_COL_PINS { D1, D2, D3, C6 }


/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5
