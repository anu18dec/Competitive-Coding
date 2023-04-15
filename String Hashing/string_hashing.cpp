#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define mod1 1000000007
#define mod2 1000000009
typedef vector<ll> vl ;

// Modulo inverse
ll binexpo(ll a, ll b, ll m){ ll ans = 1; while(b>0){ if(b&1){ ans = (ans * a)%m; } a = (a*a)%m; b>>=1; } return ans; }
ll mminvprime(ll a, ll m){ return binexpo(a,m-2,m); }

/****************************************************************/
// 1. Polynomial hash
// 2. Double hash
// 3. Prefix of polynomial hash and prime powers (for getting hash of any substring of string)
// 4. Rabin karp rolling hash
/****************************************************************/



vl pre_hash1; // storing prefix hash of poly_hash1
vl pre_power1; // storing prefix of prime power of poly_hash1

// Polynomial hash ( poly hash1 for single hash)
ll poly_hash1( string str ) {

	ll len = str.size();
	ll hash = 0;
	ll prime = 31;
	ll prime_power = 1;

	for (ll i = 0; i < len; ++i) {

		hash = ( hash + ( str[i] - 'a' + 1 ) * prime_power ) % mod1;
		prime_power = ( prime_power * prime ) % mod1;

		pre_hash1.push_back(hash);
        pre_power1.push_back(prime_power);
        
	}

	return hash;
}


vl pre_hash2; // storing prefix hash of poly_hash2 
vl pre_power2; // storing prefix of prime power of poly_hash2

// Polynomial hash ( poly hash1 + poly hash2 for double hashing)
ll poly_hash2( string str ) {

	ll len = str.size();
	ll hash = 0;
	ll prime = 57;
	ll prime_power = 1;

	for (ll i = 0; i < len; ++i) {

		hash = ( hash + ( str[i] - 'a' + 1 ) * prime_power ) % mod2;
		prime_power = ( prime_power * prime ) % mod2;

		pre_hash2.push_back(hash);
        pre_power2.push_back(prime_power);
        
	}

	return hash;
}



// Rabin karp rolling hash
void rabin_karp( string text, string pattern) {
 
  ll n = text.size();
  ll m = pattern.size();
  ll prime = 31;
 
  ll pat_hash = poly_hash1(pattern);
  ll text_hash = poly_hash1(text.substr(0,m));
 
  if( pat_hash == text_hash ) {
 
    cout<<0<<" ";
  }
 
  for (int i = 1; i + m - 1 < n; ++i)
  {
    text_hash = (text_hash - (text[i - 1] - 'a' + 1) + mod1) % mod1;
 
    text_hash = (text_hash * mminvprime(prime,mod1)) % mod1 ;
 
    text_hash = (text_hash + ( text[i + m - 1] - 'a' + 1) * binexpo(prime,m-1,mod1)) % mod1;
 
    if( text_hash == pat_hash) {

       cout<<i<<" ";
    }
  }
}

