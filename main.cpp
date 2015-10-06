#include <iostream>
#include "project_euler.h"
#include <chrono>
#include "big_int.h"

using namespace std;
using namespace std::chrono;

int main()
{
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    euler::SolveP080();
    high_resolution_clock::time_point t2 = high_resolution_clock::now();

//    string blah = "4142135623730950488016887242096980785696718753769480731766797379907324784621070388503875343276415727";
//    int sum = 0;
//    for (char c : blah)
//    {
//        sum += (c - '0');
//    }
//    cout << sum << endl;
    long long int duration = duration_cast<milliseconds>(t2 - t1).count();
    cout << "Run time: " << duration / 1000.0 << " seconds" << endl;

    return 0;
}