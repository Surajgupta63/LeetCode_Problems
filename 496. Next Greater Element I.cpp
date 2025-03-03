// Approach -1 Brute Force
// T.C : O(n*m)
// S.C : O(1)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int n = nums1.size();
        int m = nums2.size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                bool flag = false;
                if(nums1[i] == nums2[j]){
                    for(int k=j+1; k<m; k++){
                        if(nums2[k] > nums1[i]){
                            ans.push_back(nums2[k]);
                            flag = true;
                            break;
                        }
                    }
                    if(!flag){
                        ans.push_back(-1);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

// Approach - 2 Monotonic Stack
// T.C : O(n+m)
// S.C : O(m)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int n = nums1.size();
        int m = nums2.size();

        stack<int> st;
        unordered_map<int, int> mp;

        for(int i=m-1; i>=0; i--){
            while(!st.empty() && nums2[i] > st.top()){
                st.pop();
            }
            
            if(!st.empty() && nums2[i] < st.top()){
                mp[nums2[i]] = st.top();
            }else{
                mp[nums2[i]] = -1;
            }
            st.push(nums2[i]);
        }

        for(int num : nums1){
            ans.push_back(mp[num]);
        }

        return ans;
    }
};
