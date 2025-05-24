/* Copyright 2023 @ Keychron (https://www.keychron.com)
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
    MAC_BASE,
    WIN_BASE,
    MAC_FN,
    WIN_FN,
    L_FN1,
};

enum custom_keycodes { WIN_TAB = SAFE_RANGE, WIN_E, ALT_F4 };

// Define your combo keys
const uint16_t PROGMEM combo_win_tab[] = {MO(L_FN1), KC_TAB, COMBO_END};
const uint16_t PROGMEM combo_win_e[]   = {MO(L_FN1), KC_E, COMBO_END};
const uint16_t PROGMEM combo_alt_f4[]  = {MO(L_FN1), KC_Q, COMBO_END};

// Declare all combos
combo_t key_combos[] = {COMBO(combo_win_tab, WIN_TAB), COMBO(combo_win_e, WIN_E), COMBO(combo_alt_f4, ALT_F4)};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case WIN_TAB:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
                unregister_code(KC_LGUI);
            }

            return false;

        case WIN_E:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_E);
            } else {
                unregister_code(KC_E);
                unregister_code(KC_LGUI);
            }

            return false;

        case ALT_F4:
            if (record->event.pressed) {
                tap_code16(LALT(KC_F4));
            }
            return false;
    }

    return true;
}

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_61_ansi(
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,   KC_EQL,  KC_BSPC,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,   KC_RBRC, KC_BSLS,
        LT(MAC_FN, KC_ESC), KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     LT(L_FN1, KC_SCLN),  KC_QUOT,            KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,
        KC_LCTL,  KC_LOPTN, KC_LCMMD,                                KC_SPC,                                 KC_RCMMD, MO(MAC_FN), MO(L_FN1), KC_RCTL),


    [WIN_BASE] = LAYOUT_61_ansi(
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,
        LT(WIN_FN, KC_ESC),  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,
        KC_LCTL,  MO(L_FN1),  KC_LALT,                                KC_SPC,                                 KC_RALT, KC_LWIN,MO(L_FN1),KC_RCTL),

    [MAC_FN] = LAYOUT_61_ansi(
        KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_MUTE,  KC_VOLD,  KC_VOLU,  BAT_LVL,  _______,  RGB_TOG,  RGB_VAD,  RGB_VAI,  _______,
        _______,  KC_ENT,   KC_UP,    KC_F5,    BT_HST1,  BT_HST2,  BT_HST3,  KC_7,     KC_8,     KC_9,     KC_PAST,  KC_PGUP,  KC_HOME,  KC_PSCR,
        _______,  KC_LEFT,  KC_DOWN,  KC_RIGHT, RGB_MOD,  RGB_HUI,  RGB_SAI,  KC_4,     KC_5,     KC_6,     KC_PPLS,  KC_END,             _______,
        _______,            KC_F2,    KC_F3,    KC_F4,    RGB_RMOD, RGB_HUD,  RGB_SAD,  KC_1,     KC_2,     KC_3,     KC_0,               _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______),

    [WIN_FN] = LAYOUT_61_ansi(
        KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_MUTE,  KC_VOLD,  KC_VOLU,  BAT_LVL,  _______,  RGB_TOG,  RGB_VAD,  RGB_VAI,  _______,
        _______,  KC_ENT,  KC_UP,  KC_F5,  BT_HST1,  BT_HST2,  BT_HST3,  KC_7,  KC_8,   KC_9,  KC_PAST,   KC_PGUP,  KC_HOME,  KC_PSCR,
        _______,  KC_LEFT,  KC_DOWN,  KC_RIGHT,  RGB_MOD,  RGB_HUI,  RGB_SAI,  KC_4,  KC_5,    KC_6,  KC_PPLS,  KC_END,             _______,
        _______,            KC_F2, KC_F3,  KC_F4,  RGB_RMOD,  RGB_HUD,  RGB_SAD,  KC_1,  KC_2,  KC_3, KC_0,             _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______),

    [L_FN1] = LAYOUT_61_ansi(
        KC_CAPS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,
        _______,  _______,  KC_UP,  _______,  _______,  _______,  _______,  KC_DEL,  KC_UP,  KC_EQL,  KC_BSPC,  KC_9,  KC_0,  _______,
        _______,  KC_LEFT,  KC_DOWN,  KC_RIGHT,  _______,  _______,  KC_PGUP,  KC_LEFT,  KC_DOWN,  KC_RIGHT,  KC_ENT,  _______,            KC_INS,
        _______,            _______,  _______,  _______,  _______,  _______,  KC_PGDN,  KC_HOME,  _______,  KC_END,  _______,            _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______),
    };
