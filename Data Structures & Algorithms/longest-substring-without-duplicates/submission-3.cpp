class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const int n = s.size();

        int ans = 0, l = 0;
        vector <int> freq (256, 0);

        for (int i = 0; i < n; i++) {
            freq[int(s[i])]++;

            while (l < i && freq[int(s[i])] > 1) {
                freq[int(s[l])]--;
                l++;
            }
            // cout << i << ' ' << l << '\n';
            ans = max (ans, i - l + 1);
        }

        return ans;
    }
};
