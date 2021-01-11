/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 13:37:35 by trbonnes          #+#    #+#             */
/*   Updated: 2021/01/11 16:58:32 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <utility>
# include <limits>
# include <sstream>
# include <memory>
# include "../ReverseIterator.hpp"
# include "../utils.hpp"

namespace ft {

	template <typename T>
	class Vector;

    template <typename T>
	class	VectorIterator {
	public:
		typedef T value_type;
		typedef T *pointer;
		typedef T &reference;
        typedef size_t size_type;
		typedef	std::ptrdiff_t difference_type;
		typedef std::random_access_iterator_tag iterator_category;
		
	private:
		typedef VectorIterator<T> _Self;

        pointer _e;
	public:
		VectorIterator(): _e(NULL) {}
		VectorIterator(pointer elem): _e(elem) {}
		VectorIterator(const VectorIterator<T> &c): _e(c._e) {}
		~VectorIterator() {}

		template <typename _T>
		friend class Vector;

		template <typename _T>
		friend bool operator==(const VectorIterator<_T> &lhs, const VectorIterator<_T> &rhs);

		template <typename _T>
		friend bool operator!=(const VectorIterator<_T> &lhs, const VectorIterator<_T> &rhs);

		_Self &operator=(const _Self &c) {
			_e = c._e;
			return *this;
		}

		_Self &operator++() {
			++_e;
			return *this;
		}

		_Self operator++(int) {
			_Self cpy = *this;
			++_e;
			return cpy;
		}

		_Self &operator--() {
            --_e;
			return *this;
		}

		_Self operator--(int) {
			_Self cpy = *this;
			--_e;
			return cpy;
		}

        _Self &operator+=(size_type offset) {
            _e += offset;
            return *this;
        }

        _Self &operator-=(size_type offset) {
            _e -= offset;
            return *this;
        }

		reference operator*() const {
			return _e;
		}

		pointer operator->() const {
			return &_e;
		}

        reference operator[](size_type n) {
            return *(*this + n);
        }
        
	}; //VectorIterator

    template <typename T>
	bool operator==(const VectorIterator<T> &lhs, const VectorIterator<T> &rhs) {
		return lhs._e == rhs._e;
	}

	template <typename T>
	bool operator!=(const VectorIterator<T> &lhs, const VectorIterator<T> &rhs) {
		return !(lhs == rhs);
	}

	template <typename T>
	bool operator<(const VectorIterator<T> &lhs, const VectorIterator<T> &rhs) {
		return lhs._e < rhs._e;
	}

	template <typename T>
	bool operator>(const VectorIterator<T> &lhs, const VectorIterator<T> &rhs) {
		return rhs < lhs;
	}

	template <typename T>
	bool operator<=(const VectorIterator<T> &lhs, const VectorIterator<T> &rhs) {
		return !(lhs > rhs);
	}

	template <typename T>
	bool operator>=(const VectorIterator<T> &lhs, const VectorIterator<T> &rhs) {
		return !(lhs < rhs);
	}

	template <typename T>
	VectorIterator<T> operator+(const VectorIterator<T> &it, size_t offset) {
		VectorIterator<T> it2 = it;
		return it2 += offset;
	}

	template <typename T>
	VectorIterator<T> operator+(typename VectorIterator<T>::difference_type offset, const VectorIterator<T> &it) {
		return it + offset;
	}

	template <typename T>
	VectorIterator<T> operator-(const VectorIterator<T> &it, typename VectorIterator<T>::difference_type offset) {
		VectorIterator<T> it2 = it;
		return it2 -= offset;
	}

	template <typename T>
	ptrdiff_t operator-(const VectorIterator<T> &lhs, const VectorIterator<T> &rhs) {
		return lhs._e - rhs._e;
	}

    template <typename T>
	class	Vector {
	public:
		typedef T value_type;
		typedef T &reference;
		typedef const T &const_reference;
		typedef T *pointer;
		typedef const T *const_pointer;
		typedef VectorIterator<T> iterator;
		typedef const VectorIterator<const T> const_iterator;
		typedef ReverseIterator<iterator> reverse_iterator;
		typedef const ReverseIterator<const_iterator> const_reverse_iterator;
		typedef std::ptrdiff_t difference_type;
		typedef size_t size_type;

	private:
		typedef Vector<T> _Self;

		size_type _size;
        size_type _cap;

        pointer _arr;
		
	public:

		//construtors

		Vector(): _size(0), _cap(0), _arr(NULL) {
		}

		Vector(size_type n, const value_type &val = value_type()): _size(0), _cap(0), _arr(NULL) {
			insert(begin(), n, val);
		}

		template <typename InputIterator>
		Vector(InputIterator first, InputIterator last): _size(0), _cap(0), _arr(NULL) {
			insert(begin(), first, last);
		}

		Vector(const _Self &c): _size(0), _cap(0), _arr(NULL) {
			insert(begin(), c.begin(), c.end());
		}

		//destructor

		~Vector() {
            std::allocator<T> alloc;
            for (size_type i = 0; i < _size; i++) {
                alloc.destroy(&_arr[i]);
            }
            alloc.deallocate(_arr, _cap);
		}

		template <typename _T>
		friend class Vector;
		
		template <typename _T>
		friend class VectorIterator;

		template <typename Iterator>
		friend class ReverseIterator;
		
		//operators and iterators

		_Self &operator=(const Vector &c) {
			clear();
			insert(begin(), c.begin(), c.end());
			return *this;
		}

		iterator begin() {
			return _arr;
		}

		iterator end() {
			return _arr + _size;
		}

		const_iterator begin() const {
			return _arr;
		}

		const_iterator end() const {
			return _arr;
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

        size_type size() const {
            return _size;
        }

		size_type max_size() const {
			return std::numeric_limits<std::size_t>::max() / sizeof(value_type);
		}

        void resize(size_type n, value_type val = value_type()) {
			if (n >= _size)
				insert(end(), n - _size, val);
			else
				erase(begin() + n, end());
		}

        size_type capacity() const {
            return _cap;
        }

        bool empty() const {
			return _size == 0;
		}

        void reserve(size_type n) {
            if (_cap < n) {
                std::allocator<T> alloc;
                T *realloc = alloc.allocate(n);
                for (size_type i = 0; i < _size; i++) {
                    alloc.construct(&realloc[i], _arr[i]);
                    alloc.destroy(&_arr[i]);
                }

                alloc.deallocate(_arr, _cap);
                _arr = realloc;
                _cap = n;
            }
        }

        //element access

        reference operator[](size_type n) {
            return _arr[n];
        }

        const_reference operator[](size_type n) const {
            return _arr[n];
        }

        reference at(size_type n) {
            if (n >= _size) {
                std::stringstream ss;

                ss << "index " << n << " out of bound (size() is " << size() << ");";
                throw std::out_of_range(ss.str()); 
            }
            return _arr[n];
        }

        const_reference at(size_type n) const {
            if (n >= _size) {
                std::stringstream ss;

                ss << "index " << n << " out of bound (size() is " << size() << ");";
                throw std::out_of_range(ss.str()); 
            }
            return _arr[n];
        }

        reference front() {
            return _arr[0];
        }

        const_reference front() const {
            return _arr[0];
        }

        reference back() {
            return _arr[_size - 1];
        }

        const_reference back() const {
            return _arr[_size - 1];
        }

        //modifiers

        template <typename InputIterator>
        void assign(InputIterator first, InputIterator last) {
			clear();
			insert(begin(), first, last);
        }

        void assign(size_type n, const value_type &val) {
			clear();
			insert(begin(), n, val);
        }

        void push_back(const value_type &val) {
			insert(end(), val);
        }

        void pop_back() {
			erase(end() - 1);
        }

        iterator insert(iterator position, const value_type &val) {
            insert(position, 1, val);
            return position;
		}

		void insert(iterator position, size_type n, const value_type &val) {
            if (!n)
                return ;

            std::allocator<T> alloc;

            size_type index = position._e - _arr;
            reserve(_size + n);
            for (size_type i = _size - 1; i >= index; i--) {
                alloc.construct(&_arr[i + n], _arr[i]);
                alloc.destroy(&_arr[i]);
            }

            for (size_type i = index; i < index + n; i++) {
                alloc.construct(&_arr[i], val);
            }

            _size += n;
		}

		template <typename InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last) {
            if (first == last)
                return ;
            
            std::allocator<T> alloc;

            size_type index = position._e - _arr;
            size_type n = last - first;
            reserve(_size + n);
            for (size_type i = _size - 1; i >= index; i--) {
                alloc.construct(&_arr[i + n], _arr[i]);
                alloc.destroy(&_arr[i]);
            }

            for (InputIterator it = first; it != last; it++) {
                alloc.construct(&_arr[index++], *it);
            }

            _size += n;
		}

		iterator erase(iterator position) {
            return erase(position, position + 1);
		}

		iterator erase(iterator first, iterator last) {
            if (first == last)
                return ;
            
            std::allocator<T> alloc;

            size_type index = first._e - _arr;
            size_type n = last - first;
            for (size_type i = index; i < index + n; i++) {
                alloc.destroy(&_arr[i]);
            }

            for (size_type i = index + n; i < _size; i++) {
                alloc.construct(&_arr[i - n], _arr[i]);
                alloc.destroy(&_arr[i]);
            }

            _size -= n;
            return first;
		}

        void swap(Vector &x) {
			std::swap(_arr, x._arr);
			std::swap(_size, x._size);
			std::swap(_cap, x._cap);

        }

        void clear() {
            erase(begin(), end());
        }

    }; //Vector

	//non-member function overloads

	template <typename T>
	bool operator==(const Vector<T> &lhs, const Vector<T> &rhs) {
		if (lhs.size() != rhs.size())
			return false;
		return std::equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template <typename T>
	bool operator!= (const Vector<T> &lhs, const Vector<T> &rhs) {
		return !(lhs == rhs);
	}

	template <typename T>
	bool operator<(const Vector<T> &lhs, const Vector<T> &rhs) {
		return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <typename T>
	bool operator<=(const Vector<T> &lhs, const Vector<T> &rhs) {
		return !(rhs < lhs);
	}

	template <typename T>
	bool operator>(const Vector<T> &lhs, const Vector<T> &rhs) {
		return rhs < lhs;
	}

	template <typename T>
	bool operator>=(const Vector<T> &lhs, const Vector<T> &rhs) {
		return !(lhs < rhs);
	}

	template <typename T>
	void swap (Vector<T> &x, Vector<T> &y) {
		return x.swap(y);
	}
    
} //namespace

#endif
