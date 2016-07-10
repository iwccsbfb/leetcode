#include <algorithm>
// ERROR: ���˺ܶ�Σ��ܶ�ϸ�ڶ����ˣ�Ҫ��д����
// 1. Ҫ�� >= ��������>
// 2. ����Ҫ��ǰ��++
// 3. ��һ��д���������ջ��idx���ݼ�ջ��idx
class Solution {
public:
	int trap(vector<int>& height) {
		int n = height.size();
		vector<int> inc, dec;
		int idx = 0;
		for (int i = 0; i<n; i++) {
			int h = height[i];
			if (h > 0 && (inc.empty() || h >= inc.back())) {
				inc.push_back(h);
				idx = i;
			}
		}
		for (int i = n-1; i >= idx; i--) {
			int h = height[i];
			if (h > 0 && (dec.empty() || h >= dec.back()))
				dec.push_back(h);
		}
		reverse(dec.begin(), dec.end());

		if (inc.empty()) return 0;
		int i = 0, res = 0;
		idx = 0;
		while (height[i] < inc[0]) i++;

		while (idx < inc.size() - 1) {
			int h1 = inc[idx++];
			int h2 = inc[idx];
			while (height[++i] < h2) {
				res += h1 - height[i];
			}
		}
		idx = 0;
		while (idx < dec.size() - 1) {
			int h1 = dec[idx++];
			int h2 = dec[idx];
			while (height[++i] < h2) {
				res += h2 - height[i];
			}
		}
		return res;
	}
};