class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;

        reverse(nums.begin(), nums.end()); // reverses the entire array

        reverse(nums.begin(), nums.begin() + k); // reverses the first k elements

        reverse(nums.begin() + k, nums.end()); // reverses the elements after k elements
    }
};