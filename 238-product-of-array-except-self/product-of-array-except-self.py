class Solution(object):
    def productExceptSelf(self, nums):
        n = len(nums)
        ans = [1] * n
        pre = 1
        for i in range(n):
            ans[i] = pre
            pre*= nums[i]

        post = 1
        for j in range(n-1, -1,-1):
            ans[j] *= post
            post*= nums[j]
        return ans        
        
        