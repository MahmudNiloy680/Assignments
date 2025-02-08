#include <stdio.h>

int main() 
{
    int N;
    scanf("%d", &N);

    int salami[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &salami[i]);
    }

    int max_salami = salami[0];
    for (int i = 1; i < N; i++) 
    {
        if (salami[i] > max_salami) 
        {
            max_salami = salami[i];
        }
    }
    
    for (int i = 0; i < N; i++) 
    {
        printf("%d", max_salami - salami[i]); 
        if (i < N - 1) 
        {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}
