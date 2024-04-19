// COSC3765 Final Project: DES Implementation
// Block Sizes & Bit Operations Header
// Noah Mulvaney
// 19 Apr 2024

#ifndef BLOCK_H
#define BLOCK_H

#define BLOCK_LEN 64
#define CHUNK_LEN 48
#define SEMIBLOCK_LEN 32
#define SEMIKEY_LEN 28
#define CELL_LEN 6
#define NIBBLE_LEN 4

// print a block
void print_block(char* adr, int len);

// Copy bit from src to dest
void bit(int dest_bit, int src_bit, char* dest_adr, char* src_adr);

#endif
