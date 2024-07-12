class Solution {
public:

int xorr(vector<int>&nums){
    int ans = 0;
    for(int i=0; i<nums.size(); i++){
        ans^= nums[i];                     // We used XOR operation to find the missing number in the array .
    }

    int n=nums.size();

    for(int i=0; i<=n; i++){
        ans^=i;
    }
    return ans;
}

    int missingNumber(vector<int>& nums) {
        return xorr(nums);
    }
};
