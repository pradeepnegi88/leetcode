class Solution {
public:
    void solve(vector<int>&arr,int n,int idx,int prev_idx,vector<int>&ans,vector<int>&output){
        if(idx == n){
            if(output.size()>ans.size()){
                ans = output;
            }
            return;
        }

        if(prev_idx == -1 || arr[idx]%prev_idx==0){
            output.push_back(arr[idx]);
            solve(arr,n,idx+1,arr[idx],ans,output);
            output.pop_back();
        }
            solve(arr,n,idx+1,prev_idx,ans,output);
        
    }
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n = arr.size();

        sort(arr.begin(),arr.end());
        // vector<int>ans;
        // vector<int>output;
        // solve(arr,n,0,-1,ans,output);
        // return ans;


    vector<int> dp(n, 1), hash(n), ans;

    sort(arr.begin(), arr.end());

    // ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    // hash[0]=0;

    int longind=0, maxi=1;

    for (int i=1; i<n; i++){

        hash[i]=i;

        for(int j=0; j<i; j++){

            if (arr[i]%arr[j]==0 && dp[i]<dp[j]+1){

                dp[i]=dp[j]+1;

                hash[i]=j;

            }

        }

        if (dp[i]>maxi){

            maxi=dp[i];

            longind=i;

        }

    }

    ans.push_back(arr[longind]);

    while (hash[longind]!=longind){

        longind=hash[longind];

        ans.push_back(arr[longind]);

    }

    return ans;
    }
};