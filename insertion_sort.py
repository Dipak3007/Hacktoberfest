def inserstion_sort(arr):
    for j in range(1,len(arr)):
        key=arr[j]
        i=j-1

        while i>=0 and arr[i]>key:
            arr[i+1]=arr[i]
            i-=1

        arr[i+1]=key

    return arr

array=[5,3,8,9,12,1] 
print(inserstion_sort(array))