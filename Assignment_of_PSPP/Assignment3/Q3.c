#include <stdio.h>
int main()
{
    char ch;
    scanf("%c", &ch);
    if ((ch == 'a') || (ch == 'A'))
        printf("vowel");
    else if ((ch == 'i' )|| (ch == 'I'))
        printf("vowel");
    else if ((ch == 'e' )|| (ch == 'E'))
        printf("vowel");
    else if ((ch == 'o') || (ch == 'O'))
        printf("vowel");
    else if ((ch == 'u') || (ch == 'U'))
        printf("vowel");
    else
    {
        printf("not vowel");
    }
}
