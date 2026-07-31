class Solution {
public:
    bool isSafe(int row, int col, vector<string>&board, int n){
        int duprow=row;
        int dupcol=col;
        while(row>=0&&col<n){
            if(board[row][col]=='Q') return false;
            row--;
            col++;
        }
        row=duprow;
        col=dupcol;
        while(row>=0){
            if(board[row][col]=='Q') return false;
            row--;
        }
        row=duprow;
        col=dupcol;
        while(row>=0&&col>=0){
            if(board[row][col]=='Q') return false;
            row--;
            col--;
        }
        return true;
    }
    void solve(int row, vector<string>&board, vector<vector<string>>&ans, int n){
        if(row==n){
            ans.push_back(board);
            return;
        }
        for(int col=0;col<n;col++){
            if(isSafe(row, col, board,n)){
                board[row][col]='Q';
                solve(row+1, board, ans, n);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        solve(0,board,ans, n);
        return ans;
    }
};