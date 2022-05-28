#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

vector<int> bst;
bool isMirror = false;

struct TreeNode {
    int n;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int n = 0, TreeNode* left = nullptr, TreeNode* right = nullptr)
        : n{n}, left{left}, right{right} {}
    ~TreeNode() {
        if (left) delete left;
        if (right) delete right;
    }
};

bool broken = false;

void constructTree(TreeNode* root, int l, int r) {
    if (broken) return ;
    if (!root) return ;
    // cout << "rt = " << root->n << " " << l << " " << r << endl;
    if (r == l) return ;
    int nl = l + 1;
    if (!isMirror) {
        while (nl < r && bst[nl] < root->n)
            ++nl;
        if (any_of(bst.begin() + nl, bst.begin() + r, [&root](int& a) { return a < root->n; })) {
            broken = true;
            return ;
        }
    }
    else {
        while (nl < r && bst[nl] >= root->n)
            ++nl;
        if (any_of(bst.begin() + nl, bst.begin() + r, [&root](int& a) { return a >= root->n; })) {
            broken = true;
            return ;
        }
    }
    if (broken) return ;
    if (nl != l) {
        root->left = new TreeNode(bst[l]);
        constructTree(root->left, l + 1, nl);
    }
    if (broken) return ;
    if (r != nl) {
        root->right = new TreeNode(bst[nl]);
        constructTree(root->right, nl + 1, r);
    }
}

bool firstIn = true;

void postTraversal(TreeNode* root) {
    if (!root) return ;
    postTraversal(root->left);
    postTraversal(root->right);
    if (firstIn) firstIn = false;
    else cout << ' ';
    cout << root->n;
}

int main()
{
    int n;
    cin >> n;
    if (n == 1) {
        int a;
        cin >> a;
        cout << "Yes\n" << a << endl;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        bst.push_back(a);
    }

    if (bst[1] >= bst[0]) {
        isMirror = true;
    }

    TreeNode* root = new TreeNode(bst.front());
    constructTree(root, 0, n);

    if (broken) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
        postTraversal(root);
        cout << endl;
    }

    return 0;
}
