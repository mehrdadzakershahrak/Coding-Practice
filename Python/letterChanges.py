
def LetterChanges(str): 

    newString = ""
    
    for char in str:
        if char.isalpha():
            if char.lower() == 'z':
                char = 'a'
            else:
                char = chr(ord(char) + 1)
        if char in 'aeiou':
            char = char.upper()
        
        newString = newString + char
    
    return newString


print LetterChanges("Hello World!")