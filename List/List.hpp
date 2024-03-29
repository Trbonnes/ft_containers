/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 11:12:50 by trbonnes          #+#    #+#             */
/*   Updated: 2021/01/12 11:07:23 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include <utility>
# include <limits>
# include "../ReverseIterator.hpp"
# include "../utils.hpp"

namespace ft {

	template <typename T>
	class List;

	template <typename T>
	class	ListIterator {
	public:
		typedef T value_type;
		typedef T *pointer;
		typedef T &reference;
		typedef	std::ptrdiff_t difference_type;
		typedef std::bidirectional_iterator_tag iterator_category;
		
	private:
		typedef typename List<T>::_node _node;
		typedef ListIterator<T> _Self;

		_node *_n;

	public:
		ListIterator() {}
		ListIterator(_node *node): _n(node) {}
		ListIterator(const ListIterator<T> &c): _n(c._n) {}
		~ListIterator() {}

		template <typename _T>
		friend class List;

		template <typename _T>
		friend bool operator==(const ListIterator<_T> &lhs, const ListIterator<_T> &rhs);

		template <typename _T>
		friend bool operator!=(const ListIterator<_T> &lhs, const ListIterator<_T> &rhs);

		_Self &operator=(const _Self &c) {
			_n = c._n;
			return *this;
		}

		_Self &operator++() {
			_n = _n->next;
			return *this;
		}

		_Self operator++(int) {
			_Self cpy = *this;
			++*this;
			return cpy;
		}

		_Self &operator--() {
			_n = _n->prev;
			return *this;
		}

		_Self operator--(int) {
			_Self cpy = *this;
			--*this;
			return cpy;
		}

		reference operator*() const {
			return _n->data;
		}

		pointer operator->() const {
			return &_n->data;
		}
	}; //ListIterator

	template <typename T>
	bool operator==(const ListIterator<T> &lhs, const ListIterator<T> &rhs) {
		return lhs._n == rhs._n;
	}

	template <typename T>
	bool operator!=(const ListIterator<T> &lhs, const ListIterator<T> &rhs) {
		return !(lhs._n == rhs._n);
	}

	template <typename T>
	class	List {
	public:
		typedef T value_type;
		typedef T &reference;
		typedef const T &const_reference;
		typedef T *pointer;
		typedef const T *const_pointer;
		typedef ListIterator<T> iterator;
		typedef const ListIterator<const T> const_iterator;
		typedef ReverseIterator<iterator> reverse_iterator;
		typedef const ReverseIterator<const_iterator> const_reverse_iterator;
		typedef std::ptrdiff_t difference_type;
		typedef size_t size_type;

	private:
		typedef List<T> _Self;

		struct _node {
			value_type data;

			_node *prev;
			_node *next;

			_node(_node *prev_, _node *next_): prev(prev_), next(next_) {}; 
		};
		
		size_type _size;
		_node *_first;
		_node *_last;
		
	public:

		//construtors

		List(): _size(0) {
			_first = new _node(NULL, NULL); //Sentinel
			_last = _first;
		}

		List(size_type n, const value_type &val): _size(0) {
			_first = new _node(NULL, NULL); //Sentinel
			_last = _first;

			insert(begin(), n, val);
		}

		template <typename InputIterator>
		List(InputIterator first, InputIterator last): _size(0) {
			_first = new _node(NULL, NULL); //Sentinel
			_last = _first;

			insert(begin(), first, last);
		}

		List(const _Self &c): _size(0) {
			_first = new _node(NULL, NULL); //Sentinel
			_last = _first;

			insert(begin(), c.begin(), c.end());
		}

		//destructor

		~List() {
			erase(begin(), end());
			delete _last;
		}

		template <typename _T>
		friend class List;
		
		template <typename _T>
		friend class ListIterator;

		template <typename Iterator>
		friend class ReverseIterator;
		
		//operators and iterators

		_Self &operator=(const List &c) {
			clear();
			insert(begin(), c.begin(), c.end());
			return *this;
		}

		iterator begin() {
			return iterator(_first);
		}

		iterator end() {
			return iterator(_last);
		}

		const_iterator begin() const {
			typedef typename List<const T>::_node const_node;
			return const_iterator(reinterpret_cast<const_node *>(_first));
		}

		const_iterator end() const {
			typedef typename List<const T>::_node const_node;
			return const_iterator(reinterpret_cast<const_node *>(_last));
		}

		reverse_iterator rbegin() {
			return reverse_iterator(end());
		}

		reverse_iterator rend() {
			return reverse_iterator(begin());
		}

		const_reverse_iterator rbegin() const {
			return const_reverse_iterator(end());
		}

		const_reverse_iterator rend() const {
			return const_reverse_iterator(begin());
		}

		//capacity

		bool empty() const {
			return _size == 0;
		}

		size_type size() const {
			return _size;
		}

		size_type max_size() const {
			return std::numeric_limits<std::size_t>::max() / sizeof(value_type);
		}

		//element access

		reference front() {
			return _first->data;
		}

		const_reference front() const {
			return _first->data;
		}

		reference back() {
			return _last->prev->data;
		}

		const_reference back() const {
			return _last->prev->data;
		}

		//modifiers
		
		template<typename InputIterator>
		void assign(InputIterator first, InputIterator last) {
			clear();
			insert(begin(), first, last);
		}

		void assign(size_type n, const value_type &val) {
			clear();
			insert(begin(), n, val);
		}

		void push_front(const value_type &val) {
			insert(begin(), val);
		}

		void pop_front() {
			erase(begin());
		}

		void push_back(const value_type &val) {
			insert(end(), val);
		}

		void pop_back() {
			iterator it = end();
			it--;
			erase(it);
		}

		iterator insert(iterator position, const value_type &val) {
			_node *n = new _node(position._n->prev, position._n);
			n->data = val;

			if (n->prev)
				n->prev->next = n;
			else
				_first = n;

			n->next->prev = n;

			_size++;
			return iterator(n);
		}

		void insert(iterator position, size_type n, const value_type &val) {
			_node *leftNode = position._n->prev;
			_node *rightNode = position._n;

			_node *insert = leftNode;
			for (size_type i = 0; i < n; i++) {
				_node *n = new _node(insert, NULL);
				n->data = val;

				if (insert)
					insert->next = n;
				else
					_first = n;

				_size++;
				insert = n;
			}
			rightNode->prev = insert;
			if (insert)
				insert->next = rightNode;
		}

		template <typename InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last) {
			_node *leftNode = position._n->prev;
			_node *rightNode = position._n;
			
			_node *insert = leftNode;
			for (InputIterator it = first; it != last; it++) {
				_node *n = new _node(insert, NULL);
				n->data = *it;

				if (insert)
					insert->next = n;
				else
					_first = n;

				_size++;
				insert = n;
			}
			rightNode->prev = insert;
			if (insert)
				insert->next = rightNode;
		}

		iterator erase(iterator position) {
			if (position._n->prev)
				position._n->prev->next = position._n->next;
			else
				_first = position._n->next;
			if (position._n->next)
				position._n->next->prev = position._n->prev;

			iterator ret = position._n->next;

			_size--;
			delete position._n;
			return ret;
		}

		iterator erase(iterator first, iterator last) {
			iterator it = first;
			while(it != last)
				it = erase(it);

			return it;
		}

		void swap(List &x) {
			std::swap(_first, x._first);
			std::swap(_last, x._last);
			std::swap(_size, x._size);
		}

		void resize(size_type n, value_type val = value_type()) {
			if (n >= _size)
				insert(end(), n - _size, val);
			else {
				iterator it = begin();
				for (size_type i = 0; i < n; i++)
					it++;
				erase(it, end());
			}
		}

		void clear() {
			erase(begin(), end());
		}

		//operations

		void splice(iterator position, List &x) {
			splice(position, x, x.begin(), x.end());
		}

		void splice(iterator position, List &x, iterator i) {
			_node *leftNode = position._n->prev;
			_node *rightNode = position._n;

			_node *x_leftNode = i._n->prev;
			_node *x_rightNode = i._n->next;

			if (leftNode) {
				leftNode->next = i._n;
				i._n->prev = leftNode;
			}
			else {
				_first = i._n;
				i._n->prev = NULL;
			}
			i._n->next = rightNode;
			rightNode->prev = i._n;

			if (x_leftNode)
				x_leftNode->next = x_rightNode;
			else
				x._first = x_rightNode;
			x_rightNode->prev = x_leftNode;

			_size++;
			x._size--;
		}

		void splice(iterator position, List &x, iterator first, iterator last) {
			while (first != last) {
				iterator it = first;
				first++;
				splice(position, x, it);
			}
		}

		void remove(const value_type &val) {
			for (iterator it = begin(); it != end();) {
				if (*it == val)
					it = erase(it);
				else
					it++;
			}
		}

		template <typename Predicate>
		void remove_if(Predicate pred) {
			for (iterator it = begin(); it != end();) {
				if (pred(*it))
					it = erase(it);
				else
					it++;
			}
		}

		void unique() {
			unique(Equal<T>());
		}

		template <typename BinaryPredicate>
		void unique(BinaryPredicate binary_pred) {

			if (begin() == end())
				return ;
			
			iterator prev = begin();
			iterator it = prev;
			it++;
			while (it != end()) {
				if (binary_pred(*it, *prev))
					it = erase(it);
				else {
					prev = it;
					it++;
				}
			}
		}

		void merge(List &x) {
			merge(x, std::less<T>());
		}

		template <typename Compare>
		void merge(List &x, Compare comp) {
			iterator selfIt = begin();

			for (iterator it = x.begin(); it != x.end();) {
				while(selfIt != end() && comp(*selfIt, *it))
					selfIt++;
				
				iterator tmp = it;
				it++;

				if (selfIt._n->prev)
					selfIt._n->prev->next = tmp._n;
				else
					_first = tmp._n;
				
				tmp._n->prev = selfIt._n->prev;
				tmp._n->next = selfIt._n;
				selfIt._n->prev = tmp._n;
			}

			_size += x._size;
			x._size = 0;
			x._first = x._last;
			x._last->prev = NULL;
		}

		void sort() {
			sort(Less<T>());
		}

		template <typename Compare>
		void sort(Compare comp) {

			if (begin() == end())
				return ;

			for (size_type i = 0; i < _size; i++) {
				iterator cur = begin();
				iterator nxt = cur;
				nxt++;

				while (nxt != end()) {
					if (!comp(*cur, *nxt)) {
						_node *node_left = cur._n->prev;
						_node *node_right = nxt._n->next;

						cur._n->prev = nxt._n;
						nxt._n->next = cur._n;
						if (node_left)
							node_left->next = nxt._n;
						else
							_first = nxt._n;
						nxt._n->prev = node_left;
						node_right->prev = cur._n;
						cur._n->next = node_right;

						nxt = cur;
						nxt++;
					}
					else {
						cur = nxt;
						nxt++;
					}
				}
			}
		}

		void reverse() {
			size_t i = 1;

			iterator it = begin();
			iterator it2 = end();
			it2--;

			while (it != it2 && i < _size / 2) {

				iterator tmp = it;
				iterator tmp2 = it2;
				_node *prv = tmp2._n->prev;
				_node *nxt = tmp2._n->next;
				it++;
				it2--;

				if (tmp._n->prev)
					tmp._n->prev->next = tmp2._n;
				else
					_first = tmp2._n;
				tmp2._n->prev = tmp._n->prev;
				tmp2._n->next = tmp._n->next;
				tmp._n->next->prev = tmp2._n;

				tmp._n->next = nxt;
				tmp._n->prev = prv;
				nxt->prev = tmp._n;
				prv->next = tmp._n;

				i++;
			}
		}

	}; //List

	//non-member function overloads

	template <typename T>
	bool operator==(const List<T> &lhs, const List<T> &rhs) {
		if (lhs.size() != rhs.size())
			return false;
		return std::equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template <typename T>
	bool operator!= (const List<T> &lhs, const List<T> &rhs) {
		return !(lhs == rhs);
	}

	template <typename T>
	bool operator<(const List<T> &lhs, const List<T> &rhs) {
		return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <typename T>
	bool operator<=(const List<T> &lhs, const List<T> &rhs) {
		return !(rhs < lhs);
	}

	template <typename T>
	bool operator>(const List<T> &lhs, const List<T> &rhs) {
		return rhs < lhs;
	}

	template <typename T>
	bool operator>=(const List<T> &lhs, const List<T> &rhs) {
		return !(lhs < rhs);
	}

	template <typename T>
	void swap (List<T> &x, List<T> &y) {
		return x.swap(y);
	}

}; //namespace

#endif
