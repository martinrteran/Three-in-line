#include "threeinline.h"


void gotoxy(int x,int y)/*bien*/
{
	HANDLE hcon;
hcon = GetStdHandle(STD_OUTPUT_HANDLE);
COORD dwPos;
dwPos.X = x;
dwPos.Y= y;
SetConsoleCursorPosition(hcon,dwPos);
}

void lowest_matrix(int vector[3][3],int* Px,int* Py)/*Va bien*/
{
	int x,y, menor;
	*Px=0;
	*Py=0;
	menor=vector[*Px][*Py];
	for(y=0;y<3;y++){
		for(x=0;x<3;x++)
		{
		if(vector[x][y]<menor)
		{
			menor=vector[x][y];
			*Py=y;
			*Px=x;
		}
		}

	}

}

void lowest_number(int * vector, int l, int *p)/*Chequear*/
{
	int i,menor;
		menor=vector[0];
	for(i=0;i<l;i++){
		if(vector[i]<menor)
		{
			menor=vector[i];
			*p=i;
		}

	}
}

void set_board()/*BIEN*/
{
	ty table;
	int x,y,dimension;/*valor es el n�mero donde a partir se va a calcular la posicion de todo*/
	char character='+';
	char	blank=' ';
	dimension=dime*3+2;/*lo dividimos en tres partes para as� poder trabajar*/

	for(y=0;y<dimension;y++){
		for(x=0;x<dimension;x++){
			if(x==dime+1|| x==(dime+1)*2 || y==dime+1 || y==(dime+1)*2)
				table.matriz[x][y]=character;
			else
				table.matriz[x][y]=blank;
		}
	}

	dimension=3*dime+2;
	system("cls");
	for(y=0;y<dimension;y++)
		for(x=0;x<dimension;x++){
			gotoxy(x+Ox,y+Oy);
			printf("%c",table.matriz[x][y]);
		}

}

void location_piece(char entrada,int * x,int *y)/*BIEN*/
{
	int Ix,Iy;
	Ix= *x;
	Iy= *y;

	switch(entrada){
		case '1':
			Ix=Ox;
			Iy=Oy;
			break;
		case '2':
			Ix=Ox+dime+2;
			Iy=Oy;
			break;
		case '3':
			Ix=Ox+(dime+1)*2+1;
			Iy=Oy;
			break;
		case '4':
			Ix=Ox;
			Iy=Oy+dime+2;
			break;
		case '5':
			Ix=Ox+dime+2;
			Iy=Oy+dime+2;
			break;
		case '6':
			Ix=Ox+(dime+1)*2+1;
			Iy=Oy+dime+2;
			break;
		case '7':
			Ix=Ox;
			Iy=Oy+(dime+1)*2+1;
			break;
		case '8':
			Ix=Ox+dime+2;
			Iy=Oy+(dime+1)*2+1;
			break;
		case '9':
			Ix=Ox+(dime+1)*2+1;
			Iy=Oy+(dime+1)*2+1;
			break;
		default:
			break;
		}
	*x=Ix;
	*y=Iy;
}

void print_X(int Ix,int Iy)/*BIEN*/
{
	char mat[dime][dime];
	int i,k,x,y;
/*primero la X*/
	for(i=0;i<dime;i++){
		for(k=0;k<dime;k++){

			if(i-k==0 || i+k==6)
				mat[k][i]='*';
			else
				mat[k][i]=' ';
		}
	}

	i=0;
	k=i;
	for(y=Iy;y<dime+Iy;y++){
		for(x=Ix;x<Ix+dime;x++)
		{
			gotoxy(x,y);
			printf("%c",mat[i][k]);
			i++;
		}
		i=0;
		k++;
	}

}

void print_O(int Ix,int Iy)/*BIEN*/
{
	int i,k,x,y;
	char mat[dime][dime];
	/*Ahora la O*/
		for(k=0;k<dime;k++){
			for(i=0;i<dime;i++){
				mat[i][k]=' ';
				switch(k){
					case 0:
					case dime-1:
						if(i>1 &&i<7-2)
						mat[i][k]='*';
					break;
					case 1:
					case dime-2:
						if(i==1 || i==7-2)
						mat[i][k]='*';
						break;
					default:
						if(i==0 || i==6)
						mat[i][k]='*';
						break;
				}
				}
			}/*salir del for*/
	/*print piece*/
	i=0;
	k=i;
	for(y=Iy;y<dime+Iy;y++){
		for(x=Ix;x<Ix+dime;x++)
		{
			gotoxy(x,y);
			printf("%c",mat[i][k]);
			i++;
		}
		i=0;
		k++;
	}
}

