#include "codon_mutation_functions.cpp" 
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using ll=long long;
using namespace std;
vector<string> run_dive(string S) 
{
    vector<string> results;
    string org=S; 
    ifstream password("transed_dive.rule");
    string line;
    while (password>>line) 
    {
        if (func(S,line))
        {
            results.push_back(S);
            S=org;
        }
    }
    return results; 
}
