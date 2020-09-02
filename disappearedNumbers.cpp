// Time Complexity : O(n) 
// Space Complexity : O(1) 
// Did this code successfully run on Leetcode : Yes
// Any problem you faced while coding this : No

// [***] KEY INSIGHT: ITERATE THRU ARRAY AND NEGATE VALUE AT INDEX EQ TO CURR ELEMENT

// Your code here along with comments explaining your approach
// 1. Iterate thru input array and for each element go to index = element-1 and check if number there is positive
// 2. If yes, negate it else if already made negative, leave it
// 3. At the end iterate n check which indices are positive and add to result array

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        if(nums.size()==0)
            return {};
        vector<int> result;
        for(int num: nums){
            if(nums[abs(num)-1] > 0)
                nums[abs(num)-1] *= -1;
        }
        for(int i=0;i<nums.size();i++)
            if(nums[i]>0)
                result.emplace_back(i+1);
        return result;
    }
};

// My O(n) solution
// Time Complexity : O(n) 
// Space Complexity : O(1) 
// Did this code successfully run on Leetcode : Yes
// Any problem you faced while coding this : No

// [***] KEY INSIGHT: FOR EACH ELEMEN, GO TO INDEX = ELEMENT-1 AND MAKE IT EQUAL TO ELEMENT

// Your code here along with comments explaining your approach
// 1. Two pointers: i and j. Do till i does not cross bounds
// 2. Keep increasing i till we find elements in their proper place
// 3. Once this is broken, move element position to right place till we come to an already right element
// 4. In the end, iterate and check which indices don't have proper elements and add to result

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        if(nums.size()==0)
            return {};
        int i=0,j=0;
        vector<int> result;
        while(i<nums.size()){
            while(i<nums.size() && i+1 == nums[i])
                i++;
            if(i>=nums.size())
                break;
            j = nums[i];
            i++;
            while(j<=nums.size() && j!=nums[j-1]){
                int temp = nums[j-1];
                nums[j-1] = j;
                j = temp;
            }
        }
        for(auto el:nums)
            cout<<el<<" ";
        for(i=0;i<nums.size();i++)
            if(nums[i] != i+1)
                result.emplace_back(i+1);
        return result;
    }
};