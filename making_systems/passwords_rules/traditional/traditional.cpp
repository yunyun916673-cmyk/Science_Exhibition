#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <string>
#include <utility>
#include <random>
#include <cctype>
using ll=long long;
using namespace std;
struct markov
{
 map<pair<int,int>,vector<int>> model;
 mt19937 gen{random_device{}()};

 void training(const string& S)
 {
  if (S.empty()) return;
  vector<int> tokens={256,256};
  for (char ch:S)
   tokens.push_back((int)ch);
  tokens.push_back(257);
  for (int i=0;i<(int)tokens.size()-2;i++)
   model[{tokens[i],tokens[i+1]}].push_back(tokens[i+2]);
 }

 pair<string,ll> getting(ll length,bool nums,bool lowr,bool uppr,bool specl)
 {
  ll cnt=0LL;
  while (cnt<=10000)
  {
   cnt++;
   string S="";
   pair<int,int> base={256,256};
   for (ll i=0;i<length;i++)
   {
    auto it=model.find(base);
    if (it==model.end()||it->second.empty()) break;
    auto& nexts=it->second;
    int nxt=nexts[uniform_int_distribution<int>(0,(int)nexts.size()-1)(gen)];
    if (nxt==257) break;
    S+=(char)nxt;
    base={base.second,nxt};
   }
   bool tag=false;
   if ((int)S.size()<length) tag=true;
   bool bn=false,bl=false,bu=false,bs=false;
   for (char &ch:S)
   {
    unsigned char uch=(unsigned char)ch;
    if (nums&&isdigit(uch)) bn=true;
    if (lowr&&islower(uch)) bl=true;
    if (uppr&&isupper(uch)) bu=true;
    if (specl&&!isdigit(uch)&&!islower(uch)&&!isupper(uch)) bs=true;
   }
   if (nums&&!bn) tag=true;
   if (lowr&&!bl) tag=true;
   if (uppr&&!bu) tag=true;
   if (specl&&!bs) tag=true;
   if (!tag) return {S,cnt};
  }
  return {"FAIL",-1LL};
 }
};

void build_traditional(const string& fname)
{
 markov base;
 ifstream fin("rockyou.txt");
 string line;
 while (getline(fin,line))
 {
  while (!line.empty()&&(line.back()=='\n'||line.back()=='\r')) line.pop_back();
  base.training(line);
 }
 ofstream fout(fname,ios::binary);
 ll sz=(ll)base.model.size();
 fout.write(reinterpret_cast<const char*>(&sz),sizeof(sz));
 for (const auto& [state,nexts]:base.model)
 {
  fout.write(reinterpret_cast<const char*>(&state.first),sizeof(state.first));
  fout.write(reinterpret_cast<const char*>(&state.second),sizeof(state.second));
  ll vec_size=(ll)nexts.size();
  fout.write(reinterpret_cast<const char*>(&vec_size),sizeof(vec_size));
  fout.write(reinterpret_cast<const char*>(nexts.data()),vec_size*sizeof(int));
 }
}
markov cursion;
void load_traditional(const string& fname)
{
 ifstream fin(fname,ios::binary);
 if (!fin) return;
 ll sz;
 cursion.model.clear();
 fin.read(reinterpret_cast<char*>(&sz),sizeof(sz));
 for (ll i=0;i<sz;i++)
 {
  int fst,snd;
  fin.read(reinterpret_cast<char*>(&fst),sizeof(fst));
  fin.read(reinterpret_cast<char*>(&snd),sizeof(snd));
  ll vec_size;
  fin.read(reinterpret_cast<char*>(&vec_size),sizeof(vec_size));
  vector<int> nexts(vec_size); 
  fin.read(reinterpret_cast<char*>(nexts.data()),vec_size*sizeof(int));
  cursion.model[{fst,snd}]=nexts;
 }
}
vector<string> run_traditional(const string& S,ll length,bool nums,bool lowr,bool uppr,bool specl,ll how_many)
{
 if (cursion.model.empty()) load_traditional("traditional_map.bin");
 vector<string> temp;
 ll pos=0LL;
 while (pos<how_many)
 {
  auto ts=cursion.getting(length,nums,lowr,uppr,specl);
  if (ts.first=="FAIL"&&ts.second==-1LL) continue;
  temp.push_back(ts.first);
  pos++;
 }
 return temp;
}
