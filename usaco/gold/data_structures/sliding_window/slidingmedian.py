class Solution:
    def medianSlidingWindow(self, nums: List[int], k: int) -> List[float]:
        left = []
        right = []
        rm_left = defaultdict(int)
        rm_right = defaultdict(int)
        ans = []
        for x in range(k):
            heapq.heappush(left,-nums[x])
            heapq.heappush(right, -heapq.heappop(left))
            if len(right) > len(left):
                heapq.heappush(left, -heapq.heappop(right))
        if k%2==1:
            ans.append(-left[0])
        else:
            ans.append((-left[0] + right[0])/2)

        for x in range(k, len(nums)):
            incoming = nums[x]
            outgoing = nums[x-k]
            leftW = 0
            rightW = 0
            if right and outgoing >= right[0]:
                rightW -= 1
                rm_right[outgoing] += 1
            else:
                leftW -= 1
                rm_left[outgoing] += 1

            if right and incoming >= right[0]:
                rightW += 1
                heapq.heappush(right, incoming)
            else:
                leftW += 1
                heapq.heappush(left, -incoming)
            if leftW > rightW:
                heapq.heappush(right, -heapq.heappop(left))
            elif rightW > leftW:
                heapq.heappush(left, -heapq.heappop(right))
            #cleanHeap
            while left and rm_left[-left[0]] > 0:
                rm_left[-left[0]] -= 1
                heapq.heappop(left)
            while right and rm_right[right[0]] > 0:
                rm_right[right[0]] -= 1
                heapq.heappop(right)
            if k%2==1:
                ans.append(-left[0])
            else:
                ans.append((-left[0] + right[0])/2)
        return ans




