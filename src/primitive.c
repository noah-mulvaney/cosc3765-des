// COSC3765 Final Project: DES Implementation
// Primitive Functions Implementation
// Noah Mulvaney
// 20 Apr 2024

#include <assert.h>

#include "block.h"
#include "primitive.h"

const int EXPANSION_TABLE[] = 
  {32,  1,  2,  3,  4,  5,
    4,  5,  6,  7,  8,  9,
    8,  9, 10, 11, 12, 13,
   12, 13, 14, 15, 16, 17,
   16, 17, 18, 19, 20, 21,
   20, 21, 22, 23, 24, 25,
   24, 25, 26, 27, 28, 29,
   28, 29, 30, 31, 32,  1};

const int SELECT_TABLES[][4][16] = // ADD tables 2 to 8
  {{{14,  4, 13,  1,  2, 15, 11,  8,  3, 10,  6, 12,  5,  9,  0,  7},
    { 0, 15,  7,  4, 14,  2, 13,  1, 10,  6, 12, 11,  9,  5,  3,  8},
    { 4,  1, 14,  8, 13,  6,  2, 11, 15, 12,  9,  7,  3, 10,  5,  0},
    {15, 12,  8,  2,  4,  9,  1,  7,  5, 11,  3, 14, 10,  0,  6, 13}}};

const int PERMUTATION_TABLE[] =
  {16,  7, 20, 21,
   29, 12, 28, 17,
    1, 15, 23, 26,
    5, 18, 31, 10,
    2,  8, 24, 14,
   32, 27,  3,  9,
   19, 13, 30,  6,
   22, 11,  4, 25};

void expand(ubyte* dest_chunk, ubyte* src_semiblock) {
  for (int i = 0; i < CHUNK_LEN; ++i)
    bit(i, EXPANSION_TABLE[i] - 1, dest_chunk, src_semiblock);
}

void select(int s, ubyte* dest_nibble, ubyte* src_cell) {
  int i = ((src_cell[0] & 0x20) >> 4) + (src_cell[0] & 0x01);
  int j = (src_cell[0] & 0x1e) >> 1;

  assert(i >= 0 && i < 4);
  assert(j >= 0 && j < 16);

  // ADD tables 2 to 8
  *dest_nibble = SELECT_TABLES[0][i][j];
}

void perm(ubyte* dest_semiblock, ubyte* src_semiblock) {
  for (int i = 0; i < SEMIBLOCK_LEN; ++i)
    bit(i, PERMUTATION_TABLE[i] - 1, dest_semiblock, src_semiblock);
}