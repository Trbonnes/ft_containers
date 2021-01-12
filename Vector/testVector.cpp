# include <iostream>
# include <fstream>
# include <string>
# include <sstream>

#include "Vector.hpp"
#include "../utils.hpp"

void    vec_enum(ft::Vector<int> &vec) {
    ft::Vector<int>::iterator it;
    ft::Vector<int>::iterator it2;

    it = vec.begin();
    it2 = vec.end();

    std::cout << "\e[1;33mEnumeration" << std::endl;
    while (it != it2) {
        std::cout << *it << std::endl;
        it++;
    }
}

void    vec_test_iterator() {
    std::cout << "\e[0;34m----------ITERATOR----------" << std::endl;

    ft::Vector<int> vec;
    vec.push_back(111);
    vec.push_back(0);
    vec.push_back(0);
    vec.push_back(0);
    vec.push_back(999);

    ft::Vector<int>::iterator it;
    ft::Vector<int>::iterator it2;
    ft::Vector<int>::reverse_iterator rit;
    ft::Vector<int>::reverse_iterator rit2;

    it = vec.begin();
    it2 = vec.end();
    rit = vec.rend();
    rit2 = vec.rbegin();

    std::cout << "\e[1;33mEnumeration" << std::endl;
    while (it != it2) {
        std::cout << *it << std::endl;
        it++;
    }
    std::cout << "Reverse Enumeration" << std::endl;
    while (rit2 != rit) {
        std::cout << *rit2 << std::endl;
		rit2++;
    }

    it = vec.begin();
    std::cout << "begin: " << *it << std::endl;
    it = vec.end();
    it--;
    std::cout << "end: " << *it << std::endl;
    rit = vec.rbegin();
    std::cout << "rbegin: " << *rit << std::endl;
    rit = vec.rend();
    rit--;
    std::cout << "rend: " << *rit << std::endl;

    vec.clear();
}

void    vec_test_capacity() {
    std::cout << "\e[0;34m----------SIZE----------" << std::endl;

    ft::Vector<int> vec;
    vec_enum(vec);
    std::cout << "empty ?: " << vec.empty() << std::endl;
    std::cout << "size: " << vec.size() << std::endl;
    vec.push_back(111);
    vec.push_back(0);
    vec.push_back(0);
    vec.push_back(0);
    vec.push_back(999);

    vec_enum(vec);

    std::cout << "empty ?: " << vec.empty() << std::endl;
    std::cout << "size: " << vec.size() << std::endl;
    std::cout << "max size: " << vec.max_size() << std::endl;

    vec.pop_back();
    vec_enum(vec);

    std::cout << "empty ?: " << vec.empty() << std::endl;
    std::cout << "size: " << vec.size() << std::endl;

    vec.clear();
    vec_enum(vec);
    std::cout << "empty ?: " << vec.empty() << std::endl;
    std::cout << "size: " << vec.size() << std::endl;
}

void    vec_test_resize() {
    std::cout << "\e[0;34m----------RESIZE----------" << std::endl;

    ft::Vector<int> vec;
    vec.push_back(111);
    vec.push_back(0);
    vec.push_back(0);
    vec.push_back(0);
    vec.push_back(999);

    vec_enum(vec);

    vec.resize(2);
    vec_enum(vec);
    vec.resize(8, 42);
    vec_enum(vec);
}

void    vec_test_reserve() {
    std::cout << "\e[0;34m----------RESERVE & CAPACITY----------" << std::endl;

    ft::Vector<int> vec;
    vec.push_back(111);
    vec.push_back(0);
    vec.push_back(0);
    vec.push_back(0);
    vec.push_back(999);

    vec_enum(vec);

    std::cout << "capacity: " << vec.capacity() << std::endl;
    vec.reserve(1);
    std::cout << "capacity: " << vec.capacity() << std::endl;
    vec.reserve(69);
    std::cout << "capacity: " << vec.capacity() << std::endl;
}

void    vec_test_access() {
    std::cout << "\e[0;34m----------ACCESS----------" << std::endl;

    ft::Vector<int> vec;
    vec.push_back(111);
    vec.push_back(0);
    vec.push_back(0);
    vec.push_back(0);
    vec.push_back(999);

    vec_enum(vec);

    std::cout << "front: " << vec.front() << std::endl;
    std::cout << "back: " << vec.back() << std::endl;

    size_t i;

    for (i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << std::endl;
        std::cout << vec.at(i) << std::endl;
    }

    try {
        std::cout << vec.at(i) << std::endl;
    }
    catch (std::exception &e ) {
        std::cout << e.what() << std::endl;
    }

    vec.clear();
}

void    vec_test_assign() {
    std::cout << "\e[0;34m----------ASSIGN----------" << std::endl;

    ft::Vector<int> vec;
    vec.push_back(111);
    vec.push_back(0);
    vec.push_back(0);
    vec.push_back(0);
    vec.push_back(999);

    vec_enum(vec);

    std::cout <<  "Assign" << std::endl;
    vec.assign((size_t)8, (const int)42);
    vec_enum(vec);

    ft::Vector<int> vec2;
    vec2.push_back(111);
    vec2.push_back(0);
    vec2.push_back(0);
    vec2.push_back(0);
    vec2.push_back(999);

    std::cout << "vec2" << std::endl;
    vec_enum(vec2);

    std::cout <<  "Assign" << std::endl;
    vec.assign(vec2.begin(), vec2.end());
    vec_enum(vec);

    vec.clear();
    vec2.clear();
}

