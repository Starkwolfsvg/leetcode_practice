class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int, int> mp; // this map will store the number, corresponding index
        for(int i=0; i<n;i++){
            int remaining = target - nums[i];
            if(mp.find(remaining)!= mp.end())
                return {mp[remaining], i}; //ans mil gaya
            mp[nums[i]] =i;
        }
        return {};
    }
};