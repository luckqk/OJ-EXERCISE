/*******************************
���ַ����еĿո��滻��%20
���룺	�ַ���
�����	�޸ĺ���ַ���
********************************/

#include <bits/stdc++.h>
using namespace std;

int changeText(string &cText)
{
	if (cText.empty()) {
		return -1;
	}
	string::iterator pt1, pt2;
	int cnt = 0;
	int original_size, new_size;
	original_size = cText.size();
	for (pt1 = cText.begin();pt1 != cText.end();++pt1) {
		if (*pt1 == ' ')
			++cnt;
	}
	new_size = original_size + cnt * 2;
	cText.resize(new_size);
	pt2 = cText.end()-1;
	pt1--;
	while (pt1 > cText.begin() && pt1 < pt2) {
		if (*pt1 == ' ') {
			*pt2-- = '0';
			*pt2-- = '2';
			*pt2-- = '%';
		}
		else {
			*pt2-- = *pt1;
		}
		pt1--;
	}
	if (pt1 == cText.begin()) {
		if (*pt1 == ' ') {
			*pt2-- = '0';
			*pt2-- = '2';
			*pt2 = '%';
		}
		else {
			*pt2 = *pt1;
		}
	}
	return 1;
}

int main()
{
	string text;
	int res;
	cout << "�������ַ���" << endl;
	getline(cin, text);
	res = changeText(text);
	if (res != -1) {
		cout << "�޸ĺ���ַ�������" << endl;
		cout << text << endl;
	}
	else {
		cout << "δ������Ч�ַ�" << endl;
	}
	return 0;
}