class Solution {
    // !!!!!!!!!
    // in exp: s1 > A.size()-1;
    // if A.size() = 0, A.size()-1 would be 2^31;
    // becuase arithmatic of unsigned int would still be unsigned int
    // so instead use s1 >= A.size()
    // Error2: 第k/2个数字的下表是s1+idx-1 而不是 s1+idx
    // Error3: 如果数组长度不够，那么就用INT_MAX, 而不是INT_MIN 
    // 自己想想为什么
	int findKthNumber(vector<int> &A, int s1, vector<int> &B, int s2, int k) {
		if (s1 >= A.size()) return B[s2 + k - 1];
		if (s2 >= B.size()) return A[s1 + k - 1];
		if (k == 1) return A[s1] > B[s2] ? B[s2] : A[s1];

		int idx = k / 2 ;
		int val_A = s1 + idx - 1 < A.size() ? A[s1 + idx -1] : INT_MAX;
		int val_B = s2 + idx - 1 < B.size() ? B[s2 + idx -1] : INT_MAX;
		if (val_A > val_B) {
			int cnt = s2 + idx < B.size() ? idx : B.size() - s2;
			return findKthNumber(A, s1, B, s2 + cnt, k - cnt);
		}
		else {
			int cnt = s1 + idx < A.size() ? idx : A.size() - s1;
			return findKthNumber(A, s1 + cnt, B, s2, k - cnt);
		}
	}
    
public:
    double findMedianSortedArrays(vector<int> A, vector<int> B) {
        // cout<<findKthNumber(A, 0, B, 0, (m+n)/2)<<endl;
        int m = A.size(), n = B.size();
        if( (m+n)%2 != 0) 
            return findKthNumber(A, 0, B, 0, (m+n)/2+1);
        else 
            return (findKthNumber(A, 0, B, 0, (m+n)/2 + 1) + 
                    findKthNumber(A, 0, B, 0, (m+n)/2) )/2.0;
    }
};
