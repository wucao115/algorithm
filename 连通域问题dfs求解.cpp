#include<vector>
#include<iostream>
#include<queue>
using namespace std;
int dfs(vector<vector<int>>&mat,int r,int c,int n);
int findCon(vector<vector<int>>& mat) {
    int n = mat.size();
    int max1 = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(mat[i][j] == 0)
              max1 = max(dfs(mat,i,j,n),max1);
        }
    }
    return max1;
}
int dfs(vector<vector<int>>&mat,int r,int c,int n) {
    if(r<0||r>=n||c<0||c>=n||mat[r][c]==1) return 0;
    int size = 1;
    mat[r][c] = 1;
    size += dfs(mat,r,c+1,n);
    size += dfs(mat,r,c-1,n);
    size += dfs(mat,r+1,c,n);
    size += dfs(mat,r-1,c,n);
    return size;
}
int main(void) {
    vector<vector<int>> mat = {{1,1,1,1},
                               {1,1,0,0},
                               {1,0,0,1},
                               {0,1,1,1}};
    cout<<findCon(mat);
}
