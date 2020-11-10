def VowelCount(str): 
    
    str = str.lower()
    
    count  = 0
    
    for i in range(0, len(str)):
        
        if str[i] in 'aeiou':
            count = count + 1
    return count