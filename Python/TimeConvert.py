import math

def TimeConvert(num):
    
    hours = int(math.floor(num / 60))
    
    minutes = num % 60
    
    return str(hours) + ':' + str(minutes)