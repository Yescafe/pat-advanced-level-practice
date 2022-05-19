#include <iostream>
#include <vector>
#include <map>
#include <cassert>
using namespace std;

map<int, vector<int>> layerorder;
vector<int> inorder, postorder;

void genLayerOrder(int is, int ie, int ps, int pe, int depth) {
    if (ie < is) return ;
    int root = postorder[pe];
    auto fnd = layerorder.find(depth);
    if (fnd == layerorder.end()) {
        layerorder.insert({});
    }
    layerorder[depth].push_back(root);
    if (ie == is) {
        return ;
    }
    int mid = -1;
    for (int i = is; i <= ie; ++i) {
        if (inorder[i] == root) {
            mid = i;
            break;
        }
    }
    assert(mid != -1);
    genLayerOrder(is, mid - 1, ps, ps + (mid - 1 - is), depth + 1);
    genLayerOrder(mid + 1, ie, ps + (mid - is), pe - 1, depth + 1);
}

int main()
{
    int n;
    postorder.reserve(n);
    inorder.reserve(n);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        postorder.push_back(a);
    }
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        inorder.push_back(a);
    }

    genLayerOrder(0, n - 1, 0, n - 1, 0);
    bool first = true;
    for (int i = 0; i < layerorder.size(); ++i) {
        for (auto& item : layerorder[i]) {
            if (first) first = false;
            else cout << " ";
            cout << item;
        }
    }
    cout << endl;

    return 0;
}
