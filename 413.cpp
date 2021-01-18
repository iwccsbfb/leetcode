
// 413
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        size_t i = 0, j = i + 2;
        int count = 0;
        // check if [i,j] is a valid slice
        while (j < A.size()) {
            int max_len = 0; // maximum number of slices starting from i
            while (j < A.size() and A[i+1]-A[i] == A[j]-A[j-1]) {
                j++;
                max_len++;
            }
            count += max_len * (max_len + 1) / 2;
            i = j - 1;
            j++; 
        }
        return count;
    }
};



int main() {
    int a[] = {1,2,3};
    cout << sizeof(size_t) << endl;
    cout << sizeof(int) << endl;
    cout << 10 / 2 << endl;
    cout << 5*6/3 << endl;


}
