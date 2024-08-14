class Solution {
public:

// void reverse(char name[], int k) {
//     int s = 0;
//     int e = n-1;

//     while(s<e) {
//         swap(name[s++], name[e--]);
//     }
// }
    void reverseString(vector<char>& s) {
            int start = 0;
            int e = s.size()-1;

            while(start<e) {
             swap(s[start++], s[e--]);
            }
        
        }
};