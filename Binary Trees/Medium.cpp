#include<bits/stdc++.h>
using namespace std;

using TreeNode = struct TreeNode;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(): val(-1), left(nullptr) , right(nullptr) {};
};


int maxDepth(TreeNode* root) {
    if(root == nullptr)
        return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int helperDepth(TreeNode* root){
    if(root == nullptr)
        return 0;
    int left = helperDepth(root->left);
    int right = helperDepth(root->right);
    if(left == -1 || right == -1)
        return -1;
    if(abs(left - right) <=1){
        return 1 + max(left, right);
    }else {
        return -1;
    }
}
bool isBalanced(TreeNode* root) {
    if (helperDepth(root) >= 0){
        return true;
    }else{
        return false;
    }
}

int maxDiameter = 0;
int helperDiameter(TreeNode* root){
    if(root == nullptr)
        return 0;
    int left = helperDiameter(root->left);
    int right = helperDiameter(root->right);
    maxDiameter = max(maxDiameter, left+right);
    return 1 + max(left,right);
}
int diameterOfBinaryTree(TreeNode* root) {
    helperDiameter(root);
    return maxDiameter;
}

int maxPath = INT_MIN;
int helperPathSum(TreeNode* root){
    if(root == nullptr)
        return 0;

    int left = max(0, helperPathSum(root->left));
    int right = max(0, helperPathSum(root->right));

    maxPath = max(maxPath, root->val + left + right);

    return max(left, right) + root->val;
}
int maxPathSum(TreeNode* root) {
    helperPathSum(root);
    return maxPath;
}


bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p == nullptr && q == nullptr){
            return true;
    }

    if(p == nullptr || q == nullptr)
        return false;

    if(p->val != q->val)
        return false;

    return isSameTree(p->left,q->left) && isSameTree(p->right, q->right);
}


vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if(root == nullptr)
        return {};
    queue<TreeNode*> q;
    vector<vector<int>> ans;
    vector<int> row;
    q.push(root);
    int h = 0;
    while(!q.empty()){
        int qLen = q.size();
        row = {};
        for(int i=0;i<qLen;i++){
            auto curr = q.front();
            q.pop();
            row.push_back(curr->val);
            if(curr->left != nullptr)
                q.push(curr->left);
            if(curr->right != nullptr)
                q.push(curr->right);
        }
        if(h % 2 == 1)
            reverse(row.begin(), row.end());
        ans.push_back(row);
        h++;
    }
    return ans;
}

void leftBoundary(TreeNode* root, vector<int>& ans){
    if(root == nullptr || (root->left == nullptr && root->right == nullptr)){
        return;
    }
    ans.push_back(root->val);
    if(root->left != nullptr){
        leftBoundary(root->left, ans);
    }else{
        leftBoundary(root->right, ans);
    }
}
void leaf(TreeNode* root, vector<int>& ans){
    if(root == nullptr)
        return;
    if(root->left == nullptr && root->right == nullptr){
        ans.push_back(root->val);
        return;
    }
    leaf(root->left, ans);
    leaf(root->right, ans);
}
void rightBoundary(TreeNode* root, vector<int>& ans){
    if(root == nullptr || (root->right == nullptr && root->left == nullptr)){
        return;
    }
    if(root->right != nullptr){
        rightBoundary(root->right, ans);
    }else{
        rightBoundary(root->left, ans);
    }
    ans.push_back(root->val);
}
vector<int> boundary(TreeNode* root){
    if(root == nullptr)
        return {};
    vector<int> ans;
    ans.push_back(root->val);
    leftBoundary(root->left, ans);
    if(root->left != nullptr || root->right != nullptr)
        leaf(root, ans);
    rightBoundary(root->right, ans);
    return ans;
}

