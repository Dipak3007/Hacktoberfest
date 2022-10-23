import java.io.*;
import java.util.*;
public class KadaneAlgorithm {

    //Driver code
    public static void main(String[] args)
    {
        int[] a = {  5, -3 , 4, -2, 6, -1};
        System.out.println("Maximum subArray sum is "
                + maxSumSubArray(a));
    }
    //Function call
    static int maxSumSubArray(int a[])
    {
        int maxSum =0, curSum=0;
        for(int i=0;i<a.length;i++){
            curSum=curSum+a[i];
            if(curSum>maxSum){
                maxSum=curSum;
            }
            if(curSum<0){
                curSum=0;
            }
        }
       return maxSum;
    }
}
