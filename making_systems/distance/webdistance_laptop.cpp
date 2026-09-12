//筆電
#include <iostream>
#include <unordered_map>
#include <utility>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using ll=long long;
using namespace std;
unordered_map<string,pair<ll,ll>> area=
{
	{"`",{0LL,0LL}},{"~",{0LL,0LL}},
	{"1",{1LL,0LL}},{"!",{1LL,0LL}},
	{"2",{2LL,0LL}},{"@",{2LL,0LL}},
	{"3",{3LL,0LL}},{"#",{3LL,0LL}},
	{"4",{4LL,0LL}},{"$",{4LL,0LL}},
	{"5",{5LL,0LL}},{"%",{5LL,0LL}},
	{"6",{6LL,0LL}},{"^",{6LL,0LL}},
	{"7",{7LL,0LL}},{"&",{7LL,0LL}},
	{"8",{8LL,0LL}},{"*",{8LL,0LL}},
	{"9",{9LL,0LL}},{"(",{9LL,0LL}},
	{"0",{10LL,0LL}},{")",{10LL,0LL}},
	{"-",{11LL,0LL}},{"_",{11LL,0LL}},
	{"=",{12LL,0LL}},{"+",{12LL,0LL}},
	{"q",{1LL,1LL}},{"Q",{1LL,1LL}},
	{"w",{2LL,1LL}},{"W",{2LL,1LL}},
	{"e",{3LL,1LL}},{"E",{3LL,1LL}},
	{"r",{4LL,1LL}},{"R",{4LL,1LL}},
	{"t",{5LL,1LL}},{"T",{5LL,1LL}},
	{"y",{6LL,1LL}},{"Y",{6LL,1LL}},
	{"u",{7LL,1LL}},{"U",{7LL,1LL}},
	{"i",{8LL,1LL}},{"I",{8LL,1LL}},
	{"o",{9LL,1LL}},{"O",{9LL,1LL}},
	{"p",{10LL,1LL}},{"P",{10LL,1LL}},
	{"[",{11LL,1LL}},{"{",{11LL,1LL}},
	{"]",{12LL,1LL}},{"}",{12LL,1LL}},
	{"\\",{13LL,1LL}},{"|",{13LL,1LL}},
	{"capslock",{0LL,2LL}},
	{"a",{1LL,2LL}},{"A",{1LL,2LL}},
	{"s",{2LL,2LL}},{"S",{2LL,2LL}},
	{"d",{3LL,2LL}},{"D",{3LL,2LL}},
	{"f",{4LL,2LL}},{"F",{4LL,2LL}},
	{"g",{5LL,2LL}},{"G",{5LL,2LL}},
	{"h",{6LL,2LL}},{"H",{6LL,2LL}},
	{"j",{7LL,2LL}},{"J",{7LL,2LL}},
	{"k",{8LL,2LL}},{"K",{8LL,2LL}},
	{"l",{9LL,2LL}},{"L",{9LL,2LL}},
	{";",{10LL,2LL}},{":",{10LL,2LL}},
	{"'",{11LL,2LL}},{"\"",{11LL,2LL}},
	{"shift_left",{0LL,3LL}},
	{"z",{1LL,3LL}},{"Z",{1LL,3LL}},
	{"x",{2LL,3LL}},{"X",{2LL,3LL}},
	{"c",{3LL,3LL}},{"C",{3LL,3LL}},
	{"v",{4LL,3LL}},{"V",{4LL,3LL}},
	{"b",{5LL,3LL}},{"B",{5LL,3LL}},
	{"n",{6LL,3LL}},{"N",{6LL,3LL}},
	{"m",{7LL,3LL}},{"M",{7LL,3LL}},
	{",",{8LL,3LL}},{"<",{8LL,3LL}},
	{".",{9LL,3LL}},{">",{9LL,3LL}},
	{"/",{10LL,3LL}},{"?",{10LL,3LL}},
	{"shift_right",{11LL,3LL}},
	{"ctrl",{0LL,4LL}}
};
unordered_map<string,vector<string>> temp=
{
	{"`",{"`"}},{"~",{"shift","`"}},
	{"1",{"1"}},{"!",{"shift","1"}},
	{"2",{"2"}},{"@",{"shift","2"}},
	{"3",{"3"}},{"#",{"shift","3"}},
	{"4",{"4"}},{"$",{"shift","4"}},
	{"5",{"5"}},{"%",{"shift","5"}},
	{"6",{"6"}},{"^",{"shift","6"}},
	{"7",{"7"}},{"&",{"shift","7"}},
	{"8",{"8"}},{"*",{"shift","8"}},
	{"9",{"9"}},{"(",{"shift","9"}},
	{"0",{"0"}},{")",{"shift","0"}},
	{"-",{"-"}},{"_",{"shift","-"}},
	{"=",{"="}},{"+",{"shift","="}},
	{"q",{"q"}},{"Q",{"shift","q"}},
	{"w",{"w"}},{"W",{"shift","w"}},
	{"e",{"e"}},{"E",{"shift","e"}},
	{"r",{"r"}},{"R",{"shift","r"}},
	{"t",{"t"}},{"T",{"shift","t"}},
	{"y",{"y"}},{"Y",{"shift","y"}},
	{"u",{"u"}},{"U",{"shift","u"}},
	{"i",{"i"}},{"I",{"shift","i"}},
	{"o",{"o"}},{"O",{"shift","o"}},
	{"p",{"p"}},{"P",{"shift","p"}},
	{"[",{"["}},{"{",{"shift","["}},
	{"]",{"]"}},{"}",{"shift","]"}},
	{"\\",{"\\"}},{"|",{"shift","\\"}},
	{"a",{"a"}},{"A",{"shift","a"}},
	{"s",{"s"}},{"S",{"shift","s"}},
	{"d",{"d"}},{"D",{"shift","d"}},
	{"f",{"f"}},{"F",{"shift","f"}},
	{"g",{"g"}},{"G",{"shift","g"}},
	{"h",{"h"}},{"H",{"shift","h"}},
	{"j",{"j"}},{"J",{"shift","j"}},
	{"k",{"k"}},{"K",{"shift","k"}},
	{"l",{"l"}},{"L",{"shift","l"}},
	{";",{";"}},{":",{"shift",";"}},
	{"'",{"'"}},{"\"",{"shift","'"}},
	{"z",{"z"}},{"Z",{"shift","z"}},
	{"x",{"x"}},{"X",{"shift","x"}},
	{"c",{"c"}},{"C",{"shift","c"}},
	{"v",{"v"}},{"V",{"shift","v"}},
	{"b",{"b"}},{"B",{"shift","b"}},
	{"n",{"n"}},{"N",{"shift","n"}},
	{"m",{"m"}},{"M",{"shift","m"}},
	{",",{","}},{"<",{"shift",","}},
	{".",{"."}},{">",{"shift","."}},
	{"/",{"/"}},{"?",{"shift","/"}},
	{"capslock",{"capslock"}}
};
ll webdist(string A,string B)
{
	ll asz=(ll)A.size();
	ll bsz=(ll)B.size();
	A=" "+A;
	B=" "+B;
	vector<vector<ll>> dp(asz+1LL,vector<ll> (bsz+1LL,0LL));
	for (ll i=1LL;i<=asz;i++) dp[i][0LL]=i;
	for (ll i=1LL;i<=bsz;i++) dp[0LL][i]=i;
	for (ll i=1LL; i<=asz; i++)
	{
		for (ll j=1LL; j<=bsz; j++)
		{
            string a(1,A[i]),b(1,B[j]);
			if (a==b) {dp[i][j]=dp[i-1LL][j-1LL];continue;}
			ll sza=(ll)temp[a].size();
			ll szb=(ll)temp[b].size();
			ll dist=0LL;
			pair<ll,ll> afront={-1LL,-1LL};
			pair<ll,ll> aback={-1LL,-1LL};
			pair<ll,ll> bfront={-1LL,-1LL};
			pair<ll,ll> bback={-1LL,-1LL};
			bool taga=false,tagb=false;
			if (sza>1LL)
			{
			    if (temp[a][0LL]=="shift") taga=true;
			    else
			    {afront={area[temp[a][0LL]].first,area[temp[a][0LL]].second};}
			    aback={area[temp[a][1LL]].first,area[temp[a][1LL]].second};
			}
			else aback={area[temp[a][0LL]].first,area[temp[a][0LL]].second};
			if (szb>1LL)
			{
			    if (temp[b][0LL]=="shift") tagb=true;
			    else
			    {bfront={area[temp[b][0LL]].first,area[temp[b][0LL]].second};}
			    bback={area[temp[b][1LL]].first,area[temp[b][1LL]].second};
			}
			else bback={area[temp[b][0LL]].first,area[temp[b][0LL]].second};
			if (!taga&&!tagb)
			{
			    if (afront.first==-1LL&&bfront.first==-1LL)
			    {
			        dist+=abs(aback.first-bback.first)
			        +abs(aback.second-bback.second);
			    }
			    else if (afront.first!=-1LL&&bfront.first!=-1LL)
			    {
			        dist+=abs(afront.first-bfront.first)
			        +abs(afront.second-bfront.second);
			        dist+=abs(aback.first-bback.first)
			        +abs(aback.second-bback.second);
			    }
			    else
			    {
			        dist+=abs(aback.first-bback.first)
			        +abs(aback.second-bback.second)+1LL;
			    }
			}
			else
            {
                pair<ll, ll> target_a=taga?area[temp[a][1LL]]:area[temp[a][0LL]];
                pair<ll, ll> target_b=tagb?area[temp[b][1LL]]:area[temp[b][0LL]];
                dist=abs(target_a.first-target_b.first)
                +abs(target_a.second-target_b.second);
                if (taga&&!tagb)
                {
                    ll test=abs(area["shift_left"].first-target_b.first)
                    +abs(area["shift_left"].second-target_b.second);
                    test=min(test,abs(area["shift_right"].first-target_b.first)
                    +abs(area["shift_right"].second-target_b.second));
                    dist+=test;
                }
                else if (!taga&&tagb)
                {
                    ll test=abs(area["shift_left"].first-target_a.first)
                    +abs(area["shift_left"].second-target_a.second);
                    test=min(test,abs(area["shift_right"].first-target_a.first)
                    +abs(area["shift_right"].second-target_a.second));
                    dist+=test;
                }
            }
			dp[i][j]=min({dp[i-1][j-1]+dist,dp[i-1][j]+1LL,dp[i][j-1LL]+1LL});
		}
	}
	return dp[asz][bsz];
}
