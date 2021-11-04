# Write binary search for a list of numbers
def search(nums: list, target: int) -> int:
    """
    Find the index of target in nums
    :param nums: list of numbers
    :param target: target number
    :return: index of target in nums
    """
    left = 0
    right = len(nums) - 1
    while left <= right:
        mid = (left + right) // 2
        if nums[mid] == target:
            return mid
        elif nums[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return -1
    

