#include <stdio.h>
#include <stdint.h>

// 1024-bit type = 32 words of 32 bits
typedef struct {
    uint32_t words[32];   // words[0] = LSB, words[31] = MSB
} uint1024_t;


// Set a 1024-bit number from a 64-bit integer (for testing)
void set_uint1024(uint1024_t *x, uint64_t val) {
    for (int i = 0; i < 32; i++) x->words[i] = 0;
    x->words[0] = (uint32_t)(val & 0xFFFFFFFFULL);
    x->words[1] = (uint32_t)(val >> 32);
}

void print_uint1024(const uint1024_t *x) {
    int started = 0;
    for (int i = 31; i >= 0; i--) {
        if (!started && x->words[i] == 0) continue;
        if (!started) {
            printf("%X", x->words[i]); // first nonzero word
            started = 1;
        } else {
            printf("%08X", x->words[i]); // pad rest
        }
    }
    if (!started) printf("0");  // all zero
}

// =============== COMPARISON =================

// Return 1 if a > b, else 0
int gt_uint1024(const uint1024_t *a, const uint1024_t *b) {
    for (int i = 31; i >= 0; i--) {
        if (a->words[i] > b->words[i]) return 1;   // a bigger
        if (a->words[i] < b->words[i]) return 0;   // b bigger
    }
    return 0;   // equal → not greater
}

// =============== MAIN WITH TEST VECTORS =================

int main() {
    uint1024_t a, b;

    // Test 1: 5 > 3
    set_uint1024(&a, 5);
    set_uint1024(&b, 3);
    printf("Test 1: ");
    print_uint1024(&a); printf(" > "); print_uint1024(&b);
    printf(" ? %d\n", gt_uint1024(&a, &b));

    // Test 2: 100 < 200
    set_uint1024(&a, 100);
    set_uint1024(&b, 200);
    printf("Test 2: ");
    print_uint1024(&a); printf(" > "); print_uint1024(&b);
    printf(" ? %d\n", gt_uint1024(&a, &b));

    // Test 3: very large number > 0
    for (int i = 0; i < 32; i++) a.words[i] = 0xFFFFFFFF;
    for (int i = 0; i < 32; i++) b.words[i] = 0;
    printf("Test 3: ");
    print_uint1024(&a); printf(" > "); print_uint1024(&b);
    printf(" ? %d\n", gt_uint1024(&a, &b));

    // Test 4: equal numbers
    set_uint1024(&a, 5000);
    set_uint1024(&b, 5000);
    printf("Test 4: ");
    print_uint1024(&a); printf(" > "); print_uint1024(&b);
    printf(" ? %d\n", gt_uint1024(&a, &b));

    return 0;
}
