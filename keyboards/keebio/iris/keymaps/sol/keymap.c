#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _GAMING 1
#define _RGB 2
#define _PUNC 4
#define L2ESC LT(2,KC_ESC)
#define L3ENT LT(3,KC_ENT)

// Tap dancing page up/down.
enum {
    TD_PG,
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_PG] = ACTION_TAP_DANCE_DOUBLE(KC_PGDN, KC_PGUP),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINUS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     L2ESC,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L, LT(4,KC_SCLN),KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LALT,          _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴   ┬────┘        └───┬    ┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LCTL, KC_LGUI, _______,                   L3ENT,   KC_SPC,  MO(2)
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_GAMING] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, KC_SPC,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                     _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
                                // 
  ),

  [_RGB] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     RGB_VAI, RGB_HUI, RGB_SAI, RGB_TOG, _______, RESET,                              RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW,RGB_M_SN, RGB_M_K,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_VAD, RGB_HUD, RGB_SAD, _______, _______, _______,                            RGB_M_X, RGB_M_G, RGB_M_T, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, RGB_SPI, RGB_MOD, RGB_RMOD,_______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, RGB_SPD, KC_VOLD, KC_VOLU, KC_MNXT, KC_MPRV, TG(1),            _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                    _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
                                // 
  ),

  [3] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                              KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            KC_MUTE, KC_MPLY, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU, _______, KC_SLEP,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, KC_PGDN, KC_PGUP
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
  [_PUNC] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            KC_ASTR, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            KC_EQL,  KC_LPRN, KC_RPRN, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            KC_PLUS, KC_LCBR, KC_RCBR, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, KC_MINS, KC_LBRC, KC_RBRC, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                    _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
                                // 
  ),
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
}

// BACKLIGHT RGB LED GRID
//
//┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
// _______, _______, _______, _______,  _______,_______,                            _______, _______, _______, _______, _______, _______,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
//   LED2,  _______, _______,   LED1,  _______,   LED0,                               LED11, _______,   LED10, _______, _______,   LED9,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
// _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
//   LED3,  _______, _______,   LED4,  _______, _______, _______,          _______, _______, _______,   LED7,  _______, _______,   LED8,
//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
//                                _______,   LED5,  _______,                   _______,   LED6,  _______
                              // └────────┴────────┴────────┘                 └────────┴────────┴────────┘


// LED0-LED3 white for layer 1.
const rgblight_segment_t PROGMEM l1_rgb[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 3, HSV_RED}
);

// LED5 blue for layer 2.
const rgblight_segment_t PROGMEM l2_rgb[] = RGBLIGHT_LAYER_SEGMENTS(
    {5, 1, 170, 255, 140}
);

// LED6 red for layer 3.
const rgblight_segment_t PROGMEM l3_rgb[] = RGBLIGHT_LAYER_SEGMENTS(
    {6, 1, HSV_RED}
);

// LED9 pink for punctuation layer.
const rgblight_segment_t PROGMEM l4_rgb[] = RGBLIGHT_LAYER_SEGMENTS(
    {8, 2, 213, 200, 110}
);


const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    l1_rgb,
    l2_rgb,
    l3_rgb,
    l4_rgb
);

void keyboard_post_init_user(void) {
    rgblight_layers = rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _GAMING));
    rgblight_set_layer_state(1, layer_state_cmp(state, _RGB));
    rgblight_set_layer_state(2, layer_state_cmp(state, 3));
    rgblight_set_layer_state(3, layer_state_cmp(state, _PUNC));
    return state;
}
