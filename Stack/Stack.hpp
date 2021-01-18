/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 12:17:17 by trbonnes          #+#    #+#             */
/*   Updated: 2021/01/18 14:29:38 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include <utility>
# include <limits>
# include <sstream>
# include <memory>
# include "../ReverseIterator.hpp"
# include "../utils.hpp"
# include "../List/List.hpp"
# include "../Vector/Vector.hpp"
# include "../Map/Map.hpp"
//# include "../Queue/Queue.hpp"

namespace ft {

    template <typename T, typename Container = Vector<T> >
	class	Stack {
	public:
		typedef T value_type;
		typedef Container container_type;
		typedef size_t size_type;

	private:
		typedef Stack<T, Container> _Self;

        container_type _cntr;
		
	public:

		//construtors

		explicit Stack(const container_type &cntr = container_type()): _cntr(cntr) {
		}

        //functions

        bool empty() const {
            return _cntr.empty();
        }

        size_type size() const {
            return _cntr.size();
        }

        value_type &top() {
            return _cntr.back();
        }

        const value_type &top() const {
            return _cntr.back();
        }

        void push(const value_type &val) {
            _cntr.push_back(val);
        }

        void pop() {
            _cntr.pop_back();
        }

        template <typename _T, typename _Container>
		friend bool operator==(const Stack<_T, _Container> &lhs, const Stack<_T, _Container> &rhs);

		template <typename _T, typename _Container>
		friend bool operator<(const Stack<_T, _Container> &lhs, const Stack<_T, _Container> &rhs);

    }; //stack

    template <typename T, typename Container>
	bool operator==(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs) {
		return lhs._cntr == rhs._cntr;
	}

	template <typename T, typename Container>
	bool operator!=(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs) {
		return !(lhs == rhs);
	}

	template <typename T, typename Container>
	bool operator<(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs) {
		return lhs._cntr < rhs._cntr;
	}

	template <typename T, typename Container>
	bool operator<=(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs) {
		return !(lhs > rhs);
	}

	template <typename T, typename Container>
	bool operator>(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs) {
		return rhs < lhs;
	}

	template <typename T, typename Container>
	bool operator>=(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs) {
		return !(lhs < rhs);
	}
    
}; //namespace

#endif