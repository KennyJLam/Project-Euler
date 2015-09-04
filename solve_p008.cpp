//
// Created by KLam on 8/27/2015.
//

#include "solve_p008.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void euler::SolveP008()
{
    stringstream ss;
    ss  << "73167176531330624919225119674426574742355349194934"
        << "96983520312774506326239578318016984801869478851843"
        << "85861560789112949495459501737958331952853208805511"
        << "12540698747158523863050715693290963295227443043557"
        << "66896648950445244523161731856403098711121722383113"
        << "62229893423380308135336276614282806444486645238749"
        << "30358907296290491560440772390713810515859307960866"
        << "70172427121883998797908792274921901699720888093776"
        << "65727333001053367881220235421809751254540594752243"
        << "52584907711670556013604839586446706324415722155397"
        << "53697817977846174064955149290862569321978468622482"
        << "83972241375657056057490261407972968652414535100474"
        << "82166370484403199890008895243450658541227588666881"
        << "16427171479924442928230863465674813919123162824586"
        << "17866458359124566529476545682848912883142607690042"
        << "24219022671055626321111109370544217506941658960408"
        << "07198403850962455444362981230987879927244284909188"
        << "84580156166097919133875499200524063689912560717606"
        << "05886116467109405077541002256983155200055935729725"
        << "71636269561882670428252483600823257530420752963450";

    string target = ss.str();
    const int sub_len = 13;

    int zeros = 0;

    long long product = 1;
    long long max_product = 0;

    for (int i = 0; i < sub_len; ++i)
    {
        if (target[i] == '0')
        {
            ++zeros;
            product = 0;
        }
        else
            product *= (long long)(target[i] - '0');
    }
    max_product = product;

    int head = sub_len - 1, tail = 0;

    while (head < target.length())
    {
        if (target[tail] == '0')
            --zeros;
        else if (zeros == 0 && product != 0)
            product /= (long long)(target[tail] - '0');
        ++head;
        ++tail;
        if (target[head] == '0')
        {
            ++zeros;
            product = 0;
        }
        else if (zeros == 0)
        {
            if (product == 0)
            {
                product = 1;
                for (int i = 0; i < sub_len; ++i)
                {
                    product *= (long long)(target[tail + i] - '0');
                }
            }
            else
                product *= (long long)(target[head] - '0');
            if (product > max_product)
                max_product = product;
        }
    }

    long long solution = max_product;
    cout << "P008 solution: " << solution << endl;
}