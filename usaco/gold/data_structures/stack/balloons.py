# Pythonized balloons sol
def calculateFinal(balloonPairs: List[List[float]]) -> List[float]:
    n = len(balloonPairs)
    finalRadii = []
    stack = []
    # invariant: blaoonpairs is sorted.
    for x in range(n):
        cx = balloonPairs[x][0]
        r = balloonPairs[x][1]
        while stack:
            px = stack[-1][0]
            pr = stack[-1][1]
            calculatedRadius = (cx-px)**2 / (4*pr)
            r = min(r, calculatedRadius)
            if (r >= pr):
                stack.pop()
            else:
                break
        finalRadii.append(r)
        stack.append([balloonPairs[x][0], r])
    return finalRadii
