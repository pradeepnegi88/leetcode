class Solution {
public:

    void dfs(int r,int c,int initialColor,int replaceColor,vector<vector<int>>& image,vector<vector<int>>& ans){
     ans[r][c] = replaceColor;
     int dx[] ={0,0,-1,1};
     int dy[] = {1,-1,0,0};
     for(int i=0;i<4;i++){
         int rr = r+dx[i];
         int cc = c+dy[i];
         if(rr>=0 && rr<image.size() && cc>=0 && cc<image[0].size() && image[rr][cc] == initialColor && ans[rr][cc]!=replaceColor){
                    dfs( rr,cc,initialColor,replaceColor,image,ans);
         }
     }
     

        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];
        vector<vector<int>> output = image;
        dfs( sr,sc,initialColor,color,image,output);
        return output;
    }
};