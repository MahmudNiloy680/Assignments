#include <stdio.h>
int main()
{
    int n; 
    scanf("%d", &n);

    int mat[n][n];

    for (int i  = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d ", &mat[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (mat[i][i] != 1) //checking the primary diagonal
        {
            printf("NO");
            return 0;
        }
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                if (mat[i][j] != 0) // checking the else
                {
                    printf("NO");
                    return 0;
                }
            }
        }
    }
    printf("YES");
}