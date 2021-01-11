#include <string>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char, int > m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        
        int res = m[s[s.size()-1]];
        for(int i=0; i<s.size()-1; i++) {
            if( m[s[i]] < m[s[i+1]] ) 
                res -= m[s[i]];
            else 
                res += m[s[i]];
        }
        return res;
    }
};


/* copied from someone else
class Solution {
public:
    string intToRoman(int num) {
        vector<int> div={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string> roman={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string res;

        for(int i=0;i<div.size()&&num>3;i++){
            for(int j=0;j<num/div[i];j++)
                res+=roman[i];
            num%=div[i];
        }
        for(int i=0;i<num;i++){
            res+="I";
        }
        return res;
    }
};
*/

int main() {
    cout << Solution().romanToInt("MCMXCIV") << endl;
}

