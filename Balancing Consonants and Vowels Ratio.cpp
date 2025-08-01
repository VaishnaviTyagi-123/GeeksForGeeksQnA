class Solution {
  public:
    
bool isVowel(char c) {
    return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}

long long countBalanced(const vector<string>& arr) {
    unordered_map<long long, long long> freq;
    long long prefix = 0;
    freq[0] = 1;
    long long ans = 0;
    for (int idx = 0; idx < arr.size(); ++idx) {
        const string& s = arr[idx];
        long long vowels = 0;
        for (char c : s) if (isVowel(c)) vowels++;
        long long len = s.size();
        long long diff = 2 * vowels - len; // vowels - consonants
        prefix += diff;

        long long added = freq[prefix];
        ans += added;
        freq[prefix]++;

       
    }
    return ans;
    }
};