void print_piece(char p, int Ix,int Iy)/*REGULAR*/
{
	if(p=='X')
		print_X(Ix,Iy);
	else if(p=='O')
		print_O(Ix,Iy);
}

int winner(jugar set)/*It counts the number of consecutive equal pieces*/
{
	int x,y,i,machine=0,human=0;
/*checks the horizontal lines*/
/*to avoid errors while counting, it is reseted the values*/
for(y=0;y<3;y++){
	machine=0;
	human=0;
	for(x=0;x<3;x++){
		i=3*y+x;
		if(set.vector[i]!=' '){
				if(set.vector[i]==set.machine_piece)
					machine++;
				else if(set.vector[i]==set.player_piece)
					human++;

				if(machine==3)
					return 2;
				else if(human==3)
					return 1;/*da el lugar donde se deber� poner la pieza*/
			}
	}
}


	/*checks the vertical lines*/
for(x=0;x<3;x++){
	machine=0;
	human=0;
	for(y=0;y<7;y+=3){
		if(set.vector[x+y]!=' ')
			{
				if(set.vector[x+y]==set.machine_piece)
					machine++;
				else if(set.vector[x+y]==set.player_piece)
					human++;

				if(machine==3)
					return 2;
				else if(human==3)
					return 1;/*da el lugar donde se deber� poner la pieza*/
			}
	}
}
	machine=0;
	human=0;
	/*diagonals*/
	/*the first one*/
	for(i=2;i<7;i+=2){
		if(set.vector[i]!=' ')
		{
			if(set.vector[i]==set.machine_piece)
				machine++;
			if(set.vector[i]==set.player_piece)
				human++;
			if(machine==3)
				return 2;
			if(human==3)
				return 1;
		}
	}
	/*to avoid errors while counting, it is reseted the values*/
	machine=0;
	human=0;
	/*the other diagonal*/
	for(i=0;i<9;i+=4){
		if(set.vector[i]!=' ')
		{
			if(set.vector[i]==set.machine_piece)
				machine++;
			if(set.vector[i]==set.player_piece)
				human++;
			if(machine==3)
				return 2;
			if(human==3)
				return 1;/*vacio es donde la m�quina tiene que poner la pieza*/
		}
	}

	machine=0;
	human=0;
	for(i=0;i<9;i++){
		if(set.vector[i]!=' ')
				machine++;
		if(machine==9)
			return 3;
	}

	return 0;
}


void example_table()
{
	int x,y,j=1,k,u;
	char borde='+';

	for(y=0;y<5;y++){
		for(x=0;x<5;x++){
			k=x%2;
			u=y%2;
			if(k==0 && u==0){
				if(x==4)
				   printf("%d\n",j);
				else
				   printf("%d%c",j,borde);

				j++;

			}else{
				if(u!=0)
				printf("%c",borde);
				if(x==4)
				printf("\n");
			}

		}
   }

}


void tic_toe(void)
{
	/*Main function wheere everything runs*/
	jugar player;/*structre where the piece of the player and the vector (where the machine will read the information) are stored*/
	char basura;/*it is used to clean the input*/
	int sel,i,j,k,x,y,dice;
	srand(time(0));
	/*to avoid the same player to start playing, it is set a random funtion*/
	do{
		dice=rand()%3;
	}while(dice>1);

	printf("Tic-Tac-Toe\n");/*asks the player what they want to play*/
	do{
	printf("Please choose the gamemode:\n1.-1vs1\n2.-Solo\n");
	scanf("%d",&sel);

	if(sel==1){/*if it is selected th 1vs1 it executes the following code*/
		system("cls");
		printf("Instructions:\nYou can only use the numbers from 1 to 9 to select were you want to put your piece\nHere it is an example of each position\n");
	   example_table();
	for(i=0;i<9;i++)/*to avoid problems, it saves a blank space in  each position*/
		player.vector[i]=' ';

	/*Makes the user selec their piece for the game*/
 		menu_1vs1(&player);
		system("cls");

	/*It starts the game*/
		printf("To end the game press 0\n");
		set_board();/*set the board for the game and prints it*/
		fflush(stdin);
		/*the 1vs1 game*/
		teams(&player,dice);

	}else if(sel==2){
		/*The second option, Against the machine*/
		system("cls");
		printf("Instructions:\nYou can only use the numbers from 1 to 9 to select were you want to put your piece\nHere it is an example of each position\n");
	example_table();
	for(i=0;i<9;i++)/*it cleans the matrix*/
		player.vector[i]=' ';

	/*Makes the user selec their piece for the game*/
	menu(&player);
	system("cls");

	/*It starts the game*/
	printf("To end the game press 0\n");
	set_board();/*set the board for the game and prints it*/
	fflush(stdin);

	play(&player,dice);/*the against machine game*/

	}
	/*if the option is not 1 or 2, it shows an error message*/
	if(sel<1 || sel>2)
		printf("\nThat option does not exist, choose again\n");

	}while(sel<1 || sel>2);/*closes the first while*/




	do{
	system("cls");
	printf("Do you want to play again?\n1.-Yes\n2.-No\n");
	scanf("%d",&i);
	if(i<1 || i>2)
		printf("Incorrect answer\n");

	}while(i<1 || i>2);

	if(i==1){
		system("cls");
		tic_toe();
	}


}

