class Solution {
public:
    int NumberOf1(int n) {
        int cnt = 0;
        for(int i = 0;i < 32;i++)
            if(n >> i & 1) cnt++;
        return cnt;
    }
    
	int NumberOf1(int n) {
        unsigned int u = n;

        int res = 0;
        while(u) res += u & 1,u >>= 1;
        return res;
    }
};
