/*******************************
Ѱ���������ظ�������
���룺	���������ĸ���
		������
�����	�ظ�������С����
********************************/
#include <bits/stdc++.h>
using namespace std;

vector<int> repeated_num;

vector<int> searchRepeatedNum(const int num, vector<int> array_tmp)
{
	for (int i = 0;i < num;++i) {
		while(array_tmp[i] != i) {
			if (array_tmp[array_tmp[i]] == array_tmp[i]) {
				repeated_num.push_back(array_tmp[i]);
				break;
			}
			else {
				swap(array_tmp[array_tmp[i]], array_tmp[i]);
			}
		}
	}
	unique(repeated_num.begin(), repeated_num.end());
	sort(repeated_num.begin(), repeated_num.end());
	return repeated_num;
}

int main()
{
	int array_num,num_tmp;
	vector<int> array;
	cout << "����������Ĵ�С" << endl;
	cin >> array_num;
	if (array_num > 0) {
		cout << "�����������ڸ�������" << endl;
		for (int i = 0;i < array_num;++i) {
			cin >> num_tmp;
			array.push_back(num_tmp);
		}
		repeated_num = searchRepeatedNum(array_num, array);
	}
	else {
		cout << "�����С�������0" << endl;
	}
	cout << "�ظ���������" << endl;
	for (int i = 0;i < repeated_num.size(); ++i) {
		cout << repeated_num[i] << endl;
	}
	return 0;
}