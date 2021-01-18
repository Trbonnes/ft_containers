/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:37:18 by trbonnes          #+#    #+#             */
/*   Updated: 2021/01/18 14:42:30 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_HPP
# define QUEUE_HPP

# include <utility>
# include <limits>
# include <sstream>
# include <memory>
# include "../utils.hpp"
# include "../List/List.hpp"
# include "../Vector/Vector.hpp"
# include "../Map/Map.hpp"
# include "../Stack/Stack.hpp"


namespace ft {

    template <typename T, typename Container = List<T> >
	class	Queue {
	public:
		typedef T value_type;
		typedef Container container_type;
		typedef size_t size_type;

	private:
		typedef Queue<T, Container> _Self;

        container_type _cntr;
		
	public:

		//construtors

		explicit Queue(const container_type &cntr = container_type()): _cntr(cntr) {
		}

        //functions

        bool empty() const {
            return _cntr.empty();
        }

        size_type size() const {
            return _cntr.size();
        }

        value_type &front() {
            return _cntr.front();
        }

        const value_type &front() const {
            return _cntr.front();
        }

        value_type &back() {
            return _cntr.back();
        }

        const value_type &back() const {
            return _cntr.back();
        }

        void push(const value_type &val) {
            _cntr.push_back(val);
        }

        void pop() {
            _cntr.pop_back();
        }

        template <typename _T, typename _Container>
		friend bool operator==(const Queue<_T, _Container> &lhs, const Queue<_T, _Container> &rhs);

		template <typename _T, typename _Container>
		friend bool operator<(const Queue<_T, _Container> &lhs, const Queue<_T, _Container> &rhs);

    }; //Queue

    template <typename T, typename Container>
	bool operator==(const Queue<T, Container> &lhs, const Queue<T, Container> &rhs) {
		return lhs._cntr == rhs._cntr;
	}

	template <typename T, typename Container>
	bool operator!=(const Queue<T, Container> &lhs, const Queue<T, Container> &rhs) {
		return !(lhs == rhs);
	}

	template <typename T, typename Container>
	bool operator<(const Queue<T, Container> &lhs, const Queue<T, Container> &rhs) {
		return lhs._cntr < rhs._cntr;
	}

	template <typename T, typename Container>
	bool operator<=(const Queue<T, Container> &lhs, const Queue<T, Container> &rhs) {
		return !(lhs > rhs);
	}

	template <typename T, typename Container>
	bool operator>(const Queue<T, Container> &lhs, const Queue<T, Container> &rhs) {
		return rhs < lhs;
	}

	template <typename T, typename Container>
	bool operator>=(const Queue<T, Container> &lhs, const Queue<T, Container> &rhs) {
		return !(lhs < rhs);
	}
    
}; //namespace

#endif