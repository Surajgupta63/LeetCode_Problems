// Approach Binary Search
// T.C : O(log(n))
// S.C : O(1)
class Solution {
public:

    int findPivot(vector<int>& nums){
        int s = 0;
        int e = nums.size()-1;

        while(s < e){
            int mid = s + (e-s)/2;
            if(nums[mid] > nums[e]){
                s = mid+1;
            }else{
                e = mid;
            }
        }

        return e;
    }

    int BS(int s, int e, vector<int>& nums, int target){
        int idx = -1;

        while(s <= e){
            int mid = s + (e-s)/2;
            if(nums[mid] == target){
                idx = mid;
                break;
            }else if(nums[mid] < target){
                s = mid+1;
            }else{
                e = mid-1;
            }
        }
        return idx;
    }

    int search(vector<int>& nums, int target) {
        
        int pivot = findPivot(nums);

        int idx = BS(0, pivot-1, nums, target);

        if(idx != -1) return idx;

        idx = BS(pivot, nums.size()-1, nums, target);

        return idx;

    }
};
