/**
 * Auth :   liubo
 * Date :   2022/3/20 12:59
 * Comment: 堆排序
 *              核心思想是，堆积，土堆，组织成二叉树的形状。
 *                  然后利用特性：小顶堆，每个子节点都比父节点大
 *              复杂度o(nlogn)
 *  图文解释：https://zhuanlan.zhihu.com/p/45725214
 */

#ifndef TEST_ALG_HEAPSORT_H
#define TEST_ALG_HEAPSORT_H

#include <vector>
#include <iostream>
#include <assert.h>
#include "Utils.h"

class HeapSortSln {
public:

    // 大顶堆
    static void HeapSortMax(std::vector<int>& Data)
    {
        int Len = Data.size();

        // 从后往前，比较根和子节点，如果不满足“根比子节点大“，那么调换”根和子节点的值“
        for(int i=Len/2-1; i>=0; i--)
        {
            MaxHeapify(Data, i, Len);
        }

        // 上一步，能够保证所有的根，比所有的子节点大
        // 那么，第0个元素是最大的，与最后一位交换
        // 然后再执行MaxHeapify，构建[0, n-1]的堆
        // 那么此时，第0个元素是[0,n-1]中最大的，同样与最后一位交换
        // 如此反复，直到结束
        for(int i=Len-1; i>=0; i--)
        {
            utils::Swap(Data[i], Data[0]);
            MaxHeapify(Data, 0, i);
        }
    }

    // 小顶堆
    static void HeapSortMin(std::vector<int>& Data)
    {
        int Len = Data.size();

        // 小顶堆，那么文字中的“大”应该换成“小”
        // 从后往前，比较根和子节点，如果不满足“根比子节点小“，那么调换”根和子节点的值“
        for(int i=Len/2-1; i>=0; i--)
        {
            MinHeapify(Data, i, Len);
        }

        // 上一步，能够保证所有的根，比所有的子节点大
        // 那么，第0个元素是最大的，与最后一位交换
        // 然后再执行MaxHeapify，构建[0, n-1]的堆
        // 那么此时，第0个元素是[0,n-1]中最大的，同样与最后一位交换
        // 如此反复，直到结束
        for(int i=Len-1; i>=0; i--)
        {
            utils::Swap(Data[i], Data[0]);
            MinHeapify(Data, 0, i);
        }
    }
    template<class T>
    static void HeapSortTemplate(std::vector<int>& Data, T func)
    {
        int Len = Data.size();

        // 小顶堆，那么文字中的“大”应该换成“小”
        // 从后往前，比较根和子节点，如果不满足“根比子节点小“，那么调换”根和子节点的值“
        for(int i=Len/2-1; i>=0; i--)
        {
            TemplateHeapify(Data, i, Len, func);
        }

        // 上一步，能够保证所有的根，比所有的子节点大
        // 那么，第0个元素是最大的，与最后一位交换
        // 然后再执行MaxHeapify，构建[0, n-1]的堆
        // 那么此时，第0个元素是[0,n-1]中最大的，同样与最后一位交换
        // 如此反复，直到结束
        for(int i=Len-1; i>=0; i--)
        {
            utils::Swap(Data[i], Data[0]);
            TemplateHeapify(Data, 0, i, func);
        }
    }

    static void Test()
    {
        std::vector<int> Data = {3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6, 1};

        // 从小到大排列，那么应该用“大顶堆”
#define SmallToBig 1

#if 1
        HeapSortTemplate(Data, [](int a, int b)
        {
#if SmallToBig
            return a > b;
#else
            return a < b;
#endif

        });
#else
#if SmallToBig
        HeapSortMax(Data);
#else
        HeapSortMin(Data);
#endif
#endif

        int Last = Data[0];
        for(auto it : Data)
        {
#if SmallToBig
            assert(Last <= it);
#else
            assert(Last >= it);
#endif

            std::cout << it << " ";
        }
        std::cout << std::endl;
    }

private:

    // 确保所有的“父节点”都比“子节点”大
    static void MaxHeapify(std::vector<int>& Data, int Start, int Len)
    {
        int Dad = Start;
        int Son = Dad * 2 + 1;
        while(Son < Len)
        {
            assert(Dad >= 0 && Son >= 0);

            // 找到最大的儿子
            if(Son+1 < Len && Data[Son+1] > Data[Son] )
            {
                Son = Son + 1;
            }

            // 如果父亲比儿子大，那么完毕
            if(Data[Dad] > Data[Son])
            {
                return;
            }
            else
            {
                utils::Swap(Data[Dad], Data[Son]);
                Dad = Son;
                Son = Dad * 2 + 1;
            }
        }
    }

    // 确保所有的“父节点”都比“子节点”小
    static void MinHeapify(std::vector<int>& Data, int Start, int Len)
    {
        int Dad = Start;
        int Son = Dad * 2 + 1;
        while(Son < Len)
        {
            assert(Dad >= 0 && Son >= 0);

            // 找到最大的儿子
            if(Son+1 < Len && Data[Son+1] < Data[Son] )
            {
                Son = Son + 1;
            }

            // 如果父亲比儿子大，那么完毕
            if(Data[Dad] < Data[Son])
            {
                return;
            }
            else
            {
                utils::Swap(Data[Dad], Data[Son]);
                Dad = Son;
                Son = Dad * 2 + 1;
            }
        }
    }

    // 确保所有的“父节点”都比“子节点” “大或者小”
    template<class T>
    static void TemplateHeapify(std::vector<int>& Data, int Start, int Len, T func)
    {
        int Dad = Start;
        int Son = Dad * 2 + 1;
        while(Son < Len)
        {
            assert(Dad >= 0 && Son >= 0);

            // 找到最大的儿子
            if(Son+1 < Len && func(Data[Son+1], Data[Son] ))
            {
                Son = Son + 1;
            }

            // 如果父亲比儿子大，那么完毕
            if(func(Data[Dad], Data[Son]))
            {
                return;
            }
            else
            {
                utils::Swap(Data[Dad], Data[Son]);
                Dad = Son;
                Son = Dad * 2 + 1;
            }
        }
    }
};


#endif //TEST_ALG_HEAPSORT_H
