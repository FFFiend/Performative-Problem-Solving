x, n = map(int, input().split())
arr = list(map(int, input().split()))
import heapq
h = []
for x in arr:
	heapq.heappush(h, x)
cost = 0
# read proof for why ts is optimal and greedy maxheap strat wasnt?
while len(h) >= 2:
	first = heapq.heappop(h)
	second = heapq.heappop(h)
	cost += first + second
	heapq.heappush(h,first+second)
print(cost)
	