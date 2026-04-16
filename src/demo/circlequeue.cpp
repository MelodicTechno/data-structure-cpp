#include "Queue/CircleQueue.h"
#include <iostream>

int main() {
    CircleQueue queue(5);
    queue.offer(1);
    queue.offer(2);
    queue.offer(3);
    std::cout << queue.pop() << std::endl;
    queue.offer(4);
    std::cout << queue.size() << std::endl;
    while (!queue.isEmpty()) {
        std::cout << queue.pop() << " ";
    }
    std::cout << std::endl;
}