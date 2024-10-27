/* Copyright 2022 @ Keychron (https://www.keychron.com)
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
#include "keymap_swedish.h"

// clang-format off
bool user_led_enabled;
bool colemak_ovveride;
uint8_t default_layer; 
HSV hsv;


enum layers {
    WIN,
    SWOLEMAKDH,
    COLEMAKDH,
    _FN1,
    _FN2,
    _FN3
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [WIN] = LAYOUT_iso_62(
        KC_ESC,  KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,
        KC_TAB,  KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,
        KC_CAPS, KC_A,     KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,  KC_NUHS,  KC_ENT,
        KC_LSFT, KC_NUBS,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,            KC_RSFT,
        KC_LCTL, KC_LGUI,  KC_LALT,                            KC_SPC,                             KC_RALT,  MO(_FN1), MO(_FN2), TT(_FN3)),
    [SWOLEMAKDH] = LAYOUT_iso_62(
        KC_ESC,  KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_6,       KC_7,      KC_8,    KC_9,    KC_0,     SE_PLUS,  SE_ACUT,  KC_BSPC,
        KC_TAB,  KC_Q,     KC_W,    KC_F,    KC_P,    KC_B,    KC_J,       KC_L,      KC_U,    SE_ADIA, SE_ARNG,  SE_MINS,  SE_DIAE,
        KC_CAPS, KC_A,     KC_R,    KC_S,    KC_T,    KC_G,    KC_M,       KC_N,      KC_E,    KC_I,    KC_O,     KC_Y,     SE_QUOT,  KC_ENT,
        KC_LSFT, KC_Z,     KC_X,    KC_C,    KC_D,    KC_V,    KC_NUBS,    KC_K,      KC_H,    SE_COMM, SE_DOT,   SE_ODIA,            KC_RSFT,
        KC_LCTL, KC_LGUI,  KC_LALT,                            KC_SPC,                                  KC_RALT,  MO(_FN1), MO(_FN2), TT(_FN3)),
    [COLEMAKDH] = LAYOUT_iso_62(
        KC_ESC,  KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_6,       KC_7,      KC_8,    KC_9,    KC_0,     SE_PLUS,  SE_ACUT,  KC_BSPC,
        KC_TAB,  KC_Q,     KC_W,    KC_F,    KC_P,    KC_B,    KC_J,       KC_L,      KC_U,    KC_Y,    KC_LBRC,  KC_RBRC,  KC_NUBS,
        KC_CAPS, KC_A,     KC_R,    KC_S,    KC_T,    KC_G,    KC_M,       KC_N,      KC_E,    KC_I,    KC_O,     KC_SCLN,  KC_QUOT,  KC_ENT,
        KC_LSFT, KC_Z,     KC_X,    KC_C,    KC_D,    KC_V,    KC_NUBS,    KC_K,      KC_H,    KC_COMM, KC_DOT,   KC_SLASH,           KC_RSFT,
        KC_LCTL, KC_LGUI,  KC_LALT,                            KC_SPC,                                  KC_RALT,  MO(_FN1), MO(_FN2), TT(_FN3)),

    [_FN1] = LAYOUT_iso_62(
        SE_ACUT, KC_BRID, KC_BRIU, _______, _______,  _______, _______, _______, _______, _______, KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_DEL,
        _______, _______, _______, _______, _______,  _______, _______, _______, KC_APP,  KC_SCRL, KC_INS,   KC_HOME,  KC_PGUP,
        NK_TOGG, _______, _______, _______, _______,  _______, _______, _______, KC_UP,   _______, KC_PSCR,  KC_END,   KC_PGDN,  _______,
        _______, _______, _______, _______, _______,  KC_MPRV, KC_MNXT, _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______,            _______,
        _______, _______, _______,                             KC_MPLY,                            _______,  _______,  _______,  _______),

    [_FN2] = LAYOUT_iso_62(
        KC_TILD, KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______,
        RGB_TOG, RGB_VAI,  _______, KC_MS_U, _______, _______, _______, _______, _______, _______, KC_WH_U,  KC_BTN3,  _______,
        _______, RGB_VAD,  KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, _______, _______, _______, KC_WH_D,  KC_BTN1,  KC_BTN2,  _______,
        _______, _______,  _______, KC_ACL0, KC_ACL1, _______, _______, _______, _______, _______, _______,  _______,            _______,
        _______, _______,  _______,                            _______,                            _______,  _______,  _______,  _______),

    [_FN3] = LAYOUT_iso_62(
        _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______,  _______,
        _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______,  _______,
        _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, KC_UP,             _______,
        _______, _______, _______,                             _______,                            KC_LEFT, KC_DOWN, KC_RIGHT, _______)
};


// [Post Init] --------------------------------------------------------------//
void keyboard_post_init_user(void) {
    default_layer = eeconfig_read_default_layer();
    // Set RGB to known state
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(212,200,rgb_matrix_config.hsv.v); 
    rgb_matrix_enable_noeeprom();
    user_led_enabled = true;
}

void rgb_hsv_update_user(void) {
    rgb_matrix_sethsv_noeeprom(rgb_matrix_config.hsv.h, rgb_matrix_config.hsv.s, rgb_matrix_config.hsv.v);
}

// [Process User Input] ------------------------------------------------------//
bool process_record_user(uint16_t keycode, keyrecord_t * record) {
    switch (keycode) {
        case RGB_VAI:
            if (record -> event.pressed) {
                if ((RGB_MATRIX_MAXIMUM_BRIGHTNESS - rgb_matrix_get_val()) >= RGB_MATRIX_VAL_STEP) {
                    rgb_matrix_config.hsv.v += RGB_MATRIX_VAL_STEP;
                }
                else if (rgb_matrix_get_val() == 0){
                     rgb_matrix_config.hsv.v += (RGB_MATRIX_VAL_STEP - 1);
                }
                else {
                    rgb_matrix_config.hsv.v = RGB_MATRIX_MAXIMUM_BRIGHTNESS;
                }
                rgb_hsv_update_user();
            }
            return false;
        case RGB_VAD:
            if (record -> event.pressed) {
                if (rgb_matrix_get_val() >= RGB_MATRIX_VAL_STEP) {
                    rgb_matrix_config.hsv.v -= RGB_MATRIX_VAL_STEP;
                }
                else {
                    rgb_matrix_config.hsv.v = 0;
                }
                rgb_hsv_update_user();
            }
            return false;
        // Handle RGB Changes sans eeprom - necessary due to the layer dependent RGB color changes in matrix_scan_user
        case RGB_TOG:
            if (record -> event.pressed) {
                // Toggle matrix on key press
                user_led_enabled ? rgb_matrix_disable_noeeprom() : rgb_matrix_enable_noeeprom();
                // Toggle boolean flag
                user_led_enabled = !user_led_enabled;
            }
            return false;
        default:
            // Use process_record_keymap to reset timer on all other keypresses to awaken from idle.
            if (record -> event.pressed) {
                // Restore LEDs if they are enabled by user
                if (user_led_enabled) {
                    rgb_matrix_enable_noeeprom();
                }
            }
            return true;
    }
}


layer_state_t layer_state_set_user(layer_state_t state) {
    default_layer = eeconfig_read_default_layer();
    switch (get_highest_layer(state)) {
        case _FN1:
            rgb_matrix_sethsv_noeeprom(0,255,rgb_matrix_config.hsv.v);
            break;
        case _FN2:
            rgb_matrix_sethsv_noeeprom(86,200,rgb_matrix_config.hsv.v);
            break;
        case _FN3:
            rgb_matrix_sethsv_noeeprom(170,255,rgb_matrix_config.hsv.v);
            break;
        default:
            rgb_matrix_sethsv_noeeprom(212,200,rgb_matrix_config.hsv.v);
            break;
    }
    return state;  
}
// clang-format on

/*
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keychron(keycode, record)) {
        return false;
    }

    return true;
}
*/
