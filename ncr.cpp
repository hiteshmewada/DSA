

// When we want to calculate ncr that can be done in O(r) using this
vector<ll> fact(1000);
void init(ll m)
{
    ll fac = 1;
    for (ll i = 2; i < 1000; i++)
    {
        fac *= i;
        fac %= m;
    }
    fact[1000 - 1] = powermod(fac, m - 2, m);
    for (ll i = 1000 - 2; i >= 0; i--)
    {
        fact[i] = fact[i + 1] * (i + 1) % m;
    }
}
ll ncr(ll n, ll r, ll m)
{
    r = min(r, n - r);
    ll res = 1;
    for (ll i = 1; i <= r; i++)
    {
        res *= n - r + i;
        res %= m;
    }
    return res * fact[r] % m;
}
ll powermod(ll x, ll y, ll m)
{
    ll res = 1;
    x %= m;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % m;
        y = (y >> 1);
        x = (x * x) % m;
    }
    return res;
}