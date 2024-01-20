class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        unordered_map<int,int> prev;
        for(int i=0;i<nums.size();i++){
            if (prev.find(target-nums[i])!=prev.end()){
                ret.push_back(i);
                ret.push_back(prev[target-nums[i]]);
                return ret;
            }else{
                prev[nums[i]]=i;
            }
        }
        return ret;
    }
};