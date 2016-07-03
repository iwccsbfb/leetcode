#include <string>
#include <iostream>
#include <vector>
using namespace std;
// "4 + 8" Output: 12; + - * /
// 4 + 2 * 3; 
inline bool isSpace(string s) {
	for (char &ch : s) {
		if (ch != ' ') return false;
	}
	return true;
}

bool helper(string s, int start, int end, int &res) {
	// traverse from end to start
	int res1, res2;
	for (int i = end; i >= start; i--) {
		if (s[i] == '+' || s[i] == '-') {
			if (helper(s, start, i - 1, res1) && helper(s, i + 1, end, res2)) {
				if (s[i] == '+')
					res = res1 + res2;
				else res = res1 - res2;
				return true;
			}
			return false;
		}
	}
	for (int i = end; i >= start; i--) {
		if (s[i] == '*' || s[i] == '/') {
			if (helper(s, start, i - 1, res1) && helper(s, i + 1, end, res2)) {
				if (s[i] == '*')
					res = res1 * res2;
				else res = res1 / res2;
				return true;
			}
			return false;
		}
	}
	
// for invalid 输入，也可以在这里throw exception, 然后在最外面catch住；
	string str = s.substr(start, end - start + 1);
	if (isSpace(str))
		return false;
	res = std::stoi(str);
	return true;
}

inline bool isValidCharacter(char ch) {
	return ('0' <= ch && ch <= '9') || ch == ' ' || ch == '+' ||
		ch == '-' || ch == '*' || ch == '/';
}
// 12 ** 23 ++ 2 + 
int evaluateString(string s) {
	//8 - 4 - 2 == 2; 8/4/2 == 1

	// test if any character is not [0-9 + - * / ]
	// TODO
	for (auto &ch : s) {
		if (!isValidCharacter(ch)) return 0;
	}

	if (s.empty()) return 0;
	int res;
	if (helper(s, 0, s.size() - 1, res))
		return res;
	return 0;
}

// [1, 2, 5, 5, 9]
// n = 2
int countOccurance(vector<int> &v, int n) {
	if (v.empty()) return 0;
	int idx1, idx2;
	int s = 0, e = v.size() - 1;
	while (s < e - 1) {
		int mid = s + (e - s) / 2;
		if (v[mid] < n)
			s = mid;
		else if (v[mid] > n)
			e = mid;
		else  // v[mid] == n
			e = mid;
	}
	if (v[s] == n)  idx1 = s;
	else if (v[e] == n) idx1 = e;
	else return 0;

	s = 0, e = v.size() - 1;
	while (s < e - 1) {
		int mid = s + (e - s) / 2;
		if (v[mid] < n)
			s = mid;
		else if (v[mid] > n)
			e = mid;
		else  // v[mid] == n
			s = mid;
	}
	if (v[e] == n)  idx2 = e;
	else if (v[s] == n) idx2 = s;
	return idx2 - idx1 + 1;
}


int main() {
	string s = "12 / 2 * 3";
	// int res = evaluateString(s);
	// cout << res << endl;

	vector<int> v{ 9, 9, 9 };
	cout << countOccurance(v, 9) << endl;
	return 0;
}
















