void welcome() {
    system("cls");
    for(int x=0;x<80;x++)
        { gotoxy(x,0);
    cout<<""; delay(5); }
     for(int y=0;y<48;y++) {
            gotoxy(0,y);
     cout<<"\n"; delay(5); }
     for(x=79;x>0;x--)
      { gotoxy(x,49);
      cout< <""; delay(5); }
      gotoxy(80,49);
      cout<<"";
      for(y;y>0;y--)
       { gotoxy(80,y);
       cout< <"\n";
       delay(5); }
         gotoxy(10,10);
         puts("*********************** W E L C O M E *********************** ");
          gotoxy(18,16);
          puts("STUDENT MONITORING SYSTEM");
           gotoxy(38,22);
           puts(" D E V E L O P E D B Y : ");
            gotoxy(28,26);
             puts(" Shubham Verma & Shubham Singh & Shubham Garg ");
     gotoxy(28,28);
      puts(" IIyr CSE");
      gotoxy(28,30);
       puts(" Krishna Enstitute of Engineering & Technology");
       gotoxy(28,32);
       puts(" Ghaziabad");
    gotoxy(28,40);
     puts(" *** PRESS ANY KEY TO CONTINUE ***");
     getch(); }
