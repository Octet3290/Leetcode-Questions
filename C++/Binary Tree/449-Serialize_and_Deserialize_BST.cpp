/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if (root == nullptr) return "";
        string result = "";
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node *node = q.front();
            q.pop();
            if (node == nullptr) {
                result += "null,";
            } else {
                result += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }
        }
        return result;
    }
    
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        if (data == "") return nullptr;
        vector<string> nodes;
        stringstream ss(data);
        string item;
        while (getline(ss, item, ',')) {
            nodes.push_back(item);
        }
        Node *root = new Node(stoi(nodes[0]));
        queue<Node*> q;
        q.push(root);
        int i = 1;
        while (!q.empty()) {
            Node *node = q.front();
            q.pop();
            if (nodes[i] != "null") {
                node->left = new Node(stoi(nodes[i]));
                q.push(node->left);
            }
            i++;
            if (nodes[i] != "null") {
                node->right = new Node(stoi(nodes[i]));
                q.push(node->right);
            }
            i++;
        }
        return root;
    }
};

int main() {
    Node *node = new Node(1, new Node(2, new Node(4)), new Node(3, new Node(5), new Node(6)));
    Codec codec;
    string serialized = codec.serialize(node);
    // printf("%s ", serialized.c_str());
    Node *deserialized = codec.deserialize(serialized);
    // printf("%d ", deserialized->left->left->val);
    // printf("%d ", deserialized->right->left->val);
    // printf("%d ", deserialized->right->right->val);
    assert(deserialized->left->left->val == 4);
    return 0;
}

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;