#include <vector>
// 
//

#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
	int helper(string s, int start) {
		int res = 0, sz = s.size();
		if (start >= sz) return 1;

		for (int i = start; i<sz; i++) {
			if ('3' <= s[i] || (s[i] == '2' && (i == sz - 1 || '7' <= s[i + 1])))
				return helper(s, i + 1);
			else if (((s[i] == '1' || s[i] == '2') && (i == sz - 1 || s[i + 1] == '0')))
				return helper(s, i + 2);
			else
				return helper(s, i + 1) + helper(s, i + 2);
		}
	}
public:
	int numDecodings(string s) {
		return helper(s, 0);
	}
};


int main() {

	auto res = Solution().numDecodings("11");
	return 0;
}