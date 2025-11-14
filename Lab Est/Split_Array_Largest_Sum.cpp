class Solution {
    bool possible(vector<int>& nums, int k, int maxSum){
        int cnt=1;
        int currSum=0;
        for(int num:nums) {
            currSum+=num;
            if(currSum>maxSum) {
                cnt++;
                currSum=num;
                if(cnt>k) return false;
            }
        }
        return true;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int l=0, h=0;
        for(int num : nums) {
            l=max(l, num);
            h+=num;
        }
        int ans=h;
        while(l<=h){
            int m=(l+h)/2;
            if(possible(nums, k, m)) {
                ans=m;
                h=m-1;
            } 
            else l=m+1;
        }
        return ans;
    }
};