
1.请实现两个函数，分别用来序列化和反序列化二叉树


对于序列化二叉树，即将二叉树中的结点元素拼接成一个字符串、反序列化则将拼接的字符串组成二叉树

class Solution {
public:
	char* Serialize(TreeNode *root) {//序列化二叉树
		if (root == NULL)//如果二叉树为空的话则返回
			return NULL;
		string str;//用来保存序列化后的二叉树
		Serialize(root, str);//序列化二叉树
		char *ret = new char[str.length() + 1];
		int i;
		for (i = 0; i < str.length(); i++){
			ret[i] = str[i];//因为返回值是一个char*，所以需要将string给char*
		}
		ret[i] = '\0';
		return ret;
	}
	void Serialize(TreeNode *root, string& str){//重载序列化二叉树
		if (root == NULL){//如果当前结点为空则用“#表示”
			str += '#';
			return;
		}
		string r = to_string(root->val);//将整数转换为字符串
		str += r;//拼接一个字符.这里是根节点的字符，后面用逗号来区分
		str += ',';//，
		Serialize(root->left, str);//遍历左子树
		Serialize(root->right, str);//遍历右子树
	}

	TreeNode* Deserialize(char *str) {
		if (str == NULL)
			return NULL;
		TreeNode *ret = Deserialize(&str);

		return ret;
	}
	TreeNode* Deserialize(char **str){//由于递归时，会不断的向后读取字符串
		if (**str == '#'){  //所以一定要用**str,
			++(*str);         //以保证得到递归后指针str指向未被读取的字符
			return NULL;
		}
		int num = 0;
		while (**str != '\0' && **str != ','){//将字符串转换为整形
			num = num * 10 + ((**str) - '0');
			++(*str);
		}
		TreeNode *root = new TreeNode(num);//创建根节点
		if (**str == '\0')//等于\0证明字符串读取完成了，则返回
			return root;
		else
			(*str)++;//往后走
		root->left = Deserialize(str);
		root->right = Deserialize(str);
		return root;
	}
};