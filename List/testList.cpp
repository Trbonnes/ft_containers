# include <iostream>
# include <fstream>
# include <string>
# include <sstream>

#include "List.hpp"

void    test_iterator() {
    std::cout << "----------ITERATOR----------" << std::endl;

    ft::List<int> lst;
    lst.push_front(111);
    lst.push_front(0);
    lst.push_front(0);
    lst.push_front(0);
    lst.push_front(999);

    ft::List<int>::iterator it;
    ft::List<int>::iterator it2;
    ft::List<int>::reverse_iterator rit;
    ft::List<int>::reverse_iterator rit2;

    it = lst.begin();
    it2 = lst.end();
    rit = lst.rend();
    rit2 = lst.rbegin();

    std::cout << "Enumeration" << std::endl;
    while (it != it2) {
        std::cout << *it << std::endl;
        it++;
    }
    std::cout << "Reverse Enumeration" << std::endl;
    while (rit2 != rit) {
        std::cout << *rit2 << std::endl;
		rit2++;
    }

    it = lst.begin();
    std::cout << "begin: " << *it << std::endl;
    it = lst.end();
    it--;
    std::cout << "end: " << *it << std::endl;
    rit = lst.rbegin();
    std::cout << "rbegin: " << *rit << std::endl;
    rit = lst.rend();
	rit--;
    std::cout << "rend: " << *rit << std::endl;
}

void    test_capacity() {

}

void    test_access() {

}

void    test_assign() {

}

void    test_push_front() {

}

void    test_pop_front() {

}

void    test_push_back() {

}

void    test_pop_back() {

}

void    test_insert() {

}

void    test_erase() {

}

void    test_swap() {

}

void    test_resize() {

}

void    test_clear() {

}

void    test_splice() {

}

void    test_remove() {

}

void    test_remove_if() {

}

void    test_unique() {

}

void    test_merge() {

}

void    test_sort() {

}

void    test_reverse() {

}

void    test_relational_operators() {

}

void    test_swap_overload() {

}

void testList() {
	test_iterator();
    test_capacity();
    test_access();
    test_assign();
    test_push_front();
    test_pop_front();
    test_push_back();
    test_pop_back();
    test_insert(); 
    test_erase();
    test_swap();
    test_resize();
    test_clear();
    test_splice();
    test_remove();
    test_remove_if();
    test_unique();
    test_merge();
    test_sort();
    test_reverse();
    test_relational_operators();
    test_swap_overload();
}