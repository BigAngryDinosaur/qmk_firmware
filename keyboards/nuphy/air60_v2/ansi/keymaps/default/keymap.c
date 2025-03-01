#include <stdint.h>
#include QMK_KEYBOARD_H


// TAP DANCE
enum {
    TD_ESC,
    TD_HYPER_MEH,
    TD_F13_16,
    TD_F17_20,
    TD_V,
    TD_A
};

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


td_state_t cur_dance(tap_dance_state_t *state);
td_state_t repeat_dance(tap_dance_state_t *state);

void hm_finished(tap_dance_state_t *state, void *user_data);
void hm_reset(tap_dance_state_t *state, void *user_data);

void f13_16_finished(tap_dance_state_t *state, void *user_data);
void f13_16_reset(tap_dance_state_t *state, void *user_data);

void f17_20_finished(tap_dance_state_t *state, void *user_data);
void f17_20_reset(tap_dance_state_t *state, void *user_data);

void v_finished(tap_dance_state_t *state, void *user_data);
void v_reset(tap_dance_state_t *state, void *user_data);

void a_finished(tap_dance_state_t *state, void *user_data);
void a_reset(tap_dance_state_t *state, void *user_data);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[0] = LAYOUT(
	TD(TD_ESC), 	    KC_1,           KC_2,   	KC_3,  		KC_4,   	KC_5,   	KC_6,   	KC_7,   	KC_8,   	KC_9,  		KC_0,   	KC_MINS,        KC_EQL, 	KC_BSPC,
	KC_TAB,             KC_Q,           KC_W,   	KC_E,  		KC_R,   	KC_T,   	KC_Y,   	KC_U,   	KC_I,   	KC_O,  		KC_P,   	KC_LBRC,        KC_RBRC, 	KC_BSLS,
	TD(TD_HYPER_MEH),   KC_A,   	    KC_S,       LT(2, KC_D),KC_F,   	KC_G,   	KC_H,   	KC_J,   	KC_K,   	KC_L,  		KC_SCLN,	LT(4, KC_QUOT), KC_ENT,
	KC_LSFT,            KC_Z,           KC_X,   	KC_C,  		TD(TD_V),	KC_B,   	KC_N,   	KC_M,   	KC_COMM,	KC_DOT,		KC_SLSH,	KC_RSFT,        KC_UP,		KC_DEL,
	KC_LCTL,            KC_LGUI,        KC_LALT,										KC_SPC, 							KC_RALT,	MO(1),   	KC_LEFT,        KC_DOWN,    KC_RGHT),

[1] = LAYOUT(
	SHIFT_GRV, 	KC_BRID,  	KC_BRIU,  	MAC_TASK, 	MAC_SEARCH, MAC_VOICE,  MAC_DND,  	KC_MPRV,  	KC_MPLY,  	KC_MNXT, 	KC_MUTE, 	KC_VOLD, 	KC_VOLU, 	_______,
	_______, 	LNK_BLE1,  	LNK_BLE2,  	LNK_BLE3,  	LNK_RF,   	_______,   	_______,   	_______,   	_______,   	_______,  	_______,   	DEV_RESET,	SLEEP_MODE, BAT_SHOW,
	_______, 	_______,   	_______,   	_______,  	_______,   	_______,   	_______,   	_______,   	_______,   	_______,  	_______,   	_______,	            _______,
	MO(2),	    _______,   	_______,   	_______,  	_______,   	_______,   	_______,   	MO(6),   	RGB_SPD,	RGB_SPI,  	_______,	MO(2),  	RGB_VAI,    _______,
	_______,	_______,	_______,										_______, 							_______,	_______,   	RGB_MOD,	RGB_VAD,    RGB_HUI),

