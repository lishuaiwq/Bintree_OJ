������������ת��Ϊ˫��ѭ������

�㷨��ʹ�ö�����������������У�����һ����־λָ��ǰλ�õ���һ����㣬�������Ϊpre�����ǾͿ��Խ�if(pre)
{
	(*pre)->right = pRoot;
}
pRoot->left = *pre;
pre = Proot;

//���������㷨�ĺ��Ĵ���,Ȼ����ǽ������������Ķ��������������������ȥ

���룺�ݹ�汾

/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/
class Solution {
public:
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		if (pRootOfTree == NULL)
			return NULL;
		TreeNode* pre = NULL;
		Trans(pRootOfTree, &pre);//��Ϊֻ�Ǹı�ָ���ڲ���next���ı�ָ����������ݣ����Բ���Ҫ��
		while (pRootOfTree->left)
		{
			pRootOfTree = pRootOfTree->left;
		}
		return pRootOfTree;
	}
	void Trans(TreeNode* pRoot, TreeNode** prev)
	{
		if (pRoot)
		{
			//if(pRoot->left!=NULL)
			Trans(pRoot->left, &(*prev));
			if (*prev)//prev������Null
			{
				(*prev)->right = pRoot;
			}
			pRoot->left = *prev;
			*prev = pRoot;
			//   if(pRoot->right!=NULL)
			Trans(pRoot->right, &(*prev));
		}
	}
};

���룺�ǵݹ�İ汾

��Ҫ�Ƕ�����������ǵݹ����

ʹ��ջ������������ȫ��ѹ��ջ�У�while(cur){ s.push(cur);cur=cur->next }Ȼ��Ԫ�ص������ж��Ƿ���������������еĻ�������cur=cur->right������cur=NULL,

�����Ƕ���������������ǵݹ�ĺ��Ĵ��룬ֻ��Ҫ�������ĺ��Ĵ�����ȥ�ľͿ�����

/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/
class Solution {
public:
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		if (pRootOfTree == NULL)
			return NULL;
		stack<TreeNode*> s;
		TreeNode* cur = pRootOfTree;
		TreeNode* prev = NULL;
		while (cur || !s.empty())
		{
			while (cur)
			{
				s.push(cur);
				cur = cur->left;
			}
			cur = s.top();
			if (prev)
			{
				prev->right = cur;
			}
			cur->left = prev;
			prev = cur;
			s.pop();
			if (cur->right)
			{
				cur = cur->right;
			}
			else
			{
				cur = NULL;
			}
		}
		while (pRootOfTree->left != NULL)
		{
			pRootOfTree = pRootOfTree->left;
		}
		return pRootOfTree;
	}
};