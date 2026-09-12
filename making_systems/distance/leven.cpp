#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using ll=long long;
using namespace std;
ll leven(string A,string B)
{
    ll asz=(ll)A.size();
    ll bsz=(ll)B.size();
    A=" "+A; B=" "+B;
    vector<vector<ll>> dp(asz+1LL,vector<ll> (bsz+1LL,0LL));
    for (ll i=1LL;i<=asz;i++) dp[i][0LL]=i;
    for (ll i=1LL;i<=bsz;i++) dp[0LL][i]=i;
    for (ll i=1LL;i<=asz;i++)
    {
        for (ll j=1LL;j<=bsz;j++)
        {
            if (A[i]==B[j]) {dp[i][j]=dp[i-1LL][j-1LL];continue;}
            else dp[i][j]=min({dp[i-1LL][j-1LL],dp[i-1LL][j],dp[i][j-1LL]})+1LL;
        }
    }
    return dp[asz][bsz];
}