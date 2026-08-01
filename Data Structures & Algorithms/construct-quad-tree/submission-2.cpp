/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

// 0,1 -->0, 1

// 0,3 --> 0,1 --> 2,3

// 0 9
// 0,1,2,3,4,5,6,7,8,9 --> [(0,4);(5,9)]
// 0,1,2,3,4,5,6,7,8,9, 10 --> [(0,5);(5,10)]
class Solution {
public:
    Node* traverse(vector<vector<int>>& grid, int left, int right, int top, int bottom){
        if(left == right && top == bottom){
            return new Node(grid[top][left], true);
        }
        int midH = top+(bottom-top)/2, midV = left+(right-left)/2;

        Node *n1 = traverse(grid, left, midV, top, midH);
        Node *n2 = traverse(grid, midV+1, right, top, midH);
        Node *n3 = traverse(grid, left, midV, midH+1, bottom);
        Node *n4 = traverse(grid, midV+1, right, midH+1, bottom);

        if(n1->isLeaf && n2->isLeaf && n3->isLeaf && n4->isLeaf && (n1->val==n2->val && n2->val==n3->val && n3->val==n4->val)){
            return n1; 
        }
        return new Node(true, false, n1,n2,n3,n4);
    }
    Node* construct(vector<vector<int>>& grid) {
        return traverse(grid, 0, grid[0].size()-1, 0, grid.size()-1);
    }
};