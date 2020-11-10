def ArrayAdditionI(arr):
    
    largest = max(arr)
    arr.remove(largest)
    
    sets = [[]]
    
    for i in range(0, len(arr)):
        sets_len = len(sets)
        for j in range(0, sets_len):
            temp = sets[j] + [arr[i]]
            sets.append(temp)
            if sum(temp) == largest:
                return "true"
                
    return "false"