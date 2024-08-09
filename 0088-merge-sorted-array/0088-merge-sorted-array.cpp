class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> tempVector;
        for(int i=0; i<m; i++)
        {
            tempVector.push_back(nums1[i]); //inserting all the elements of nums1 into the temporary vector
        }

        for(int i=0; i<n; i++)
        {
            tempVector.push_back(nums2[i]);
        }

        sort(tempVector.begin(), tempVector.end());
        nums1 = tempVector;
    }
};