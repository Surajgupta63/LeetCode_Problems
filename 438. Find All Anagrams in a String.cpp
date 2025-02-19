// Approach Sliding Window
// T.C : O(n)
// S.C : O(26) ~ O(1)
class Solution {
public:
    bool allZeros(vector<int>& freq){
        for(int &f : freq){
            if(f != 0) return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        vector<int> freq(26, 0);

        for(char &ch : p){
            freq[ch - 'a']++;
        }

        int i=0, j=0;
        vector<int> ans;

        while(j < n){
            freq[s[j]-'a']--;

            if(j - i + 1 == p.length()){
                if(allZeros(freq)){
                    ans.push_back(i);
                }

                freq[s[i]-'a']++;
                i++;
            }
            j++;
        }
        return ans;
    }
};
