//Given an unsorted array arr[] of integers, find the number of subarrays whose sum exactly equal to a given number k.


class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // code here
        unordered_map<int, int> prefixCount;
        int currSum = 0, count = 0;

        prefixCount[0] = 1;  

        for (int num : arr) {
            currSum += num;

            
            if (prefixCount.find(currSum - k) != prefixCount.end()) {
                count += prefixCount[currSum - k];
            }

            
            prefixCount[currSum]++;
        }

        return count;
    }
};
