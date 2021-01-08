#include "test.hpp"

int main() {
    std::cout << "Select Container:" << std::endl;
    std::cout << "1- List" << std::endl;
    std::cout << "2- Vector" << std::endl;
    std::cout << "3- Map" << std::endl;
    std::cout << "4- Stack" << std::endl;
    std::cout << "5- Queue" << std::endl << std::endl;

    std::cout << "Entry: ";
    std::string line;
    std::getline(std::cin, line);
    while (line.length() != 1 && line[0] < '1' && line[0] > '5') {
        std::cout << "Wrong entry" << std::endl;
        std::cout << "Entry: ";
        std::getline(std::cin, line);
    }

    if (line[0] == '1')
        testList();

    return 0;
}