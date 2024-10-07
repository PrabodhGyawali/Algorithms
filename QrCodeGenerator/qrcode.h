#include <stdio.h>
#include <stdint.h>


typedef unsigned int t_flag;
#define MODE_NUMERIC 0x1
#define MODE_ALPHANUMERIC 0x2
#define MODE_BYTE 0x3
#define MODE_KANJI 0x4

// ERROR correction modes
#define ECC_LOW  0x1
#define ECC_MEDIUM 0x2
#define ECCC_QUARTILE 0x3
#define ECC_HIGHT 0x4

/**
 * version: V1 to V40 -> V1: 21x21 -> V++ = (m+4)x(n+4)
 * size: number of modules per side
 * ecc: L, M, Q, H levels of correction
 * mode: Encoding mode used
 * mask: 
 * modules: 1 for black, 0 for white
 */
typedef struct QRCode {
    uint8_t version;
    uint8_t size;
    uint8_t ecc;
    uint8_t mode;
    uint8_t mask;
    uint8_t* modules;
} QRCode;

uint16_t qrcode_get_buffer_size(uint8_t version);

int8_t qrcode_encode_text(const char* text);

