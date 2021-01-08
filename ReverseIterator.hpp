/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReverseIterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 14:51:34 by trbonnes          #+#    #+#             */
/*   Updated: 2021/01/08 15:45:57 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSEITERATOR_HPP
# define REVERSEITERATOR_HPP

# include <cstddef>

namespace ft {

    template <typename Iterator>
	class	ReverseIterator {
	public:
		typedef Iterator iterator_type;
		typedef typename std::iterator_traits<Iterator>::iterator_category iterator_category;
		typedef typename std::iterator_traits<Iterator>::value_type value_type;
		typedef typename std::iterator_traits<Iterator>::difference_type difference_type;
		typedef typename std::iterator_traits<Iterator>::pointer pointer;
		typedef typename std::iterator_traits<Iterator>::reference reference;
		
	private:
		typedef ReverseIterator<Iterator> _Self;

        Iterator _base;


	public:
        ReverseIterator() {}
		ReverseIterator(Iterator base): _base(base) {}
		ReverseIterator(const ReverseIterator<Iterator> &c): _base(c._base) {}
		~ReverseIterator() {}

        iterator_type base() const {
            return _base;
        }

        _Self &operator=(const _Self &c) {
			_base = c._base;
			return *this;
		}

        reference operator*() const {
            iterator_type it(_base);
            it--;
            return *it;
        }

        pointer operator->() const {
			iterator_type it(_base);
			--it;
			return it.operator->();
		}

        _Self &operator++() {
            --_base;
            return *this;
        }

        _Self  operator++(int) {
            _Self rit(_base--);
            return rit;
        }

        _Self &operator+=(difference_type offset) {
			_base -= offset;
			return *this;
		}

        _Self &operator--() {
			++_base;
			return *this;
		}

		_Self operator--(int) {
			_Self rit(_base++);
			return rit;
		}

        _Self &operator-=(difference_type offset) {
			_base += offset;
			return *this;
		}
    };

    template <typename Iterator>
	bool operator==(const ReverseIterator<Iterator> &lhs, const ReverseIterator<Iterator> &rhs) {
		return lhs.base() == rhs.base();
	}

	template <typename Iterator>
	bool operator!=(const ReverseIterator<Iterator> &lhs, const ReverseIterator<Iterator> &rhs) {
		return lhs.base() != rhs.base();
	}

	template <typename Iterator>
	bool operator<(const ReverseIterator<Iterator> &lhs, const ReverseIterator<Iterator> &rhs) {
		return lhs.base() > rhs.base();
	}

	template <typename Iterator>
	bool operator>(const ReverseIterator<Iterator> &lhs, const ReverseIterator<Iterator> &rhs) {
		return lhs.base() < rhs.base();
	}

	template <typename Iterator>
	bool operator<=(const ReverseIterator<Iterator> &lhs, const ReverseIterator<Iterator> &rhs) {
		return lhs.base() >= rhs.base();
	}

	template <typename Iterator>
	bool operator>=(const ReverseIterator<Iterator> &lhs, const ReverseIterator<Iterator> &rhs) {
		return lhs.base() <= rhs.base();
	}

	template <typename Iterator>
	ReverseIterator<Iterator> operator+(const ReverseIterator<Iterator> &rit, size_t offset) {
		ReverseIterator<Iterator> r(rit.base() - offset);
		return r;
	}

	template <typename Iterator>
	ReverseIterator<Iterator> operator+(typename ReverseIterator<Iterator>::difference_type offset, const ReverseIterator<Iterator> &rit) {
		ReverseIterator<Iterator> r(rit.base() - offset);
		return r;
	}

	template <typename Iterator>
	ReverseIterator<Iterator> operator-(const ReverseIterator<Iterator> &rit, typename ReverseIterator<Iterator>::difference_type offset) {
		ReverseIterator<Iterator> r(rit.base() + offset);
		return r;
	}

	template <typename Iterator>
	ptrdiff_t operator-(const ReverseIterator<Iterator> &lhs, const ReverseIterator<Iterator> &rhs) {
		return rhs.base() - lhs.base();
	}
}

#endif