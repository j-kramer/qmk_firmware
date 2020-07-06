#include QMK_KEYBOARD_H
#include "action_layer.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _COLEMAK 1
#define _DVORAK 2
#define _WORKMAN 3
#define _LOWER 4
#define _RAISE 5
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  WORKMAN,
};

// Layer switching shortcuts
#define LOWER OSL(_LOWER)
#define RAISE OSL(_RAISE)
#define ADJUST MO(_ADJUST)

// One-shot key shortcuts
#define OS_LSFT OSM(MOD_LSFT)
#define OS_RSFT OSM(MOD_RSFT)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_RCTL OSM(MOD_RCTL)
#define OS_LALT OSM(MOD_LALT)
#define OS_RALT OSM(MOD_RALT)
#define OS_LGUI OSM(MOD_LGUI)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------..-----------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  ||   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  ||   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  ||   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |Adjust| Ctrl | GUI  | Alt  |Lower |Space ||Enter |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------''-----------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12( \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  OS_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, OS_RSFT, \
  ADJUST,  OS_LCTL, OS_LGUI, OS_LALT, LOWER,   KC_SPC,  KC_ENT,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
),

/* Colemak
 * ,-----------------------------------------..-----------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  ||   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  ||   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  ||   K  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |Adjust| Ctrl | GUI  | Alt  |Lower |Space ||Enter |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------''-----------------------------------------'
 */
[_COLEMAK] = LAYOUT_ortho_4x12( \
  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC, \
  KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, \
  OS_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, OS_RSFT, \
  ADJUST,  OS_LCTL, OS_LGUI, OS_LALT, LOWER,   KC_SPC,  KC_ENT,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
),

/* Dvorak
 * ,-----------------------------------------..-----------------------------------------.
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  ||   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  ||   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  ||   B  |   M  |   W  |   V  |   Z  |Shift |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |Adjust| Ctrl | GUI  | Alt  |Lower |Space ||Enter |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------''-----------------------------------------'
 */
[_DVORAK] = LAYOUT_ortho_4x12( \
  KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC, \
  KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH, \
  OS_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    OS_RSFT, \
  ADJUST,  OS_LCTL, OS_LGUI, OS_LALT, LOWER,   KC_SPC,  KC_ENT,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

/* Workman
 * ,-----------------------------------------..-----------------------------------------.
 * | Tab  |   Q  |   D  |   R  |   W  |   B  ||   J  |   F  |   U  |   P  |   ;  | Bksp |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   H  |   T  |   G  ||   Y  |   N  |   E  |   O  |   I  |  "   |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   M  |   C  |   V  ||   K  |   L  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |Adjust| Ctrl | GUI  | Alt  |Lower |Space ||Enter |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------''-----------------------------------------'
 */
[_WORKMAN] = LAYOUT_ortho_4x12( \
  KC_TAB,  KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,    KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN, KC_BSPC, \
  KC_ESC,  KC_A,    KC_S,    KC_H,    KC_T,    KC_G,    KC_Y,    KC_N,    KC_E,    KC_O,    KC_I,    KC_QUOT, \
  OS_LSFT, KC_Z,    KC_X,    KC_M,    KC_C,    KC_X,    KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_SLSH, OS_RSFT, \
  ADJUST,  OS_LCTL, OS_LGUI, OS_LALT, LOWER,   KC_SPC,  KC_ENT,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

/* Lower
 * ,-----------------------------------------..-----------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  ||   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  ||  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 ||  F12 |      |      |      |      |      |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |      |      |      |      |      |      ||      |      |      |      |      |      |
 * `-----------------------------------------''-----------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* Raise
 * ,-----------------------------------------..-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  ||   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  ||  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 ||  F12 |      |      |      |      |      |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |      |      |      |      |      |      ||      |      |      |      |      |      |
 * `-----------------------------------------''-----------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* Adjust
 * ,-----------------------------------------..-----------------------------------------.
 * |      | Reset|      |      |      |      ||      |      |      |      | Reset|      |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |      |Workmn|Dvorak|Colemk|Qwerty|      ||      |Qwerty|Colemk|Dvorak|Workmn|      |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |      |      |      |      |      |      ||      |      |      |      |      |      |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |      |      |      |      |      |      ||      |      |      |      |      |      |
 * `-----------------------------------------''-----------------------------------------'
 */
[_ADJUST] = LAYOUT_ortho_4x12( \
  _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, RESET,   _______, \
  _______, WORKMAN, DVORAK,  COLEMAK, QWERTY,  _______, _______, QWERTY,  COLEMAK, DVORAK,  WORKMAN, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
    case WORKMAN:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_WORKMAN);
      }
      return false;
    default:
      break;
  }
  return true;
}
