def LetterCapitalizer(str):
    words = str.split(" ")
    
    for i in range(0,len(words)):
        words[i] = words[i][0].upper() + words[i][1:]
        
        return " ".join(words)
        
        " you can use str.title in python"