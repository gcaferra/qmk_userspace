#include QMK_KEYBOARD_H

extern uint8_t is_master;


#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3
#define _FUNC 4
#define _MOVES 5

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  FUNC,
  MOVES,
  RGBRST
};

#define CTL_F CTL_T(KC_F)
#define SFT_D SFT_T(KC_D)
#define ALT_S ALT_T(KC_S)
#define CMD_G LCMD_T(KC_G)

#define CMD_H RCMD_T(KC_H)
#define CTL_J CTL_T(KC_J)
#define SFT_K SFT_T(KC_K)
#define ALT_L ALT_T(KC_L)

#define ALT_INS RALT(KC_INS)
#define KC_AMP LSFT(KC_7)

#define KC_UNDE LSFT(KC_MINS)



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
       KC_TAB,    KC_A,   ALT_S,   SFT_D,   CTL_F,  CMD_G ,                        CMD_H,   CTL_J,   SFT_K,   ALT_L, KC_SCLN, KC_QUOT,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      ALT_INS,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,KC_COMMA,  KC_DOT, KC_SLSH, KC_BSLS,\
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
      KC_GRV, KC_PLUS, KC_MINS ,  KC_EQL, KC_LBRC, KC_RBRC,                      KC_HASH, KC_BSLS,KC_COMMA, KC_DOT, KC_ASTR , KC_CIRC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_BSLS, KC_SLSH, KC_EXLM, KC_PIPE, KC_LPRN, KC_RPRN,                      _______, _______, _______, _______, KC_PERC, KC_TILD,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_UNDE,  KC_AT ,  KC_AMP,  KC_DLR, KC_LABK, KC_RABK,                      _______, _______, _______, _______, _______, _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______  , _______, _______,    _______, _______, _______ \
                                      //`--------------------------'  `--------------------------'
  ),

 [_FUNC] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_F1 , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,  KC_F6 ,                      _______, _______, _______, _______, _______, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_F7 , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,                      _______, _______, _______, _______, _______, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_CAPS, CG_TOGG, KC_PSCR, _______, KC_INS , KC_MENU,                      _______, _______, _______, _______, _______, _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______ \
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
      UG_PREV, UG_NEXT, XXXXXXX, XXXXXXX, XXXXXXX, _______,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      UG_TOGG, UG_HUEU, UG_SATU, UG_VALU, UG_SPDU, _______,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, UG_HUED, UG_SATD, UG_VALD, UG_SPDD, _______,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
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
        #ifdef RGBLIGHT_ENABLE
          update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
        #endif
      } else {
        layer_off(_LOWER);
        #ifdef RGBLIGHT_ENABLE
          update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
        #endif
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        #ifdef RGBLIGHT_ENABLE
          update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
        #endif
      } else {
        layer_off(_RAISE);
        #ifdef RGBLIGHT_ENABLE
          update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
        #endif
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
