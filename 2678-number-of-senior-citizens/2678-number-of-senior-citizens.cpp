class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        
        for (const std::string& detail : details) {
            // Extract the age substring and convert it to an integer
            int age = std::stoi(detail.substr(11, 2));
            
            // Check if the age is greater than 60
            if (age > 60) {
                count++;
            }
        }
        
        return count;
    }
};