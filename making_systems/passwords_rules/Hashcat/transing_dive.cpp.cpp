#include "codon_mutation_functions.cpp"
#include <iostream>
#include <string>
#include <fstream>
using ll=long long;
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string S; cin>>S; string org=S;
    ifstream password("transed_dive.rule");
    ofstream fout("password_dive_result.txt");
    cin.rdbuf(password.rdbuf());
    string line;
    while (cin>>line)
    {
        if (func(S,line))
        {
            fout<<S<<"\n";
            S=org;
        }
    }
    return 0;
}