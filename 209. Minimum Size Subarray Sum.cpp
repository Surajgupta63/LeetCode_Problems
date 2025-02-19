// Approach Sliding Window
// T.C : O(n)
// S.C : O(1)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i=0, j=0;

        int sum = 0;
        int minAns = INT_MAX;

        while(j < n){
            sum += nums[j];

            while(sum >= target){
                minAns = min(minAns, j-i+1);

                sum -= nums[i];
                i++;
            }
            j++;
        }

        return minAns == INT_MAX ? 0 : minAns;
    }
};
