#include <stdio.h>

void towerOfHanoi(int n, char a, char b, char c) {
    if (n > 0) {
        towerOfHanoi(n - 1, a, c, b);
        printf("Move disk %d from %c to %c\n", n, a, c);
        towerOfHanoi(n - 1, b, a, c);
    }
}

int main() {
    int n = 3;
    char A = 'A';
    char B = 'B';
    char C = 'C';
    towerOfHanoi(n, A, B, C);
    return 0;
}