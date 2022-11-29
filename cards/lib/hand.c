#include <stdbool.h>
#include <stdlib.h>

#include "hand.h"

void sort_hand(hand_t h) {
  qsort(h, 5, sizeof(card_t), (int (*)(const void*, const void*))cmp_cards);
}

bool is_straight_flush(hand_t h) {
  return is_flush(h) && is_straight(h);
};

bool is_four_of_a_kind(hand_t h) {
  // either a, b, b, b, b
  // or     a, a, a, a, b
  sort_hand(h);
  card_t *begin = h, *end = h + 4;

  if (begin->value == h[1].value) {
    --end;
  } else {
    ++begin;
  }

  return begin->value == end->value;
};

bool is_full_house(hand_t h) {
  return is_three_of_a_kind(h) && is_pair(h);
};

bool is_flush(hand_t h) {
  color_t c = h[0].color;
  for (unsigned char i = 1; i < 5; ++i) {
    if (c != h[i].color) {
      return false;
    }
  }
  return true;
};

bool is_straight(hand_t h) {
  sort_hand(h);
  // !ACE UNIQUE
  // Can work for 5, 4, 3, 2, A and A, K, D, J, 10

  unsigned char v = h[0].value, i = 1;

  if (v == A && h[1].value == 5) {
    ++i;
  }

  for (; i < 5; ++i) {
    if (v-- != h[i].value) {
      return false;
    }
  }

  return true;
}

bool is_three_of_a_kind(hand_t h) {
  sort_hand(h);
  // A, A, A, b, c //e-rb: 4, e-re: 2
  // a, B, B, B, c //e-rb: 3, e-re: 1
  // a, b, C, C, C //e-rb: 2, e-re: 0
  card_t *rb = h, *re = h + 2, *e = h + 4;

  for (; re <= e; ++rb, ++re) {
    if (rb->value == re->value) {
      unsigned char i = (e - re) * 2;
      return re + 1 == e || h[i].value != h[i + 1].value;
    }
  }

  return false;
};

bool is_two_pairs(hand_t h) {
  if (is_three_of_a_kind(h)) {
    return false;
  }

  card_t *rb = h, *re = h + 1, *e = h + 4;
  bool pair_found = false;

  for (; re <= e; ++rb, ++re) {
    if (rb->value == re->value) {
      if (pair_found) {
        return true;
      }
      pair_found = true;
      ++rb;
      ++re;
    }
  }
  return false;
}

bool is_pair(hand_t h) {
  if (is_two_pairs(h)) {
    return false;
  }

  card_t *rb = h, *re = h + 1, *e = h + 4;
  for (; re <= e; ++rb, ++re) {
    if (rb->value == re->value) {
      ++re;
      // check for 3 or 4 of a kind
      return re > e ? true : rb->value != re->value;
    }
  }
  return false;
}

poker_hands_t hand_type(hand_t h) {
  return is_straight_flush(h)    ? STRAIGHT_FLUSH
         : is_four_of_a_kind(h)  ? FOUR_OF_A_KIND
         : is_full_house(h)      ? FULL_HOUSE
         : is_flush(h)           ? FLUSH
         : is_straight(h)        ? STRAIGHT
         : is_three_of_a_kind(h) ? THREE_OF_A_KIND
         : is_two_pairs(h)       ? TWO_PAIRS
         : is_pair(h)            ? PAIR
                                 : STRONGEST_CARD;
}