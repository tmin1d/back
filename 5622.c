#include <stdio.h>
#include <string.h>

int dial(char str) {
    if ('A' <= str && str <= 'C') return 3;
    if ('D' <= str && str <= 'F') return 4;
    if ('G' <= str && str <= 'I') return 5;
    if ('J' <= str && str <= 'L') return 6;
    if ('M' <= str && str <= 'O') return 7;
    if ('P' <= str && str <= 'S') return 8;
    if ('T' <= str && str <= 'V') return 9;
    if ('W' <= str && str <= 'Z') return 10;

    return -1; // 알파벳 이외의 문자가 들어올 경우를 대비한 기본값
}

int main() {
    char str[16];
    int total = 0;

    scanf("%s", str);

    for (int i = 0; i < strlen(str); i++) {
        total = total + dial(str[i]);
    }
    printf("%d", total);

    return 0;
}
