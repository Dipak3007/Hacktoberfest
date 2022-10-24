def bubbleSort(arr):
    
  for i in range(len(arr)):
    for j in range(0, len(arr) - i - 1):
      
      # compare two adjacent elements
      if arr[j] > arr[j + 1]:

        # swapping elements if elements are unordered
        temp = arr[j]
        arr[j] = arr[j+1]
        arr[j+1] = temp

d = [-2, 45, 0, 11, -9]
bubbleSort(d)
print('Sorted Array in Ascending Order=')
print(d)
