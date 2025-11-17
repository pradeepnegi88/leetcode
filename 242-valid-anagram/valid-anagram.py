class Solution(object):
    def isAnagram(self, s, t):
        if len(s) != len(t):
            return False
        # a = dict()
        # b = dict()
        # for i in range(len(s)):
        #     a[s[i]] = 1 + a.get(s[i],0)
        #     b[t[i]] = 1 + b.get(t[i],0)

        # if a == b:
        #     return True
        # else:
        #     return False      
        a = [0]*26
        for i in range(len(s)):
            a[ord(s[i]) - ord('a')] +=1
            a[ord(t[i]) - ord('a')] -=1
        for i in a:
            if i != 0:
                return False
        return True              



        