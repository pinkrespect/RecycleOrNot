#include <iostream>
#include <string>

using namespace std;
class ArrayUtility2 {
public:
	static int* concat(int s1[], int s2[], int size);
	static int* remove(int s1[], int s2[], int size, int& retSize);
}

int* ArrayUtility2::concat(int s1[], int s2[], int size) {
	int *p = new int[size];
	for(int i = 0; i < 5; i++) {
		p[i] = s1[i];
	}
	for (int i = 5;i < 10;i++) {
		p[i] = s2[i-5];
	}
	return p;
	delete []p;
}

int* ArrayUtility2::remove(int s1[], int s2[], int size, int& retSize) {
	int *p = new int[];
	int pc = 0;
	for (int i = 0;i < 5;i++) {
		if (s1[i] == s2[k]){
			flag++;
		}
	}
	if(flag == 0) {
		p[pc] = s1[i];
		pc++;
	}
	retSize = pc + 1;
	return p;
	delete []p;
}

int main() {
	ArrayUtility2 AU2;
	cout << "정수 5개 입력 to 배열 x";
	int x[5];
	for (int i = 0;i < 5; i++) {
		cin >> x[i];
	}
	for (int i = 0; i < 10; i++) {
		cout << a.concat(x, y, 10)[i] << ' ';
	}
	cout << endl;

	int retSize = 1;
	cout << "배열 x에서 y를 뺀 결과를 출력한다. 개수는 " << retSize << endl;
	for (int i = 0; i < retSize; i++) {
		cout << a.remove(x, y, 5, retSize)[i] << ' ';
	}
	cout << endl;
}


