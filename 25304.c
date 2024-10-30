#include <stdio.h>

int main()
{
    int X, N, a, b;
    int A = 0;
    int i;

    scanf("%d", &X);
    scanf("%d", &N);


    for (i = 0; i < N; i++)
    {
        scanf("%d %d", &a, &b);
        A = A + a * b;
    }

    if (X == A)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
}