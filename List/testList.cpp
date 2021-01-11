# include <iostream>
# include <fstream>
# include <string>
# include <sstream>

#include "List.hpp"
#include "../utils.hpp"

void    list_enum(ft::List<int> &lst) {
    ft::List<int>::iterator it;
    ft::List<int>::iterator it2;

    it = lst.begin();
    it2 = lst.end();

    std::cout << "\e[1;33mEnumeration" << std::endl;
    while (it != it2) {
        std::cout << *it << std::endl;
        it++;
    }
}

void    lst_test_iterator() {
    std::cout << "\e[0;34m----------ITERATOR----------" << std::endl;

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

    lst.clear();
}

void    lst_test_capacity() {
    std::cout << "\e[0;34m----------CAPACITY----------" << std::endl;

    ft::List<int> lst;
    list_enum(lst);
    std::cout << "empty ?: " << lst.empty() << std::endl;
    std::cout << "size: " << lst.size() << std::endl;
    lst.push_front(111);
    lst.push_front(0);
    lst.push_front(0);
    lst.push_front(0);
    lst.push_front(999);

    list_enum(lst);

    std::cout << "empty ?: " << lst.empty() << std::endl;
    std::cout << "size: " << lst.size() << std::endl;
    std::cout << "max size: " << lst.max_size() << std::endl;

    lst.pop_front();
    list_enum(lst);

    std::cout << "empty ?: " << lst.empty() << std::endl;
    std::cout << "size: " << lst.size() << std::endl;

    lst.clear();
    list_enum(lst);
    std::cout << "empty ?: " << lst.empty() << std::endl;
    std::cout << "size: " << lst.size() << std::endl;
}

void    lst_test_access() {
    std::cout << "\e[0;34m----------ACCESS----------" << std::endl;

    ft::List<int> lst;
    lst.push_front(111);
    lst.push_front(0);
    lst.push_front(0);
    lst.push_front(0);
    lst.push_front(999);

    list_enum(lst);

    std::cout << "front: " << lst.front() << std::endl;
    std::cout << "back: " << lst.back() << std::endl;

    lst.clear();
}

void    lst_test_assign() {
    std::cout << "\e[0;34m----------ASSIGN----------" << std::endl;

    ft::List<int> lst;
    lst.push_front(111);
    lst.push_front(0);
    lst.push_front(0);
    lst.push_front(0);
    lst.push_front(999);

    list_enum(lst);

    std::cout <<  "Assign" << std::endl;
    lst.assign((size_t)8, (const int)42);
    list_enum(lst);

    ft::List<int> lst2;
    lst2.push_front(111);
    lst2.push_front(0);
    lst2.push_front(0);
    lst2.push_front(0);
    lst2.push_front(999);

    std::cout << "lst2" << std::endl;
    list_enum(lst2);

    std::cout <<  "Assign" << std::endl;
    lst.assign(lst2.begin(), lst2.end());
    list_enum(lst);

    lst.clear();
    lst2.clear();
}

void    lst_test_push_pop() {
    std::cout << "\e[0;34m----------PUSH & POP----------" << std::endl;

    ft::List<int> lst;
    lst.push_front(111);
    lst.push_front(0);
    lst.push_front(0);
    lst.push_front(0);
    lst.push_front(999);

    list_enum(lst);

    lst.pop_front();
    list_enum(lst);

    lst.pop_back();
    list_enum(lst);

    lst.push_back(42);
    list_enum(lst);

    lst.clear();
}

void    lst_test_insert() {
    std::cout << "\e[0;34m----------INSERT----------" << std::endl;

    ft::List<int> lst;
    lst.push_front(111);
    lst.push_front(0);
    lst.push_front(0);
    lst.push_front(0);
    lst.push_front(999);

    list_enum(lst);

    lst.insert(lst.begin(), 42);
    lst.insert(lst.end(), 42);

    list_enum(lst);

    lst.insert(lst.end(), (size_t)8, 3);

    list_enum(lst);

    ft::List<int> lst2(lst);

    lst.insert(lst.end(), lst2.begin(), lst2.end());

    list_enum(lst);

    lst.clear();
    lst2.clear();
}

