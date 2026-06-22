//includes
#include <iostream>
#include <conio.h>
#include <Windows.h>
//handle
HANDLE base= GetStdHandle(STD_OUTPUT_HANDLE); 
//using
using namespace std;
/*forloop*/#define forrange(var,range) for(int var=0;var<range;var++)
/*len*/ #define len(array) sizeof(array)/sizeof(array[0])
namespace windows
{
/*clear*/#define clear system("cls"); 
/*Sleep*/#define xleep Sleep
/*pause*/#define pause system("pause");
}
//#define append(array,object) array[0]=object;
//Screen

namespace Screen
{
/*width,hight*/	const int width = 6, height = 9;/*is_running*/ bool is_running;
}
int Score;
//class car
class car
{
public:
	//vars
	int x, y, speed,color; char shape, move_left, move_right, move_rightC, move_leftC;
	//__init__
	void __init__(int x, int y, int speed, char shape, char move_left, char move_right, char move_leftC, char move_rightC,int color)
	{
		this->x = x%Screen::width; this->y = y%Screen::height; this->speed = speed; this->shape = shape; this->move_left = move_left; this->move_right = move_right; this->move_leftC = move_leftC; this->move_rightC = move_rightC;
		this->color = color;
	}
	//__init__ overload
	void __init__(int x, int y, int speed, char shape,int color) { this->x = x; this->y = y; this->shape = shape; this->speed = speed; this->color = color; }
	//moves
	void Move_right(int speed) { x += speed; }
	void Move_up(int speed) { y -= speed; }
	//control
	void control()

	{
		if (_kbhit())
		{
			char key = _getch();
			if (key == move_right || key == move_rightC) { Move_right(speed); }
			else if (key == move_left || key == move_leftC) { Move_right(-speed); }
			else if (key == 'r'||key=='R') { Screen::is_running = false; }
			else if (key == 'p' || key == 'P') { system("cls");system("color 07"); printf("Press Any Key To Continue..."); _getch(); }
		}
	}
	/*==*/bool operator ==(car auther) { return this->x == auther.x && this->y == auther.y; }
	/*=*/void operator =(car auther) 
	{
		x = auther.x; y = auther.y; shape = auther.shape; speed = auther.speed;
		move_left = auther.move_left; move_leftC = auther.move_leftC; move_right = auther.move_right; move_rightC = auther.move_rightC;
	}
	/*draw*/void draw()
	{
		
		SetConsoleTextAttribute(base, color);
		cout << shape; 
	}
};
/*car define;
car cars{define};
car new_car(int x, int y, int speed, char shape)
{
	car self; self.__init__(x, y, speed, shape);
	append(cars, self);
	return self;
}
car new_car(int x,int y,int speed,char shape,char move_left,char move_right,char move_leftC,char move_rightC)
{
	car self; self.__init__(x, y, speed, shape, move_left, move_right, move_leftC, move_rightC);
	car self; self.__init__(x, y, speed, shape, move_left, move_right, move_leftC, move_rightC);
	return self;
}*/
//new car
car car1;
car enemy;
//cars

#define new_enemy  enemy.__init__(car1.x,int(Score/9)%Screen::height,0,car1.shape,3);if(enemy.y>=Screen::height){enemy.x+=(rand()%3)-1;} 

//var
void setup()
{
	srand(time(0));
	Screen::is_running = true;
	//__init__
	car1.__init__(((rand() % 2) + 1)*2, Screen::height - 1, 1, 'O', 'a', 'd', 'A', 'D',12);
	/*new_enemy*/new_enemy;
	/*Score*/Score = 0;
}