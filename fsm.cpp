#include "fsm.h"

bool FSM::Test(const string &str) const
{
    for (const auto &c : str)
    {
        BelongAlphabet(c);
        ChangeState(c);
    }

    return target_state.find(curr_state) != end(target_state);
}

void FSM::ChangeState(const char &c) const
{
    try
    {
        curr_state = transitions.at(curr_state).at(c);
    }
    catch (exception &e)
    {
        throw invalid_argument("Not transition for " + curr_state + " by " + c);
    }
}

void FSM::BelongAlphabet(const char &c) const
{
    if (alphabet.find(c) == end(alphabet))
    {
        throw invalid_argument("Unknown symbol " + c);
    }
}