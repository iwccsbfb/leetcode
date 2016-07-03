
class Solution {
public:
    // hashtable: O(2n)
	// 方法1和3，都是用Hashtable; 但1可以不用考虑重复，三必须要考虑重复；
	// 因为3是遍历hashtable获得值的
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for(int i=0; i<nums.size(); i++)
            m[nums[i]] = i;
        
        for(int i=0; i<nums.size(); i++) {
            if(m.find(target-nums[i]) != m.end()) {
                int idx = m[target-nums[i]];
                if(idx != i)
                    return vector<int> {min(idx, i), max(idx, i)};
            }
        }
    }
    
    vector<int> twoSum3(vector<int>& nums, int target) {
		unordered_map<int, vector<int>> m;
		for (int i = 0; i < nums.size(); i++)
			m[nums[i]].push_back(i);
		for (auto &i : m) {
			if (m.find(target - i.first) != m.end()) {
				int &a = i.second[0];
				auto &v = m[target - i.first];
				int &b = v.back();
				// ATTENTION HERE
				if (a == b && v.size()==1 ) continue;
				if(a<b) return vector<int> {a, b};
				else return vector<int> {b, a};
			}
		}
	}
	
	// sort, two pointers: n*logn
	vector<int> twoSum2(vector<int>& nums, int target) {
		int sz = nums.size();
		auto cp = nums;
		q_sort(cp, 0 , sz-1);
		int i = 0, j = sz - 1;
		while (i<j) {
			int sum = cp[i] + cp[j];
			if (sum == target) break;
			else if (sum < target) i++;
			else j--;
		}
		int l = -1, r = -1;
		for (int tmp = 0; tmp < sz; tmp++)
		{
			if (l == -1 && nums[tmp] == cp[i]) l = tmp;
			else if (r == -1 && nums[tmp] == cp[j]) r = tmp;
		}
		return vector<int>{l, r};
	}

	void q_sort(vector<int> &nums, int s, int e) {
		if (s >= e) return;
		int id = partition(nums, s, e);
		q_sort(nums, s, id - 1);
		q_sort(nums, id + 1, e);
	}

	int partition(vector<int> &nums, int s, int e) {
		int idx = rand() % (e - s) + s;
		std::swap(nums[idx], nums[e]);
		int &pivot = nums[e];
		int res = s;
		for (int i = s; i < e; i++) {
			if (nums[i] <= pivot)
				std::swap(nums[i], nums[res++]);
		}
		std::swap(nums[res], nums[e]);
		return res;
	}
};