void    vec_test_push_pop() {
    std::cout << "\e[0;34m----------PUSH & POP----------" << std::endl;

    ft::Vector<int> vec;
    vec.push_back(111);
    vec.push_back(0);
    vec.push_back(0);
    vec.push_back(0);
    vec.push_back(999);

    vec_enum(vec);

    vec.pop_back();
    vec_enum(vec);

    vec.pop_back();
    vec_enum(vec);

    vec.push_back(42);
    vec_enum(vec);

    vec.clear();
}

void    vec_test_insert() {
    std::cout << "\e[0;34m----------INSERT----------" << std::endl;

    ft::Vector<int> vec;
    vec.push_back(111);
    vec.push_back(0);
    vec.push_back(0);
    vec.push_back(0);
    vec.push_back(999);

    vec_enum(vec);

    vec.insert(vec.begin(), 42);
    vec.insert(vec.end(), 42);

    vec_enum(vec);

    vec.insert(vec.end(), (size_t)8, 3);

    vec_enum(vec);

    ft::Vector<int> vec2(vec);

    vec.insert(vec.end(), vec2.begin(), vec2.end());

    vec_enum(vec);

    vec.clear();
    vec2.clear();
}

void    vec_test_erase() {
    std::cout << "\e[0;34m----------ERASE----------" << std::endl;

    ft::Vector<int> vec;
    vec.push_back(111);
    vec.push_back(0);
    vec.push_back(0);
    vec.push_back(0);
    vec.push_back(999);

    vec_enum(vec);

    vec.erase(vec.begin());

    vec_enum(vec);

    ft::Vector<int>::iterator it;

    it = vec.begin();
    it++;

    vec.erase(it, vec.end());

    vec_enum(vec);

    vec.clear();    
}

void    vec_test_swap() {
    std::cout << "\e[0;34m----------SWAP----------" << std::endl;

    ft::Vector<int> vec;
    vec.push_back(111);
    vec.push_back(0);
    vec.push_back(0);
    vec.push_back(0);
    vec.push_back(999);

    ft::Vector<int> vec2;
    vec2.push_back(42);
    vec2.push_back(42);
    vec2.push_back(42);
    vec2.push_back(42);
    vec2.push_back(42);

    std::cout << "\e[1;33mvec" << std::endl;
    vec_enum(vec);
    std::cout << "vec2" << std::endl;
    vec_enum(vec2);

    std::cout << "swap" << std::endl;
    vec.swap(vec2);

    std::cout << "vec" << std::endl;
    vec_enum(vec);
    std::cout << "vec2" << std::endl;
    vec_enum(vec2);
}

void    vec_test_clear() {
    std::cout << "\e[0;34m----------CLEAR----------" << std::endl;

    ft::Vector<int> vec;
    vec.push_back(111);
    vec.push_back(0);
    vec.push_back(0);
    vec.push_back(0);
    vec.push_back(999);

    vec_enum(vec);
    vec.clear();
    vec_enum(vec);
}

void    vec_test_relational_operators() {
    std::cout << "\e[0;34m----------RELATIONAL OPERTORS----------" << std::endl;

	ft::Vector<int> vec;
    vec.push_back(111);
    vec.push_back(111);
    vec.push_back(0);
    vec.push_back(0);
    vec.push_back(0);
    vec.push_back(999);
    vec.push_back(999);
	ft::Vector<int> vec2(vec);

    std::cout << "\e[1;33mvec" << std::endl;
    vec_enum(vec);
    std::cout << "vec2" << std::endl;
    vec_enum(vec2);

	std::cout << (vec == vec2) << std::endl;
	std::cout << (vec >= vec2) << std::endl;
	std::cout << (vec <= vec2) << std::endl;

	vec2.push_back(50);
	std::cout << (vec != vec2) << std::endl;
	std::cout << (vec < vec2) << std::endl;
	std::cout << (vec <= vec2) << std::endl;
	std::cout << (vec2 > vec) << std::endl;
	std::cout << (vec2 >= vec) << std::endl;

	vec.push_back(200);
	std::cout << (vec != vec2) << std::endl;
	std::cout << (vec > vec2) << std::endl;
	std::cout << (vec >= vec2) << std::endl;
	std::cout << (vec2 < vec) << std::endl;
	std::cout << (vec2 <= vec) << std::endl;
}

void testVector() {
	vec_test_iterator();
    vec_test_capacity();
    vec_test_resize();
    vec_test_reserve();
    vec_test_access();
    vec_test_assign();
    vec_test_push_pop();
    vec_test_insert(); 
    vec_test_erase();
    vec_test_swap();
    vec_test_clear();
    vec_test_relational_operators();
}