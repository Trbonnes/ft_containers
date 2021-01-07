/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 11:12:50 by trbonnes          #+#    #+#             */
/*   Updated: 2021/01/07 15:05:40 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

namespace ft {

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

		template <typename T>
		friend class List;

		template <typename T>
		friend bool operator==(const ListIterator<T> &lhs, ListIterator<T> &rhs);

		template <typename T>
		friend bool operator!=(const ListIterator<T> &lhs, ListIterator<T> &rhs);

		_Self &operator=(const _Self &c) {
			_n = c._n;
			return *this;
		}

		_Self &operator++() {
			_n = _n->next;
			return *this;
		}

		_Self &operator++(int) {
			_Self cpy = *this;
			++*this;
			return cpy;
		}

		_Self &operator--() {
			_n = _n->prev;
			return *this;
		}

		_Self &operator--(int) {
			_Self cpy = *this;
			--*this;
			return cpy;
		}

		_Self &operator*() {
			return _n->data;
		}

		_Self &operator->() {
			return &_n->data;
		}
	}; //ListIterator

	template <typename T>
	bool operator==(const ListIterator<T> &lhs, ListIterator<T> &rhs) {
		return lhs._n == rhs._n;
	}

	template <typename T>
	bool operator!=(const ListIterator<T> &lhs, ListIterator<T> &rhs) {
		return !(lhs._n == rhs._n);
	}

	template <typename T>
	class	ReverseListIterator {
	public:
		typedef T value_type;
		typedef T *pointer;
		typedef T &reference;
		typedef	std::ptrdiff_t difference_type;
		typedef std::bidirectional_iterator_tag iterator_category;
		
	private:
		typedef typename List<T>::_node _node;
		typedef ReverseListIterator<T> _Self;

		_node *_n;

	public:
		ReverseListIterator() {}
		ReverseListIterator(_node *node): _n(node) {}
		ReverseListIterator(const ReverseListIterator<T> &c): _n(c._n) {}
		~ReverseListIterator() {}

		template <typename T>
		friend class List;

		template <typename T>
		friend bool operator==(const ReverseListIterator<T> &lhs, ReverseListIterator<T> &rhs);

		template <typename T>
		friend bool operator!=(const ReverseListIterator<T> &lhs, ReverseListIterator<T> &rhs);

		_Self &operator=(const _Self &c) {
			_n = c._n;
			return *this;
		}

		_Self &operator++() {
			_n = _n->prev;
			return *this;
		}

		_Self &operator++(int) {
			_Self cpy = *this;
			--*this;
			return cpy;
		}

		_Self &operator--() {
			_n = _n->next;
			return *this;
		}

		_Self &operator--(int) {
			_Self cpy = *this;
			++*this;
			return cpy;
		}

		_Self &operator*() {
			return _n->data;
		}

		_Self &operator->() {
			return &_n->data;
		}
	}; //ReverseListIterator

	template <typename T>
	bool operator==(const ReverseListIterator<T> &lhs, ReverseListIterator<T> &rhs) {
		return lhs._n == rhs._n;
	}

	template <typename T>
	bool operator!=(const ReverseListIterator<T> &lhs, ReverseListIterator<T> &rhs) {
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
		typedef ReverseListIterator<T> reverse_iterator;
		typedef const ReverseListIterator<const T> const_reverse_iterator;
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

		List(size_type n, const value_type &val): _len(0) {
			_first = new _node(NULL, NULL); //Sentinel
			_last = _first;

			insert(begin(), n, val);
		}

		template <typename InputIterator>
		List(InputIterator first, InputIterator last) {
			_first = new _node(NULL, NULL); //Sentinel
			_last = _first;

			insert(first, last);
		}

		List(const List &c): _len(c._len) {
			_first = new _node(NULL, NULL); //Sentinel
			_last = _first;

			insert(begin(), c.begin(), c.end())
		}

		//destructor

		~List() {
			erase(begin(), end());
			delete _last;
		}

		template <typename T>
		friend class ListIterator<T>;

		template <typename T>
		friend class ReverseListIterator<T>;
		
		//operators and iterators

		_Self &operator=(const List &c) {
			return *this;
		}

		iterator begin() {
			return iterator(_first);
		}

		iterator end() {
			return iterator(_last);
		}

		reverse_iterator rbegin() {
			return reverse_iterator(_last);
		}

		reverse_iterator rend() {
			return reverse_iterator(_first);
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
		template<class InputIterator>
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
			
			_node *insert = leftNode
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
			delete position;
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

	}; //List

}; //namespace

#endif
