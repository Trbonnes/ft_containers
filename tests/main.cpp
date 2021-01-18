#include "test.hpp"

int main() {
    std::cout << "\e[0;32mSelect Container:" << std::endl;
    std::cout << "\e[1;33m1- List" << std::endl;
    std::cout << "2- Vector" << std::endl;
    std::cout << "3- Map" << std::endl;
    std::cout << "4- Stack" << std::endl;
    std::cout << "5- Queue" << std::endl << std::endl;

    std::cout << "\e[0;32mEntry: ";
    std::string line;
    std::getline(std::cin, line);
    while (line.length() != 1 && line[0] < '1' && line[0] > '5') {
        std::cout << "Wrong entry" << std::endl;
        std::cout << "Entry: ";
        std::getline(std::cin, line);
		std::cout << std::endl;
    }

    if (line[0] == '1')
        testList();
    else if (line[0] == '2')
        testVector();
    else if (line[0] == '3')
        testMap();
    else if (line[0] == '4')
        testStack();

    return 0;
}