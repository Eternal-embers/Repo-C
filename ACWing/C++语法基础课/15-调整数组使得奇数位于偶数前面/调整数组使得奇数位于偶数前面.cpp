class Solution {
public:
    void reOrderArray(vector<int> &array) {
		int l = 0,r = array.size() - 1;
		while(l < r){
			if(array[l] % 2 == 1) l++;
			if(array[r] % 2 == 0) r--;
			if(l < r) swap(array[l],array[r]);
		}
    }
};
