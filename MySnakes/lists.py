def arrInsert(arr, arg1, arg2):
    arr.insert(arg1,arg2)
    
    
def arrRemove(arr,arg1, arg2):
    if arr.count(arg1) > 0:
        arr.remove(arg1)
    
    
def arrAppend(arr,arg1, arg2):
    arr.append(arg1)
    
    
def arrSort(arr,arg1, arg2):
    arr.sort()
    
    
def arrPop(arr,arg1, arg2):
    if (len(arr) > 0):
        arr.pop()
    
    
def arrRev(arr,arg1, arg2):
    arr.reverse()
    
    
def arrPrint(arr,arg1, arg2):
    print arr
    

    
if __name__ == '__main__':
    N = int(raw_input())
    arr = list()
    for i in range(N):
        inp = raw_input().split()
        cmd = inp[0]
        options = {"insert": arrInsert,
                   "print": arrPrint,
                   "remove": arrRemove,
                   "append": arrAppend,
                   "sort": arrSort,
                   "pop": arrPop,
                   "reverse": arrRev,
        }
        
        arg1 = 0
        arg2 = 0
        if (len(inp) > 1) :
            arg1 = int(inp[1])
        if (len(inp) > 2) :
            arg2 = int(inp[2])
        options[cmd](arr, arg1, arg2)
    
