#include <iostream>
using namespace std;

class GameObject {
protected:
	int x, y;
public:
	GameObject(){}
	GameObject(int startX, int startY) {
		this->x = startX;
		this->y = startY;
	}
	virtual ~GameObject() {}

	virtual void move() = 0;
	virtual char getShape() = 0;
	virtual void randStart() = 0;
	
	int getX(){
		return x;
	}

	int getY(){
		return y;
	}

	bool collide(GameObject *p){
		if(this->x == p->getX() && this->y == p->getY())
			return true;
		else
			return false;
	}
};

class Human : public GameObject {
protected:
	char input;

public:
	Human(){}
	Human(int startX, int startY):
	GameObject(startX, startY) {}
	
	
	void setStartXY(char wasd){
		this->input = wasd;
	}
	
	void randStart(){
		this->x = rand() % 10;
		this->y = rand() % 20;
	}

	void move(){
		if(input == 'w')
			this->y -= 1;

		else if(input == 'a')
			this->x -= 1;

		else if(input == 's')
			this->y += 1;

		else if(input == 'd')
			this->x += 1;
		
		else
			cout << endl <<"잘 못 입력하셨습니다." << endl;
	}
	char getShape(){
		return 'H';
	}
};

class Food : public GameObject {
protected:
	bool sequence[5] = { false, }; // : Means Food's move sequence(move = true, stay = 0).
	int count; // : Counting Food's turn.(Minimum: 0, Maximum: 4)
public:
	void setSequence(){
		this->sequence[rand() % 5];
		
		int index = rand() % 4;
		if(this->sequence[index] == false)
			this->sequence[index] = true;
		else
			this->sequence[index+1] = true;
	}

	void setCount(){
		this->count = 0;
	}

	Food(){}
	Food(int startX, int startY):
	GameObject(startX, startY) {}
	void move(){
		if(count == 5){
			count = 0;
			setSequence();
		} else {
			this->x = rand() % 2;
			this->y = rand() % 2;
		}
	}
	
	char getShape(){
		return '@';
	}
	
	void randStart(){
		this->x = rand() % 10;
		this->y = rand() % 20;
	}
};

class Monster : public GameObject {
public:
	Monster(){}
	Monster(int startX, int startY):
	GameObject(startX, startY){}
	void move(){
		int monsterX = 0, monsterY = 0;

		monsterX = rand() % 2;

		if((monsterX - 2) == -2)
			monsterY = 2;
		
		else if((monsterX - 2) == -1)
			monsterY = 1;
		
		else
			monsterY = 0;
	}

	char getShape(){
		return 'M';
	}
	
	void randStart(){
		this->x = rand() % 10;
		this->y = rand() % 20;
	}
};

int main(){
	Food food;
	Monster monster;
	Human human;


	}