[2] = LAYOUT(
	SHIFT_GRV, 	KC_F1,  	KC_F2,  	KC_F3, 		KC_F4,  	KC_F5,  	KC_F6,  	KC_F7,  	KC_F8,  	KC_F9, 		KC_F10, 	KC_F11, 	KC_F12, 	_______,
	_______, 	_______,  	_______,  	_______,  	_______,   	_______,   	_______,   	_______,   	_______,   	_______,  	_______,   	_______,	_______,    _______,
	_______, 	_______,   	_______,   	_______,  	_______,   	_______,   	KC_LEFT,   	KC_DOWN,   	KC_UP,   	KC_RIGHT,  	_______,   	_______,	            _______,
	_______,	_______,   	_______,   	_______,  	_______,   	_______,   	_______,   	_______,   	_______,   	_______,  	_______,	_______, 	_______,    _______,
	_______,	_______,	_______,										_______, 							_______,	_______,   	_______,	_______,    _______),

[3] = LAYOUT(
	KC_ESC, 	KC_1,       KC_2,   	KC_3,  		KC_4,   	KC_5,   	KC_6,   	KC_7,   	KC_8,   	KC_9,  		KC_0,   	KC_MINS,        KC_EQL, 	KC_BSPC,
	KC_TAB,     KC_Q,       KC_W,   	KC_E,  		KC_R,   	KC_T,   	KC_Y,   	KC_U,   	KC_I,   	KC_O,  		KC_P,   	KC_LBRC,        KC_RBRC, 	KC_BSLS,
	KC_CAPS,    KC_A,   	KC_S,   	KC_D,  		KC_F,   	KC_G,   	KC_H,   	KC_J,   	KC_K,   	KC_L,  		KC_SCLN,	KC_QUOT, 	    KC_ENT,
	KC_LSFT,    KC_Z,       KC_X,   	KC_C,  		KC_V,   	KC_B,   	KC_N,   	KC_M,   	KC_COMM,	KC_DOT,		KC_SLSH,	KC_RSFT,        KC_UP,		KC_DEL,
	KC_LCTL,    KC_LGUI,    KC_LALT,										KC_SPC, 							KC_RALT,	MO(1),   	KC_LEFT,        KC_DOWN,    KC_RGHT),

[4] = LAYOUT(
	SHIFT_GRV, 	_______,  	_______,  	_______, 	_______,  	_______,  	_______,  	_______,  	_______,  	_______, 	_______, 	_______, 	_______, 	_______,
	_______, 	KC_WH_U,  	KC_MS_U,  	KC_WH_D, 	_______,  	_______,  	_______,  	_______,  	_______,  	_______, 	_______, 	_______, 	_______, 	_______,
	_______, 	KC_MS_L,  	KC_MS_D,  	KC_MS_R, 	_______,  	_______,  	_______,  	KC_BTN1,  	KC_BTN2,  	_______, 	_______, 	_______, 	         	_______,
	_______,	_______,   	_______,   	_______,  	_______,   	_______,   	KC_ACL0,   	KC_ACL1,   	KC_ACL2,   	_______,  	_______,	_______, 	_______,    _______,
	_______,	_______,	_______,										_______, 							_______,	_______,   	SIDE_MOD,	SIDE_VAD,    SIDE_HUI),

[5] = LAYOUT(
	_______, 	_______,  	_______,  	_______, 	_______,  	_______,  	_______,  	_______,  	_______,  	_______, 	_______, 	_______, 	_______, 	_______,
	_______, 	KC_P7,  	KC_P8,  	KC_P9, 	    KC_PDOT,  	_______,  	_______,  	_______,  	KC_NUM,  	_______, 	_______, 	_______, 	_______, 	_______,
	_______, 	KC_P4,   	KC_P5,   	KC_P6,  	KC_P0,   	_______,   	_______,   	KC_PENT,   	KC_PPLS,   	KC_PMNS,  	_______,   	_______,	            _______,
	_______,    KC_P1,   	KC_P2,   	KC_P3,  	KC_NUBS,   	_______,   	KC_PSLS,   	KC_PAST,   	_______,	_______,  	_______,	_______,  	SIDE_VAI,    _______,
	_______,	_______,	_______,										_______, 							_______,	_______,   	SIDE_MOD,	SIDE_VAD,    SIDE_HUI),

