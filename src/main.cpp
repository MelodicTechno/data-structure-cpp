#include "Queue/Queue.h"

#include <iostream>

int main() {
    Queue q;
    for (int i = 0; i < 8; i++) {
        q.offer(i);
    }
    std::cout << q.top() << " " << q.tail() << std::endl;
    std::string s1 = "!";
    std::string s2 = "!";
    std::cout << (s1 == s2) << std::endl;
}
