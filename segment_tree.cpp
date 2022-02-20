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
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << endl
#define ff first
#define ss second
#define pp pair<ll, ll>
#define mp make_pair
#define ll long long
#define ld long double
typedef pair<ll, ll> pl;
typedef vector<ll> vl;
typedef vector<pl> vpl;
typedef vector<vl> vvl;
ll powermod(ll x, ll y, ll p);
const ll mod = 1e9 + 7;
#define PI 3.1415926535897932384626
#define endl "\n"
ll a[1e5], seg[4 * 1e5];
// Always use 1ll when doing 2 to the power
void build(ll ind, ll low, ll high)
{
    if (low == high)
    {
        seg[ind] = a[low];
        return;
    }
    ll mid = (low + high) / 2;
    build(2 * ind + 1, low, mid);
    build(2 * ind + 2, mid + 1, high);
    seg[ind] = max(seg[2 * ind + 1], seg(2 * ind + 2));
}
ll query(ll ind, ll low, ll high, ll l, ll r)
{
    if (low >= l and high <= r) // completely inside
        return seg[ind];
    if (high < l or low > r) // completely outside
        return INT_MIN;
    ll mid = (low + high) / 2;
    ll left = query(2 * ind + 1, low, mid, l, r);
    ll right = query(2 * ind + 2, mid + 1, high, l, r);
    return max(left, right);
}
void solve()
{
    ll n, a = 0, b = 0, m = 1, c = 0, k = 0, i = 0, j = 0, l = 1e9 + 5;
    string s, p, q;
    // This program is to find maximum between ranges
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    build(0, 0, n - 1);
    cin >> a; // queries
    while (a--)
    {
        ll left, right;
        cin >> left >> right;
        cout << query(0, 0, n - 1, left, right);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
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