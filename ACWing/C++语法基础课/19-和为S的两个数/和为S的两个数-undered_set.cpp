class Solution {
public:
    vector<int> findNumbersWithSum(vector<int>& nums, int target) {
		unordered_set<int> hash;

		for(int i = 0;i < nums.size();i++){
			if(hash.count(target - nums[i])) return vector<int> {target - nums[i],nums[i]};
			hash.insert(nums[i]);
		}

		return vector<int>{};
    }
};
