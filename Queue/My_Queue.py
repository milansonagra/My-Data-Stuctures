class Queue:
    __Queue = []

    def enQueue(self,element):
        self.__Queue.append(element)

    def deQueue(self):
        if len(self.__Queue) is 0:
            return None
        first = self.__Queue[0]
        self.__Queue.remove(first)
        return first

    def isEmpty(self):
        if len(self.__Queue) is 0:
            return True
        else:
            return False

    def makeEmpty(self):
        while not self.isEmpty():
            self.deQueue()
