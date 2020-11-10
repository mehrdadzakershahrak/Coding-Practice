def FirstFactorial(num):
    factorial = 1
    
    for i in range (1,num+1):
        factorial = factorial * i
        
    return factorial
    
print FirstFactorial(4)