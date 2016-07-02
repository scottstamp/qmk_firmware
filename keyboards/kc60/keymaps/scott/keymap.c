// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "kc60.h"

// Used for SHIFT_ESC, SHIFT_HOME, SHIFT_END
#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = KEYMAP( /* Basic QWERTY */
      F(0),     KC_1,     KC_2,     KC_3,    KC_4,     KC_5,     KC_6,     KC_7,    KC_8,  KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  \
      KC_TAB,   KC_Q,     KC_W,     KC_E,    KC_R,     KC_T,     KC_Y,     KC_U,    KC_I,  KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  \
      MO(1),    KC_A,     KC_S,     KC_D,    KC_F,     KC_G,     KC_H,     KC_J,    KC_K,  KC_L,     KC_SCLN,  KC_QUOT,  KC_NO,    KC_ENT,   \
      KC_LSFT,  KC_NO,    KC_Z,     KC_X,    KC_C,     KC_V,     KC_B,     KC_N,    KC_M,  KC_COMM,  KC_DOT,   KC_SLSH,  KC_NO,    KC_RSFT,  \
      KC_LCTL,  KC_LGUI,  KC_LALT,                     KC_SPC,                                       KC_RALT,  KC_RGUI,  MO(1),    KC_RCTL \
      ),
  [1] = KEYMAP(
      F(0),     KC_F1,    KC_F2,    KC_F3,   KC_F4,    KC_F5,    KC_F6,    KC_F7,   KC_F8,  KC_F9,   KC_F10,   KC_F11,   KC_F12,   KC_DEL,   \
      KC_TRNS,  KC_HOME,  KC_UP,    KC_END,  KC_PGUP,  KC_TRNS,  KC_PGUP,  KC_HOME, KC_UP,  KC_END,  KC_PSCR,  KC_TRNS,  KC_TRNS,  KC_TRNS,  \
      KC_TRNS,  KC_LEFT,  KC_DOWN,  KC_RGHT, KC_PGDN,  KC_TRNS,  KC_PGDN,  KC_LEFT, KC_DOWN,KC_RGHT, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  \
      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,KC_VOLD, KC_VOLU,  KC_MUTE,  KC_TRNS,  KC_TRNS,  \
      KC_TRNS,  KC_TRNS,  KC_TRNS,                     KC_TRNS,                                      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS \
      ),
};

enum function_id {
	SHIFT_ESC,
};

const uint16_t PROGMEM fn_actions[] = {
	[0] = ACTION_FUNCTION(SHIFT_ESC),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
	static uint8_t shift_mask;
	switch (id) {
		case SHIFT_ESC:
			shift_mask = get_mods()&MODS_CTRL_MASK;
			if (record->event.pressed) {
				if (shift_mask) {
					add_key(KC_GRV);
					send_keyboard_report();
				} else {
					add_key(KC_ESC);
					send_keyboard_report();
				}
			} else {
				if (shift_mask) {
					del_key(KC_GRV);
					send_keyboard_report();
				} else {
					del_key(KC_ESC);
					send_keyboard_report();
				}
			}
			break;
	}
}
