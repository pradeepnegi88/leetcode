class Solution(object):
    def groupAnagrams(self, strs):
        m = defaultdict(list)
        for s in strs:
            c = [0]*26
            for i in s:
                c[ord(i)-ord('a')] += 1
            m[tuple(c)].append(s)
        return list(m.values())        
        
        