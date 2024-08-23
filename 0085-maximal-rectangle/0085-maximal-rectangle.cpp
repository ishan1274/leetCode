class Solution {
public:
    int maximalRectangle(std::vector<std::vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        std::vector<int> heights(cols, 0);
        int maxArea = 0;
        
        for (int i = 0; i < rows; ++i) {
            // Update the histogram heights
            for (int j = 0; j < cols; ++j) {
                heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
            }
            // Calculate the max area for the current histogram
            maxArea = std::max(maxArea, largestRectangleArea(heights));
        }
        
        return maxArea;
    }

private:
    int largestRectangleArea(std::vector<int>& heights) {
        std::stack<int> stack;
        heights.push_back(0); // Add a sentinel value for easy calculation
        int maxArea = 0;
        
        for (int i = 0; i < heights.size(); ++i) {
            while (!stack.empty() && heights[i] < heights[stack.top()]) {
                int height = heights[stack.top()];
                stack.pop();
                int width = stack.empty() ? i : i - stack.top() - 1;
                maxArea = std::max(maxArea, height * width);
            }
            stack.push(i);
        }
        
        return maxArea;
    }
};