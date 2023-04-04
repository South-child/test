#pragma once
#include <vector>
#include <string>

template<class K>
struct Hash
{
	size_t operator()(const K& key)
	{
		return key;
	}
};

// 特化
template<>
struct Hash < string >
{
	size_t operator()(const string& s)
	{
		// BKDR
		size_t value = 0;
		for (auto ch : s)
		{
			value *= 31;
			value += ch;
		}
		return value;
	}
};


namespace CloseHash
{
	enum Status
	{
		EXIST,
		EMPTY,
		DELETE
	};

	template<class K, class V>
	struct HashData
	{
		pair<K, V> _kv;
		Status _status = EMPTY;
	};

	//struct HashStr
	//{
	//	size_t operator()(const string& s)
	//	{
	//		// BKDR
	//		size_t value = 0;
	//		for (auto ch : s)
	//		{
	//			value *= 31;
	//			value += ch;
	//		}
	//		return value;
	//	}
	//};

	template<class K, class V, class HashFunc = Hash<K>>
	class HashTable
	{
	public:
		bool Erase(const K& key)
		{
			HashData<K, V>* ret = Find(key);
			if (ret == nullptr)
			{
				return false;
			}
			else
			{
				--_n;
				ret->_status = DELETE;
				return true;
			}
		}

		HashData<K, V>* Find(const K& key)
		{
			if (_tables.size() == 0)
			{
				return nullptr;
			}

			HashFunc hf;
			size_t start = hf(key) % _tables.size();
			size_t i = 0;
			size_t index = start;
			// 线性探测 or 二次探测
			while (_tables[index]._status != EMPTY)
			{
				if (_tables[index]._kv.first == key && _tables[index]._status == EXIST)
				{
					return &_tables[index];
				}

				++i;
				//index = start + i*i;
				index = start + i;

				index %= _tables.size();
			}

			return nullptr;
		}

		bool Insert(const pair<K, V>& kv)
		{
			HashData<K, V>* ret = Find(kv.first);
			if (ret)
			{
				return false;
			}

			// 负载因子到0.7，就扩容
			// 负载因子越小，冲突概率越低，效率越高，空间浪费越多
			// 负载因子越大，冲突概率越高，效率越低，空间浪费越少
			if (_tables.size() == 0 || _n * 10 / _tables.size() >= 7)
			{
				// 扩容
				size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				//vector<HashData<K, V>> newTables;
				//newTables.resize(newSize);
				//// 遍历原表，把原表中的数据，重新按newSize映射到新表
				//for (size_t i = 0; i < _tables.size(); ++i)
				//{
				//	// 
				//}
				//_tables.swap(newTables);
				HashTable<K, V, HashFunc> newHT;
				newHT._tables.resize(newSize);
				for (size_t i = 0; i < _tables.size(); ++i)
				{
					if (_tables[i]._status == EXIST)
					{
						newHT.Insert(_tables[i]._kv);
					}
				}

				_tables.swap(newHT._tables);
			}

			HashFunc hf;
			size_t start = hf(kv.first) % _tables.size();
			size_t i = 0;
			size_t index = start;
			// 线性探测 or 二次探测
			while (_tables[index]._status == EXIST)
			{
				++i;
				//index = start + i*i;
				index = start + i;

				index %= _tables.size();
			}

			_tables[index]._kv = kv;
			_tables[index]._status = EXIST;
			++_n;

			return true;
		}

	private:
		vector<HashData<K, V>> _tables;
		size_t _n = 0;	// 有效数据个数
	};

	void TestHashTable1()
	{
		//HashTable<int, int, Hash<int>> ht;
		HashTable<int, int> ht;

		int a[] = { 2, 12, 22, 32, 42, 52, 62 };
		for (auto e : a)
		{
			ht.Insert(make_pair(e, e));
		}

		ht.Insert(make_pair(72, 72));
		ht.Insert(make_pair(32, 32));
		ht.Insert(make_pair(-1, -1));
		ht.Insert(make_pair(-999, -999));

		Hash<int> hs;
		cout << hs(9) << endl;
		cout << hs(-9) << endl;

		cout << ht.Find(12) << endl;
		ht.Erase(12);
		cout << ht.Find(12) << endl;
	}

	struct Date
	{


	};

	struct HashDate
	{
		size_t operator()(const Date& d)
		{
			//...
		}
	};

	void TestHashTable2()
	{
		/*HashStr hs;
		cout << hs("sort")<<endl;
		cout << hs("insert") << endl;
		cout << hs("eat") << endl;
		cout << hs("ate") << endl;
		cout << hs("abcd") << endl;
		cout << hs("aadd") << endl;*/

		HashTable<string, string> ht;
		ht.Insert(make_pair("sort", "排序"));
		ht.Insert(make_pair("string", "字符串"));

		// 当key是一个定义类型时，需要配置一个仿函数，将key转成整形
		HashTable<Date, string, HashDate> htds;
	}
}

