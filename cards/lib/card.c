#include <stdbool.h>
#include <stdio.h>

#include "card.h"

int cmp_card_vals(const card_t* x, const card_t* y) {
  return y->value - x->value;
}

int cmp_card_cols(const card_t* x, const card_t* y) {
  return y->color - x->color;
}

int cmp_cards(const card_t* x, const card_t* y) {
  int result = cmp_card_vals(x, y);
  if (result == 0) {
    return cmp_card_cols(x, y);
  }
  return result;
}

// Currently card's size is <= sizeof(*) -> copying it is much faster than going
// through pointer
card_t next_card(card_t c) {
  if (++c.color <= HEART) {
    return c;
  }

  if (++c.value > A) {
    c.value = 2;
  }

  return c;
}