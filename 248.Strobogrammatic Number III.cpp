class Solution {
public:
// 找出所有的string, 然后比较，内存会爆: 内存并不会爆，之前自己可能出错了
// test input validaty first
// 把<=high的数字都测一下，这样会超时
    int strobogrammaticInRange(string low, string high) {
        int n1 = low.size(), n2 = high.size();
        if(n1 > n2 || (n1 == n2 && low>high) ) return 0;
        
        vector<int> cnt(n2, 0);
        for(int i=1; i<n2; i++) {
            if(i == 1) cnt[i] = 3;
            else if(i == 2) cnt[i] = 4;
            else if(i % 2 != 0) cnt[i] = cnt[i-1]*3;
            else cnt[i] = cnt[i-2]*5;
        }
        int sum = 0;
        for(int i = n1+1; i<= n2-1; i++) sum += cnt[i];
        
        auto res1 = findStrobogrammatic(n1);
        if(n1 == n2) {
            for(auto s: res1) {
                if(low <= s && s<= high) sum++;
            }
        } else {
            for(auto s: res1) {
                if(s >= low) sum++;
            }
            auto res2 = findStrobogrammatic(n2);
            for(auto s: res2) {
                if(s <= high) sum++;
            }
        }
        /*
        string s = low; 
        if(low.size() != high.size()) {
            do{ 
                if(isStrobogrammatic(s)) sum++;
            }while(next(s));
            s = high;
            do {
                if(isStrobogrammatic(s)) sum++;
            }while(before(s));
        } else {
            do{
                if(isStrobogrammatic(s)) sum++;
            }while(next(s) && s <= high);
        }
        */
        return sum;
    }
    
private:
    vector<string> findStrobogrammatic(int n) {
        if(n <= 0) return vector<string>{};
        if(n == 1) return vector<string>{"0", "1", "8"};
        if(n == 2) return vector<string>{"11","69","88","96"};
        vector<string> tmp1; // longer result
        vector<string> tmp2; // shorter result
        if(n%2 == 0) {
            tmp1 = findStrobogrammatic(n - 2);
            tmp2 = findStrobogrammatic(2);
            tmp2.push_back("00");
        } else {
            tmp1 = findStrobogrammatic(n-1);
            tmp2 = findStrobogrammatic(1);
        }
        vector<string> res;
        for(auto str1: tmp1) {
            int sz = str1.size();
            string s1 = str1.substr(0, sz/2);
            string s2 = str1.substr(sz/2, sz/2);
            for(auto str2: tmp2) {
                res.push_back(s1 + str2 + s2);
            }
        }
        return res;
    }


    // return false if increase by one digit
    bool next(string &num) {
        int idx = num.size() - 1;
        // 必须要先判断idx >=0 ，再访问idx，否则会报错
        while(idx >= 0 && num[idx] == '9'){
            num[idx] = '0';
            idx--;
        }
        if(idx<0) return false;
        num[idx] ++;
        return true;
    }
    
    bool before(string &num) {
        int idx = num.size() - 1;
        while(num[idx] == '0'){
            num[idx] = '9';
            idx--;
        }
        if(idx==0 && num[idx] == '1') return false;
        num[idx] --;
        return true;
    }
    
    bool isStrobogrammatic(string num) {
        for(int i=0, j=num.size()-1; i<=j; i++, j--) {
            if(!match(num[i], num[j]))
                return false;
        }
        return true;
    }
    
    bool match(char ch1, char ch2) {
        if(ch1 == ch2) {
            if(ch1 == '0' || ch1 == '1' || ch1 == '8')
                return true;
            return false;
        }
        if( (ch1 == '6' && ch2 == '9') || (ch1 == '9' && ch2 == '6') )
            return true;
        return false;
    }
};


