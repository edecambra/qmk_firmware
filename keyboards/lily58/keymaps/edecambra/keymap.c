// Copyright 2022 Cole Smith <cole@boadsource.xyz>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "features/sentence_case.h"

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_sentence_case(keycode, record)) { return false; }
  // Your macros ...

  return true;
}

enum layers {
    _QWERTY,
    _NAVI,
    _NUMSYM,
    _ADJUST
};

#define NAVI MO(_NAVI)
#define NUMSYM MO(_NUMSYM)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  =  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                   |------+------+------+------+------+------|
 * | ESC |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|                   |------+------+------+------+------+------|
 * | Alt |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|enc vol    | enc pg|------+------+------+------+------+------|
 * |LCTRL|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_EQUAL, KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
  KC_ESC,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  KC_LALT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LCTL,  KC_Z,   MT(MOD_LGUI,KC_X),    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RCTL,
     KC_MS_BTN1,  KC_MS_BTN2, LT(NUMSYM, KC_TAB),MT(MOD_LSFT,KC_SPC),MT(MOD_RSFT,KC_BSPC),  LT(NAVI,KC_ENT),  KC_MS_BTN1,  MT(KC_LNUM,KC_MS_BTN2)
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   -  |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |   _  |   +  |   {  |   }  |   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \backsp\  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_NUMSYM] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, _______, KC_SLSH ,KC_ASTR, XXXXXXX, _______,
  KC_GRV,  KC_F2,   KC_F3,  C(S(KC_TAB)), C(KC_TAB),  XXXXXXX,            XXXXXXX,   KC_7,   KC_8,   KC_9,   KC_MINS,  _______,
  _______, KC_LCBR, KC_LBRC, KC_RBRC,  KC_RCBR,    XXXXXXX,               XXXXXXX,   KC_4,   KC_5,   KC_6,   KC_PLUS, XXXXXXX,
  _______, _______, _______, _______ , _______, _______, _______, _______, XXXXXXX,   KC_1,   KC_2,   KC_3,   KC_DOT, KC_ENTER,
                             _______, KC_LNUM, _______, _______, _______,  KC_0, _______, _______

),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |MOD   | MODR |  S+  |  S-  |  B+  |  B-  |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |-------.    ,-------|      | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+------|RGB_TOG|    |    ]  |------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  | F10  | F11  | F12  |-------|    |-------|   +  |   -  |   =  |   [  |   ]  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \backsp\  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |ccccccc
 *                   `----------------------------'           '------''--------------------'cc
 */

[_NAVI] = LAYOUT(
  RGB_MOD,   RGB_RMOD,RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD,                     _______, _______, _______, _______, _______, _______,
  KC_GRV,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______,   AC_TOGG, KC_F3,   KC_F4,   KC_F5,   KC_F6,                       KC_PGUP, KC_HOME, KC_UP, KC_END,  KC_INS, KC_F12,
  _______,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   RGB_TOG, _______,  KC_PGDN, KC_LEFT, KC_DOWN,  KC_RGHT,  KC_DEL,  _______,
                             _______, _______, _______,  _______, _______,  _______, KC_LNUM, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
   return update_tri_layer_state(state, _NUMSYM, _NAVI, _ADJUST);
}
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT(MOD_LSFT,KC_SPC):
            return TAPPING_TERM - 21;
        case MT(MOD_RSFT,KC_BSPC):
            return TAPPING_TERM - 10;
        default:
            return TAPPING_TERM;
    }
}
/*
#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [_QWERTY] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD),  ENCODER_CCW_CW(KC_PGDN,KC_PGUP) },
  [_NUMSYM]  = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD), ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
  [_NAVI]  = { ENCODER_CCW_CW(RGB_SAD, RGB_SAI),  ENCODER_CCW_CW(RGB_HUD, RGB_HUI) },
  [_ADJUST] = { ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______) }
};
#endif
*/
