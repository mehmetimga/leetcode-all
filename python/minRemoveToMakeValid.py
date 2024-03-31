class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        balance = 0
        answer = 0
        last = 0
        r = ""
        w = ""
        for i in range(len(s)):
            if s[i] == "(":
                balance += 1
            elif s[i] == ")":
                balance -= 1

            if balance == 1:
                last = i

            if balance == 0:
                if s[i] != ")":
                    r += s[i]
                else:
                    r += w + ")"
                    w = ""

            if balance > 0:
                w += s[i]

            if balance < 0:
                balance = 0
        print (w)
        if len(w) > 0:
            r += w.replace("(", "")

        if balance > 0:
            r1 = r[:last]
            l = balance
            for i in range(last, len(r)):
                if r[i] == "(" and l > 0:
                    l -= 1
                else:
                    r1 += r[i]
            return r1

        return r


if __name__ == "__main__":
    solution = Solution()

    # Test case 1
    print(solution.minRemoveToMakeValid("(lee(t(c)o)de)"))

