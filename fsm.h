#pragma once

#include <string>
#include <set>
#include <map>

using namespace std;

class FSM
{
private:
    const set<char> &alphabet;
    const set<string> &states;
    string &curr_state;
    const set<string> &target_state;
    const map<string, map<char, string>> &transitions;

public:
    explicit FSM(const set<char> &alphabet,
                 const set<string> &states,
                 string start_state,
                 const set<string> &target_state,
                 const map<string, map<char, string>> &transitions)
        : alphabet(alphabet), states(states), curr_state(start_state), target_state(target_state), transitions(transitions)
    {
    }

    bool Test(const string &string) const;

private:
    void ChangeState(const char &c) const;
    void BelongAlphabet(const char &c) const;
};