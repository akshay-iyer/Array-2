// Time Complexity : O(mn) 
// Space Complexity : O(1) 
// Did this code successfully run on Leetcode : Yes
// Any problem you faced while coding this : No

// [***] KEY INSIGHT: IF 1 CHANGES TO 0, MAKE IT -1 AND IF 0 TO CHANGES TO 1 MAKE IT 2

// Your code here along with comments explaining your approach
// 1. Iterate through the board and at each element count the number of 1s and -1s in the 8 neighbors (-1 as well since it implies it was prev a 1)
// 2. If cell is 0 then make it 2 if the count is 3. If it has to remain 0 then let it be
// 3. If cell is 1 then make it -1 if the count is less than 2 or more than 3. If it has to remain 1 (alive) then let it be it as it is

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if(board.size() == 0)
            return;
        vector<vector<int>> dirs {{0,1},{1,0},{0,-1},{-1,0},{1,1},{-1,1},{1,-1},{-1,-1}};
        int counter = 0;
        int m=board.size(), n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                counter = 0;
                // calc no. of alive neighbors
                for(auto dir: dirs){
                    int r = i+dir[0];
                    int c = j+dir[1];
                    if(r>=0 && r<m && c>=0 && c<n && (board[r][c] == 1 || board[r][c] == -1))
                        counter++;
                }
                // if curr cell is alive
                if(board[i][j] == 1){
                    if(counter < 2 || counter > 3)
                        board[i][j] = -1;
                }
                // curr cell is not alive
                else{
                    if(counter == 3)
                        board[i][j] = 2;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == 2)
                    board[i][j] = 1;
                else if(board[i][j] == -1)
                    board[i][j] = 0;
            }
        }
        return;
    }
};