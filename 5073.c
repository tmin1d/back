#include <stdio.h>

int main() {
    int a, b, c;

    while(1){
        scanf("%d %d %d", &a, &b, &c);

        if (a == 0 && b == 0 && c == 0) return 0;

        if (!(a + b > c && b + c > a && a + c > b)) {
            printf("Invalid\n");
            continue;
        }

        if (a == b) {
            if (b == c) {
                printf("Equilateral\n");
            }
            else printf("Isosceles\n");
        }
        else if (b == c) printf("Isosceles\n");
        else if (a == c) printf("Isosceles\n");
        else printf("Scalene\n");
    }

}
