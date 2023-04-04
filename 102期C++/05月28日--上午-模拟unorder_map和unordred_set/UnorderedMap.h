#pragma once
#include "HashTable.h"

namespace bit
{
	template<class K, class V, class hash = Hash<K>>
	class unordered_map
	{
		struct MapKeyOfT
		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};
	public:
		typedef typename LinkHash::HashTable<K, pair<K, V>, MapKeyOfT, hash>::iterator iterator;
		iterator begin()
		{
			return _ht.begin();
		}

		iterator end()
		{
			return _ht.end();
		}


		bool insert(const pair<K, V>& kv)
		{
			return _ht.Insert(kv);
		}

	private:
		LinkHash::HashTable<K, pair<K, V>, MapKeyOfT, hash> _ht;
	};

	void test_unordered_map()
	{
		unordered_map<string, string> dict;
		dict.insert(make_pair("sort", "ÅÅĞò"));
		dict.insert(make_pair("string", "×Ö·û´®"));
		dict.insert(make_pair("map", "µØÍ¼¡¢Ó³Éä"));

		unordered_map<string, string>::iterator it = dict.begin();
		while (it != dict.end())
		{
			cout << it->first << ":"<<it->second<<endl;
			++it;
		}
		cout<<endl;
	}
}