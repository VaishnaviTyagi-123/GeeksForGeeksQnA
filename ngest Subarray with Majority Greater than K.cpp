Given an array arr[] and an integer k, the task is to find the length of longest subarray in which the count of elements greater than k is more than the count of elements less than or equal to k.

Examples:

Input: arr[] = [1, 2, 3, 4, 1], k = 2
Output: 3
Explanation: The subarray [2, 3, 4] or [3, 4, 1] satisfy the given condition, and there is no subarray of length 4 or 5 which will hold the given condition, so the answer is 3.

  class Solution {
  public:

int longestSubarray(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> diff(n);
    for (int i = 0; i < n; ++i) {
        diff[i] = (arr[i] > k) ? 1 : -1;
    }

    unordered_map<int, int> firstIndex;
    int prefixSum = 0, maxLen = 0;

    for (int i = 0; i < n; ++i) {
        prefixSum += diff[i];

        if (prefixSum > 0) {
            maxLen = i + 1;  
        } else {
            if (firstIndex.find(prefixSum - 1) != firstIndex.end()) {
                maxLen = max(maxLen, i - firstIndex[prefixSum - 1]);
            }
        }

        if (firstIndex.find(prefixSum) == firstIndex.end()) {
            firstIndex[prefixSum] = i;
        }
    }

    return maxLen;

    }
};
