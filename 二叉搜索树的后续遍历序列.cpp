����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ��������������Yes, �������No���������������������������ֶ�������ͬ��
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