#include <iostream>
using namespace std;
 
class Stack {
    int stack[10];
    int top;
public :
    Stack() { top=-1; }
    Stack& operator <<(int n) {
        top++;
        stack[top] = n;
        return *this;
    }
    Stack operator >>(int &n) {
        n = stack[top];
        top--;
        return *this;
    }
    bool operator !() {
        if( top == -1 ) return true;
        else return false;
    }
};
 
int main() {
    Stack stack;
    stack << 3 << 5 << 10;
    while(true) {
        if(!stack) break;
        int x;
        stack >> x;
        cout << x << ' ';
    }
    cout << endl;
}


