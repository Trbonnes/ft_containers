# include <iostream>
# include <fstream>
# include <string>
# include <sstream>

#include "Stack.hpp"
#include "../utils.hpp"

void testStack() {
    std::cout << "\e[0;34m----------ALL IN ONE----------" << std::endl;
    ft::Stack<int> stack;
    std::cout << "\e[1;33mempty 1: " << stack.empty() << std::endl;
    stack.push(111);
    stack.push(0);
    stack.push(0);
    stack.push(0);
    stack.push(999);

    ft::Stack<int> stack2;
    std::cout << "empty 2: " << stack2.empty() << std::endl;
    stack2.push(1);
    stack2.push(2);
    stack2.push(3);
    stack2.push(4);
    stack2.push(5);
    stack2.push(6);
    stack2.push(7);
    stack2.push(8);
    stack2.push(9);

    std::cout << "empty 1: " << stack.empty() << std::endl;
    std::cout << "empty 2: " << stack2.empty() << std::endl;

    std::cout << "size 1: " << stack.size() << std::endl;
    std::cout << "size 2: " << stack2.size() << std::endl;

    stack.pop();
    std::cout << "size 1: " << stack.size() << std::endl;
    std::cout << "size 2: " << stack2.size() << std::endl;

    stack.push(999);
    int size = stack.size();

    for (int i = 0; i < size; i++) {
        std::cout << stack.top() << std::endl;
        stack.pop();
    }

    size = stack2.size();

    for (int i = 0; i < size; i++) {
        std::cout << stack2.top() << std::endl;
        stack2.pop();
    }

    std::cout << "empty 1: " << stack.empty() << std::endl;
    std::cout << "empty 2: " << stack2.empty() << std::endl;

    stack.push(111);
    stack.push(0);
    stack.push(0);
    stack.push(0);
    stack.push(999);
    stack2.push(111);
    stack2.push(0);
    stack2.push(0);
    stack2.push(0);
    stack2.push(999);

	std::cout << (stack == stack2) << std::endl;
	std::cout << (stack >= stack2) << std::endl;
	std::cout << (stack <= stack2) << std::endl;

	stack2.push(50);
	std::cout << (stack != stack2) << std::endl;
	std::cout << (stack < stack2) << std::endl;
	std::cout << (stack <= stack2) << std::endl;
	std::cout << (stack2 > stack) << std::endl;
	std::cout << (stack2 >= stack) << std::endl;

	stack.push(200);
	std::cout << (stack != stack2) << std::endl;
	std::cout << (stack > stack2) << std::endl;
	std::cout << (stack >= stack2) << std::endl;
	std::cout << (stack2 < stack) << std::endl;
	std::cout << (stack2 <= stack) << std::endl;
}