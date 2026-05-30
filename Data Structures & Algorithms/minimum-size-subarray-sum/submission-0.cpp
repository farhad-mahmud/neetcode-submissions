class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
          int n = nums.size();
          int min_len = n+1 ;
          int cur_sum = 0 ;
          int l = 0 ;

          for(int r =0;r<n;r++){
               cur_sum += nums[r] ;

               while(cur_sum >= target){
                   min_len = min(min_len , (r- l + 1)) ;
                   cur_sum -= nums[l] ;
                   l++ ;
               }
          }

          if(min_len > n){
              return 0 ;
          }
          else{
             return min_len ;
          }
    }
};