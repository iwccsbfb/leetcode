#include <string>
#include <map>
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    // test: 1900 1901 1899 1911 4 40 44
    string intToRoman(int num) {
        vector<int> v = {1000,  100,  10,  1};
        map< int, char> m;
        m[1] = 'I';
        m[5] = 'V';
        m[10] = 'X';
        m[50] = 'L';
        m[100] = 'C';
        m[500] = 'D';
        m[1000] = 'M';
        string res = "";
        for(int i=0; i<v.size(); i++) {
            for(int j=0; j < num / v[i]; j++)
                res += m[v[i]];
            num %= v[i];
            if (i < v.size()-1) {
                if (v[i]-num <= v[i+1]) {
                    // cannot use += below 
                    res = res + m[v[i+1]] + m[v[i]]; // e.g. CM
                    num -= (v[i] - v[i+1]); // -= 900
                }else if ( num >= v[i]/2 ) {
                    res += m[v[i]/2];
                    num -= v[i]/2;
                } else if ( num >= v[i]/2 - v[i+1] ) {
                    num -= v[i]/2 - v[i+1];
                    res = res + m[v[i+1]] + m[v[i]/2];
                }
            }
            //cout << res << endl;
        }
        return res;
    }
};



int main() {
    //string s = "abc";
    //s = s + 'd' + 'e';
    //cout << s << endl;
    cout << Solution().intToRoman(1901) << endl;
    cout << Solution().intToRoman(4) << endl;
    cout << Solution().intToRoman(40) << endl;
    cout << Solution().intToRoman(44) << endl;
}
