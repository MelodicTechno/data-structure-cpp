#include <iostream>
#include <vector>

void headAdjust(std::vector<int>& a, int k, int n) {
    int temp = a[k];  // Store the root
    
    for (int i = 2 * k + 1; i < n; i = 2 * i + 1) {
        // Find the larger child
        if (i + 1 < n && a[i] < a[i + 1]) {
            i++;
        }
        
        // If parent is already larger, we're done
        if (temp >= a[i]) {
            break;
        }
        
        // Move the larger child up
        a[k] = a[i];
        k = i;
    }
    
    a[k] = temp;  // Place the original root in correct position
}

void buildMaxHeap(std::vector<int>& a) {
    int n = a.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        headAdjust(a, i, n);
    }
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void heapSort(std::vector<int>& a) {
    buildMaxHeap(a);  // First build the max heap
    
    int n = a.size();
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);  // Move max to end
        headAdjust(a, 0, i);  // Restore heap property
    }
}

int main() {
    std::vector<int> a = {38, 65, 97, 76, 13, 27, 49};
    
    heapSort(a);
    
    for (int i = 0; i < a.size(); i++) {
        std::cout << a[i] << ' ';
    }
    std::cout << std::endl;
    
    return 0;
}