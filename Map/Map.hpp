/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 09:12:03 by trbonnes          #+#    #+#             */
/*   Updated: 2021/01/18 12:02:40 by trbonnes         ###   ########.fr       */
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
        typedef std::pair<const key_type, mapped_type> value_type;
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

		template <typename _Key, typename _T, typename _Compare>
		friend class Map;

		template <typename _Key, typename _T, typename _Compare>
		friend bool operator==(const MapIterator<_Key, _T, _Compare> &lhs, const MapIterator<_Key, _T, _Compare> &rhs);

		template <typename _Key, typename _T, typename _Compare>
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

	template <typename Key, typename T, typename Compare>
	bool operator==(const MapIterator<Key, T, Compare> &lhs, const MapIterator<Key, T, Compare> &rhs) {
		return lhs._n == rhs._n;
	}

	template <typename Key, typename T, typename Compare>
	bool operator!=(const MapIterator<Key, T, Compare> &lhs, const MapIterator<Key, T, Compare> &rhs) {
		return !(lhs._n == rhs._n);
	}
    
    template <typename Key, typename T, typename Compare>
	class	Map {
	public:
        typedef Key key_type;
		typedef T mapped_type;
        typedef std::pair<const key_type, mapped_type> value_type;
        typedef Compare key_compare;
		typedef value_type &reference;
		typedef const value_type &const_reference;
		typedef value_type *pointer;
		typedef const value_type *const_pointer;
		typedef MapIterator<Key, T, Compare> iterator;
		typedef const MapIterator<const Key, const T, Compare> const_iterator;
		typedef ReverseIterator<iterator> reverse_iterator;
		typedef const ReverseIterator<const_iterator> const_reverse_iterator;
		typedef std::ptrdiff_t difference_type;
		typedef size_t size_type;

		class value_compare {
		private:
			key_compare _cmp;

		public:
			typedef bool result_type;
			typedef value_type first_argument_type;
			typedef value_type second_argument_type;
			
			template <typename _Key, typename _T, typename _Compare>
			friend class Map;

			value_compare(key_compare c): _cmp(c) {}

			value_compare(const value_compare &val): _cmp(val._cmp) {}

			~value_compare() {}

			value_compare &operator=(const value_compare &val) {
				_cmp = val._cmp;
				return *this;
			}

			bool operator()(value_type &x, value_type &y) const {
				return _cmp(x.first, y.first);
			}

		};

	private:
		typedef Map<Key, T, Compare> _Self;

        struct _node {
			value_type data;

			_node *left; //<
			_node *right; //>

            _node *parent;

			_node(_node *left_, _node *right_, _node *parent_, value_type data_)
            : data(data_), left(left_), right(right_), parent(parent_) {}; 
		};

		size_type _size;
		_node *_root;
        _node *_sentinel;

        key_compare _cmp;
		
	public:

		//construtors

		Map(const key_compare &comp = key_compare()): _size(0), _cmp(comp) {
			_root = new _node(NULL, NULL, NULL, value_type()); //Sentinel
			_sentinel = _root;
		}

		template <typename InputIterator>
		Map(InputIterator first, InputIterator last, const key_compare &comp = key_compare()): _size(0), _cmp(comp) {
			_root = new _node(NULL, NULL, NULL, value_type()); //Sentinel
			_sentinel = _root;

			insert(begin(), first, last);
		}

		Map(const _Self &c): _size(0), _cmp(c._cmp) {
			_root = new _node(NULL, NULL, NULL, value_type()); //Sentinel
			_sentinel = _root;

			insert(begin(), c.begin(), c.end());
		}

		//destructor

		~Map() {
			clear();
			delete _sentinel;
		}

		template <typename _Key, typename _T, typename _Compare>
		friend class Map;
		
		template <typename _Key, typename _T, typename _Compare>
		friend class MapIterator;

		template <typename Iterator>
		friend class ReverseIterator;
		
		//operators and iterators

		_Self &operator=(const Map &c) {
			clear();
			_size = 0;
			_cmp = c._cmp;
			insert(begin(), c.begin(), c.end());
			return *this;
		}

		iterator begin() {
            _node *n = _root;

            while (n && n->left) {
                n = n->left;
            }
			return iterator(n);
		}

		iterator end() {
			return iterator(_sentinel);
		}

		const_iterator begin() const {
            _node *n = _root;

            while (n && n->left) {
                n = n->left;
            }
			return const_iterator(n);
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

        std::pair<iterator, bool> insert(const value_type &val) {
            _node *n = _root;

            while (1) {
				if (n == _sentinel) {
					_node *parent = _sentinel->parent;
					
					if (parent) {
						parent->right = new _node(NULL, _sentinel, parent, val);
						n = parent->right;
					}
					else {
						_root = new _node(NULL, _sentinel, parent, val);
						n = _root;
					}
					_sentinel->parent = n;
					break ;
				}

                if (!_cmp(n->data.first, val.first) && !_cmp(val.first, n->data.first)) {
                    return std::make_pair(iterator(n), false);
                }

                if (_cmp(n->data.first, val.first)) {
                    if (n->right) {
                        n = n->right;
                    }
                    else {
                        n->right = new _node(NULL, NULL, n, val);
                        n = n->right;
                        break ;
                    }
                }
                
                else if (_cmp(val.first, n->data.first)) {
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

			_size++;
            return std::make_pair(iterator(n), true);
            
        }

        iterator insert(iterator position, const value_type &val) {
            (void)position;
            iterator it = insert(val).first;
            
            return it;
        }

        template <typename InputIterator>
        void insert(InputIterator first, InputIterator last) {
            for (; first != last; first++)
                insert(*first);
        }

		void erase(iterator position) {
			_node *n = position._n;


			if (n->parent) {
				if (n->right) {
					if (n == n->parent->right)
						n->parent->right = n->right;
					else
						n->parent->left = n->right;
					n->right->parent = n->parent;

					if (n->left) {
						_node *tmp = n->right;
						while (tmp->left)
							tmp = tmp->left;
						tmp->left = n->left;
						n->left->parent = tmp;
					}
				}
				else if (n->left) {
					if (n == n->parent->right)
						n->parent->right = n->left;
					else
						n->parent->left = n->left;
					n->left->parent = n->parent;
				}
				else {
					if (n == n->parent->right)
						n->parent->right = NULL;
					else
						n->parent->left = NULL;
				}
			}
			else {
				if (n->right) {
					_root = n->right;
					n->right->parent = NULL;

					if (n->left) {
						_node *tmp = n->right;
						while (tmp->left)
							tmp = tmp->left;
						tmp->left = n->left;
						n->left->parent = tmp;
					}
				}
				else if (n->left) {
					_root = n->left;
					n->left->parent = NULL;
				}
				else 
					_root = _sentinel;
			}
			_size--;
			delete n;
		}

		size_type erase(const key_type &k) {
			iterator it = begin();

			for(; (*it).first != k; it++) {}
			if (it != end()) {
				erase(it);
				return 1;
			}
			return 0;
		}

		void erase(iterator first, iterator last) {
			for (; first != last;) {
				iterator it = first;
				first++;
				erase(it);
			}
		}

		void swap(Map &x) {
			std::swap(_root, x._root);
			std::swap(_sentinel, x._sentinel);
			std::swap(_size, x._size);
		}

		void clear() {
			erase(begin(), end());
			_sentinel->right = NULL;
			_sentinel->left = NULL;
			_sentinel->parent = NULL;
			_root = _sentinel;
			_size = 0;
		}

		//observers

		key_compare key_comp() const {
			return _cmp;
		}

		value_compare value_comp() const {
			value_compare comp(_cmp);
			return comp;
		}

		//operations

		iterator find(const key_type &k) {
			_node *n = _root;

			while (n && n != _sentinel) {
				bool test = _cmp(n->data.first, k);
				if (!test && !_cmp(k, n->data.first)) {
					return iterator(n);
				}
				if (!test)
					n = n->left;
				else
					n = n->right;
			}
			return end();
		}

		const_iterator find(const key_type &k) const {
			_node *n = _root;

			while (n && n != _sentinel) {
				bool test = _cmp(n->data.first, k);
				if (!test && !_cmp(k, n->data.first)) {
					return const_iterator(n);
				}
				if (!test)
					n = n->left;
				else
					n = n->right;
			}
			return end();
		}

		size_type count(const key_type &k) const {
			_node *n = _root;

			while (n && n != _sentinel) {
				bool test = _cmp(n->data.first, k);
				if (!test && !_cmp(k, n->data.first)) {
					return 1;
				}
				if (!test)
					n = n->left;
				else
					n = n->right;
			}
			return 0;
		}

		iterator lower_bound(const key_type &k) {
			for (iterator it = begin(); it != end(); it++) {
				if (!_cmp((*it).first, k))
					return it;
			}
			return end();
		}

		const_iterator lower_bound(const key_type &k) const {
			for (const_iterator it = begin(); it != end(); it++) {
				if (!_cmp((*it).first, k))
					return it;
			}
			return end();
		}

		iterator upper_bound(const key_type &k) {
			for (iterator it = begin(); it != end(); it++) {
				if (_cmp(k, (*it).first))
					return it;
			}
			return end();
		}

		const_iterator upper_bound(const key_type &k) const {
			for (const_iterator it = begin(); it != end(); it++) {
				if (_cmp(k, (*it).first))
					return it;
			}
			return end();
		}

		std::pair<iterator, iterator> equal_range(const key_type &k) {
			return std::make_pair(lower_bound(k), upper_bound(k));
		}

		std::pair<const_iterator, const_iterator> equal_range(const key_type &k) const {
			return std::make_pair(lower_bound(k), upper_bound(k));
		}
        
    }; //Map

}; //namespace

#endif