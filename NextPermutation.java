public class NextPermutation {
    static void nextPermutationSoln(int[] num) {
        int n = num.length;
        if (n < 2)
            return;
        int index = n - 1;
        while (index > 0) {
            if (num[index - 1] < num[index])
                break;
            index--;
        }
        if (index == 0) {
            reverseSort(num, 0, n - 1);
            return;
        } else {
            int val = num[index - 1];
            int j = n - 1;
            while (j >= index) {
                if (num[j] > val)
                    break;
                j--;
            }
            swap(num, j, index - 1);
            reverseSort(num, index, n - 1);
            return;
        }
    }

    public static void swap(int[] num, int i, int j) {
        int temp = 0;
        temp = num[i];
        num[i] = num[j];
        num[j] = temp;
    }

    public static void reverseSort(int[] num, int start, int end) {
        if (start > end)
            return;
        for (int i = start; i <= (end + start) / 2; i++)
            swap(num, i, start + end - i);
    }

     //Driver code
    public static void main(String[] args) {

        int[] num = new int[]{1, 2, 3, 6, 5, 4};

        // Function call
        nextPermutationSoln(num);

        // Printing the answer
        for (int i : num) {
            System.out.print(i + " ");
        }
    }
}
