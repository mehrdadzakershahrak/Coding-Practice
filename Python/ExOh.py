def ExOh(str):
    
    x = "".join(str.split("x"))
    
    o = "".join(str.split("o"))
    
    if len(x) == len(o):
        return 'true'
    else:
        return 'false'