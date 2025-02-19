// Approach Sliding Window
//T.C : O(m+n) where m = length of s and n = length of t
//S.C : O(n)
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();

        if(n < t.length()) return "";

        unordered_map<char, int> mp;

        for(char &ch : t){
            mp[ch]++;
        }

        int i=0, j=0;
        int minSize = INT_MAX;
        int count = t.length();

        int start_idx = -1;

        while(j < n){
            char ch = s[j];
            if(mp[ch] > 0){
                count--;
            }

            mp[ch]--;

            while(count == 0){
                int windowSize = j-i+1;

                if(windowSize < minSize){
                    minSize = windowSize;
                    start_idx = i;
                }

                mp[s[i]]++;

                if(mp[s[i]] > 0){
                    count++;
                }
                i++;
            }
            j++;
        }

        return minSize == INT_MAX ? "" : s.substr(start_idx, minSize);
    }
};