[6] = LAYOUT(
	_______, 	_______,  	_______,  	_______, 	_______,  	_______,  	_______,  	_______,  	_______,  	_______, 	_______, 	_______, 	_______, 	_______,
	_______, 	KC_F1,  	KC_F2,  	KC_F3, 	    KC_F10,  	_______,  	_______,  	KC_F13,  	KC_F14,  	KC_F15, 	KC_F20, 	_______, 	_______, 	_______,
	_______, 	KC_F4,   	KC_F5,   	KC_F6,  	KC_F11,   	_______,   	_______,   	KC_F16,   	KC_F17,   	KC_F18,  	_______,   	_______,	            _______,
	_______,    KC_F7,   	KC_F8,   	KC_F9,  	KC_F12,   	_______,   	_______,   	KC_F19,   	_______,	_______,  	_______,	_______,  	SIDE_VAI,    _______,
	_______,	_______,	_______,										_______, 							_______,	_______,   	SIDE_MOD,	SIDE_VAD,    SIDE_HUI),

[7] = LAYOUT(
	_______, 	_______,  	_______,  	_______, 	_______,  	_______,  	_______,  	_______,  	_______,  	_______, 	_______, 	_______, 	_______, 	_______,
	_______, 	_______,  	_______,  	_______, 	_______,  	_______,  	_______,  	_______,  	_______,  	_______, 	_______, 	_______, 	_______, 	_______,
	_______, 	_______,   	_______,   	_______,  	_______,   	_______,   	_______,   	_______,   	_______,   	_______,  	_______,   	_______,	            _______,
	_______,    _______,   	_______,   	_______,  	_______,   	_______,   	_______,   	_______,   	SIDE_SPD,	SIDE_SPI,  	_______,	_______,  	SIDE_VAI,    _______,
	_______,	_______,	_______,										_______, 							_______,	_______,   	SIDE_MOD,	SIDE_VAD,    SIDE_HUI),
};


const is31_led PROGMEM g_is31_leds[RGB_MATRIX_LED_COUNT] = {
    {0, A_16,   B_16,   C_16},      // "Esc"
    {0, A_2,    B_2,    C_2},       // "!1"
    {0, A_3,    B_3,    C_3},       // "@2"
    {0, A_4,    B_4,    C_4},       // "#3"
    {0, A_5,    B_5,    C_5},       // "$4"
    {0, A_6,    B_6,    C_6},       // "%5"
    {0, A_7,    B_7,    C_7},       // "^6"
    {0, A_8,    B_8,    C_8},       // "&7"
    {0, A_9,    B_9,    C_9},       // "*8"
    {0, A_10,   B_10,   C_10},      // "(9"
    {0, A_11,   B_11,   C_11},      // ")0"
    {1, D_1,    E_1,    F_1},       // "_-"
    {1, D_2,    E_2,    F_2},       // "+="
    {1, D_3,    E_3,    F_3},       // "Backsp"
    {0, D_1,    E_1,    F_1},       // "Tab"
    {0, D_2,    E_2,    F_2},       // "Q"
    {0, D_3,    E_3,    F_3},       // "W"
    {0, D_4,    E_4,    F_4},       // "E"
    {0, D_5,    E_5,    F_5},       // "R"
    {0, D_6,    E_6,    F_6},       // "T"
    {0, D_7,    E_7,    F_7},       // "Y"
    {0, D_8,    E_8,    F_8},       // "U"
    {0, D_9,    E_9,    F_9},       // "I"
    {0, D_10,   E_10,   F_10},      // "O"
    {0, D_11,   E_11,   F_11},      // "P"
    {1, G_1,    H_1,    I_1},       // "{["
    {1, G_2,    H_2,    I_2},       // "}]"
    {1, G_3,    H_3,    I_3},       // "|\\"
    {0, G_1,    H_1,    I_1},       // "Caps"
    {0, G_2,    H_2,    I_2},       // "A"
    {0, G_3,    H_3,    I_3},       // "S"
    {0, G_4,    H_4,    I_4},       // "D"
    {0, G_5,    H_5,    I_5},       // "F"
    {0, G_6,    H_6,    I_6},       // "G"
    {0, G_7,    H_7,    I_7},       // "H"
    {0, G_8,    H_8,    I_8},       // "J"
    {0, G_9,    H_9,    I_9},       // "K"
    {0, G_10,   H_10,   I_10},      // "L"
    {0, G_11,   H_11,   I_11},      // ":"
    {1, G_16,   H_16,   I_16},      // "\""
    {1, G_14,   H_14,   I_14},      // "Enter"
    {0, J_1,    K_1,    L_1},       // "Shift"
    {0, J_3,    K_3,    L_3},       // "Z"
    {0, J_4,    K_4,    L_4},       // "X"
    {0, J_5,    K_5,    L_5},       // "C"
    {0, J_6,    K_6,    L_6},       // "V"
    {0, J_7,    K_7,    L_7},       // "B"
    {0, J_8,    K_8,    L_8},       // "N"
    {0, J_9,    K_9,    L_9},       // "M"
    {0, J_10,   K_10,   L_10},      // "<,"
    {0, J_11,   K_11,   L_11},      // ">."
    {1, J_1,    K_1,    L_1},       // "?/"
    {1, J_3,    K_3,    L_3},       // "Shift"
    {1, J_4,    K_4,    L_4},       // "↑"
    {1, G_4,    H_4,    I_4},       // "Del"
    {0, J_16,   K_16,   L_16},      // "Ctrl"
    {0, J_15,   K_15,   L_15},      // "Opt"
    {0, J_14,   K_14,   L_14},      // "Cmd"
    {0, J_13,   K_13,   L_13},      // "Space"
    {0, J_12,   K_12,   L_12},      // "Cmd"
    {1, J_16,   K_16,   L_16},      // "Fn"
    {1, J_13,   K_13,   L_13},      // "←"
    {1, J_12,   K_12,   L_12},      // "↓"
    {1, J_11,   K_11,   L_11},      // "→"

    {1, A_5,    B_5,    C_5},       // logo left
    {1, A_4,    B_4,    C_4},       //
    {1, A_3,    B_3,    C_3},       //
    {1, A_2,    B_2,    C_2},       //
    {1, A_1,    B_1,    C_1},       //

    {1, A_6,    B_6,    C_6},       // logo right
    {1, A_7,    B_7,    C_7},       //
    {1, A_8,    B_8,    C_8},       //
    {1, A_9,    B_9,    C_9},       //
    {1, A_10,   B_10,   C_10}       //
};

