/*
Copyright 2019 Sekigon

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
#include "app_ble_func.h"
#include <stdio.h>


enum custom_keycodes {
    AD_WO_L = SAFE_RANGE, /* Start advertising without whitelist  */
    BLE_DIS,              /* Disable BLE HID sending              */
    BLE_EN,               /* Enable BLE HID sending               */
    USB_DIS,              /* Disable USB HID sending              */
    USB_EN,               /* Enable USB HID sending               */
    DELBNDS,              /* Delete all bonding                   */
    ADV_ID0,              /* Start advertising to PeerID 0        */
    ADV_ID1,              /* Start advertising to PeerID 1        */
    ADV_ID2,              /* Start advertising to PeerID 2        */
    ADV_ID3,              /* Start advertising to PeerID 3        */
    ADV_ID4,              /* Start advertising to PeerID 4        */
    DEL_ID0,              /* Delete bonding of PeerID 0           */
    DEL_ID1,              /* Delete bonding of PeerID 1           */
    DEL_ID2,              /* Delete bonding of PeerID 2           */
    DEL_ID3,              /* Delete bonding of PeerID 3           */
    DEL_ID4,              /* Delete bonding of PeerID 4           */
    ENT_SLP,              /* Deep sleep mode                      */
    LOWER,                /* Layer  keycode                       */
    RAISE,                /* Layer  keycode                       */
};


extern keymap_config_t keymap_config;

enum {
  _QWERTY,
  _LOWER,
  _RAISE,
 _ADJUST,
};

// Macros
enum {
  KF_1 = 0, // 1, F1
  KF_2, // ...
  KF_3,
  KF_4,
  KF_5,
  KF_6,
  KF_7,
  KF_8,
  KF_9,
  KF_10,
  KF_11,
  KF_12,
};

uint16_t kf_timers[12];

#define LONGPRESS_DELAY 150
#define LAYER_TOGGLE_DELAY 300

// Layer related keycodes
#define ADJUST  MO(_ADJUST)

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( 
	KC_ESC,   KC_1,    KC_2,     KC_3,     KC_4,    KC_5,    	KC_6,    KC_7,    KC_8,    KC_9,     KC_0,     KC_MINS, \
    	KC_TAB,   KC_Q,    KC_W,     KC_E,     KC_R,    KC_T,    	KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,     KC_LBRC, \
    	KC_LGUI,  KC_A,    KC_S,     KC_D,     KC_F,    KC_G,    	KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN,  KC_QUOT, \
    	KC_LCTL,  KC_Z,    KC_X,     KC_C,     KC_V,    KC_B,    	KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_LALT,  KC_LCTL, \
    		         ADJUST,    LOWER,  KC_BSPC, KC_LSFT,  		KC_ENT,  KC_SPC,  KC_RGUI, RAISE \
  ),

  [_LOWER] = LAYOUT(
	_______, KF_1,    KF_2,    KF_3,    KF_4,       KF_5,  		KF_6,    KF_7,    KF_8,    KF_9,     KF_10,   KF_11,   \
	_______, KC_LABK, KC_RABK, KC_LCBR, KC_RCBR, KC_PLUS, 		KC_AT,   KC_DQT,  _______, KC_GRAVE, KC_SLSH, KC_RBRC, \
	_______, KC_EXLM, KC_EQL,  KC_LPRN, KC_RPRN, KC_MINS, 		KC_UNDS, KC_CIRC, KC_DLR,  KC_AMPR,  KC_PIPE, _______, \
	_______, _______, KC_PERC, _______, _______, KC_ASTR, 		KC_HASH, _______, KC_COLN, KC_QUES,  KC_BSLS, _______, \
			  _______, _______, _______, _______, 		_______, _______, _______, _______ \
  ),

  [_RAISE] = LAYOUT(
	_______, _______, _______, _______, _______, _______,        	_______, KC_P7,   KC_P8,   KC_P9,    _______, _______, \
	_______, _______, _______, _______, _______, _______,        	_______, KC_P4,   KC_P5,   KC_P6,    _______, _______, \
	_______, _______, _______, _______, _______, _______,		XXXXXXX, KC_P1,   KC_P2,   KC_P3,    KC_RGHT, XXXXXXX, \
	_______, _______, _______, _______, _______, _______,        	XXXXXXX, KC_P0,   KC_PDOT, KC_PGUP,  KC_END,  XXXXXXX, \
                          _______, _______, _______, _______,		_______, _______, _______, _______ \
  ),

  [_ADJUST] = LAYOUT (
 	_______, ADV_ID0, ADV_ID1, ADV_ID2, ADV_ID3, ADV_ID4, 		_______, _______, _______, _______,  _______, _______, \
	_______, DEL_ID0, DEL_ID1, DEL_ID2, DEL_ID3, DEL_ID4, 		KC_HOME, KC_PGDN, KC_PGUP, KC_END,   DELBNDS, KC_MUTE, \
	_______, _______, _______, _______, _______, _______, 		KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, AD_WO_L, KC_VOLU, \
	_______, _______, _______, _______, _______, _______, 		_______, _______, _______, _______,  ENT_SLP, KC_VOLD, \
			  _______, _______, _______, _______, 		_______, _______, _______, _______ \
		  	  		  
 )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
  }
  if (record->event.pressed) {
    switch (keycode) {
    case DELBNDS:
      delete_bonds();
      return false;
    case AD_WO_L:
      restart_advertising_wo_whitelist();
      return false;
    case USB_EN:
      set_usb_enabled(true);
      return false;
      break;
    case USB_DIS:
      set_usb_enabled(false);
      return false;
      break;
    case BLE_EN:
      set_ble_enabled(true);
      return false;
      break;
    case BLE_DIS:
      set_ble_enabled(false);
      return false;
      break;
    case ADV_ID0:
      restart_advertising_id(0);
      return false;
    case ADV_ID1:
      restart_advertising_id(1);
      return false;
    case ADV_ID2:
      restart_advertising_id(2);
      return false;
    case ADV_ID3:
      restart_advertising_id(3);
      return false;
    case ADV_ID4:
      restart_advertising_id(4);
      return false;
    case DEL_ID0:
      delete_bond_id(0);
      return false;
    case DEL_ID1:
      delete_bond_id(1);
      return false;
    case DEL_ID2:
      delete_bond_id(2);
      return false;
    case DEL_ID3:
      delete_bond_id(3);
      return false;
    }
  }
  else if (!record->event.pressed) {
    switch (keycode) {
    case ENT_SLP:
      sleep_mode_enter();
      return false;
    }

  }
  return true;
};

static void m_handle_kf (keyrecord_t *record, uint8_t id) {
  uint8_t code = id - KF_1;

  if (record->event.pressed) {
    kf_timers[code] = timer_read ();
  } else {
    uint8_t kc_base;
    uint8_t long_press = (kf_timers[code] && timer_elapsed (kf_timers[code]) > TAPPING_TERM);

    kf_timers[code] = 0;

    switch(id){
      case KF_1 ... KF_10:
        if (long_press) {
          // Long press
          kc_base = KC_F1;
        } else {
          kc_base = KC_1;
        }
        code += kc_base;
        break;
      case KF_11:
        code = long_press ? KC_F11 : KC_ESC;
        break;
      case KF_12:
        code = long_press ? KC_F12 : KC_EQUAL;
        break;
    }
    register_code (code);
    unregister_code (code);
  }
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch (id) {
    case KF_1 ... KF_12:
      m_handle_kf(record, id);
      break;
  }
  return MACRO_NONE;
};

