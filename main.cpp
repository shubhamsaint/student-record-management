#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <fstream>
#include <stdio.h>
#include <time.h>
#include <windows.h>
using namespace std;
struct student
{
    char rn[20];
    char fname[20];
    char lname[20];
    char emailid[40];
    char add[20];
    char no[20];
    char dob[20];
}st;
struct admin
{
    char password[20];
}ad;
void welcome();
void gotoxy(int x, int y)
{
  static HANDLE h = NULL;
  if(!h)
    h = GetStdHandle
(STD_OUTPUT_HANDLE);
  COORD c = { x, y };
  SetConsoleCursorPosition
(h,c);
}


void delay(long seconds)
{
	clock_t time1 = clock();  // use clock time
   	clock_t time2 = time1 + seconds;
  	while(time1 < time2)
    	time1 = clock();
  	return;
}
void welcome();
void creation();
void display();
void searching();
void insertion();
void deletion();
void modification();
int main()
{
 welcome();
 system("cls");
fstream file;
int ch,i,ch1;
cout<<"KRISHNA INSTITUTE OF ENGINEERING AND TECHNOLOGY"<<"\n"<<"\t\t"<<"STUDENT RECORDS";
system("Color 1E" );
/*HANDLE hOut;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hOut,
BACKGROUND_BLUE |
BACKGROUND_INTENSITY);*/
cout<<"\nADMIN LOGIN!!";
file.open("admin.dat",ios::in|ios::binary);
char n1[20],n2[20];
cout<<"\nUsername:";
                   cin>>n1;
                   cout<<"Password:";
                   cin>>n2;
                   file.read((char*)&ad,sizeof(ad));
                   if((strcmp(ad.password,n2)==0)&&(strcmp(n1,"admin")==0)  )
                            {
while(1)
{

    system("cls");
    system("color 4A");
    cout<<"KRISHNA INSTITUTE OF ENGINEERING AND TECHNOLOGY"<<"\n"<<"\t\t"<<"STUDENT RECORDS";
printf("\n1.Create a new file.\n");
printf("2.Insert new record.\n");
printf("3.Search the record.\n");
printf("4.Modify record.\n");
printf("5.Delete record.\n");
printf("6.ALL RECORDS\n");
printf("7.EXIT/LOGOUT\n");
printf("::------ENTER YOUR CHOICE------::");
scanf("%d",&ch);
   // cout<<"\n$$$$--------------------------------------------**************.....+++++.....*************---------------------------------------------$$$$";
switch(ch)
{
case 1:
creation();
break;
case 2:
insertion();
break;
case 3:
searching();
break;
case 4:
modification();
break;
case 5:
deletion();
break;
case 6:
display();
break;
case 7:cout<<"\n******THANK YOU******";
exit(0);
default:
printf("\nWRONG CHOICE\n\n");
break;
}
}

}
else cout<<"WRONG username or password";
return 0;
}
void creation()
{
  char n[20];
  fstream file;
  int i=0;
  int t;int l;
 char ch,ch1;
  file.open("student.dat",ios::out|ios::binary);
  do{
   cout<<"\nStudent"<<":\nRoll no.:";
   cin>>n;
   l=strlen(n);
   if(l==10)
   {
   strcpy(st.rn,n);
   cout<<"FName:";
   cin>>n;
   strcpy(st.fname,n);
   cout<<"LName:";
   cin>>n;
   strcpy(st.lname,n);
   cout<<"Email ID:";
   cin>>n;
   strcpy(st.emailid,n);
   cout<<"City:";
   cin>>n;
   strcpy(st.add,n);
   cout<<"Contact No.:";
   cin>>n;
   strcpy(st.no,n);
   cout<<"D.O.B.:";
   cin>>n;
   strcpy(st.dob,n);
   file.write((char*)&st,(sizeof(st)));
   cout<<"\t\tContinue.....(Y/N):";
   cin>>(ch1);}
   else {cout<<"INVALID ROLL NO.\n";
   cout<<"\t\tContinue.....(Y/N):";
   cin>>(ch1);}
  }  while(ch1=='Y'||ch1=='y');
  getch();
}
void display()
{
    system("color 1a");
    system("cls");
    int i=0;
    char ch;
    fstream file("student.dat",ios::in|ios::binary);
   while(file.read((char*)&st,sizeof(st)))
    {
    cout<<"\nRoll no:"<<st.rn;
    cout<<"\nName:";
    cout<<(st.fname)<<" "<<(st.lname);
    cout<<"\nEmail ID:";
    cout<<(st.emailid);
     cout<<"\nCity:";
    cout<<(st.add);
     cout<<"\nContact No.:";
    cout<<(st.no);
    cout<<"\nD.O.B:"<<(st.dob);
        cout<<"\n$$$$--------------------------------------------**************.....+++++.....*************---------------------------------------------$$$$";

    ;}
    getch();
}
void searching()
{
     int i=0;
     int f=0;
     char n1[20],n2[20];
     int ch;
     fstream file("student.dat",ios::in|ios::binary);
     cout<<"\nsearch by:\n1.Roll no"<<"\n2.Name"<<"\nEnter ur choice:";
     cin>>ch;
     switch(ch)
     {
         case 1:
             cout<<"\nEnter roll no.:";
     scanf("%s",n1);

     while(file.read((char*)&st,sizeof(st)))
     {
      if((strcmp(st.rn,n1))==0)
      {
      cout<<"\nStudent"<<":\nRoll no:"<<st.rn<<"\nName:";
      cout<<(st.fname)<<" "<<(st.lname);
      cout<<"\nEmail ID:";
      cout<<(st.emailid);
      cout<<"\nCity:";
      cout<<(st.add);
      cout<<"\nContact No.:";
      cout<<(st.no)<<"\n";
      cout<<(st.no);
    cout<<"\nD.O.B:"<<(st.dob);
        cout<<"\n$$$$--------------------------------------------**************.....+++++.....*************---------------------------------------------$$$$";

       f=1;
      }
     }
     if(f==0)
        {
            cout<<"\n**Record doesn't exist.**\n\n";
        }
        break;
        case 2:
   cout<<"FName:";
   cin>>n1;
   cout<<"LName:";
   cin>>n2;
     while(file.read((char*)&st,sizeof(st)))
     {

      if(((strcmp(st.fname,n1))==0)&&(strcmp(st.lname,n2))==0)
      {
      cout<<"\nStudent"<<":\nRoll no:"<<st.rn<<"\nName:";
      cout<<(st.fname)<<" "<<(st.lname);
      cout<<"\nEmail ID:";
      cout<<(st.emailid);
      cout<<"\nCity:";
      cout<<(st.add);
      cout<<"\nContact No.:";
      cout<<(st.no)<<"\n";
      cout<<(st.no);
    cout<<"\nD.O.B:"<<(st.dob);
        cout<<"\n$$$$--------------------------------------------**************.....+++++.....*************---------------------------------------------$$$$";

       f=1;
      }
     }
     if(f==0)
        {
            cout<<"\n**Record doesn't exist.**\n\n";
        }
        break;
        default:cout<<"\nWRONG CHOICE";
        break;
     }
        getch();
}
void deletion()
{
     int f=1;
     char n1[20],n2[20];
     cout<<"\nEnter Roll no:";
     cin>>(n1);
     fstream file("student.dat",ios::in|ios::binary);
     fstream tfile;
     tfile.open("temp.dat",ios::out|ios::binary);
     while(file.read((char*)&st,sizeof(st)))
     {

        if((strcmp(st.rn,n1))==0)
        {
          f=0;
        }
        else
        {
         tfile.write((char*)&st,sizeof(st));
        }
    }
    file.close();
    tfile.close();
       if(f==1)
       {
       cout<<"\n**Record doesn't exist.**\n\n";
       }
       else
       {
       cout<<"\n**Record deleted successfully**\n";
       }
    remove("student.dat");
    rename("temp.dat","student.dat");
    getch();
}
void modification()
{
     int f=1;
     int choice;
     char n1[20],n2[20];char n[20],n3[20];
     cout<<"\nEnter roll no. of student whose data to modify/update:";
     scanf("%s",n3);
     fstream file("student.dat",ios::in|ios::binary);
     fstream tfile;
     tfile.open("temp.dat",ios::out|ios::binary);
     while( file.read((char*)&st,sizeof(st)))
     {
     if((strcmp(st.rn,n3))==0)
        {
          cout<<"\nMODIFY :"<<"\n1:Name"<<"\n2:Email id"<<"\n3:Address"<<"\n4:Contact no."<<"\n5:D.OB."<<"\nEnter your choice for modification:";
          cin>>choice;
          switch(choice)
          {
          case 1:cout<<"\nEnter name";
          scanf("%s",n1);scanf("%s",n2);
          strcpy(st.fname,n1);strcpy(st.lname,n2);
          break;
          case 2:cout<<"\nEnter email id:";
          scanf("%s",n);
          strcpy(st.emailid,n);
          break;
          case 3:cout<<"\nEnter City:";
          scanf("%s",n);
          strcpy(st.add,n);
          break;
          case 4:cout<<"\nEnter contact no:";
          scanf("%s",n);
          strcpy(st.no,n);
          break;
          case 5:cout<<"\nEnter D.O.B::";
          scanf("%s",n);
          strcpy(st.dob,n);
          }
          f=0;
          tfile.write((char*)&st,sizeof(st));
        }
        else
        {
         tfile.write((char*)&st,sizeof(st));
        }
    }
    file.close();
    tfile.close();
      if(f==1)
      {
      cout<<"\n**Record doesn't exist.**\n\n";
      }
      else
      {
      cout<<"\n**Record is modified/updated successfully**\n";
      }
      remove("student.dat");
      rename("temp.dat","student.dat");
      getch();
}
void insertion()
{
  char n[20],ch1;
  int i=0;
  int l;
  int t;
  fstream tfile("student.dat",ios::in|ios::out|ios::binary);
   tfile.seekp(0,ios::end);
   do{
   cout<<"\nStudent"<<":\nRoll no.:";
   cin>>n;
   l=strlen(n);
   if(l==10)
   {
   strcpy(st.rn,n);
   cout<<"FName:";
   cin>>n;
   strcpy(st.fname,n);
   cout<<"LName:";
   cin>>n;
   strcpy(st.lname,n);
   cout<<"Email ID:";
   cin>>n;
   strcpy(st.emailid,n);
   cout<<"City:";
   cin>>(n);
   strcpy(st.add,n);
   cout<<"Contact No.:";
   cin>>n;
   strcpy(st.no,n);
   cout<<"D.O.B:";
   cin>>n;
   strcpy(st.dob,n);
   tfile.write((char*)&st,(sizeof(st)));
   cout<<"\t\tContinue.....(Y/N):";
   cin>>(ch1);
  }
  else{ cout<<"\n INVALID ROLL NO.\n";
  cout<<"\t\tContinue.....(Y/N):";
   cin>>(ch1);}
  } while(ch1=='Y'||ch1=='y');
   tfile.close();
    getch();
}
void welcome()
{
    int x,y;
    system("cls");
    for(x=0;x<80;x++)
        { gotoxy(x,0);
    cout<<""; delay(5); }
     for(y=0;y<48;y++) {
            gotoxy(0,y);
     cout<<"\n"; delay(5); }
     for(x=79;x>0;x--)
      { gotoxy(x,49);
      cout<<""; delay(5); }
      gotoxy(80,49);
      cout<<"";
      for(y;y>0;y--)
       { gotoxy(80,y);
       cout<<"\n";
       delay(5); }
         gotoxy(10,10);
         puts("*********************** W E L C O M E *********************** ");
          gotoxy(27,16);
          puts("STUDENT MONITORING SYSTEM");
           gotoxy(28,22);
           puts(" D E V E L O P E D B Y : ");
            gotoxy(28,26);
             puts(" Shubham Verma & Shubham Singh & Shubham Garg ");
     gotoxy(28,28);
      puts(" IIyr CSE");
      gotoxy(28,30);
       puts(" Krishna Institute of Engineering & Technology");
       gotoxy(28,32);
       puts(" Ghaziabad");
    gotoxy(28,40);
     puts(" *** PRESS ANY KEY TO CONTINUE ***");
     getch(); }
