def ABCheck(str):
    
    str = str.lower()
    
    for i in range(0, len(str)):
        
        if (str[i] == 'a' and i+4 < len(str) and str[i+4] == 'b'):
            return 'true'
            
        if(str[i] == 'b' and i+4 < len(str) and str[i+4] == 'a'):
            return 'true'
            
    return 'false'