#include <stdbool.h>
#include <stdio.h>

#include "poker.h"

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
