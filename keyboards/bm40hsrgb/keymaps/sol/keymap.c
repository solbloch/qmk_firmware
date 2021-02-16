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

enum layers {
  _QWERTY,
  _GAMING,
  _LOWER,
  _RAISE,
  _ADJUST,
  _PUNC
};

enum custom_keycodes{
  PAREN = SAFE_RANGE,
  CBRACE,
  SBRACE,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define CTL_ESC CTL_T(KC_ESC)
#define SPCLOW LT(2,KC_SPC)
#define ENTLOW LT(2,KC_ENT)
#define L5SCLN LT(5,KC_SCLN)
#define L2SHFT LM(2,MOD_LSFT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_planck_mit(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    L5SCLN,  KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
    L2SHFT,  MO(5),   LOWER,   KC_LGUI, KC_LALT,     KC_SPC,       ENTLOW,  RAISE,   KC_DOWN, KC_UP,   _______
),

[_GAMING] = LAYOUT_planck_mit(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,      KC_SPC,      _______, _______, _______, _______, _______
),

[_LOWER] = LAYOUT_planck_mit(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_MNXT, KC_MPRV, KC_VOLD, KC_VOLU, KC_MPLY, KC_MUTE,
    RESET,   _______, _______, _______, _______,      _______,     _______, _______, _______, _______, _______
),

[_RAISE] = LAYOUT_planck_mit(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, 
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    RESET,   _______, _______, _______, _______,      _______,     _______, _______, _______, _______, _______
),

[_ADJUST] = LAYOUT_planck_mit(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, KC_SLEP
),

[_PUNC] = LAYOUT_planck_mit(
    KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  _______, KC_EQL,  PAREN,   KC_RPRN, S(KC_MINS), _______, _______,
    _______, _______, _______, _______, _______, _______, KC_PLUS, CBRACE,  KC_RCBR, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_MINS, SBRACE,  KC_RBRC, _______, _______, _______,
    _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  switch (keycode) {
    case PAREN:
      if (record->event.pressed) {
        SEND_STRING("()" SS_TAP(X_LEFT));
      }
      break;
    case CBRACE:
      if (record->event.pressed) {
        SEND_STRING("{}" SS_TAP(X_LEFT));
      }
      break;
    case SBRACE:
      if (record->event.pressed) {
        SEND_STRING("[]" SS_TAP(X_LEFT));
      }
      break;
  }
  return true;
};
