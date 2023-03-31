#include QMK_KEYBOARD_H

#define _L0 0
#define _L1 1
#define _L2 2

#define L1_BSP LT(_L1,KC_BSPC)
#define L2_SPC LT(_L2,KC_SPC)
#define CRL_QT LCTL_T(KC_QUOT)

// Adds mod tap keys on the home row for all layouts as well
// No pinkies, they accidentally trigger all the time and OPT is really not used that often 

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Default layer: Split QWERTY
   * ,-----------------------------------------------------------------------------------.
   * |   Q  |   W  |   E  |   R  |   T  |      |      |   Y  |   U  |   I  |   O  |   P  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |   A  | S/Ctl| D/GUI|F/Shft|   G  |      |      |   H  |J/Shft| K/GUI| L/Ctl|   ;  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |   Z  |   X  |   C  |   V  |   B  |      |      |   N  |   M  |   ,  |   .  |   /  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      | GUI  |Shift |Bsp/L1| Opt  | Tab  |Spc/L2|'/Ctl |      |      |      |
   * `-----------------------------------------------------------------------------------'
   */
  [_L0] = LAYOUT_ortho_4x12(
    KC_Q,  KC_W,        KC_E,         KC_R,        KC_T,   KC_NO,   KC_NO,  KC_Y,   KC_U,        KC_I,         KC_O,        KC_P,
    KC_A,  CTL_T(KC_S), LGUI_T(KC_D), SFT_T(KC_F), KC_G,   KC_NO,   KC_NO,  KC_H,   SFT_T(KC_J), LGUI_T(KC_K), CTL_T(KC_L), KC_SCLN,
    KC_Z,  KC_X,        KC_C,         KC_V,        KC_B,   KC_NO,   KC_NO,  KC_N,   KC_M,        KC_COMM,      KC_DOT,      KC_SLSH,
    KC_NO, KC_NO,       KC_LGUI,      KC_LSFT,     L1_BSP, KC_LOPT, KC_TAB, L2_SPC, CRL_QT,      KC_NO,        KC_NO,       KC_NO),

  /* Layer 1: Numbers, Brackets and Symbols
   * ,-----------------------------------------------------------------------------------.
   * |   1  |   2  |   3  |   4  |   5  |      |      |   6  |   7  |   8  |   9  |   0  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |   [  |   <  |   {  |   (  |   -  |      |      |   =  |   )  |   }  |   >  |   ]  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |   !  |   @  |   #  |   $  |   %  |      |      |   ^  |   &  |   *  |   +  |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |######|      | Ctl->|Enter |Shift |      |      |      |
   * `-----------------------------------------------------------------------------------'
   */
  [_L1] = LAYOUT_ortho_4x12(
    KC_1,    KC_2,  KC_3,    KC_4,    KC_5,    KC_NO, KC_NO,          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_LBRC, KC_LT, KC_LCBR, KC_LPRN, KC_MINS, KC_NO, KC_NO,          KC_EQL,  KC_RPRN, KC_RCBR, KC_GT,   KC_RBRC,
    KC_EXLM, KC_AT, KC_HASH, KC_DLR,  KC_PERC, KC_NO, KC_NO,          KC_CIRC, KC_AMPR, KC_ASTR, KC_PLUS, KC_NO,
    KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_TRNS, KC_NO, LCTL(KC_RIGHT), KC_ENT,  KC_LSFT, KC_NO,   KC_NO,   KC_NO),

  /* Layer 2: Arrows & Extras
   * ,-----------------------------------------------------------------------------------.
   * |  F1  |  F2  |  F3  |  F4  |  F5  |      |      |  F6  |  F7  |  F8  |  F9  | F10  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |   `  |   \  |   |  |   /  |   _  |      |      | Esc  | Left | Down |  Up  |Right |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |   ~  |   *  |   -  |   +  |   =  |      |      | Play | Vol- | Vol+ | Bri- | Bri+ |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |Shift | Bsp  |<-Ctl |      |######|      |      |      |      |
   * `-----------------------------------------------------------------------------------'
   */
  [_L2] = LAYOUT_ortho_4x12(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_NO,         KC_NO, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    KC_GRV,  KC_BSLS, KC_PIPE, KC_SLSH, KC_UNDS, KC_NO,         KC_NO, KC_ESC,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
    KC_TILD, KC_ASTR, KC_MINS, KC_PLUS, KC_EQL,  KC_NO,         KC_NO, KC_MPLY, KC_VOLD, KC_VOLU, KC_BRID, KC_BRIU,
    KC_NO,   KC_NO,   KC_NO,   KC_LSFT, KC_BSPC, LCTL(KC_LEFT), KC_NO, KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO)
};
