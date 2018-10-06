class LinkedList:

    __list = []
            
    def append(self,data):
        self.__list.append(data)
        print("done!")

    def addfirst(self,data):
        self.__list = [data] + self.__list
        print("done!")

    def addafter(self,before,data):
        before_index = self.find(before)
        self.__list = self.__list[:before_index] + [data] + self.__list[before_index:]
        print("done!")

    def delete(self,data):
        self.__list.remove(data)
        
    def find(self,data):
        index = 0
        for node in self.__list:
            if node is data:
                return index
            index = index + 1
        print("data not found in LinkedList")
        return None
    
    def show(self):
        for node in self.__list:
            print(node,"-->",end="")
        print("\end.")

    
