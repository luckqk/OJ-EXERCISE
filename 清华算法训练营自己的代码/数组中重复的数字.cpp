/*******************************
寻找数组中重复的数字
输入：	数组内数的个数
		各个数
输出：	重复的数由小到大
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
	cout << "请输入数组的大小" << endl;
	cin >> array_num;
	if (array_num > 0) {
		cout << "请输入数组内各个数字" << endl;
		for (int i = 0;i < array_num;++i) {
			cin >> num_tmp;
			array.push_back(num_tmp);
		}
		repeated_num = searchRepeatedNum(array_num, array);
	}
	else {
		cout << "数组大小必须大于0" << endl;
	}
	cout << "重复数字如下" << endl;
	for (int i = 0;i < repeated_num.size(); ++i) {
		cout << repeated_num[i] << endl;
	}
	return 0;
}