// COSC3765 Final Project: DES Implementation
// Block Sizes & Bit Operations Implementation
// Noah Mulvaney
// 8 Apr 2024

#include "block.h"

void bit(int dest_bit, int src_bit, char* dest_adr, char* src_adr) {
  char src_value = (src_adr[src_bit / 8] >> (src_bit % 8)) & 0x1;

  if (src_value) dest_adr[dest_bit / 8] |= (0x1 << (dest_adr % 8));
  // FIX dest_adr[dest_bit / 8] &= (0x0 << (dest_adr % 8));
}

