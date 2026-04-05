class Solution {
public:
    int maxArea(vector<int>& heights) {
        int res = 0, i=0, j=heights.size()-1;
        while(i!=j){
            int h = min(heights[i],heights[j]);
            res = max(res, (j-i)*h);
            cout << i << " " << j << " " << (j-i)*h<<endl;
            (heights[i]<heights[j]) ? i++:j--;
        }
        return res;
    }
};
