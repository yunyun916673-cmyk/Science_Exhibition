#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
using ll=long long;
struct TrieNode
{
    bool is_word=false;
    TrieNode*child[256]={nullptr};
};
TrieNode*dict_root=new TrieNode();
TrieNode*kb_root=new TrieNode();
void insert_trie(TrieNode*root,const string&s)
{
    TrieNode*curr=root;
    for(char c:s){
        ll idx=tolower((unsigned char)c);
        if(!curr->child[idx])curr->child[idx]=new TrieNode();
        curr=curr->child[idx];
    }
    curr->is_word=true;
}
ll find_longest(TrieNode*root,const string&s,ll start)
{
    TrieNode*curr=root;
    ll max_len=0LL;
    ll curr_len=0LL;
    for(ll i=start;i<s.length();i++){
        ll idx=tolower((unsigned char)s[i]);
        if(!curr->child[idx])break;
        curr=curr->child[idx];
        curr_len++;
        if(curr->is_word)max_len=curr_len;
    }
    return max_len;
}
int main()
{
    ifstream dict_file("english_10514_top.txt");
    string w;
    while(dict_file>>w)insert_trie(dict_root,w);
    dict_file.close();
    ifstream kb_file("keyboard connect.txt");
    while(kb_file>>w)insert_trie(kb_root,w);
    kb_file.close();
    ifstream in("rockyou.txt");
    ofstream out("passwords_to_get_rules.txt");
    string pwd;
    while(getline(in,pwd)){
        if(!pwd.empty()&&pwd.back()=='\r') pwd.pop_back();
        if(pwd.empty())continue;
        string res="";
        ll n=pwd.length();
        ll i=0LL;
        while(i<n)
        {
            ll kb_len=find_longest(kb_root,pwd,i);
            if(kb_len>0LL)
            {
                for(ll j=0LL;j<kb_len;j++) res+="B";
                i+=kb_len;
                continue;
            }
            ll dict_len=find_longest(dict_root,pwd,i);
            if(dict_len>0LL)
            {
                res+="W";
                i+=dict_len;
                continue;
            }
            if(isdigit(pwd[i]))
            {
                ll same_len=1LL,inc_len=1LL,dec_len=1LL;
                for(ll j=i+1LL;j<n;j++)
                {if(pwd[j]==pwd[j-1])same_len++;else break;}
                for(ll j=i+1LL;j<n;j++)
                {if(pwd[j]==pwd[j-1]+1)inc_len++;else break;}
                for(ll j=i+1LL;j<n;j++)
                {if(pwd[j]==pwd[j-1]-1)dec_len++;else break;}
                
                ll max_num=max({same_len,inc_len,dec_len});
                if(max_num>=3LL)
                {
                    if(max_num==same_len)
                    {for(ll j=0LL;j<max_num;j++)res+="k";}
                    else if(max_num==inc_len)
                    {for(ll j=0LL;j<max_num;j++)res+="u";}
                    else
                    {for(ll j=0LL;j<max_num;j++)res+="d";}
                    i+=max_num;
                    continue;
                }
            }
            char c=pwd[i];
            if(isupper(c))res+="U";
            else if(islower(c))res+="L";
            else if(isdigit(c))res+="N";
            else res+="S";
            i++;
        }
        out<<res<<"\n";
    }
    in.close();
    out.close();
    return 0;
}
