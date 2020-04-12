#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
	int val;
	TreeNode* l;
	TreeNode* r;
};


TreeNode* insert(int v, TreeNode* x)
{
	if (x == NULL) {		
		x = new TreeNode();
		x->val = v;
		x->l = NULL;
		x->r = NULL;
		return x;
	}
	if (v < x->val)
		x->l = insert(v, x->l);
	else
		x->r = insert(v, x->r);
	return x;
}

void dlr(TreeNode* t, vector<int> &ans_tmp)
{
	if (t != NULL) {
		ans_tmp.push_back(t->val);
		dlr(t->l, ans_tmp);
		dlr(t->r, ans_tmp);
	}
}

void lrd(TreeNode* t, vector<int> &ans_tmp)
{
	if (t != NULL) {
		lrd(t->l, ans_tmp);
		lrd(t->r, ans_tmp);
		ans_tmp.push_back(t->val);
	}
}

vector<int> getAnswer(int n, vector<int> sequence) {
	TreeNode* tree = NULL;
	TreeNode* root = NULL;
	for (int i = 0;i<int(sequence.size());++i) {
		tree = insert(sequence[i], tree);
		if (i == 0) {
			root = tree;
		}
	}
	vector<int> ans;
	dlr(root, ans);
	lrd(root, ans);

	delete tree;

	return ans;
}



int main() {
    int n;
    scanf("%d", &n);
    vector<int> sequence;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        sequence.push_back(x);
    }
    vector<int> ans = getAnswer(n, sequence);
    for (int i = 0; i < n; ++i)
        printf("%d%c", ans[i], " \n"[i == n - 1]);
    for (int i = 0; i < n; ++i)
        printf("%d%c", ans[n + i], " \n"[i == n - 1]);
    return 0;
}
