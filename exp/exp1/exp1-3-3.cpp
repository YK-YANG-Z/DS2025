#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    if (n == 0) return 0;
    int maxArea = 0;
    for (int i = 0; i < n; ++i) {
        int left = i, right = i;
        // 找左边界
        while (left > 0 && heights[left - 1] >= heights[i]) left--;
        // 找右边界
        while (right < n - 1 && heights[right + 1] >= heights[i]) right++;
        // 计算面积并更新最大值
        maxArea = max(maxArea, heights[i] * (right - left + 1));
    }
    return maxArea;
}

void testRandomData() {
    srand(time(0));
    for (int t = 0; t < 10; ++t) {
        int n = rand() % 105 + 1;
        vector<int> heights(n);
        for (int i = 0; i < n; ++i) heights[i] = rand() % 105;
        cout << "测试用例 " << t + 1 << " 高度数组: ";
        for (int h : heights) cout << h << " ";
        cout << "\n最大矩形面积: " << largestRectangleArea(heights) << "\n\n";
    }
}

int main() {
    vector<int> heights1 = {2, 1, 5, 6, 2, 3};
    cout << "示例1 输出: " << largestRectangleArea(heights1) << endl;
    
    vector<int> heights2 = {2, 4};
    cout << "示例2 输出: " << largestRectangleArea(heights2) << endl;
    
    testRandomData();
    return 0;
}