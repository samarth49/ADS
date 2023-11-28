#include <stdio.h>
#include <string.h>

#define SIZE 10
#define PRIME 7

void Print(int *vec, int n, char *s) {
    printf("%s: [", s);
    for (int i = 0; i < n; i++) {
        printf("%d", vec[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int Hash(int key) {
    return key % SIZE;
}

int PrimeHash(int key) {
    return PRIME - (key % PRIME);
}

int DoubleHash(int H[], int key) {
    int idx = Hash(key);
    int i = 0;
    while (H[(Hash(idx) + i * PrimeHash(idx)) % SIZE] != 0) {
        i++;
    }
    return (idx + i * PrimeHash(idx)) % SIZE;
}

void Insert(int H[], int key) {
    int idx = Hash(key);

    if (H[idx] != 0) {
        idx = DoubleHash(H, key);
    }
    H[idx] = key;
}

int Search(int H[], int key) {
    int idx = Hash(key);
    int i = 0;
    while (H[(Hash(idx) + i * PrimeHash(idx)) % SIZE] != key) {
        i++;
        if (H[(Hash(idx) + i * PrimeHash(idx)) % SIZE] == 0) {
            return -1;
        }
    }
    return (Hash(idx) + i * PrimeHash(idx)) % SIZE;
}

int main() {
    int A[] = {5, 25, 15, 35, 95};
    int n = sizeof(A) / sizeof(A[0]);
    Print(A, n, " A");

    // Hash Table
    int HT[SIZE] = {0};
    for (int i = 0; i < n; i++) {
        Insert(HT, A[i]);
    }
    Print(HT, SIZE, "HT");

    int index = Search(HT, 25);
    printf("key found at: %d\n", index);

    index = Search(HT, 35);
    printf("key found at: %d\n", index);

    return 0;
}

