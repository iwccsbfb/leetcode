
class Solution {
public:
    // O(k) �ռ�
    void rotate(vector<int>& nums, int k) {
		int n = nums.size();
		k = k%n;
		// ERROR1: ��Ҫ�ж�k == 0
		if(k == 0) return;
		vector<int> buffer(k);
		for(int j=0; j < k; j++) {
			buffer[j] = nums[j];
		}
		
		int i = 0, s_idx = 0;
		while(i < n) {
			s_idx += k;
			for(int j=0; j < k; j++, i++) {
				std::swap(nums[(s_idx + j)%n], buffer[j]);
			}
		}
	}
	// O(1)�ռ䣬�����ü��δ���
    void rotate2(vector<int>& nums, int k) {
		int n = nums.size();
		int nn = gcd(n, k);
		for(int i=0; i<nn; i++) {
			int tmp = nums[i];
			for(int j=1; j<= n/nn; j++){
				int idx = (i + j*k) % n;
				// ��swap����������Ҫ����tmp
				std::swap(nums[idx], tmp);
			}
		}
	}
    
private:
    int gcd(int a, int b) {
        if(a == 0) return b;
        if(b == 0) return a;
        return gcd(b, a%b);
    }
};