// Tapping Term
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TD(TD_ESC):
            return 200;
        case TD(TD_HYPER_MEH):
            return 200;
        case TD(TD_F13_16):
            return 150;
        case TD(TD_F17_20):
            return 150;
        case TD(TD_V):
            return 200;
        case TD(TD_A):
            return 200;
        default:
            return TAPPING_TERM;
    }
}

// Tap Dance
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

td_state_t repeat_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        return TD_SINGLE_TAP;
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


// -------------------------


// TD: Esc
void dance_esc(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            tap_code(KC_ESC);
            break;
        case 2:
            tap_code(KC_GRV);
            break;
        default:
            reset_tap_dance(state);
    }
}

// TD: Hyper Meh
static td_tap_t hm_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void hm_finished(tap_dance_state_t *state, void *user_data) {
    hm_tap_state.state = cur_dance(state);
    switch (hm_tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_PAGE_UP); break;
        case TD_SINGLE_HOLD: register_code(KC_PAGE_UP); break;
        case TD_DOUBLE_TAP: register_code(KC_END); break;
        case TD_DOUBLE_HOLD: register_code(KC_PAGE_DOWN); break;
        default: break;
    }
}

void hm_reset(tap_dance_state_t *state, void *user_data) {
    switch (hm_tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_PAGE_UP); break;
        case TD_SINGLE_HOLD: unregister_code(KC_PAGE_UP); break;
        case TD_DOUBLE_TAP: unregister_code(KC_END); break;
        case TD_DOUBLE_HOLD: unregister_code(KC_PAGE_DOWN); break;
        default: break;
    }
    hm_tap_state.state = TD_NONE;
}

// TD: V
static td_tap_t v_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void v_finished(tap_dance_state_t *state, void *user_data) {
    v_tap_state.state = repeat_dance(state);
    switch (v_tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_V); break;
        case TD_SINGLE_HOLD: register_code(KC_V); break;
        case TD_DOUBLE_TAP: register_code(KC_HOME); break;
        case TD_DOUBLE_HOLD: register_code(KC_INSERT); break;
        case TD_DOUBLE_SINGLE_TAP: register_code(KC_V); break;
        default: break;
    }
}

