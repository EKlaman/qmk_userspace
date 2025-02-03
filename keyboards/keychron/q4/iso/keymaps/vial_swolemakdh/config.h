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

/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

#define VIAL_KEYBOARD_UID {0x41, 0xF8, 0x47, 0xD0, 0xA8, 0x04, 0xAD, 0x7A}

#define VIAL_UNLOCK_COMBO_ROWS {0, 2}
#define VIAL_UNLOCK_COMBO_COLS {0, 13}
#define FORCE_NKRO

/* Set dynamic keymap layer counts to 5 */
#undef DYNAMIC_KEYMAP_LAYER_COUNT
#define DYNAMIC_KEYMAP_LAYER_COUNT 6
#undef VIAL_TAP_DANCE_ENTRIES
#define VIAL_TAP_DANCE_ENTRIES 32
#define TAPPING_TERM 200
#define TAPPING_TOGGLE 3

#ifdef RGB_MATRIX_ENABLE
#   define RGB_MATRIX_DISABLE_KEYCODES // disables control of rgb matrix by keycodes (must use code functions to control the feature)
#   define RGB_MATRIX_MAXIMUM_BRIGHTNESS 255    // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash.
#   define RGB_MATRIX_DEFAULT_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS // Sets the default brightness value, if none has been set
#   define RGB_MATRIX_HUE_STEP 16
#   define RGB_MATRIX_SAT_STEP 16
#   define RGB_MATRIX_VAL_STEP 32
#   define RGB_MATRIX_SPD_STEP 20
#   define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_COLOR
#   undef RGB_MATRIX_FRAMEBUFFER_EFFECTS
#   undef RGB_MATRIX_KEYPRESSES
//#   undef ENABLE_RGB_MATRIX_SOLID_COLOR
#   undef ENABLE_RGB_MATRIX_ALPHAS_MODS
#   undef ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#   undef ENABLE_RGB_MATRIX_BREATHING
#   undef ENABLE_RGB_MATRIX_BAND_SAT
#   undef ENABLE_RGB_MATRIX_BAND_VAL
#   undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#   undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#   undef ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#   undef ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#   undef ENABLE_RGB_MATRIX_CYCLE_ALL
#   undef ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#   undef ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#   undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#   undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#   undef ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#   undef ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#   undef ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#   undef ENABLE_RGB_MATRIX_DUAL_BEACON
#   undef ENABLE_RGB_MATRIX_RAINBOW_BEACON
#   undef ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#   undef ENABLE_RGB_MATRIX_RAINDROPS
#   undef ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#   undef ENABLE_RGB_MATRIX_TYPING_HEATMAP
#   undef ENABLE_RGB_MATRIX_DIGITAL_RAIN
#   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE
#   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#   undef ENABLE_RGB_MATRIX_SPLASH
#   undef ENABLE_RGB_MATRIX_MULTISPLASH
#   undef ENABLE_RGB_MATRIX_SOLID_SPLASH
#   undef ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
#   undef ENABLE_RGB_MATRIX_PIXEL_FLOW
#   undef ENABLE_RGB_MATRIX_PIXEL_FRACTAL
#   undef ENABLE_RGB_MATRIX_PIXEL_RAIN
#endif
