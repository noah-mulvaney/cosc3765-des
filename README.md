# Data Encryption Standard Implementation in C

COSC3765 Computer Security Final Project  
Noah Mulvaney  
Spring 2024

## Build Instructions

On a unix-based system with the normal GNU C tools (gcc, make, libc, etc), you can run `$ make release` to compile the program. Run `$ ./bin/release` to run the program.

## Project Structure

### Block Sizes

- Block = 64 bits
- Chunk = 48 bits
- Semiblock = 32 bits
- Semikey = 28 bits
- Cell = 6 bits
- Nibble = 4 bits

### Primitive Functions

- Expansion function, 32 bit -> 48 bit
- Selection functions, 6 bit -> 4 bit
- Permutation function, 32 bit -> 32 bit

### Key Schedule

- Key schedule, 64 bit -> 16x 48 bit
- Permuted choice A, 64 bit -> 2x 28 bit
- Shift functions, 28 bit -> 28 bit
- Permuted choice B, 2x 28 bit -> 48 bit

### Encryption Structure

$L_n = R_{n-1}, \quad n = 1 \ldots 16$  
$R_n = L_{n-1} \oplus f(R_{n-1}, K_n)$

- Cipher function, 32 bit & 48 bit -> 32 bit
- Initial permutation, 64 bit -> 64 bit permutation
- Inverse permutation, 64 bit -> 64 bit permutation

### Modes of Operation

- Electric code block (ECB)
  - Encryption
  - Decryption
- Counter

## Resources

- [FIPS 46: Data Encryption Standard](https://nvlpubs.nist.gov/nistpubs/Legacy/FIPS/fipspub46-2.pdf)
- [RFC 4772: Security Implications of Using DES](https://www.rfc-editor.org/rfc/rfc4772)
