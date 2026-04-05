class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /**
        l = 0;
        r = m*n;
        mid = l+r/2;
        x = mid % n;
        y = mid /n;
        **/

        bool found = false;
        int l=0, m=matrix.size(), n=matrix[0].size(), r=(n*m)-1;
        if(n==1 && m==1) return (matrix[0][0]==target?true:false);
        while(!found && l<r){
            int mid = (l+r)/2;
            if(matrix[mid/n][mid%n]<target){
                l = mid+1;
            }else if(matrix[mid/n][mid%n]>target){
                r = mid;
            }else{
                found = true;
            }
            mid = (l+r)/2;
            if(matrix[mid/n][mid%n]==target){
                found = true;
            }
        }
        return found;
    }
};
