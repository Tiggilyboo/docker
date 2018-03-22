#include "planck.h"
#include "action_layer.h"

#ifdef BACKLIGHT_ENABLE 
#include "backlight.h"
#endif
#ifdef SLEEP_LED_ENABLE
#include "sleep_led.h"
#endif

extern keymap_config_t keymap_config;

enum planck_layers {
  _BASE = 1,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  LOWER = SAFE_RANGE,
  RAISE,
  BLTGL,
  BLINC,
  BLDEC,
  SLEEP,
  WRKSPC,
  XEDDEV
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Base
   * ,-----------------------------------------------------------------------------------.
   * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
   * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
   * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
   * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
   * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / | Vol- | Vol+ |      |
   * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
   * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Vol- | Vol+ |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Scr- | Scr+ |      |      |      |      |      |      | Home |Pg Up |Pg Dn | End  |
   * | Ctrl | GUI  | Alt  |WrkSp |Lower |Space | Bksp |Raise | Left | Down |  Up  |Right |
   * | Scr- | Scr+ |      |      |      | Vol- | Vol+ |      | Home |Pg Up |Pg Dn | End  |
   * `-----------------------------------------------------------------------------------'
   */
  [_BASE] = {
    {KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC},
    {KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT},
    {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
    {KC_LCTL, KC_LGUI, KC_LALT, WRKSPC,  LOWER,   KC_SPC,  KC_BSPC, RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
  },
  [_LOWER] = {
    {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC},
    {KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE},
    {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), _______, _______, KC_F8},
    {KC_F6,   KC_F7,   _______, _______, _______, KC_F10,  KC_F11,  _______,    KC_HOME,    KC_PGDN, KC_PGUP, KC_END }
  },
  [_RAISE] = {
    {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC},
    {KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS},
    {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, _______, _______, KC_F8},
    {KC_F6,   KC_F7,   _______, _______, _______, KC_F10,  KC_F11,  _______,    KC_HOME,    KC_PGDN, KC_PGUP, KC_END }
  },

  /* Adjust (Lower + Raise)
   * ,-----------------------------------------------------------------------------------.
   * |Sleep | Reset|      |      |      |      |      |      |      |      |      |  Del |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | BL+  |      |      |Aud on|Audoff|AGnorm|AGswap|      |      |      |      |      |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * | BL-  |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      | Dev  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | BL   |      |      |      |      |             |      |      |      |      |      |
   * `-----------------------------------------------------------------------------------'
   */
  [_ADJUST] = {
    {SLEEP,  RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL },
    {BLINC,  _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______, _______, _______, _______,  _______},
    {BLDEC,  MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, XEDDEV },
    {BLTGL,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
  }
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
    case WRKSPC:
      if(record->event.pressed){
        register_code(KC_LALT);
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        unregister_code(KC_LALT);
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case XEDDEV:
      if(record->event.pressed){
        register_code(KC_LALT);
        register_code(KC_ENT);
        unregister_code(KC_ENT);
        unregister_code(KC_LALT);
        wait_ms(500);
        SEND_STRING("cd ~/Source && xed -c Dev");
        register_code(KC_ENT);
        unregister_code(KC_ENT);
      }
      return false;
      break;
    case SLEEP:
      if(record->event.pressed) {
        register_code(KC_SLEP);
        breathing_enable();
      } else {
        unregister_code(KC_SLEP);
      }
      return false;
      break;
  #ifdef BACKLIGHT_ENABLE
    case BLTGL:
      if (record->event.pressed) {
        backlight_toggle();
        breathing_disable();
      }
      return false;
      break;
    case BLINC:
      if (record->event.pressed) {
        backlight_increase();
        breathing_disable();
      }
      return false;
      break;
    case BLDEC:
      if (record->event.pressed) {
        backlight_decrease();
        breathing_disable();
      }
      return false;
      break;
  #endif
  }
  return true;
}

