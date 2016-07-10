class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1 ;
        while(i>=0 && digits[i] == 9) {
            digits[i] = 0;
            i--;
        }
        if(i == -1) {
            vector<int>res{1};
            for(auto i: digits) res.push_back(i);
            return res;
        }else {
            digits[i] ++;
            return digits;
        }
    }
};