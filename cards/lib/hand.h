#ifndef _HAND_H
#define _HAND_H

#include <stdbool.h>

#include "card.h"

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

#endif  // _HAND_H