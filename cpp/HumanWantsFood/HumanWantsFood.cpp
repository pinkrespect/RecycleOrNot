#include <iostream>
using namespace std;

class GameObject {
protected:
	int distance;
	int x, y;
public:
	GameObject(int startX, int startY, int distance) {
		this->x = startX;
		this->y = startY;
		this->distance = distance;
	}

	virtual ~GameObject() {}

	virtual void move() = 0;
	virtual char getShape() = 0;

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

};

class Food : public GameObject {
protected:
	int count; // Integer variable count checks Food's turn.
	int moved; // Integer variable moved checks Food moved 2 time.
public:
	
};

class Monster : public GameObject {

};

int main(){
	}
