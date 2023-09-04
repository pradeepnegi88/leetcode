class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // int left = 0;
        // int right = numbers.size()-1;
        // vector<int> ans;
        // while(left<right){
        //     if(numbers[left]+numbers[right] == target){
        //         ans.push_back(left+1);
        //         ans.push_back(right+1);
        //        break;
        //     }else if (numbers[left]+numbers[right]>target){
        //         right--;
        //     }else{
        //         left++;
        //     }
        // }
        // return ans;

        unordered_map<int,int> m;
        vector<int> ans;

        for (int i = 0;i<numbers.size();i++){
            if(m.count(numbers[i])){
              ans.push_back(m[numbers[i]]);
              ans.push_back(i+1);
              break;
            }else{
                m[target-numbers[i]] = i+1;
            }

        }
        return ans;
    }
};