#include <stdint.h>
#include <stdlib.h>
#include <qrcode.h>

uint16_t qrcode_get_buffer_size(uint8_t version) {
    // V1 is 21x21 -> addition versions: +=4
    return (21 + 4 * version) * (21 + 4 * version);
}

int8_t qrcode_encode_text(const char* text) {
    uint8_t version = 2;
    uint8_t size = qrcode_get_buffer_size(version);
    uint8_t* modules = calloc(size, sizeof(uint8_t));

    
}