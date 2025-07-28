//Minimum number of operations needed to make a square matrix beautiful


class Solution {
  public:
    int balanceSums(vector<vector<int>>& mat) {
        // code here
        int maxsum = INT_MIN;
        int sum1 = 0,sum2 = 0,ans=0;
        int n = mat.size();
        for(int i=0;i<n;++i){
            sum1=0,sum2=0;
            for(int j=0;j<n;++j){
                sum1 += mat[i][j];
                sum2 += mat[j][i];
            }
            maxsum = max({maxsum,sum1,sum2});
        }
        

        for(int i=0;i<n;++i){
            int num=0;
            for(int j=0; j<n; ++j){
                num += mat[i][j];
            }
            ans += (maxsum-num);
        }
        return ans;
    }
};
