class Solution {
public:
//ERROR: 1. forѭ��֮�󣬻�Ӧ������һ��push_back
//EEROR: 2. ��Ϊ�����forѭ�����push_back��������Ҫ����nums��empty�����
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