class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> premax(n);
        vector<int> sufmax(n);
        premax[0]=height[0];
        sufmax[n-1]=height[n-1];
        for(int i=1;i<=n-1;i++){
            premax[i]=max(premax[i-1], height[i]);
        }
        for(int i=n-2;i>=0;i--){
            sufmax[i]=max(sufmax[i+1],height[i]);
        }
        int total=0;
        for(int i=0;i<=n-1;i++){
            if(height[i]<premax[i]&&height[i]<sufmax[i]){
                total+=min(premax[i],sufmax[i])-height[i];
            }
        }
        return total;
    }
};