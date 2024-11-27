#include <stdio.h>

int main() {
    char s[128];
    char b[8];
    float a;
    float total = 0;
    float all = 0;

    for (int i = 0; i < 20; i++) {
        scanf("%s", s);
        scanf("%f", &a);
        scanf("%s", b);

        if (b[0] == 'A') {
            if (b[1] == '+') {
                total += 4.5 * a;
                all += a;
            }
            else {
                total += 4.0 * a;
                all += a;
            }
        }
        if (b[0] == 'B') {
            if (b[1] == '+') {
                total += 3.5 * a;
                all += a;
            }
            else {
                total += 3.0 * a;
                all += a;
            }
        }
        if (b[0] == 'C') {
            if (b[1] == '+') {
                total += 2.5 * a;
                all += a;
            }
            else {
                total += 2.0 * a;
                all += a;
            }
        }
        if (b[0] == 'D') {
            if (b[1] == '+') {
                total += 1.5 * a;
                all += a;
            }
            else {
                total += 1.0 * a;
                all += a;
            }
        }
        if (b[0] == 'F') all += a;
    }
    
    if(all != 0){
    printf("%f", total / (float)all);
    }
    else printf("%f", total);
}