void teams(jugar* p, int sel)/*1vs1 player entire game*/
{
	int flag=0,choice=0,x,y,player1=0,player2=0,i,fix=0;
	char desicion='0',basura;
	jugar set;
	set=*p;

	for(i=0;i<9;i++){
		set.vector[i]=' ';
	}

	if(sel==1){
		/*player nº2 starts*/
		gotoxy(0,0);
			printf("                                               \n                                                      ");
			gotoxy(0,0);
		printf("Player 2 starts\nChoose where do you want to start\n");
		do{
			if(kbhit()==1){
				/*if a key is pressed it saves it in desicion*/
			desicion=getch(stdin);
			if(desicion>'0'&& desicion<='9'){
			choice=desicion-'1';/*translate teh char to int*/
			set.vector[choice]=set.machine_piece;/*put the piece of player 2 in the position =choice*/
			location_piece(desicion,&x,&y);
			print_piece(set.machine_piece,x,y);/*este no problema*/
			}

			fflush(stdin);
			}
		}while(desicion<='0'|| desicion > '9');/*it keeps running until the position is valid*/
		/*set who is next*/
		player2=0;
		player1=1;
	}/*end of if(sel==1)*/

	/*If the player nº1 starts first*/
	if(sel==0)
	{/*it is almost equal to the one before, for player 2*/
		gotoxy(0,0);
		printf("                                               \n                                                      ");
		gotoxy(0,0);
		printf("Player 1 starts\nChoose where do you want to start\n");
		do{
			if(kbhit()==1){
			desicion=getch(stdin);
			if(desicion>'0'&& desicion<='9'){
			choice=desicion-'1';
			set.vector[choice]=set.player_piece;
			location_piece(desicion,&x,&y);
			print_piece(set.player_piece,x,y);

			}

			fflush(stdin);
		}
		}while(desicion<='0'|| desicion > '9');
		player2=1;
		player1=0;
	}/*ende of sel==0/



	/*REVISAR*/
	do{
	if(player1==1){
		if(fix==0){
		gotoxy(0,0);
		printf("                                               \n                                                      ");
		gotoxy(0,0);
		printf("Player 1 turn.\nChoose a position:");
		fix=1;
		}

		if(kbhit()==1){/*introduces when a player have to select a position*/
		desicion=getch(stdin);
		if(desicion>'0'&& desicion<='9'){
			choice=desicion-'1';/*revisar*/
			if(set.vector[choice]==' '){
				fflush(stdin);
				set.vector[choice]=set.player_piece;
				location_piece(desicion,&x,&y);
				print_piece(set.player_piece,x,y);
				player2=1;
				player1=0;
				fix=0;
			}else{
				fflush(stdin);
					gotoxy(0,0);
    			printf("                                               \n                                                      ");
				gotoxy(0,0);
				printf("There is already a piece, choose again\n");
			}
		/*problem with this function*/
		}
		fflush(stdin);
		}

	}else if(player2==1){/*REVISAR*/
		if(fix==0){
			gotoxy(0,0);
		printf("                                               \n                                                      ");
		gotoxy(0,0);
		printf("Player 2 turn.\nChoose a position:");
		fix=1;
		}

		if(kbhit()==1){/*introduces when a player have to select a position*/
		desicion=getch(stdin);
		if(desicion>'0'&& desicion<='9'){
			choice=desicion-'1';/*from char to int*/
			if(set.vector[choice]==' '){
				fflush(stdin);
				set.vector[choice]=set.machine_piece;
				location_piece(desicion,&x,&y);
				print_piece(set.machine_piece,x,y);
				player2=0;
				player1=1;
				fix=0;
			}else{
				fflush(stdin);
					gotoxy(0,0);
  				  printf("                                               \n                                                      ");
				gotoxy(0,0);
				printf("There is already a piece, choose again\n");
			}

		}
		fflush(stdin);
		}
	}

	flag=winner(set);/*did someone won?*/

	}while(flag==0);/*end of the do while*/
/*who won?*/
	*p=set;
	gotoxy(0,0);
    printf("                                               \n                                                      ");
	gotoxy(0,0);
	/*it prints who won*/
	if(flag==3)
		printf("A tie\n");
	if(flag==1)
		printf("Player 1 wins\n");
	if(flag==2)
		printf("Player 2 wins\n");
	sleep(5);
}


