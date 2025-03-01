class Solution(object):
    def isAnagram(self, s, t):
        if len(s) != len(t):
            return False
        a = dict()
        b = dict()
        for i in range(len(s)):
            a[s[i]] = 1+ a.get(s[i],0)    
            b[t[i]] = 1+ b.get(t[i],0)    
        return a == b    

     
        