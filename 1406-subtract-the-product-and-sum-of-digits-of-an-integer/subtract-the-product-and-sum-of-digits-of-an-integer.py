class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        add=0
        product=1
        while n>0:
            r=n%10
            add=add+r
            product=product*r
            n=n//10
        return product-add