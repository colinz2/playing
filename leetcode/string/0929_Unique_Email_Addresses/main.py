#!/bin/env python3
#coding:utf-8

class Solution:
    def numUniqueEmails(self, emails):
        """
        :type emails: List[str]
        :rtype: int
        """
        seen = set()
        for email in emails:
            sep = email.split("@")
            sep[0] = sep[0].split("+")[0]
            sep[0] = sep[0].replace(".", "")

            seen.add("@".join(sep))
        return len(seen)
        

if __name__ == '__main__':
    emails = ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
    cnt = Solution().numUniqueEmails(emails)
    assert(cnt == 2)