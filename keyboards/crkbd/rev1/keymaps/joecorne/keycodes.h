#pragma once

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3
#define _FUNC 4
#define _MOVES 5

enum custom_keycodes {
  QWERTY = QK_USER, // 100
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
