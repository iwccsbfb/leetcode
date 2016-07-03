#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

/*
Set 4 (Subset Sum)
Subset sum problem is to find subset of elements that are selected from a given set whose sum adds up to a given number K. We are considering the set contains non-negative values. It is assumed that the input set is unique (no duplicates are presented).

Exhaustive Search Algorithm for Subset Sum

One way to find subsets that sum to K is to consider all possible subsets. A power set contains all those subsets generated from a given set. The size of such a power set is 2N.

Backtracking Algorithm for Subset Sum

Using exhaustive search we consider all subsets irrespective of whether they satisfy given constraints or not. Backtracking can be used to make a systematic consideration of the elements to be selected.
*/

struct ReturnType {
	vector<int> values;
	bool flag;
	ReturnType(bool _flag) : flag(_flag) {}

	ReturnType(vector<int> &sol, bool _flag) :
		values(sol), flag(_flag) {}
};

ReturnType helper(vector<int> &v, vector<int> &sol, int cur_sum, int idx, int sum) {
	int sz = v.size();
	if (idx >= sz) return false;
	for (int i = idx; i<sz; i++) {
		cur_sum += v[i];
		sol.push_back(v[i]);
		if (cur_sum == sum)
			return ReturnType(sol, true);
		if (cur_sum < sum) {
			auto res = helper(v, sol, cur_sum, i + 1, sum);
			if (res.flag)
				return res;
		}
		cur_sum -= v[i];
		sol.pop_back();
	}
	return ReturnType(false);
}

bool subset_sum(vector<int> &v, int sum) {
	vector<int> sol;
	auto res = helper(v, sol, 0, 0, sum);
	if (res.flag) {
		for (auto &i : res.values) {
			cout << i << ' ';
		}
	}
	return res.flag;
}

int main() {
	vector<int> v{ 1,2,5,8,23 };
	cout << subset_sum(v, 28) << endl;
	return 0;
}























