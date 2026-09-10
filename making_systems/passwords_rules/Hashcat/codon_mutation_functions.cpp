//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using ll=long long;
using namespace std;
void Org(string& s) {return;}
void l(string& s)
{transform(s.begin(),s.end(),s.begin(),::tolower);return;}
void u(string& s)
{transform(s.begin(),s.end(),s.begin(),::toupper);return;}
void c(string& s)
{
    if (s!="") s[0]=toupper(s[0]);
    if (s.size()>=1) transform(s.begin()+1,s.end(),s.begin()+1,::tolower);
    return;
}
void C(string& s)
{
    if (s!="") s[0]=tolower(s[0]);
    if (s.size()>=1) transform(s.begin()+1,s.end(),s.begin()+1,::toupper);
    return;
}
void t(string& s)
{
    for (char &ch:s)
    {
        if (islower(ch)) ch=toupper(ch);
        else if (isupper(ch)) ch=tolower(ch);
    }
    return;
}
void T(const ll pos,string& s)
{
    if ((ll)s.size()>pos&&pos>=0LL)
    {
        auto& ch=s[pos];
        if (isupper(ch)) ch=tolower(ch);
        else if (islower(ch)) ch=toupper(ch);
    }
    return;
}
void dollar(const char ch,string& s) {s+=ch; return;}
void caret(const char ch,string& s) {s=ch+s; return;}
void i(const ll pos,const char ch,string& s)
{
    if (pos<0LL||pos>(ll)s.size()) return;
    s.insert(pos,1,ch);
    return;
}
void lsquare(string& s)
{if (s!="") s.erase(s.begin());return;}
void rsquare(string& s)
{if (s!="") s.pop_back();return;}
void D(ll pos,string& s)
{
    if (pos>=(ll)s.size()||pos<0LL) return;
    s.erase(s.begin()+pos);
    return;
}
void quote(const ll pos,string& s)
{
    if (pos>=(ll)s.size()||pos<0LL) return;
    s.erase(s.begin()+pos+1,s.end());
    return;
}
void O(const ll pos,const ll len,string& s)
{
    if (pos>=(ll)s.size()||pos<0LL) return;
    ll cur=min(len,(ll)s.size()-pos);
    s.erase(pos,cur);
    return;
}
void r(string& s) {reverse(s.begin(),s.end());return;}
void d(string& s) {s+=s; return;}
void f(string& s)
{
    string ns=s;reverse(ns.begin(),ns.end());
    s+=ns; return;
}
void S(char A,char B,string& s)
{
    for (char &ch:s) {if (ch==A) ch=B;}
    return;
}
void ate(char A,string& s)
{
    s.erase(remove(s.begin(),s.end(),A),s.end());
    return;
}
void z(ll times,string& s)
{
    if (s!=""&&times>0LL) s.insert(0,times,s[0]);
    return;
}
void Z(ll times,string& s)
{
    if (s=="") return;
    char ch=s[(ll)s.size()-1LL];
    s.append(times,ch);
    return;
}
void change(const ll pos,const char ch,string& s)
{
	if (pos>=0LL&&pos<(ll)s.size()) 
		s[pos]=ch;
	return;
}
void swapping(const ll pos1,const ll pos2,string& s)
{
	if (pos1>=0&&pos2>=0&&pos1<(ll)s.size()&&pos2<(ll)s.size())
		swap(s[pos1],s[pos2]);
	return;
}
void tofront(string& s)
{
	if (s=="") return;
	char ch=s.back();
	s.pop_back();
	s.insert(0,1,ch);
	return;
}
void toback(string& s)
{
	if (s=="") return;
	char ch=s[0];
	s.erase(s.begin());
	s.push_back(ch);
	return;
}
void puff(string& s)
{
	string test;
	for (char &ch:s)
	{test+=ch;test+=ch;}
	s=test;
	return;
}
bool func(string &s,string &tag)
{
	if (tag==":") Org(s);
    else if (tag=="l") l(s);
    else if (tag=="u") u(s);
    else if (tag=="c") c(s);
    else if (tag=="C") C(s);
    else if (tag=="t") t(s);
    else if (tag=="T")
    {
        ll pos;cin>>pos;
        T(pos,s);
    }
    else if (tag=="$")
    {
        char ch;cin>>ch;
        dollar(ch,s);
    }
    else if (tag=="^")
    {
        char ch;cin>>ch;
        caret(ch,s);
    }
    else if (tag=="i")
    {
        ll pos;char ch;
        cin>>pos>>ch;
        i(pos,ch,s);
    }
    else if (tag=="[") lsquare(s);
    else if (tag=="]") rsquare(s);
    else if (tag=="D")
    {
        ll pos;cin>>pos;
        D(pos,s);
    }
    else if (tag=="'")
    {
        ll pos;cin>>pos;
        quote(pos,s);
    }
    else if (tag=="O")
    {
        ll pos,times;cin>>pos>>times;
        O(pos,times,s);
    }
    else if (tag=="r") r(s);
    else if (tag=="d") d(s);
    else if (tag=="f") f(s);
    else if (tag=="s")
    {
        char A,B;cin>>A>>B;
        S(A,B,s);
    }
    else if (tag=="@")
    {
        char ch;cin>>ch;
        ate(ch,s);
    }
    else if (tag=="z")
    {
        ll times;cin>>times;
        z(times,s);
    }
    else if (tag=="Z")
    {
        ll times;cin>>times;
        Z(times,s);
    }
	else if (tag==".")
	{
		ll pos;char ch;
		cin>>pos>>ch;
		change(pos,ch,s);
	}
	else if (tag=="*")
	{
		ll pos1,pos2;
		cin>>pos1>>pos2;
		swapping(pos1,pos2,s);
	}
	else if (tag=="<") tofront(s);
	else if (tag==">") toback(s);
	else if (tag=="q") puff(s);
    else if (tag=="end") return true;
	else return false;
}
