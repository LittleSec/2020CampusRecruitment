#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<int>& nums, vector<bool>& visited, int cursum, int target, int start, int k) {
    if (k == 1) {
        return true;
    }
    if (cursum > target) {
        return false;
    }
    if (cursum == target) {
        return dfs(nums, visited, 0, target, 0, k-1);
    }
    else {
        for (int i = start; i < nums.size(); i++) {
            if (visited[i]) {
                continue;
            }
            visited[i] = true;
            if (dfs(nums, visited, cursum+nums[i], target, i+1, k)) {
                return true;
            }
            else {
                visited[i] = false;
            }
        }
    }
    return false;
}

int main () {
    vector<int> nums({4, 3, 2, 3, 5, 2, 1});
    int k = 4;
    
    vector<bool> visited(nums.size());
    int sum = 0;
    for (int n : nums) {
        sum += n;
    }
    if (sum % k != 0) {
        cout << false << endl;
    }
    else {
        cout << dfs(nums, visited, 0, sum/k, 0, k) << endl;
    }
    return 0;
}