#include <stdio.h>
#include <math.h>

int main(){

    int a;
    int b;
    int v;
    int k;

    scanf("%d %d %d", &a, &b, &v);

    k = ceil(((v - a) /(double)(a - b)) + 1);
    printf("%d\n", k);

}
