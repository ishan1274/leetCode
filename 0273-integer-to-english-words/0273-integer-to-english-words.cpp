class Solution {
public:
   class Solution {
public:
    std::string numberToWords(int num) {
        if (num == 0) return "Zero";

        std::string result;
        std::vector<std::string> thousands = {"", "Thousand", "Million", "Billion"};

        std::unordered_map<int, std::string> belowTwenty = {
            {0, ""}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"},
            {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"}, {10, "Ten"},
            {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"},
            {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"},
            {19, "Nineteen"}
        };
        
        std::unordered_map<int, std::string> tens = {
            {0, ""}, {2, "Twenty"}, {3, "Thirty"}, {4, "Forty"}, {5, "Fifty"},
            {6, "Sixty"}, {7, "Seventy"}, {8, "Eighty"}, {9, "Ninety"}
        };

        std::string convertBelowHundred(int num) {
            if (num < 20) return belowTwenty[num];
            int ten = num / 10;
            int remainder = num % 10;
            return tens[ten] + (remainder ? " " + belowTwenty[remainder] : "");
        }
        
        std::string convertBelowThousand(int num) {
            if (num < 100) return convertBelowHundred(num);
            int hundred = num / 100;
            int remainder = num % 100;
            return belowTwenty[hundred] + " Hundred" + (remainder ? " " + convertBelowHundred(remainder) : "");
        }
        
        for (int i = 0; num > 0; i++) {
            if (num % 1000 != 0) {
                result = convertBelowThousand(num % 1000) + (thousands[i].empty() ? "" : " " + thousands[i]) + (result.empty() ? "" : " " + result);
            }
            num /= 1000;
        }
        
        return result;
    }
};