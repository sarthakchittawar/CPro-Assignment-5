#include <stdio.h>

int main()
{
    int L, K, m;
    scanf("%d %d %d", &L, &K, &m);

    char str[L];
    scanf("%s", str);
    int i = 0;
    int flag = 0;
    while (i + K - 1 < L)
    {
        for (int j = i; j < i + K; j++)
        {
            printf("%c", str[j]);
        }
        printf("\n");
        if (i + K - 1 == L - 1)
        {
            flag = 1;
        }
        i += K - m;
    }
    if (flag == 0)
    {
        for (int j = i; j < L; j++)
        {
            printf("%c", str[j]);
        }
        printf("\n");
    }

    return 0;
}
