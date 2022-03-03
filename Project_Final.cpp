/* Vehicle parking program */

#include <stdio.h>
#include <conio.h>
#include<stdlib.h>    //Instead we can use windows.h header file...
#include<iostream>
#include<windows.h>   //Due to sleep() we have used  windows.h
#include <string>
#include <sstream>
#include<cstring>
#include<fstream>
#include<ctime>
#define CAR 1
#define SCOOTER 2
using namespace std;
/* to store vehicle number, and its
   row-col position in an array */
struct vehicle
    {
     int num ;
     int row ;
     int col ;
      int type ;
    } ;
        int parkinfo[4][10] ;  /* a 2-D array to store number of vehicle parked */
        int vehcount ;  /* to store total count of vehicles */
        int carcount ; /* stores total count of cars */
        int scootercount ;  /* stores total count of scooters */
        char state[4][10];

        void display( ) ;
        void changecol ( struct vehicle * ) ;
        struct vehicle * add ( int, int, int, int ) ;
        void del ( struct vehicle * ) ;
        void getfreerowcol ( int, int * ) ;
        void getrcbyinfo ( int, int, int * ) ;
        void show( ) ;

/* decrements the col. number by one
   this fun. is called when the data is
   shifted one place to left */
void changecol ( struct vehicle *v )
    {
     v -> col = v -> col - 1 ;
    }
/* adds a data of vehicle */
struct vehicle *add( int t, int num, int row, int col )
  {
    struct vehicle *v;
    v = ( struct vehicle * ) malloc ( sizeof ( struct vehicle ) ) ;
    v -> type = t ;
    v -> row = row ;
    v -> col = col ;

     if ( t == CAR )
          carcount++ ;
     else
          scootercount++ ;
          vehcount++ ;
          parkinfo[row][col] = num ;

    return v ;
  }
/* deletes the data of the specified
   car from the array, if found */
void del ( struct vehicle *v )
 {
  int c ;

   for ( c = v -> col ; c < 9 ; c++ )
       parkinfo[v -> row][c] = parkinfo[v -> row][c+1] ;
       parkinfo[v -> row][c] = 0 ;

        if ( v -> type == CAR )
             carcount-- ;
        else
             scootercount-- ;
             vehcount-- ;
 }

/* get the row-col position for the vehicle to be parked */
void getfreerowcol ( int type, int *arr )
  {
   int r, c, fromrow = 0, torow = 2 ;

      if ( type == SCOOTER )
       {
        fromrow += 2 ;
        torow += 2 ;
       }

  for ( r = fromrow ; r < torow ; r++ )
    {
       for ( c = 0 ; c < 10 ; c++ )
          {
               if ( parkinfo[r][c] == 0 )
               {
                arr[0] = r ;
                arr[1] = c ;
                    return ;
               }
          }
    }
     if ( r == 2 || r == 4 )
     {
        arr[0] = -1 ;
        arr[1] = -1 ;
     }
}
/* get the row-col position for the vehicle with specified number */
void getrcbyinfo ( int type, int num, int *arr )
 {
  int r, c, fromrow = 0, torow = 2 ;

   if ( type == SCOOTER )
     {
        fromrow += 2 ;
        torow += 2 ;
     }

  for ( r = fromrow ; r < torow ; r++ )
     {
        for ( c = 0 ; c < 10 ; c++ )
           {
               if ( parkinfo[r][c] == num )
               {
                arr[0] = r ;
                arr[1] = c ;
                return ;
               }
           }
      }

  if ( r == 2 || r == 4 )
     {
      arr[0] = -1 ;
      arr[1] = -1 ;
     }
}
/* displays list of vehicles parked */
class disp
{
  public:
    void display( )
   {
      int r, c ;

      cout<< "Cars ->\n" ;

          for ( r = 0 ; r < 4 ; r++ )
          {
               if ( r == 2 )
                    cout<< "Scooters ->\n" ;

               for ( c = 0 ; c < 10 ; c++ )
               {
                    cout<< "\t"<< parkinfo[r][c];
                    cout<<" "<<state[r][c];
               }
                    cout<< "\n"  ;
         }
    }
};
class log
{
 public:
   int login()
    {
        string pass1;
   static int cnt;
    char pass[32];//to store password.
    int i = 0;
    char a;//a Temp char
    START:
    system("cls");
    cout <<"\n\n\n\n\n\n\n\t\t\t\t\t*********Car Parking Reservation System Login*********";
       cout << "\n\n\n\n\n\n\n\t\t\t\t\t\tEnter Password: ";

    for(i=0;;)//infinite loop
    {
        a=getch();//stores char typed in a
        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
            //check if a is numeric or alphabet
        {
            pass[i]=a;//stores a in pass
            ++i;
            cout<<"*";
        }
        if(a=='\b'&&i>=1)//if user typed backspace
            //i should be greater than 1.
        {
            cout<<"\b \b";//rub the character behind the cursor.
            --i;
        }
        if(a=='\r')//if enter is pressed
        {
            pass[i]='\0';//null means end of string.
            break;//break the loop
        }
    }
    pass1=pass;
    if(pass1 == "cpp")
    {
      cout << "\n\n\n\n\t\t\t\t\t  Access Granted! Welcome To Our System \n\n";
      system("PAUSE");   //It also prints "Press any key to continue..." but work as same as getch()
    }
   else
    {
      cout << "\n\n\n\n\t\t\t\t\tAccess Aborted...Please Try Again!!\n";
      //system("PAUSE");
      getch();
      cnt++;
      if(cnt==3)
        {
          system("CLS");
             for(i=10;i>=0;i--)
               {
                  cout<<"\n\n\n\t\t\t\t===================================================";
                  cout<<"\n\n\n\n\n\t\t\t\t\tRe-Enter the Password after seconds ";
                  cout<<i;
                  Sleep(1000);
                  system("CLS");
               }
            cnt=0;
        }
    //here we can even check for minimum digits needed
    /*if(i<=4)
    {
        cout<<"\nMinimum 6 digits needed.\nEnter Again";
        getch();//It was not pausing :p
        goto START;
    }*/
    system("CLS");
    login();
    }
    }
};

