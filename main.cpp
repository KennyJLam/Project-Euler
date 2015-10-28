#include <iostream>
#include "project_euler.h"
#include <chrono>

using namespace std;
using namespace std::chrono;

int main()
{
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    euler::SolveP119();
    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    long long int duration = duration_cast<milliseconds>(t2 - t1).count();
    cout << "Run time: " << duration / 1000.0 << " seconds" << endl;

    return 0;
}