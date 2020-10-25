#ifndef threeinline
#define threeinline

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
/*Defines the position of the first square of the matrix*/
#define Ox 20
#define Oy 5
#define dime 7/*It is the size of each square*/

typedef struct{/*It is the structure used to print the matrix*/
	char matriz[dime*3+2][dime*3+2];
}ty;

typedef struct{
	char vector[9];      /*It is the vector used*/
	char player_piece;/* to calculate how the game*/
	char machine_piece;/* is going*/
}jugar;

void gotoxy(int,int);/*it puts the cursor on the position x,y of the screen*/
void lowest_matrix(int vectot[3][3],int*,int*);/*it gives the position of the lowest number on the matrix*/
void set_board(void);/*it sets the board for the game*/
void lowest_number(int*, int,int*);/*like lowest_matrix but only a vector*/
void print_piece(char,int ,int);/*¿Which piece do you want to print?*/
void print_X(int, int);/*part of print_piece, it prints the x piece*/
void print_O(int,int);/*like the one before but the O piece*/
void location_piece(char,int* ,int* );/*it position of where the piece it is going to be printed on te screen*/
int winner(jugar);/*it tells if someone won or not (1,0)*/
void tic_toe(void);/*main function*/
void example_table(void);/*prints the table that shows at the beginning*/
void menu(jugar *);/*choose your piece*/
void lowest_matrix(int vector[3][3],int* Py,int* Px);
/*rules of playing for the machine*/
int rule_1(jugar);/*try to win first*/
int rule_2(jugar);/*try not to loose*/
int rule_3(jugar);/*find the best position(value)*/
/*what type of game would you like to play*/
void play(jugar *,int );/*against the machine?*/
void teams(jugar *,int);/*against another player?*/
void menu_1vs1(jugar* );/*menu of the 1v1 game*/
#endif
