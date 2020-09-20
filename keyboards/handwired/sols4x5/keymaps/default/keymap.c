#include QMK_KEYBOARD_H

#define _G1 LGUI(KC_1)
#define _G2 LGUI(KC_2)
#define _G3 LGUI(KC_3)
#define _G4 LGUI(KC_4)
#define _G5 LGUI(KC_5)
#define _G6 LGUI(KC_6)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT(
  //┌────────┬────────┬────────┬────────┐
     _G1,     _G2,     _G3,     _G4,
  //├────────┼────────┼────────┼────────┤
     _G5 ,    _G6,     _______, _______,
  //├────────┼────────┼────────┼────────┤
     KC_MPLY, _______, _______, MO(1),
  //├────────┼────────┼────────┼────────┤
     KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU,
  //├────────┼────────┼────────┼────────┤
     KC_F13,  KC_F14,  _______, _______
  //└────────┴────────┴────────┴────────┘
  ),

  [1] = LAYOUT(
  //┌────────┬────────┬────────┬────────┐
     _______, _______, _______, RESET,
  //├────────┼────────┼────────┼────────┤
     _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┤
     _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┤
     _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┤
     _______, _______, _______, _______
  //└────────┴────────┴────────┴────────┘
  )
};

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {

}
