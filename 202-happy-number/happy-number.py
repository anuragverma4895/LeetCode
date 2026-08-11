class Solution:
    def isHappy(self, n: int) -> bool:
        seen=set()
        while n>0:
            sum=0
            a=n
            while a>0:
                sum+=pow(a%10,2)
                a//=10
            if sum in seen:
                return False
            seen.add(sum)
            n=sum
            if n==1:
                return True

