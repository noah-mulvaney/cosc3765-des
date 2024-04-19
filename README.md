# Data Encryption Standard Implementation in C

COSC3765 Computer Security Final Project  
Noah Mulvaney  
Spring 2024

## Build Instructions

On a unix-based system with the normal GNU C tools (gcc, make, libc, etc), you can run `$ make release` to compile the program. Run `$ ./bin/release` to run the program.

## Project Structure

### Block Sizes

`block.h` & `block.c`

- Block = 64 bits
- Chunk = 48 bits
- Semiblock = 32 bits
- Semikey = 28 bits
- Cell = 6 bits
- Nibble = 4 bits
- Copy bit, 1 bit -> 1 bit, `void bit(int dest, int src, char* dest_adr, char* src_adr)`

### Primitive Functions

`primitive.h` & `primitive.c`

- Expansion function, 32 bit -> 48 bit, `void expand(Chunk* dest, Semiblock* src)`
- Selection functions, 6 bit -> 4 bit, `void select(int i, Nibble* dest, Cell* src)`
- Permutation function, 32 bit -> 32 bit, `void perm(Semiblock* dest, Semiblock* src)`

### Key Schedule

`schedule.h` & `schedule.c`

- Key schedule, 64 bit -> 48 bit
- Permuted choice A, 64 bit -> 2x 28 bit
- Shift functions, 28 bit -> 28 bit
- Permuted choice B, 2x 28 bit -> 48 bit

### Encryption Structure

`encrypt.h` & `encrypt.c`

$L_n = R_{n-1}, \quad n = 1 \ldots 16$  
$R_n = L_{n-1} \oplus f(R_{n-1}, K_n)$

- Cipher function, 32 bit & 48 bit -> 32 bit
- Initial permutation, 64 bit -> 64 bit
- Inverse permutation, 64 bit -> 64 bit

### Modes of Operation

- Electric code block (ECB)
  - Encryption
  - Decryption
- Counter

## Resources

- [FIPS 46: Data Encryption Standard](https://nvlpubs.nist.gov/nistpubs/Legacy/FIPS/fipspub46-2.pdf)
- [RFC 4772: Security Implications of Using DES](https://www.rfc-editor.org/rfc/rfc4772)
