
class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        int i1 = arr1.size() - 1, i2 = arr2.size() - 1;
        int c1 = 0, c2 = 0;
        vector<int> res; // (max(arr1.size(), arr2.size()), 0);
        while (i1 >= 0 or i2 >= 0 or c1 or c2) {
            // careful: deduct 2 c1 with 1 c2. otherwise, could go to infinite loop
            // For example: [1,1] + [1,1,1]
            while (c1 >= 2 && c2 >= 1) {
                c2--;
                c1 -= 2;
            }
            int sum = c1, cur;
            if (i1 >= 0) sum += arr1[i1--];
            if (i2 >= 0) sum += arr2[i2--];
            cur = sum % 2;
            // calc next round of carry
            c1 = c2; c2 = 0;
            if (sum == 2 || sum == 3) {
                c1++; c2++;
            }
            else if (sum == 4) {
                c2++;
            }
            res.emplace_back(cur);
        }
        // could have redundant post zeroes here. e.g.: [1] + [1,1]
        while (res.size() >= 2 && res.back() == 0)
            res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};


int main() {
    vector<int> v1{ 1,1,1,1,1 }, v2{ 1,0,1 }, v3;
    v3 = Solution().addNegabinary(v1, v2);
    for (auto& i : v3)
        cout << i << ' ';
    cout << endl;

    v1 = vector<int>{ 1,1 };
    v2 = vector<int>{ 1 };
    v3 = Solution().addNegabinary(v1, v2);
    for (auto& i : v3)
        cout << i << ' ';
    cout << endl;


    v1 = vector<int>{ 0 };
    v2 = vector<int>{ 1 };
    v3 = Solution().addNegabinary(v1, v2);
    for (auto& i : v3)
        cout << i << endl;

    return 0;
}


