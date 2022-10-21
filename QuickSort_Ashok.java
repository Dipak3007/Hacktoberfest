public class QuickSort {
    public int partition(int [] arr,int low,int high){
        int pivot=arr[low];
        int i=low,j=high;
        while(i<j){
            while(arr[i]<=pivot && i<high) i++;
            while(arr[j]>pivot) j--;
            if(i<j){
                int temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
        }
        int temp=pivot;
        arr[low]=arr[j];
        arr[j]=temp;
        return j;
    }
    public void quickSort(int []arr,int low,int high){
        if(low<high){
            int j=partition(arr, low, high);
            quickSort(arr, low, j-1);
            quickSort(arr, j+1,high);
        }
    }
    public static void main(String[] args) {
        int arr[]={23,54,34,16,78,11,70};
        int low=0,high=arr.length-1;
        SortQuick q1=new SortQuick();
        q1.quickSort(arr,low,high);
        for (int i : arr) {
            System.out.print(i+" ");
        }
    }
}
