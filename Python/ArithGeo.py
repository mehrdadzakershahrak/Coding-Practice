def ArithGeo(arr):
    
    def arrayDiffs(diff, arr, subtract):
        
        for i in range(2,len(arr)):
            if subtract:
                tempDiff = arr[i] - arr[i-1]
            else:
                tempDiff = arr[i] / arr[i-1]
                
            if (tempDiff != diff):
                return False
                
            elif (i == len(arr) - 1 and tempDiff == diff):
                return True
                
    diffArith = arr[1] - arr[0]
        
    diffGeo = arr[1] / arr[0]
        
    isArithSeq = arrayDiffs(diffArith, arr, True)
        
    if isArithSeq:
            return "Arithmetic"
            
    else:
        isGeoSeq = arrayDiffs(diffGeo, arr, False)
        if isGeoSeq:
            return "Geometric"
        else:
            return -1
                
print ArithGeo([3, 9, 27, 81])  