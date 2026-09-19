//get_honeywords_or_change_traditional.cpp
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <utility>
#include <unordered_set>
#include "leven.cpp"
#include "webdist.cpp"
#include "traditional.cpp"
using ll=long long;
using namespace std;
ll length=8LL;
bool nums=true,lowr=true,uppr=true,specl=true;
ll lv_l=2LL,lv_r=7LL,wd_l=2LL,wd_r=7LL;
ll how_many=19LL;
bool check(string ts)
{
    if((ll)ts.size()<length) return false;
    bool bn=false,bl=false,bu=false,bs=false;
    for(char &ch:ts)
    {
        if(nums&&isdigit(ch)) bn=true;
        if(lowr&&islower(ch)) bl=true;
        if(uppr&&isupper(ch)) bu=true;
        if(specl&&!isdigit(ch)&&!islower(ch)&&!isupper(ch)) bs=true;
    }
    if(nums&&!bn) return false;
    if(lowr&&!bl) return false;
    if(uppr&&!bu) return false;
    if(specl&&!bs) return false;
    return true;
}
struct data
{
    string word;
    ll L,W;
};
bool vers_lv(const data& a,const data& b) {return a.L<b.L;}
bool vers_wd(const data& a,const data& b) {return a.W<b.W;}
void changing(string S)
{
    ll sz=(ll)S.size();
    ll pos=sz-1LL;
    string test="";
    while(pos>=0LL)
    {
        if(!isdigit(S[pos])) break;
        test=S[pos]+test;
        pos--;
        S.pop_back();
    }
    ll val=0LL;
    if(test!="") val=stoll(test);
    if(S=="password_length") length=val;
    else if(S=="need_numbers") nums=true;
    else if(S=="no_numbers") nums=false;
    else if(S=="need_lower") lowr=true;
    else if(S=="no_lower") lowr=false;
    else if(S=="need_upper") uppr=true;
    else if(S=="no_upper") uppr=false;
    else if(S=="need_special") specl=true;
    else if(S=="no_special") specl=false;
    else if(S=="leven_left") lv_l=val;
    else if(S=="leven_right") lv_r=val;
    else if(S=="webdist_left") wd_l=val;
    else if(S=="webdist_right") wd_r=val;
    else if(S=="honey_numbers") how_many=val;
    return;
}
pair<vector<string>,ll> get_honeywords(const string& S,bool is_set)
{
    if(is_set) {changing(S);return {{},-2LL};}
    static mt19937 gen(random_device{}());
    vector<string> temp;
    vector<string> list=run_traditional(S,length,nums,lowr,uppr,specl);
    auto add_to_temp=[&](const vector<string>& lst)
    {
        for(const string& word:lst)
            if(check(word))
                temp.push_back(word);
    };
    add_to_temp(list);
    vector<data> finall;
    for(string& str:temp)
    {
        ll lv_dist=leven(str,S);
        if(lv_dist<lv_l||lv_dist>lv_r) continue;
        ll wd_dist=webdist(str,S);
        if(wd_dist<wd_l||wd_dist>wd_r) continue;
        finall.push_back({str,lv_dist,wd_dist});
    }
    vector<string> answers;
    if((ll)finall.size()<how_many) return {answers,-1LL};
    uniform_int_distribution<long long> dist(1,how_many);
    ll val=dist(gen);
    ll where=dist(gen);
    ll pos=0LL;
    unordered_set<string> before;
    sort(finall.begin(),finall.end(),vers_lv);
    for(ll i=0LL;i<val;i++)
    {
        answers.push_back(finall[i].word);
        before.insert(finall[i].word);
        pos++;
        if(pos==where) answers.push_back(S);
    }
    sort(finall.begin(),finall.end(),vers_wd);
    ll curr=0LL;
    for(ll i=0LL;i<(ll)finall.size()&&curr<(how_many-val);i++)
    {
        if (before.count(finall[i].word)) continue; 
        answers.push_back(finall[i].word);
        curr++; pos++;
        if(pos==where) answers.push_back(S);
    }
    return {answers,where};
}