class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        int right=nums.size()-1;
        for(int i=0;i<nums.size()-1;i++){
            while(i<right){
                if (nums[i]+nums[right]==target){
                    ret.push_back(i);
                    ret.push_back(right);
                    return ret; 
                }
                right--;
            }
            right=nums.size()-1;
        }
        return ret;
    }
};