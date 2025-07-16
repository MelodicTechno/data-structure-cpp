#include <iostream>
using namespace std;

struct SSTable {
    int* elem;
    int tableLen;

    SSTable(int* e, int tl) : elem(e), tableLen(tl) {}

    int searchSeq(char key) {
        this->elem[0] = key;
        int i;
        for (i = this->tableLen; this->elem[i] != key; --i);
        return i;
    }

    int binarySearch(int key) {
        int low = 0, high = this->tableLen - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (this->elem[mid] > key) {
                high = mid - 1;
            }
            else if (key > this->elem[mid]) {
                low = mid + 1;
            }
            else {
                return mid;
            }
        }
        return -1;
    }
};

int main() {
    int e[] = {1, 2, 3, 4, 5, 6, 7};
    SSTable t(e, 7);
    cout << t.binarySearch(3) << endl;
}