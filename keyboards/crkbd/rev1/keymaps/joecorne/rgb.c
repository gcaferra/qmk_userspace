#pragma once

#ifdef RGBLIGHT_ENABLE
extern rgblight_config_t rgblight_config;
rgblight_config_t        RGB_current_config;
#endif

#ifdef RGB_MATRIX_ENABLE
extern rgb_config_t rgb_matrix_config;
rgb_config_t        RGB_current_config;
#endif

void save_rgb_config(void) {
#ifdef RGBLIGHT_ENABLE
    RGB_current_config.enable = rgblight_config.enable;
    RGB_current_config.mode   = rgblight_get_mode();
    RGB_current_config.speed  = rgblight_get_speed();
    RGB_current_config.hue    = rgblight_get_hue();
    RGB_current_config.sat    = rgblight_get_sat();
    RGB_current_config.val    = rgblight_get_val();
#endif
#ifdef RGB_MATRIX_ENABLE
    RGB_current_config.enable = rgb_matrix_config.enable;
    RGB_current_config.mode   = rgb_matrix_get_mode();
    RGB_current_config.speed  = rgb_matrix_config.speed;
    RGB_current_config.hsv    = rgb_matrix_config.hsv;
#endif
}

void restore_rgb_config(void) {
#ifdef RGBLIGHT_ENABLE
    rgblight_set_speed_noeeprom(RGB_current_config.speed);
    if (rgblight_config.mode != RGB_current_config.mode) {
        rgblight_mode_noeeprom(RGB_current_config.mode);
    }
    if ((RGB_current_config.hue != rgblight_config.hue) || (RGB_current_config.sat != rgblight_config.sat) || (RGB_current_config.val != rgblight_config.val)) {
        rgblight_sethsv_noeeprom(RGB_current_config.hue, RGB_current_config.sat, RGB_current_config.val);
    }
    if (rgblight_config.enable) {
        rgblight_enable_noeeprom();
    } else {
        rgblight_disable_noeeprom();
    }
#elif RGB_MATRIX_ENABLE
    rgb_matrix_config.speed   = RGB_current_config.speed;
    if (rgb_matrix_config.mode != RGB_current_config.mode) {
        rgb_matrix_mode_noeeprom(RGB_current_config.mode);
    }
    if ((RGB_current_config.hsv.h != rgb_matrix_config.hsv.h) || (RGB_current_config.hsv.s != rgb_matrix_config.hsv.s) || (RGB_current_config.hsv.v != rgb_matrix_config.hsv.v)) {
        rgb_matrix_sethsv_noeeprom(RGB_current_config.hsv.h, RGB_current_config.hsv.s, RGB_current_config.hsv.v);
    }
    if (rgb_matrix_config.enable) {
        rgb_matrix_enable_noeeprom();
    } else {
        rgb_matrix_disable_noeeprom();
    }
#endif
}

void rgb_by_layer(int layer) {
    switch (layer) {
        case _ADJUST:
            rgblight_sethsv_noeeprom(HSV_YELLOW);
            break;
        case _RAISE:
            rgblight_sethsv_noeeprom(HSV_CYAN);
            break;
        case _LOWER:
            rgblight_sethsv_noeeprom(HSV_MAGENTA);
            break;
        case _FUNC:
            rgblight_sethsv_noeeprom(HSV_GREEN);
            break;
        case _MOVES:
            rgblight_sethsv_noeeprom(HSV_WHITE);
            break;
        default:
            rgblight_sethsv_noeeprom(HSV_BLUE);
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    /* For any layer other than default, save current RGB state and switch to layer-based RGB */
    if (layer_state_cmp(state, 0)) {
        restore_rgb_config();
    } else {
        uint8_t layer = get_highest_layer(state);
        if (layer_state_cmp(layer_state, 0)) save_rgb_config();
        rgb_by_layer(layer);
    }
    return state;
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  }
  if(IS_LAYER_OFF(layer1) && IS_LAYER_OFF(layer2)) {
    layer_off(layer3);
  }
}
