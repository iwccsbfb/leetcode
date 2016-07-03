class Solution {
public:
// 1. ����˼�룺�����ֲ��볤�����м�
// 2. bug: ����Ķ����ֿ����� 00; �������ֵ�һλ�������һλ��������0
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
};