/**
 * Auth :   liubo
 * Date :   2022/3/20 16:07
 * Comment: 归并排序
 *  https://www.runoob.com/w3cnote/merge-sort.html
 *  https://zhuanlan.zhihu.com/p/44656243
 *
 *
 */
#ifndef TEST_ALG_MERGESORT_H
#define TEST_ALG_MERGESORT_H
#include "Utils.h"

class MergeSortSln {

public:

    static void MergeSort(std::vector<int>& Data)
    {
        std::vector<int> Temp = Data;

        MergeSortRecursiveOpenInterval(Data, Temp, 0, Data.size());
//        MergeSortRecursive(Data, Temp, 0, Data.size() - 1);
//        MergeSortNoneRecursive(Data, Temp);
    }

    static void Test(std::vector<int> Data)
    {
        MergeSort(Data);

        utils::DumpSmallToBig(Data);
    }

private:

    // 申请一块合并空间，和原始数据大小一样
    // 将数据分治，处理2,4,8,16个等等
    // 依次比较，并放在合并空间内，将数据小的放前面，数据大的房后面
    // 排序后，将“合并空间”的数据，复制到原始数据处
    static void MergeSortRecursive(std::vector<int>& Data, std::vector<int>& Temp, int Start, int End)
    {
        if(Start >= End)
        {
            return;
        }

        int Mid = (End - Start) / 2 + Start;

        // 拆成2份，比较2份的内容，按照优先级，放在Temp上
        int Start1 = Start, End1 = Mid;
        int Start2 = Mid + 1, End2 = End;

        MergeSortRecursive(Data, Temp, Start1, End1);
        MergeSortRecursive(Data, Temp, Start2, End2);

        int K = Start;
        while(Start1 <= End1 && Start2 <= End2)
        {
            Temp[K] = Data[Start1] < Data[Start2] ? Data[Start1++] : Data[Start2++];
            K++;
        }

        while(Start1 <= End1)
        {
            Temp[K] = Data[Start1];
            Start1++;
            K++;
        }
        while(Start2 <= End2)
        {
            Temp[K] = Data[Start2];
            Start2++;
            K++;
        }

        for(int i=Start; i <= End; i++)
        {
            Data[i] = Temp[i];
        }
    }

    static void MergeSortRecursiveOpenInterval(std::vector<int>& Data, std::vector<int>& Temp, int Start, int Len)
    {
        if(Len <= 1)
        {
            return;
        }

        int Mid = (Len-1) / 2 + Start;

        // 拆成2份，比较2份的内容，按照优先级，放在Temp上
        int Start1 = Start, End1 = Mid + 1;
        int Start2 = Mid + 1, End2 = Start + Len;

        assert((End1 - Start1) <= Len);
        assert((End2 - Start2) <= Len);

        MergeSortRecursiveOpenInterval(Data, Temp, Start1, End1 - Start1);
        MergeSortRecursiveOpenInterval(Data, Temp, Start2, End2 - Start2);

        int K = Start;
        while(Start1 < End1 && Start2 < End2)
        {
            Temp[K] = Data[Start1] < Data[Start2] ? Data[Start1++] : Data[Start2++];
            K++;
        }

        while(Start1 < End1)
        {
            Temp[K] = Data[Start1];
            Start1++;
            K++;
        }
        while(Start2 < End2)
        {
            Temp[K] = Data[Start2];
            Start2++;
            K++;
        }

        for(int i=Start; i < Start + Len; i++)
        {
            Data[i] = Temp[i];
        }
    }

    static void MergeSortNoneRecursive(std::vector<int>& Data1, std::vector<int>& Temp1)
    {
        int Len = Data1.size();
        int* Data = &Data1[0];
        int* Temp = &Temp1[0];


        // 将递归平铺成非递归即可
        int Seg = 0;
        for(Seg = 1; Seg < Len; Seg *= 2)
        {
            int K = 0;
            for(int i=0; i<Len; i+=Seg*2)
            {
                int Start1 = i;
                int Start2 = i + Seg;
                int End1 = Start1 + Seg;
                int End2 = Start2 + Seg;

                if(End2 >= Len)
                {
                    End2 = Len;
                }
                if(End1 >= Len)
                {
                    End1 = Len;
                }

                while(Start1 < End1 && Start2 < End2)
                {
                    Temp[K] = Data[Start1] < Data[Start2] ? Data[Start1++] : Data[Start2++];
                    K++;
                }

                while(Start1 < End1)
                {
                    Temp[K] = Data[Start1];
                    Start1++;
                    K++;
                }
                while(Start2 < End2)
                {
                    Temp[K] = Data[Start2];
                    Start2++;
                    K++;
                }
            }
            utils::Swap(Temp, Data);
        }

        if(Data != &Data1[0])
        {
            for(int i=0; i<Len; i++)
            {
                Data1[i] = Data[i];
            }
        }
    }

};


#endif //TEST_ALG_MERGESORT_H
