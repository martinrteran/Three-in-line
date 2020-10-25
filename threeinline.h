#ifndef threeinline
#define threeinline

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define Ox 20
#define Oy 5
#define dime 7

typedef struct{
	char matriz[dime*3+2][dime*3+2];
}ty;

typedef struct{
	char vector[9];
	char player_piece;
	char machine_piece;
}jugar;

void gotoxy(int,int);
void lowest_matrix(int vectot[3][3],int*,int*);
void set_board(void);
void lowest_number(int*, int,int*);
void print_piece(char,int ,int);
void print_X(int, int);
void print_O(int,int);
void location_piece(char,int* ,int* );
int winner(jugar);
void tic_toe(void);/*main function*/
void example_table(void);/*prints the table that shows at the beginning*/
void menu(jugar *);/*choose your piece*/
void lowest_matrix(int vector[3][3],int* Py,int* Px);
/*rules of playing*/
int rule_1(jugar);/*busca ganar*/
int rule_2(jugar);/*busca no perder*/
int rule_3(jugar);/*busca el de menor valor*/
/*funcion que comprueba si alguien ha ganado, en el caso que no lo haga continuará el juego con un do{}while(flag==1),
 tiene salida 1 o 2 para el ganador;*/
void play(jugar *,int );/*solo el jugar*/
void teams(jugar *,int);
void menu_1vs1(jugar* );
#endif