void    lst_test_erase() {
    std::cout << "\e[0;34m----------ERASE----------" << std::endl;

    ft::List<int> lst;
    lst.push_front(111);
    lst.push_front(0);
    lst.push_front(0);
    lst.push_front(0);
    lst.push_front(999);

    list_enum(lst);

    lst.erase(lst.begin());

    list_enum(lst);

    ft::List<int>::iterator it;

    it = lst.begin();
    it++;

    lst.erase(it, lst.end());

    list_enum(lst);

    lst.clear();    
}

void    lst_test_swap() {
    std::cout << "\e[0;34m----------SWAP----------" << std::endl;

    ft::List<int> lst;
    lst.push_front(111);
    lst.push_front(0);
    lst.push_front(0);
    lst.push_front(0);
    lst.push_front(999);

    ft::List<int> lst2;
    lst2.push_front(42);
    lst2.push_front(42);
    lst2.push_front(42);
    lst2.push_front(42);
    lst2.push_front(42);

    std::cout << "\e[1;33mlst" << std::endl;
    list_enum(lst);
    std::cout << "lst2" << std::endl;
    list_enum(lst2);

    std::cout << "swap" << std::endl;
    lst.swap(lst2);

    std::cout << "lst" << std::endl;
    list_enum(lst);
    std::cout << "lst2" << std::endl;
    list_enum(lst2);
}

void    lst_test_resize() {
    std::cout << "\e[0;34m----------RESIZE----------" << std::endl;

    ft::List<int> lst;
    lst.push_front(111);
    lst.push_front(0);
    lst.push_front(0);
    lst.push_front(0);
    lst.push_front(999);

    list_enum(lst);

    lst.resize(2);
    list_enum(lst);
    lst.resize(8, 42);
    list_enum(lst);
}

void    lst_test_clear() {
    std::cout << "\e[0;34m----------CLEAR----------" << std::endl;

    ft::List<int> lst;
    lst.push_front(111);
    lst.push_front(0);
    lst.push_front(0);
    lst.push_front(0);
    lst.push_front(999);

    list_enum(lst);
    lst.clear();
    list_enum(lst);
}

void    lst_test_splice() {
    std::cout << "\e[0;34m----------SPLICE----------" << std::endl;

    ft::List<int> lst;
    lst.push_front(111);
    lst.push_front(0);
    lst.push_front(0);
    lst.push_front(0);
    lst.push_front(999);

    ft::List<int> lst2;
    lst2.push_front(42);
    lst2.push_front(42);
    lst2.push_front(42);
    lst2.push_front(42);
    lst2.push_front(42);

    std::cout << "\e[1;33mlst" << std::endl;
    list_enum(lst);
    std::cout << "lst2" << std::endl;
    list_enum(lst2);

    std::cout << "splice" << std::endl;
    lst.splice(lst.end(), lst2);
    std::cout << "\e[1;33mlst" << std::endl;
    list_enum(lst);
    std::cout << "lst2" << std::endl;
    list_enum(lst2);

    std::cout << "splice" << std::endl;
    lst2.splice(lst2.end(), lst, lst.begin());
    std::cout << "\e[1;33mlst" << std::endl;
    list_enum(lst);
    std::cout << "lst2" << std::endl;
    list_enum(lst2);

    ft::List<int>::iterator it;
    it = lst.begin();
    it++;

    std::cout << "splice" << std::endl;
    lst2.splice(lst2.end(), lst, it, lst.end());
    std::cout << "\e[1;33mlst" << std::endl;
    list_enum(lst);
    std::cout << "lst2" << std::endl;
    list_enum(lst2);
}

void    lst_test_remove() {
    std::cout << "\e[0;34m----------REMOVE----------" << std::endl;

    ft::List<int> lst;
    lst.push_front(111);
    lst.push_front(0);
    lst.push_front(0);
    lst.push_front(0);
    lst.push_front(999);

    list_enum(lst);

    lst.remove(0);
    list_enum(lst);
}

bool predicate1(int i) {
    return i == 42;
}

bool predicate2(int i) {
    return i > 1;
}

