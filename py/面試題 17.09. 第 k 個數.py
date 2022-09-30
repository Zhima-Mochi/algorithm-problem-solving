class Solution:
    def getKthMagicNumber(self, k: int) -> int:
        records = [0]*(k+1)
        records[1] = 1
        use = [1, 1, 1]
        for i in range(2, k+1):
            num1 = records[use[0]]*3
            num2 = records[use[1]]*5
            num3 = records[use[2]]*7
            minVal = min(num1, num2, num3)
            records[i] = minVal
            if num1 == minVal:
                use[0] += 1
            if num2 == minVal:
                use[1] += 1
            if num3 == minVal:
                use[2] += 1
        return records[-1]
