// 双指针问题；自己并没有想出来这个算法
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(),res = 0;
        int i = 0, j = n-1;
        while(i<j) {
            res = max(res, (j-i)*min(height[i], height[j]));
            if(height[i] < height[j]) i++;
            else if(height[i] > height[j]) j--;
            else {
                i++; j--;
            }
        }
        return res;
    }
};
