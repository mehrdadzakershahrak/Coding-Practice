def subsetsum(target, arr):
    if len(arr) == 0:
        return target == 0

    return subsetsum(target, arr[1:]) or subsetsum(target - arr[0], arr[1:])
    
def ArrayAdditionII(arr):

    arr = sorted(arr)
    target = arr[-1]
    arr = arr[:-1]
    if subsetsum(target, arr):
        return 'true' 
    else:
        return 'false'
    
print ArrayAdditionII([1,2,3,6])