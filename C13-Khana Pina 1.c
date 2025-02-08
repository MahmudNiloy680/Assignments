#include <stdio.h>
int main() 
{
    int M;
    scanf("%d", &M);

    if (M >= 1000)
        {
            printf("Three Kacchi");
        }
    else if (500 <= M && M < 1000) 
        {
            printf("One Large Pizza");
        }
    else if (250 <= M && M < 500)
        {
            printf("Three Small Burger");
        }
    else if (100 <= M && M < 250)
        {
            printf("Three Fuchka");
        }
    else if (M<100)
        {
            printf("Nothing");
        }
        
     return 0;
}
