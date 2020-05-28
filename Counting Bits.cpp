class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans;
        for(int i=0;i<=num;i++)
            ans.push_back(__builtin_popcount(i));
        return ans;
    }
};

class Solution {
public:
    vector<int> countBits(int num) {
        
        if(num==0)  return {0};
        if(num==1)  return {0,1};
        vector<int> ans(num+1,0);
        ans[1]=1;
        for(int i=2;i<=num;i++){
            if(i%2==0)  ans[i]=ans[i/2];
            else        ans[i]=ans[i-1]+1;
            
        }
        return ans;
    }
    
};