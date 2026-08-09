class Solution:
    def isPalindrome(self, s: str) -> bool:
        st=""
        n=len(s)
        for i in range(n):
            ch=s[i]
            if(ch.isalnum()):
                if(ch.isupper()):
                    ch=ch.lower()
                st+=ch
        print(st)
        m=len(st)
        for i in range(0,m//2,1):
            if st[i]!=st[m-i-1]:
                return False
        return True