import java.util.*;
public class MergeSort {
        //method to print the elements of the array
        static void mergedArray(int arr[])
        {
            StringBuffer sb=new StringBuffer("");
            int n = arr.length;
            for (int i=0; i<n; ++i)
                sb.append(arr[i]+" ");
            System.out.println(sb.toString());
        }
        public static void main(String args[])
        {
            Scanner sc = new Scanner(System.in);
            System.out.print("Enter the number of elements: ");

         //checking all ans for various testcases
            int ans = sc.nextInt();
            while(ans>0)
            {

                int n = sc.nextInt();

                MergeSort ms = new MergeSort();
                //array created for storing elements

                int arr[] = new int[n];

                //adding elements to the array
                for(int i=0;i<n;i++)
                    arr[i] = sc.nextInt();

                Merge me = new Merge();

                //calling the method mergeSort
                me.mergeSort(arr,0,arr.length-1);

                //calling the method printArray
                ms.mergedArray(arr);
                ans--;
            }
        }
    }



// } Driver Code Ends
    class Merge
    {
        void merge(int arr[], int left, int mid, int right)
        {

            int[] merged = new int[right-left+1];
            int ind1=left;
            int ind2=mid+1;
            int x=0;
            while(ind1<=mid&&ind2<=right){
                if(arr[ind1]<arr[ind2]){
                    merged[x++] = arr[ind1++] ;
                }else{
                    merged[x++]  =arr[ind2++] ;
                }
            }
            while(ind1<=mid){
                merged[x++]= arr[ind1++] ;
            }
            while(ind2<=right){
                merged[x++] =arr[ind2++] ;
            }
            for(int i=0,j=left;i<merged.length;i++,j++){
                arr[j] = merged[i];
            }
        }
        void mergeSort(int arr[], int l, int r)
        {
            // return merged arr;
            if(l>=r){
                return ;
            }
            int mid = l+(r-l)/2;
            mergeSort(arr,l,mid);
            mergeSort(arr,mid+1,r);
            merge(arr,l,mid,r);
        }
    }

