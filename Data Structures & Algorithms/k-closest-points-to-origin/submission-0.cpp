class Solution {
public:
    struct Point{
        int x, y;
    };
    struct ComparePoint{
        double calRange(Point p){
            return sqrt(pow(p.x,2)+pow(p.y,2));
        }
        bool operator()(Point a, Point b){
            return calRange(a)<calRange(b);
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<Point, vector<Point>, ComparePoint> pq;
        for(int i=0;i<points.size();i++){
            cout << "Point: (" << points[i][0] << "," << points[i][1] <<")" << endl;
            pq.push(Point(points[i][0], points[i][1]));
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<vector<int>> res;
        cout << pq.size() << endl;
        while(k-- && !pq.empty()){
            cout << "Point: (" << pq.top().x << "," << pq.top().y <<")" << endl;
            res.push_back({pq.top().x, pq.top().y});
            pq.pop();
        }
        return res;
    }
};
