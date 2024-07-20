// Copyright 2022 Manna Harbour
// https://github.com/manna-harbour/miryoku
// generated -*- buffer-read-only: t -*-
// target: qmk

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#pragma once

#define DLIECHTY_ALTERNATIVES_BASE_COLEMAKDH \
KC_GRV,            KC_1,              KC_2,              KC_3,              KC_4,              KC_5,              KC_6,              KC_7,              KC_8,              KC_9,              KC_0,            KC_LALT,      \
KC_TAB,            KC_Q,              KC_W,              KC_F,              KC_P,              KC_B,              KC_J,              KC_L,              KC_U,              KC_Y,              KC_QUOT,         KC_LGUI,      \
KC_LSFT,           LGUI_T(KC_A),      LALT_T(KC_R),      LCTL_T(KC_S),      LSFT_T(KC_T),      KC_G,              KC_M,              LSFT_T(KC_N),      LCTL_T(KC_E),      LALT_T(KC_I),      LGUI_T(KC_O),    KC_UP,        \
KC_LCTL,           KC_Z,              KC_X,              KC_C,              KC_D,              KC_V,              KC_K,              KC_H,              KC_COMM,           KC_DOT,            KC_SLSH,         KC_DOWN,      \
U_NP,              KC_LGUI,           KC_LALT,           LT(U_MEDIA,KC_ESC),LT(U_NAV,KC_SPC),  LT(U_MOUSE,KC_TAB),LT(U_SYM,KC_ENT),  LT(U_NUM,KC_BSPC), LT(U_FUN,KC_DEL),  KC_HYPR,           U_NP,            U_NP

#define DLIECHTY_ALTERNATIVES_BASE_COLEMAKDH_MOVEMODS \
KC_GRV,            KC_1,              KC_2,              KC_3,              KC_4,              KC_5,              KC_6,              KC_7,              KC_8,              KC_9,              KC_0,            KC_LALT,      \
KC_TAB,            KC_Q,              KC_W,              KC_F,              KC_P,              KC_B,              KC_J,              KC_L,              KC_U,              KC_Y,              KC_QUOT,         KC_LGUI,      \
KC_LSFT,           KC_A,              KC_R,              KC_S,              KC_T,              KC_G,              KC_M,              KC_N,              KC_E,              KC_I,              KC_O,            KC_UP,        \
KC_LCTL,           LGUI_T(KC_Z),      LALT_T(KC_X),      LCTL_T(KC_C),      LSFT_T(KC_D),      KC_V,              KC_K,              LSFT_T(KC_H),      LCTL_T(KC_COMM),   LALT_T(KC_DOT),    LGUI_T(KC_SLSH), KC_DOWN,      \
U_NP,              KC_LGUI,           KC_LALT,           LT(U_MEDIA,KC_ESC),LT(U_NAV,KC_SPC),  LT(U_MOUSE,KC_TAB),LT(U_SYM,KC_ENT),  LT(U_NUM,KC_BSPC), LT(U_FUN,KC_DEL),  KC_HYPR,           U_NP,            U_NP

#define DLIECHTY_ALTERNATIVES_GAME_QWERTY \
KC_GRV,            KC_1,              KC_2,              KC_3,              KC_4,              KC_5,              KC_6,              KC_7,              KC_8,              KC_9,              KC_0,            KC_LALT,      \
KC_TAB,            KC_Q,              KC_W,              KC_E,              KC_R,              KC_T,              KC_Y,              KC_U,              KC_I,              KC_O,              KC_P,            KC_LGUI,      \
KC_LSFT,           KC_A,              KC_S,              KC_D,              KC_F,              KC_G,              KC_H,              KC_J,              KC_K,              KC_L,              KC_SCLN,         KC_QUOT,      \
KC_LCTL,           KC_Z,              KC_X,              KC_C,              KC_V,              KC_B,              KC_N,              KC_M,              KC_COMM,           KC_DOT,            KC_SLSH,         KC_DOWN,      \
U_NP,              KC_LGUI,           KC_LALT,           KC_ESC,            LT(U_NAV,KC_SPC),  KC_TAB,            KC_ENT,            KC_BSPC,           LT(U_FUN,KC_DEL),  KC_HYPR,           U_NP,            U_NP

#define DLIECHTY_ALTERNATIVES_NAV \
U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,            U_NA,         \
U_NA,              TD(U_TD_BOOT),     TD(U_TD_U_GAME),   TD(U_TD_U_EXTRA),  TD(U_TD_U_BASE),   U_NA,              U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,           U_NA,         \
KC_LSFT,           KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,              CW_TOGG,           KC_LEFT,           KC_DOWN,           KC_UP,             KC_RGHT,         U_NA,         \
KC_LCTL,           KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,              KC_INS,            KC_HOME,           KC_PGDN,           KC_PGUP,           KC_END,          U_NA,         \
U_NP,              U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              KC_ENT,            KC_BSPC,           KC_DEL,            U_NP,              U_NP,            U_NP

