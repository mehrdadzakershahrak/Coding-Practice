def outerTrees(self, points: List[List[int]]) -> List[List[int]]:
    # Function to get the slope
    def get_slope(p1, p2):
        if p1[0] == p2[0]:
            return float('inf')
        else:
            return 1.0*(p1[1]-p2[1])/(p1[0]-p2[0])

    # Function to get the cross product
    def get_cross_product(p1,p2,p3):
        return ((p2[0] - p1[0])*(p3[1] - p1[1])) - ((p2[1] - p1[1])*(p3[0] - p1[0]))

    # Function to get the Euclidean distance
    def get_distance(p1, p2):
        return ((p1[0] - p2[0])**2 + (p1[1] - p2[1])**2)**0.5

    points.sort(key=lambda x:[x[0],x[1]])
    start = points.pop(0)
    hull = [start]

    points.sort(key=lambda p: (get_slope(p,start), -get_distance(p, start)))

    for p3 in points:
        hull.append(p3)
        while len(hull) > 2 and get_cross_product(hull[-3],hull[-2],hull[-1]) < 0:
            hull.pop(-2)
    return hull
