//Taiwan_rulling
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <random>
#include <algorithm>
using ll=long long;
using namespace std;
vector<string> run_taiwan(const string& S)
{
    if (S.empty()) return {};
    static mt19937 gen(random_device{}());
    uniform_int_distribution<int> dist1(0,9);
    uniform_int_distribution<int> dist2(1,12);
    uniform_int_distribution<int> dist3(1,31);
    uniform_int_distribution<int> dist4(1,100);
    ll sz=(ll)S.size();
    string result=S;
    vector<string> temp={result};
    if (isdigit(S.back()))
    {
        for (ll k=0LL;k<10;k++)
        {
            result=S;
            for (ll i=sz-1LL;i>=0LL;i--)
            {
                if (isdigit(S[i]))
                {
                    result[i]=dist1(gen)+'0';
                }
                else break;
            }
            temp.push_back(result);
        }
    }
    else
    {
        for (ll k=0LL;k<10;k++)
        {
            result=S;
            result+=k+'0';
            temp.push_back(result);
        }
    }
    result=S;
    ll month=dist2(gen); string sm;
    if (month<10) sm='0'+to_string(month);
    else sm=to_string(month);
    ll date=dist3(gen); string sd;
    if (date<10) sd='0'+to_string(date);
    else sd=to_string(date);
    if (sz>=4LL&&isdigit(S[sz-1LL])&&isdigit(S[sz-2LL])&&isdigit(S[sz-3LL])&&isdigit(S[sz-4LL]))
        for (ll i=0LL;i<4LL;i++) result.pop_back();
    result+=sm; result+=sd; temp.push_back(result);
    result=S;
    ll test1=dist4(gen);
    if (test1<=60&&islower(S[0LL]))
    {result[0LL]=toupper(result[0LL]);temp.push_back(result);}
    result=S;
    stable_partition(result.begin(),result.end(),[](char ch){return !isdigit(ch);});
    temp.push_back(result);
    stable_partition(result.begin(),result.end(),[](char ch){return !isalpha(ch);});
    temp.push_back(result);
    stable_partition(result.begin(),result.end(),[](char ch){return isalnum(ch);});
    temp.push_back(result);
    temp.push_back(S+'!'); temp.push_back(S+'@'); temp.push_back(S+'#');
    temp.push_back(S+'$'); temp.push_back(S+'%'); temp.push_back(S+'^');
    temp.push_back(S+'&'); temp.push_back(S+'*'); temp.push_back(S+'(');
    temp.push_back(S+')'); temp.push_back(S+'-'); temp.push_back(S+'_');
    temp.push_back(S+'='); temp.push_back(S+'+'); temp.push_back(S+'~');
    temp.push_back(S+'`'); temp.push_back(S+'<'); temp.push_back(S+'>');
    temp.push_back(S+','); temp.push_back(S+'.'); temp.push_back(S+'/');
    temp.push_back(S+'\\'); temp.push_back(S+'|'); temp.push_back(S+'?');
    sort(temp.begin(),temp.end());
    temp.erase(unique(temp.begin(),temp.end()),temp.end());
    return temp;
}