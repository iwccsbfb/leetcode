class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> le(n,1), ri(n,1);
    for(int i=1; i<n; i++) le[i] = le[i-1] * nums[i-1];
    for(int i=n-2; i>=0; i--) ri[i] = ri[i+1] * nums[i+1];
    vector<int> res(n);
    for(int i=0; i<n; i++)
      res[i] = le[i] * ri[i];
    return res;
  }
};