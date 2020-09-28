/* XD75 Firmware 
 * R31 2020
 */
#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _GAME 1
#define _COLEMAK 2
#define _LOWER 3
#define _RAISE 4
#define _NUMPD 14
#define _ADJUST 15
#define _DYNAMIC_MACRO_RANGE 16

// Defining Custom keycodes
enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  GAME,
  COLEMAK,
  DVORAK,
  LOWER,
  RAISE,
  NUMPD,
  ADJUST,
  DYNAMIC_MACRO_RANGE,
};

/* Fillers to make layering more clear = Obsolete¿?
 *#define _______ KC_TRNS
 *#define XXXXXXX KC_NO
 */

// Custom keycodes
#define CTL_ESC CTL_T(KC_ESC)  // Tap for Escape, hold for Control
#define SFT_ENT SFT_T(KC_ENT)  // Tap for Enter, hold for Shift
#define SFT_BSP SFT_T(KC_BSPC) // Tap for Backspace, hold for Shift
#define HPR_TAB ALL_T(KC_TAB)  // Tap for Tab, hold for Hyper (Super+Ctrl+Alt+Shift)
#define ADJ_ESC LT(_ADJUST, KC_ESC)
// #define MEH_GRV MEH_T(KC_GRV)  // Tap for Backtick, hold for Meh (Ctrl+Alt+Shift)
#define RALTESC RALT_T(KC_ESC)  // Tap for ESC hold for alt_gr
#define SPC_CTL LCTL_T(KC_SPC)
#define SPC_NUM LT(_NUMPD, KC_SPC)

// Unicode keycodes
#define EUR_SGN UC(0x20AC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,--------------------------------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  | NLck | P/   |  P*  |   6  |   7  |   8  |   9  |   0  | DEL  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  | P7   | P8   | P9   |   Y  |   U  |   I  |   O  |   P  |  Bksp|
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |  P4  |  P5  |  P6  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   P1 |  P2 |  P3   |   N  |   M  |   ,  |   .  |  /   |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  |Lower |Space |Space | Space| P0   | P.   | Space|Raise | Left | Down |  Up  | Rght |
 * `--------------------------------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_5x15( 
   KC_ESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,  KC_NLCK, KC_PSLS, KC_PAST, KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_DEL ,
   KC_TAB, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_P7,   KC_P8,   KC_P9, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC   ,
   RALTESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_P4,   KC_P5,   KC_P6, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT ,
   SFT_BSP, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_P1,   KC_P2,   KC_P3, KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, SFT_ENT ,
   KC_LCTL, KC_LGUI, KC_LALT, LOWER,XXXXXXX, SPC_CTL, XXXXXXX, KC_P0,   KC_PDOT, SPC_NUM,  RAISE, KC_LEFT, KC_DOWN,  KC_UP, KC_RGHT 
),

/* GAME --> no winkey, no mod taps, to be enhanced
 * ,--------------------------------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  | NLck | P/   |  P*  |   6  |   7  |   8  |   9  |   0  | DEL  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  | P7   | P8   | P9   |   Y  |   U  |   I  |   O  |   P  |  Bksp|
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Bksp |   A  |   S  |   D  |   F  |   G  |  P4  |  P5  |  P6  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   P1 |  P2 |  P3   |   N  |   M  |   ,  |   .  |  /   |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |      | Alt  |Lower |Space |Space | Space| P0   | P.   |Enter |Raise | Left | Down |  Up  | Rght |
 * `--------------------------------------------------------------------------------------------------------'
 */
[_GAME] = LAYOUT_ortho_5x15( 
   KC_ESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,  KC_NLCK, KC_PSLS, KC_PAST, KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_DEL ,
   KC_TAB, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_P7,   KC_P8,   KC_P9, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC   ,
   KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_P4,   KC_P5,   KC_P6, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT ,
   KC_SFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_P1,   KC_P2,   KC_P3, KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_ENT ,
   KC_LCTL, XXXXXXX, KC_LALT, LOWER,XXXXXXX, KC_SPC, XXXXXXX, KC_P0,   KC_PDOT, KC_PENT,  RAISE, KC_LEFT, KC_DOWN,  KC_UP, KC_RGHT 
),

