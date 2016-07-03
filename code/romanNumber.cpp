#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <assert.h>
using namespace std;





int roman2Int(string romanNumber)
{
	int length = romanNumber.size();
	int previous = 0;
	bool error = false;
	int idx = 0;

	int sum = 0;

	while ((error == false) && (idx < length))
	{
		switch (romanNumber[idx]) {
		case 'M':
			sum += 1000;
			if (previous < 1000)
				sum -= 2 * previous;
			previous = 1000;
			break;
		case 'D':
			sum += 500;
			if (previous < 500)
				sum -= 2 * previous;
			previous = 500;
			break;
		case 'C':
			sum += 100;
			if (previous < 100)
				sum -= 2 * previous;
			previous = 100;
			break;
		case 'L':
			sum += 50;
			if (previous < 50)
				sum -= 2 * previous;
			previous = 50;
			break;
		case 'X':
			sum += 10;
			if (previous < 10)
				sum -= 2 * previous;
			previous = 10;
			break;
		case 'V':
			sum += 5;
			if (previous < 5)
				sum -= 2 * previous;
			previous = 5;
			break;
		case 'I':
			sum += 1;
			if (previous < 1)
				sum -= 2 * previous;
			previous = 1;
			break;
		default:
			cout << romanNumber[idx] << " is not a Roman Numeral!" << endl;
			error = true;
			sum = 0;
		} // switch
		idx++;
	} // while 
	return sum;
}

vector<int> helper(int x) {
	assert(1 <= x && x <= 9);
	// if (x == 0) return vector<int>{-1};
	if (x < 4) return vector<int>(x, 0);
	if (x == 4) return vector<int>{0, 1};
	if (5 <= x && x <= 8) {
		vector<int>res(x - 5, 0);
		res.insert(res.begin(), 1);
		return res;
	}
	if (x == 9) return vector<int>{0, 2};
}

string int2Roman(int num)
{
	if (num > 3999) return "INVALID";
	char matrix[4][3] = { {'I', 'V', 'X'},
							{'X','L', 'C' },
							{'C', 'D', 'M'},
							{'M', 'M', 'M'} };
	string res;
	int cnt = 0;
	while (num) {
		int digit = num % 10;
		num /= 10;
		if (digit) {
			auto idx = helper(digit);
			string tmp;
			for (auto &i : idx) {
				tmp += matrix[cnt][i];
			}
			res = tmp + res;
		}
		cnt++;
	}
	return res;
}

int main()
{
	int tmp = 3999; // max 3999
	while (true) {
		cin >> tmp;
		auto roman = int2Roman(tmp);
		int value = roman2Int(roman);
		cout << "Roman Number " << roman << " equals " << value << endl;
	}
	return 0;
}



