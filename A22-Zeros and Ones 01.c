#include <stdio.h>
int main()
{
    int N, zero = 0, one = 0;
    scanf("%d", &N);

    int num[N];
    for (int i = 0; i < N; i++ )
    {
        scanf("%d", &num[i]);
    }
    for (int j = 0; j < N; j++)
    {
        if (num[j] == 0)
        {
            zero++;
        }
        else if (num[j] == 1)
        {
            one++;
        }
        
    }
    printf("%d %d\n", zero, one);

    return 0;
}