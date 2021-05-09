#pragma once

#include <string>
#include <set>
#include <map>

using namespace std;

template <typename State>
class FSM
{
private:
    const set<char> &alphabet;
    const set<State> &states;
    State curr_state;
    const set<State> &target_state;
    const map<State, map<char, State>> &transitions;

public:
    explicit FSM(const set<char> &alphabet,
                 const set<State> &states,
                 State start_state,
                 const set<State> &target_state,
                 const map<State, map<char, State>> &transitions)
        : alphabet(alphabet), states(states), curr_state(start_state), target_state(target_state), transitions(transitions)
    {
    }

    bool Test(const string &str)
    {
        for (const auto &c : str)
        {
            BelongAlphabet(c);
            ChangeState(c);
        }
        return target_state.find(curr_state) != end(target_state);
    }

private:
    void ChangeState(const char &c)
    {
        try
        {
            curr_state = transitions.at(curr_state).at(c);
        }
        catch (exception &e)
        {
            throw invalid_argument("Not transition!!!");
        }
    }

    void BelongAlphabet(const char &c)
    {
        if (alphabet.find(c) == end(alphabet))
        {
            throw invalid_argument("Unknown symbol!!!");
        }
    }
};