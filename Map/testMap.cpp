# include <iostream>
# include <fstream>
# include <string>
# include <sstream>

#include "Map.hpp"
#include "../utils.hpp"

void    map_enum(ft::Map<int,int> &map) {
    ft::Map<int,int>::iterator it;
    ft::Map<int,int>::iterator it2;

    it = map.begin();
    it2 = map.end();

    std::cout << "\e[1;33mEnumeration" << std::endl;
    while (it != it2) {
        std::cout << "Key: " << it->first << "Mapped: " << it->second << std::endl;
        it++;
    }
}

void    map_test_iterator() {
    std::cout << "\e[0;34m----------ITERATOR----------" << std::endl;

    ft::Map<int,int> map;
    map.insert(std::make_pair(0, 2));
    map.insert(std::make_pair(1, 6));
    map.insert(std::make_pair(2, 0));
    map.insert(std::make_pair(8, 56));
    map.insert(std::make_pair(75, 23));
    map.insert(std::make_pair(5, 111));

    ft::Map<int,int>::iterator it;
    ft::Map<int,int>::iterator it2;
    ft::Map<int,int>::reverse_iterator rit;
    ft::Map<int,int>::reverse_iterator rit2;

    it = map.begin();
    it2 = map.end();
    rit = map.rend();
    rit2 = map.rbegin();

    std::cout << "\e[1;33mEnumeration" << std::endl;
    while (it != it2) {
        std::cout << "Key: " << it->first << "Mapped: " << it->second << std::endl;
        it++;
    }
    std::cout << "Reverse Enumeration" << std::endl;
    while (rit2 != rit) {
        std::cout << "Key: " << rit2->first << "Mapped: " << rit2->second << std::endl;
		rit2++;
    }

    it = map.begin();
    std::cout << "begin: " << "Key: " << it->first << "Mapped: " << it->second << std::endl;
    it = map.end();
    it--;
    std::cout << "end: " << "Key: " << it->first << "Mapped: " << it->second << std::endl;
    rit = map.rbegin();
    std::cout << "rbegin: " << "Key: " << rit->first << "Mapped: " << rit->second << std::endl;
    rit = map.rend();
    rit--;
    std::cout << "rend: " << "Key: " << rit->first << "Mapped: " << rit->second << std::endl;

    map.clear();
}

void    map_test_capacity() {
    std::cout << "\e[0;34m----------SIZE----------" << std::endl;

    ft::Map<int,int> map;
    map_enum(map);
    std::cout << "empty ?: " << map.empty() << std::endl;
    std::cout << "size: " << map.size() << std::endl;
    map.insert(std::make_pair(0, 2));
    map.insert(std::make_pair(1, 6));
    map.insert(std::make_pair(2, 0));
    map.insert(std::make_pair(8, 56));
    map.insert(std::make_pair(75, 23));
    map.insert(std::make_pair(5, 111));

    map_enum(map);

    std::cout << "empty ?: " << map.empty() << std::endl;
    std::cout << "size: " << map.size() << std::endl;
    std::cout << "max size: " << map.max_size() << std::endl;

    map.erase(75);
    map_enum(map);

    std::cout << "empty ?: " << map.empty() << std::endl;
    std::cout << "size: " << map.size() << std::endl;

    map.clear();
    map_enum(map);
    std::cout << "empty ?: " << map.empty() << std::endl;
    std::cout << "size: " << map.size() << std::endl;
}

void    map_test_access() {
    std::cout << "\e[0;34m----------ACCESS----------" << std::endl;

    ft::Map<int,int> map;
    map[0] = 2;
    map[1] = 6;
    map[2] = 0;
    map[8] = 56;
    map[75] = 23;
    map[5] = 111;

    map_enum(map);
    std::cout << "size: " << map.size() << std::endl;

    map.clear();
}

void    map_test_insert() {
    std::cout << "\e[0;34m----------INSERT----------" << std::endl;

    ft::Map<int,int> map;
    map.insert(std::make_pair(0, 2));
    map.insert(std::make_pair(1, 6));
    map.insert(std::make_pair(2, 0));
    map.insert(std::make_pair(8, 56));
    map.insert(std::make_pair(75, 23));
    map.insert(std::make_pair(5, 111));

    map_enum(map);

    map.insert(map.end(), std::make_pair(999, 49));
    map.insert(map.end(), std::make_pair(0, 888));

    map_enum(map);

    ft::Map<int,int> map2;

    map2.insert(map.begin(), map.end());

    std::cout << "map2" << std::endl;
    map_enum(map2);

    map.clear();
    map2.clear();
}

