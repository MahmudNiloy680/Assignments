#include <stdio.h>
int main()
{
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    int X;
    scanf("%d", &X);

    if (X>=1 && X <= N)
    {
        if (arr[X-1] == 0)
        {
            arr[X-1] = 1;
        }
        else if (arr[X-1] == 1)
        { 
            arr[X-1] = 0;
        }
    }
    for (int j = 0; j<N; j++)
    {
        printf("%d ", arr[j]);
    }

    return 0;
}    
