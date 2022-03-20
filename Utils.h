//
// Created by Administrator on 2022/3/20.
//

#ifndef TEST_ALG_UTILS_H
#define TEST_ALG_UTILS_H

namespace utils
{
    template<class T>
    static void Swap(T& A, T& B)
    {
        auto Temp = B;
        B = A;
        A = Temp;
    }
}


#endif //TEST_ALG_UTILS_H