void play(jugar* p, int sel)/*REVISAR, error masivo!!*/
{
	int flag=0,choice=0,x,y,player=0,machine=0,i,fix=0;
	char desicion='0',basura;
	jugar set;
	set=*p;

	for(i=0;i<9;i++){
		set.vector[i]=' ';
	}

	if(sel==1){
		/*first the machine*/
		gotoxy(0,0);
   		 printf("                                               \n                                                      ");
		gotoxy(0,0);
		printf("Machine goes first\n");
			desicion='5';/*choose the centre of the matrix if it is possible*/
			choice=desicion-'1';/*char to integer*/
			set.vector[choice]=set.machine_piece;
			location_piece(desicion,&x,&y);
			print_piece(set.machine_piece,x,y);
		player=1;
	}/*end of if(sel==1)*/

	/*like sel==1, it runs just once*/
	if(sel==0)
	{/*Player goes first*/
		gotoxy(0,0);
    	printf("                                               \n                                                      ");
		gotoxy(0,0);
		printf("Player goes first\nChoose where to start:\n");
		do{
			if(kbhit()==1){
			desicion=getch(stdin);
			if(desicion>'0'&& desicion<='9'){
			choice=desicion-'1';
			set.vector[choice]=set.player_piece;
			location_piece(desicion,&x,&y);
			print_piece(set.player_piece,x,y);

			}

			fflush(stdin);
			}
		}while(desicion<='0'|| desicion > '9');/*makes sure that the option it's between the values*/

		machine=1;
		player=0;
		fix=1;
	}

/*it goes until the game ends*/
	do{
		/*Whoes turn ir it?*/
	if(player==1){/*player goes*/
		if(fix==0){
		gotoxy(0,0);
   		printf("                                               \n                                                      ");
		gotoxy(0,0);
		printf("Select a position");
		fix=1;
		}

		if(kbhit()==1){/*introduces when a player have to select a position*/
		desicion=getch(stdin);
		if(desicion>'0'&& desicion<='9'){
			choice=desicion-'1';/*revisar*/
			/*Is there (choice) a piece? */
			if(set.vector[choice]==' '){
				fflush(stdin);
				set.vector[choice]=set.player_piece;
				location_piece(desicion,&x,&y);
				print_piece(set.player_piece,x,y);
				machine=1;/*sets the next player turn*/
				player=0;
				fix=0;
			}else{/*if there is a problem*/
				fflush(stdin);
				gotoxy(0,0);
  			  printf("                                               \n                                                      ");
				gotoxy(0,0);
				printf("There is already a piece, choose again\n");
			}
		}
		fflush(stdin);
	}/*end of the kbhit()==1*/

}else if(machine==1){/*machine goes*/
/*first, can the machine win?*/
		choice=rule_1(set);
/*it returns a 11 if it can't win\\  rule_2 avoid loosing the game*/
		if(choice==11)
		choice=rule_2(set);
/*it returns a 12 if it has more options*/
		if(choice==12)
		choice=rule_3(set);/*it looks for a position where it increases the chances of winning*/
/*it sets the piece on  the position of choice*/
		set.vector[choice]=set.machine_piece;
		desicion=choice + '1';
		location_piece(desicion,&x,&y);
		print_piece(set.machine_piece,x,y);
		fix=0;
		player=1;
		machine=0;
	}
	flag=winner(set);
		/*Did someone win?*/
	}while(flag==0);

	*p=set;
	gotoxy(0,0);
    printf("                                               \n                                                      ");
	gotoxy(0,0);
	/*Who won?*/
	if(flag==3)
		printf("A tie\n");
	if(flag==1)
		printf("Player wins\n");
	if(flag==2)
		printf("Machine wins\n");
	sleep(5);/*time, so the player can read the message*/
}

