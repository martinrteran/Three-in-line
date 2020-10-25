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
	int x,y,dimension;/*valor es el número donde a partir se va a calcular la posicion de todo*/
	char character='+';
	char	blank=' ';
	dimension=dime*3+2;/*lo dividimos en tres partes para así poder trabajar*/
	
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

int winner(jugar set)/*revisar!!!*/
{
	int x,y,i,machine=0,human=0;
/*empezamos chequeando las horizontales*/
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
					return 1;/*da el lugar donde se deberá poner la pieza*/
			}
	}		
}

	
	/*chequeando las verticales*/
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
					return 1;/*da el lugar donde se deberá poner la pieza*/
			}
	}
}
	machine=0;
	human=0;
	/*chequear las dos diagonales*/
	/*pero primero la de pendiente positiva*/
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
				return 1;/*vacio es donde la máquina tiene que poner la pieza*/
		}
	}
	
	machine=0;
	human=0;
	/*diagonal de pendiente negativa*/
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
				return 1;/*vacio es donde la máquina tiene que poner la pieza*/
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
	jugar player;
	char basura;
	int sel,i,j,k,x,y,dice;
	srand(time(0));
	do{
		dice=rand()%3;
	}while(dice>1);		
	
	printf("Tic-Tac-Toe\n");
	do{
	printf("Please choose the gamemode:\n1.-1vs1\n2.-Solo\n");
	scanf("%d",&sel);
	
	if(sel==1){
		system("cls");
		printf("Instructions:\nYou can only use the numbers from 1 to 9 to select were you want to put your piece\nHere it is an example of each position\n");
	   example_table();
	for(i=0;i<9;i++)/*pone en blanco toda la matriz de juego*/
		player.vector[i]=' ';
	
	/*Makes the user selec their piece for the game*/
 		menu_1vs1(&player);/*chequear*/
		system("cls");
	
	/*It starts the game*/
		printf("To end the game press 0\n");
		set_board();/*set the board for the game and prints it*/
		fflush(stdin);
		teams(&player,dice);/*chequear*/
		
	}else if(sel==2){
		system("cls");
		printf("Instructions:\nYou can only use the numbers from 1 to 9 to select were you want to put your piece\nHere it is an example of each position\n");
	example_table();
	for(i=0;i<9;i++)/*pone en blanco toda la matriz de juego*/
		player.vector[i]=' ';
	
	/*Makes the user selec their piece for the game*/
	menu(&player);
	system("cls");
	
	/*It starts the game*/
	printf("To end the game press 0\n");
	set_board();/*set the board for the game and prints it*/
	fflush(stdin);
	
	play(&player,dice);
	
	}		
	if(sel<1 || sel>2)
		printf("\nThat option does not exist, choose again\n");
		
	}while(sel<1 || sel>2);


	

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

