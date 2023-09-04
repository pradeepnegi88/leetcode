class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
       sudokuSolver(board);
    }
bool sudokuSolver(vector<vector<char>> &board){
         int size = board.size();
       int insideSize = board.size();
       for(int row = 0;row<size;row++){
             for(int column=0;column<insideSize;column++){ 
                    if(board[row][column] == '.'){
                     for(int i=1; i<10;i++){
                        if(checkCondition(column,row,board,i)){
                            char c = '0' + i;
                            board[row][column] =  c; 
                           if(sudokuSolver(board) == true){
                             return true;
                           }else{
                              board[row][column] = '.';
                           }
                        }
                    }
                    return false;
                    }

             }
       }
        
    return true;
}

bool checkCondition(int column,int row,vector<vector<char>> &board, int i){
 char c = '0' + i;
 for (int j = 0; j<9;j++){
   if(board[j][column] ==  c) return false;
   if(board[row][j] ==  c) return false;
   if(board[3*(row/3)+j/3][3*(column/3)+j%3] == c) return false;


 }
 return true;
}
};