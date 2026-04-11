#include "LinkedList/LinkedList.h"
#include <iostream>

int main() {
    LinkedList list;
    list.add(1);
    list.add(2);
    list.addBack(3);
    list.print();
    std::cout << list.size();
}
