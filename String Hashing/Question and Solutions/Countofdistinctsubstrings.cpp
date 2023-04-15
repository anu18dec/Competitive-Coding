// GFG Count of distinct substrings
// https://practice.geeksforgeeks.org/problems/count-of-distinct-substrings/1

#include<bits/stdc++.h>
using namespace std;

int countDistinctSubstring(string s);

int main()
{
	int t,l,i,j;
	int temp;
	cin>>t;
	while(t--){

		string s;
		cin>>s;
		cout<<countDistinctSubstring(s)<<endl;

	 }
}


#define ll long long
#define mod1 1000000007
#define mod2 1000000009


/*You are required to complete this method */
int countDistinctSubstring(string s)
{
    // poly_hash(s);
    int n = s.size();
    vector<pair<ll,ll>> res;
    
	
    for( int i = 0; i < n; i++) {
        
        ll tmp_hash1 = 0;
        ll tmp_hash2 = 0;
        ll prime1 = 31;
        ll prime2 = 47;
        ll num;
        for( int j = i; j < n; j++ ) {
            
            num = s[j] - 'a' + 1;
            
            tmp_hash1 = (tmp_hash1 + (s[j] * prime1)) % mod1;
            prime1 = (prime1 * 31)%mod1;
            
            tmp_hash2 = (tmp_hash2 + (s[j] * prime2)) % mod2;
            prime2 = (prime2 * 31)%mod2;
            
            res.push_back(make_pair(tmp_hash1,tmp_hash2));
        }
    }

    sort(res.begin(),res.end());
    ll count = 1;
    ll len = res.size();
    for(int i = 1; i < len; i++) {
        if( res[i] != res[i-1])
            count++;
    }
    
    return count + 1;
}