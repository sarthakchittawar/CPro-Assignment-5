#include <stdio.h>

int main()
{
    long int n, k;
    scanf("%ld %ld", &n, &k);

    long int num;
    long int count = 0;
    long int i;
    long int buffer = 0;
    for (i = 0; i < n && count < k; i++)
    {
        scanf("%ld", &num);
        buffer += num;
        if (buffer > 8)
        {
            count += 8;
            buffer -= 8;
        }
        else
        {
            count += buffer;
            buffer = 0;
        }
    }

    if (count < k || i > n)
    {
        printf("-1\n");
    }
    else
    {
        printf("%ld\n", i);
    }

    return 0;
}
