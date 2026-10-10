class Solution {
public:
    bool isValid(char c, int i ,int j, vector<vector<char>>& board){
        for(int k=0;k<9;k++){
           if(board[i][k]==c) return false;
           if(board[k][j]==c) return false;
           if(board[3*(i/3)+(k/3)][3*(j/3)+(k%3)]==c) return false;
        }
        return true;
    }
    bool helper(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char c='1'; c<='9';c++){
                         if(isValid(c,i,j,board)){
                            board[i][j]=c;
                             if(helper(board)){
                                return true;
                             }
                             else{
                                board[i][j]='.';
                             }
                         }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        helper(board);
    }
};