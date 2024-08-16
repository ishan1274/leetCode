class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
         int min_val = arrays[0][0];
        int max_val = arrays[0].back();
        int max_distance = 0;

        for (int i = 1; i < arrays.size(); ++i) {
            int curr_min = arrays[i][0];
            int curr_max = arrays[i].back();
            
            // Calculate potential max distances
            max_distance = max(max_distance, abs(curr_max - min_val));
            max_distance = max(max_distance, abs(max_val - curr_min));
            
            // Update global min and max
            min_val = min(min_val, curr_min);
            max_val = max(max_val, curr_max);
        }

        return max_distance;
    }
};