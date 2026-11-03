class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # Key Resource: Counter -> return a dictionary
        # Dictionary -> list with most frequent: using name.most_common(number)
        # List Comprehension: [item for item, count in *[list]]
        cnt = Counter(nums)
        return [item for item, count in cnt.most_common(k)]
        