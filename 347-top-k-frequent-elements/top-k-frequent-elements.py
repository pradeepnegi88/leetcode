class Solution(object):
    def topKFrequent(self, nums, k):
        count = defaultdict(int)
        freq = defaultdict(list)
        for i in nums:
            count[i] += 1
        for num,value in count.items():
            freq[value].append(num)

        ans = []
        for i in range(len(nums),0,-1):
            if i in freq:
                ans.extend(freq[i])
                if len(ans) >= k:
                    return ans[:k]

  
        