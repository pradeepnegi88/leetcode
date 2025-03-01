class Solution(object):
    def twoSum(self, nums, target):
        m = dict()
        for i, n in enumerate(nums):
            diff = target - n 
            if diff in m:
                return [m[diff],i]
            m[n] = i    
       
        