#include QMK_KEYBOARD_H
#include "keycodes.h"

extern uint8_t is_master;

#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
#    include "rgb.c"
#endif


#ifdef OLED_ENABLE
#    include "oled.c"
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_A,   ALT_S,   SFT_D,   CTL_F,    KC_G,                         KC_H,   CTL_J,   SFT_K,   ALT_L, KC_SCLN, KC_QUOT,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LGUI,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,KC_COMMA,  KC_DOT, KC_SLSH, KC_BSLS,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        MOVES,   LOWER,  KC_SPACE,     KC_ENT,   RAISE,    FUNC\
                                      //`--------------------------'  `--------------------------'
  ),

  [_LOWER] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                         KC_1,    KC_2,    KC_3,    KC_4,    KC_5, KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______ \
                                      //`--------------------------'  `--------------------------'
    ),

  [_RAISE] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_GRV, KC_PLUS, KC_MINS,   KC_DLR, KC_LBRC, KC_RBRC,                      _______, _______, _______, _______, _______, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_ASTR, KC_HASH, KC_EXLM,  KC_EQL, KC_LPRN, KC_RPRN,                      _______, _______, _______, _______, _______, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TILD, KC_PERC,  KC_AMP,   KC_AT, KC_LABK, KC_RABK,                      _______, _______, _______, _______, _______, _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_PIPE, KC_CIRC,    ALT_INS,    _______, _______, _______ \
                                      //`--------------------------'  `--------------------------'
  ),

 [_FUNC] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_F11,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      _______, _______, _______, _______, _______, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_F12,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                      _______, _______, _______, _______, _______, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_CAPS, CG_TOGG, KC_PSCR, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_MENU,  KC_INS, _______,    _______, _______, _______ \
                                      //`--------------------------'  `--------------------------'
    ),

 [_MOVES] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      _______, KC_HOME,   KC_UP,  KC_END, _______, KC_DEL,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, KC_LEFT, KC_DOWN,KC_RIGHT, _______, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, KC_PGUP, _______, KC_PGDN, _______, _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______ \
                                      //`--------------------------'  `--------------------------'
    ),


  [_ADJUST] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       BL_OFF,  RGBRST, XXXXXXX, XXXXXXX, XXXXXXX, BL_BRTG,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_M_R, RGB_M_K,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_M_X, RGB_M_G,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______ \
                                      //`--------------------------'  `--------------------------'
  ),

};




bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef OLED_ENABLE
if (record->event.pressed) {
    oled_timer = timer_read32();
    add_keylog(keycode);
    update_wpm(keycode);
  }
#endif
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
          set_single_persistent_default_layer(_QWERTY);
      }
      return false;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {

        layer_off(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
    case FUNC:
        if (record->event.pressed) {
          layer_on(_FUNC);
        } else {
          layer_off(_FUNC);
        }
        return false;
    case MOVES:
        if (record->event.pressed) {
          layer_on(_MOVES);
        } else {
          layer_off(_MOVES);
        }
        return false;
  }
  return true;
}


void matrix_scan_user(void) {
    decay_wpm();
}
