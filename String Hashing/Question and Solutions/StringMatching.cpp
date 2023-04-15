// CSES String Matching
// https://cses.fi/problemset/task/1753/

#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define ld long double
#define ull unsigned long long
#define F first
#define S second
#define pb push_back
#define cy cout << "YES\n"
#define cn cout << "NO\n"
#define mod 1000000007
#define mod2 1000000009
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
 
typedef vector<ll> vl ;
typedef vector<char> vc ;
typedef vector<string> vs ;
typedef vector<double> vd ;
typedef vector<bool> vb ;
typedef pair<ll,ll> pl;
typedef vector<vector<ll>> vvl ;
typedef vector<vector<char>> vvc ;
typedef vector<pair<ll,ll>> vpl ;
typedef vector<vector<pair<ll,ll>>> vvpl;
 
// -------------------------------------------------------------------------------//
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); /* exchanging a and b coz of we are assuming a always > b */ }
ll binexpo(ll a, ll b, ll m){ ll ans = 1; while(b>0){ if(b&1){ ans = (ans * a)%m; } a = (a*a)%m; b>>=1; } return ans; }
ll binexporec(ll a, ll b, ll m) { if (b == 0) return 1; ll res = binexporec(a, b / 2, m); if (b&1) return (((res * res)%m) * a)%m ; else return (res * res)%m ; }
ll mminvprime(ll a, ll m){ return binexpo(a,m-2,m); }
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}//when m is prime
bool isPowerOfTwo(int n) { return n > 0 && not (n & n - 1); }
vector<ll> c_div;/*clear c_div after using it*/
void common_div(ll a, ll b){ ll g = gcd(a,b); for (ll i = 1; i*i <= g; ++i){ if(g%i==0){ if(g/i==i){ c_div.pb(i); } else { c_div.pb(i); c_div.pb(g/i); } } } }
vector<ll>  prime_factors(ll num){    vector<ll> pfactors; for (ll i = 2; i*i <= num ; ++i) { while(num%i==0) { pfactors.pb(i); num/=i; } } if(num>1) { pfactors.pb(num); } return pfactors; }
vector<ll> factorial; void fact_mod(ll n,ll m) { factorial.resize(n+1); factorial[0]=1; for (ll i = 1; i <= n; ++i) { factorial[i] = factorial[i-1]*i%m; }}
// -------------------------------------------------------------------------------//
 

ll poly_hash( string str ) {
 
	ll hash = 0;
	ll prime = 31;
	ll prime_power = 1;
	for (ll i = 0; i < str.size(); ++i) {
 
		hash = ( hash + ( str[i] - 'a' + 1 ) * prime_power ) % mod;
		prime_power = ( prime_power * prime ) % mod;
 
	}
 
	return hash;
}
 
ll rabin_karp( string text, string pattern) {
 
	ll cnt = 0;
 
	ll n = text.size();
	ll m = pattern.size();
	ll prime = 31;
 
	ll pat_hash = poly_hash(pattern);
	ll text_hash = poly_hash(text.substr(0,m));
 
	if( pat_hash == text_hash ) {
 
		cnt++;
	}
 
	for (int i = 1; i + m - 1 < n; ++i)
	{
		text_hash = (text_hash - (text[i - 1] - 'a' + 1) + mod) % mod;
 
		text_hash = (text_hash * mminvprime(prime,mod)) % mod ;
 
		text_hash = (text_hash + ( text[i + m - 1] - 'a' + 1) * binexpo(prime,m-1,mod)) % mod;
 
		if( text_hash == pat_hash) {
			cnt++;
		}
	}
 
	return cnt;
}
 
 
void solve()
{
	string text,pattern; cin>>text>>pattern;
 
	cout<<rabin_karp(text,pattern);
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
 
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	clock_t z_clock = clock();
 
	ll t = 1;
	while(t--)
	{
		solve();
	}
	cerr << "Run Time : " << ((double)(clock() - z_clock) / CLOCKS_PER_SEC)<<" ";
 
	return 0;
}