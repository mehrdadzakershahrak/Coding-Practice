def maxArea(self, h: int, w: int, horizontalCuts: List[int], verticalCuts: List[int]) -> int:
    horizontalCuts.sort()
    verticalCuts.sort()
    
    horizontalCuts = [0] + horizontalCuts + [h]
    verticalCuts = [0] + verticalCuts + [w]
    
    max_h = max(horizontalCuts[i] - horizontalCuts[i-1] for i in range(1, len(horizontalCuts)))
    max_w = max(verticalCuts[i] - verticalCuts[i-1] for i in range(1, len(verticalCuts)))
        
    return (max_h * max_w) % (10**9 + 7)
