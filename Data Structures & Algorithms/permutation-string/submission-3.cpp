class Solution {
public:
    
    bool checkInclusion(string s1, string s2) {
        const int n1 = s1.size(), n2 = s2.size();
        if (n1 > n2) return false;

        array<int, 26> cnt{};
        for (int i = 0; i < n1; i++) {
            cnt[s1[i] - 'a']++;
            cnt[s2[i] - 'a']--;
        }

        int matches = 0;                      // letters whose count is 0
        for (int c : cnt) matches += (c == 0);
        if (matches == 26) return true;

        // Change one letter's count and keep `matches` in sync.
        auto update = [&](char ch, int delta) {
            int& c = cnt[ch - 'a'];
            if (c == 0) matches--;            // it was balanced, now it won't be
            c += delta;
            if (c == 0) matches++;            // it just became balanced
        };

        for (int i = n1; i < n2; i++) {
            update(s2[i - n1], +1);           // char leaving the window
            update(s2[i],      -1);           // char entering the window
            if (matches == 26) return true;
        }
        return false;
    }
};
