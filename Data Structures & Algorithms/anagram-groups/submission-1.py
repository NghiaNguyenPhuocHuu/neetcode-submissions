class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        
        ans = defaultdict(list)
        for takenStr in strs:
            key = "".join(sorted(takenStr))
            ans[key].append(takenStr)
        return list(ans.values())