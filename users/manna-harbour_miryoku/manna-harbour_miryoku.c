// Copyright 2022 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#include QMK_KEYBOARD_H

#include "manna-harbour_miryoku.h"


// Additional Features double tap guard
// Also tap-dance for tap-hold-repeat for layers

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

// tap dance enums
enum {
    U_TD_SPC_NAV,
    U_TD_TAB_MOUSE,
    U_TD_ENT_SYM,
    U_TD_BSPC_NUM,
    U_TD_DEL_FUN,
    U_TD_BOOT,
#define MIRYOKU_X(LAYER, STRING) U_TD_U_##LAYER,
MIRYOKU_LAYER_LIST
#undef MIRYOKU_X
};

// functions for tap-hold-repeat tap dance
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}

// Create an instance of 'td_tap_t' for the 'spc' tap dance.
static td_tap_t spctap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

// Create an instance of 'td_tap_t' for the 'tab' tap dance.
static td_tap_t tabtap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

// Create an instance of 'td_tap_t' for the 'ent' tap dance.
static td_tap_t enttap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

// Create an instance of 'td_tap_t' for the 'bspc' tap dance.
static td_tap_t bspctap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

// Create an instance of 'td_tap_t' for the 'del' tap dance.
static td_tap_t deltap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void finished(td_state_t state, uint8_t key, uint8_t layer) {
    switch (state) {
        case TD_SINGLE_TAP: register_code(key); break;
        case TD_SINGLE_HOLD: layer_on(layer); break;
        case TD_DOUBLE_TAP: register_code(key); break;
        case TD_DOUBLE_HOLD: register_code(key); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not the double tap key.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP: tap_code(key); register_code(key); break;
        default: break;
    }
}

void reset(td_state_t state, uint8_t key, uint8_t layer) {
    switch (state) {
        case TD_SINGLE_TAP: unregister_code(key); break;
        case TD_SINGLE_HOLD: layer_off(layer); break;
        case TD_DOUBLE_TAP: unregister_code(key); break;
        case TD_DOUBLE_HOLD: unregister_code(key); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(key); break;
        default: break;
    }
}

void spc_finished(tap_dance_state_t *state, void *user_data) {
    spctap_state.state = cur_dance(state);
    finished(spctap_state.state, KC_SPC, U_NAV);
}

void spc_reset(tap_dance_state_t *state, void *user_data) {
    reset(spctap_state.state, KC_SPC, U_NAV);
    spctap_state.state = TD_NONE;
}

void tab_finished(tap_dance_state_t *state, void *user_data) {
    tabtap_state.state = cur_dance(state);
    finished(tabtap_state.state, KC_TAB, U_MOUSE);
}

void tab_reset(tap_dance_state_t *state, void *user_data) {
    reset(tabtap_state.state, KC_TAB, U_MOUSE);
    tabtap_state.state = TD_NONE;
}

void ent_finished(tap_dance_state_t *state, void *user_data) {
    enttap_state.state = cur_dance(state);
    finished(enttap_state.state, KC_ENT, U_SYM);
}

void ent_reset(tap_dance_state_t *state, void *user_data) {
    reset(enttap_state.state, KC_ENT, U_SYM);
    enttap_state.state = TD_NONE;
}

void bspc_finished(tap_dance_state_t *state, void *user_data) {
    bspctap_state.state = cur_dance(state);
    finished(bspctap_state.state, KC_BSPC, U_NUM);
}

void bspc_reset(tap_dance_state_t *state, void *user_data) {
    reset(bspctap_state.state, KC_BSPC, U_NUM);
    bspctap_state.state = TD_NONE;
}

void del_finished(tap_dance_state_t *state, void *user_data) {
    deltap_state.state = cur_dance(state);
    finished(deltap_state.state, KC_DEL, U_FUN);
}

void del_reset(tap_dance_state_t *state, void *user_data) {
    reset(deltap_state.state, KC_DEL, U_FUN);
    deltap_state.state = TD_NONE;
}


