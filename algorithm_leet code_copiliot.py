# Write binary search for a list of numbers
def search(nums: list, target: int) -> int:
    """
    Find the index of target in nums using binary search.
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
    

# Remove duplicates from a sorted array
def remove_duplicates(nums: list) -> int:
    """
    Remove duplicates from a sorted array
    """
    if len(nums) == 0:
        return 0
    i = 1
    while i < len(nums):
        if nums[i] == nums[i-1]:
            nums.pop(i)
        else:
            i += 1
    return len(nums)

# Find the maximum positive difference between two elements in a list
def max_diff(nums: list) -> int:
    """
    Find the maximum positive difference between two elements in a list
    """
    if len(nums) == 0:
        return 0
    max_diff = 0
    for i in range(len(nums) - 1):
        if nums[i] > 0 and nums[i+1] > 0:
            max_diff = max(max_diff, nums[i] - nums[i+1])
    return max_diff

# Given an array, rotate the array to the right by k steps, where k is non-negative.
def rotate(nums: list, k: int) -> None:
    """
    Given an array, rotate the array to the right by k steps, where k is non-negative.
    """
    if len(nums) == 0:
        return
    k = k % len(nums)
    nums[:] = nums[-k:] + nums[:-k]

# Given an integer array, return true if any value appears at least twice in the array, and false if every element is distinct.
def contains_duplicate(nums: list) -> bool:
    """
    Given an integer array, return true if any value appears at least twice in the array, and false if every element is distinct.
    """
    if len(nums) == 0:
        return False
    nums.sort()
    for i in range(len(nums) - 1):
        if nums[i] == nums[i+1]:
            return True
    return False

def single_number(nums: list) -> int:
    """
    Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
    """
    # XOR 0 with the number, if the number is not repeated, the result is the number
    if len(nums) == 0:
        return 0
    a = 0
    for i in range(len(nums)):
        a = a ^ nums[i]
    return a

# Return an intersection of two lists. Each element in the result must appear as many times as it shows in both arrays 
def intersect(nums1: list, nums2: list) -> list:
    if len(nums1) == 0 or len(nums2) == 0:
        return []
    nums1.sort()
    nums2.sort()
    i = 0
    j = 0
    result = []
    while i < len(nums1) and j < len(nums2):
        if nums1[i] == nums2[j]:
            result.append(nums1[i])
            i += 1
            j += 1
        elif nums1[i] < nums2[j]:
            i += 1
        else:
            j += 1
    return result

# Given a large integer represented in an array, increment the large integer by 1.
def plus_one(digits: list) -> list:
    if len(digits) == 0:
        return []
    carry = 1
    for i in range(len(digits) - 1, -1, -1):
        if digits[i] + carry == 10:
            digits[i] = 0
            carry = 1
        else:
            digits[i] += carry
            carry = 0
    if carry == 1:
        digits.insert(0, 1)
    return digits

# Given an integer array, move all elements containing '0' to the end while maintaining the order of other elements in the array.
def move_zeros(nums: list) -> None:
    """
    Given an integer array, move all elements containing '0' to the end while maintaining the order of other elements in the array.
    """
    if len(nums) == 0:
        return
    i = 0
    j = 0
    while i < len(nums):
        if nums[i] == 0:
            i += 1
        else:
            nums[j] = nums[i]
            i += 1
            j += 1
    while j < len(nums):
        nums[j] = 0
        j += 1

# Given an array of integers, and an integer target return indices of the two numbers such that they add up to a specific target.
def two_sum(nums: list, target: int) -> list:
    """
    Given an array of integers, and an integer target return indices of the two numbers such that they add up to a specific target.
    """
    if len(nums) == 0:
        return []
    d = {}
    for i in range(len(nums)):
        if nums[i] in d:
            return [d[nums[i]], i]
        else:
            d[target - nums[i]] = i
    return []

# Determine if a 9x9 Sudoku board is valid. 
def is_valid_sudoku(board: list) -> bool:
    """
    Determine if a 9x9 Sudoku board is valid. 
    """
    if len(board) != 9 or len(board[0]) != 9:
        return False
    for i in range(9):
        d = {}
        for j in range(9):
            if board[i][j] != '.':
                if board[i][j] in d:
                    return False
                else:
                    d[board[i][j]] = 1
    for j in range(9):
        d = {}
        for i in range(9):
            if board[i][j] != '.':
                if board[i][j] in d:
                    return False
                else:
                    d[board[i][j]] = 1
    for i in range(0, 9, 3):
        for j in range(0, 9, 3):
            d = {}
            for k in range(i, i + 3):
                for l in range(j, j + 3):
                    if board[k][l] != '.':
                        if board[k][l] in d:
                            return False
                        else:
                            d[board[k][l]] = 1
    return True

# Given a nxn 2D matrix, rotate it 90 degrees clockwise.
def rotate_matrix(matrix: list) -> None:
    """
    Given a nxn 2D matrix, rotate it 90 degrees clockwise.
    """
    if len(matrix) == 0:
        return
    n = len(matrix)
    for i in range(n // 2):
        for j in range(i, n - i - 1):
            temp = matrix[i][j]
            matrix[i][j] = matrix[n - 1 - j][i]
            matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j]
            matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i]
            matrix[j][n - 1 - i] = temp

# Write a function to reverse an array of characters.
def reverse_string(s: str) -> None:
    """
    Write a function to reverse an array of characters.
    """
    if len(s) == 0:
        return
    i = 0
    j = len(s) - 1
    while i < j:
        s[i], s[j] = s[j], s[i]
        i += 1
        j -= 1

# Given a signed integer, reverse digits of an integer.
def reverse_integer(x: int) -> int:
    """
    Given a signed integer, reverse digits of an integer.
    """
    sign = 1
    if x == 0:
        return 0
    if x < 0:
        x = -x
        sign = -1
    result = 0
    while x > 0:
        result = result * 10 + x % 10
        x //= 10
    return sign*result if result < 2147483648 else 0

# Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.
def first_uniq_char(s: str) -> int:
    """
    Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.
    """
    if len(s) == 0:
        return -1
    d = {}
    for i in range(len(s)):
        if s[i] in d:
            d[s[i]] += 1
        else:
            d[s[i]] = 1
    for i in range(len(s)):
        if d[s[i]] == 1:
            return i
    return -1

# Given two strings s and t, write a function to determine if t is an anagram of s.
def is_anagram(s: str, t: str) -> bool:
    """
    Given two strings s and t, write a function to determine if t is an anagram of s.
    """
    if len(s) != len(t):
        return False
    d = {}
    for i in range(len(s)):
        if s[i] in d:
            d[s[i]] += 1
        else:
            d[s[i]] = 1
    for i in range(len(t)):
        if t[i] in d:
            d[t[i]] -= 1
        else:
            d[t[i]] = 1
    for i in d:
        if d[i] != 0:
            return False
    return True

# Given a string, return true if it is a palindrome or false otherwise.
def is_palindrome(s: str) -> bool:
    """
    A phrase is a palindrome if, after converting all uppercase letters into lowercase letters
    and removing all non-alphanumeric characters,
    it reads the same forward and backward. Alphanumeric characters include letters and numbers.
    Given a string, return true if it is a palindrome or false if it is not.
    """
    if len(s) == 0:
        return True
    i = 0
    j = len(s) - 1
    while i < j:
        while not s[i].isalnum() and i < j:
            i += 1
        while not s[j].isalnum() and i < j:
            j -= 1
        if s[i].lower() != s[j].lower():
            return False
        i += 1
        j -= 1
    return True

# Implement the myAtoi function. Convert a string to a 32-bit signed integer.
def my_atoi(str: str) -> int:
    """
    Implement the myAtoi function. Convert a string to a 32-bit signed integer.
    """
    if len(str) == 0:
        return 0
    i = 0
    while i < len(str) and str[i] == ' ':
        i += 1
    if i == len(str):
        return 0
    sign = 1
    if str[i] == '+':
        i += 1
    elif str[i] == '-':
        sign = -1
        i += 1
    result = 0
    while i < len(str):
        if str[i].isdigit():
            result = result * 10 + int(str[i])
            i += 1
        else:
            break
    if sign == -1:
        result *= sign
    if result < -2147483648:
        return -2147483648
    elif result > 2147483647:
        return 2147483647
    else:
        return result

# Implement strStr().  
def str_str(haystack: str, needle: str) -> int:
    return haystack.find(needle)

# The count-and-say sequence is the sequence of integers beginning as follows:
# 1, 11, 21, 1211, 111221, ...
# 1 is read off as "one 1" or 11.
# 11 is read off as "two 1s" or 21.
# 21 is read off as "one 2, then one 1" or 1211.
# Given an integer n, generate the nth sequence.
def count_and_say(n: int) -> str:
    if n == 1:
        return '1'
    s = '1'
    for i in range(2, n + 1):
        result = ''
        count = 1
        for j in range(1, len(s)):
            if s[j] == s[j - 1]:
                count += 1
            else:
                result += str(count) + s[j - 1]
                count = 1
        result += str(count) + s[-1]
        s = result
    return s

# Write a function to find the longest common prefix string amongst an array of strings.
def longest_common_prefix(strs: List[str]) -> str:
    if len(strs) == 0:
        return ''
    s = strs[0]
    for i in range(1, len(strs)):
        while strs[i].find(s) != 0:
            s = s[:-1]
    return s

# Delete a node from a linked list, given only access to that node.
def delete_node(node: ListNode) -> None:
    """
    Delete a node from a linked list, given only access to that node.
    """
    node.val = node.next.val
    node.next = node.next.next

# Remove the Nth node from the end of a linked list.
def remove_nth_from_end(head: ListNode, n: int) -> ListNode:
    """
    Remove the Nth node from the end of a linked list.
    """
    if head is None:
        return None
    dummy = ListNode(0)
    dummy.next = head
    slow = dummy
    fast = dummy
    for i in range(n):
        fast = fast.next
    while fast.next is not None:
        fast = fast.next
        slow = slow.next
    slow.next = slow.next.next
    return dummy.next

# Reverse a singly linked list.
def reverse_list(head: Optional[ListNode]) -> Optional[ListNode]:
    """
    Reverse a singly linked list.
    """
    if head is None:
        return None
    prev = None
    curr = head
    while curr is not None:
        next_node = curr.next
        curr.next = prev
        prev = curr
        curr = next_node
    return prev


# Merge two sorted linked lists and return it as a new list.
def mergeTwoLists(l1: ListNode, l2: ListNode) -> ListNode:
    """
    Merge two sorted linked lists and return it as a new list.
    """
    dummy = ListNode(0)
    curr = dummy
    while l1 is not None and l2 is not None:
        if l1.val < l2.val:
            curr.next = l1
            l1 = l1.next
        else:
            curr.next = l2
            l2 = l2.next
        curr = curr.next
    if l1 is not None:
        curr.next = l1
    if l2 is not None:
        curr.next = l2
    return dummy.next

# Recursive solution
def mergeTwoLists(l1: ListNode, l2: ListNode) -> ListNode:
    if not l1: return l2
    elif not l2: return l1
    if l1.val < l2.val:
        l1.next = self.mergeTwoLists(l1.next, l2)
        return l1
    else:
        l2.next = self.mergeTwoLists(l1, l2.next)
        return l2

# Check if a given linked list is a palindrome.
def isPalindrome(self, head: Optional[ListNode]) -> bool:
        reverse = None
        fast = head
        # Reverse the first half part of the list.
        while fast and fast.next:
            fast = fast.next.next
            head.next, reverse, head = reverse, head, head.next
            # head.next = reverse
            # reverse = head
            # head = head.next

        # If the number of the nodes is odd,
        # set the head of the tail list to the next of the median node.
        tail = head.next if fast else head

        # Compare the reversed first half list with the second half list.
        # And restore the reversed first half list.
        is_palindrome = True
        while reverse:
            is_palindrome = is_palindrome and reverse.val == tail.val
            reverse.next, head, reverse = head, reverse, reverse.next
            tail = tail.next

        return is_palindrome

# Given a linked list, determine if the linked list has a cycle in it.
def hasCycle(head: Optional[ListNode]) -> bool:
    """
    Given a linked list, determine if the linked list has a cycle in it.
    """
    if head is None:
        return False
    slow = head
    fast = head
    while fast.next and fast.next.next:
        slow = slow.next
        fast = fast.next.next
        if slow == fast:
            return True
    return False

# Given the root of a binary tree, return its maximum depth
def maxDepth(root: Optional[TreeNode]) -> int:
    """
    Given the root of a binary tree, return its maximum depth.
    """
    if root is None:
        return 0
    return max(maxDepth(root.left), maxDepth(root.right)) + 1

# Given a list of integers, find the index at which the sum of the left half of the list equals the sum of the right half.
def find_pivot(nums: List[int]) -> int:
    """
    Given a list of integers, find the index at which the sum of the left half of the list equals the sum of the right half.
    """
    left_sum = 0
    right_sum = sum(nums)
    for i in range(len(nums)):
        right_sum -= nums[i]
        if left_sum == right_sum:
            return i
        left_sum += nums[i]
    return -1

# Given the root of a binary tree, determine if it is a valid binary search tree (BST).
def isValidBST(root: Optional[TreeNode]) -> bool:
    """
    Given the root of a binary tree, determine if it is a valid binary search tree (BST).
    """
    if root is None:
        return True
    if root.left is not None and root.left.val >= root.val:
        return False
    if root.right is not None and root.right.val <= root.val:
        return False
    return isValidBST(root.left) and isValidBST(root.right)

# Given the root of a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
def isSymmetric(root: Optional[TreeNode]) -> bool:
    """
    Given the root of a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
    """
    if root is None:
        return True
    return is_symmetric(root.left, root.right)

# Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
def levelOrder(root: Optional[TreeNode]) -> List[List[int]]:
    """
    Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
    """
    if root is None:
        return []
    result = []
    queue = [root]
    while queue:
        level = []
        for i in range(len(queue)):
            node = queue.pop(0)
            level.append(node.val)
            if node.left is not None:
                queue.append(node.left)
            if node.right is not None:
                queue.append(node.right)
        result.append(level)
    return result

# Convert a sorted array to a height balanced BST
def sortedArrayToBST(nums: List[int]) -> Optional[TreeNode]:
    """
    Convert a sorted array to a height balanced BST
    """
    if len(nums) == 0:
        return None
    mid = len(nums) // 2
    root = TreeNode(nums[mid])
    root.left = sortedArrayToBST(nums[:mid])
    root.right = sortedArrayToBST(nums[mid+1:])
    return root

# Merge two sorted array into one sorted array in non-decreasing order
def merge(nums1: List[int], m: int, nums2: List[int], n: int) -> None:
    """
    Merge two sorted array into one sorted array in non-decreasing order
    """
    i = m - 1
    j = n - 1
    k = m + n - 1
    while i >= 0 and j >= 0:
        if nums1[i] > nums2[j]:
            nums1[k] = nums1[i]
            i -= 1
        else:
            nums1[k] = nums2[j]
            j -= 1
        k -= 1
    if j >= 0:
        nums1[:j+1] = nums2[:j+1]

# You are climbing a stair case. It takes n steps to reach to the top.
# Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
def climbStairs(n:int) -> int:
    if n == 1:
        return 1
    if n == 2:
        return 2
    return self.climbStairs(n-1) + self.climbStairs(n-2)

def maxProfit(prices: List[int]) -> int:
    """
    You are given an array of integers prices, for which the i-th element is the price of a given stock on day i; and a non-negative integer fee representing a transaction fee.
    You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction. You may not buy more than 1 share of a stock at a time (ie. you must sell the stock share before you buy again.)
    Return the maximum profit you can make.
    """
    if len(prices) < 2:
        return 0
    profit = 0
    low = prices[0]
    for i in range(len(prices) - 1):
        if prices[i] < low: low = prices[i]
        profit = max(prices[i] - low, profit)
    return profit

def maxSubArray(nums: List[int]) -> int:
    """
    Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
    """
    if len(nums) == 0:
        return 0
    max_sum = nums[0]
    cur_sum = nums[0]
    for i in range(1, len(nums)):
        cur_sum = max(nums[i], cur_sum + nums[i])
        max_sum = max(cur_sum, max_sum)
    return max_sum

def rob(nums: List[int]) -> int:
    """
    You are a professional robber planning to rob houses along a street. 
    Each house has a certain amount of money stashed, the only constraint stopping you from robbing
    each of them is that adjacent houses have security systems connected
    and it will automatically contact the police if two adjacent houses were broken into on the same night.
    """
    for i in range(len(nums)):
        if i % 2 == 0:
            odd = max(odd + nums[i], even)
        else:
            even = max(even + nums[i], odd)
    return max(odd, even)

# Shuffle an array of integers
def shuffle(nums: List[int], n: int) -> List[int]:
    """
    Shuffle an array of integers
    """
    if n == 1:
        return nums
    for i in range(n):
        j = random.randint(i, n-1)
        nums[i], nums[j] = nums[j], nums[i]
    return nums

# Add two large numbers given in a linked list
def addTwoNumbers(l1: ListNode, l2: ListNode) -> ListNode:
    """
    Add two large numbers given in a linked list
    """
    carry = 0
    head = ListNode(0)
    cur = head
    while l1 or l2 or carry:
        if l1:
            carry += l1.val
            l1 = l1.next
        if l2:
            carry += l2.val
            l2 = l2.next
        cur.next = ListNode(carry % 10)
        cur = cur.next
        carry //= 10
    return head.next

# Given a string s, find the length of the longest substring without repeating characters.
def lengthOfLongestSubstring(s: str) -> int:
    chars = {}
    start, mx = 0,0
    
    for i in range(len(s)):
        if s[i] in chars and start <= chars[s[i]]:
            start = chars[s[i]] + 1
        else:
            mx = max(mx, i - start + 1)
        chars[s[i]] = i
    return mx

def findMedianSortedArrays(nums1: List[int], nums2: List[int]) -> float:
    """
    Find the median of two sorted arrays
    """
    nums = nums1 + nums2
    nums.sort()
    if len(nums) % 2 == 1:
        return nums[len(nums) // 2]
    return (nums[len(nums) // 2] + nums[len(nums) // 2 - 1]) / 2

# Given an integer x, return true if x is palindrome, otherwise return false.
def isPalindrome(x: int) -> bool:
    return str(x) == str(x)[::-1]

# Given the head of a linked list and an integer value, remove all nodes that has Node.val == value.
def removeElement(head: ListNode, val: int) -> ListNode:
    """
    Given the head of a linked list and an integer value, remove all nodes that has Node.val == value.
    """
    if not head:
        return head
    cur = head
    while cur.next:
        if cur.next.val == val:
            cur.next = cur.next.next
        else:
            cur = cur.next
    if head.val == val:
        return head.next
    return head

# Given an integer array nums of size n, return the minumum number of steps required to make all elements equal. 
# In one step you can increment one of the elements X by 1 or decrement X by 1.
def minMoves2(nums: List[int]) -> int:
    median = sorted(nums)[len(nums) // 2]
    return sum(abs(num - median) for num in nums)

# Given an mxn matrix of distinct numbers, return all lucky numbers in the matrix in any order.
def luckyNumbers(matrix: List[List[int]]) -> List[int]:
    m, n = len(matrix), len(matrix[0])
    min_row = [min(row) for row in matrix]
    min_col = [max(col) for col in zip(*matrix)]
    return [min_row[i] for i in range(m) if min_row[i] in min_col]

# Given the root of a binary tree, return the smallest level x such that the sum of all the values of nodes at level x is the maximum possible.
def maxLevelSum(root: TreeNode) -> int:
    if not root:
            return 0   
    max_level = 0
    queue = []
    queue.append(root)
    levels = []
    
    while queue:
        size = len(queue)
        level = []
        for i in range(size):
            node = queue.pop(0)
            level.append(node.val)
            if node.left: 
                queue.append(node.left)
            if node.right: 
                queue.append(node.right)
        levels.append(sum(level))
    return levels.index(max(levels)) + 1

# Given a string s and an integer k, return the final string after repeated substring removal.
def removeDuplicates(s: str, k: int) -> str:
    stack = [['#', 0]]

    for c in s:
        if stack[-1][0] == c:
            stack[-1][1] += 1
            if stack[-1][1] == k:
                stack.pop()
        else:
            stack.append([c, 1])
    return "".join([c*i for c, i in stack])

# Given an n * n binary matrix image, flip the image horizontally, then invert it, and return the new image.
def flipAndInvertImage(image: List[List[int]]) -> List[List[int]]:
    for row in image:
        row.reverse()
        for i in range(len(row)):
            row[i] = 1 - row[i]
    return image

# Given an array of distinct integers candidates and a target integer target, return a list of all unique 
# combinations of candidates where the chosen numbers sum to target.
# You may return the combinations in any order.
def combinationSum(candidates: List[int], target: int) -> List[List[int]]:
    def dfs(candidates, target, path, res):
            if target == 0:
                res.append(path)
                return
            else:
                for i in range(len(candidates)):
                    if candidates[i] > target:
                        break
                    dfs(candidates[i:], target - candidates[i], path+[candidates[i]], res)   
        
    res = []
    candidates.sort()
    dfs(candidates, target, [], res)
    return res

# Given an array of integers deliciousness where deliciousness[i] is the deliciousness of the i​​​​​​th​​​​​​​​ item of food,
# return the number of different good meals you can make from this list modulo 109 + 7.
def countPairs(deliciousness: List[int]) -> int:
    
    