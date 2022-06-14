/* Copyright 2020 tominabox1
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _NUMS 1
#define _SYMBS 2
#define _FUNCS 3
#define _ARROWS 4

enum custom_keycodes {
    LAYER0 = SAFE_RANGE,
    LAYER1,
    LAYER2,
    LAYER3,
    LAYER4,
};

// python3 gen.py -i ~/qmk_firmware/keyboards/kprepublic/bm40hsrgb/keymaps/lifan-zeng/keymap.c

/* QWERTY
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * │ Esc  │   Q  │   W  │   E  │   R  │   T  │   Y  │   U  │   I  │   O  │   P  │ Bksp │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Tab  │   A  │   S  │   D  │   F  │   G  │   H  │   J  │   K  │   L  │   ;  │Enter │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Shft │   Z  │   X  │   C  │   V  │   B  │   N  │   M  │   ,  │   .  │   /  │ Shft │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Ctrl │   4  │ Alt  │ Gui  │   1  │     Space   │      │   4  │ Down │  Up  │  Del │
 * └──────┴──────┴──────┴──────┴──────┴─────────────┴──────┴──────┴──────┴──────┴──────┘
 */

/* NUMS
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * │   `  │   1  │   2  │   3  │   4  │   5  │   6  │   7  │   8  │   9  │   0  │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │ Null │  -   │  +   │  =   │ Null │ Null │   4  │   5  │   6  │   :  │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │ Null │   /  │  *   │  (   │  )   │ Null │   1  │   2  │   3  │ Null │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │             |     3│   0  │   .  │   ,  │      │
 * └──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┘
 */

/* SYMBS
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * │  ~   │  !   │  @   │  #   │  $   │ Null │ Null │  %   │  ^   │  &   │  *   │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │  -   │  +   │  =   │ Null │ Null │   '  │  "   │  \   │  |   │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │  <   │  [   │  {   │  (   │ Null │ Null │  )   │  }   │  ]   │  >   │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │     3│             │      │      │ Null │ Null │      │
 * └──────┴──────┴──────┴──────┴──────┴─────────────┴──────┴──────┴──────┴──────┴──────┘
 */

/* FUNCS
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * │ Null │Ld Tog│ Ld M+│ Ld M-│ Ld H+│ Ld H-│ Ld S+│ Ld S-│ Ld V+│ Ld V-│Ld Sp+│Ld Sp-│
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │  F1  │  F2  │  F3  │  F4  │  F5  │  F6  │  F7  │  F8  │  F9  │  F10 │  F11 │  F12 │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Null │ Null │ Null │ Null │PrtScn│ Null │ Null │ Caps │ Null │ Null │LALT(KC F4│AG Swp│
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Reset│ Null │ Null │      │      │             │      │      │ Null │ Null │AG Nrm│
 * └──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┘
 */

/* ARROWS
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * │      │ Null │ Null │ Null │ Null │ Null │ Null │ PgUp │  Up  │ PgDn │ Null │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │ Null │ Prev │ Play │ Next │ Brt+ │ Null │ Left │ Down │ Right│ Null │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │ Null │ Mute │ Vol- │ Vol+ │ Brt- │ Null │ Home │  End │ Null │ Null │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      |             │      │      │      │      │      │
 * └──────┴──────┴──────┴──────┴──────┴─────────────┴──────┴──────┴──────┴──────┴──────┘
 */


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_planck_mit(
    KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, 
    KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, 
    KC_LCTL, MO(4), KC_LALT, KC_LGUI, MO(1), KC_SPC, MO(2), MO(4), KC_DOWN, KC_UP, KC_DEL
  ),

  [_NUMS] = LAYOUT_planck_mit(
    KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS, 
    KC_TRNS, XXXXXXX, KC_MINS, KC_PLUS, KC_EQL, XXXXXXX, XXXXXXX, KC_4, KC_5, KC_6, KC_SCLN, KC_TRNS, 
    KC_TRNS, XXXXXXX, KC_SLSH, KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX, KC_1, KC_2, KC_3, XXXXXXX, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(3), KC_0, KC_DOT, KC_COMM, KC_TRNS
  ),

  [_SYMBS] = LAYOUT_planck_mit(
    KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, XXXXXXX, XXXXXXX, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_TRNS, 
    KC_TRNS, KC_UNDS, KC_MINS, KC_PLUS, KC_EQL, XXXXXXX, XXXXXXX, KC_QUOT, KC_DQUO, KC_BSLS, KC_PIPE, KC_TRNS, 
    KC_TRNS, KC_LT, KC_LBRC, KC_LCBR, KC_LPRN, XXXXXXX, XXXXXXX, KC_RPRN, KC_RCBR, KC_RBRC, KC_GT, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(3), KC_TRNS, KC_TRNS, KC_TRNS, XXXXXXX, XXXXXXX, KC_TRNS
  ),

  [_FUNCS] = LAYOUT_planck_mit(
    XXXXXXX, RGB_TOG, RGB_MOD, RGB_RMOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, RGB_SPI, RGB_SPD, 
    KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, 
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, XXXXXXX, XXXXXXX, KC_CAPS, XXXXXXX, XXXXXXX, LALT(KC_F4), AG_SWAP, 
    RESET, XXXXXXX, XXXXXXX, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, XXXXXXX, XXXXXXX, AG_NORM
  ),

  [_ARROWS] = LAYOUT_planck_mit(
    KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGUP, KC_UP, KC_PGDN, XXXXXXX, KC_TRNS, 
    KC_TRNS, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, KC_BRIU, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, KC_TRNS, 
    KC_TRNS, XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, KC_BRID, XXXXXXX, KC_HOME, KC_END, XXXXXXX, XXXXXXX, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ) 

};

