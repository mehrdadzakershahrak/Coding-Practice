def Palindrome(str):
    
    str = "".join(str.split(" ")).lower()
    
    rev = ''.join(reversed(str))
    
    if str == rev:
        return 'true'
    else:
        return 'false'