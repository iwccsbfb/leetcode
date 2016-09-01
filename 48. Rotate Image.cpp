
class Solution {
public:
// ERROR: 有一个轴需要能达到mid，没有或者两个都不行
// 方法2：[i, j] --> [j, n-1-i]
  void rotate(vector<vector<int>>& matrix) {
    if(matrix.empty()) return;
    int n = matrix.size();
    double mid = (0 + n-1)/2.0;
    for(int i=0; i<=mid; i++) {
      for(int j=0; j<mid; j++) {
        int ii = i, jj = j;
        int tmp = matrix[ii][jj];
        double x = i - mid, y = j - mid;
        to_idx(ii, jj, mid, y, -x);
        std::swap(tmp, matrix[ii][jj]);
        to_idx(ii, jj, mid, -x, -y);
        std::swap(tmp, matrix[ii][jj]);
        to_idx(ii, jj, mid, -y, x);
        std::swap(tmp, matrix[ii][jj]);
        to_idx(ii, jj, mid, x, y);
        std::swap(tmp, matrix[ii][jj]);
      }
    }
  }
private:
  void to_idx(int &i, int &j, double mid, double x, double y) {
    i = int(x + mid);
    j = int(y + mid);
  }
};