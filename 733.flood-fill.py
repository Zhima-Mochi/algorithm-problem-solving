#
# @lc app=leetcode id=733 lang=python3
#
# [733] Flood Fill
#

# @lc code=start
class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        if image[sr][sc]==newColor:
            return image
        self.dfs(image, sr, sc, image[sr][sc], newColor)
        return image

    def dfs(self, image, row, col, num, new_num):
        if row < 0 or col < 0 or row >= len(image) or col >= len(image[0]):
            return
        if image[row][col] == num:
            image[row][col] = new_num
            for i in range(-1, 2, 2):
                self.dfs(image, row+i, col, num, new_num)
                self.dfs(image, row, col+i, num, new_num)


# @lc code=end
