//
// Created by Administrator on 2022/3/20.
//

#ifndef TEST_ALG_UTILS_H
#define TEST_ALG_UTILS_H
#include <vector>
#include <iostream>
#include <assert.h>

namespace utils
{
    template<class T>
    static void Swap(T& A, T& B)
    {
        auto Temp = B;
        B = A;
        A = Temp;
    }

    static void DumpSmallToBig(const std::vector<int>& Data)
    {
        int Last = Data[0];
        for(auto it : Data)
        {
            assert(Last <= it);

            std::cout << it << " ";
        }
        std::cout << std::endl;
    }
    static void DumpBigToSmall(const std::vector<int>& Data)
    {
        int Last = Data[0];
        for(auto it : Data)
        {
            assert(Last >= it);

            std::cout << it << " ";
        }
        std::cout << std::endl;
    }
}


#endif //TEST_ALG_UTILS_H
