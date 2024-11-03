//USING POINTERS

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a, b;
    scanf("%d %d", &a, &b);

    int *pa = &a, *pb = &b;

    int dif = abs(*pa - *pb);

    printf("%d", dif);

    return 0;
}