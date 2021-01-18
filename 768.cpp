

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<pair<int, int> > v;
        for (int i = 0; i < arr.size(); i++) {
            v.emplace_back(arr[i], i);
            //v.push_back(std::make_pair(arr[i], i));
        }
        std::sort(v.begin(), v.end()); // use stable sort;
        int count = 0;
        for (int i = 0; i < v.size(); ) {
            int max_idx = v[i].second; // [i, max_idx] must be within one chunk
            for (int j = i + 1; j <= max_idx; j++) {
                max_idx = max(max_idx, v[j].second);
            }
            count++;
            i = max_idx + 1;
        }
        return count;
    }
};


int main() {
    auto test_cases = vector< vector<int> >{ vector<int>{ 1, 0, 2, 3, 4 }, vector<int>{ 4,3,2,1,0 },
        vector<int>{ 4}, vector<int>{ 2,1,3,4,4 } };
    for (auto& v : test_cases) {
        cout << Solution().maxChunksToSorted(v) << endl;
    }
}