namespace LinkHash
{
	template<class T>
	struct HashNode
	{
		T _data;
		HashNode<T>* _next;

		HashNode(const T& data)
			:_data(data)
			, _next(nullptr)
		{}
	};

	template<class K, class T, class KeyOfT, class HashFunc>
	class HashTable;

	template<class K, class T, class Ref, class Ptr, class KeyOfT, class HashFunc>
	struct __HTIterator
	{
		typedef HashNode<T> Node;
		typedef __HTIterator<K, T, Ref, Ptr, KeyOfT, HashFunc> Self;

		Node* _node;
		HashTable<K, T, KeyOfT, HashFunc>* _pht;

		__HTIterator(Node* node, HashTable<K, T, KeyOfT, HashFunc>* pht)
			:_node(node)
			, _pht(pht)
		{}

		Ref operator*()
		{
			return _node->_data;
		}

		Ptr operator->()
		{
			return &_node->_data;
		}

		Self& operator++()
		{
			if (_node->_next)
			{
				_node = _node->_next;
			}
			else
			{
				KeyOfT kot;
				HashFunc hf;
				size_t index = hf(kot(_node->_data)) % _pht->_tables.size();
				++index;
				// 找下一个不为空的桶
				while (index < _pht->_tables.size())
				{
					if (_pht->_tables[index])
					{
						break;
					}
					else
					{
						++index;
					}
				}

				// 表走完了，都没有找到下一个桶
				if (index == _pht->_tables.size())
				{
					_node = nullptr;
				}
				else
				{
					_node = _pht->_tables[index];
				}
			}

			return *this;
		}

		bool operator!=(const Self& s) const
		{
			return _node != s._node;
		}

		bool operator==(const Self& s) const
		{
			return _node == s._node;
		}
	};

	template<class K, class T, class KeyOfT, class HashFunc>
	class HashTable
	{
		typedef HashNode<T> Node;

		template<class K, class T, class Ref, class Ptr, class KeyOfT, class HashFunc>
		friend struct __HTIterator;
	public:
		typedef __HTIterator<K, T, T&, T*, KeyOfT, HashFunc> iterator;

		iterator begin()
		{
			for (size_t i = 0; i < _tables.size(); ++i)
			{
				if (_tables[i])
				{
					return iterator(_tables[i], this);
				}
			}

			return end();
		}

		iterator end()
		{
			return iterator(nullptr, this);
		}

		bool Erase(const K& key)
		{
			if (_tables.empty())
			{
				return false;
			}

			HashFunc hf;
			size_t index = hf(key) % _tables.size();
			Node* prev = nullptr;
			Node* cur = _tables[index];
			KeyOfT kot;
			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					if (prev == nullptr) // 头删
					{
						_tables[index] = cur->_next;
					}
					else // 中间删除
					{
						prev->_next = cur->_next;
					}

					--_n;

					delete cur;

					return true;
				}
				else
				{
					prev = cur;
					cur = cur->_next;
				}
			}

			return false;
		}

		Node* Find(const K& key)
		{
			if (_tables.empty())
			{
				return nullptr;
			}

			HashFunc hf;
			size_t index = hf(key) % _tables.size();
			Node* cur = _tables[index];
			KeyOfT kot;
			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					return cur;
				}
				else
				{
					cur = cur->_next;
				}
			}

			return nullptr;
		}

		bool Insert(const T& data)
		{
			KeyOfT kot;
			Node* ret = Find(kot(data));
			if (ret)
				return false;

			HashFunc hf;
			// 负载因子 == 1时扩容
			if (_n == _tables.size())
			{
				size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				vector<Node*> newTables;
				newTables.resize(newSize);
				for (size_t i = 0; i < _tables.size(); ++i)
				{
					Node* cur = _tables[i];
					while (cur)
					{
						Node* next = cur->_next;

						size_t index = hf(kot(cur->_data)) % newTables.size();
						// 头插
						cur->_next = newTables[index];
						newTables[index] = cur;

						cur = next;
					}

					_tables[i] = nullptr;
				}

				_tables.swap(newTables);
			}


			size_t index = hf(kot(data)) % _tables.size();
			Node* newnode = new Node(data);
			// 头插
			newnode->_next = _tables[index];
			_tables[index] = newnode;

			++_n;
			return true;
		}

	private:
		/*struct Data
		{
			forward_list<T> _list;
			set<T> _rbtree;
			size_t _len;
		};
		vector<Data> _tables;*/
		vector<Node*> _tables;

		size_t _n = 0;  // 有效数据的个数
	};

	void TestHashTable()
	{
		/*int a[] = { 4, 24, 14,7,37,27,57,67,34,14,54};
		HashTable<int, int> ht;
		for (auto e : a)
		{
		ht.Insert(make_pair(e, e));
		}

		ht.Insert(make_pair(84, 84));*/
	}
}