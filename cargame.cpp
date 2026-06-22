//includes
#include <iostream>
#include "Header.hpp"
#include <Windows.h>
//using``	`
using namespace std;
using namespace windows;
//y
#define y_ y == Screen::height
#define x_ x == Screen::width  
//draw
void draw()
{
/*y*/	forrange(y, Screen::height + 1)
	{
	/*x*/	forrange(x, Screen::width + 1)
		{
	/*color*/	if (x_ || y_) { SetConsoleTextAttribute(base, 2); }
	/*print -*/	if (y_) { printf("%c", '-'); }
	/*print |*/	else if (x_) { printf("%c",'|'); }
	/*draw plr*/		else if (x == car1.x && y == car1.y) { car1.draw(); }
	/*draw enm*/		else if (x == enemy.x && y == enemy.y) { enemy.draw(); }
	/*deaw space*/		else { cout << ' '; }
		}
	printf("%c", '\n');
	}
SetConsoleTextAttribute(base, 6);
	printf("Your Score:%d%s", Score,"\nPress 'A' to move left\nPress 'D' to move right\nPress 'R' to Back to Menu\nPress 'P' To Pause");
	xleep(50);
	clear;
}
void control() 
{
	//LOSE
	if (car1 == enemy) 
	{ 
		system("color 07");
		Screen::is_running = false;
		//lose
		char lose[] = " You lose";
#ifndef  max_x
#define max_x len(lose)+2
#endif
		//for loop
		forrange(y, 7)
		{
			for (size_t x = 0; x <= max_x; x++)
			{
				if (x == 0 || x == max_x || y == 0 || y == 6) { cout << '*'; }
				else if (y == 3 && x > 0 && x <= len(lose)) { cout << lose[x-1]; }
				else { cout << ' '; }
			}
			
		
			cout << "\n";
		}
		pause;
	}
	car1.control();
	if (car1.x < 0) { car1.x = 0; }
	else if (car1.x > Screen::width-1) { car1.x =Screen::width-1; }
	enemy.y++;
	int default_speed = enemy.speed;
	if (enemy.y >= Screen::height) { new_enemy; Score++; enemy.speed++; }
}
//main
void Maingame()
{
	setup();
	while (Screen::is_running)
	{
		draw();
		control();
	}
}
int main()
{
	SetConsoleTitleA("Car Game");
	while (true)
	{
		system("color 07 ");
		cout << "Menu:\n";
		string Menu[]
		{
			"Exit"
			,"Enter to Game"

		};
		forrange(i, len(Menu))
		{
			cout << "Press'" << i << "'To Enter in " << Menu[i]<<"\n";
		}
		bool run = true;
		while (run)
		{
			switch (_getch())
			{
			case('0'):exit(0);
			case('1'):Maingame();
			default:clear;
			}
			run = !run;


		}
	}
}