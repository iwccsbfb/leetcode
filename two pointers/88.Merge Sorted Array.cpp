
class Solution {
public:

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		vector<int> res(m+n);
		int i = 0, j = 0;
		while(i < m || j < n) {
		    //ERROR: 这个地方要出错过
			if(j == n  || (i < m && nums1[i] < nums2[j]) )
				res[i+j] = nums1[i++];
			else 
				res[i+j] = nums2[j++];
		}
		for(i=0; i<m+n; i++)
			nums1[i] = res[i];
	}
    void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0, j=0;
        while(j<n){
            while(i<m && nums1[i]<nums2[j] ) 
                i++;
            nums1.insert(nums1.begin()+i, nums2[j++]);
        }
        while(nums1.size()>m+n)
            nums1.pop_back();
    }
};

