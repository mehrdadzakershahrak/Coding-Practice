def SecondGreatLow(arr):
    
    unique  = set(arr)
    
    sortedList = sorted(unique)
    
    if len(sortedList) < 2:
        return str(sortedList[0]) + " "  + str(sortedList[0])
    else:
        return str(sortedList[1]) + " " + str(sortedList[len(sortedList) - 2])