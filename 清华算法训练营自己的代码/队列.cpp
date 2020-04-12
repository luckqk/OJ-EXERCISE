#include "stdc++.h"
using namespace std;


const int N = 100005;

string Queue[N];
int head = 1, tail = 1;

void enqueue(string name) {
	Queue[tail] = name;
	++tail;
}


string dequeue() {
	int tmp = head;
	++head;
	return Queue[tmp];
}


string query(int pos) {
	return Queue[head+pos-1];
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
            enqueue(name);
        } else if (op == 2) {
            printf("%s\n", dequeue().c_str());
        } else {
            int pos;
            scanf("%d", &pos);
            printf("%s\n", query(pos).c_str());
        }
    }
    return 0;
}
