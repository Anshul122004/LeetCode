class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>matrix(n,vector<int>(n));
        int left=0, top=0, right=n-1, bottom=n-1;
        int a=1;
        vector<int> ans;
        while(top<=bottom && left<=right){
            for(int i=left; i<=right; i++){
                matrix[top][i]=a;
                a++;
            }
            top++;
            for(int i=top; i<=bottom; i++){
                matrix[i][right]=a;
                a++;
            }
            right--;
            if(top<=bottom){
                for(int i=right; i>=left; i--){
                    matrix[bottom][i]=a;
                    a++;
                }
                bottom--;
            }
            if(left<=right){
                for(int i=bottom; i>=top; i--){
                    matrix[i][left]=a;
                    a++;
                }
                left++;
            }
        }
        return matrix;
    }
};