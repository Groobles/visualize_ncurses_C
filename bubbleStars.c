#include <curses.h>

#include <time.h>
#include <stdlib.h>

void swap(int *x, int *y);
int * Bubble(int A[], int n);
void Printstars(int num, int j);
int * printRandoms(int lower, int upper, int count);


int main(){

	int i, y, x, k=0;
	int *p;
	srand(time(0));
	
	initscr();
	
	bkgd(0);
	start_color();
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	

	getmaxyx(stdscr, y, x);
	p = printRandoms(0, y, x); /* the count 'last number' tells how many columns to make' */
	while(i < x)
		{

			Printstars(*(p+i), k);
			i++;
			k++;
		}

	Bubble(p, x);

	getch();
	endwin();

	
	return 0;
	
}

int * printRandoms(int lower, int upper, int count)
{
 int num;
 int i=0;
 int t=0;
 static int holder[1000]; /* the static part is needed */

 	for (; i <= count; i++) {
	        num = (rand() % (upper - lower + 1)) + lower;
		for(; t<i; t++){
			holder[t] = num;
		}
	}

	return holder;
}

void swap(int *x, int *y)
{
	int temp=*x;
	*x = *y;
	*y = temp;

}

int * Bubble(int A[], int n)
{
	int i, j, flag=0;
	for (i=0; i<n-1; i++)
	{
		flag=0;
		for(j=0; j<n-1-i; j++)
		{
				attrset(COLOR_PAIR(2));
				Printstars(A[j+1], j);
				attroff(COLOR_PAIR(2));
				refresh();

			if(A[j] < A[j+1]){  /*  I inverted the operator to reverse the effect on the screen
					     *  Mainly so I can use ncurses to better effect. */


				swap(&A[j], &A[j+1]);

				
				attrset(COLOR_PAIR(1));
				Printstars(A[j], j);
				attroff(COLOR_PAIR(1));
				napms(50);
				refresh();


			}

			flag=1;
			if(flag==0)
			break;
		}
			
			attrset(COLOR_PAIR(1));
			attron(A_UNDERLINE);
			Printstars(A[j], j);
			attroff(A_UNDERLINE);
			clrtobot();
			refresh();

	}

	return A;

}

void Printstars(int num, int j){
	int i;
	 for(i=0; i<num; i++){
		mvaddch(0+i, j, '0');
		} 
}
