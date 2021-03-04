
#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

using namespace std;
//starting 
void D(int r, int c, char chr);
void I(int r, int c, char chr);
void E(int r, int c, char chr);
void G(int r, int c, char chr);
void A(int r, int c, char chr);
void M(int r, int c, char chr);
void E1(int r, int c, char chr);
void Symbol(int r, int c, char chr);

//General Purpose

void gotoRowCol(int rpos, int cpos);
void ChangeColor(int color);
void HorizontalLine(int r, int c);
void VerticalLine(int r, int c);
void Wait(int s);

//WhichStage
void WhichStage(int st);
void Stage(int r, int c);
void S(int r, int c);
void T(int r, int c);
void A(int r, int c);
void G(int r, int c);
void E(int r, int c);
void D (int r,int c);
//Couting
void Counting(int eger, int r, int c, int sig);
void one(int r, int c);
void two(int r, int c);
void three(int r, int c);
void four(int r, int c);
void six(int r, int c);
void seven(int r, int c);
void eight(int r, int c);
void nine(int r, int c);
void zero(int r, int c);
void Square(int r, int c);

void MakeList(int *&person, int ip);  //Initializes with zero
void Joining(int *&persons, int &ip, int p, int sig);
int DeathCountGen();

//Arrangment&Execution
void Arrangement(int *persons, int ip);
void Lenth_Width(int &l, int &w, int ip);
void Execution(int *persons, int ip, int dc, int rang, int &cor, char ch);
void ExecutionMessage(int r, int c, char ch);
void CorpseRemoval(int *&persons, int &ip, int c);

void Ending(int *p);


int main()
{
	int r=0, c=0;
	char chr = -37;
	while (true) {
		ChangeColor(11);
		D(r, c, chr);
		ChangeColor(11);
		I(r, c, chr);
		ChangeColor(11);
		E(r, c, chr);
		ChangeColor(11);
		cout << endl << endl << endl << endl;
		G(r, c, chr);
		ChangeColor(11);
		A(r, c, chr);
		ChangeColor(11);
		M(r, c, chr);
		ChangeColor(11);
		E1(r, c, chr);
		ChangeColor(11);
		Symbol(r, c, chr);
		Wait(4);
			system("CLS");
			cout << "  \n\n\n\n\n\n\n\n\n\n\n\n\n\n                               Loading   " << endl;
			for (int i = 0; i < 20; i++)
			{
				gotoRowCol(15, i + 25);
					cout << chr;
					Wait(3);
			}
			srand(time(NULL));
			int *persons = NULL;
			int p = 0, ip = 0, dc = 0, st = 1;      
			int signal = 0, corpse = 0, ind = 0;
			do {
				system("CLS");
				ChangeColor(10);
				cout << "How many people Added (Min : 2 and Max : 20) ";
				ChangeColor(16);
				ChangeColor(12);
				cin >> ip;
			} while (ip > 20 || ip < 2);
			do {
				system("CLS");
				WhichStage(st);                     
				if (st < 5)
				{
					st++;
					Joining(persons, ip, p, signal);     
				}
				else
				{
					st = 5;
				}
				Arrangement(persons, ip);              
				signal = 1;
				dc = DeathCountGen();                    
				ind = 0;
				do
				{
					if (ind > ip - 1) ind = 0;
					dc--;
					Counting(dc, 20, 9, signal);         
					Execution(persons, ip, dc, ind, corpse, 'n');        
					ind++;
				} while (dc != 0);
				CorpseRemoval(persons, ip, corpse);             
			} while (ip != 1);
			Ending(persons);
			delete[] persons;
			return 0;
		
	}
}

