class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
         std::sort(target.begin(), target.end());
        std::sort(arr.begin(), arr.end());
        
        // Compare sorted arrays
        return target == arr;
    }
};