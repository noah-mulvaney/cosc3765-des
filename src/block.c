// COSC3765 Final Project: DES Implementation
// Block Sizes & Bit Operations Implementation
// Noah Mulvaney
// 19 Apr 2024

#include <assert.h>
#include <stdio.h>

#include "block.h"

void print_block(char* adr, int len) {
  assert(len < BLOCK_LEN);

  for (int i = 0; i < len; ++i) {
    printf("%d", (adr[i / 8] >> (7 - (i % 8))) & 0x1);
    if (i % 8 == 7) printf(" ");
  }
  printf("\n");
}

void bit(int dest_bit, int src_bit, char* dest_adr, char* src_adr) {
  assert(dest_bit < BLOCK_LEN && src_bit < BLOCK_LEN);

  char src_value = (src_adr[src_bit / 8] >> ((7 - src_bit) % 8)) & 0x1;

  if (src_value) dest_adr[dest_bit / 8] |= (0x1 << ((7 - dest_bit) % 8));
  else dest_adr[dest_bit / 8] &= (0xff ^ (0x1 << ((7 - dest_bit) % 8)));
}
