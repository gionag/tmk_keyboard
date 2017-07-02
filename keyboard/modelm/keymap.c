/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/* 
 * Keymap for Macway mod
 */
#include <stdint.h>
#include <stdbool.h>
#include <avr/pgmspace.h>
#include "keycode.h"
#include "print.h"
#include "debug.h"
#include "util.h"
#include "keymap.h"


/*
 * Layout: 59key
 * ,-----------------------------------------------------------.
 * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  \|  `|
 * |-----------------------------------------------------------|
 * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]| BS  |
 * |-----------------------------------------------------------|
 * |Contro|  A|  S|  D|  F|  G|  H|  J|  K|  L|Fn3|  '|Return  |
 * |-----------------------------------------------------------|
 * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|Fn2|Shift     |
 * |-----------------------------------------------------------|
 * |Ctrl |   |Alt  |           Fn4             |Alt  |   |Fn1  |
 * `-----'   `---------------------------------------'   `-----'
 *
 * Matrix: 12x8
 *    |       0 |       1 |       2 |       3 |       4 |       5 |       6 |       7
 * ---+---------+---------+---------+---------+---------+---------+---------+---------
 *  0 |         |         | LCTRL   |         |         |         | RCTRL   |        
 *  1 |         | LSHIFT  |         |         |         |         | RSHIFT  |        
 *  2 |         | Tab     | Grave   | 1       | Q       | A       | Z       |        
 *  3 |         | Cpslck  |         | 2       | W       | S       | X       |        
 *  4 |         |         |         | 3       | E       | D       | C       |        
 *  5 | G       | T       | 5       | 4       | R       | F       | V       | B      
 *  6 |         | Bckspc  |         |         | Key*1   | Bckslsh | Enter   | Space  
 *  7 | H       | Y       | 6       | 7       | U       | J       | M       | N      
 *  8 |         | Rbrckt  | Equal   | 8       | I       | K       | Comma   |
 *  9 |         |         |         | 9       | O       | L       | Dot     |        
 *  A |         | Lbrckt  | Minus   | 0       | P       | Smcolon |         | Slash  
 *  B | LALT    |         |         |         |         |         |         | RALT   
 *  Key*1 This key locates between Equal and Backspace.
 *
 *  Original matrix here: http://geekhack.org/showthread.php?7767-Wireless-Model-M&p=133911&viewfull=1#post133911
 */
/*
#define KEYMAP( \
    K22, K23, K33, K43, K53, K52, K72, K73, K83, K93, KA3, KA2, K82, K64, K61, \
    K21, K24, K34, K44, K54, K51, K71, K74, K84, K94, KA4, KA1, K81, K65, \
    K31, K25, K35, K45, K55, K50, K70, K75, K85, K95, KA5, KA0, K66, \
    K11, K26, K36, K46, K56, K57, K77, K76, K86, K96, KA7, K16, \
    K02, KB0,      K67,      KB7, K06 \
) { \
    { KC_NO,    KC_NO,    KC_##K02, KC_NO,    KC_NO,    KC_NO,    KC_##K06, KC_NO    }, \
    { KC_NO,    KC_##K11, KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_##K16, KC_NO    }, \
    { KC_NO,    KC_##K21, KC_##K22, KC_##K23, KC_##K24, KC_##K25, KC_##K26, KC_NO    }, \
    { KC_NO,    KC_##K31, KC_NO,    KC_##K33, KC_##K34, KC_##K35, KC_##K36, KC_NO    }, \
    { KC_NO,    KC_NO,    KC_NO,    KC_##K43, KC_##K44, KC_##K45, KC_##K46, KC_NO    }, \
    { KC_##K50, KC_##K51, KC_##K52, KC_##K53, KC_##K54, KC_##K55, KC_##K56, KC_##K57 }, \
    { KC_NO,    KC_##K61, KC_NO,    KC_NO,    KC_##K64, KC_##K65, KC_##K66, KC_##K67 }, \
    { KC_##K70, KC_##K71, KC_##K72, KC_##K73, KC_##K74, KC_##K75, KC_##K76, KC_##K77 }, \
    { KC_NO,    KC_##K81, KC_##K82, KC_##K83, KC_##K84, KC_##K85, KC_##K86, KC_NO    }, \
    { KC_NO,    KC_NO,    KC_NO,    KC_##K93, KC_##K94, KC_##K95, KC_##K96, KC_NO    }, \
    { KC_##KA0, KC_##KA1, KC_##KA2, KC_##KA3, KC_##KA4, KC_##KA5, KC_NO,    KC_##KA7 }, \
    { KC_##KB0, KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_##KB7 }, \
}
*/


