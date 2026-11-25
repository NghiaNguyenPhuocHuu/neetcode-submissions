class Solution {
public:
    vector <int> track;
    // Found turn into 0
    bool smallCheck (vector <int>& track) {
        int cur = 0;
        for (int i = 0; i < 26; i++)    cur |= track[i];
        return cur == 0;
    }
    bool checkInclusion(string s1, string s2) {
        const int n1 = s1.size(), n2 = s2.size();
        if (n1 > n2)    return false;
        track.resize(26, 0);
        
        for (int i = 0; i < n1; i++) {
            track[s1[i] - 'a']++;
            track[s2[i] - 'a']--;
        }
        if (smallCheck(track)) return true;

        for (int i = 0; i < n2 - n1; i++) {
            track[s2[i] - 'a']++;
            track[s2[i + n1] - 'a']--;
            if (smallCheck(track)) return true;
        }

        return false;
    }
};
