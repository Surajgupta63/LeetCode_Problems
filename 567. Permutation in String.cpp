//// Approach Sliding Window
// T.C : O(n)
// S.C : O(n)
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        unordered_map<char, int> mp;

        for(char &ch: s1){
            mp[ch]++;
        }

        int i=0,j=0;
        int count = m;
        
        while(j < n){
            char ch = s2[j];
            if(mp[ch] > 0){
                count--;
            }
            mp[ch]--;

            if(j-i+1 == m){
                if(count == 0) return true;
                mp[s2[i]]++;
                if(mp[s2[i]] > 0){
                    count++;
                }
                i++;
            }
            j++;
        
        }

        return false;
        

        return true;
    }
};
