
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        vector<int> hash(n,1);
        int length = 0;
        for(int i = 0;i<n;i++){
            if(temp.empty()|| temp.back()<nums[i]){
                temp.push_back(nums[i]);
                hash[i] = temp.size();
                length++;
            }else{
                auto index = lower_bound(temp.begin(),temp.end(),nums[i]);
                *index = nums[i];
                hash[i] = index-temp.begin()+1;
            }
        }
        vector<int> ans;
        int currIndex = length;

        for(int i = n-1;i>=0;i--){
        if(hash[i] == currIndex){
            ans.push_back(nums[i]);
            currIndex--;
        }
        }
        reverse(ans.begin(),ans.end());
        for(auto it:ans){
            cout<< it<<" , ";
        }
        return length;
    }
};