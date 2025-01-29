// Using Stack
// T.C : O(N)
// S.C : O(N)
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int i=0, j=0;
        int n = pushed.size();

        while(i<n && j<n){
            st.push(pushed[i]);
            while(!st.empty() && j < n && st.top() == popped[j]){
                st.pop();
                j++;
            }
            i++;
        }

        return st.empty();
    }
};
