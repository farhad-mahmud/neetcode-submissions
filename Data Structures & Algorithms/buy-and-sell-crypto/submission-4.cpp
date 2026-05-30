class Solution {
public:
    int maxProfit(vector<int>& prices) {
            int n = prices.size() ;

            int l = 0 ;

            int pr = 0 ;

            if(n==2){
                  int ans = prices[1] - prices[0];

                  return max(0, ans) ;
            }
            int right = n-1 ;
            int ans = 0 ;
            for(int l=n-2;l>=0;l--){

                  int dif = 0 ;
                  if(prices[l] > prices[right]){
                        right = l ;

                  }
                  else {
                       dif = prices[right] - prices[l] ;

                  }

                  ans = max(ans , dif) ;

            }
            
                return ans ;
         
    }
};
