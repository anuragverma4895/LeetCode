class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq={}
        for x in nums:
            freq[x]=freq.get(x,0)+1
        freq = sorted(freq.items(), key=lambda x: x[1], reverse=True)

        return [x[0] for x in freq[:k]]