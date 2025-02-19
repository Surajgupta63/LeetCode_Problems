//// Approach Sliding Window
// T.C : O(n)
// S.C : O(1)
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();

        long long ans = 0;

        int minKPos = -1;
        int maxKPos = -1;
        int culpritPos = -1;

        for(int i=0; i<n; i++){
            if(nums[i] < minK || nums[i] > maxK){
                culpritPos = i;
            }
            if(nums[i] == minK){
                minKPos = i;
            }
            if(nums[i] == maxK){
                maxKPos = i;
            }

            int smaller = min(minKPos, maxKPos);

            int temp = smaller - culpritPos;

            ans += temp < 0 ? 0 : temp; 
        }

        return ans;
    }
};
