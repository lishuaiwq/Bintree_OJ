输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes, 否则输出No。假设输入的数组的任意两个数字都互不相同。

算法：

//因为二叉树搜索树的后续遍历结果的特性
//即最后一个一定为根节点，它比其左子树所有的元素都大，但是比其所有的右子树元素都大
//所以我们从起始元素往后走sequence[i++] < sequence[size],当前跳出来即找到第一个比根节点大的元素的换，意味着到其右子树了，
//所以此时其右子树应该都比其大while (sequence[i++]>sequence[size]);当这个走到头应该i=size，即自己和自己比
//如果i<size出来了证明不符合后续遍历的顺序
//我们以此类推，遍历所有的组合
class Solution {
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		int size = sequence.size();
		if (0 == size)
			return false;
		int i = 0;
		while (--size)
		{
			while (sequence[i++] < sequence[size]);
			while (sequence[i++]>sequence[size]);

			if (i < size)
				return false;
			i = 0;
		}
		return true;
	}
};