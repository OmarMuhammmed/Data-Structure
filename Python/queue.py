# Using a list for queues is inefficient, 
# so we use deque from collections for better performance.
from collections import deque

queue = deque()
queue.append(1)  # Enqueue
queue.append(2)
queue.append(3)
print(queue.popleft())  # Dequeue -> Output: 1
print(queue)  # deque([2, 3])
