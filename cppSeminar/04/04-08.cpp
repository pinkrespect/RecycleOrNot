#include <iostream>
#include <cstring>
#pragma warning(disable : 4996)

using namespace std;

class Book{
	char *title;
	int price;
public:
	Book(char* title, int price){
		int len = strlen(title);
		this->title = new char[len+1];
		strcpy(this->title, title);
		this->price = price;
	}

	Book(Book& b){
		int len = strlen(b.title);
		this->title = new char[len+1];
		strcpy(this->title, title);
		this->price = price;
	}

	~Book(){
		delete[] title;
	}

	void set(char* title, int price){
		int len = strlen(title);
		this->title = new char[len+1];
		strcpy(this->title, title);
		this->price = price;
	}

	void show() {
		cout << title << ' ' << price << "원" << endl;
	}
};

int main(){
	Book cpp('명품C++', 10000);
	Book java = cpp;
	java.set('명품자바', 12000);
	cpp.show();
	java.show();

}
