/// SPARSE TABLE IMPLEMENTATION
#pragma GCC optimize("trapv")
#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <string.h>
using namespace std;
#define pb push_back
#define all(v) v.begin(), v.end()
#define rep(i, n, v) for (i = n; i < v; i++)
#define per(i, n, v) for (i = n; i > v; i--)
#define ff first
#define ss second
#define pp pair<ll, ll>
#define ll long long
#define ld long double
ll powermod(ll x, ll y, ll p)
{
    ll res = 1;
    x = x % p;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = (y >> 1);
        x = (x * x) % p;
    }
    return res;
}
#define endl "\n"

const ll mod = 1e9 + 7;
void solve()
{
    ll n, a = 0, b = 0, m = 1, c = 0, k = 0, i = 0, j = 0, l = 1e9 + 5;
    string s, p, q;
    cin >> n >> a;
    vector<ll> v(n);
    for (auto x : v)
        cin >> x;
    vector<ll> lg(n + 1); // lg(i)=log2(i);
    lg[1] = 0;
    for (int i = 2; i <= n; i++)
        lg[i] = lg[i / 2] + 1;
    // sparse[i][j] : Minimum value in interval [j,j+2^i-1]
    vector<vector<int>> sparse(lg[n] + 1, vector<int>(n));
    for (int j = 0; j < n; j++)
        sparse[0][j] = v[j];
    for (int i = 1; i <= lg[n]; i++)
    {
        for (int j = 0; j + (1 << i) - 1 < n; j++)
            sparse[i][j] = min(sparse[i - 1][j], sparse[i - 1][j + (1 << (i - 1))]);
    }
    while (a--)
    {
        cin >> i >> j;
        i--;
        j--;
        ll k = lg[j - i + 1];
        cout << min(sparse[k][i], sparse[k][j - (1 << k) + 1]) << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}