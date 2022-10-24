def insertionSort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
     
        # For descending order = key<arr[j] --> key>arr[j].        
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j = j - 1
        arr[j + 1] = key
        
d = [7, 4, 2, 3, 8]
insertionSort(d)
print('Sorted Array in Ascending Order=')
print(d)
