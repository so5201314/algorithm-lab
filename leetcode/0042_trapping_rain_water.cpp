#include <algorithm>
#include <vector>

class Solution {
public:
    int trap(std::vector<int>& height)
    {
        const int n = static_cast<int>(height.size());
        int left = 0;
        int right = n - 1;
        int leftMax = 0;
        int rightMax = 0;
        int result = 0;

        while (left < right)
        {
            if (height[left] <= height[right])
            {
                leftMax = std::max(leftMax, height[left]);
                result += leftMax - height[left];
                ++left;
            }
            else
            {
                rightMax = std::max(rightMax, height[right]);
                result += rightMax - height[right];
                --right;
            }
        }

        return result;
    }
};
