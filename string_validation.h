#pragma once

#include <set>
#include <map>

using namespace std;

namespace sv
{

    set<char> set_union(const set<char> &V1, const set<char> &V2, const set<char> &V3)
    {
        set<char> result(V1);
        result.insert(begin(V2), end(V2));
        result.insert(begin(V3), end(V3));
        return result;
    }

    enum State
    {
        START_STATE,
        Q1,
        Q2,
        Q3,
        Q4,
        Q5,
        Q6,
        Q7,
        Q8,
        Q9,
        VALID
    };

    const set<char> V1 = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                          'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    const set<char> V2 = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    const set<char> V3 = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')'};
    const set<char> V = set_union(V1, V2, V3);

    map<char, State> create_transitions(State v1, State v2, State v3)
    {
        {
            map<char, State> result;
            for (const auto &c : V1)
            {
                result.insert({c, v1});
            }
            for (const auto &c : V2)
            {
                result.insert({c, v2});
            }
            for (const auto &c : V3)
            {
                result.insert({c, v3});
            }
            return result;
        }
    }

    const set<State> Q = {START_STATE, Q1, Q2, Q3, Q4, Q5, Q6, Q7, Q8, Q9, VALID};
    const State S = START_STATE;
    const set<State> F = {VALID};
    const map<State, map<char, State>> d = {
        {START_STATE, create_transitions(Q1, Q4, Q7)},
        {Q1, create_transitions(Q1, Q2, Q3)},
        {Q2, create_transitions(Q2, Q2, VALID)},
        {Q3, create_transitions(Q3, VALID, Q3)},
        {Q4, create_transitions(Q5, Q4, Q6)},
        {Q5, create_transitions(Q5, Q5, VALID)},
        {Q6, create_transitions(VALID, Q6, Q6)},
        {Q7, create_transitions(Q8, Q9, Q7)},
        {Q8, create_transitions(Q8, VALID, Q8)},
        {Q9, create_transitions(VALID, Q9, Q9)},
        {VALID, create_transitions(VALID, VALID, VALID)}};
}