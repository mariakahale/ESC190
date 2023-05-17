class Queue:
    def __init__(self):
        self.data = []

    def enqueue(self, item):
        self.data.append(item)   # O(n) worst-case, usually O(1)

    def dequeue(self):
        # return self.data.pop()
        ret_val = self.data[0]
        del self.data[0] # O(n), because need to move self.data[1:] to self.data[0:]
        return ret_val    
    
class Circular:
    #assumes the queue is never full.
    def __init__(self, size):
        self.data=[None] * size
        self.head = -1
        self.tail = -1

    def __str__(self):
        outputList = []
        #If it does not loop around
        if self.tail >= self.head:
            for i in range(self.head, self.tail+1):
                outputList.append(self.data[i])
        #If it does loop around
        else:
            for i in range(self.head, len(self.data)): #check if you need to -1
                outputList.append(self.data[i])
            for i in range(0, self.tail+1):
                outputList.append(self.data[i])


        return f'{outputList}, ({self.head},{self.tail})'

    def enqueue(self, item):
        if self.head == -1:
            self.head = 0
            self.tail = 0
            self.data[self.tail] = item

        else:
            self.tail=(self.tail +1) % (len(self.data))
            self.data[self.tail] = item


    def dequeue(self):
        item = self.data[self.head]

        if self.head == len(self.data)-1:
            self.head = 0
        else:
            self.head +=1
        return item

    def __lt__(self, other):
        i, j = self.head, other.head
        for a in range(max(len(self.data),len(other.data))):
            if self.data[i % len(self.data)] < other.data[ j% len(other.data)]:
                return True
            elif self.data[i % len(self.data)] > other.data[ j% len(other.data)]:
                return False
            i += 1
            j+=1
        return True
    


c1 = Circular(3)
c2 = Circular(3)
c3 = Circular(4)
c4 = Circular(2)

# array_queues = [c1,c2,c3]
# array_queues.sort()
# print("\nI am here",array_queues[0], array_queues[1], array_queues[2])

c1.enqueue(1)
c1.enqueue(5)
c1.enqueue(6)

c2.enqueue(2)
c2.enqueue(1)
c2.enqueue(5)


c3.enqueue(2)
c3.enqueue(5)
c3.enqueue(10)
c3.enqueue(12)


c4.enqueue(11)
c4.enqueue(2)


array_queues = [c2,c3,c4,c1]
array_queues.sort()
for i in range(4):
    print(array_queues[i])


# # print(c)
# c.enqueue(7)
# print(c)
# print("dequeue:", c.dequeue())
# print("dequeue:", c.dequeue())
# print("dequeue:", c.dequeue())
# print("dequeue:", c.dequeue())
# print(c)
