class Solution {
public:
    static bool compare(string &a, string &b) {
        return a + b > b + a;
    }
    
    string largestNumber(vector<int>& nums) {
        // Convert all numbers to strings
        vector<string> numStrings;
        for (int num : nums) {
            numStrings.push_back(to_string(num));
        }
        
        // Sort the strings based on the custom comparator
        sort(numStrings.begin(), numStrings.end(), compare);
        
        // If the largest number is "0", then all numbers are zero
        if (numStrings[0] == "0") {
            return "0";
        }
        
        // Join the sorted strings to form the largest number
        string result;
        for (string &numStr : numStrings) {
            result += numStr;
        }
        
        return result;
    }
};