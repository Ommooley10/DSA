//GOOD PROBLEM TO UNDERSTAND PREFIX AND SUFFIX SUM OR PRODUCT
#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        std::vector<int> ans;
        std::vector<long long> prefix; // Use long long to avoid overflow
        std::vector<long long> postfix; // Use long long to avoid overflow
        int n = nums.size();
        postfix.resize(n);
        long long pre = 1;
        long long post = 1;
        long long res;

        // Calculate prefix products
        for (int i = 0; i < n; i++) {
            pre = pre * nums[i];
            prefix.push_back(pre);
        }

        // Calculate postfix products
        for (int i = n - 1; i >= 0; i--) {
            post = post * nums[i];
            postfix[i] = post;
        }

        // Calculate the result using prefix and postfix
        for (int i = 0; i < n; i++) {
            res = 0;
            if (i == 0) {
                res = 1 * postfix[i + 1];
            } else if (i == n - 1) {
                res = prefix[i - 1] * 1;
            } else {
                res = prefix[i - 1] * postfix[i + 1];
            }
            ans.push_back(res);
        }
        return ans;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {1, -2, -100, 5, 7}; // Example input
    std::vector<int> result = solution.productExceptSelf(nums);

    // Output the result
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}