#include <stdio.h>

#include "poker.h"

// clang-format off
hand_t hands[] = {
  {{SPADE, 2}, {DIAMOND, 2}, {HEART, 4}, {DIAMOND, 3}, {CLUB, J}}, // Pair
  {{SPADE, 2}, {DIAMOND, 2}, {HEART, 3}, {DIAMOND, 3}, {CLUB, J}}, // Two pairs
  {{SPADE, 2}, {DIAMOND, 2}, {HEART, 2}, {DIAMOND, 3}, {CLUB, J}}, // Three of a kind
  {{SPADE, A}, {DIAMOND, 2}, {HEART, 4}, {DIAMOND, 3}, {CLUB, 5}}, // Straight
  {{CLUB,  A}, {CLUB,    2}, {CLUB,  4}, {CLUB,    3}, {CLUB, 7}}, // Flush
  {{SPADE, 2}, {DIAMOND, 2}, {HEART, 3}, {DIAMOND, 3}, {CLUB, 3}}, // Full house
  {{SPADE, 2}, {DIAMOND, 2}, {HEART, 2}, {DIAMOND, 2}, {CLUB, 3}}, // Four of a kind
  {{CLUB,  A}, {CLUB,    2}, {CLUB,  4}, {CLUB,    3}, {CLUB, 5}}, // Straigh flush
};
// clang-format on

int main() {
  printf("Is four of a kind: %s\n", is_four_of_a_kind(hands[6]) ? "Yes" : "No");
  printf("Is four of a kind: %s\n", is_four_of_a_kind(hands[0]) ? "Yes" : "No");
  printf("Is four of a kind: %s\n", is_four_of_a_kind(hands[1]) ? "Yes" : "No");

  printf("Is pair: %s\n", is_pair(hands[6]) ? "Yes" : "No");
  printf("Is pair: %s\n", is_pair(hands[0]) ? "Yes" : "No");
  printf("Is pair: %s\n", is_pair(hands[1]) ? "Yes" : "No");

  printf("Is two pairs: %s\n", is_two_pairs(hands[6]) ? "Yes" : "No");
  printf("Is two pairs: %s\n", is_two_pairs(hands[0]) ? "Yes" : "No");
  printf("Is two pairs: %s\n", is_two_pairs(hands[1]) ? "Yes" : "No");
  return 0;
}
