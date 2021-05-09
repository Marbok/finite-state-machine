#pragma once

#include <set>
#include <map>

using namespace std;

namespace bc
{
    enum State
    {
        VALID,
        INVALID
    };

    const set<char> V = {'0', '1'};
    const set<State> Q = {VALID, INVALID};
    const State S = INVALID;
    const set<State> F = {VALID};
    const map<State, map<char, State>> d = {
        {INVALID, {{'0', VALID}, {'1', VALID}}},
        {VALID, {{'0', VALID}, {'1', VALID}}}};
}
