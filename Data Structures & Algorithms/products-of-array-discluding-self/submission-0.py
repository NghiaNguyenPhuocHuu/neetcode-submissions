class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [1] * n

        # Step 1: Compute prefix products directly into ans
        # ans[i] will store product of all elements to the left of i
        prefix = 1
        for i in range(n):
            ans[i] = prefix
            prefix *= nums[i]

        # Step 2: Multiply by suffix products moving right to left
        suffix = 1
        for i in range(n - 1, -1, -1):
            ans[i] *= suffix
            suffix *= nums[i]

        return ans
