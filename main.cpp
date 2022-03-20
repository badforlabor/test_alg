#include <iostream>
#include "HeapSort.h"
#include "QuickSort.h"
#include "MergeSort.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    std::vector<int> Data = {3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6, 1};
    std::vector<int> Data1 = {3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6};

    HeapSortSln::Test(Data);
    HeapSortSln::Test(Data1);

    QuickSortSln::Test(Data);
    QuickSortSln::Test(Data1);

    MergeSortSln::Test(Data);
    MergeSortSln::Test(Data1);

    return 0;
}