#define DLIECHTY_ALTERNATIVES_MOUSE \
U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,            U_NA,         \
U_NA,              TD(U_TD_BOOT),     TD(U_TD_U_GAME),   TD(U_TD_U_EXTRA),  TD(U_TD_U_BASE),   U_NA,              U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,           U_NA,         \
U_NA,              KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,              U_NU,              KC_MS_L,           KC_MS_D,           KC_MS_U,           KC_MS_R,         U_NA,         \
U_NA,              KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,              U_NU,              KC_WH_L,           KC_WH_D,           KC_WH_U,           KC_WH_R,         U_NA,         \
U_NP,              U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              KC_BTN2,           KC_BTN1,           KC_BTN3,           U_NP,              U_NP,            U_NP

#define DLIECHTY_ALTERNATIVES_MEDIA \
U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,            U_NA,         \
U_NA,              TD(U_TD_BOOT),     TD(U_TD_U_GAME),   TD(U_TD_U_EXTRA),  TD(U_TD_U_BASE),   U_NA,              RGB_TOG,           RGB_MOD,           RGB_HUI,           RGB_SAI,           RGB_VAI,         U_NA,         \
U_NA,              KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,              U_NU,              KC_MPRV,           KC_VOLD,           KC_VOLU,           KC_MNXT,         RGB_SPI,      \
U_NA,              KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,              OU_AUTO,           U_NU,              U_NU,              U_NU,              U_NU,            RGB_SPD,      \
U_NP,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              KC_MSTP,           KC_MPLY,           KC_MUTE,           U_NP,              U_NP,            U_NP

#define DLIECHTY_ALTERNATIVES_NUM \
KC_GRV,            KC_1,              KC_2,              KC_3,              KC_4,              KC_5,              KC_6,              KC_7,              KC_8,              KC_9,              KC_0,            U_NA,         \
U_NA,              KC_LBRC,           KC_7,              KC_8,              KC_9,              KC_RBRC,           U_NA,              TD(U_TD_U_BASE),   TD(U_TD_U_EXTRA),  TD(U_TD_U_GAME),   TD(U_TD_BOOT),   U_NA,         \
U_NA,              KC_SCLN,           KC_4,              KC_5,              KC_6,              KC_EQL,            U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,         KC_HOME,      \
U_NA,              KC_GRV,            KC_1,              KC_2,              KC_3,              KC_BSLS,           U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,         KC_END,       \
U_NP,              U_NP,              U_NP,              KC_DOT,            KC_0,              KC_MINS,           U_NA,              U_NA,              U_NA,              U_NP,              U_NP,            U_NP

#define DLIECHTY_ALTERNATIVES_SYM \
KC_TILD,           KC_EXLM,           KC_AT,             KC_HASH,           KC_DLR,            KC_PERC,           KC_CIRC,           KC_AMPR,           KC_ASTR,           KC_LPRN,           KC_UNDS,         U_NA,         \
U_NA,              KC_LCBR,           KC_AMPR,           KC_ASTR,           KC_LPRN,           KC_RCBR,           U_NA,              TD(U_TD_U_BASE),   TD(U_TD_U_EXTRA),  TD(U_TD_U_GAME),   TD(U_TD_BOOT),   U_NA,         \
U_NA,              KC_COLN,           KC_DLR,            KC_PERC,           KC_CIRC,           KC_PLUS,           U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,         U_NA,         \
U_NA,              KC_TILD,           KC_EXLM,           KC_AT,             KC_HASH,           KC_PIPE,           U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,         U_NA,         \
U_NP,              U_NP,              U_NP,              KC_LPRN,           KC_RPRN,           KC_UNDS,           U_NA,              U_NA,              U_NA,              U_NP,              U_NP,            U_NP

#define DLIECHTY_ALTERNATIVES_FUN \
KC_F13,            KC_F14,            KC_F15,            KC_F16,            KC_F17,            KC_F18,            KC_F19,            KC_F20,            KC_F21,            KC_F22,            KC_F23,          KC_F24,       \
U_NA,              KC_F12,            KC_F7,             KC_F8,             KC_F9,             KC_PSCR,           U_NA,              TD(U_TD_U_BASE),   TD(U_TD_U_EXTRA),  TD(U_TD_U_GAME),   TD(U_TD_BOOT),   U_NA,         \
U_NA,              KC_F11,            KC_F4,             KC_F5,             KC_F6,             KC_SCRL,           U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,         KC_PAGE_UP,   \
U_NA,              KC_F10,            KC_F1,             KC_F2,             KC_F3,             KC_PAUS,           U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,         KC_PAGE_DOWN, \
U_NP,              U_NP,              U_NP,              KC_APP,            KC_SPC,            KC_TAB,            U_NA,              U_NA,              U_NA,              U_NP,              U_NP,            U_NP