void    map_test_erase() {
    std::cout << "\e[0;34m----------ERASE----------" << std::endl;

    ft::Map<int,int> map;
    map.insert(std::make_pair(0, 2));
    map.insert(std::make_pair(1, 6));
    map.insert(std::make_pair(2, 0));
    map.insert(std::make_pair(8, 56));
    map.insert(std::make_pair(75, 23));
    map.insert(std::make_pair(5, 111));

    map_enum(map);

    map.erase(0);

    map_enum(map);

    map.erase(map.begin());

    map_enum(map);

    ft::Map<int,int>::iterator it;

    it = map.begin();
    it++;

    map.erase(it, map.end());

    map_enum(map);

    map.clear();    
}

void    map_test_swap() {
    std::cout << "\e[0;34m----------SWAP----------" << std::endl;

    ft::Map<int,int> map;
    map.insert(std::make_pair(0, 2));
    map.insert(std::make_pair(1, 6));
    map.insert(std::make_pair(2, 0));
    map.insert(std::make_pair(8, 56));
    map.insert(std::make_pair(75, 23));
    map.insert(std::make_pair(5, 111));

    ft::Map<int,int> map2;
    map2.insert(std::make_pair(0, 42));
    map2.insert(std::make_pair(1, 42));
    map2.insert(std::make_pair(2, 42));
    map2.insert(std::make_pair(3, 42));
    map2.insert(std::make_pair(4, 42));
    map2.insert(std::make_pair(5, 42));

    std::cout << "\e[1;33mmap" << std::endl;
    map_enum(map);
    std::cout << "map2" << std::endl;
    map_enum(map2);

    std::cout << "swap" << std::endl;
    map.swap(map2);

    std::cout << "map" << std::endl;
    map_enum(map);
    std::cout << "map2" << std::endl;
    map_enum(map2);
}

void    map_test_clear() {
    std::cout << "\e[0;34m----------CLEAR----------" << std::endl;

    ft::Map<int,int> map;
    map.insert(std::make_pair(0, 2));
    map.insert(std::make_pair(1, 6));
    map.insert(std::make_pair(2, 0));
    map.insert(std::make_pair(8, 56));
    map.insert(std::make_pair(75, 23));
    map.insert(std::make_pair(5, 111));

    map_enum(map);
    map.clear();
    map_enum(map);
}

void map_test_observers() {
    std::cout << "\e[0;34m----------OBSERVERS----------" << std::endl;

    ft::Map<int,int> map;
    map.insert(std::make_pair(0, 2));
    map.insert(std::make_pair(1, 6));
    map.insert(std::make_pair(2, 0));
    map.insert(std::make_pair(8, 56));
    map.insert(std::make_pair(75, 23));
    map.insert(std::make_pair(5, 111));
    ft::Map<int,int>::key_compare mycomp = map.key_comp();

    map_enum(map);

    ft::Map<int,int>::iterator it = map.begin();
    do {
        std::cout << it->first << " => " << it->second << '\n';
    } while ( mycomp((*it++).first, 75));
}

void map_test_operations() {
    std::cout << "\e[0;34m----------OPERATIONS----------" << std::endl;

    ft::Map<int,int> map;
    map.insert(std::make_pair(0, 2));
    map.insert(std::make_pair(1, 6));
    map.insert(std::make_pair(2, 0));
    map.insert(std::make_pair(8, 56));
    map.insert(std::make_pair(75, 23));
    map.insert(std::make_pair(5, 111));

    map_enum(map);

    std::cout << "find" << std::endl;
    std::cout << "Key: " << map.find(5)->first << "Mapped: " << map.find(5)->second << std::endl;
    std::cout << "Key: " << map.find(9)->first << "Mapped: " << map.find(9)->second << std::endl;

    std::cout << "count" << std::endl;
    std::cout << map.count(5) << std::endl;
    std::cout << map.count(9) << std::endl;

    std::cout << "lower bound" << std::endl;
    std::cout << "Key: " << map.lower_bound(5)->first << "Mapped: " << map.lower_bound(5)->second << std::endl;
    std::cout << "Key: " << map.lower_bound(9)->first << "Mapped: " << map.lower_bound(9)->second << std::endl;

    std::cout << "upper bound" << std::endl;
    std::cout << "Key: " << map.upper_bound(5)->first << "Mapped: " << map.upper_bound(5)->second << std::endl;
    std::cout << "Key: " << map.upper_bound(9)->first << "Mapped: " << map.upper_bound(9)->second << std::endl;

    std::cout << "equal range" << std::endl;
    std::cout << "first: " << map.equal_range(5).first->first << "second: " << map.equal_range(5).second->first << std::endl;
    std::cout << "first: " << map.equal_range(9).first->first << "second: " << map.equal_range(9).second->first << std::endl;
}

void testMap() {
	map_test_iterator();
    map_test_capacity();
    map_test_access();
    map_test_insert(); 
    map_test_erase();
    map_test_swap();
    map_test_clear();
    map_test_observers();
    map_test_operations();
}