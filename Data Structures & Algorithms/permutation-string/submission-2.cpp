class Solution {
public:
    
    bool checkInclusion(string s1, string s2) {
        const int n1 = s1.size(), n2 = s2.size();
        if (n1 > n2)    return false;

        array <int, 26> cnt{};

        for (int i = 0; i < n1; i++) {
            cnt[s1[i] - 'a']++;
            cnt[s2[i] - 'a']--;
        }

        auto allZero = [&] {
            for (int c : cnt)   if (c)  return false;
            return true;
        };

        if (allZero())  return true;

        for (int i = n1; i < n2; i++) {
            cnt[s2[i - n1] - 'a']++;
            cnt[s2[i] - 'a']--;

            if (allZero())  return true;
        }

        return false;
    }
};
