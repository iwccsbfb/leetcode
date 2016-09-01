#inlcude <unordered_set>

class Solution {
public:
// ERROR: 需要用i-k-1,而不是i-k, 否则会runtime error
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> s;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            if(i-k-1 >= 0) {
                auto pos = s.find(nums[i-k-1]);
                s.erase(pos);
            }
            if(s.find(nums[i]) != s.end()) 
                return true;
            s.insert(nums[i]);
        }
        return false;
    }
};
