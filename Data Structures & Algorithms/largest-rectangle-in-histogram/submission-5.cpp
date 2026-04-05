class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int mxArea = 0;
        stack<int> idx; //monotonic increasing
        
        heights.push_back(0); //flush stack when end

        for(int i;i<heights.size();i++){
            while(!idx.empty() && heights[idx.top()]>= heights[i]){
                int h = heights[idx.top()];
                idx.pop();
                int width = idx.empty() ? i : i-idx.top()-1;
                mxArea = max(mxArea, width*h);
                cout << i << "<<" << width << "<<" << h << "<<" << mxArea << endl;
            }
            idx.push(i);
        }
        return mxArea;

    }
};
