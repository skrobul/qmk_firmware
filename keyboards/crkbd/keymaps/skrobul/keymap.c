/*
Copyright 2019 @foostan
Copyright 2023 skrobul

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "skrobul.h"
// #include "features/achordion.h"

// i3 WM workspace switching
#define I3_1 G(KC_1)
#define I3_2 G(KC_2)
#define I3_3 G(KC_3)
#define I3_4 G(KC_4)
#define I3_5 G(KC_5)


// Left-hand home row mods
#define GUI_A LGUI_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define CTL_D LCTL_T(KC_D)
#define SFT_F LSFT_T(KC_F)

// Right-hand home row mods
#define SFT_J RSFT_T(KC_J)
#define CTL_K RCTL_T(KC_K)
#define ALT_L LALT_T(KC_L)
#define GUI_SCLN RGUI_T(KC_SCLN)


enum custom_keycodes {
  TMUXNEXT = SAFE_RANGE,
  TMUXPREV,
  // FN_MO13,
  // FN_MO23,
  TMUXCOPY,
  TMUXPASTE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     LT(4, KC_TAB),    KC_Q,      KC_W,    KC_E,    KC_R,    KC_T,                 KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,   GUI_A,   ALT_S,  CTL_D,    SFT_F,    KC_G,                         KC_H,   SFT_J,   CTL_K,  ALT_L ,GUI_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, FN_MO13,  KC_SPC,     KC_ENT, FN_MO23, KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),

  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, G(KC_1), G(KC_2), G(KC_3), G(KC_4), G(KC_5),                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, KC_HOME, KC_END,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TMUXCOPY, TMUXPASTE,                  TMUXPREV, TMUXNEXT, _______, _______, _______, KC_PSCR,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [2] = LAYOUT_split_3x6_3(
  //,---------------------------------------------------------.                ,-----------------------------------------------------.
       KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+------------+--------+--------+--------+--------|                |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,KC_SYSTEM_SLEEP,              KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_F1  ,   KC_F2,   KC_F3,   KC_F4,   KC_F5, KC_F6 ,                       KC_F7  , KC_F8  ,  KC_F9 ,  KC_F10, KC_F11, KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, DT_UP, DT_DOWN,                        DT_PRNT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, QK_BOOT, QK_CLEAR_EEPROM,             KC_MEDIA_NEXT_TRACK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),
  [4] = LAYOUT_split_3x6_3(
  // i3 navigation layer
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, G(KC_1),    G(KC_2),    G(KC_3),    G(KC_4),    G(KC_5),    G(KC_6),   G(KC_7),   G(KC_8),   G(KC_9),   G(KC_0),   XXXXXXX,
      XXXXXXX, LSG(KC_1),  LSG(KC_2),  LSG(KC_3),  LSG(KC_4),  LSG(KC_5),  LSG(KC_6), LSG(KC_7), LSG(KC_8), LSG(KC_9), LSG(KC_0), XXXXXXX,
      XXXXXXX, HYPR(KC_Z), HYPR(KC_X), HYPR(KC_C), HYPR(KC_V), HYPR(KC_B), XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
      
  )
};


// macros

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef OLED_ENABLE
  if (record->event.pressed) {
    /* set_keylog(keycode, record); */
  }
#endif // OLED_ENABLE

  // if (!process_achordion(keycode, record)) { return false; }

  switch (keycode) {
    case TMUXNEXT:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("b") SS_DELAY(50) "n");
      }
      return false;
    case TMUXPREV:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("b") SS_DELAY(50) "p");
      }
      return false;

    case TMUXCOPY:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("b") SS_DELAY(50) "[");
      }
      return false;

    case TMUXPASTE:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("b") SS_DELAY(50) "]");
      }
      return false;

    case FN_MO13:
      if (record->event.pressed) {
        layer_on(1);
        update_tri_layer(1, 2, 3);
      } else {
        layer_off(1);
        update_tri_layer(1, 2, 3);
      }
      return false;
      break;
    case FN_MO23:
      if (record->event.pressed) {
        layer_on(2);
        update_tri_layer(1, 2, 3);
      } else {
        layer_off(2);
        update_tri_layer(1, 2, 3);
      }
      return false;
      break;
  }
  return true;

}



// void matrix_scan_user(void) {
//   achordion_task();
// }
//
/* const uint16_t PROGMEM esc_combo[] = {KC_U, KC_I, COMBO_END}; */
/* combo_t key_combos[COMBO_COUNT] = { */
/*     COMBO(esc_combo, KC_ESC), */
/* }; */
//
//
// uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case SFT_F:
//         case SFT_J:
//             return g_tapping_term - 50;
//         default:
//             return g_tapping_term;
//     }
// }
// // replacement for get_tapping_force_hold
// uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case SFT_J:
//         case CTL_K:
//             return QUICK_TAP_TERM;
//         default:
//             return 0;
//     }
// }
