class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] == val) {
                nums.erase(nums.begin() + i); // Remove the element at index i
            } else {
                i++; // Only increment i if no removal occurred
            }
        }
        return nums.size(); // Return the new size of the vector
    }
};
