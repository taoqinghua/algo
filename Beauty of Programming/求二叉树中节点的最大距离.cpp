#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;


class TreeNode {
public:
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void display(TreeNode* root, int col = 0) {
  if(root == 0)    
    return;
  display(root->right, col + 1);
  for(int i = 0; i < col; ++i)   
    std::cout<<"| ";
  cout<<"|"<<root->val<<std::endl;
  display(root->left, col + 1);
}
int getHeight(TreeNode* root) {
  int cnt = 0, i, j, cur = 0, next = 1;
  vector<TreeNode*> layers[2];
  layers[cur].push_back(root);
  while (!layers[cur].empty()) {
    ++cnt;
    for (i = 0; i < layers[cur].size(); ++i) {
      if (layers[cur][i]->left)
        layers[next].push_back(layers[cur][i]->left);
      if (layers[cur][i]->right)
        layers[next].push_back(layers[cur][i]->right);
    } 
    layers[cur].clear();
    cur = !cur;
    next = !next;
  }
  return cnt;
}
int getMaxDistance(TreeNode* root) {
  int lcount = 0, rcount = 0, res = 0;
  if (root == NULL)
    return 0;
  while (root->left && !root->right || !root->left && root->right) {
    ++res;
    if (root->left)
      root = root->left;
    else
      root = root->right;
  }
  if (root->left && root->right) {
    lcount = getHeight(root->left);
    rcount = getHeight(root->right);
  }
  return res + lcount + rcount;
}
int main() {

  TreeNode *root = new TreeNode(0);
  root->left = new TreeNode(1);
  root->right = new TreeNode(2);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(4);
  root->right->left = new TreeNode(5);
  root->right->right = new TreeNode(6);
  root->right->right->right = new TreeNode(7);

  display(root);
  int res = getMaxDistance(root);

  return 0;
}


/*#include <iostream>
using namespace std;
struct NODE
{
	NODE *pLeft;
	NODE *pRight;
};
struct RESULT
{
	int nMaxDistance;
	int nMaxDepth;
};

RESULT GetMaximumDistance(NODE* root)
{
	if(!root)
	{
		RESULT empty={0,-1};
		return empty;
	}

	RESULT lhs=GetMaximumDistance(root->pLeft);
	RESULT rhs=GetMaximumDistance(root->pRight);

	RESULT reslult;
	reslult.nMaxDepth=max(lhs.nMaxDepth+1,rhs.nMaxDepth+1);
	reslult.nMaxDistance=max(max(lhs.nMaxDistance,rhs.nMaxDistance),lhs.nMaxDepth+rhs.nMaxDepth+2);
	return reslult;
}
void Link(NODE* nodes,int parent,int left,int right)
{
	if(left!=-1)
		nodes[parent].pLeft=&nodes[left];
	if(right!=-1)
		nodes[parent].pRight=&nodes[right];
}

int main()
{
	NODE test1[9]={0};
	Link(test1,0,1,2);
	Link(test1,1,3,4);
	Link(test1,2,5,6);
	Link(test1,3,7,-1);
	Link(test1,5,-1,8);
	cout<<"test1:"<<GetMaximumDistance(&test1[0]).nMaxDistance<<endl;

	// P. 242 Graph 3-13 left
    NODE test2[4] = { 0 };
    Link(test2, 0, 1, 2);
    Link(test2, 1, 3, -1);
    cout << "test2: " << GetMaximumDistance(&test2[0]).nMaxDistance << endl;
 
    // P. 242 Graph 3-13 right
    NODE test3[9] = { 0 };
    Link(test3, 0, -1, 1);
    Link(test3, 1, 2, 3);
    Link(test3, 2, 4, -1);
    Link(test3, 3, 5, 6);
    Link(test3, 4, 7, -1);
    Link(test3, 5, -1, 8);
    cout << "test3: " << GetMaximumDistance(&test3[0]).nMaxDistance << endl;
 
    // P. 242 Graph 3-14
    // Same as Graph 3-2, not test
 
    // P. 243 Graph 3-15
    NODE test4[9] = { 0 };
    Link(test4, 0, 1, 2);
    Link(test4, 1, 3, 4);
    Link(test4, 3, 5, 6);
    Link(test4, 5, 7, -1);
    Link(test4, 6, -1, 8);
    cout << "test4: " << GetMaximumDistance(&test4[0]).nMaxDistance << endl;

}
*/




/*
struct Node
{
	Node* pLeft;
	Node* pRight;
	int nMaxLeft;
	int nMaxRight;
	char value;
};

int nMaxLen=0;
void FindMaxLen(Node *pRoot)
{
	if(pRoot==NULL)
		return;

	if(pRoot->pLeft==NULL)
		pRoot->nMaxLeft=0;
	if(pRoot->pRight==NULL)
		pRoot->nMaxRight=0;

	if(pRoot->pLeft!=NULL)
		FindMaxLen(pRoot->pLeft);
	if(pRoot->pRight!=NULL)
		FindMaxLen(pRoot->pRight);

	if(pRoot->pLeft!=NULL)
	{
		int temp=0;
		if(pRoot->pLeft->nMaxLeft>pRoot->pLeft->pMaxRight)
			temp=pRoot->pLeft->nMaxLeft+1;
		else
			temp=pRoot->pLeft->pMaxRight+1;
	}

	if(pRoot->pRight!=NULL)
	{
		int temp=0;
		if(pRoot->pRight->nMaxLeft>pRoot->pRight->pMaxRight)
			temp=pRoot->pRight->nMaxLeft+1;
		else
			temp=pRoot->pRight->pMaxRight+1;
	}
	if(pRoot->nMaxLeft+pRoot->nMaxRight>nMaxLen)
		nMaxLen=pRoot->nMaxLeft+pRoot->nMaxRight;
}*/