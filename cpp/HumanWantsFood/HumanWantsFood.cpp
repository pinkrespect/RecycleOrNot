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
	Human(){
		this->x = rand() % 10;
		this->y = rand() % 20;
	}
	Human(int startX, int startY):
	GameObject() {
	}
	
	
	void setStartXY(char wasd){
		this->input = wasd;
	}
	
	void move(){
		if(input == 'w' && this->y > 0)
			this->y -= 1;

		else if(input == 'a' && this->x > 0)
			this->x -= 1;

		else if(input == 's' && this->y < 20)
			this->y += 1;

		else if(input == 'd' && this->x < 10)
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
		setCount();
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

	Food(){
		this->x = rand() % 10;
		this->y = rand() % 20;
	}
	Food(int startX, int startY):
	GameObject(startX, startY) {
	}
	void move(){
		// Food.move() makes move Food object random direction once.
		if(count == 5){
			setSequence();
		} else {
			int directionX = 0;
			int directionY = 0;

			directionX = rand() % 2 - 1;
			directionY = rand() % 2 - 1;
		
			if(directionX == 1 && this->getX() < 10)
				this->x += directionX;
			else if(directionX == -1 && this->getX() > 0)
				this->x += directionX;

			if(directionY == 1 && this->getY() < 20)
				this->y += directionY;
			else if(directionY == -1 && this->getY() > 0)
				this->y += directionY;	

			this->count++;	
		}
	}
	
	char getShape(){
		return '@';
	}
	
};

class Monster : public GameObject {
public:
	Monster(){
		this->x = rand() % 10;
		this->y = rand() % 20;
	}
	Monster(int startX, int startY):
	GameObject(startX, startY){
	}
	void move(){
		// Monster.move() makes move monster objects twice for random directions.
		int monsterX = 0;
		int monsterY = 0;
		int directionX = 0;
		int directionY = 0;

		monsterX = rand() % 2;

		if((monsterX - 2) == -2)
			monsterY = 2;
		
		else if((monsterX - 2) == -1)
			monsterY = 1;


		directionX = rand() % 2 - 1;
		directionY = rand() % 2 - 1;
		
		if(directionX == 1 && this->getX() < 10)
			this->x += directionX * monsterX;
		else if(directionX == -1 && this->getX() > 0)
			this->x += monsterX * directionX;
		else
			this->x += monsterX;

		if(directionY == 1 && this->getY() < 20)
			this->y += directionY * monsterY;
		else if(directionY == -1 && this->getY() > 0)
			this->y += directionY * monsterY;	
		else
			this->y += monsterY;
	}

	char getShape(){
		return 'M';
	}
};

int main(){
	Food food;
	Monster monster;
	Human human;

	while(true){
		char gameboard[10][20];
		char input;
		for(int x = 0; x < 10; x++){
			for(int y = 0; y < 20; y++){
				if(food.getX() == x && food.getY() == y)
					gameboard[x][y] = food.getShape();
				else if(monster.getX() == x && monster.getY() == y)
					gameboard[x][y] = monster.getShape();
				else if(human.getX() == x && human.getY() == y)
					gameboard[x][y] = human.getShape();
				else
					gameboard[x][y] = '~';
				cout << gameboard[x][y];
			}
			cout << endl;
		}
		cout << "이동 방향을 입력하세요. >>"; 
		cin >> input;
		human.setStartXY(input);
		human.move();
		monster.move();
		food.move();
	
		if(human.collide(&food) == true){
			cout << "인간 승리!" << endl;
			return 0;
		}else if(monster.collide(&human) == true){
			cout << "몬스터 승리!" << endl;
			return 0;
		}
	}
}
