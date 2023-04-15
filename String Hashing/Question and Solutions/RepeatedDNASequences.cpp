// Leetcode 187. Repeated DNA Sequences
// https://leetcode.com/problems/repeated-dna-sequences/

#define ll long long
#define mod1 1000000007
#define mod2 1000000009
class Solution {
public:

    ll binexpo(ll a, ll b, ll m){ ll ans = 1; while(b>0){ if(b&1){ ans = (ans * a)%m; } a = (a*a)%m; b>>=1; } return ans; }
    ll mminvprime(ll a, ll m){ return binexpo(a,m-2,m); }

    vector<ll> pre_hash1, pre_hash2;
    vector<ll> pre_power1, pre_power2;

    void poly_hash1( string str ) {

        ll hash = 0;
        ll prime = 31;
        ll prime_power = 1;
        for (ll i = 0; i < str.size(); ++i) {

            hash = ( hash + ( str[i] - 'A' + 1 ) * prime_power ) % mod1;
            pre_hash1.push_back(hash);
            prime_power = ( prime_power * prime ) % mod1;
            pre_power1.push_back(prime_power);
            

        }

    }

    void poly_hash2( string str ) {

        ll hash = 0;
        ll prime = 37;
        ll prime_power = 1;
        for (ll i = 0; i < str.size(); ++i) {

            hash = ( hash + ( str[i] - 'A' + 1 ) * prime_power ) % mod2;
            pre_hash2.push_back(hash);
            prime_power = ( prime_power * prime ) % mod2;
            pre_power2.push_back(prime_power);
            

        }

    }

    vector<string> findRepeatedDnaSequences(string s) {
        
        vector<string> ans;
        ll n = s.size();
        if( n <= 10 )
            return ans;

        poly_hash1(s);
        poly_hash2(s);

        map<pair<ll,ll>,ll> mp;
        map<string,ll> res;

        ll prime = 31;
        ll text_hash1, text_hash2;

        mp[make_pair(pre_hash1[9],pre_hash2[9])]++;


        for (int i = 10; i  < n; ++i)
        {
            text_hash1 = ((pre_hash1[i] - pre_hash1[i - 10]) + mod1) % mod1;
            text_hash2 = ((pre_hash2[i] - pre_hash2[i - 10]) + mod2) % mod2;

            text_hash1 = (text_hash1 * mminvprime(pre_power1[i-10],mod1)) % mod1;
            text_hash2 = (text_hash2 * mminvprime(pre_power2[i-10],mod2)) % mod2;

            if( mp[make_pair(text_hash1,text_hash2)] > 0) {
                res[s.substr(i-9,10)]++;
            }

            mp[make_pair(text_hash1,text_hash2)]++;

        }

        for( auto i : res) {

            ans.push_back(i.first);
        }

        return ans;
    }
};
