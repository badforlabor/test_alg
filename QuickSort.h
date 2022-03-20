/**
 * Auth :   liubo
 * Date :   2022/3/20 16:07
 * Comment: 快排
 *      https://zhuanlan.zhihu.com/p/40179798
 *      https://www.runoob.com/w3cnote/quick-sort-2.html
 *
 */

#ifndef TEST_ALG_QUICKSORT_H
#define TEST_ALG_QUICKSORT_H
#include "Utils.h"

class QuickSortSln {

public:
    static void QuickSort(std::vector<int>& Data)
    {
        QuickSort(Data, 0, Data.size() - 1);
    }
    static void Test(std::vector<int> Data)
    {
        QuickSort(Data);

        utils::DumpSmallToBig(Data);
    }

private:

    static void QuickSort(std::vector<int>& Data, int Low, int High)
    {
        if(Low < High)
        {
            int Pivot = Paritition1(Data, Low, High);
            QuickSort(Data, Low, Pivot - 1);
            QuickSort(Data, Pivot + 1, High);
        }
    }
    // 从数列中挑出一个元素，称为 "基准"（pivot）;
    // 然后遍历所有的元素，将小于Pivot的放在左边，大于Pivot的放在右边
    static int Paritition(std::vector<int>& Data, int Low, int High)
    {
        // 随便找一个Pivot
        auto Pivot = Data[Low];

        while(Low < High)
        {
            // 比Pivot大的，放在右边
            while(Low < High && Data[High] > Pivot)
            {
                High--;
            }
            // 找到第一个比Pivot小的元素
            Data[Low] = Data[High];

            // 比Pivot小的，放在左边
            while(Low < High && Data[Low] <= Pivot)
            {
                Low++;
            }
            Data[High] = Data[Low];
        }
        Data[Low] = Pivot;

        return Low;
    }

    static int Paritition1(std::vector<int>& Data, int Low, int High)
    {
        assert(Low < High);

        // 随便找一个Pivot
        auto First = Low;
        auto Pivot = Data[First];

        // 刨除第0个
        Low = First + 1;

        while(Low < High)
        {
            // 比Pivot大的，放在右边
            // 比Pivot小的，放在左边
            // 那么，可以，从右边找到第一个比Pivot小的，从左边找到第一个比Pivot大的，然后交换两者
            while(Low < High && Data[High] > Pivot)
            {
                High--;
            }
            while(Low < High && Data[Low] <= Pivot)
            {
                Low++;
            }
            assert(Low <= High);

            utils::Swap(Data[Low], Data[High]);
        }

        // Data[Low]理论上就是中间了，如果比Data[First]小，那么交换一下
        if(Data[Low] < Data[First])
        {
            utils::Swap(Data[Low], Data[First]);
        }

        return Low;
    }
};


#endif //TEST_ALG_QUICKSORT_H
