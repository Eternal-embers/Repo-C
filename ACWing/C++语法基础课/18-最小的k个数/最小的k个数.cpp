class Solution {
public:
    vector<int> getLeastNumbers_Solution(vector<int> input, int k) {
		priority_queue<int> heap;
		
		for(auto x: input){
			heap.push(x);
			if(heap.size() > k) heap.pop();
		}
		
		vector<int> res;
		while(heap.size()) {
			res.push_back(heap.top());
			heap.pop();
		}
		
		reverse(res.begin(),res.end());
		return res;
    }
};
