// powermod function to be used as binary exponentiation

ll powermod(ll x, ll y, ll m)
{
    ll res = 1;
    x = x % m;
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