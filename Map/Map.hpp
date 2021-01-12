/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 09:12:03 by trbonnes          #+#    #+#             */
/*   Updated: 2021/01/12 13:56:17 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <utility>
# include <limits>
# include <sstream>
# include <memory>
# include "../ReverseIterator.hpp"
# include "../utils.hpp"

namespace ft {

	template <typename Key, typename T, typename Compare = Less<Key> >
	class Map;

    template <typename Key, typename T, typename Compare = Less<Key> >
	class	MapIterator {
	public:
        typedef Key key_type;
		typedef T mapped_type;
        typedef pair<const key_type, mapped_type> value_type;
        typedef Compare key_compare;
		typedef value_type *pointer;
		typedef value_type &reference;
		typedef	std::ptrdiff_t difference_type;
		typedef std::bidirectional_iterator_tag iterator_category;
		
	private:
		typedef typename Map<Key, T, Compare>::_node _node;
		typedef MapIterator<Key, T, Compare> _Self;

		_node *_n;

	public:
		MapIterator() {}
		MapIterator(_node *node): _n(node) {}
		MapIterator(const _Self &c): _n(c._n) {}
		~MapIterator() {}

		template <typename _Key, typename _T, typename _Compare = Less<_Key> >
		friend class Map;

		template <typename _Key, typename _T, typename _Compare = Less<_Key> >
		friend bool operator==(const MapIterator<_Key, _T, _Compare> &lhs, const MapIterator<_Key, _T, _Compare> &rhs);

		template <typename _Key, typename _T, typename _Compare = Less<_Key> >
		friend bool operator!=(const MapIterator<_Key, _T, _Compare> &lhs, const MapIterator<_Key, _T, _Compare> &rhs);

		_Self &operator=(const _Self &c) {
			_n = c._n;
			return *this;
		}

		_Self &operator++() {
            if (_n->right) {
                _n = _n->right;
                while (_n->left) {
                    _n = _n->left;
                }
            }
            else {
                _node *tmp;
                do {
                    tmp = _n;
                    _n = _n->parent;
                } while(_n && _n->right == tmp);
            }

			return *this;
		}

		_Self operator++(int) {
			_Self cpy = *this;
            operator++();
			return cpy;
		}

		_Self &operator--() {
            if (_n->left) {
                _n = _n->left;
                while (_n && _n->right) {
                    _n = _n->right;
                }
            }
            else {
                _node *tmp;
                do {
                    tmp = _n;
                    _n = _n->parent;
                } while (_n && _n->left == tmp);
            }

			return *this;
		}

		_Self operator--(int) {
			_Self cpy = *this;
            operator--();
			return cpy;
		}

		reference operator*() const {
			return _n->data;
		}

		pointer operator->() const {
			return &_n->data;
		}
	}; //MapIterator

	template <typename Key, typename T, typename Compare = Less<Key> >
	bool operator==(const MapIterator<Key, T, Compare> &lhs, const MapIterator<Key, T, Compare> &rhs) {
		return lhs._n == rhs._n;
	}

	template <typename Key, typename T, typename Compare = Less<Key> >
	bool operator!=(const MapIterator<Key, T, Compare> &lhs, const MapIterator<Key, T, Compare> &rhs) {
		return !(lhs._n == rhs._n);
	}
    
    template <typename Key, typename T, typename Compare = Less<Key> >
	class	Map {
	public:
        typedef Key key_type;
		typedef T mapped_type;
        typedef pair<const key_type, mapped_type> value_type;
        typedef Compare key_compare;
		typedef value_type &reference;
		typedef const value_type &const_reference;
		typedef value_type *pointer;
		typedef const value_type *const_pointer;
		typedef MapIterator<T> iterator;
		typedef const MapIterator<const T> const_iterator;
		typedef ReverseIterator<iterator> reverse_iterator;
		typedef const ReverseIterator<const_iterator> const_reverse_iterator;
		typedef std::ptrdiff_t difference_type;
		typedef size_t size_type;

	private:
		typedef Map<Key, T, Compare> _Self;

        struct _node {
			value_type data;

			_node *left; //<
			_node *right; //>

            _node *parent;

			_node(_node *left_, _node *right_, _node *parent_, value_type data_)
            : left(left_), right(right_), parent(parent_), data(data_) {}; 
		};

		size_type _size;
		_node *_root;
        _node *_sentinel;

        key_compare _cmp;
		
	public:

		//construtors

		Map(const key_compare &comp = key_compare()): _size(0) {
			_root = new _node(NULL, NULL, NULL, ); //Sentinel
			_sentinel = _root;
		}

		template <typename InputIterator>
		Map(InputIterator first, InputIterator last, const key_compare &comp = key_compare()): _size(0) {
			_root = new _node(NULL, NULL); //Sentinel
			_sentinel = _root;

			insert(begin(), first, last);
		}

		Map(const _Self &c): _size(0) {
			_root = new _node(NULL, NULL); //Sentinel
			_sentinel = _root;

			insert(begin(), c.begin(), c.end());

		//destructor

		~Map() {
			clear();
			delete _sentinel;
		}

		template <typename _Key, typename _T, typename _Compare = Less<_Key> >
		friend class Map;
		
		template <typename _Key, typename _T, typename _Compare = Less<_Key> >
		friend class MapIterator;

		template <typename Iterator>
		friend class ReverseIterator;
		
		//operators and iterators

		_Self &operator=(const Map &c) {
			clear();
			insert(begin(), c.begin(), c.end());
			return *this;
		}

		iterator begin() {
            _node *n = _root;

            while (_n && _n->left) {
                _n = _n->left;
            }
			return iterator(_n);
		}

		iterator end() {
			return iterator(_sentinel);
		}

		const_iterator begin() const {
            _node *n = _root;

            while (_n && _n->left) {
                _n = _n->left;
            }
			return const_iterator(_n);
		}

		const_iterator end() const {
			return const_iterator(_sentinel);
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

        mapped_type &operator[](const key_type& k) {
            return (*((this->insert(std::make_pair(k,mapped_type()))).first)).second;
        }

        //modifiers

        pair<iterator, bool> insert(const value_type &val) {
            _node *n = _root;
            _node *new;

            while (1) {
                if (!_cmp(n->data, val) && !_cmp(val, n->data)) {
                    return std::make_pair(iterator(n), false);
                }

                if (_cmp(n->data, val)) {
                    if (n->right) {
                        n = n->right;
                    }
                    else {
                        n->right = new _node(NULL, NULL, n, val);
                        n = n->right;
                        break ;
                    }
                }
                
                else if (_cmp(val, n->data)) {
                    if (n->left) {
                        n = n->left;
                    }
                    else {
                        n->left = new _node(NULL, NULL, n, val);
                        n = n->left;
                        break ;
                    }
                }
            }
            return std::make_pair(iterator(n, true));
            
        }

        iterator insert(iterator position, const value_type &val) {
            (void)position;
            iterator = insert(val).first;
            
            return iterator;
        }

        template <typename InputIterator>
        void insert(InputIterator first, InputIterator last) {
            for (; first != last; first++)
                insert(*first);
        }
        
    }; //Map

} //namespace

#endif