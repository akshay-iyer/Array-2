// Time Complexity : O(n); 1.5n total computations instead of 2n 
// Space Complexity : O(1) 
// Did this code successfully run on Leetcode : Yes
// Any problem you faced while coding this : No

// [***] KEY INSIGHT: PROCESS ELEMENTS IN PAIRS

// Your code here along with comments explaining your approach
// 1. We need to reduce number of computations. Brute force is 2n
// 2. Process array in pairs, compare min of pair with global min and max of pair with global max
// 3. Thus, for each pair - 3 comparisons - within pair, with glob min, with glob max; n/2 such pairs thus 3n/2 comparisons in toto


vector<int> minMax(vector<int> nums){
	if(nums.size()==0)
		return {};
	int maxNum = INT_MIN, minNum = INT_MAX;
	for(int i=0;i<nums.size() && i+1<nums,size();){
		int temp_min = min(nums[i],nums[i+1]);
		int temp_max = max(nums[i],nums[i+1]);
		minNum = min(minNum,temp_min);
		maxNum = max(maxNum,temp_max);
		i+=2;
	}
	result = {minNum,maxNum};
	return result;
}