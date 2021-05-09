#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>

#include "fsm.h"

using namespace std;

/* const set<char> V1 = {'a', 'b', 'c', 'd', 'e', 'f'};
const set<char> V2 = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
const set<char> V3 = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')'};

const set<string> Q = {"q0", "q1", "q2", "q3", "q4", "q5", "q6", "q7", "q8", "q9", "q10"};
const string S = "q0";
const set<string> F = {"q0", "q1"}; */

/* set<char> &set_union(vector<set<char>> &alphabets)
{
    set<char> V;
    for (const auto &alphabet : alphabets)
    {
        for (const auto &c : alphabet)
        {
            V.insert(c);
        }
    }
    return V;
} */

const set<char> V = {'0', '1'};
const set<string> Q = {"q0", "q1"};
const string S = "q0";
const set<string> F = {"q1"};
const map<string, map<char, string>> d = {
    {"q0", {{'0', "q1"}, {'1', "q1"}}},
    {"q1", {{'0', "q1"}, {'1', "q1"}}}};

int main()
{
    string in;
    cin >> in;

    //    set<char> V = set_union({V1, V2, V3});
    FSM fsm(V, Q, S, F, d);

    try
    {
        bool result = fsm.Test(in);
        cout << result << endl;
    }
    catch (exception &e)
    {
        cout << false << endl;
    }
    return 0;
}