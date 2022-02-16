#include <stdio.h>

#define mod 1000000007

typedef long long ll;

ll inverse(ll n)
{
    ll ans = 1;
    ll p = mod - 2;
    while (p > 0)
    {
        if (p % 2 == 1)
        {
            ans = (ans * n) % mod;
        }
        n = (n * n) % mod;
        p /= 2;
    }
    return ans;
}

int main(void)
{
    ll n, m;
    scanf("%lld", &n);
    scanf("%lld", &m);
    ll ar[n][m];

    for (int i = 0; i < n; i++)
    {
        ll prod = 1;
        for (int j = 0; j < m; j++)
        {
            ll temp;
            scanf("%lld", &temp);
            ar[i][j] = (prod % mod * temp % mod) % mod;
            prod = ar[i][j] % mod;
        }
    }
    for (int j = 0; j < m; j++)
    {
        ll prod = 1;
        for (int i = 0; i < n; i++)
        {
            ar[i][j] = (ar[i][j] % mod * prod % mod) % mod;
            prod = ar[i][j] % mod;
        }
    }
    ll q;
    scanf("%lld", &q);
    while (q--)
    {
        ll x1, y1, x2, y2;
        ll ans = 1;
        scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
        if (x1 != 0 && y1 != 0)
        {
            ans = (ar[x2][y2] % mod * inverse(ar[x1 - 1][y2]) % mod) % mod;
            ans = (ans % mod * inverse(ar[x2][y1 - 1]) % mod) % mod;
            ans = (ans % mod * ar[x1 - 1][y1 - 1] % mod) % mod;
        }
        else if (x1 == 0 && y1 == 0)
        {
            ans = ar[x2][y2] % mod;
        }
        else if (x1 >= 1 && y1 == 0)
        {
            ans = (ar[x2][y2] % mod * inverse(ar[x1 - 1][y2]) % mod) % mod;
        }
        else if (x1 == 0 && y1 >= 1)
        {
            ans = (ar[x2][y2] % mod * inverse(ar[x2][y1 - 1]) % mod) % mod;
        }
        printf("%lld\n", ans);
    }
}
