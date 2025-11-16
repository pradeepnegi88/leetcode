class Solution(object):
    def containsDuplicate(self, nums):
        # for i in range(0,len(nums)):
        #     for j in range(i+1,len(nums)):
        #         if nums[i] == nums[j]:
        #             return True
        # return False      
        # nums = sorted(nums)
        # for i in range(1, len(nums)):
        #     if nums[i] == nums[i-1]:
        #         return True
        # return False      
        # s = set()
        # for i in  nums:
        #     if i in s:
        #         return True
        #     s.add(i)
        # return False    
        s = set(nums)
        if len(s) < len(nums):
            return True
        else:
            return False                

        