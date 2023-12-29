// SPDX-License-Identifier: MIT OR Apache-2.0 OR GPL-2.0-or-later OR
// Karl Palsson <karlp@tweak.au> 2023
#include <stdbool.h>

#include <quantum.h>

struct special_pin_s {
    pin_t    pin;
    uint32_t fake_row;
    uint32_t fake_col;
};

// These are our direct connected pins
struct special_pin_s specials[] = {
    {A3, 8, 0}, {B8, 8, 1}, {C15, 8, 2}, {C14, 8, 3}, {C13, 8, 4},
};

void keyboard_pre_init_user(void) {
    // turn off USB-C-PD peripheral, we need those pins please.
    PWR->CR3 |= PWR_CR3_UCPD_DBDIS;
}

void keyboard_post_init_user(void) {
    debug_config.enable = true;
    debug_config.matrix = true;
}

extern matrix_row_t matrix[MATRIX_ROWS];

void matrix_scan_user(void) {
    for (int i = 0; i < ARRAY_SIZE(specials); i++) {
        struct special_pin_s *s   = &specials[i];
        // Because we placed our direct pins into the matrix, make sure it's back to a plain input for us.
        setPinInputLow(s->pin);
        uint8_t val = readPin(s->pin);
        // make sure it's cleared first.
        matrix[s->fake_row] &= ~(1 << s->fake_col);
        matrix[s->fake_row] |= (val << s->fake_col);
    }
}
