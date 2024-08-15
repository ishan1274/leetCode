class Solution {
public:
    void sortColors(vector<int>& nums) {\



//Better aprroach
        int count1=0, count2=0, count3=0;

        for(int i=0; i<nums.size(); i++) {
            if(nums[i]==0) {
                count1++;
            }
            else if(nums[i]==1) {
                count2++;
            }
            else {
                count3++;
            }
        }

        for(int i = 0; i < count1; i++) nums[i] = 0; // Corrected: = instead of ==
        for(int i = count1; i < count1 + count2; i++) nums[i] = 1; // Corrected: = instead of ==
        for(int i = count1 + count2; i < nums.size(); i++) nums[i] = 2; // Corre



        
    }
};