void Ending(int *p)
{
	system("CLS");
	ChangeColor(10);
	gotoRowCol(20, 65);
	cout << "*************************";
	gotoRowCol(21, 65);
	ChangeColor(12);
	cout << p[0];
	ChangeColor(10);
	cout << "  is Survived "<<endl;
	cout << "                                                          ************************"<<endl;
	ChangeColor(15);
}
void CorpseRemoval(int *&persons, int &ip, int c)
{
	int j = 0;
	int *temp = new int[ip - 1];
	for (int i = 0; i < ip; i++)
	{
		if (persons[i] != persons[c])
		{
			temp[j] = persons[i];
			j++;
		}
	}
	delete[] persons;
	ip -= 1;
	persons = temp;
}
void Execution(int *persons, int ip, int dc, int rang, int &cor, char ch)
{
	ChangeColor(15);
	int l = 0, w = 0;
	Lenth_Width(l, w, ip);
	int ind = 0;
	int c = 0;
	int r = 0;
	int i = 0;
	if (ip >= 20 && ip <= 40)
	{
		c = 60;
		r = 21;
	}
	else if (ip >= 1 && ip < 20)
	{
		c = 70;
		r = 21;
	}
	else if (ip > 40)
	{
		c = 45;
		r = 21;
	}
	for (; i < l; i++)
	{
		if (i == rang && dc != 0)
		{
			gotoRowCol(r, c);
			ChangeColor(9);
			cout << persons[ind];
			c += 6;
		}
		else if (i == rang && dc == 0)
		{
			gotoRowCol(r, c);
			ChangeColor(12);
			cout << persons[ind];
			cor = ind;
			Wait(5);
			ExecutionMessage(r, c - 1, ch);
			c += 6;
		}
		else
		{
			gotoRowCol(r, c);
			ChangeColor(15);
			cout << persons[ind];
			c += 6;
		}
		ind++;
	}
	for (; i < l + w; i++)
	{
		gotoRowCol(r, c);
		if (i == rang && dc != 0)
		{
			ChangeColor(9);
			cout << persons[ind];
		}
		else if (i == rang && dc == 0)
		{
			ChangeColor(12);
			cout << persons[ind];
			cor = ind;
			Wait(5);
			ExecutionMessage(r, c, ch);
		}
		else
		{
			ChangeColor(15);
			cout << persons[ind];
		}
		ind++;
		r += 3;
	}
	for (; i < (2 * l) + w; i++)
	{
		gotoRowCol(r, c);
		if (i == rang && dc != 0)
		{
			gotoRowCol(r, c);
			ChangeColor(9);
			cout << persons[ind];
			c -= 6;
		}
		else if (i == rang && dc == 0)
		{
			gotoRowCol(r, c);
			ChangeColor(12);
			cout << persons[ind];
			cor = ind;
			Wait(5);
			ExecutionMessage(r, c - 1, ch);
			c -= 6;

		}
		else
		{
			gotoRowCol(r, c);
			ChangeColor(15);
			cout << persons[ind];
			c -= 6;
		}
		ind++;
	}
	for (; i < ((2 * l) + (2 * w)); i++)
	{
		gotoRowCol(r, c);
		if (ind > ip - 1)
		{
			char box = -37;
			ChangeColor(4);
			cout << box;
		}
		
		else
		{
			if (i == rang && dc != 0)
			{
				ChangeColor(9);
				cout << persons[ind];
			}
			else if (i == rang && dc == 0)
			{
				ChangeColor(12);
				cout << persons[ind];
				cor = ind;
				Wait(5);
				ExecutionMessage(r, c - 1, ch);
			}
			else
			{
				ChangeColor(15);
				cout << persons[ind];
			}
		}
		ind++;
		r -= 3;
	}
	Wait(5);
	ChangeColor(15);
}
void ExecutionMessage(int r, int c, char ch)
{
	int mr, mc;
	bool notclick = true;
	while (notclick) {
		if (ch == 'y')
		{
			
		}
		else
		{
			mr = r;
			mc = c;
		}
		if ((mr == r || mr == r + 1 || mr == r - 1 || mr == r + 2 || mr == r - 2) && (mc == c || mc == c + 1 || mc == c - 1 || mc == c + 2 || mc == c - 2))
		{
			notclick = false;
			r -= 1;
			c -= 2;
			gotoRowCol(r, c);
			
			gotoRowCol(r + 1, c);
			
			gotoRowCol(r + 2, c);
			
			Wait(8);
			gotoRowCol(r, c);
			cout << "        ";
			gotoRowCol(r + 1, c);
			cout << "        ";
			gotoRowCol(r + 2, c);
			cout << "        ";
		}
	}
}
void Arrangement(int *persons, int ip)
{
	int l = 0, w = 0;
	Lenth_Width(l, w, ip);
	int ind = 0;
	int c = 0;
	int r = 0;
	if (ip >= 20 && ip <= 40)
	{
		c = 60;
		r = 21;
	}
	else if (ip >= 1 && ip < 20)
	{
		c = 70;
		r = 21;
	}
	else if (ip > 40)
	{
		c = 45;
		r = 21;
	}
	for (int i = 0; i < l; i++)
	{
		gotoRowCol(r, c);
		cout << persons[ind];
		ind++;
		c += 6;
	}
	for (int i = 0; i < w; i++)
	{
		gotoRowCol(r, c);
		cout << persons[ind];
		ind++;
		r += 3;
	}
	for (int i = 0; i < l; i++)
	{
		gotoRowCol(r, c);
		cout << persons[ind];
		ind++;
		c -= 6;
	}
	for (int i = 0; i < w; i++)
	{
		gotoRowCol(r, c);
		if (ind > ip - 1)
		{
			char box = -37;
			ChangeColor(4);
			cout << box;
		}
		else
		{
			cout << persons[ind];
		}
		ind++;
		r -= 3;
	}
}
void Lenth_Width(int &l, int &w, int ip)
{
	l = ip / 4;
	w = (ip - 2 * l) / 2;
	if (((2 * l) + (2 * w)) != ip)
	{
		l++;
	}
}
int DeathCountGen()
{
	srand(time(NULL));
	int dc = rand() % 8 + 2;
	dc++;
	return dc;
}
void MakeList(int *&persons, int ip)
{
	for (int i = 0; i < ip; i++)
	{
		persons[i] = 0;
	}
}
void Joining(int *&persons, int &ip, int p, int sig)
{
	ChangeColor(12);
	if (sig == 0)
	{
		persons = new int[ip];
		MakeList(persons, ip);
		for (int i = 0; i < ip; i++)
		{
			*(persons + i) = i + 1;
		}
		gotoRowCol(13, 50);
		cout << ip;
		ChangeColor(14);
		cout << " people have joined ";
	}
	else
	{
		p = rand() % 4 + 1;
		int *temp = new int[ip + p];
		int val = persons[ip - 1];
		for (int i = 0; i < ip + p; i++)
		{
			if (i < ip)
			{
				temp[i] = persons[i];
			}
			else
			{
				temp[i] = val + 1;
				val++;
			}
		}
		delete[] persons;
		persons = temp;
		ip += p;
		gotoRowCol(13, 50);
		cout << p;
		ChangeColor(14);
		cout << " more people have joined in to test their luck";
	}
	ChangeColor(15);
	Wait(5);
}
void WhichStage(int st)
{
	int r = 3;
	int c = 45;
	ChangeColor(9);
	Stage(r, c);
	HorizontalLine(r + 4, c + 44);
	Counting(st, r, c + 55, 0);
	ChangeColor(8);
	Wait(5);
}
void Square(int r, int c)
{
	for (int i = c; i < c + (4 * 5); i += 4)
	{
		HorizontalLine(r, i);
	}
	for (int i = r + 1; i < r + (3 * 4); i += 3)
	{
		VerticalLine(i, (c - 1) + (4 * 5));
	}
	for (int i = r + 1; i < r + (3 * 4); i += 3)
	{
		VerticalLine(i, c);
	}
	for (int i = c; i < c + (4 * 5); i += 4)
	{
		HorizontalLine(r + (3 * 4), i);
	}
}
void Counting(int eger, int r, int c, int sig)
{
	if (sig == 1)
	{
		ChangeColor(4);
		gotoRowCol(16, 8);
		cout << "Counting !!!!!!!!!!!!";
		gotoRowCol(17, 8);
		
		ChangeColor(6);
		Square(18, 3);
		for (int i = 20; i < 29; i++)
		{
			gotoRowCol(i, 8);
			cout << "              ";
		}
	}
	ChangeColor(7);
	switch (eger)
	{
	case 1:
		one(r, c);
		break;
	case 2:
		two(r, c);
		break;
	case 3:
		three(r, c);
		break;
	case 4:
		four(r, c);
		break;
	case 5:
		S(r, c);
		break;
	case 6:
		six(r, c);
		break;
	case 7:
		seven(r, c);
		break;
	case 8:
		eight(r, c);
		break;
	case 9:
		nine(r, c);
		break;
	case 0:
		zero(r, c);
		break;
	}
	ChangeColor(15);
}
void zero(int r, int c)
{
	VerticalLine(r, c + 6);
	VerticalLine(r + 3, c + 6);
	VerticalLine(r + 6, c + 6);
	VerticalLine(r, c);
	VerticalLine(r + 3, c);
	VerticalLine(r + 6, c);
	HorizontalLine(r, c);
	HorizontalLine(r + 8, c);
	HorizontalLine(r, c + 3);
	HorizontalLine(r + 8, c + 3);
}
void nine(int r, int c)
{
	VerticalLine(r, c + 6);
	VerticalLine(r + 3, c + 6);
	VerticalLine(r + 6, c + 6);
	VerticalLine(r, c);
	VerticalLine(r + 2, c);
	HorizontalLine(r, c);
	HorizontalLine(r, c + 3);
	HorizontalLine(r + 4, c);
	HorizontalLine(r + 4, c + 3);
}
void eight(int r, int c)
{
	VerticalLine(r, c + 6);
	VerticalLine(r + 3, c + 6);
	VerticalLine(r + 6, c + 6);
	VerticalLine(r, c);
	VerticalLine(r + 3, c);
	VerticalLine(r + 6, c);
	HorizontalLine(r, c);
	HorizontalLine(r + 4, c);
	HorizontalLine(r + 8, c);
	HorizontalLine(r, c + 3);
	HorizontalLine(r + 4, c + 3);
	HorizontalLine(r + 8, c + 3);
}
void seven(int r, int c)
{
	VerticalLine(r, c + 6);
	VerticalLine(r + 3, c + 6);
	VerticalLine(r + 6, c + 6);
	HorizontalLine(r, c);
	HorizontalLine(r, c + 3);
}
void six(int r, int c)
{
	VerticalLine(r, c);
	VerticalLine(r + 3, c);
	VerticalLine(r + 6, c);
	HorizontalLine(r, c);
	HorizontalLine(r, c + 3);
	HorizontalLine(r + 4, c);
	HorizontalLine(r + 4, c + 3);
	VerticalLine(r + 5, c + 6);
	HorizontalLine(r + 8, c);
	HorizontalLine(r + 8, c + 3);
}
void four(int r, int c)
{
	VerticalLine(r, c + 3);
	VerticalLine(r + 3, c + 3);
	VerticalLine(r + 6, c + 3);
	VerticalLine(r, c);
	VerticalLine(r + 2, c);
	HorizontalLine(r + 4, c);
}
void three(int r, int c)
{
	VerticalLine(r, c + 3);
	VerticalLine(r + 3, c + 3);
	VerticalLine(r + 6, c + 3);
	HorizontalLine(r, c);
	HorizontalLine(r + 4, c);
	HorizontalLine(r + 8, c);
}
void two(int r, int c)
{
	HorizontalLine(r, c);
	VerticalLine(r + 1, c + 3);
	HorizontalLine((r + 1) + 3, c);
	VerticalLine((r + 1) + 4, c);
	HorizontalLine((r + 1) + 7, c);
}
void one(int r, int c)
{
	HorizontalLine(r, c);
	VerticalLine(r, c + 3);
	VerticalLine(r + 3, c + 3);
	VerticalLine(r + 6, c + 3);
	HorizontalLine(r + 8, c);
	HorizontalLine(r + 8, c + 3);
}
void Stage(int r, int c)
{
	S(r, c);
	T(r, c + 6);
	A(r, c + 15);
	G(r, c + 24);
	E(r, c + 33);
}
void E(int r, int c)
{
	VerticalLine(r, c);
	VerticalLine(r + 3, c);
	VerticalLine(r + 6, c);
	HorizontalLine(r, c);
	HorizontalLine(r, c + 3);
	HorizontalLine(r + 4, c);
	HorizontalLine(r + 4, c + 3);
	HorizontalLine(r + 8, c);
	HorizontalLine(r + 8, c + 3);
}
void G(int r, int c)
{
	VerticalLine(r, c);
	VerticalLine(r + 3, c);
	VerticalLine(r + 6, c);
	VerticalLine(r + 6, c + 6);
	HorizontalLine(r + 5, c + 3);
	HorizontalLine(r, c);
	HorizontalLine(r, c + 3);
	HorizontalLine(r + 8, c);
	HorizontalLine(r + 8, c + 3);
}
void A(int r, int c)
{
	VerticalLine(r, c);
	VerticalLine(r + 3, c);
	VerticalLine(r + 6, c);
	VerticalLine(r, c + 6);
	VerticalLine(r + 3, c + 6);
	VerticalLine(r + 6, c + 6);
	HorizontalLine(r, c);
	HorizontalLine(r, c + 3);
	HorizontalLine(r + 4, c);
	HorizontalLine(r + 4, c + 3);
}
void T(int r, int c)
{
	VerticalLine(r + 1, c + 3);
	VerticalLine(r + 4, c + 3);
	VerticalLine(r + 6, c + 3);
	HorizontalLine(r, c);
	HorizontalLine(r, c + 3);
}
void S(int r, int c)
{
	HorizontalLine(r, c);
	VerticalLine(r + 1, c);
	HorizontalLine((r + 1) + 3, c);
	VerticalLine((r + 1) + 4, c + 3);
	HorizontalLine((r + 1) + 7, c);
}
void VerticalLine(int r, int c)
{
	char box = -37;
	for (int i = r; i < r + 3; i++)
	{
		gotoRowCol(i, c);
		cout << box;
	}
}
void HorizontalLine(int r, int c)
{
	char box = -37;
	for (int i = c; i <= c + 3; i++)
	{
		gotoRowCol(r, i);
		cout << box;
	}
}
void Wait(int s)
{
	for (int i = 0; i <= s * 100000000; i++);
}
void ChangeColor(int color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);;
	SetConsoleTextAttribute(hConsole, color);
}
void gotoRowCol(int rpos, int cpos)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	int xpos = cpos, ypos = rpos;
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = xpos;     scrn.Y = ypos;
	SetConsoleCursorPosition(hOuput, scrn);
}
void D(int r, int c, char chr)
{
	for (int i = 0; i < 6; i++)
	{
		gotoRowCol(i, 8);
		cout << chr;
		Wait(0.2);
	}
	for (int i = 0; i<6; i++)
	{
		gotoRowCol(0, i + 8);
		cout << chr;
		Wait(0.2);
	}
	for (int i = 0; i < 6; i++)
	{
		gotoRowCol(i, 14);
		cout << chr;
		Wait(1);
	}
	for (int i = 0; i < 6; i++)
	{
		gotoRowCol(i, 14);
		cout << chr;
		Wait(1);
	}
	for (int i = 0; i < 6; i++)
	{
		gotoRowCol(5, i + 8);
		cout << chr;
		Wait(1);
	}
}
void I(int r, int c, char chr)
{
	for (int i = 0; i < 6; i++)
	{
		gotoRowCol(i, 16);
		cout << chr;
		Wait(1);
	}
}
void E(int r, int c, char chr)
{
	for (int i = 0; i < 6; i++)
	{
		gotoRowCol(i, 18);
		cout << chr;
		Wait(1);
	}
	for (int i = 0; i<6; i++)
	{
		gotoRowCol(0, i + 18);
		cout << chr;
		Wait(1);
	}
	for (int i = 0; i<6; i++)
	{
		gotoRowCol(3, i + 18);
		cout << chr;
		Wait(1);
	}
	for (int i = 0; i<6; i++)
	{
		gotoRowCol(6, i + 18);
		cout << chr;
		Wait(1);
	}
}
void G(int r, int c, char chr)
{
	for (int i = 0; i<6; i++)
	{
		gotoRowCol(12, i + 14);
		cout << chr;
		Wait(1);
	}
	for (int i = 0; i<6; i++)
	{
		gotoRowCol(i + 12, 14);
		cout << chr;
		Wait(1);
	}
	for (int i = 0; i<6; i++)
	{
		gotoRowCol(18, 14 + i);
		cout << chr;
		Wait(1);
	}
	for (int i = 0; i<3; i++)
	{
		gotoRowCol(i + 15, 19);
		cout << chr;
		Wait(1);
	}
	for (int i = 0; i<4; i++)
	{
		gotoRowCol(15, i + 19);
		cout << chr;
		Wait(1);
	}
}
void A(int r, int c, char chr)
{
	for (int i = 0; i<6; i++)
	{
		gotoRowCol(i + 13, 25);
		cout << chr;
		Wait(1);
	}
	for (int i = 0; i<4; i++)
	{
		gotoRowCol(13, i + 25);
		cout << chr;
		Wait(1);
	}
	for (int i = 0; i<6; i++)
	{
		gotoRowCol(i + 13, 28);
		cout << chr;
		Wait(1);
	}
	for (int i = 0; i<3; i++)
	{
		gotoRowCol(16, i + 25);
		cout << chr;
		Wait(1);
	}
}
void M(int r, int c, char chr)
{
	for (int i = 0; i<6; i++)
	{
		gotoRowCol(i + 13, 34);
		cout << chr;
		Wait(1);
	}
	for (int i = 0; i<6; i++)
	{
		gotoRowCol(i + 13, i + 34);
		cout << chr;
		Wait(1);
	}
	for (int i = 0; i<3; i++)
	{
		gotoRowCol(18, i + 39);
		cout << chr;
		Wait(1);
	}
	for (int i = 0; i<5; i++)
	{
		gotoRowCol(i + 13, 41);
		cout << chr;
		Wait(1);
	}
}
void E1(int r, int c, char chr)
{
	for (int i = 0; i < 6; i++)
	{
		gotoRowCol(i + 13, 44);
		cout << chr;
		Wait(1);
	}
	for (int i = 0; i<6; i++)
	{
		gotoRowCol(13, i + 44);
		cout << chr;
		Wait(1);
	}
	for (int i = 0; i<6; i++)
	{
		gotoRowCol(16, i + 45);
		cout << chr;
		Wait(1);
	}
	for (int i = 0; i<6; i++)
	{
		gotoRowCol(18, i + 45);
		cout << chr;
		Wait(1);
	}
}
void Symbol(int r, int c, char chr)
{
	for (int i = 0; i<6; i++)
	{
		gotoRowCol(i + 14, 56);
		cout << chr;
		Wait(1);
	}
	gotoRowCol(5 + 16, 56);
	cout << chr;
	Wait(1);

	for (int i = 0; i<6; i++)
	{
		gotoRowCol(i + 14, 60);
		cout << chr;
		Wait(1);
	}
	gotoRowCol(5 + 16, 60);
	cout << chr;
	Wait(1);
}
