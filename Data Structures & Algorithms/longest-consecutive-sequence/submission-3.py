class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        # Aim for the leftmost number -> from there we can pay attention more on the right side
        nums = set(nums)
        res = 0
        for x in nums:
            if x - 1 not in nums:
                y = x + 1
                while y in nums:
                    y += 1
                res = max (res, y - x)
        
        return res
