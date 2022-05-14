#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

struct Node {
    string name;
    vector<Node*> children;
    Node(string name = "") : name(name) {}
    Node* getChild(string name) {
        for (auto child : children) {
            if (child->name == name) {
                return child;
            }
        }
        return nullptr;
    }
    bool addChild(Node* child) {
        if (this->getChild(child->name)) {
            return false;
        }
        this->children.push_back(child);
        return true;
    }
};

unordered_map<string, Node*> mp;

int main()
{
    int n, m;
    cin >> n;
    if (n == 0) return 0;
    cin >> m;

    Node* tree = new Node("01");
    mp.insert(make_pair(string("01"), tree));
    for (int i = 0; i < m; ++i) {
        string rt_name;
        int k;
        cin >> rt_name >> k;
        Node* root;
        auto fnd = mp.find(rt_name);
        if (fnd != mp.end()) {
            root = fnd->second;
        } else {
            root = new Node(rt_name);
            mp.insert(make_pair(string(rt_name), root));
        }
        while (k--) {
            string cd_name;
            cin >> cd_name;
            Node* child;
            fnd = mp.find(cd_name);
            if (fnd != mp.end()) {
                child = fnd->second;
            } else {
                child = new Node(cd_name);
                mp.insert(make_pair(string(cd_name), child));
            }
            root->addChild(child);
        }
    }

    queue<Node*> q;
    q.push(tree);
    bool first = true;
    while (!q.empty()) {
        int size = q.size();
        int no_child_cnts = 0;
        while (size--) {
            auto node = q.front();
            q.pop();
            if (node->children.empty()) {
                ++no_child_cnts;
            }
            for (auto child : node->children) {
                q.push(child);
            }
        }
        if (first) first = false;
        else cout << " ";
        cout << no_child_cnts;
    }
    cout << endl;

    return 0;
}
