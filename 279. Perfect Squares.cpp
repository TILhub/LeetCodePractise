
int numSquares(int n){
    if(n<=3)    return n;
    int res=n;
    for(int i=1;i<=sqrt(n);i++)
    {
        if(x*x>n)   break;
        else        res=min(res,numSquares(n-x*x)+1);
    }
    return res;
}

class Solution {
public:
    int numSquares(int n) {
        
        int dp[n + 1], inf = 0x3f3f3f3f;
        memset(dp, inf, sizeof dp);
        if(n<=3)    return n;
        dp[0] = 0; 
        dp[1] = 1; 
        dp[2] = 2; 
        dp[3] = 3; 
        for(int i=4;i<=n;i++){
            dp[i]=i;
            for(int j=1;j<=ceil(sqrt(i));j++){
                int temp=j*j;
                if(temp>i)  break;
                else        dp[i]=min(dp[i],1+dp[i-temp]);
            }
        }
        return dp[n];
    }
};