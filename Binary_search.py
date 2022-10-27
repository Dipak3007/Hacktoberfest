
def binary_search(arr,start,end,target):

     while start <=end:
        
        mid=(start+end)//2

        if arr[mid]<target:
            start=mid+1
        
        elif arr[mid]>target:
            end=mid-1

        else:
            return mid 

     return -1 #return -1

arr=[2,3,5,6,8,9,22,40]
target=40

result=binary_search(arr,0,len(arr)-1,target)

if result!=-1:
    print(f"Element is present at index {result}")

else:
    print("Element is not in the array")



def binary_recur(arr,start,end,target):
    if end>=start:

        mid=(start+end)//2

        if arr[mid]<target:
            return binary_recur(arr,mid+1,end,target)
        
        elif arr[mid]>target:
            return binary_recur(arr,start,mid-1,target)

        else:
            return mid 

    else:
        return -1
    

arr=[2,3,5,6,8,9,22,40]
target=8

result=binary_recur(arr,0,len(arr)-1,target)

if result!=-1:
    print(f"Element is present at index {result}")

else:
    print("Element is not in the array")