void menu_1vs1(jugar* selec)/*the menu of 1vs1 game and it returns the the vector player pieces*/
{
	jugar d;
	int des;
	d= *selec;
	printf("\nPlease player n�1 select your piece:\n1.-X\n2.-O\n");/*choose the piece*/
	do{
	fflush(stdin);
	scanf("%d",&des);
	des--;
/*it sets the piece selected into the vetor of structures*/
	if(des==0){
		d.player_piece='X';
		d.machine_piece='O';
	}else if(des==1){
		d.player_piece='O';
		d.machine_piece='X';
	}

	if(des!=1 && des!=0)
		printf("Error, Please select a valid option\n");/*It prints if the option it is not correct*/

}while(des!=1 && des!=0);

	*selec=d;
}

void menu(jugar* selec)/*Makes the player choice her/his piece*/
{
	jugar d;
	int des;
	d= *selec;
	printf("\nPlease select your piece:\n1.-X\n2.-O\n");
	do{
	fflush(stdin);
	scanf("%d",&des);
	des--;

	if(des==0){
		d.player_piece='X';
		d.machine_piece='O';
	}else if(des==1){
		d.player_piece='O';
		d.machine_piece='X';
	}


	if(des!=1 && des!=0)
		printf("Error, Please select a valid option\n");

}while(des!=1 && des!=0);

	*selec=d;
}

int rule_1(jugar set)/*returns 11 if it doesn't find a position where to put the piece,and if it finds it, it returns teh position*/
{
	int x,y,i,contador=0,dos=0,vacio;

/*like in function winner, it cheks every single line/option*/
/*checks horizontal lines*/
	for(y=0;y<7;y+=3){
		contador=0;
		dos=0;
		for(x=0;x<3;x++){
		if(set.vector[x+y]!=set.player_piece)
			{
				contador++;
				if(set.vector[x+y]==set.machine_piece)
					dos++;
				if(set.vector[x+y]==' ')
					vacio=x+y;
				if(contador==3 && dos==2)
					return vacio;
			}
		}
	}

	/*checks vertical lines*/
for(x=0;x<3;x++){
	contador=0;
	dos=0;
			for(y=0;y<7;y+=3){
		if(set.vector[x+y]!=set.player_piece)
			{
				contador++;
				if(set.vector[x+y]==set.machine_piece)
					dos++;
				if(set.vector[x+y]==' ')
					vacio=x+y;
				if(contador==3 && dos==2)
					return vacio;/*It returns the position if it just needs that position to win*/
			}/*if*/
		}/*for y*/
}

	dos=0;
	contador=0;
	/*checks the diagonals*/
	/*the first one, form (0,0) (1,1) (2,2)*/
	for(i=2;i<7;i+=2){
		if(set.vector[i]!=set.player_piece)
		{
			contador++;
			if(set.vector[i]==set.machine_piece)
				dos++;
			if(set.vector[i]==' ')
				vacio=i;
			if(contador==3 && dos==2)
				return vacio;/*It returns the position if it just needs that position to win*/
		}
	}

	dos=0;
	contador=0;/*it avoids problems while counting*/
	/*the other diagnal*/
		for(i=0;i<9;i+=4){
		if(set.vector[i]!=set.player_piece)
		{
			contador++;
			if(set.vector[i]==set.machine_piece)
				dos++;
			if(set.vector[i]==' ')
				vacio=i;
			if(contador==3 && dos==2)
				return vacio;/*It returns the position if it just needs that position to win*/
		}
	}

	vacio=11;/*If it can't win*/
	return vacio;

}

