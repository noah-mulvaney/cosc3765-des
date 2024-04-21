// COSC3765 Final Project: DES Implementation
// Main File
// Noah Mulvaney
// 19 Apr 2024

#include <stdio.h>

#include "block.h"
#include "primitive.h"

void test_block();
void test_primitive();

int main(int argc, char** argv) {
  printf("Hello, world!\n");
  test_primitive();

  return 0;
}

void test_block() {
  ubyte test[] = {0x80, 0x55, 0xaa};
  print_block(test, 24);
  for (int i = 0; i < 3; ++i) {
    ubyte tmp[] = {0x00, 0xff};

    for (int j = 0; j < 16; ++j)
      bit(j, i * 8 + j % 8, tmp, test);

    print_block(tmp, 16);
  }
}

void test_primitive() {
  ubyte test[] = {0x80, 0x55, 0x01, 0xaa};
  print_block(test, 32);

  ubyte expanded[6];
  expand(expanded, test);
  print_block(expanded, 48);

  ubyte selected[4];
  select(selected, expanded);
  print_block(selected, 32);

  ubyte permuted[4];
  perm(permuted, selected);
  print_block(permuted, 32);
}
