
1.��ʵ�������������ֱ��������л��ͷ����л�������


�������л��������������������еĽ��Ԫ��ƴ�ӳ�һ���ַ����������л���ƴ�ӵ��ַ�����ɶ�����

class Solution {
public:
	char* Serialize(TreeNode *root) {//���л�������
		if (root == NULL)//���������Ϊ�յĻ��򷵻�
			return NULL;
		string str;//�����������л���Ķ�����
		Serialize(root, str);//���л�������
		char *ret = new char[str.length() + 1];
		int i;
		for (i = 0; i < str.length(); i++){
			ret[i] = str[i];//��Ϊ����ֵ��һ��char*��������Ҫ��string��char*
		}
		ret[i] = '\0';
		return ret;
	}
	void Serialize(TreeNode *root, string& str){//�������л�������
		if (root == NULL){//�����ǰ���Ϊ�����á�#��ʾ��
			str += '#';
			return;
		}
		string r = to_string(root->val);//������ת��Ϊ�ַ���
		str += r;//ƴ��һ���ַ�.�����Ǹ��ڵ���ַ��������ö���������
		str += ',';//��
		Serialize(root->left, str);//����������
		Serialize(root->right, str);//����������
	}

	TreeNode* Deserialize(char *str) {
		if (str == NULL)
			return NULL;
		TreeNode *ret = Deserialize(&str);

		return ret;
	}
	TreeNode* Deserialize(char **str){//���ڵݹ�ʱ���᲻�ϵ�����ȡ�ַ���
		if (**str == '#'){  //����һ��Ҫ��**str,
			++(*str);         //�Ա�֤�õ��ݹ��ָ��strָ��δ����ȡ���ַ�
			return NULL;
		}
		int num = 0;
		while (**str != '\0' && **str != ','){//���ַ���ת��Ϊ����
			num = num * 10 + ((**str) - '0');
			++(*str);
		}
		TreeNode *root = new TreeNode(num);//�������ڵ�
		if (**str == '\0')//����\0֤���ַ�����ȡ����ˣ��򷵻�
			return root;
		else
			(*str)++;//������
		root->left = Deserialize(str);
		root->right = Deserialize(str);
		return root;
	}
};