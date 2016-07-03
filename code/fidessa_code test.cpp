

bool isMirrored(int num) {
	vector<int> v;
	while (num) {
		v.push_back(num % 10);
		num /= 10;
	}
	for (int i = 0, j = v.size() - 1; i<j; i++, j--) {
		if (v[i] != v[j])
			return false;
	}
	return true;
}

/*
* Complete the function below.
* 1 <= x <= 5
*/
int mirroredNumber(int numberDigits) {
	long long res = 0;
	long long start = pow(10, numberDigits - 1), end = pow(10, numberDigits) - 1;
	for (float i = end; i >= start; i -= 1) {
		for (float j = i; j >= start; j -= 1) {
			long long tmp = i*j;
			if (tmp <= INT_MAX && tmp >= res && isMirrored(tmp))
				res = tmp;
		}
	}
	return res;
}



int get_mirro(int b) {
	string str = std::to_string(b);
	string rev = str + string(str.rbegin(), str.rend());
	int ret = stoi(rev.c_str());
	return ret;
}

int judge(int v, int d) {
	int x = pow(10, d) - 1;
	while (x > pow(10, d)) {
		if (v % x == 0) {
			int s = v / x;
			if (s > pow(10, d - 1) && s < pow(10, d) - 1) {
				cout << s << "*" << v / s << "=" << v << "\n";
				return 0;
			}
		}
		x--;
	}
	return 1;
}

int solve(int dig) {
	int b = 0;
	if (dig == 5) {
		b = 21474;
	}
	else if (dig == 4) {
		b = 9999;
	}
	else if (dig == 3) {
		b = 999;
	}
	else if (dig == 2) {
		b = 99;
	}
	else {
		b = 9;
	}
	while (true) {
		int x = get_mirro(b);
		if (judge(x, dig) == 0) {
			break;
		}
		b--;
	}
	return 0;
}


int main() {

}