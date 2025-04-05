#include <iostream>
#include<vector>

using namespace std;

// https://leetcode.com/problems/range-sum-query-2d-immutable/description/

//Create a new matrix with extra row & column in the constructor
//Do prefix on the given matrix 2d array
//arr[i+1][j+1]=matrix[i][j](current element in the matrix) + arr[i][j+1]( in the above row prefix) + arr[i+1][j](in the previous column prefix) - arr[i][j](subtract because we have added the that element twice -> the corner one)
//In the sum function return arr[row2+1][col2+1]-arr[row2+1][col1]-arr[row1][col2+1] + arr[row1][col1];
//Actual variables are incremented by 1 because there's one extra row & column

class NumMatrix {
public:
    vector<vector<int>> ans;
    NumMatrix(vector<vector<int>>& matrix) {
        ans.clear();
        ans.resize(matrix.size()+1, vector<int>(matrix[0].size()+1));
        for (int i=0; i<ans.size();i++) {
            for (int j=0;j<ans[0].size();j++) {
                if (j==0) {
                    ans[i][j] = 0;
                } else if (i == 0){
                    ans[i][j] = 0;
                } else {
                    ans[i][j] = ans[i-1][j]+ ans[i][j-1] + matrix[i-1][j-1] - ans[i-1][j-1];
                    
                }
                cout << ans[i][j] << " ";
            }

            cout << endl;
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {

        return ans[row2+1][col2+1] - ans[row2+1][col1] - ans[row1][col2+1] + ans[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */