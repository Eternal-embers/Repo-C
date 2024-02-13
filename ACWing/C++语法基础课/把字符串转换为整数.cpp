#include<iostream>
using namespace std;

class Solution {
public:
    int strToInt(string str) {
        int k = 0;
        while(k < str.size() && str[k] == ' ') k++;
        long long number = 0;
        bool is_minus = false;
        if(str[k] == '+') k++;
        if(str[k] == '-') is_minus = true,k++;
	   	while(k < str.size() && str[k] >= '0' && str[k] <= '9'){
            number = number * 10 + str[k] - '0';
            if(!is_minus && number > INT_MAX) return INT_MAX;
            if(is_minus && -number < INT_MIN) return INT_MIN;
            k++;
        }
        if(is_minus) number *= -1;
        return (int)number;
    }
};

int main(){
	Solution solution;
	string str = "9223372036854775808";
	cout << solution.strToInt(str) << endl;
	return 0;
}
