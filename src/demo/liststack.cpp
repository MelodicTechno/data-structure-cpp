#include "Stack/ListStack.h"
#include <iostream>

int main() {
    ListStack st(10);
    for (int i = 0; i < 9; i++) {
        st.push(i);
    }

    std::cout << st.peek() << std::endl;
    std::cout << "the size of the stack is " << st.size() << std::endl;
    while (!st.isEmpty()) {
        std::cout << st.pop() << " ";
    }
    std::cout << std::endl;
}