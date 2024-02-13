class Solution {
public:
	vector<vector<int>> ans;
	vector<int> path;
    vector<vector<int>> permutation(vector<int>& nums) {
		path.resize(nums.size());
		sort(nums.begin(),nums.end());
		dfs(nums,0,0,0);
		return ans;
    }

    void dfs(vector<int> nums,int u,int start,int state){
		if(u == nums.size()) {
			ans.push_back(path);
			return;
  		}

		/*  规定重复的数只能放在上一个重复的数的后面位置，防止重复 */
		if(!u || nums[u] != nums[u - 1]) start = 0;
		for(int i = start;i < nums.size();i++)
			if(!(state >> i & 1)){ //如果第i位没有放置
				path[i] = nums[u];
				dfs(nums,u + 1,i + 1,state + (1 << i));
			}
	}
};
