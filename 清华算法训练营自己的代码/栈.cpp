#include <bits/stdc++.h>
using namespace std;


const int N = 100005;
string Stack[N];
int n = 0, top = 1;


void push(string name) 
{
	Stack[top] = name;
	++top;
}


string pop()
{
	int tmp = --top;
	return Stack[tmp];
}

string query(int pos) 
{
	return Stack[pos];
}



int main() {
    int n;
    scanf("%d", &n);
    char name[20];
    for (; n--; ) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            scanf("%s", name);
            push(name);
        } else if (op == 2) {
            printf("%s\n", pop().c_str());
        } else {
            int pos;
            scanf("%d", &pos);
            printf("%s\n", query(pos).c_str());
        }
    }
    return 0;
}
