class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& arr) {
        if(arr.size()<=1)   return arr.size();
        //using LIS
        sort(arr.begin(),arr.end());
        
        vector<int> lis(arr.size()+1,1);
        for(int i=1;i<arr.size();i++){
            for(int j=0;j<i;j++)
                if(arr[i][0] > arr[j][0] && arr[i][1] > arr[j][1] && lis[i]<lis[j]+1)
                    lis[i]=lis[j]+1; 
        }
        return *max_element(lis.begin(),lis.end());
    }
};