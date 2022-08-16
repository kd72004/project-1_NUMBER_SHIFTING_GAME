#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define up 1
#define down 2
#define left 3
#define right  4

void rules (void);   // for display all rules
void matrix_of_random_number(int a[][4]);   // generate random numbers for 4*4 matrix
void matrix_formate(int a[][4]);     // print matrix in given formate
int winning_condition(int a[][4]);   // for check winning condition
int key (void);     // for read arrow key from keyboard
//swapping up,down,left,right
int  swap_up(int a[][4]);
int swap_down(int a[][4]);
int  swap_left(int a[][4]);
int  swap_right(int a[][4]);

int main()
{
     system("COLOR 09");  // blue color font
    char name[20];
    printf("\n\t\t\t ENTER YOUR NAME -> ");

    fgets(name,20,stdin);

     char replay;
     do
    {
        rules();
        int a[4][4],move=5,flag=0;
        matrix_of_random_number(a);    //for generate random numbers in matrix

       while(move)
       {
            printf("\n\t\t\t PLAYER NAME :  %s",name);
            printf("\n\t\t\t Remainng move: %d",move);
            matrix_formate(a);             // for print matrix of 4*4 on screen
            if(winning_condition(a))   // everytime check the winning condition
            {
                    printf("\n\t\t Congratulation You Win in %d Moves",100-move);
                    flag=1;
                    break;
            }
            switch(key())      // key function is use for read the arrow keys from key board
            {
               case 69:
                        exit(0);
               case 101:
                        exit(0);
               case up:
                        if(swap_up(a)) //swap_up function return 1 then this condition was true and swapping is not possible
                        move++;      // so that moves will remain as it is
                        break;
              case down:
                        if(swap_down(a))
                        move++;
                        break;
             case left:
                        if(swap_left(a))
                        move++;
                        break;
            case right:
                        if(swap_right(a))
                        move++;
                        break;
            default:       // if user press any other key from key boar then default will execute
                        move++;  // move will remain as it is
                        break;
        }

         move--;
        system("cls");
      }  //ending of second while loop
                  if(flag==0)
                  printf("\n\t\t YOU LOSE !!!");
                  printf("\n press \'y\' if you want to play game again\t : ");
                  fflush(stdin);
                 scanf("%c",&replay);
                 system("cls");
     }while(replay=='y');//ending of first while loop
    return 0;
}


void rules (void)
{
     system("cls");
     printf("\n\t\t::::::::::::::   MATRIX  PUZZLE          :::::::::::::::::::::: \n\n");
     printf("\n\t\t::::::::::::::   RULES OF THIS GAME      :::::::::::::::::::::: \n\n");
     system("color 0E"); //Yellow color
     printf("\n\t1. You can move only 1 strep at a time by arrow key\n");
     printf("\t\t\t\t  Move Up      : by up arrow key\n");
     printf("\t\t\t\t  Move Down    : by down arrow key\n");
     printf("\t\t\t\t  Move Left    : by left arrow key\n");
     printf("\t\t\t\t  Move Right   : by right arrow key\n");
     printf("\n\t2. You can move number at empty position only\n");
     printf("\n\t3. For eatch valid move : your total number of move will decrease by 1\n");
     printf("\n\t\t And your total number of moves are 100 . \n");
     printf("\n\t4. Winning situation    : Number in a 4 * 4 matrix should be in order from 1 to 15\n");
     printf("\n\n\t\t\t\t\t Winning situation :: \n\n");
     printf("\t\t\t\t     -------------------------\n");
     printf("\t\t\t\t     |   1 |   2 |   3 |   4 |\n");
     printf("\t\t\t\t     |   5 |   6 |   7 |   8 |\n");
     printf("\t\t\t\t     |   9 |  10 |  11 |  12 |\n");
     printf("\t\t\t\t     |  13 |  14 |  15 |     |\n");
     printf("\t\t\t\t     -------------------------\n");
     printf("\n\t5. You can exit the game by pressing \'E\'  and \' e \' \n");
     printf("\n\t So try to win in munimum no of moves ");
     getch();
     system("cls");
}

