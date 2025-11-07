class Solution:
    def search(self, pat, txt):
        res = []
        n, m = len(txt), len(pat)
        for i in range(n - m + 1):
            if txt[i:i + m] == pat:
                res.append(i + 1)
        return res
