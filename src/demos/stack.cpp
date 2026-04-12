#include "Stack/Stack.h"
#include <iostream>

int main() {
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
    std::cout << std::endl;
}
