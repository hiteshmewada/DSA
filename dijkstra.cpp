// It is a single source shortest path algorithm in a graph
#pragma GCC optimize ("trapv")
#include <bits/stdc++.h>
#include<algorithm>
#include <vector>
#include<sstream>
#include <string.h>
using namespace std;
#define pb push_back
#define all(v) v.begin(),v.end()
#define  rep(i,n,v) for(i=n;i<v;i++)
#define per(i,n,v) for(i=n;i>v;i--)
#define ll  long long
#define ld  long double
#define ff first 
#define ss second 
#define mp make_pair
typedef pair<ll,ll> pl;
typedef vector<ll> vl;
typedef vector<pl> vpl;
typedef vector<vl> vvl;
const ll mod=1e9+7;
#define PI 3.1415926535897932384626
#define endl "\n"
 
#define set_bits __builtin_popcountll
#define sp(x,y) fixed<<setprecision(y)<<x
#define sz(x) ((ll)(x).size())
#ifndef ONLINE_JUDGE
#define deb2(x, y); cerr << #x << "=";_print(x); cerr<< ", " << #y << "=";_print(y);cerr<< endl;
#else
#define deb2(x); 
#endif
#ifndef ONLINE_JUDGE
#define deb(x) cerr << #x << "=";_print(x); cerr<<endl;
#else
#define deb(x); 
#endif
void _print(int a){cerr<<a;}
void _print(ll a){cerr<<a;}
void _print(char a){cerr<<a;}
void _print(string a){cerr<<a;}
void _print(bool a){cerr<<a;}
template<class T> void _print(vector<T>a){cerr<<"[";for(T x:a){_print(x);cerr<<",";}cerr<<"]";}
template<class T,class V> void _print(pair<T,V>a){cerr<<"{";_print(a.ff);cerr<<", ";_print(a.ss);cerr<<"}";}
template<class T,class V> void _print(map<T,V>a){cerr<<"{";for(auto x:a){_print(x);cerr<<" ";}cerr<<"}";}
template<class T> void _print(set<T>a){cerr<<"[";for(T x:a){_print(x);cerr<<",";}cerr<<"]";}
void solve()
{
    ll  n, a=0,b=0,m=1, c=0,k=0, i=0, j=0, l=1e9+5;
    string s,p, q;
    cin>>n>>m;
    vector<pl>g[n+1]; // 1-indexed adjacency list for graph
    for(int i=0;i<m;i++){
        ll wt;
        cin>>a>>b>>wt;
        g[a].pb(make_pair(b,wt));
        g[b].pb(make_pair(a,wt));
    }
    ll source;
    cin>>source;
    // min Heap -> In pair -> {dist,from where did it came};
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
    vector<ll> distTo(n+1,INT16_MAX);
    distTo[source]=0;
    pq.push(make_pair(0,source));
    while(!pq.empty()){
        ll dist=pq.top().ff;
        ll prev=pq.top().ss;
        pq.pop();
        // vector<pair<ll,ll>>
        for(auto x:g[prev]){
            ll next=x.ff;
            ll nextDist=x.ss;
            if(distTo[next]>dist+nextDist){
                distTo[next]=dist+nextDist;
                pq.push(make_pair(distTo[next],next));
            }
        }
    }
    /*
    Using set
    set<pair<ll,ll>>st;
    vector<ll> distTo(n+1,INT16_MAX);
    distTo[source]=0;
    st.insert(make_pair(0,source));
    while(!st.empty()){
        ll dist=*st.begin().ff;
        ll prev=*st.begin().ss;
        st.erase(st.begin());
        // vector<pair<ll,ll>>
        for(auto x:g[prev]){
            ll next=x.ff;
            ll nextDist=x.ss;
            if(distTo[next]>dist+nextDist){
                distTo[next]=dist+nextDist;
                st.insert(make_pair(distTo[next],next));
            }
        }
    }
    */
    cout<<"The distance from source -> "<<source<<" are ";
    for(ll i=1;i<=n;i++) cout<<distTo[i]<<" ";
    cout<<endl;
}
int main()
{
#ifndef ONLINE_JUDGE
// freopen("Error.txt","w",stderr);
#endif
    ios_base::sync_with_stdio(false);
    cin. tie(0);cout. tie(0);
    ll t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
//cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0;
}