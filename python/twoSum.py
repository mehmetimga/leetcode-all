class Solution(object):
    def twoSum(self, nums, target):
        prev = {}
        for i, num in enumerate(nums):
            diff = target - num
            if diff in prev:
                return [prev[diff], i]
            prev[num] = i
        return []


if __name__ == '__main__':
    nums = [2, 7, 11, 15]
    target = 9
    result = Solution().twoSum(nums, target)
    print("Input:", nums, "Target:", target)
    print("Output:", result)
