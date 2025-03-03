class Solution(object):
    def isPalindrome(self, s):
        n = ""
        for i in s:
            if i.isalnum():
                n+=i.lower()
        return n == n[::-1]        
        # l = 0
        # r = len(s)-1
        # while l<r:
        #     while l<r and not s[l].isalnum():
        #         l+=1
        #     while r>l and not s[r].isalnum():
        #         r-=1
        #     if s[l].lower() != s[r].lower():
        #         return False
        # return True                
       
        