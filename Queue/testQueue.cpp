# include <iostream>
# include <fstream>
# include <string>
# include <sstream>

#include "Queue.hpp"
#include "../utils.hpp"

void testQueue() {
    std::cout << "\e[0;34m----------ALL IN ONE----------" << std::endl;
    ft::Queue<int> queue;
    std::cout << "\e[1;33mempty 1: " << queue.empty() << std::endl;
    queue.push(111);
    queue.push(0);
    queue.push(0);
    queue.push(0);
    queue.push(999);

    ft::Queue<int> queue2;
    std::cout << "empty 2: " << queue2.empty() << std::endl;
    queue2.push(1);
    queue2.push(2);
    queue2.push(3);
    queue2.push(4);
    queue2.push(5);
    queue2.push(6);
    queue2.push(7);
    queue2.push(8);
    queue2.push(9);

    std::cout << "empty 1: " << queue.empty() << std::endl;
    std::cout << "empty 2: " << queue2.empty() << std::endl;

    std::cout << "size 1: " << queue.size() << std::endl;
    std::cout << "size 2: " << queue2.size() << std::endl;

    queue.pop();
    std::cout << "size 1: " << queue.size() << std::endl;
    std::cout << "size 2: " << queue2.size() << std::endl;

    queue.push(999);
    int size = queue.size();

    std::cout << queue.front() << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << queue.back() << std::endl;
        queue.pop();
    }

    size = queue2.size();

    std::cout << queue2.front() << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << queue2.back() << std::endl;
        queue2.pop();
    }

    std::cout << "empty 1: " << queue.empty() << std::endl;
    std::cout << "empty 2: " << queue2.empty() << std::endl;

    queue.push(111);
    queue.push(0);
    queue.push(0);
    queue.push(0);
    queue.push(999);
    queue2.push(111);
    queue2.push(0);
    queue2.push(0);
    queue2.push(0);
    queue2.push(999);

	std::cout << (queue == queue2) << std::endl;
	std::cout << (queue >= queue2) << std::endl;
	std::cout << (queue <= queue2) << std::endl;

	queue2.push(50);
	std::cout << (queue != queue2) << std::endl;
	std::cout << (queue < queue2) << std::endl;
	std::cout << (queue <= queue2) << std::endl;
	std::cout << (queue2 > queue) << std::endl;
	std::cout << (queue2 >= queue) << std::endl;

	queue.push(200);
	std::cout << (queue != queue2) << std::endl;
	std::cout << (queue > queue2) << std::endl;
	std::cout << (queue >= queue2) << std::endl;
	std::cout << (queue2 < queue) << std::endl;
	std::cout << (queue2 <= queue) << std::endl;
}