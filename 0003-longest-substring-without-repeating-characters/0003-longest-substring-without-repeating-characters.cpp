class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
         std::unordered_set<char> seen;
        int left = 0, right = 0;
        int max_length = 0;
        
        while (right < s.size()) {
            if (seen.find(s[right]) == seen.end()) {
                seen.insert(s[right]);
                max_length = std::max(max_length, right - left + 1);
                ++right;
            } else {
                seen.erase(s[left]);
                ++left;
            }
        }
        
        return max_length;
        
    }
};