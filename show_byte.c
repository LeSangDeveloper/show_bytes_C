#include<stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    int i;
    for (i = 0; i < len; ++i) {
        printf("%.2x", start[i]);
    }

    printf("\n");
}

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void * x) {
    show_bytes((byte_pointer) &x, sizeof(void *));
}

void test_show_bytes(int val) {
    int ival = val;
    float fval = (float)ival;
    void * pval = &ival;  
    printf("\nShow bytes of int %d: ", val);
    show_int(ival);
    printf("\nShow bytes of float %f: ", fval);
    show_float(fval);
    printf("\nShow bytes of pointer void * to [%p] : ", &ival);
    show_pointer(pval);
}

int main() {
    test_show_bytes(2);

    int a = 0x12345678;
    byte_pointer ap = (byte_pointer) &a;
    show_bytes(ap, 1);
    show_bytes(ap, 2);
    show_bytes(ap, 3);
}