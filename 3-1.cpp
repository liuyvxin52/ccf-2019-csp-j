#include <cstdio>
using namespace std;
int n;
const int max_size = 1 << 10;

int res[max_size][max_size];

void recursive(int x, int y, int n, int t) {
    if (n == 0) {
        res[x][y] = /*1->*/t/*<-1*/;
        return;
    }
    int step = 1 << (n - 1);
    recursive(/*2->*/x,y/*<-2*/, n - 1, t);
    recursive(x, y + step, n - 1, t);
    recursive(x + step, y, n - 1, t);
    recursive(/*1->*/x+step,y+step/*<-1*/, n - 1, !t);
}

int main() {
    scanf("%d", &n);
    recursive(0, 0, /*1->*/n,0 /*<-1*/);
    int size =/*1->*/ 1 << n /*<-1*/;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            printf("%d", res[i][j]);
        puts("");
    }
    return 0;
}
/*
参考答案:
t
|x,y
x+step,y+step
n,0 
1 << n 
*/