void v_reset(tap_dance_state_t *state, void *user_data) {
    switch (v_tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_V); break;
        case TD_SINGLE_HOLD: unregister_code(KC_V); break;
        case TD_DOUBLE_TAP: unregister_code(KC_HOME); break;
        case TD_DOUBLE_HOLD: unregister_code(KC_INSERT); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_V); break;
        default: break;
    }
    v_tap_state.state = TD_NONE;
}

// TD: A
static td_tap_t a_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void a_finished(tap_dance_state_t *state, void *user_data) {
    a_tap_state.state = repeat_dance(state);
    switch (a_tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_A); break;
        case TD_SINGLE_HOLD: register_code(KC_A); break;
        case TD_DOUBLE_TAP: register_code(KC_PEQL); break;
        case TD_DOUBLE_HOLD: register_code(KC_RGUI); break;
        case TD_DOUBLE_SINGLE_TAP: register_code(KC_A); break;
        default: break;
    }
}

void a_reset(tap_dance_state_t *state, void *user_data) {
    switch (a_tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_A); break;
        case TD_SINGLE_HOLD: unregister_code(KC_A); break;
        case TD_DOUBLE_TAP: unregister_code(KC_PEQL); break;
        case TD_DOUBLE_HOLD: unregister_code(KC_RGUI); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_A); break;
        default: break;
    }
    a_tap_state.state = TD_NONE;
}

// TD: F13 - F16
static td_tap_t f13_16_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void f13_16_finished(tap_dance_state_t *state, void *user_data) {
    f13_16_tap_state.state = cur_dance(state);
    switch (f13_16_tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_F13); break;
        case TD_SINGLE_HOLD: register_code(KC_F14); break;
        case TD_DOUBLE_TAP: register_code(KC_F15); break;
        case TD_DOUBLE_HOLD: register_code(KC_F16); break;
        default: break;
    }
}

void f13_16_reset(tap_dance_state_t *state, void *user_data) {
    switch (f13_16_tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_Z); break;
        case TD_SINGLE_HOLD: unregister_code(KC_F13); break;
        case TD_DOUBLE_TAP: unregister_code(KC_F14); break;
        case TD_DOUBLE_HOLD: unregister_code(KC_F15); break;
        default: break;
    }
    f13_16_tap_state.state = TD_NONE;
}


// TD: F17 - F20
static td_tap_t f17_f20_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void f17_20_finished(tap_dance_state_t *state, void *user_data) {
    f17_f20_tap_state.state = cur_dance(state);
    switch (f17_f20_tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_F17); break;
        case TD_SINGLE_HOLD: register_code(KC_F18); break;
        case TD_DOUBLE_TAP: register_code(KC_F19); break;
        case TD_DOUBLE_HOLD: register_code(KC_F20); break;
        default: break;
    }
}

void f17_20_reset(tap_dance_state_t *state, void *user_data) {
    switch (f17_f20_tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_F17); break;
        case TD_SINGLE_HOLD: unregister_code(KC_F18); break;
        case TD_DOUBLE_TAP: unregister_code(KC_F19); break;
        case TD_DOUBLE_HOLD: unregister_code(KC_F20); break;
        default: break;
    }
    f17_f20_tap_state.state = TD_NONE;
}


// TD Definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_ESC] = ACTION_TAP_DANCE_FN(dance_esc),
    [TD_HYPER_MEH] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, hm_finished, hm_reset),
    [TD_F13_16] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, f13_16_finished, f13_16_reset),
    [TD_F17_20] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, f17_20_finished, f17_20_reset),
    [TD_V] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, v_finished, v_reset),
    [TD_A] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, a_finished, a_reset)
};



// COMBO
const uint16_t PROGMEM combo1[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM combo2[] = {KC_K, KC_L, COMBO_END};
combo_t key_combos[] = {
    COMBO(combo1, OSL(5)),
    COMBO(combo2, OSL(6)),
};
