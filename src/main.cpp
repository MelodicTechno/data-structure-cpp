// #include "LinkedList/LinkedList.h"
#include "Stack/Stack.h"

#include <iostream>

int main() {
    // LinkedList list;
    // list.add(1);
    // list.add(2);
    // list.addBack(3);
    // list.remove(0);
    // list.print();
    // std::cout << list.size() << std::endl;
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.pop();
    st.push(4);
    st.push(5);
    while (!st.isEmpty()) {
        std::cout << st.pop() << " ";
    }
}
