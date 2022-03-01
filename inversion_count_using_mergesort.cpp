ll mer(vector<ll> &v, vector<ll> &temp, ll l, ll md, ll r)
{
    ll i = l, j = md, k = l, cnt = 0;
    while (i <= md - 1 and j <= r)
    {
        if (v[i] <= v[j])
            temp[k++] = v[i++];
        else
        {
            temp[k++] = v[j++];
            cnt += (md - i);
        }
    }
    while (i <= md - 1)
        temp[k++] = v[i++];
    while (j <= r)
        temp[k++] = v[j++];
    for (ll c = l; c <= r; c++)
        v[c] = temp[c];
    return cnt;
}
ll _merge(vector<ll> &v, vector<ll> &temp, ll l, ll r)
{
    ll cnt = 0;
    if (r > l)
    {
        ll md = l + (r - l) / 2;
        cnt += _merge(v, temp, l, md);
        cnt += _merge(v, temp, md + 1, r);
        cnt += mer(v, temp, l, md + 1, r);
    }
    return cnt;
}
ll merge(vector<ll> &v, ll n)
{
    vl temp(n);
    return _merge(v, temp, 0, n - 1);
}
void solve()
{
    ll n, a = 0, b = 0, m = 1, c = 0, k = 0, i = 0, j = 0, l = 1e9 + 5;
    
    cin >> n;
    vl v(n), v1(n);
    rep(i, 0, n)
    {
        cin >> v[i];
        
    }
    rep(i, 0, n) cin >> v1[i];
    

    if (merge(v, n) % 2 != merge(v1, n) % 2)
        cout << "No";
    else
        cout << "Yes";
}
int main()
{

    ll t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}