class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int currentCount = 0; int maxi = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]==1)
            {
                currentCount++;
            }
            else
            {
            
                maxi = max(currentCount, maxi);
                currentCount=0;
            }
        }

        return max(maxi, currentCount);


    }
};