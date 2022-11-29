#ifndef _CARD_H
#define _CARD_H

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

int cmp_card_vals(const card_t*, const card_t*);
int cmp_card_cols(const card_t*, const card_t*);
int cmp_cards(const card_t*, const card_t*);

card_t next_card(card_t);

#endif  // _CARD_H
