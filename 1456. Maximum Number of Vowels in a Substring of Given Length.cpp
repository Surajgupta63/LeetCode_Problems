//// Approach Sliding Window
// T.C : O(n)
// S.C : O(1)
class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.length();

        int i=0, j=0;
        int maxCountVowel = INT_MIN;
        int countVowel  = 0;

        while(j < n){

            char ch = s[j];

            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                countVowel++;
            }

            if(j-i + 1 == k){
                maxCountVowel = max(maxCountVowel, countVowel);
                if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                    countVowel--;
                }
                i++;
            }
            j++;
        }

        return maxCountVowel == INT_MIN ? 0 : maxCountVowel;
    }
};
