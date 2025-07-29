//Given a string s consisting of lowercase English letters, for every character whose first and last occurrences are at different positions, calculate the sum of ASCII values of characters strictly between its first and last occurrence.
//Return all such non-zero sums (order does not matter).


class Solution {
  public:
    vector<int> asciirange(string& s) {
        // code here
         unordered_map<char,int> start;
         unordered_map<char,int> endd;
         int n = s.size();
         for(int i=0;i<s.length();++i){
             if(start.find(s[i]) == start.end()){
                 start[s[i]]=i;
             }
             else{
                 endd[s[i]] = i;
             }
         }
         vector<int> v;
         int sum = 0;
         for(int i=0;i<n;++i){
             sum += (int)s[i];
             v.push_back(sum);
         }
         vector<int> res;
         for(auto it:start){
             char ch = it.first;
             int s = start[ch];
             int e = endd[ch];
             if((e-s)<=1){
                 continue;
             }
             
             int num = v[e-1] - v[s];
             res.push_back(num);
         }
         return res;
         
    }
};
