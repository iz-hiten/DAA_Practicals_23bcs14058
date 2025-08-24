class Solution:
    def countFreq(self, arr):
        #code here
        d = {}
        for x in arr:
            d[x] = d.get(x, 0) + 1
        ans = []
        for k in sorted(d.keys()):
            ans.append([k, d[k]])
        return ans

