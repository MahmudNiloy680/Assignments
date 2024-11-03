//USING Dynamic Array

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d\n", &n);

    int len = 1;

    int *arr = (int *)malloc(len * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d ", &arr[i]);

        
        if (len == n)
        {
            break;
        }
        else
        {
            int *temp = arr;
            len +=1;
            arr = (int *)realloc(arr, len * sizeof(int));
            if (arr == NULL)
            {
                arr = temp;
            }

        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    free(arr);

    return 0;

}