void teams(jugar* p, int sel)/*REVISAR, error masivo!!*/
{
	int flag=0,choice=0,x,y,player1=0,player2=0,i,fix=0;
	char desicion='0',basura;
	jugar set;
	set=*p;
	
	for(i=0;i<9;i++){
		set.vector[i]=' ';
	}
	
	if(sel==1){
		/*Va la máquina*/
		gotoxy(0,0);
			printf("                                               \n                                                      ");
			gotoxy(0,0);
		printf("Player 2 starts\nChoose where do you want to start\n");
		do{
			if(kbhit()==1){
			desicion=getch(stdin);	
			if(desicion>'0'&& desicion<='9'){
			/*revisar*/
			choice=desicion-'1';
			set.vector[choice]=set.machine_piece;
			location_piece(desicion,&x,&y);
			print_piece(set.machine_piece,x,y);/*este no problema*/
			
			}
			
			fflush(stdin);
		}
		}while(desicion<='0'|| desicion > '9');
		player2=0;	
		player1=1;
	}/*hasta aquí es el inicio*/
	/*esta parte se corre al principio del juego y no se vuelve a correr más*/
	if(sel==0)
	{/*Va el jugador*/
		gotoxy(0,0);
		printf("                                               \n                                                      ");
		gotoxy(0,0);
		printf("Player 1 starts\nChoose where do you want to start\n");
		do{
			if(kbhit()==1){
			desicion=getch(stdin);	
			if(desicion>'0'&& desicion<='9'){
			/*revisar*/
			choice=desicion-'1';
			set.vector[choice]=set.player_piece;
			location_piece(desicion,&x,&y);
			print_piece(set.player_piece,x,y);/*este no problema*/
			
			}
			
			fflush(stdin);
		}
		}while(desicion<='0'|| desicion > '9');
		player2=1;	
		player1=0;
	}

	
	
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
			choice=desicion-'1';/*revisar*/
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
		/*problem with this function*/
		}
		fflush(stdin);
		}
	}
	
	/*AHORA DEBERÍA IR BIEN*/
	flag=winner(set);
		/*falta acabar el juego*/
	}while(flag==0);

	*p=set;
	gotoxy(0,0);
    printf("                                               \n                                                      ");
	gotoxy(0,0);
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
		/*Va la máquina*/
		gotoxy(0,0);
   		 printf("                                               \n                                                      ");
		gotoxy(0,0);
		printf("Machine goes first\n");
			desicion='5';/*al centro ya que la oportunidad de ganar es mayor*/
			choice=desicion-'1';/*revisar*/
			set.vector[choice]=set.machine_piece;
			location_piece(desicion,&x,&y);
			print_piece(set.machine_piece,x,y);
		player=1;
	}/*hasta aquí es el inicio*/
	/*esta parte se corre al principio del juego y no se vuelve a correr más*/
	if(sel==0)
	{/*Va el jugador*/
		gotoxy(0,0);
    	printf("                                               \n                                                      ");
		gotoxy(0,0);
		printf("Player goes first\nChoose where to start:\n");
		do{
			if(kbhit()==1){
			desicion=getch(stdin);	
			if(desicion>'0'&& desicion<='9'){
			/*revisar*/
			choice=desicion-'1';
			set.vector[choice]=set.player_piece;
			location_piece(desicion,&x,&y);
			print_piece(set.player_piece,x,y);/*este no problema*/
			
			}
			
			fflush(stdin);
		}
		}while(desicion<='0'|| desicion > '9');
		machine=1;	
		player=0;
		fix=1;
	}

	
	
	/*REVISAR*/
	do{	
	if(player==1){
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
			if(set.vector[choice]==' '){
				fflush(stdin);
				set.vector[choice]=set.player_piece;
				location_piece(desicion,&x,&y);
				print_piece(set.player_piece,x,y);
				machine=1;
				player=0;
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
	
	}else if(machine==1){/*REVISAR*/
		
		
		choice=rule_1(set);
		
		if(choice==11)
		choice=rule_2(set);
		
		if(choice==12)
		choice=rule_3(set);		
			
		set.vector[choice]=set.machine_piece;
		desicion=choice + '1';
		location_piece(desicion,&x,&y);
		print_piece(set.machine_piece,x,y);
		fix=0;
		player=1;
		machine=0;
	}
	
	/*AHORA DEBERÍA IR BIEN*/
	flag=winner(set);
		/*falta acabar el juego*/
	}while(flag==0);
	
	*p=set;
	gotoxy(0,0);
    printf("                                               \n                                                      ");
	gotoxy(0,0);
	if(flag==3)
		printf("A tie\n");	
	if(flag==1)
		printf("Player wins\n");
	if(flag==2)
		printf("Machine wins\n");
	sleep(5);
}

