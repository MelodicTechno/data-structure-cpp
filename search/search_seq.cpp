#include <iostream>
using namespace std;

struct SSTable {
    char* elem;
    int tableLen;

    SSTable(char* e, int tl) : elem(e), tableLen(tl) {}

    int searchSeq(char key) {
        this->elem[0] = key;
        int i;
        for (i = this->tableLen; this->elem[i] != key; --i);
        return i;
    }
};

int main() {
    char elem[] = {'a', 'b', 'c', 'd'}; 
    SSTable t(elem, 4);
    cout << t.searchSeq('b') << endl;
}