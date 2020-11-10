def LongestWord(sen):
    
    sen = sen.translate(None, "~!@#$%^&*()-_=+{};:"'<>,./?|`)
    
    array = sen.split(" ")
    return max(array, key=len)