int rule_2(jugar set)/*it returns 13 if it can't find where to put the piece,and if it works, it returns the position*/
{
	int x,y,i,contador=0,vacio=0,dos=0;

/*it starts checking the horizontal*/
	for(y=0;y<7;y+=3){
		contador=0;
		dos=0;
		for(x=0;x<3;x++){
		if(set.vector[x+y]!=set.machine_piece)
			{
				contador++;
				if(set.vector[x+y]==set.player_piece)
					dos++;
				if(set.vector[x+y]==' ')
					vacio=x+y;
				if(contador==3 && dos==2)
					return vacio;
			}
		}
	}


/*vertical lines*/
	for(x=0;x<3;x++){
		contador=0;
		dos=0;
		for(y=0;y<9;y+=3){
		if(set.vector[x+y]!=set.machine_piece)
			{
				contador++;
				if(set.vector[x+y]==set.player_piece)
					dos++;
				if(set.vector[x+y]==' ')
					vacio=x+y;
				if(contador==3 && dos==2)
					return vacio;/*It returns the position if it just needs that position to win*/
		}
	}
	}

	dos=0;
	contador=0;
	/*check diagonals*/
	/*the first one*/
	for(i=2;i<7;i+=2){
		if(set.vector[i]!=set.machine_piece)
		{
			contador++;
			if(set.vector[i]==set.player_piece)
			dos++;
			if(set.vector[i]==' ')
				vacio=i;
			if(contador==3 && dos==2)
				return vacio;/*It returns the position if it just needs that position to win*/
		}
	}
	/*the second one*/
	contador=0;
	dos=0;
	for(i=0;i<9;i+=4){
		if(set.vector[i]!=set.machine_piece)
		{
			contador++;
			if(set.vector[i]==set.player_piece)
			dos++;
			if(set.vector[i]==' ')
				vacio=i;
			if(contador==3 && dos==2)
				return vacio;/*It returns the position if it just needs that position to win*/
		}
	}

	vacio=12;/*If you have more options*/
	return vacio;
}

int rule_3(jugar set)/*it choose the best position for the piece to be*/
{
	int i,k=0,x,y,suma;
	int pos[9],mat[3][3];
	/*begining pos[]*/
	for(i=0;i<9;i++){
		pos[i]=0;
	}


	/*genreates a vector that saves teh position of where the blank spaces are*/
	for(i=0;i<9;i++){
		if(set.vector[i]==' '){ /*it saves each position*/
			pos[k]=i;
			k++;
		}
	}
	/*generates a matrix of the game*/
	printf("\n");
	for(y=0;y<3;y++){
		for(x=0;x<3;x++){
			i=3*y+x;
			if(set.vector[i]==' ')
				mat[x][y]=0;/*if there a blank space in the vector, it puts a 0 in the matrix*/
			else
				mat[x][y]=9;/*if in the position, there is a piece, it puts a 9*/
		}
	}
	/*it puts the sum of the amounts of nines, checking the spaces around it*/
	{
		for(i=0;i<k;i++)
	{
		suma=0;
		x=pos[i];
		switch(x)
		{
			case 0:
				if(mat[0][1]==9)
					suma++;
				if(mat[1][0]==9)
					suma++;
				mat[0][0]=suma;
			break;
			case 1:
				if(mat[0][0]==9)
					suma++;
				if(mat[2][0]==9)
					suma++;
				if(mat[1][1]==9)
					suma++;
				mat[1][0]=suma;
				break;
			case 2:
				if(mat[2][1]==9)
					suma++;
				if(mat[1][0]==9)
					suma++;
				mat[2][0]=suma;
				break;
			case 3:
				if(mat[0][0]==9)
					suma++;
				if(mat[0][2]==9)
					suma++;
				if(mat[1][1]==9)
					suma++;
				mat[0][1]=suma;
				break;
			case 4:
				if(mat[1][0]==9)
					suma++;
				if(mat[0][1]==9)
					suma++;
				if(mat[2][1]==9)
				suma++;
				if(mat[1][2]==9)
				suma++;
				mat[1][1]=suma;
				break;
			case 5:
				if(mat[2][0]==9)
					suma++;
				if(mat[2][2]==9)
					suma++;
				if(mat[1][1]==9)
					suma++;
				mat[2][1]=suma;
				break;
			case 6:
				if(mat[0][1]==9)
					suma++;
				if(mat[1][2]==9)
					suma++;
				mat[0][2]=suma;
				break;
			case 7:
				if(mat[0][2]==9)
					suma++;
				if(mat[2][2]==9)
					suma++;
				if(mat[1][1]==9)
					suma++;
				mat[1][2]=suma;
				break;
			case 8:
				if(mat[2][1]==9)
					suma++;
				if(mat[1][2]==9)
					suma++;
				mat[2][2]=suma;
				break;

		}

	}
}

	/*First, it is needed to be checked where is the lowest number*/
	/*the x and y, changes depending on where is the lowest number on te matrix*/
	lowest_matrix(mat,&x,&y);

	return 3*y+x;/*it returns that position(the lowest number) in the vector, that is why it returns3*y+x*/
}