#define KEYMAP( \
    K5A,      K5B, K5C, K5D, K5E,   K5F, K5G, K5H, K5I,   K5J, K5K, K5L, K5M,   K5N, K5O, K5P, \
    \
    K4A, K4B, K4C, K4D, K4E, K4F, K4G, K4H, K4I, K4J, K4K, K4L, K4M, K4N,   K4O, K4P, K4Q,   K4R, K4S, K4T, K4U, \
    K3A, K3B, K3C, K3D, K3E, K3F, K3G, K3H, K3I, K3J, K3K, K3L, K3M, K3N,   K3O, K3P, K3Q,   K3R, K3S, K3T, K3U, \
    K2A, K2B, K2C, K2D, K2E, K2F, K2G, K2H, K2I, K2J, K2K, K2L, K2Q, K2M,                    K2N, K2O, K2P, \
    K1A, K1R, K1B, K1C, K1D, K1E, K1F, K1G, K1H, K1I, K1J, K1K, K1L,             K1M,        K1N, K1O, K1P, K1Q, \
    K0A, K0B, K0C, K0D, K0E,                                                K0F, K0G, K0H,   K0I,      K0J \
) { \
/* 00 */ { KC_NO,       KC_##K0E,   KC_NO,      KC_NO,      KC_NO,      KC_##K0A,   KC_NO,      KC_NO      }, \
/* 01 */ { KC_NO,       KC_##K1L,   KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_##K1A,   KC_NO      }, \
/* 02 */ { KC_NO,       KC_##K1B,   KC_##K2B,   KC_##K3B,   KC_##K4B,   KC_##K4A,   KC_##K3A,   KC_##K5A   }, \
/* 03 */ { KC_NO,       KC_##K1C,   KC_##K2C,   KC_##K3C,   KC_##K4C,   KC_##K5B,   KC_##K2A,   KC_##K1R   }, \
/* 04 */ { KC_NO,       KC_##K1D,   KC_##K2D,   KC_##K3D,   KC_##K4D,   KC_##K5C,   KC_##K5D,   KC_##K5E   }, \
/* 05 */ { KC_##K1F,    KC_##K1E,   KC_##K2E,   KC_##K3E,   KC_##K4E,   KC_##K4F,   KC_##K3F,   KC_##K2F   }, \
/* 06 */ { KC_##K0C,    KC_##K2M,   KC_##K3N,   KC_NO,      KC_##K5K,   KC_##K5J,   KC_##K4N,   KC_##K5F   }, \
/* 07 */ { KC_##K1G,    KC_##K1H,   KC_##K2H,   KC_##K3H,   KC_##K4H,   KC_##K4G,   KC_##K3G,   KC_##K2G   }, \
/* 08 */ { KC_NO,       KC_##K1I,   KC_##K2I,   KC_##K3I,   KC_##K4I,   KC_##K4M,   KC_##K3M,   KC_##K5G   }, \
/* 09 */ { KC_NO,       KC_##K1J,   KC_##K2J,   KC_##K3J,   KC_##K4J,   KC_##K5I,   KC_##K5H,   KC_NO      }, \
/* 0A */ { KC_##K1K,    KC_##K2Q,   KC_##K2K,   KC_##K3K,   KC_##K4K,   KC_##K4L,   KC_##K3L,   KC_##K2L   }, \
/* 0B */ { KC_##K0G,    KC_##K4R,   KC_##K1N,   KC_##K3R,   KC_##K5L,   KC_##K3O,   KC_##K2N,   KC_NO      }, \
/* 0C */ { KC_##K0H,    KC_##K4S,   KC_##K1O,   KC_##K3S,   KC_##K5M,   KC_##K4O,   KC_##K2O,   KC_##K0I   }, \
/* 0D */ { KC_##K4U,    KC_##K4T,   KC_##K1P,   KC_##K3T,   KC_##K3Q,   KC_##K4Q,   KC_##K2P,   KC_##K0J   }, \
/* 0E */ { KC_##K0F,    KC_##K5P,   KC_##K1Q,   KC_##K3U,   KC_##K3P,   KC_##K4P,   KC_NO,      KC_##K1M   }, \
/* 0F */ { KC_##K0D,    KC_NO,      KC_NO,      KC_##K5O,   KC_##K5N,   KC_NO,      KC_NO,      KC_##K0B   }  \
}   
/*         0            1           2           3           4           5           6           7       */



#define KEYCODE(layer, row, col) (pgm_read_byte(&keymaps[(layer)][(row)][(col)]))


// Assign Fn key(0-7) to a layer to which switch with the Fn key pressed.
static const uint8_t PROGMEM fn_layer[] = {
    0,              // Fn0
    1,              // Fn1
    2,              // Fn2
    3,              // Fn3
    4,              // Fn4
    0,              // Fn5
    0,              // Fn6
    0               // Fn7
};

// Assign Fn key(0-7) to a keycode sent when release Fn key without use of the layer.
// See layer.c for details.
static const uint8_t PROGMEM fn_keycode[] = {
    KC_NO,          // Fn0
    KC_NO,          // Fn1
    KC_SLSH,        // Fn2
    KC_SCLN,        // Fn3
    KC_SPC,         // Fn4
    KC_NO,          // Fn5
    KC_NO,          // Fn6
    KC_NO           // Fn7
};

static const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Layer-0:   
    KEYMAP(
        ESC,  F1, F2, F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, PSCR, SLCK, BRK,
        \
        GRV,  1,    2,   3,   4,   5,   6,   7,   8,   9,   0,    MINS, EQL, BSPC,     INS, HOME, PGUP,     NLCK,PSLS,PAST,PMNS,
        TAB,  Q,    W,   E,   R,   T,   Y,   U,   I,   O,   P,    LBRC, RBRC,BSLS,     DEL, END,  PGDN,     P7,  P8,  P9, PPLS,
        LGUI, A,    S,   D,   F,   G,   H,   J,   K,   L,   SCLN, QUOT, NUHS ,ENT,                          P4,  P5,  P6,
        LSFT, NUBS, Z,   X,   C,   V,   B,   N,   M,   COMM,DOT,  SLSH, RSFT,               UP,             P1,  P2,  P3, PENT,
        LCTL,    LALT,                  SPC,                      RALT,      RCTL,     LEFT,DOWN,RGHT,       P0,       PDOT
    ),

    // Layer-1 : mouse-overlay
    KEYMAP(
    ESC,  F1, F2, F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, PSCR, SLCK, BRK,
    \
    GRV,  1,    2,   3,   4,   5,   6,   7,   8,   9,   0,    MINS, EQL, BSPC,     INS, HOME, VOLU,     NLCK,PSLS,PAST,PMNS,
    TAB,  Q,    W,   E,   R,   T,   Y,   U,   I,   O,   P,    LBRC, RBRC,BSLS,     DEL, MUTE, VOLD,     BTN1,  MS_U,  P9, BTN3,
    LGUI, A,    S,   D,   F,   G,   H,   J,   K,   L,   SCLN, QUOT, NUHS ,ENT,                          MS_L,  MS_D,  MS_R,
    LSFT, NUBS, Z,   X,   C,   V,   B,   N,   M,   COMM,DOT,  SLSH, RSFT,               UP,             P1,  P2,  P3, PENT,
    LCTL,    LALT,                  SPC,                      RALT,      RCTL,     LEFT,DOWN,RGHT,       P0,       PDOT
    ),


};


uint8_t keymap_get_keycode(uint8_t layer, uint8_t row, uint8_t col)
{
    return KEYCODE(layer, row, col);
}

uint8_t keymap_fn_layer(uint8_t index)
{
    return pgm_read_byte(&fn_layer[index]);
}

uint8_t keymap_fn_keycode(uint8_t index)
{
    return pgm_read_byte(&fn_keycode[index]);
}

