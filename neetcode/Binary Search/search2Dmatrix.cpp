// https://leetcode.com/problems/search-a-2d-matrix/description/
// Binary search y axis  first then x axis.
class Solution {
public:



    bool binarySearch(vector<int>& a, int t, int l , int r) {
        if (l == r && t == a[l]) return true;
        if (l == r) return false;
        int mid = (l+r) / 2;

        if (t > a[mid]) {
            return binarySearch(a, t, mid + 1, r);
        } else {
            return binarySearch(a, t , l, mid);
        }

    }

    bool binarySearch2d(vector<vector<int>>& matrix, int target, int bot, int top) {
        if (top < bot) return false;
        int mid = (top+bot)/2 ;

        if ( matrix[mid][0] <= target && matrix[mid][matrix[0].size()-1] >= target)
            return binarySearch(matrix[mid], target, 0, matrix[bot].size() -1);


        if (target > matrix[mid][0]) {
            return binarySearch2d(matrix, target, mid+1, top);
        } else {
            return binarySearch2d(matrix, target, bot, mid-1);
        }
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return binarySearch2d(matrix, target, 0, matrix.size()-1);
    }
};