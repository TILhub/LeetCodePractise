class Solution {
public:
    int findLongestChain(vector<vector<int>>& arr) {
        if(arr.size()<=1)   return arr.size();
        //using LIS
        sort(arr.begin(),arr.end());
        
        vector<int> lis(arr.size()+1,1);
        for(int i=1;i<arr.size();i++){
            for(int j=0;j<i;j++)
                if(arr[j][1] < arr[i][0]  && lis[i]<lis[j]+1)
                    lis[i]=lis[j]+1; 
        }
        return *max_element(lis.begin(),lis.end());
    }
};