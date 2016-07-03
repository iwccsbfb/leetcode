
// summary: 
// 1. 需要定义 compare, hash, equal_to几个class, 并OverLoad()
// 2. operator() or <, == are const functions;
// 3. can also specialize less<key>, hash<key>, equal_to<key> in std namespace;
// 4. can also define < or == in mystruct class;
// 5. set and map, are interated from smallest to biggest
// 6. priority_queue only needs < or Compare; and it does not accept init list or container;
// on the other hand, queue does not accept init list but accept container
// queue<int> q({ 1, 2, 3 }); is OK; queue<int> q{ 1, 2, 3 }; not ok;
// but both cases are not ok with priority_queue



#include <set>
#include <iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct mystruct {
	int a; int b;
	bool operator==(const mystruct&m2) const {
		return (a == m2.a) && (b == m2.b);
	}
	bool operator < (const mystruct &m2) const {
		return a<m2.a;
	}
};

class Compare {
public:
	bool operator()(const mystruct&m1, const mystruct&m2) {
		return m1.a<m2.a;
	}

};

class Hasher {
public:
	int operator()(const mystruct&m1) const {
		return m1.a * 1000 + 23467;
	}
};
class Myequal {
public:
	bool operator()(const mystruct&m1, const mystruct&m2) const {
		return (m1.a == m2.a) && (m1.b == m2.b);
	}
};

namespace std {


	template<>
	class hash<mystruct> {
	public:
		int operator()(const mystruct&m1) const {
			return m1.a * 1000 + 23467;
		}
	};
	/*
	template<>
	class less<mystruct>{
	public:
	bool operator()(const mystruct&m1, const mystruct&m2){
	return m1.a<m2.a;
	}
	};


	template<>
	class equal_to<mystruct>{
	public:
	bool operator()(const mystruct&m1, const mystruct &m2) const{
	return m1.a == m2.a && m1.b == m2.b;
	}
	};*/

}


int main() {
	mystruct m1{ 1,2 }, m2{ 0,4 };

	set<mystruct> s{ m1,m2 };
	map<mystruct, int> m;
	m[m1] = 1;

	unordered_set<mystruct, Hasher> un_s;
	un_s.insert(m1);
	unordered_map<mystruct, int, Hasher> un_m;
	// unordered_map<mystruct, int, Hasher, Compare> un_m;
	un_m[m1] = 1;
	//  for(auto i = s.begin(); i != s.end(); i++)
	//    cout<<*i <<endl;
	for (auto i : s)
		cout << i.a << ' ' << i.b << endl;
	for (auto &i : m)
		cout << i.first.a << ' ' << i.first.b << ' ' << i.second << endl;
	for (auto i : un_s)
		cout << i.a << ' ' << i.b << endl;
	for (auto &i : m)
		cout << i.first.a << ' ' << i.first.b << ' ' << i.second << endl;
}


