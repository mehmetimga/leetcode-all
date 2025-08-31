class Solution(object):
    def isPalindrome(self, x):
        if x < 0:
            return False
        s = str(x)
        return s == s[::-1]


if __name__ == "__main__":

    solution = Solution()
    tests = [121, -121, 10, 12321, 0]
    for t in tests:
        print("Input:", t, "=> Output:", solution.isPalindrome(t))
