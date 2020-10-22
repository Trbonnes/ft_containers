/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 11:12:50 by trbonnes          #+#    #+#             */
/*   Updated: 2020/10/22 12:27:22 by trbonnes         ###   ########.fr       */
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

		_node *_n;

	public:
		ListIterator() {}
		ListIterator(_node *node): _n(node) {}
		ListIterator(const ListIterator &c): _n(c._n) {}
		~ListIterator() {}

		_Self &operator=(const ListIterator &c) {
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
};

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
		typedef ListIterator<T> reverse_iterator;
		typedef const ListIterator<const T> const_reverse_iterator;
		typedef std::ptrdiff_t difference_type;
		typedef size_t size_type;

	private:
		typedef ListIterator<T> _Self;
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
		List(): _size(0), _first(new _node(NULL, NULL), _last(_first)) {}
		List(size_type n, const value_type &val) {}
		template <typename InputIterator>
		List(InputIterator first, InputIterator last) {}
		List(const List &c): _len(c._len) {}
		~List() {
			delete _last;
		}

		_Self &operator=(const List &c) {
			return *this;
		}
	};

}

#endif
