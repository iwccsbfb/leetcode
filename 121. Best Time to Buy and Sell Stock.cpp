//ERROR: �߽�����������Ϊ��; res����Ҫ��ʼ��Ϊ0����������INT_MIN
class Solution {
public:
    int maxProfit(vector<int>& prices) {
		int n = prices.size();
		vector<int> arr1(n), arr2(n);
		int tmp = INT_MAX;
		for(int i=0; i<n; i++) {
			arr1[i] = tmp = min(tmp, prices[i]);
		}
		tmp = INT_MIN;
		for(int i=n-1; i>=0; i--) {
			arr2[i] = tmp = max(tmp, prices[i]);
		}
		
		int res = 0;
		for(int i=0; i<n; i++) {
			res = max(res, arr2[i]-arr1[i]);
		}
		return res;
	}
};