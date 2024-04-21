// COSC3765 Final Project: DES Implementation
// Primitive Functions Header
// Noah Mulvaney
// 20 Apr 2024

#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include "block.h"

void expand(ubyte* dest_chunk, ubyte* src_semiblock);

void select(ubyte* dest_semiblock, ubyte* src_chunk);

void perm(ubyte* dest_semiblock, ubyte* src_semiblock);

#endif
