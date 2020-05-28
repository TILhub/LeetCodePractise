class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()<=1)  return nums.size();
        vector<int> lis(nums.size(),1);
        int n=nums.size();
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && lis[i]<lis[j]+1)
                    lis[i]=lis[j]+1;
            }
        }
        return *max_element(lis.begin(),lis.end());
    }
};
