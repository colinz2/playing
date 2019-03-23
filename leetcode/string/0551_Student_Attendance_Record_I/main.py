!/bin/env python3
#coding:utf-8

class Solution:
    def checkRecord(self, s):
        """
        :type s: str
        :rtype: bool
        """
        return 'LLL' not in s and s.count('A') <= 1


if __name__ == "__main__":
    assert Solution().checkRecord("PPALLP") == True
    assert Solution().checkRecord("PPALLL") == False
    assert Solution().checkRecord("LALL") == True 
    assert Solution().checkRecord("ALLAPPL") == False