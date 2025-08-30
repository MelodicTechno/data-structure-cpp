#include <iostream>
#include <vector>

void merge(std::vector<int>& a, int low, int mid, int high) {
    std::vector<int> b(a.begin() + low, a.begin() + high + 1);

    int p1 = 0;                 // 左半起点
    int p2 = mid - low + 1;     // 右半起点
    int k = low;                // 写入 a 的位置

    while (p1 <= mid - low && p2 <= high - low) {
        if (b[p1] <= b[p2])
            a[k++] = b[p1++];
        else
            a[k++] = b[p2++];
    }
    while (p1 <= mid - low)  a[k++] = b[p1++];
    while (p2 <= high - low) a[k++] = b[p2++];
}

void mergeSort(std::vector<int>& a, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int main() {
    std::vector<int> a = {38, 65, 97, 76, 13, 27, 49};
    mergeSort(a, 0, a.size() - 1);

    for (int i = 0; i < a.size(); i++) {
        std::cout << a[i] << ' ';
    }
    // std::cout << std::endl;
}