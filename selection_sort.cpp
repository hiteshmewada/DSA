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

// Always use 1ll when doing 2 to the power
void swapp(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void solve()
{
    ll n, a = 0, b = 0, m = 1, c = 0, k = 0, i = 0, j = 0, l = 1e9 + 5;
    string s, p, q;
    cin >> n;
    vl v(n);
    cout << "Unsorted Array" << endl;

    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (auto x : v)
        cout << x << " ";
    cout << endl;
    function<void(vector<ll>, ll)> selectionSort(vector<ll> v, ll n)
    {
        int mn;
        for (int i = 0; i < n - 1; i++)
        {
            mn = i;
            for (int j = i + 1; j < n; j++)
            {
                if (v[j] < v[mn])
                    mn = j;
            }
            swapp(&v[mn], &v[i]);
        }
    };
    selectionSort(v, n);
    cout<<"Array after selection sort ";
    for(auto x:v) cout<<x<<" ";
    cout<<endl;
}
/*
    selection sort is not stable
    yes it in inplace sorting algorithm
    space O(1)
    time O(n^2)
*/
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