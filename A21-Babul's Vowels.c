#include <stdio.h>
int main()
{
    char C;
    scanf("%c", &C);

    if (C == 'a' || C == 'e' || C == 'i' || C == 'o' || C == 'u')
    {
        printf("Vowel");
    }
    else
    {
        printf("Consonant");
    }

    return 0;
}