void    lst_test_remove_if() {
    std::cout << "\e[0;34m----------REMOVE IF----------" << std::endl;

    ft::List<int> lst;
    lst.push_front(111);
    lst.push_front(0);
    lst.push_front(0);
    lst.push_front(0);
    lst.push_front(999);

    list_enum(lst);
    
    lst.remove_if(&predicate1);

    list_enum(lst);

    lst.remove_if(&predicate2);

    list_enum(lst);
}

void    lst_test_unique() {
    std::cout << "\e[0;34m----------UNIQUE----------" << std::endl;

    ft::List<int> lst;
    lst.push_front(111);
    lst.push_front(111);
    lst.push_front(0);
    lst.push_front(0);
    lst.push_front(0);
    lst.push_front(999);
    lst.push_front(999);

    list_enum(lst);

    lst.unique();

    list_enum(lst);
}

void    lst_test_merge_sort_reverse() {
    std::cout << "\e[0;34m----------MERGE SORT REVERSE----------" << std::endl;

    ft::List<int> lst;
    lst.push_front(111);
    lst.push_front(111);
    lst.push_front(0);
    lst.push_front(0);
    lst.push_front(0);
    lst.push_front(999);
    lst.push_front(999);

    ft::List<int> lst2;
    lst2.push_front(1);
    lst2.push_front(2);
    lst2.push_front(3);
    lst2.push_front(4);
    lst2.push_front(5);
    lst2.push_front(6);
    lst2.push_front(7);
    lst2.push_front(8);
    lst2.push_front(9);

    std::cout << "\e[1;33mlst" << std::endl;
    list_enum(lst);
    std::cout << "lst2" << std::endl;
    list_enum(lst2);

    std::cout << "sort" << std::endl;
    lst.sort();
    lst2.sort();

    std::cout << "\e[1;33mlst" << std::endl;
    list_enum(lst);
    std::cout << "lst2" << std::endl;
    list_enum(lst2);

    std::cout << "merge" << std::endl;
    lst.merge(lst2);

    std::cout << "\e[1;33mlst" << std::endl;
    list_enum(lst);
    std::cout << "lst2" << std::endl;
    list_enum(lst2);

    std::cout << "reverse" << std::endl;
    lst.reverse();

    std::cout << "\e[1;33mlst" << std::endl;
    list_enum(lst);
    std::cout << "lst2" << std::endl;
    list_enum(lst2);
}

void    lst_test_relational_operators() {
    std::cout << "\e[0;34m----------RELATIONAL OPERTORS----------" << std::endl;

	ft::List<int> lst;
    lst.push_front(111);
    lst.push_front(111);
    lst.push_front(0);
    lst.push_front(0);
    lst.push_front(0);
    lst.push_front(999);
    lst.push_front(999);
	ft::List<int> lst2(lst);

    std::cout << "\e[1;33mlst" << std::endl;
    list_enum(lst);
    std::cout << "lst2" << std::endl;
    list_enum(lst2);

	std::cout << (lst == lst2) << std::endl;
	std::cout << (lst >= lst2) << std::endl;
	std::cout << (lst <= lst2) << std::endl;

	lst2.push_back(50);
	std::cout << (lst != lst2) << std::endl;
	std::cout << (lst < lst2) << std::endl;
	std::cout << (lst <= lst2) << std::endl;
	std::cout << (lst2 > lst) << std::endl;
	std::cout << (lst2 >= lst) << std::endl;

	lst.push_back(200);
	std::cout << (lst != lst2) << std::endl;
	std::cout << (lst > lst2) << std::endl;
	std::cout << (lst >= lst2) << std::endl;
	std::cout << (lst2 < lst) << std::endl;
	std::cout << (lst2 <= lst) << std::endl;
}


void testList() {
	lst_test_iterator();
    lst_test_capacity();
    lst_test_access();
    lst_test_assign();
    lst_test_push_pop();
    lst_test_insert(); 
    lst_test_erase();
    lst_test_swap();
    lst_test_resize();
    lst_test_clear();
    lst_test_splice();
    lst_test_remove();
    lst_test_remove_if();
    lst_test_unique();
    lst_test_merge_sort_reverse();
    lst_test_relational_operators();
}