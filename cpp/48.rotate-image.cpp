/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
    void rotateSquare(vector<vector<int>>& matrix,int len,pair<int,int> pivot){
        for(int i=0;i!=len-1;i++){
            swap(matrix[pivot.first][pivot.second+i],matrix[pivot.first+i][pivot.second+len-1]);
            swap(matrix[pivot.first][pivot.second+i],matrix[pivot.first+(len-1-i)][pivot.second]);
            swap(matrix[pivot.first+len-1][pivot.second+len-1-i],matrix[pivot.first+(len-1-i)][pivot.second]);
        }
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        auto len=matrix.size();
        for(int i=len,j=0;i>1;i-=2,j++){
            rotateSquare(matrix,i,pair<int,int>(j,j));
        }
    }
};
// @lc code=end
// void rotate(vector<vector<int> > &matrix) {
//     reverse(matrix.begin(), matrix.end());
//     for (int i = 0; i < matrix.size(); ++i) {
//         for (int j = i + 1; j < matrix[i].size(); ++j)
//             swap(matrix[i][j], matrix[j][i]);
//     }
// }
// void anti_rotate(vector<vector<int> > &matrix) {
//     for (auto vi : matrix) reverse(vi.begin(), vi.end());
//     for (int i = 0; i < matrix.size(); ++i) {
//         for (int j = i + 1; j < matrix[i].size(); ++j)
//             swap(matrix[i][j], matrix[j][i]);
//     }
// }
