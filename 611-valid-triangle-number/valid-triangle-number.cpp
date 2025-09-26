class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        
        int count=0;
        int n = nums.size();
        if(n<3) return 0;
        sort(nums.begin(), nums.end());
        for(int i =0;i<n-1; i++){
            for(int j =i+1; j<n-1 ; j++){
                int sum = nums[i]+nums[j];
                int l = j+1; int r = n-1;
                int k = -1;
                while(l<=r){
                    int mid = l+(r-l)/2;
                    if(sum> nums[mid]){
                        k = mid;
                        l= mid+1;
                        
                    }
                    else if(sum<=nums[mid]){
                        r = mid-1;
                        
                    }
                    
                }
                if(k!=-1){
                    count+= k-j;
                }
            }
        }
        return count;
    }
};