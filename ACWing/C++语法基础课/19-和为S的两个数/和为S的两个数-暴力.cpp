class Solution {
public:
    vector<int> findNumbersWithSum(vector<int>& nums, int target) {
		for(int i = 0;i < nums.size();i++)
			for(int j = 0;j < nums.size();j++)
				if(nums[i] + nums[j] == target && i != j) return vector<int>{nums[i],nums[j]};
    }
};
