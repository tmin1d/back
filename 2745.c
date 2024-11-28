#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char N[31];  
    int B;       
    long long result = 0; 
    int len, value;

    // 입력 받기
    scanf("%s %d", N, &B);
    
    len = strlen(N);
    
    for (int i = 0; i < len; i++) {
        if (isdigit(N[i])) {
            value = N[i] - '0';
        } else {
            value = N[i] - 'A' + 10; 
        }
        result = result * B + value; 
    }
    
    printf("%lld\n", result); 
    return 0;
}
