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

class Tree{

public:
    TreeNode *root;

    void preOrder(){
        stack<TreeNode*> st;
        st.push(this->root);
        while(!st.empty()){
            TreeNode* temp = st.top();
            st.pop();
            cout<<temp->val<<" ";
            if(temp->right != nullptr){
                st.push(temp->right);
            }
            if(temp->left != nullptr){
                st.push(temp->left);
            }
        }
    }

    void InOrder(){
        stack<TreeNode*> st;
        st.push(root);
        TreeNode* temp = root;
        while(!st.empty()){
            while(temp != nullptr && temp->left != nullptr){
                st.push(temp->left);
                temp = temp->left;
            }
            temp = st.top();
            st.pop();
            cout<<temp->val<<" ";
            if(temp->right != nullptr){
                st.push(temp->right);
            }
            temp = temp->right;
        }
    }

    void PostOrder(){
        stack<TreeNode*> st;
        TreeNode* temp = root;
        TreeNode* temp2;
        while(temp != nullptr || !st.empty()){
            if(temp != nullptr){
                st.push(temp);
                temp = temp->left;
            }else{
                temp2 = st.top()->right;
                if(temp2 == nullptr){
                    temp2 = st.top();
                    st.pop();
                    cout<<temp2->val<<" ";
                    while(!st.empty() && temp2 == st.top()->right){
                        temp2 = st.top();
                        st.pop();
                        cout<<temp2->val<<" ";
                    }
                }else{
                    temp = temp2;
                }
            }
        }
    }

    vector<vector<int>> All(){
        vector<vector<int>> v(3);
        stack<pair<TreeNode*, int>> st;
        st.push({root, 1});
        while(!st.empty()){
            auto curr = st.top();
            st.pop();
            if(curr.second == 1){
                v[0].push_back(curr.first->val);
                curr.second++;
                st.push(curr);
                if(curr.first->left != nullptr)
                    st.push({curr.first->left,1});
            }else if(curr.second == 2){
                v[1].push_back(curr.first->val);
                curr.second++;
                st.push(curr);
                if(curr.first->right != nullptr)
                    st.push({curr.first->right,1});
            }else{
                v[2].push_back(curr.first->val);
            }
        }
        return v;
    }
};


int main(){
    Tree t;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    t.root = root;
    vector<vector<int>> sol;
    sol = t.All();
    for(auto r: sol){
        for(auto c: r){
            cout<<c<<" ";
        }
        cout<<"\n";
    }
}
