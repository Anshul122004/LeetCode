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
    void solve(int row, vector<string>&board, vector<vector<string>>&ans, vector<int>&topRow,
                                vector<int>&leftDiagonal,vector<int>&rightDiagonal, int n){
        if(row==n){
            ans.push_back(board);
            return;
        }
        for(int col=0;col<n;col++){
            if(topRow[col]==0&&leftDiagonal[n-1+col-row]==0&&rightDiagonal[row+col]==0){
                board[row][col]='Q';
                topRow[col]=1;
                leftDiagonal[n-1+col-row]=1;
                rightDiagonal[row+col]=1;
                solve(row+1, board, ans, topRow, leftDiagonal, rightDiagonal, n);
                board[row][col]='.';
                topRow[col]=0;
                leftDiagonal[n-1+col-row]=0;
                rightDiagonal[row+col]=0;
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
        vector<int> topRow(n,0), leftDiagonal(2*n-1,0), rightDiagonal(2*n-1,0);
        solve(0,board,ans,topRow, leftDiagonal, rightDiagonal,n);
        return ans;
    }
};