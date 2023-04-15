// Leetcode 49. Group Anagrams
// https://leetcode.com/problems/group-anagrams/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution {
public:

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


    vector<vector<string>> groupAnagrams(vector<string>& strs) {


        map<ll,vector<string>> hashes;
        string str = "";
        for(int i = 0; i < strs.size(); i++){

            string str = strs[i];
            sort(str.begin(),str.end());
            
            hashes[poly_hash(str)].push_back(strs[i]);

        }

        vector<vector<string>> ans(hashes.size());

        ll i = 0;
        for( pair<ll,vector<string>> tmp : hashes) {

            vector<string> vec = tmp.second;

            for(int j = 0; j < vec.size(); j++) {

                ans[i].push_back(vec[j]);

            }
            i++;

        }

        return ans;
    }
};