int main()
{
 int choice, type,number,row = 0, col = 0,r,c,temp,del_num;
 static int i,line_cnt,empty_slot,empty_car,empty_scooter;
 char s[50];
 int num1;
  int tarr[2];
 int finish = 1;
 disp o1;
 log o2;
time_t now;
struct tm nowlocal;
fstream ofile;
ofile.open("C://Users//DELL//Desktop//file.txt",ios::app|ios::out);

 /* creates a 2-D array of car and scooter class */
 struct vehicle *car[2][10] ;
 struct vehicle *scooter[2][10] ;

  system ( "CLS" ) ;
  o2.login();

 /* displays menu and calls corresponding functions */
 while ( finish )
 {
    system ( "CLS" );
      cout<< "\n\t\t\t\t\t\t!!!==========Car Parking===========!!!\n\t\t\t\t\t"  ;
      cout<< "===================================================\n\t\t\t\t\t"  ;
      cout<< " 1. Arrival of a vehicle \n\t\t\t\t\t"  ;
      cout<< " 2. Vehicle Info \n\t\t\t\t\t"  ;
      cout<< " 3. Remove vehicle from parking slot \n\t\t\t\t\t"  ;
      cout<< " 4. Empty slots available in parking \n\t\t\t\t\t"  ;
      cout<< " 5. Display order in which vehicles are parked \n\t\t\t\t\t" ;
      cout<< " 6. Departure of vehicle \n\t\t\t\t\t" ;
      cout<< " 7. Exit\n\t\t\t\t\t"  ;
      cout<< "===================================================\n\t\t\t\t\t" ;
      cout<<"\n\n\n\t\t\t\t\tEnter your Choice :";
      cin>> choice;

  switch ( choice )
  {
   case 1 :
          system ( "CLS" ) ;
          cout<<"\t----------";
          cout<< "\n\t|  Add   |\n" ;
          cout<<"\t----------"<<endl;
          type = 0 ;

          /* check for vehicle type */
          while ( type != CAR && type != SCOOTER )
          {
             cout<< "\tEnter vehicle type (1 for Car / 2 for Scooter ): ";
             cin>>type;
           if ( type != CAR && type != SCOOTER )
             cout<< "\n\tInvalid vehicle type...\n" ;
          }

      pro3: cout<< "\tEnter vehicle number : "  ;
      cin>> s;
      num1=strlen(s);
	if(num1>4)
    {
        cout<<"\n\tInvalid number...";
        cout<<"\n\tPlease enter again...!!!";
        getch();
        system("CLS");
        goto pro3;
    }
	istringstream(s) >> number;
	for ( r = 0 ; r < 4 ; r++ )
          {
               for ( c = 0 ; c<10 ; c++ )
               {
                    if(parkinfo[r][c]==number)
                    {
                        cout<<"\n\tDuplicate number found...!!!";
                        cout<<"\n\tPlease enter again...!!!";
                        getch();
                        system("CLS");
                        goto pro3;
                    }
                   }
               }
      /* add cars' data */
      if ( type == CAR || type == SCOOTER )
        {
          getfreerowcol ( type, tarr ) ;

           if ( tarr[0] != -1 && tarr[1] != -1 )
             {
                row = tarr[0];
                col = tarr[1];

              if ( type == CAR )
                  car[row][col] =  add ( type, number, row, col ) ;
              else
                  scooter[row - 2][col] = add ( type, number, row, col ) ; ;
             }
       else
            {
              if ( type == CAR )
                 cout<< "\n\tNo parking slot free to park a car....\n"  ;
              else
                 cout<< "\n\tNo parking slot free to park a scooter....\n" ;
            }
          }
      else
          {
             cout<< "\tInvalid type\n"  ;
             break ;
          }
             cout<< "\n\tPress any key to continue..." ;
             getch( ) ;
             break ;

      case 2 :
              system ( "CLS" ) ;
              cout<<"\t\t========================================================================";
              cout<< "\n\t\t\t|\tTotal cars parked     :"<<carcount <<"      |"<<endl ;
              cout<<"\t\t========================================================================";
              cout<< "\n\t\t\t|\tTotal scooters parked :"<<scootercount<<"      |"<<endl;
              cout<<"\t\t========================================================================";
              cout<< "\n\t\t\t|\tTotal vehicles parked :"<<vehcount<<"      |"<<endl ;
              cout<<"\t\t========================================================================";
              cout<< "\n\n\nPress any key to continue...";
              getch( ) ;
              break ;

   case 3 :
              system ( "CLS" ) ;
           //cout<< "\n\nTotal cars parked:"<<carcount <<endl ;
              cout<<"Vehicles Parked in the parking slot:";
              cout<<"\nCars:";
         for ( r = 0 ; r < 4 ; r++ )
              {
                 if ( r == 2 )
                    cout<< "\n\nScooters ->\n" ;

                     for ( c = 0 ; c < 10 ; c++ )
                        {
                            i++;
                            cout<<"\nVehicle "<<i<<": "<< parkinfo[r][c];

                            if(i==20)
                            {
                                i=0;
                            }
                        }
              }
                    cout<<"\n____________________________________________________";
                    check:cout<<"\n\n\nEnter the number you want to remove:";
                    cin>>del_num;
                    /*for ( r = 0 ; r < 4 ; r++ )
                         {
                            for ( c = 0 ; c < 10 ; c++ )
                               {
                                if(parkinfo[r][c]!=del_num)
                                  {
                                    cout<<"";
                                    if(parkinfo[r][c]==parkinfo[3][9]&&parkinfo[3][9]!=del_num)
                                      {
                                        cout<<"\nVehicle does not exist...!!!";
                                        goto check;
                                      }
                                  }
                                  else
                                  {
                                      goto check1;
                                  }

                               }
                        }*/
                      for ( r = 0 ; r < 4 ; r++ )
                         {
                            for ( c = 0 ; c < 10 ; c++ )
                               {
                                if(del_num==parkinfo[r][c])
                                  {
                                    cout<<"Vehicle Removed...!!!";
                                     parkinfo[r][c]=0;
                                   if(r<2)
                                     {
                                         carcount--;
                                     }
                                   else
                                    {
                                      scootercount--;
                                    }
                                    break;
                                  }
                               }
                        }
              vehcount--;
                cout<< "\nPress any key to continue..."  ;
                getch( ) ;
                break ;

   case 4 :
          system ( "CLS" ) ;
          for ( r = 0 ; r < 4 ; r++ )
              {
                    for ( c = 0 ; c < 10 ; c++ )
                       {
                        if(parkinfo[r][c]==0)
                            {
                              empty_slot++;
                                if(r<2)
                                   {
                                     empty_car++;
                                   }
                                else
                                   {
                                     empty_scooter++;
                                   }
                            }
                      }
                }
                cout<<"\n\n";
                  cout<<"\t===============================================================================";
                  cout<< "\n\t\t|\tNo. of Empty slots in parking are         :"<<empty_slot<<"      |"<<endl ;
                  cout<<"\t===============================================================================";
                  cout<< "\n\t\t|\tNo. of Empty slots in car parking are     :"<<empty_car<<"      |"<<endl ;
                  cout<<"\t===============================================================================";
                  cout<< "\n\t\t|\tNo. of Empty slots in scooter parking are :"<<empty_scooter<<"      |"<<endl ;
                  cout<<"\t==============================================================================="<<endl;
                  empty_car=0;
                  empty_scooter=0;
                  empty_slot=0;
                  cout<< "\n\nPress any key to continue..."  ;
                  getch( ) ;
                  break ;

   case 5 :
           system ( "CLS" ) ;
              cout<< "Display\n";
              o1.display( ) ;
              cout<< "\nPress any key to continue..."  ;
              getch( ) ;
              break ;

   case 6 :
          system ( "CLS" ) ;
          cout<< "Departure\n" ;
          type = 0 ;
          if(carcount==0&&scootercount==0)
            {
              cout<<"\n\nNo vehicle is Parked\n\n";
            }
          else
            {
               pro:  cout<< "Enter vehicle type (1 for Car / 2 for Scooter ): \n" ;
               cin>> type ;
             if ( type != CAR && type != SCOOTER)
                {
                    cout<< "\nInvalid vehicle type.\n" ;
                    goto pro;
                }
            }
               cout<< "Enter number: ";
               cin>> number ;

 if(type==CAR)
   {
     for ( r = 0 ; r < 4 ; r++ )
       {
         for ( c = 0 ; c < 10 ; c++ )
            {
               if(parkinfo[r][c]==number)
                  {
                      cout<<"\nCAR with this number is Parked here...!!!";
                      goto pro1;
                  }
                  else
                  {
                      cout<<"";
                  }
            }
        }
          cout<<"\nCAR with this number is not Parked here...!!!";
    }
      if(type==SCOOTER)
        {
          for ( r = 2 ; r < 4 ; r++ )
             {
                for ( c = 0 ; c < 10 ; c++ )
                   {
                      if(parkinfo[r][c]==number)
                        {
                            cout<<"\nSCOOTER with this number is Parked here...!!!";
                            goto pro2;
                        }
                       else
                        {
                            cout<<"";
                        }
                  }
             }
               cout<<"\nScooter with such number has not been parked here...\n";
        }
    pro1: cout<<"\n";
    pro2: cout<<"\n";
          cout<< "\nPress any key to continue...";
          getch();
          break ;

   case 7 :

          system ( "CLS" );
          cout<<"\n\n\n\t\t\t\t===================================================";
          Sleep(1000);
          cout<<"\n\n\t\t\t\t\tThanks";Sleep(500);
          cout<<" for";Sleep(1000);
          cout<<" using";Sleep(1000);
          cout<<" our";Sleep(1000);
          cout<<" service...!!!\n\n";Sleep(1000);
          cout<<"\t\t\t\t===================================================\n\n\n";
          getch();
          now=time(NULL);
          nowlocal=*localtime(&now);
          ofile<<"\n--------------------------\n";

          ofile<<"|  Date:"<<nowlocal.tm_mday<<"-"<<nowlocal.tm_mon+1<<"-"<<nowlocal.tm_year+1900<<"  |";
          ofile<<"\n--------------------------";
          ofile<<"\nCars ->\n";
            for ( r = 0 ; r < 4 ; r++ )
              {
                if ( r == 2 )
                ofile<< "Scooters ->\n" ;

                for ( c = 0 ; c < 10 ; c++ )
                  ofile<< "\t"<< parkinfo[r][c];
                  ofile<< "\n"  ;
              }
              ofile<<endl;
          ofile<< "Total cars parked:"<<carcount <<endl ;
          ofile<< "Total scooters parked:"<<scootercount<<endl;
          ofile<< "Total vehicles parked:"<<vehcount <<endl ;
          ofile<<"=======================================================================================";
          ofile<<endl<<endl;
          ofile.close();
          exit(0);
          break;
       }
    }

  return 0;
}