/* Colemak
 * ,--------------------------------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  | NLck | P/   |  P*  |   6  |   7  |   8  |   9  |   0  | DEL  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  | P7   | P8   | P9   |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |  P4  |  P5  |  P6  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   P1 |  P2 |  P3   |   K  |   M  |   ,  |   .  |  /   |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  |Lower |Space |Space | PEnt | P0   | P.   |Space |Raise | Left | Down |  Up  | Rght |
 * `--------------------------------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_ortho_5x15( 
   KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_NLCK, KC_PSLS, KC_PAST, KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_DEL ,
   KC_TAB, KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,     KC_P7,   KC_P8,   KC_P9, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC ,
   RALTESC, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,     KC_P4,   KC_P5,   KC_P6, KC_H,    KC_N,    KC_E,    KC_I,    KC_O,   KC_QUOT ,
   SFT_BSP, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_P1,   KC_P2,   KC_P3, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_ENT ,
   KC_LCTL, KC_LGUI, KC_LALT , LOWER,  XXXXXXX, SPC_CTL, XXXXXXX, KC_P0,   KC_PDOT, SPC_NUM,  RAISE, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT 
),


/* Lower
 * ,--------------------------------------------------------------------------------------------------------.
 * |   `  |      |      |      |      |      | Calc |  P-  |  P+  |      |      |      |      | acc  |Del   |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  | Home |  Up  | PgUp |   ^  |   &  |   *  |   (  |   )  | KC_INT|
 * |------+------+------+------+------+-------------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  | Left |      |Right |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  End | Down | Pgdn |  F12 | MS L | MS D |MS U  | MS R |MS Btn|
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  €   | Del  |      |      |      | Vol- | Vol+ |      |
 * `--------------------------------------------------------------------------------------------------------'
  */
[_LOWER] = LAYOUT_ortho_5x15( 
   KC_GRV , _______, _______, _______, _______, _______, KC_CALC, KC_PMNS, KC_PPLS, _______, _______, _______, _______,KC_GRAVE, KC_DEL  ,
   KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_HOME, KC_UP , KC_PGUP, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_NUBS  ,
   KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_LEFT, _______, KC_RGHT, KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE ,
   _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_END, KC_DOWN, KC_PGDN, KC_F12,  KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_BTN1 ,
   _______, _______, _______, _______, _______, _______, _______, EUR_SGN, KC_DEL , _______, _______, _______,  KC_VOLD, KC_VOLU,_______ 
),

/* Raise
 * ,--------------------------------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  | Calc |  P-  |  P+  |  F7  |  F8  |  F9  |  F10 |  F11 | F12  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |      |      |      |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |      |      |      |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  M1  |      |  M2  |  F12 |      |      |      |      |MS_BN2|
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      | Vol- | Vol+ |      |
 * `--------------------------------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_5x15( 
   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, KC_F6, KC_CALC, KC_PMNS, KC_PPLS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, KC_F12 ,
   KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC ,
   KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, _______, _______, KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS ,
   _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  DYN_MACRO_PLAY1, _______, DYN_MACRO_PLAY2, KC_F12,  _______, _______, _______, _______, KC_BTN2 ,
   _______, _______, _______, _______, _______, _______,_______, _______, _______, _______, _______, _______,  KC_VOLD, KC_VOLU,_______  
),

/* Numpad
 * ,--------------------------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |Reset |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |NUMLCK|   7  |   8  |   9  |   /  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |   4  |   5  |   6  |   *  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |   ,  |   1  |   2  |   3  |   -  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |   0  |   .  |   +  |   =  |
 * `--------------------------------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_5x15( 
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  RESET ,
   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_NLCK,  KC_P7,   KC_P8,   KC_P9, KC_KP_SLASH, _______, 
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  KC_P4,   KC_P5,   KC_P6, KC_KP_ASTERISK, _______,
   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_COMM, KC_P1,   KC_P2,   KC_P3, KC_KP_MINUS, _______, 
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  KC_GRV, KC_P0, KC_DOT, KC_KP_PLUS, KC_KP_EQUAL 
),

/* Adjust (Lower + Raise)
 * ,--------------------------------------------------------------------------------------------------------.
 * |Reset |      |      |      |      |      |      |      |      |      |      |      |      |      |Reset |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Qwerty|Colemk|      |      | Game |Rec_M1|Recstp|Rec_M2|      |      |      |      |      | Del  |
 * |------+------+------+------+------+------|------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      | Left | Down |  Up  | Rght |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |BL I/O|BL LEV|BL BRT|      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * `--------------------------------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_5x15( 
    RESET , M(0)   , M(1)   , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET ,
   _______, QWERTY,  COLEMAK,_______, _______,   GAME, DYN_REC_START1, DYN_REC_STOP, DYN_REC_START2, _______, _______,  _______, _______, _______,   KC_DEL  ,
   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN,  KC_UP, KC_RGHT, _______, _______ ,
   _______, _______, BL_TOGG, BL_STEP, BL_BRTG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ ,
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ 
),
};



const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    if (record->event.pressed) {
        switch(id) {
            case 0:
                SEND_STRING("SendstringMacro1");
                return false;
            case 1:
                send_unicode_string("(ノಠ痊ಠ)ノ彡┻━┻");
                return false;
            case 2:
                send_unicode_hex_string("0028 30CE 0CA0 75CA 0CA0 0029 30CE 5F61 253B 2501 253B");
                return false;
        }
    }
    return MACRO_NONE;
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (!process_record_dynamic_macro(keycode, record)) {
        return false;
    }
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_colemak, false, 0);
        #endif
        persistent_default_layer_set(1UL<<_COLEMAK);
      }
      return false;
      break;
    case GAME:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_dvorak, false, 0);
        #endif
        persistent_default_layer_set(1UL<<_GAME);
      }
      return false;
      break;
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
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
