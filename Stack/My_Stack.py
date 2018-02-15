class Stack:
    __Stack = []

    def puch(slef,element):
        self.__Stack.append(element)

    def pop():
        if len(seld.__Stack) is 0:
            return None
        top = self.__Stack[-1]
        self.__Stack.remove(top)
        return top

    def isEmpty(self):
        if len(self.__Stack) is 0:
            return True
        else:
            return False

    def makeEmpty(self):
        while not self.isEmpty():
            self.pop()
