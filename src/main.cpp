#include "LinkedList/LinkedList.h"
#include <iostream>

int main() {
    LinkedList list;
    list.add(1);
    list.add(2);
    std::cout << list.get(0) << std::endl;
    std::cout << list.size();
}