/* also optimal,
void populateGrid(map<pair<int,int>,vector<int>>& grid_mapping,TreeNode* root, int i, int j){
    if(root == nullptr)
        return;
    grid_mapping[{j,i}].push_back(root->val);
    populateGrid(grid_mapping, root->left, i+1, j-1);
    populateGrid(grid_mapping, root->right, i+1, j+1);
}
vector<vector<int>> verticalTraversal(TreeNode* root) {
    //<col, row>, <index>
    map<pair<int,int>, vector<int>> grid_mapping;
    populateGrid(grid_mapping,root, 0, 0);
    vector<vector<int>> res;
    int curr_col = INT_MIN;
    for(auto it : grid_mapping){
        sort(it.second.begin(), it.second.end());
        if(it.first.first != curr_col){
            curr_col = it.first.first;
            res.push_back(it.second);
        }else{
            for(auto e : it.second){
                res.back().push_back(e);
            }
        }
    }
    return res;
}
*/
void populateGrid(vector<tuple<int,int,int>>& grid_ele,TreeNode* root, int i, int j){
    if(root == nullptr)
        return;
    grid_ele.push_back({j,i, root->val});
    populateGrid(grid_ele, root->left, i+1, j-1);
    populateGrid(grid_ele, root->right, i+1, j+1);
}
vector<vector<int>> verticalTraversal(TreeNode* root) {
    //<col, row>, <index>
    vector<tuple<int,int,int>> grid_mapping;
    populateGrid(grid_mapping,root, 0, 0);
    vector<vector<int>> res;
    int curr_col = INT_MIN;
    sort(grid_mapping.begin(), grid_mapping.end());
    for(auto it : grid_mapping){
        int col = get<0>(it);
        int row = get<1>(it);
        int val = get<2>(it);
        if(col != curr_col){
            curr_col = col;
            res.push_back({val});
        }else{
            res.back().push_back(val);
        }
    }
    return res;
}

vector<int> topView(TreeNode* root){
    if(root == nullptr)
        return {};
    vector<int> ans;
    map<int,int> col_ele;
    queue<pair<TreeNode*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        int qLen = q.size();
        for(int i=0;i<qLen;i++){
            auto curr = q.front();
            q.pop();
            if(col_ele.find(curr.second) == col_ele.end()){
                col_ele[curr.second] = curr.first->val;
            }
            if(curr.first->left != nullptr){
                q.push({curr.first->left,curr.second-1});
            }
            if(curr.first->right != nullptr){
                q.push({curr.first->right,curr.second+1});
            }
        }
    }
    for(auto col : col_ele){
        ans.push_back(col.second);
    }
    return ans;
}

vector<int> bottomView(TreeNode* root){
    if(root == nullptr)
        return {};
    vector<int> ans;
    map<int,int> col_ele;
    queue<pair<TreeNode*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        int qLen = q.size();
        for(int i=0;i<qLen;i++){
            auto curr = q.front();
            q.pop();
            col_ele[curr.second] = curr.first->val;
            if(curr.first->left != nullptr){
                q.push({curr.first->left,curr.second-1});
            }
            if(curr.first->right != nullptr){
                q.push({curr.first->right,curr.second+1});
            }
        }
    }
    for(auto col : col_ele){
        ans.push_back(col.second);
    }
    return ans;
}

vector<int> rightSideView(TreeNode* root) {
    if(root == nullptr)
        return {};
    vector<int> ans;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int qLen = q.size();
        TreeNode* curr;
        for(int i=0;i<qLen;i++){
            curr = q.front();
            q.pop();
            if(curr->left != nullptr){
                q.push(curr->left);
            }
            if(curr->right != nullptr){
                q.push(curr->right);
            }
        }
        ans.push_back(curr->val);
    }
    return ans;
}

bool isSymmetric(TreeNode* root) {
    if(root == nullptr){
        return true;
    }
    // <treenode, col>
    queue<TreeNode*> qLeft, qRight;
    qLeft.push(root);
    qRight.push(root);
    while(!qLeft.empty() && !qRight.empty()){
        auto left = qLeft.front().first;
        auto left_val = qLeft.front().second;
        qLeft.pop();

        auto right = qRight.front().first;
        auto right_val = qRight.front().second;
        qRight.pop();

        if(left_val != right_val*(-1) || left->val != right->val){
            return false;
        }

        if(right->right != nullptr){
            qRight.push({right->right, right_val+1});
        }
        if(right->left != nullptr){
            qRight.push({right->left,right_val-1});
        }

        if(left->left != nullptr){
            qLeft.push({left->left, left_val-1});
        }
        if(left->right != nullptr){
            qLeft.push({left->right, left_val+1});
        }
    }
    if(!qLeft.empty()){
        return false;
    }
    if(!qRight.empty()){
        return false;
    }
    return true;
}
