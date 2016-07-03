class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num, cnt = 0;
        for(int &i : nums) {
            if(cnt == 0) {
                cnt = 1;
                num = i;
            }else if(i == num){
                cnt++;
            } else
                cnt--;
        }
        return num;
    }
};