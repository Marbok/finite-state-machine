#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <map>


#include "binary_code.h"
#include "string_validation.h"
#include "fsm.h"

using namespace std;


int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        cerr << "Not arguments" << endl;
        exit(1);
    }
    string in = argv[1];

    //FSM<bc::State> fsm(bc::V, bc::Q, bc::S, bc::F, bc::d); // binary code validation

    FSM<sv::State> fsm(sv::V, sv::Q, sv::S, sv::F, sv::d); // string validation validation

    try
    {
        cout << fsm.Test(in) << endl;
    }
    catch (exception &e)
    {
        cout << false << endl;
    }
    return 0;
}