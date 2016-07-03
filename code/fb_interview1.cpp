/**
 * Print the diagonals of a matrix, starting from the top right diagonal,
 * ending with the bottom left diagonal
 *
 * Input:
 *  1   2   3   4
 *  5   6   7   8
 *  9  10  11  12
 *
 * Output: 
 * 4 3 8 2 7 12 1 6 11 5 10 9
 */

#include <iostream>
#include <vector>
using namespace std;

void printMatrix(vector<vector<int>> &v){
  if(v.empty()) return;
  int m = v.size(), n = v[0].size(); // m = 3, n = 4
  for(int i = n-1; i>=0; i--){
    int idx = 0;
    while(idx<m && i+idx < n){
      cout<<v[idx][i+idx]<<' ';
      idx++;
    }
  }
  for(int i=1; i<m; i++){
    int idx = 0;
    while(i+idx<m && idx <n){
      cout<<v[i+idx][idx]<<' ';
	  idx++;
    }
  }
}

/**

Input : binary tree

      A
     / \
    B   C
   / \   \
  D   E   F
       \
        G

Output : 
A
BC
DEF
G

*/
struct TreeNode{
  TreeNode *left=nullptr, *right=nullptr; 
  int val;
  TreeNode(int _val):val(_val){}
};

void printBinaryTree(TreeNode *root){
  if(root == nullptr) return;
  vector<TreeNode*>v1{root}, v2;
  while(!v1.empty()){
    for(auto &i: v1){
      cout<<i->val;
      if(i->left != nullptr) v2.push_back(i->left);
      if(i->right != nullptr) v2.push_back(i->right);
    }
    cout<<endl;
    v1 = std::move(v2);
  }
}

void dfs(TreeNode *root, int layer){
  if(root == nullptr || layer < 1) return;
  if(layer == 1) cout<<root->val <<' ';
  dfs(root->left, layer-1);
  dfs(root->right, layer-1);
}

int getHeight(TreeNode *root){
  if(root == nullptr) return 0;
  int left = getHeight(root->left);
  int right = getHeight(root->right);
  return max(left, right)+1;
}

// preorder
void def_nonrecur(TreeNode *root, int layer){
  vector<TreeNode*>s{root};
  vector<int>s2{1}; //store layer
  int cur = 1;
  TreeNode* p = s.back();
  while(!s.empty()){
    p = s.back(); s.pop_back();
    cur = s2.back(); s2.pop_back();
    if(cur == layer) cout<<p->val <<' ';
    if(p->right != nullptr){
      s.push_back(p->right);
      s2.push_back(cur+1);
    }
    if(p->left != nullptr){
      s.push_back(p->left);
      s2.push_back(cur+1);      
    }
  }
}


void dfs_nonrecur_inorder(TreeNode *root, int layer) {
  vector<TreeNode*>s;
  vector<int>s2; //store layer
  int cur = 0;
  TreeNode* p = root;
  while (!s.empty() || p != nullptr) {
    while (p != nullptr) {
      s.push_back(p);
      p = p->left;
      s2.push_back(++cur);
    }
    if (!s.empty()) {
      p = s.back(); s.pop_back();
      cur = s2.back(); s2.pop_back();
      if (cur == layer)
        cout << p->val << ' ';
      p = p->right;
    }
  }
}

// space complexity is O(logN)
void printBinaryTree_dfs(TreeNode *root){
  if(root == nullptr) return;
  int h = getHeight(root);
  for(int i=1; i<=h; i++){
    dfs(root, h);
    cout<<endl;
  }
}

int main() {
	TreeNode *n1 = new TreeNode(1);
	TreeNode *n2 = new TreeNode(2);
	TreeNode *n3 = new TreeNode(3);
	TreeNode *n4 = new TreeNode(4);
	TreeNode *n5 = new TreeNode(5);
	TreeNode *n6 = new TreeNode(6);
	TreeNode *n7 = new TreeNode(7);
	n1->left = n2; n1->right = n3;
	n2->left = n4; n2->right = n5;
	n3->right = n6;
	n5->right = n7;
	printBinaryTree_dfs(n1);
	return 0;
}