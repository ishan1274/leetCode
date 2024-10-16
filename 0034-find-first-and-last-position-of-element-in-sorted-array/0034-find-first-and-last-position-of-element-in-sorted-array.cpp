class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int startPosition = -1; int endPosition = -1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==target){
                startPosition = i;
                break;
            }
        }

        for(int i=nums.size()-1; i>=0; i--){
            if(nums[i]==target){
                endPosition = i;
                break;
            }
        }

        return {startPosition, endPosition};
    }
};