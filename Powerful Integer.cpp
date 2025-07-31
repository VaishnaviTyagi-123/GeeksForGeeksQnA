//You are given a 2D integer array intervals[][] of length n, where each intervals[i] = [start, end] represents a closed interval (i.e., all integers from start to end, inclusive). You are also given an integer k. An integer is called Powerful if it appears in at least k intervals. Find the maximum Powerful Integer.







class Solution {
  public:
    int powerfulInteger(vector<vector<int>>& intervals, int k) {
        map<int, int> events;

   
    for (auto& interval : intervals) {
        events[interval[0]] += 1;
        events[interval[1] + 1] -= 1;
    }

    int count = 0;
    int maxPowerful = -1;
    int activeStart = -1;

    for (auto& [point, delta] : events) {
        count += delta;

    
        if (count >= k && activeStart == -1) {
            activeStart = point;
        }

     
        if (count < k && activeStart != -1) {
            maxPowerful = max(maxPowerful, point - 1); 
            activeStart = -1;
        }
    }

    return maxPowerful;
    }
};
