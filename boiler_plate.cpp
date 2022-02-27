{
	// Place your snippets for cpp here. 
	//Each snippet is defined under a snippet name and has a prefix, body and 
	// description. 
	//The prefix is what is used to trigger the snippet
	// the body will be expanded and inserted. 
	//Possible variables are: $1, $2 for tab stops, $0 for the final cursor position, and ${1:label}, ${2:another} for placeholders. Placeholders with the 
	// same ids are connected.
	"Default cpp formate": {
		"prefix": [
			"include",
			"default"
		],
		"body": [
			"#pragma GCC optimize (\"trapv\")",
			"#include <bits/stdc++.h>",
			"#include<algorithm>",
			"#include <vector>",
			"#include<sstream>",
			"#include <string.h>",
			"using namespace std;",
			"#define pb push_back",
			"#define all(v) v.begin(),v.end()",
			"#define  rep(i,n,v) for(i=n;i<v;i++)",
			"#define per(i,n,v) for(i=n;i>v;i--)",
			"#define ll  long long",
			"#define ld  long double",
			"#define ff first ",
			"#define ss second ",
			"#define mp make_pair",
			"typedef pair<ll,ll> pl;",
			"typedef vector<ll> vl;",
			"typedef vector<pl> vpl;",
			"typedef vector<vl> vvl;",
			"const ll mod=1e9+7;",
			"#define PI 3.1415926535897932384626",
			"#define endl \"\\n\""\" ",
			"#define set_bits __builtin_popcountll",
			"#define sp(x,y) fixed<<setprecision(y)<<x",
			"#define sz(x) ((ll)(x).size())",
			"#ifndef ONLINE_JUDGE",
			"#define deb2(x, y) cerr << #x << \"=\";_print(x); cerr<< \", \" << #y << \"=\";_print(y);cerr<< endl;",
			"#define deb(x) cerr << #x << \"=\";_print(x); cerr<<endl;",
			"#endif",
			"void _print(int a){cerr<<a;}",
			"void _print(ll a){cerr<<a;}",
			"void _print(char a){cerr<<a;}",
			"void _print(string a){cerr<<a;}",
			"void _print(bool a){cerr<<a;}",
			"template<class T> void _print(vector<T>a){cerr<<\"[\";for(T x:a){_print(x);cerr<<\",\";}cerr<<\"]\";}",
			"template<class T,class V> void _print(pair<T,V>a){cerr<<\"{\";_print(a.ff);cerr<<\", \";_print(a.ss);cerr<<\"}\";}",
			"template<class T,class V> void _print(map<T,V>a){cerr<<\"{\";for(auto x:a){_print(x);cerr<<\" \";}cerr<<\"}\";}",
			"template<class T> void _print(set<T>a){cerr<<\"[\";for(T x:a){_print(x);cerr<<\",\";}cerr<<\"]\";}",
			"void solve()",
			"{",
			"\tll  n, a=0,b=0,m=1, c=0,k=0, i=0, j=0, l=1e9+5;",
			"\tstring s,p, q;",
			"\tcin>>$1",
			"}",
			"int main()",
			"{",
			"#ifndef ONLINE_JUDGE",
			"// freopen(\"Error.txt\",\"w\",stderr);",
			"#endif",
			"\tios_base::sync_with_stdio(false);",
			"\tcin. tie(0);cout. tie(0);",
			"\tll t=1;",
			"\t//cin>>t;",
			"\twhile(t--)",
			"\t{",
			"\t\tsolve();",
			"\t}",
			"\treturn 0;",
			"}",
		],
		"description": "This is a c++ sniffpet",
	},
	"for loop": {
		"prefix": "forl",
		"body": [
			"for($1 $2 = $3 ; $2 < $4 ; $2++)",
			"}"
		],
		"description": "For Loop"
	}
}