void menu_1vs1(jugar* selec)/*BIEN*/
{
	jugar d;
	int des;
	d= *selec;
	printf("\nPlease player nº1 select your piece:\n1.-X\n2.-O\n");
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

void menu(jugar* selec)/*BIEN*/
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

int rule_1(jugar set)/*devuelve 11 sí no encontró donde poner pieza, y si funciona devuelve la posición dentro del vector*/
{
	int x,y,i,contador=0,dos=0,vacio;
	
/*empezamos chequeando las horizontales*/
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
					return vacio;/*da el lugar donde se deberá poner la pieza*/
			}
		}		
	}
	
	/*chequeando las verticales*/
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
					return vacio;
			}/*if*/
		}/*for y*/
}
	
	dos=0;
	contador=0;
	/*chequear las dos diagonales*/
	/*pero primero la de pendiente positiva*/
	for(i=2;i<7;i+=2){
		if(set.vector[i]!=set.player_piece)
		{
			contador++;
			if(set.vector[i]==set.machine_piece)
				dos++;
			if(set.vector[i]==' ')
				vacio=i;
			if(contador==3 && dos==2)
				return vacio;/*vacio es donde la máquina tiene que poner la pieza*/
		}
	}
	
	dos=0;
	contador=0;
	/*diagonal de pendiente negativa*/
		for(i=0;i<9;i+=4){
		if(set.vector[i]!=set.player_piece)
		{
			contador++;
			if(set.vector[i]==set.machine_piece)
				dos++;
			if(set.vector[i]==' ')
				vacio=i;
			if(contador==3 && dos==2)
				return vacio;/*vacio es donde la máquina tiene que poner la pieza*/
		}
	}
		
	vacio=11;/*este valor representa que no se consiguió ganar*/
	return vacio;	
	
}

int rule_2(jugar set)/*devuelve 13 sí no encontró donde poner pieza, y si funciona devuelve la posición dentro del vector*/
{
	int x,y,i,contador=0,vacio=0,dos=0;
	
/*empezamos chequeando las horizontales*/
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
					return vacio;/*da el lugar donde se deberá poner la pieza*/
			}
		}
	}
	
	
/*chequeando las verticales*/
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
					return vacio;/*da el lugar donde se deberá poner la pieza*/
		}
	}
	}
		
	dos=0;
	contador=0;
	/*chequear las dos diagonales*/
	/*pero primero la de pendiente positiva*/
	for(i=2;i<7;i+=2){
		if(set.vector[i]!=set.machine_piece)
		{
			contador++;
			if(set.vector[i]==set.player_piece)
			dos++;
			if(set.vector[i]==' ')
				vacio=i;
			if(contador==3 && dos==2)
				return vacio;/*vacio es donde la máquina tiene que poner la pieza*/
		}
	}
	/*diagonal de pendiente negativa*/
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
				return vacio;/*vacio es donde la máquina tiene que poner la pieza*/
		}
	}
		
	vacio=12;/*este valor representa que no se consiguió ganar*/
	return vacio;
}

int rule_3(jugar set)/*BIEN*/
{
	int i,k=0,x,y,suma;
	int pos[9],mat[3][3];
	/*inicio de pos[]*/
	for(i=0;i<9;i++){
		pos[i]=0;
	}
	

	/*genera un vector de valor numérico qeu guarda las posiciones de donde están los espacios en blanco*/
	for(i=0;i<9;i++){
		if(set.vector[i]==' '){ /*esto es una pieza*/	
			pos[k]=i;
			k++;
		}		
	}
	/*genera la matriz*/
	printf("\n");
	for(y=0;y<3;y++){
		for(x=0;x<3;x++){
			i=3*y+x;
			if(set.vector[i]==' ')
				mat[x][y]=0;
			else
				mat[x][y]=9;
		}
	}
	/*hace la sumatoria en los espacios en blanco*/
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

	/*Hay que chequear lo de los valores y elegir el de menor valor*/
	/*crear función que te diga la posicion del número mas bajo
	por ahora lo más sencillo es que elija el primero que se encuentre, ya depués agregaré estados que me permitan elegir una mejor opción entre los libres*/
	lowest_matrix(mat,&x,&y);
		
	return 3*y+x;
}

