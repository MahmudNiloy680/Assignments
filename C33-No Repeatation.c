#include <stdio.h>

int main()
{
    int n;
    scanf("%d\n", &n);

    int arr[n+5];

    int freq[100005] = {0};

    for (int i = 0; i < n; i++)
    {
        scanf("%d ", &arr[i]);
        freq[arr[i]] += 1;
    }

    int count = 0;

    for (int i = 0; i <= 100000; i++)
    {
        if (freq[i] == 1)
        {
            count += 1;
        }
    }
    printf("%d", count);


    return 0;
}