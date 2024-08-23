class Solution {
public:
    string fractionAddition(string expression) {
        std::istringstream iss(expression);
        int num=0, den=1, num2, den2;
        char op, slash;

        while(iss >> num2 >> slash >> den2)
        {
            if(slash != '/'){
                iss.unget();
                iss >> op >> num2 >> slash >> den2;

            }
            num = num * den2 + num2 * den;
            den *= den2;
            int gcd = std::gcd(abs(num), den);
            num /= gcd;
            den /= gcd;
        }
        return std::to_string(num) + "/" + std::to_string(den);
    }
};