/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 11:12:50 by trbonnes          #+#    #+#             */
/*   Updated: 2020/10/22 11:43:45 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

namespace ft {

	template <typename T>
	class	ListIterator {
	private:
		;
	public:
		ListIterator::ListIterator() {

		}

		ListIterator::ListIterator(const ListIterator &c) {

		}

		ListIterator::ListIterator::~ListIterator() {

		}

		ListIterator &ListIterator::operator=(const ListIterator &c) {
			return *this;
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
		typedef List<T> _Self;

		struct _node {
			T data;

			_node *prev;
			_node *next;

			_node(_node *prev_, _node *next_): prev(prev_), next(next_) {}; 
		};
		

		size_type _size;
		_node *_first;
		_node *_last;
		
	public:
		List::List() {

		}

		List::List(const List &c) {

		}
		
		List::~List() {

		}

		List &List::operator=(const List &c) {
			return *this;
		}
	};

}

#endif
