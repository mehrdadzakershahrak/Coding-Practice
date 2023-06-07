def minSubsequence(self, nums: List[int]) -> List[int]:
    nums.sort(reverse=True)
    total_sum = sum(nums)
    subseq_sum = 0
    result = []
    
    for num in nums:
        subseq_sum += num
        result.append(num)
        if subseq_sum > total_sum - subseq_sum:
            break
            
    return result
