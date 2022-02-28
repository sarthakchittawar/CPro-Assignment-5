#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(long int *)a - *(long int *)b);
}

int main()
{
    long int n, m;
    scanf("%ld %ld", &n, &m);

    long int ar[n], br[m];

    for (int i = 0; i < n; i++)
    {
        scanf("%ld", &ar[i]);
    }

    for (int i = 0; i < m; i++)
    {
        scanf("%ld", &br[i]);
    }
    qsort(ar, n, sizeof(long int), compare);
    qsort(br, m, sizeof(long int), compare);

    int i = 0, j = 0;
    int count = 0;
    while (i < n && j < m)
    {
        if (ar[i] == br[j])
        {
            count++;
            i++;
            j++;
        }
        else if (ar[i] < br[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    printf("%d\n", count);
    return 0;
}
