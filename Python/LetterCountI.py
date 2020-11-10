def LetterCountI(str):
    
    maxl = 1
    res = -1
    for w in str.split():
        for c in w:
            if w.count(c) > maxl:
                maxl = w.count(c)
                res = w
    return res