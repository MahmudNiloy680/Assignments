#include <stdio.h>

int freq[1000000] = {0};

int main()
{
    int n, m, x;
    scanf("%d %d %d", &n, &m, &x);

    int mat[n][m];

    

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d ", &mat[i][j]);

            freq[mat[i][j]] += 1;
        }
    }

    for (int i = 0; i < x; i++)
    {
        int s;
        
        scanf("%d", &s);

        printf("%d\n", freq[s]);

    }
    return 0;
}