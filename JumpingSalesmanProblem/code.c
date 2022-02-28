#include <stdio.h>
#include <stdlib.h>

#define ll long long
#define FOR(i, l, n) for (int i = l; i < n; i++)
#define ROF(i, l, n) for (int i = n - 1; i >= l; i--)

int main()
{
    ll n, m;
    scanf("%lld %lld", &n, &m);

    ll ar[n];

    FOR(i, 0, n)
    {
        scanf("%lld", &ar[i]);
    }

    int lds[n];

    FOR(i, 0, n)
    {
        lds[i] = 1;
    }
    ROF(i, 0, n - 1)
    {
        ROF(j, i + 1, n)
        {
            if (ar[i] > ar[j] && lds[i] < lds[j] + 1)
            {
                lds[i] = lds[j] + 1;
            }
        }
    }
    int maxlds = 0;
    FOR(i, 0, n)
    {
        if (lds[i] > maxlds)
        {
            maxlds = lds[i];
        }
    }
    if (m > n)
    {
        printf("%d\n", maxlds);
    }
    else
    {
        int c = 0;
        int br[n];
        FOR(i, 0, n)
        {
            if (ar[i] > ar[m - 1])
            {
                br[c] = ar[i];
                c++;
            }
            else if (i == m - 1)
            {
                br[c] = ar[i];
                c++;
                break;
            }
        }
        int alt_lds[n];
        FOR(i, 0, n)
        {
            alt_lds[i] = 1;
        }
        ROF(i, 0, c - 1)
        {
            ROF(j, i + 1, c)
            {
                if (br[i] > br[j] && alt_lds[i] < alt_lds[j] + 1)
                {
                    alt_lds[i] = alt_lds[j] + 1;
                }
            }
        }

        int alt_lds_max = 0;
        FOR(i, 0, c)
        {
            if (alt_lds[i] > alt_lds_max)
            {
                alt_lds_max = alt_lds[i];
            }
        }

        int postm_lds[n];
        FOR(i, 0, n)
        {
            postm_lds[i] = 1;
        }

        ROF(i, m, n - 1)
        {
            ROF(j, i + 1, n)
            {
                if (ar[i] > ar[j] && postm_lds[i] < postm_lds[j] + 1)
                {
                    postm_lds[i] = postm_lds[j] + 1;
                }
            }
        }
        int postm_max = 0;

        FOR(i, m, n)
        {
            if (postm_lds[i] > postm_max)
            {
                postm_max = postm_lds[i];
            }
        }
        if ((alt_lds_max + postm_max) <= maxlds || m == n)
        {
            printf("%d\n", maxlds);
        }
        else
        {
            printf("%d\n", alt_lds_max + postm_max);
        }
    }

    return 0;
}
