// All libraries we use
#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include <conio.h>
#define size 9

// All struct we use
struct student {
    int id;
    float gpa;
    char name[50];
    char lastname[20];
    char location[30];
};

struct player {
    char name[16];
    int score;
};

struct playerintial {
    char name[16];
    int score;
};

char box[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

// All Functions for Student Registration program
int numofrecfun(struct student f[], int N) {
    int count = 0;
    FILE *p1;
    p1 = fopen("studentsdata.txt", "r");
    if (p1 == NULL)
        printf("File couldn't be opened\n");
    else {
        while (fscanf(p1, "%s%s%d%f%s", f[count].name, f[count].lastname, &f[count].id, &f[count].gpa, f[count].location) != EOF)
            count++;
    }
    fclose(p1);
    return count;
}

void searchbyname(char *sname, char *sname2, struct student f[], int N) {
    N = numofrecfun(f, 150); // for updating number of records
    int i, flag = 0;
    for (i = 0; i < N; i++) {
        if (strcmp(sname, f[i].name) == 0 && strcmp(sname2, f[i].lastname) == 0) {
            printf("Name:%s%s\tID:%d\tGPA:%.2f", f[i].name, f[i].lastname, f[i].id, f[i].gpa);
            flag = 1;
            if (f[i].gpa < 2.0)
                printf("\n(half load)\n");
        }
    }
    if (flag == 0) {
        printf("NOT FOUND");
        printf("\a");
    }
}

void searchbylocation(char *sloc, struct student f[], int N) {
    N = numofrecfun(f, 150); // for updating number of records
    int i, flag = 0;
    for (i = 0; i < N; i++) {
        if (strcmp(sloc, f[i].location) == 0) {
            printf("Name:%s %s\tID:%d\tGPA:%.2f\n", f[i].name, f[i].lastname, f[i].id, f[i].gpa);
            flag = 1;
        }
    }
    if (flag == 0) {
        printf("NOT FOUND");
        printf("\a");
    }
}

void searchbyID(int sid, struct student f[], int N) {
    N = numofrecfun(f, 150); // for updating number of records
    int i, flag = 0;
    for (i = 0; i < N; i++) {
        if (f[i].id == sid) {
            printf("Name:%s %s\tID:%d\tGPA:%.2f", f[i].name, f[i].lastname, f[i].id, f[i].gpa);
            flag = 1;
            if (f[i].gpa < 2.0)
                printf("\n(half load)\n");
        }
    }
    if (flag == 0) {
        printf("NOT FOUND");
        printf("\a");
    }
}

void halfload(struct student f[], int N, int i) {
    N = numofrecfun(f, 150); // for updating number of records
    if (i == N)
        return; // recursive function
    else if (f[i].gpa < 2)
        printf("%s %s\t%d\n", f[i].name, f[i].lastname, f[i].id);
    halfload(f, N, i + 1);
}

void halfloadwr(struct student f[], int N) {
    halfload(f, N, 0);
}

void sort5(struct student f[], int N) {
    struct student temp;
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < (N - 1 - i); j++) {
            if (f[j].gpa < f[j + 1].gpa) {
                temp = f[j];
                f[j] = f[j + 1];
                f[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < 5; i++)
        printf("Name:%s %s\tID:%d\tGPA:%.2f\n", f[i].name, f[i].lastname, f[i].id, f[i].gpa);
}

int delet(struct student f[], int N, int idf) {
    int i, x, flag = 0;
    for (i = 0; i < N; i++) {
        if (f[i].id == idf) {
            flag = 1;
            for (x = i; x < N; x++)
                f[x] = f[x + 1];
        }
    }
    if (flag == 1)
        return 1;
    else
        return 0;
}

void savefdel(struct student f[], int N) {
    FILE *p3;
    p3 = fopen("studentsdata.txt", "w");
    if (p3 == NULL)
        printf("File couldn't be opened\n");
    else {
        for (int i = 0; i < N; i++)
            fprintf(p3, "%s %s\t%d\t%.2f\t%s\n", f[i].name, f[i].lastname, f[i].id, f[i].gpa, f[i].location);
    }
    fclose(p3);
}

void addnew(struct student f[], int N, struct student arr[], int B) {
    FILE *p2;
    p2 = fopen("studentsdata.txt", "a");
    if (p2 == NULL)
        printf("File couldn't be opened\n");
    else {
        for (int i = 0; i <= B; i++)
            fprintf(p2, "%s %s\t%d\t%.2f\t%s\n", arr[i].name, arr[i].lastname, arr[i].id, arr[i].gpa, arr[i].location);
        printf("\nnumber of students added %d\n", B + 1);
    }
    fclose(p2);
    numofrecfun(f, 150);
}

// All Functions for Tic Tac Toe Game
void creating_board(struct player ply[], char box[]) {
    system("color 5");
    system("cls");
    printf("\n\n\t\t\t\t\t\t\t\t\tTic Tac Toe\n\n");
    printf("\t\t\t\t\t\t\t\tPlayer %s (X) -- Player %s (O)\n\n", ply[0].name, ply[1].name);
    printf("\t\t\t\t\t\t\t\t         |         |     \n");
    printf("\t\t\t\t\t\t\t\t         |         |      \n");
    printf("\t\t\t\t\t\t\t\t    %c    |    %c    |    %c  \n", box[1], box[2], box[3]);
    printf("\t\t\t\t\t\t\t\t         |         |      \n");
    printf("\t\t\t\t\t\t\t\t_________|_________|_________\n");
    printf("\t\t\t\t\t\t\t\t         |         |     \n");
    printf("\t\t\t\t\t\t\t\t         |         |      \n");
    printf("\t\t\t\t\t\t\t\t    %c    |    %c    |    %c  \n", box[4], box[5], box[6]);
    printf("\t\t\t\t\t\t\t\t         |         |      \n");
    printf("\t\t\t\t\t\t\t\t_________|_________|_________\n");
    printf("\t\t\t\t\t\t\t\t         |         |     \n");
    printf("\t\t\t\t\t\t\t\t         |         |      \n");
    printf("\t\t\t\t\t\t\t\t    %c    |    %c    |    %c  \n", box[7], box[8], box[9]);
    printf("\t\t\t\t\t\t\t\t         |         |      \n");
    printf("\t\t\t\t\t\t\t\t_________|_________|_________\n");
    printf("\t\t\t\t\t\t\t\t         |         |     \n");
    printf("\t\t\t\t\t");

}
void marking_board( char choice, char mark)
{
    if(choice=='1' && box[1]=='1')
        box[1]=mark;
    else if(choice=='2' && box[2]=='2')
        box[2]=mark;
    else if(choice=='3' && box[3]=='3')
        box[3]=mark;
    else if(choice=='4' && box[4]=='4')
        box[4]=mark;
    else if (choice=='5' && box[5]=='5')
        box[5]=mark;
    else if (choice=='6' && box[6]=='6')
        box[6]=mark;
    else if (choice=='7' && box[7]=='7')
        box[7]=mark;
    else if (choice=='8' && box[8]=='8')
        box[8]=mark;
    else if (choice=='9' && box[9]=='9')
        box[9]=mark;
else
printf(" ");

}
int check_for_win()
{
    if(box[1]==box[2] && box[2]==box[3])
        return 1;
    else if(box[4]==box[5] && box[5]==box[6])
        return 1;                                   // horizontal win
    else if (box[7]==box[8] && box[8]==box[9])
        return 1;

    else if (box[1]==box[4] && box[4]==box[7])
        return 1;
    else if(box[2]==box[5] && box[5]==box[8])           // vertical win
        return 1;
    else if(box[3]==box[6] && box[6]==box[9])
        return 1;


    else if(box[1]==box[5] && box[5]==box[9])
        return 1;
    else if(box[3]==box[5] && box[5]==box[7])           //diagonal win
        return 1;

    else if(box[1]!= '1' && box[2]!= '2' && box[3]!= '3' && box[4]!= '4'&& box[5]!= '5' && box[6]!= '6'&& box[7]!= '7' && box[8]!= '8' && box[9]!='9')  //no match
        return 0;

else
        return -1;


}
int valid(char choice,char box[])
{
int z,flag=0;

for(z=1;z<10;z++)
{
if(choice==box[z])
flag=1;
}
if(flag==1)
return 1;
else
return 0;
}
void save_player_score(struct player ply[])
{
int i;
FILE *ptr1;
ptr1=fopen("gamescore.txt","w");
if(ptr1==NULL)printf("ERROR");
else
{
for(i=0;i<2;i++) fprintf(ptr1,"%s %d\n",ply[i].name,ply[i].score);
}
fclose(ptr1);
}
void intializ(char box[])
{
struct player ply[2]={" ",0," ",0};
int i;
char boxintial[10]={'0','1','2','3','4','5','6','7','8','9'};
for(i=1;i<10;i++)
{
box[i]=boxintial[i];
}
}
int redfromfile(struct player ply[])
{
int cnt=0;
FILE *ptr2;
ptr2=fopen("gamescore.txt","r");
if(ptr2==NULL) printf("ERROR");
else{while(fscanf(ptr2,"%s%d",ply[cnt].name,&ply[cnt].score)!=EOF)
{
cnt++;
}
}
fclose(ptr2);
return cnt;
}
void intialplayer(struct player ply[],struct player plyintial[])
{
int i;
for(i=0;i<2;i++){
    strcpy(ply[i].name,plyintial[i].name);
	ply[i].score=plyintial[i].score;}
}

int main(void)
{
//structs declation for Student Registration program
struct student arr[30];
struct student f[150];
//Variables declation for Student Registration program
int pass=0,flag=0,i=0,j=0,sid=0,mexit=0,exit=0,numofrec=0,check=0;
char username[5],sname[30],sname2[30],sloc[30],ans[10],pass1[50],pass2[50]="dr12345";
//structs declation for Tic Tac Toe Game
struct player plyintial[2]={" ",0," ",0};
struct player ply[2]={" ",0," ",0};
//Variables declation for Tic Tac Toe Game
int player=1,l=-1,x,pass4=-1 ,record=0,z;
char choice,mark;
//Main menu
char uchoice[50];
int mflag=0;
do{
system("cls");
system("color F0");
    printf("=====================================");
printf("=\n=\n=\t    <<<<<<Finall Project>>>>>>\n=\n=  \tMade by MEDHAT HASSAN and Youssef Tarek\n=\n=\t    \n=\n=\t      <<<<<<Programs>>>>>>\n");
printf("\t\t\t\t\t\t\t=\n\t   STUDENT REGISTRATION PROGRAM==> 1\t\t=\n\t\t\t\t\t\t\t=\n\t   TIC TAC TOE GAME==> 2\t\t\t=\n\t\t\t\t\t\t\t=\n\t   FOR EXIT THE PROGRAM==> 3\t\t\t=\n\t\t\t\t\t\t\t=\n\t <<<<All Files & Data Are Included>>>>\t\t=");
printf("\n\t\t    =====================================\n\n");
scanf("%s",uchoice);
 
 do{
//MIAN OF STUDENT REGISTRATION PROGRAM
   if(strcmp(uchoice,"1")==0||strcmp(uchoice,"option1")==0)
     {
    do{
        system("cls");
        system("color 4");
        printf("\t\t\t<<<STUDENT REGISTRATION PROGRAM>>>\n");
        printf("Username:");
        scanf("%s",username);
      if(strcmp(username,"DR")==0||strcmp(username,"dr")==0)
flag=1;
      else
   { printf("Wrong username!!\n");printf("\a");}
   }while(flag!=1);
 do{
       printf("password:");
       scanf("%s",pass1);
       if(strcmp(pass1,pass2)==0) pass=1;
       else{ printf("Wrong password!!\n");printf("\a");}
   }while(pass!=1);
     system("cls");
    printf("\nwelcome back DR!!!\n");
    numofrec=numofrecfun(f,150);

do
 {
   char mychoice[50];
   system("color A");
   
   printf("\t\t\t<<<STUDENT REGISTRATION PROGRAM>>>\n\n\nAdd New Student==> 1\nDelete Student==> 2\nSearch For Student==> 3\nFrist Five Students==> 4\nAll Half Load Students==> 5\nExit Student Registration Program==> 6\n");
   scanf("%s",mychoice);
   if(strcmp(mychoice,"1")==0||strcmp(mychoice,"option1")==0)
   {
  system("cls");
  do
  {
        printf("\nEnter student [name,lastname,id,gpa,location]:");
        scanf("%s%s%d%f%s",arr[j].name,arr[j].lastname,&arr[j].id,&arr[j].gpa,arr[j].location);
    printf("\nDo you want to continue?[y/n]:");
    scanf("%s",ans);
    if(strcmp(ans,"Y")==0||strcmp(ans,"y")==0)j++;
else {flag=5;addnew(f,numofrec,arr,j);numofrec=numofrecfun(f,150);system("cls");}
      } while (flag!=5);
   }
   else if(strcmp(mychoice,"2")==0||strcmp(mychoice,"option2")==0){
      system("cls");
    do{
      system("color 4");
      printf("\nEnter student ID:");
      scanf("%d",&sid);
      check=delet(f,numofrec,sid);
      if(check==1)
   {printf("\nThe student data is succesfully deleted");numofrec--;}
      else
   {printf("\nThe student data is not found");printf("\a");}
      printf("\nDo you want to continue?[y/n]:");
      scanf("%s",ans);
      if(strcmp(ans,"Y")==0||strcmp(ans,"y")==0);
      else
   {flag=6;savefdel(f,numofrec);system("cls");}
 }while (flag!=6);
    }
  else if(strcmp(mychoice,"3")==0||strcmp(mychoice,"option3")==0)
   {
 do
       {
  char schoice[50];
       system("cls");
       printf("\nsearch by name==>1\tsearch by ID==>2\tsearch by location==>3\t\texit==>4\t");
       scanf("%s",schoice);
     
       if (strcmp(schoice,"1")==0||strcmp(schoice,"option1")==0)
        { system("cls");
         do
         {
            printf("\nEnter student name[Fristname,lastname]: ");
            scanf("%s%s",sname,sname2);
            searchbyname(sname,sname2,f,numofrec);
            printf("\nDo you want to continue?[y/n]:");
            scanf("%s",ans);
            if(strcmp(ans,"Y")==0||strcmp(ans,"y")==0);
            else
{flag=2;exit=4;system("cls");}
         } while (flag!=2);
    }
  else if (strcmp(schoice,"2")==0||strcmp(schoice,"option2")==0)
    {  
system("cls");
       do
        {
            printf("\nEnter student ID:");
            scanf("%d",&sid);
            searchbyID(sid,f,numofrec);
            printf("\nDo you want to continue?[y/n]:");
            scanf("%s",ans);
            if(strcmp(ans,"Y")==0||strcmp(ans,"y")==0);
            else
{flag=3;exit=4;system("cls");}
         } while (flag!=3);
    }
  else if (strcmp(schoice,"3")==0||strcmp(schoice,"option3")==0)
    {
system("cls");
     do{
         printf("Enter student location:");
         scanf("%s",sloc);
         searchbylocation(sloc,f,numofrec);
         printf("\nDo you want to continue?[y/n]: ");
         scanf("%s",ans);
         if(strcmp(ans,"Y")==0||strcmp(ans,"y")==0);
         else
{flag=4;exit=4;system("cls");}
       } while (flag!=4);
    }
     else if (strcmp(schoice,"4")==0||strcmp(schoice,"option4")==0)
     {exit=4;system("cls");}
     else
     {system("cls");printf("NOT OPTION!!!");printf("\a");}
    } while (exit!=4);
  }
    else if(strcmp(mychoice,"4")==0||strcmp(mychoice,"option4")==0) {system("cls");sort5(f,numofrec);}
    else if(strcmp(mychoice,"5")==0||strcmp(mychoice,"option5")==0) {system("cls");numofrec=numofrecfun(f,150);halfloadwr(f,numofrec);} // wrapper function
    else if(strcmp(mychoice,"6")==0||strcmp(mychoice,"option6")==0) {exit=6;}
else {system("cls");printf("\t\t\t<<<STUDENT REGISTRATION PROGRAM>>>\n\n");printf("NOT OPTION!!!");printf(" \a ");}
   } while (exit!=6);
    flag=8;system("cls");
  }
   else if(strcmp(uchoice,"2")==0||strcmp(uchoice,"option2")==0)
   {
 //MIAN OF Tic Tac Toe Game
      system("cls");
      record=redfromfile(ply);
       do{
         if(record==0){
          system("color 5");
          printf("\nPlayer 1 name:  ");
          scanf("%s",ply[0].name);
          printf("Player 2 name:  ");
 scanf("%s",ply[1].name);
 z=2;
}
         if(record==2){
 system("color 4");
          printf("Do you want continue after last game?[y/n] :  ");
 scanf("%s",ans);
 system("cls");
if(strcmp(ans,"y")==0|| strcmp(ans,"Y")==0)
 z=2;
         else
 {intialplayer(ply,plyintial);z=1;record=0;}
         }
       }while(z==1);
     do{
       if(strcmp(ans,"y")==0 || strcmp(ans,"Y")==0){intializ(box);player=1;}
       do{
          system("cls");
 if(pass4==0) printf("<<<<------invalid move------>>>>");
   player= (player % 2) ? 1: 2;
            creating_board(ply,box);
   printf("\n\nPlayer %d, enter a number: ",player);
            choice=_getch();
			//while(getchar()!='\n'){} if you use scanf to scan the character
   pass4=valid(choice,box);
          if(pass4==1){mark = (player==1) ? 'X' : 'O';
            marking_board(choice,mark);
            l=check_for_win();
            player++;}          
          else printf("\a");
        }while(l == -1);
    while(l==1 || l==0)
{
system("cls");
        creating_board(ply,box);
if(l==1)
         {
           printf("\nPlayer %d  you have won the game\t\t\t\t\t",--player);
           if(player==1)ply[0].score++;
           else ply[1].score++;
          }
       else printf("<-------Draw------>\t\t\t");
        l=l+2;
        if(player==1 || player==2)
{
       if(player==1)
          {
            printf("%s score: %d |  ",ply[0].name,ply[0].score);printf("%s score: %d\n\n",ply[1].name,ply[1].score);
Beep(250,1000);
Beep(300,900);
Beep(250,1000);
Beep(400,2000);
          }
       else
  {
  printf("%s score: %d |  ",ply[0].name,ply[0].score);printf("%s score: %d\n\n",ply[1].name,ply[1].score);
  Beep(250,1000);
Beep(300,900);
Beep(250,1000);
Beep(400,2000);
  }
         }
    }
    printf("\n\nDo you want to play again ? [y/n] :   ");
    scanf(" %s",ans);
 }while(strcmp(ans,"y")==0 || strcmp(ans,"Y")==0);
    save_player_score(ply);
    flag=8;
}
   else if(strcmp(uchoice,"3")==0||strcmp(uchoice,"option3")==0){flag=8;mflag=1;system("cls");}
   else {printf("NOT OPTION!!!");printf(" \a ");flag=8;}
  }while(flag!=8);

 }while(mflag!=1);
 
 return 0;

}