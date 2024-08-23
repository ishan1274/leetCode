class Solution {
public:
    int minSwaps(vector<int>& nums) {
          int n = nums.size();
        int totalOnes = 0;
        
        // Step 1: Count the total number of 1's in the array
        for (int num : nums) {
            if (num == 1) {
                totalOnes++;
            }
        }
        
        // If there are no 1's, no swaps are needed
        if (totalOnes == 0) {
            return 0;
        }
        
        // Step 2: Create the extended array for circular handling
        nums.insert(nums.end(), nums.begin(), nums.end());
        
        // Step 3: Use sliding window of size totalOnes to find the minimum swaps
        int minSwaps = totalOnes; // Maximum number of swaps could be totalOnes
        int currentZeros = 0;
        
        for (int i = 0; i < totalOnes; i++) {
            if (nums[i] == 0) {
                currentZeros++;
            }
        }
        
        minSwaps = std::min(minSwaps, currentZeros);
        
        for (int i = totalOnes; i < 2 * n; i++) {
            // Slide the window: Remove the element going out of the window and add the new element coming in
            if (nums[i] == 0) {
                currentZeros++;
            }
            if (nums[i - totalOnes] == 0) {
                currentZeros--;
            }
            
            minSwaps = std::min(minSwaps, currentZeros);
        }
        
        return minSwaps;
    }
};