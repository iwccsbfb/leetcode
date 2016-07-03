#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
	class BigInt {
		vector<int> data;
	public:
		BigInt() {}
		BigInt(string &s) {
			for (int i = s.size() - 1; i >= 0; i--)
				data.push_back(s[i] - '0');
		}
		bool is_zero() {
			return data.size == 1 && data[0] == 0;
		}
		string to_string() {
			string res;
			for (int i = data.size() - 1; i >= 0; i--) {
				res += data[i] + '0';
			}
			return res;
		}
	private:
		void operator+=(BigInt &a) {
			BigInt tmp = a + *this;
			data = std::move(tmp.data);
		}

		friend BigInt operator*(BigInt &a, BigInt &b) {
			if (a.is_zero()) return a;
			if (b.is_zero()) return b;
			int sz1 = a.data.size(), sz2 = b.data.size();
			BigInt res;
			for (int i = 0; i<sz1; i++) {
				BigInt tmp;
				tmp.data = vector<int>(i, 0);
				int carry = 0;
				for (int j = 0; j<sz2; j++) {
					int digit = carry + b.data[j] * a.data[i];
					carry = digit / 10;
					digit %= 10;
					tmp.data.push_back(digit);
				}
				if (carry != 0) tmp.data.push_back(carry);
				res += tmp;
			}
			return res;
		}

		friend BigInt operator+(BigInt &a, BigInt &b) {
			int sz1 = a.data.size(), sz2 = b.data.size(), sz = max(sz1, sz2);
			int carry = 0;
			BigInt c;
			for (int i = 0; i<sz; i++) {
				int digit = carry;
				if (i<sz1) digit += a.data[i];
				if (i<sz2) digit += b.data[i];
				carry = digit / 10;
				digit %= 10;
				c.data.push_back(digit);
			}
			if (carry != 0) c.data.push_back(carry);
			return c;
		}

	};
public:
	string multiply(string num1, string num2) {
		BigInt a(num1), b(num2);
		BigInt c = a*b;
		return c.to_string();
	}
};
int main() {
	cout << Solution().multiply("1", "1") << endl;
	return 0;
}























