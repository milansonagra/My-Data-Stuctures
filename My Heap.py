class MinHeap:
    __Heap = []

    def insert(self,element):

        #   INSERT ELEMENT IN MIN-HEAP
        
        self.__Heap.append(element)
        self.__Heapify()
            
    def delete(self):

        #   REMOVE ELEMENT FROM MIN-HEAP
        
        self.__Heap[-1],self.__Heap[0] = self.__Heap[0],self.__Heap[-1]
        rm_element = self.__Heap[-1]
        self.__Heap.remove(self.__Heap[-1])
        self.__Heapify()
        return rm_element

    def __Heapify(self):

        #   PUT THE ELEMENT AT RIGHT PLACE
        
        element = self.__Heap[-1]
        ele_index = len(self.__Heap)-1
        while True and len(self.__Heap) > 1:
            par_index = ele_index//2 if ele_index%2 is not 0 else ele_index//2-1
            parent = self.__Heap[par_index]

            if element < parent:
                self.__Heap[par_index],self.__Heap[ele_index] = self.__Heap[ele_index],self.__Heap[par_index]
                ele_index = par_index
            if element > parent or par_index is 0:
                break

    def showHeap(self):

        #   SHOW THE MIN-HEAP AS LIST
        
        return self.__Heap

class MaxHeap:
    __Heap = []

    def insert(self,element):

        #   INSERT ELEMENT IN MAX-HEAP
        
        self.__Heap.append(element)
        self.__Heapify()
            
    def delete(self):

        #   REMOVE ELEMENT FROM MAX-HEAP
        
        self.__Heap[-1],self.__Heap[0] = self.__Heap[0],self.__Heap[-1]
        rm_element = self.__Heap[-1]
        self.__Heap.remove(self.__Heap[-1])
        self.__Heapify()
        return rm_element

    def __Heapify(self):

        #   PUT THE ELEMENT AT RIGHT PLACE
        
        element = self.__Heap[-1]
        ele_index = len(self.__Heap)-1
        while True and len(self.__Heap) > 1:
            par_index = ele_index//2 if ele_index%2 is not 0 else ele_index//2-1
            parent = self.__Heap[par_index]

            if element > parent:
                self.__Heap[par_index],self.__Heap[ele_index] = self.__Heap[ele_index],self.__Heap[par_index]
                ele_index = par_index
            if element < parent or par_index is 0:
                break

    def showHeap(self):

        #   SHOW THE MAX-HEAP AS LIST
        
        return self.__Heap