void matrix_of_random_number(int a[][4])
{
    int index_matrix[15]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int number=-1,i,j;
     srand(time(NULL));  // every time generate new random numbers
    for(i=0;i<=3;i++)
    {
        for(int j=0;j<=3;j++)
        {
            if(i==3 && j==3)
                a[i][j]=NULL;
            else
            {
                    do
                    {
                        number=index_matrix[rand() % 15]; //every time generate random number we use it as a index
                        index_matrix[number-1]=-1;   //put -1 value on generated index number so that number can not repate
                    }while(number==-1);
                    a[i][j]=number;
            }
        }
    }
}
void matrix_formate(int a[][4])
{
    system("COLOR 0F");  // white color font
    int i,j;
    printf("\n\t-------------------------------\n");
    for(i=0;i<=3;i++)
    {
        for(j=0;j<=3;j++)
        {   if(a[i][j]!=0)
            {
                       if(j==0)
                                printf("\t| %2d  |",a[i][j]); // for a[i][0]  first column
                       else
                                printf("\t  %2d  |",a[i][j]);
            }
            else
            {
                     if(j!=0)
                                printf("\t      |"); // for a[3][3] index number
                     else
                                printf("\t|     |");
            }

        }
        printf("\n");
    }
     printf("\t-------------------------------\n");
}
int winning_condition(int a[][4])
{
    int flag=1;
    int i,j;
    for(i=0;i<=3;i++)
    {
           for(j=0;j<=3;j++)
          {
                 if(flag<=14)
                 {
                        if(a[i][j]<a[i][j+1])
                        {
                              flag++;
                        }
                         else
                         {
                              return 0;
                         }

                 }
         }
    }
    return 1;
}
int  swap_up(int a[][4])
{
    int i,j,temp=0,flag=0;
    for(i=0;i<=3;i++)
    {
        for(j=0;j<=3;j++)
        {
            if(a[i][j]==0)
            {
                flag=1;
                break;
            }
        }
        if(flag==1) //if we get zero then break all the loops
            break;
    }
    if(i==3)
        return 1; // this situation swapping is not possible because upper index number was not empty
    else{
        temp=a[i][j];
        a[i][j]=a[i+1][j];  //exact lower number was swap with zero
        a[i+1][j]=temp;
        return 0;
     }
}

int swap_down(int a[][4])
{
    int i,j,temp=0,flag=0;
    for(i=0;i<=3;i++)
    {
        for(j=0;j<=3;j++)
        {
            if(a[i][j]==0)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)  //if we get zero then break all the loops
            break;
    }
    if(i==0)// this situation swapping is not possible because lower index was not empty
        return 1;
    else{
        temp=a[i][j];
        a[i][j]=a[i-1][j];  //exact upper number was swap with zero
        a[i-1][j]=temp;
        return 0;
     }
}
int  swap_left(int a[][4])
{
     int i,j,temp=0,flag=0;
    for(i=0;i<=3;i++)
    {
        for(j=0;j<=3;j++)
        {
            if(a[i][j]==0)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)  //if we get zero then break all the loops
            break;
    }
    if(j==3)// this situation swapping is not possible because left index was not empty
        return 1;
    else{
        temp=a[i][j];
        a[i][j]=a[i][j+1];  //exact right number was swap with zero
        a[i][j+1]=temp;
        return 0;
     }
}
int  swap_right(int a[][4])
{
      int i,j,temp=0,flag=0;
    for(i=0;i<=3;i++)
    {
        for(j=0;j<=3;j++)
        {
            if(a[i][j]==0)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)  //if we get zero then break all the loops
            break;
    }
    if(j==0)// this situation swapping is not possible because left index was not empty
        return 1;
    else{
        temp=a[i][j];
        a[i][j]=a[i][j-1];  //exact right number was swap with zero
        a[i][j-1]=temp;
        return 0;
     }
}


int key (void)  // this function is use for read key from the key board
{
    int ch;
    ch=getch();
    switch(ch)
    {
    case 72:
        return (up);
        break;
    case 80:
        return (down);
        break;
    case 77:
        return (right);
        break;
    case 75:
        return (left);
        break;
    }
}

