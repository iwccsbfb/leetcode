class Solution {
public:
//ERROR: 1. for循环之后，还应该再有一个push_back
//EEROR: 2. 因为有这个for循环外的push_back，所以需要考虑nums是empty的情况
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if(nums.empty()) return res;
        int s = 0, e = 0;
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] == nums[i-1]+1) e++;
            else {
                res.push_back(summary(nums[s], nums[e]));
                e = s = i;
            }
        }
        res.push_back(summary(nums[s], nums[e]));
        return res;
    }
private:
    string summary(int s, int e) {
        if(s == e) return std::to_string(s);
        else return std::to_string(s) + "->" + std::to_string(e);
    }
};