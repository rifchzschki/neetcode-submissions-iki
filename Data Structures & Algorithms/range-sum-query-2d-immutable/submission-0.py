class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        self.prefMat = [ [0 for _ in range(len(matrix[0]))] for _ in range(len(matrix))]
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                top = self.prefMat[i-1][j] if i>0 else 0
                left = self.prefMat[i][j-1] if j>0 else 0
                topleft = self.prefMat[i-1][j-1] if i>0 and j>0 else 0
                self.prefMat[i][j] = (matrix[i][j] + top + left - topleft)

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        botRight = self.prefMat[row2][col2]
        top = self.prefMat[row1-1][col2] if row1-1 >=0 else 0
        left = self.prefMat[row2][col1-1] if col1-1 >=0 else 0
        topleft = self.prefMat[row1-1][col1-1] if row1-1 >=0 and col1-1 >=0 else 0
        return botRight-top-left+topleft
        


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)