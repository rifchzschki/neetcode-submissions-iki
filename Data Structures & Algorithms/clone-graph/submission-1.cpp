/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        unordered_map<Node*, Node*> newNode;
        queue<Node*> q;
        newNode[node] = new Node(node->val);
        q.push(node);

        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            for(Node* n: curr->neighbors){
                if(newNode.find(n)==newNode.end()){ 
                    q.push(n);
                    newNode[n] = new Node(n->val);
                }
                newNode[curr]->neighbors.push_back(newNode[n]);
            }
        }
        return newNode[node];
    }
};
