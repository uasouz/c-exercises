//
// Created by hadara on 4/17/19.
//

#include <stdlib.h>
#include <inttypes.h>
#include "hashmap.h"

#define FNV32_BASE ((unsigned int) 0x811c9dc5)
#define FNV32_PRIME ((unsigned int) 0x01000193)

#define FNV64_BASE ((uint64_t) 0xcbf29ce484222325)
#define FNV64_PRIME ((uint64_t) 0x100000001b3)

//FNV-1 32 Bit
unsigned int hash(const void *buf, size_t len) {
    unsigned int hash = FNV32_BASE;
    unsigned char *ucbuf = (unsigned char *) buf;
    while (len--) {
        unsigned int c = *ucbuf++;
        hash = (hash * FNV32_PRIME) ^ c;
    }
    return hash;
}

//FNV-1a 32 Bit
//To test
unsigned int hash1a(const void *buf, size_t len) {
    unsigned int hash = FNV32_BASE;
    unsigned char *ucbuf = (unsigned char *) buf;
    while (len--) {
        unsigned int c = *ucbuf++;
        hash = hash ^ c;
        hash = (hash * FNV32_PRIME);
    }
    return hash;
}

//FNV-1 64 Bit
//TO Test
uint64_t hash64(const void *buf, size_t len) {
    uint64_t hash = FNV64_BASE;
    unsigned char *ucbuf = (unsigned char *) buf;
    while (len--) {
        uint64_t c = *ucbuf++;
        hash = (hash * FNV64_PRIME) ^ c;
    }
    return hash;
}

//FNV-1a 64 Bit
//TO Test
uint64_t hash641a(const void *buf, size_t len) {
    uint64_t hash = FNV64_BASE;
    unsigned char *ucbuf = (unsigned char *) buf;
    while (len--) {
        uint64_t c = *ucbuf++;
        hash = hash ^ c;
        hash = (hash * FNV64_PRIME);
    }
    return hash;
}