// functions for double tap guard on extra layer switch
void u_td_fn_boot(tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
    reset_keyboard();
  }
}

#define MIRYOKU_X(LAYER, STRING) \
void u_td_fn_U_##LAYER(tap_dance_state_t *state, void *user_data) { \
  if (state->count == 2) { \
    default_layer_set((layer_state_t)1 << U_##LAYER); \
  } \
}
MIRYOKU_LAYER_LIST
#undef MIRYOKU_X

tap_dance_action_t tap_dance_actions[] = {
    [U_TD_SPC_NAV] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, spc_finished, spc_reset),
    [U_TD_TAB_MOUSE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, tab_finished, tab_reset),
    [U_TD_ENT_SYM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ent_finished, ent_reset),
    [U_TD_BSPC_NUM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, bspc_finished, bspc_reset),
    [U_TD_DEL_FUN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, del_finished, del_reset),
    [U_TD_BOOT] = ACTION_TAP_DANCE_FN(u_td_fn_boot),
#define MIRYOKU_X(LAYER, STRING) [U_TD_U_##LAYER] = ACTION_TAP_DANCE_FN(u_td_fn_U_##LAYER),
MIRYOKU_LAYER_LIST
#undef MIRYOKU_X
};


// keymap

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
#define MIRYOKU_X(LAYER, STRING) [U_##LAYER] = U_MACRO_VA_ARGS(MIRYOKU_LAYERMAPPING_##LAYER, MIRYOKU_LAYER_##LAYER),
MIRYOKU_LAYER_LIST
#undef MIRYOKU_X
};


// shift functions

const key_override_t capsword_key_override = ko_make_basic(MOD_MASK_SHIFT, CW_TOGG, KC_CAPS);

const key_override_t **key_overrides = (const key_override_t *[]){
    &capsword_key_override,
    NULL
};


// thumb combos

#if defined (MIRYOKU_KLUDGE_THUMBCOMBOS)
const uint16_t PROGMEM thumbcombos_base_right[] = {LT(U_SYM, KC_ENT), LT(U_NUM, KC_BSPC), COMBO_END};
const uint16_t PROGMEM thumbcombos_base_left[] = {LT(U_NAV, KC_SPC), LT(U_MOUSE, KC_TAB), COMBO_END};
const uint16_t PROGMEM thumbcombos_nav[] = {KC_ENT, KC_BSPC, COMBO_END};
const uint16_t PROGMEM thumbcombos_mouse[] = {KC_BTN2, KC_BTN1, COMBO_END};
const uint16_t PROGMEM thumbcombos_media[] = {KC_MSTP, KC_MPLY, COMBO_END};
const uint16_t PROGMEM thumbcombos_num[] = {KC_0, KC_MINS, COMBO_END};
  #if defined (MIRYOKU_LAYERS_FLIP)
const uint16_t PROGMEM thumbcombos_sym[] = {KC_UNDS, KC_LPRN, COMBO_END};
  #else
const uint16_t PROGMEM thumbcombos_sym[] = {KC_RPRN, KC_UNDS, COMBO_END};
  #endif
const uint16_t PROGMEM thumbcombos_fun[] = {KC_SPC, KC_TAB, COMBO_END};
combo_t key_combos[] = {
  COMBO(thumbcombos_base_right, LT(U_FUN, KC_DEL)),
  COMBO(thumbcombos_base_left, LT(U_MEDIA, KC_ESC)),
  COMBO(thumbcombos_nav, KC_DEL),
  COMBO(thumbcombos_mouse, KC_BTN3),
  COMBO(thumbcombos_media, KC_MUTE),
  COMBO(thumbcombos_num, KC_DOT),
  #if defined (MIRYOKU_LAYERS_FLIP)
  COMBO(thumbcombos_sym, KC_RPRN),
  #else
  COMBO(thumbcombos_sym, KC_LPRN),
  #endif
  COMBO(thumbcombos_fun, KC_APP)
};
#endif
