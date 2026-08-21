class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        a=0
        b=int(sqrt(c))
        while a<=b:
            temp1=a*a
            temp2=b*b
            if temp1+temp2==c:
                return True
            elif temp1+temp2>c:
                b-=1
            else:
                a+=1
        return False