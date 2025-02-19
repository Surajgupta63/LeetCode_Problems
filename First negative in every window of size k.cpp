// Approach Sliding Window
// T.C : O(n)
// S.C : O(negative numbers)
class Solution {
  public:
    vector<int> FirstNegativeInteger(vector<int>& arr, int k) {
        // write code here
        int n = arr.size();
        
        int i=0, j=0;
        
        queue<int> q;
        vector<int> ans;
        
        while(j < n){
            
            if(arr[j] < 0){
                q.push(arr[j]);
            }
            
            if(j - i + 1 == k){
                if(!q.empty()){
                    ans.push_back(q.front());
                }else{
                    ans.push_back(0);
                }
                
                if(arr[i] < 0){
                    q.pop();
                }
                
                i++;
            }
            j++;
        }
        
        return ans;
    }
};
