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

int main() {
    int x = 2;
    float x2 = 2.0;
    void *x3 = &x2;  
    printf("\nShow bytes of int 2: ");
    show_int(x);
    printf("\nShow bytes of float 2.0 at %.2x : ", &x2);
    show_float(x2);
    printf("\nShow bytes of pointer void * :");
    show_pointer(x3);
}