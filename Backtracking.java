public class Backtracking {
//N queens backtracking
        final int n = 4;
        //function to print answer
        void backtrackAns(int board[][])
        {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++)
                    System.out.print(" " + board[i][j] + " ");
                System.out.println();
            }
        }
        boolean validate(int board[][], int rowInd, int colInd)
        {
            int i, j;
            for (i = 0; i < colInd; i++)
                if (board[rowInd][i] == 1)
                    return false;

            //for upper diagonal on left side
            for (i = rowInd, j = colInd; i >= 0 && j >= 0; i--, j--)
                if (board[i][j] == 1)
                    return false;

            //for lower diagonal on left side
            for (i = rowInd, j = colInd; j >= 0 && i < n; i++, j--)
                if (board[i][j] == 1)
                    return false;

            return true;
        }

        //recursive function
        boolean solveNqueens(int board[][], int col)
        {
        //if queens are placed then return true
            if (col >= n)
                return true;
            for (int i = 0; i < n; i++) {
            //if queen can be placed or not
                if (validate(board, i, col)) {
                    board[i][col] = 1;
                    if (solveNqueens(board, col + 1) == true)
                        return true;
                    //if not then return false
                    board[i][col] = 0; // BACKTRACK
                }
            }
            return false;
        }
          //input to check the function
        boolean constructNQ()
        {
            int board[][] = { { 0, 0, 0, 0 },
                    { 0, 0, 0, 0 },
                    { 0, 0, 0, 0 },
                    { 0, 0, 0, 0 } };

            if (solveNqueens(board, 0) == false) {
                System.out.print("Failed");
                return false;
            }
            backtrackAns(board);
            return true;
        }

        //to test above function
        public static void main(String args[])
        {
            Backtracking Queen = new Backtracking();
            Queen.constructNQ();
        }
    }

