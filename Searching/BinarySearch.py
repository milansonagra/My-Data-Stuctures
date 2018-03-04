import random
count=0
def BinarySearch(word,key,start,end):
    mid = (start+end)//2
    global count
    count += 1
    count += 1
    if start <= end:
        count += 1
        if key == word[mid]:
            print("Word Found! Word is :  ",word[mid]," at index : ",mid)
        elif key < word[mid]:
            BinarySearch(word,key,start,mid-1)
            count += 1
        else:
            BinarySearch(word,key,mid+1,end)
            count += 1
    else:
        print("word not found!")
x = 1
while x == 1:
    print("enter n:")
    n = int(input())
    l = ["ABC" + str(i) for i in range(0,n)]
    l.sort()
    key = l[len(l)//random.randint(1,len(l)//4)]
    BinarySearch(l,key,0,len(l))
    print("number of instruction execute is: ",count)
    print("Input: ",len(l)," & Number of instructions: ",count)
    print("enter 1 for contunoe:")
    x = int(input())
    
