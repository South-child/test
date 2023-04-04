#include <set>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <functional>
#include <assert.h>
using namespace std;

#include "AVLTree.h"
#include "RBTree.h"
#include "MyMap.h"
#include "MySet.h"

//
//void test_set1()
//{
//	// 排序+去重
//	set<int> s;
//	s.insert(3);
//	s.insert(1);
//	s.insert(5);
//	s.insert(2);
//	s.insert(8);
//	s.insert(1);
//	s.insert(8);
//
//	//set<int>::iterator it = s.begin();
//	auto it = s.begin();
//
//	while (it != s.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	set<int>::iterator pos = s.find(30);
//	if (pos != s.end())
//	{
//		// pos必须一个有效位置的迭代器
//		s.erase(pos);
//	}
//
//	cout << s.erase(30) << endl;
//	cout << s.erase(3) << endl;
//
//	for (auto e : s)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}
//
//void test_multiset()
//{
//	// 排序
//	multiset<int> s;
//	s.insert(3);
//	s.insert(1);
//	s.insert(5);
//	s.insert(2);
//	s.insert(8);
//	s.insert(1);
//	s.insert(8);
//	s.insert(1);
//	s.insert(1);
//
//	auto it = s.begin();
//	while (it != s.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	// find 的val有多个值时，返回中序第一个val值所在节点的迭代器
//	multiset<int>::iterator pos = s.find(8);
//	while (pos != s.end())
//	{
//		cout << *pos << " ";
//		++pos;
//	}
//	cout << endl;
//
//	/*pos = s.find(1);
//	while (pos != s.end() && *pos == 1)
//	{
//		auto next = pos;
//		++next;
//
//		s.erase(pos);
//
//		pos = next;
//	}*/
//
//	cout << s.erase(1) << endl;
//
//	for (auto e : s)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	pos = s.find(5);
//	if (pos != s.end())
//	{
//		// 不允许修改
//		//*pos += 10;
//	}
//}
//
//void test_map1()
//{
//	map<string, string> dict;
//	pair<string, string> kv1("sort", "排序");
//	dict.insert(kv1);
//	dict.insert(pair<string, string>("string", "字符串"));
//	// 自动推到类型
//	dict.insert(make_pair("test", "测试"));  // 使用它
//
//	//map<string, string>::iterator it = dict.begin();
//	auto it = dict.begin();
//	while (it != dict.end())
//	{
//		//it->first = "wess";
//		//it->second = "wess";
//
//		//cout << *it << " ";
//		//cout << (*it).first << ":" << (*it).second << endl;
//		cout << it->first << ":" << it->second << endl;
//		++it;
//	}
//	cout << endl;
//
//	for (auto& kv : dict)
//	{
//		cout << kv.first << ":" << kv.second << endl;
//	}
//	cout << endl;
//}
//
//void test_map2()
//{
//	string arr[] = { "苹果", "苹果", "香蕉", "苹果", "香蕉", "苹果", "樱桃" };
//	map<string, int> countMap;
//	/*for (auto& str : arr)
//	{
//		auto ret = countMap.find(str);
//		if (ret == countMap.end())
//		{
//			countMap.insert(make_pair(str, 1));
//		}
//		else
//		{
//			ret->second++;
//		}
//	}*/
//
//	//for (auto& str : arr)
//	//{
//	//	auto kv = countMap.insert(make_pair(str, 1));
//	//	if (kv.second == false)
//	//	{
//	//		kv.first->second++;
//	//	}
//	//}
//	for (auto& str : arr)
//	{
//		countMap[str]++;
//	}
//
//	for (auto& kv : countMap)
//	{
//		cout << kv.first << ":" << kv.second << endl;
//	}
//	cout << endl;
//}
//
//void test_map3()
//{
//	map<string, string> dict;
//	dict.insert(make_pair("sort", "排序"));
//	dict.insert(make_pair("left", "左边"));
//	dict.insert(make_pair("left", "剩余"));
//
//	dict["left"] = "剩余"; // 修改
//	dict["test"];          // 插入
//	cout << dict["sort"] << endl; // 查找
//
//	dict["string"] = "字符串"; // 插入+修改
//}
//
//
//void test_map4()
//{
//	multimap<string, string> dict;
//	dict.insert(make_pair("sort", "排序"));
//	dict.insert(make_pair("left", "左边"));
//	dict.insert(make_pair("left", "剩余"));
//	dict.insert(make_pair("left", "剩余"));
//
//	cout << dict.count("left") << endl;
//}
//
//struct CountVal
//{
//	bool operator()(const pair<string, int>& l, const pair<string, int>& r)
//	{
//		//return l.second > r.second;
//		return l.second < r.second;
//	}
//};
//
//struct CountIterVal
//{
//	bool operator()(const map<string, int>::iterator& l, const map<string, int>::iterator& r)
//	{
//		//return l->second > r->second;
//		return l->second < r->second;
//	}
//};
//
//// topk
//void GetFavoriteFruit(const vector<string>& fruits, size_t k)
//{
//	map<string, int> countMap;
//	for (auto& str : fruits)
//	{
//		countMap[str]++;
//	}
//
//	// 数据量不大，排序
//	// sort
//	// multimap
//	/*vector<pair<string, int>> sortV;
//	for (auto& kv : countMap)
//	{
//		sortV.push_back(kv);
//	}
//	sort(sortV.begin(), sortV.end(), CountVal());
// 
//	for (int i = 0; i < k; ++i)
//	{
//		cout << sortV[i].first << ":" << sortV[i].second << endl;
//	}
//	cout << endl;*/
//
//	/*vector<map<string, int>::iterator> sortV;
//	auto it = countMap.begin();
//	while (it != countMap.end())
//	{
//		sortV.push_back(it);
//		++it;
//	}
//	
//	sort(sortV.begin(), sortV.end(), CountIterVal());
//
//	for (int i = 0; i < k; ++i)
//	{
//		cout << sortV[i]->first << ":" << sortV[i]->second << endl;
//	}
//	cout << endl;*/
//
//	//multimap < int, string, greater<int>> sortMap;
//	//for (auto& kv : countMap)
//	//{
//	//	sortMap.insert(make_pair(kv.second, kv.first));
//	//}
///////////////////////////////////////////////////////////////////////////////////
//	// 堆
//	/*priority_queue<pair<string, int>, vector<pair<string, int>>, CountVal> pq;
//	for (auto& kv : countMap)
//	{
//		pq.push(kv);
//	}
//
//	while (k--)
//	{
//		cout << pq.top().first << ":"<<pq.top().second << endl;
//		pq.pop();
//	}
//	cout << endl;*/
//
//	priority_queue<map<string, int>::iterator, vector<map<string, int>::iterator>, CountIterVal> pq;
//	auto it = countMap.begin();
//	while (it != countMap.end())
//	{
//		pq.push(it);
//		++it;
//	}
//
//	while (k--)
//	{
//		cout << pq.top()->first << ":" << pq.top()->second << endl;
//		pq.pop();
//	}
//	cout << endl;
//}

int main()
{
	//test_set1();
	//test_multiset();
	//test_map4();
	//TestAVLTree();
	//TestRBTree();

	bit::test_set();
	bit::test_map();

	return 0;
}