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
        unordered_map<Node *,Node *> oldnew;
        oldnew[node] = new Node(node->val);

        queue<Node *> q;
        q.push(node);

        while(!q.empty()){
            Node *curr = q.front();
            q.pop();

            for(auto nei:curr->neighbors){
                if(oldnew.find(nei)==oldnew.end()){
                    oldnew[nei] = new Node(nei->val);
                    q.push(nei);
                }
                oldnew[curr]->neighbors.push_back(oldnew[nei]);
            }
            
        }
        return oldnew[node];
        
    }
};
