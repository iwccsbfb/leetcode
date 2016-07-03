#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
//����������O(n^2), ����1������Htable�����Կ����������һЩ

	// -2,-2,-2,-2, 4,4
	// A = { (b, c) | a1+b+c=0, a<=b<=c }
	// a2 == a1, and idx(a2) > idx(a1)
	// B = { (b, c) | a2+b+c=0, a<=b<=c }
	// we have: B is a subset of A
    vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int sz = nums.size();
		unordered_map<int, int> hash;
		// for duplicate numbers, hash point to the last one; 
		// i��j�Ǵ�ͷ��β�����ģ�����hashҪָ�����һ����
		for(int i=0; i<sz; i++) hash[nums[i]] = i;
		
		vector<vector<int>> res;
		for(int i=0; i<sz; i++) {
			//ȥ���ظ��ر�
			if(i != 0 && nums[i-1] == nums[i]) 
				continue;
			int target = -nums[i];
			for(int j=i+1; j<sz; j++) {
				//ȥ���ظ��ر�
				if(j != i+1 && nums[j-1] == nums[j])
					continue;
				if( hash.find(target - nums[j]) != hash.end() ) {
					int idx = hash[target - nums[j]];
					if(idx > j) 
						res.push_back(vector<int>{nums[i], nums[j], target - nums[j]} );
				}
			}
		}
		return res;
	}
	// ȥ�� Ҫ�������ؿ�
	vector<vector<int>> threeSum2(vector<int>& nums) {
    	sort(nums.begin(), nums.end());
    	int sz = nums.size();
    	vector<vector<int>> res;
    	for (int i = 0; i < sz; i++) {
			if(i != 0 && nums[i-1] == nums[i]) 
				continue;
    		int l = i + 1, r = sz - 1;
    		while (l < r) {
				if(l != i+1 && nums[l-1] == nums[l]) {
					l++; continue;
				}
				if(r != sz-1 && nums[r] == nums[r+1]) {
					r--; continue;
				}
    			int sum = nums[l] + nums[r];
    			if (sum == -nums[i]) {
    				if (r + 1 >= sz || nums[r] != nums[r + 1]) {
    					res.push_back(vector<int>{nums[i], nums[l], nums[r]});
    				}
    				r--; l++;
    			}
    			else if (sum < -nums[i])
    				l++;
    			else r--;
    		}
    	}
    	return res;
    }
};