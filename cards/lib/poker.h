#ifndef _POKER_H
#define _POKER_H

#include <stdbool.h>

enum card_value {
  J = 11,
  Q = 12,
  K = 13,
  A = 14,
};

typedef enum color {
  SPADE = 1,
  CLUB,
  DIAMOND,
  HEART,
} color_t;

typedef struct card {
  color_t color;
  unsigned char value;
} card_t;

typedef card_t hand_t[5];

typedef enum poker_hands {
  STRONGEST_CARD,
  PAIR,
  TWO_PAIRS,
  THREE_OF_A_KIND,
  STRAIGHT,
  FLUSH,
  FULL_HOUSE,
  FOUR_OF_A_KIND,
  STRAIGHT_FLUSH,
} poker_hands_t;

int cmp_card_vals(const card_t*, const card_t*);
int cmp_card_cols(const card_t*, const card_t*);
int cmp_cards(const card_t*, const card_t*);

void sort_hand(hand_t);

poker_hands_t hand_type(hand_t);

bool is_straight_flush(hand_t);
bool is_four_of_a_kind(hand_t);
bool is_full_house(hand_t);
bool is_flush(hand_t);
bool is_straight(hand_t);
bool is_three_of_a_kind(hand_t);
bool is_two_pairs(hand_t);
bool is_pair(hand_t);

#endif  // _POKER_H
