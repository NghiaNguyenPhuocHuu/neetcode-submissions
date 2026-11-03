class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        found = {}
        for i in range (len(nums)):
            opposite = target - nums[i]
            if opposite in found:
                return [found[opposite], i]

            found[nums[i]] = i
        
        return [-1, -1]
