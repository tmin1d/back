#include <stdio.h>

int main() {
    int H, M;

    scanf("%d %d", &H, &M);

    M = M - 45;
    if (M < 0) {
        M = 60 + M;
        H = H - 1;
    }
    if (H < 0) {
        H = 23;
    }
    printf("%d %d", H, M);
}