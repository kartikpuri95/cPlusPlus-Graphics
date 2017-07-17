#include<fstream.h>
#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<ctype.h>
#include<process.h>
#include<iomanip.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<dos.h>
/************registration***************************/


void welcome_screen();
void welcome_screen()
     {
	clrscr();
	int gdriver=DETECT,gm;
	initgraph(&gdriver,&gm,"C:\\TC\\BGI");
	setbkcolor(5);

	settextstyle(5,0,6);
	outtextxy(150,250,"**************** W E L C O M E  *********************** ");
	textcolor(BLUE);
	outtextxy(200,300,"*** TECHOBLOG REGISTRATION *** " );
	textcolor(RED);
	outtext("***** M E B E R S H I P   ****** ");
	delay(1000);
	closegraph();
	return;
     }
class directory
     {
       public:
	       int record;
	       long pn1;
	       char pn2[10];
	       int age;
	       char address1[50];
	       char address2[50];
	       char occupation[20];
	       char name[20];
	       char emailadd[25];
	       char internetadd[25];

	       void addition();
	       void deleate();
	       void menu();
	       void search();
	       void view1();
	       void init();
	       void display();
	       void view();

	       int test();
	    }obj;
void directory::addition()  //ADDING  INFORMATION
    {
      ofstream fout;
      fout.open("heera",ios::out|ios::app);
      init();
      fout.write((char*)&obj,sizeof(obj));
      fout.close();
    }
int directory::test()    //FIND NO. OF RECORDS
    {
      ifstream fin;
      fin.open("heera");
      fin.seekg(0,ios::end);
      int n;
      n=fin.tellg()/sizeof(obj);
      cout<<" \n NUMBER OF RECORDS = "<<n ;
      return n ;
    }
void directory::search()  //SEARCHING FOR A PARTICULAR NUMBER
    {
      ifstream fin;
      fin.open("heera");
      if(fin.fail())
	{
	  cout<<" \n FILE NOT FOUND ";
	  getch();
	  return;
	}
      clrscr();
      textcolor(BLACK+BLINK);
      gotoxy(30,1);
      cprintf(" [SEARCHING] ");
      cout<<" \n ENTER PHONE NUMBER TO BE SEARCHED : ";
      long pn;
      cin>>pn;
      int n;
      n=test();
      for(int i=0;i<n;i++)
	{
	  fin.read((char*)&obj,sizeof(obj));
	  if(pn==pn1)
	    {
	      view1();
	      return;
	    }
	}
      if(fin.eof())
	{
	  cout<<" \n RECORD NOT FOUND ";
	}
    }
void directory::init()  // ENTERING THE DETAILS
    {

      clrscr();
      char ch;
      textcolor(BLACK+BLINK);
      gotoxy(30,1);
      cprintf(" [ADDITION] ");
      textcolor(BLACK);
      cout<<" \n ENTER HOUSE PHONE NUMBER : ";
      cin>>pn1;
      cout<<" \n ENTER OFFICE PHONE NUMBER : ";
      cin>>pn2;
      // ch=cin.get();
      cin.get(ch);
      cout<<" \n ENTER NAME : ";
      cin.getline(name,20,'\n');
      cout<<" \n ENTER THE OCCUPATION : ";
      cin.getline(occupation,20,'\n');
      cout<<" \n ENTER HOUSE ADDRESS : ";
      cin.getline(address1,50,'\n');
      cout<<" \n ENTER OFFICE ADDRESS : ";
      cin.getline(address2,50,'\n');
      cout<<" \n ENTER EMAIL ADDRESS : ";
      cin.getline(emailadd,25,'\n');
      cout<<" \n ENTER INTERNET ADDRESS : ";
      cin.getline(internetadd,25,'\n');
    }

void directory::view1() //TO DISPLAY ALL THE RECORDS
    {
      cout<<"\n";
      cout<<" PHONE NUMBER1 : "<<obj.pn1<<"\n";
      cout<<" PHONE NUMBER2 : "<<obj.pn2<<"\n";
      cout<<" NAME : "<<obj.name<<"\n";
      cout<<" HOUSE ADDRESS : "<<obj.address1<<"\n";
      cout<<" OCCUPATION : "<<obj.occupation<<"\n";
      cout<<" OFFICE ADDRESS : "<<obj.address2<<"\n";
      cout<<" EMAIL ADDRESS : "<<obj.emailadd<<"\n";
      cout<<" INTERNET ADDRESS : "<<obj.internetadd<<"\n";
      getch();
    }
/*
	  */
void  directory::deleate()
    {
       clrscr();
       window(1,1,80,25);
       textcolor(BLACK+BLINK);
       gotoxy(30,1);
       cprintf("[DELETION]");
       long pn;
       int n,i;
       ifstream fin;
       ofstream fout;
       fin.open("heera");
       if(fin.fail())
	{
	  cout<<"\n FILE NOT FOUND ! ";
	  getch();
	  return;
	}
       fout.open("new");
       n=test();
       if(n==0)
	{
	  cout<<"\n FILE IS EMPTY ! ";
	  getch();
	  return;
	}
      for(i=0;i<n;i++)
	{
	  fin.read((char*)&obj,sizeof(obj));
	  fout.write((char*)&obj,sizeof(obj));
	}
      fin.close();
      fout.close();
      fout.open("meera",ios::trunc);
      fin.open("new");
      if(fin.fail())
	{
	  cout<<"\n FILE NOT FOUND ! ";
	  getch();
	  return;
	}
     cout<<"\n ENTER PHONE NUMBER :";
     cin>>pn;
     for(i=0;i<n;i++)
       {
	 fin.read((char*)&obj,sizeof(obj));
	 if(pn!=pn1)
	    fout.write((char*)&obj,sizeof(obj));
       }
     fout.close();
     fin.close();

    }
 void directory::view()
   {
     ifstream fin;
     int n,j;
     fin.open("heera");
     if(fin.fail()||fin.bad())
       {
	  cout<<"\n FILE NOT FOUND ! ";
	  getch();
	  return;
       }
     clrscr();
     int i=0;
     n=test();
     for(j=0;j<n;j++)
       {
	 cout<<"\n RECORD "<<i+1<<"\n";
	 fin.read((char*)&obj,sizeof(obj));
	 cout<<"\n PHONE NUMBER1 :"<<obj.pn1<<"\n";
	 cout<<"\n PHONE NUMBER2 :"<<obj.pn2<<"\n";
	 cout<<"\n NAME :"<<obj.name<<"\n";
	 cout<<"\n HOUSE ADDRESS :"<<obj.address1<<"\n";
	 cout<<"\n OCCUPATION :"<<obj.occupation<<"\n";
	 cout<<"\n OFFICE ADDRESS :"<<obj.address2<<"\n";
	 cout<<"\n INTERNET ADDRESS :"<<obj.internetadd<<"\n";
	 cout<<"\n EMAIL ADDRESS : "<<obj.emailadd<<"\n";
	 i+=1;
       }
      fin.close();
      getch();

   }

void  directory::menu()
    {
       char ch;
       clrscr();
       textbackground(WHITE);
       textcolor(BLACK);
       gotoxy(30,8);
       cprintf(" A:ADDITION ");
       gotoxy(30,9);
       cprintf(" D: DELETION \n  \r ");
       gotoxy(30,10);
       cprintf(" M:MODIFICATION \n \r ");
       gotoxy(30,11);
       cprintf(" V:VIEW \n \r ");
       gotoxy(30,12);
       cprintf(" S:SEARCH \n \r ");
       gotoxy(30,13);
       cprintf(" E:EXIT \n \r ");
       ch=getch();

      switch(ch)
	   {
	     case 'a':
	     case 'A':
		addition();
		break;
	     case 'd' :
	     case 'D' :
		deleate();
		break;
	    // case 'm':
	    // case 'M':
	       //	modification();
	       //	break;
	     case 'v':
	     case 'V':
		view();
		break;
	     case 's':
	     case 'S':
		search();
		break;
	     case 'e':
	     case 'E':
		system("cls");
		exit(0);
	 }
}
/////////////////////////////////////////////////////////////////////////
int regis()
	    {
      welcome_screen();
      for(;;)
      obj.menu();
      return 0;
   }

/**************************prottotype for high low game****************/
void high_low()
{
 int totchan=7;
 int number;        //the computer's random number
 int guess;         //the user's guess
 int chances=0,score=0,chanscor;        //chanscor stores score for 1successful chance.
 char ans;
 do
 { clrscr();
   chances=score=0;
       textcolor(BLUE);
   cout<<"Welcome to the High/Low game.";
   cout<<"I will pick a random number from 0 to 100.";
   cout<<"You must try to guess the number.";
   randomize();
   number=(int)(rand()%100);
   chanscor=100/totchan;        //score for each successful chance
   do
   {   textcolor(RED);
     cprintf("What is your guess? (0 to 100) ");
     //cout<<"What is your guess? (0 to 100) ";
     cin>>guess;
     if((guess<0)||(guess>100))
     {
	cout<<"Sorry, but your guess"<<guess<<"must be from 0 to 100.";
     }
     else if(guess <number)
     {
	cout<<guess<<" is low.Try a higher number.";
     }
     else if(guess>number)
     {
	cout<<guess<<" is high.Try a lower number."<<endl;
     }
     else		//if correct number is guessed
     {			//number is correct, and the "do" loop will end below
	textcolor(GREEN);

	cout<<guess;
	cprintf("CONGRATS. ITS COORECT");
	score=chanscor*(totchan-chances);   //score calculated for number ofchances left
	cout<<"Your score is "<<score<<endl;
	break;
     }
     chances++;
     if(guess!=number)
	 cout<<"Now you have "<<totchan-chances<<"chances left."<<endl;
     if(chances==totchan)
	 { cout<<"Only "<<totchan<<"chances are allowed.Better luck nexttime";
	   cout<<"The actual number was "<<number<<endl;
	   break;
	 }
     }while (guess!=number);
     cout<<"Thank you for playing High/Low!";
     cout<<"Want to play it again? (y/n)...";
     cin>>ans;
   }while(ans=='y' || ans=='Y');
 }

/**********************protype for picture*****************************/
void pic()
{
int gdriver=DETECT,gm;
initgraph(&gdriver,&gm,"C:\\TC\\BGI");
textcolor(BLUE);
outtextxy(200, 15, "TAP AND A BUCKET");
ellipse(300,200,0,360,50,25);//base
ellipse(300,300,0,360,50,25);//lower base
line(250,200,250,300);
line(350,200,350,300);
ellipse(300,100,180,360,5,2);//rim
line(295,100,295,80);
line(305,100,305,86);
arc(300,80,90,180,5);//bottm shpe
putpixel(306,85,15);
putpixel(307,84,15);//side shape
line(308,84,630,84);
line(300,75,303,75);
line(314,75,630,75);
putpixel(304,74,15);//length of nul
putpixel(305,73,15);

line(306,72,306,65);
line(311,72,311,65);//upper nul line//upper nul line
   putpixel(312,73,15);                  //filling spacces
   putpixel(313,74,15);  //filling spaces
   pieslice(309,62,0,360,5);
   setfillstyle(1,BLUE);
   setcolor(BLUE);
   for(int i=0;i<=7;i++)
   {
   line(297+i,103,297+i,300); //for creating line

      for(i=1;i<100;i++);
	 {
	 setcolor(LIGHTBLUE);
	 ellipse(300,300-i,180,360,4,2);
	 delay(30);                                  //completing and fillling the circle
	 fillellipse(300,300-i,49,25);
	 setcolor(1);
	 line(297,275-i,303,275-i);
	 setcolor(15);
	 ellipse(300,200,180,360,50,25);
	 delay(100);
	 }
       ellipse(300,200,0,360,50,25);
       setcolor(0);
	for(i=0;i<=7;i++)
	 {line(297+i,103,297+i,174);

		    }
		    }
getch();

}











/**********************************protype for swapping char array****/
void swap(char a[], char b[])
   {
   char c;
   c=a[0];
   a[0]=b[0];
   b[0]=c;
   }


/***********************PROTYPE FOR SHUFFLING GAMES******************/

void game_swap()

   {
   a:
int card1[] = { 20,20 , 50,20 , 50,100 , 20,100 , 20,20 }; //decration for poly rectangle
int card2[] = { 80,20 , 110,20 , 110,100 , 80,100 , 80,20 };
int card3[] = { 140,20 , 170,20 , 170,100 , 140,100 , 140,20 };

   char val[3][2]={ "1" , "2", "3" };  //value 3/2 integer
   clrscr();
   char count[2]="0";
   int swaping_number=0;         //for number of times to swap the cards
   int gdriver=DETECT,gm;
initgraph(&gdriver,&gm,"C:\\TC\\BGI");

   floodfill(40,40,getmaxcolor());

    delay(100);

   setfillstyle(2,GREEN);
   fillpoly(5,card1);
   fillpoly(5,card2);
   fillpoly(5,card3);

   settextstyle(3,0,6);
   setcolor(BLUE);
   outtextxy(25,25,val[0]);

   outtextxy(85,25,val[1]);

   outtextxy(145,25,val[2]);

   do
      {
      int num=0;
      int choice[2];
      count[0]++;

      delay(1500);

      settextstyle(3,0,2);

      outtextxy(20,150,"No. of Times Cards have been swapped:");
      settextstyle(4,0,3);

      outtextxy(20+swaping_number*20,170,count);
      setfillstyle(2,YELLOW);
      fillpoly(5,card1);
      fillpoly(5,card2);
      fillpoly(5,card3);

	 do
	 {
	 randomize();
	 choice[num]= (rand() + num) % 3;

	 switch(choice[num])
	    {
	    case 0:
	       setfillstyle(3,BLUE);
	       fillpoly(5,card1);
	       break;
	    case 1:
	       setfillstyle(3,BLUE);
	       fillpoly(5,card2);
	       break;
	    case 2:
	       setfillstyle(3,BLUE);
	       fillpoly(5,card3);
	       break;
	    }
	 num++;
	 }while(num<2);

      swap(val[(choice[0])],val[(choice[1])]);

      }while(swaping_number++<6);

   settextstyle(DEFAULT_FONT,HORIZ_DIR,3);

   outtextxy(20,200,"What is card number 2");
   char ans;
   ans=getch();
   if(ans==val[1][0])
      {

      outtextxy(20,230,"HURRAY");
      }
     else
      {

      outtextxy(20,230,"YOU DUMBO");
      }

   getch();
   closegraph();
   gotoxy(2,2);
textcolor(RED);
cprintf("                           CARD SHUFFLING GAME                      ");
gotoxy(2,3);
textcolor(BLUE);
cprintf("---------------------------------------------------------------------");
gotoxy(2,6);
textcolor(GREEN);
cprintf("1)------------>DO U WANT TO CONTINUE");
gotoxy(2,8);
textcolor(GREEN);
cprintf(" 2)------------->EXIT               ");
gotoxy(2,12);
textcolor(BLUE);
gotoxy(20,12);
textcolor(RED);
cprintf("                                             " );
gotoxy(2,14);
textcolor(BLUE);
cprintf("ENTER UR CHOICE----------------------------------------->");


     int input;
     cin>>input;
     switch(input)
    {
     case 1:
     goto a;
     break;
     case 2:
     exit(0);
     break;
    }
   getch();
   }





/*******************************STARTING OF MAIN PAGE******************/

//declaration for 1st page*/
 main()
{
clrscr();
int gdriver=DETECT,gm;
/********registry page*****************/
   initgraph(&gdriver,&gm,"C:\\TC\\BGI");
setbkcolor(GREEN);

setfillstyle(2,BLACK);
setcolor(getmaxcolor());
rectangle(550,500,100,100);
floodfill(550,500,BLACK);
setcolor(BLUE);
settextstyle(6,0,5);
outtextxy(100, 40, "PRODUCT REGISTRY");
char name[20];
float num;
int code[]={1203,1332,4545,5656,6733,2344,2344,6776,6789,7899,7889};
gotoxy(15,10);
cout<<"NAME-:";
cin>>name;
gotoxy(15,15);
cout<<"PHONE-:";
cin>>num;
gotoxy(15,20);
cout<<"CD CODE-:";
randomize();
rand();
double r=code[rand()];
cout<<r<<"(keep your CD code to continue)";
getch();
closegraph();
clrscr();


initgraph(&gdriver,&gm,"C:\\TC\\BGI");
setbkcolor(BLUE);

setfillstyle(2,BLACK);
setcolor(getmaxcolor());
rectangle(550,500,100,100);
floodfill(550,500,BLACK);
setcolor(BLUE);
settextstyle(6,0,5);
outtextxy(100, 40, "ENTER CD KEY");
gotoxy(15,10);
cout<<"CD KEY-:";
double cde;
l:
cin>>cde;
if(cde==r)
{
floodfill(550,500,BLACK);
setcolor(BLUE);
settextstyle(6,0,5);
setcolor(GREEN);
outtextxy(200, 40, "ACCESS GRANTED ");
getch();
closegraph();
}
else
{
floodfill(550,500,BLACK);
setcolor(BLUE);
settextstyle(6,0,5);
setcolor(RED);
outtextxy(200, 40, "ACCESS DENIED");
goto l;
}

getch();

/********************first page ******************/
initgraph(&gdriver,&gm,"C:\\TC\\BGI");
  for(int j=0;j<=360;j++)
      {
      setfillstyle(3, 5);
       bar(90,100,j,90);
	for(int i=0;i<=7;i++)
	  {
	   setfillstyle(1, i);
	   floodfill(40, 40, 6);
	   setfillstyle(3, 5);

	   pieslice(200, 200, 0, j, 100);
	   }
	   settextstyle(2, 0, 4);
	     outtextxy(40, 10, "ver.1.100.1(build-0110) ");
	    settextstyle(3, 0, 5);
	    outtextxy(40, 10, "MULTIMEDIA ");
	    outtextxy(40,350,"Made by-:kartik");
	    setfillstyle(1, BLACK);
	    fillellipse(450,450, 20, 20);
	    settextstyle(1, 0, 2);
	    outtextxy(445,438,"C");
	     outtextxy(445,438,"C");
	    }
			    //close graph

//initialization of index



initgraph(&gdriver,&gm,"C:\\TC\\BGI");
setfillstyle(1,5);
floodfill(50,50,4);
textcolor(RED);
outtextxy(200, 15, "INDEX-:");
		for( j=0;j<=360;j++)
		{
		   setfillstyle(3,5);
		  bar(10,50,j,60);
		    for(int i=0;i<=7;i++)
		  {

		   setfillstyle(1, 2);

		   floodfill(40, 40, 4);
		   setfillstyle(2, 3);


		pieslice(100, 100, 0, j, 40);
		pieslice(100, 200, 0, j, 40);
		pieslice(100, 300, 0, j, 40);
		pieslice(100, 400, 0, j, 40);
		}
		settextstyle(3, 0, 5);
		outtextxy(200,65, "SHUFFLING GAME");
		outtextxy(200,165,"HIGH LOW GAME");
		outtextxy(200,265,"PICTURE");
		outtextxy(200,365,"REGISTRATION");

	    }
	    closegraph();

/**********STARTING OF INDEX IN CONIO******************/
for(int x=0,y=0;x<70,y<70;x++,y++)
{
gotoxy(x,0);
cout<<"-----";
gotoxy(0,y);
cout<<"|";
}

gotoxy(20,3);
textcolor(BLUE);
cprintf(" I ");
textcolor(YELLOW);
cprintf(" N ");
textcolor(MAGENTA);
cprintf(" D  ");
textcolor(BLUE);
cprintf(" E ");
textcolor(RED);
cprintf(" X ");
textcolor(RED);
gotoxy(20,1);
textcolor(BLUE);
cout<<"-------------------------------------------------------";
gotoxy(2,6);
cprintf("1)------->SHUFFLING CARD GAME");
textcolor(GREEN);
gotoxy(2,9);
cprintf("2)------->HIGH LOW GAME       ");
textcolor(MAGENTA);
gotoxy(2,12);
cprintf("3)---------->PICTURE");
textcolor(YELLOW);
gotoxy(2,15);
cprintf("4)---------->EXIT");
gotoxy(2,15);
cprintf("5)---------->REGISTRATION");

int p;                 //value taken by user
gotoxy(2,18);
textcolor(RED);
cprintf("-----");
textcolor(GREEN);
cprintf("      -----");
textcolor(YELLOW);
cprintf("            -----");
textcolor(BLUE);
cprintf("                  -----");

gotoxy(2,20);
cout<<"ENTER DESIRE OPTION--------------------------->";
cin>>p;
clrscr();
switch(p)
{
/**********************case for shuffling card*******************/
case(1):
clrscr();
gotoxy(2,2);
textcolor(RED);
cprintf("                           CARD SHUFFLING GAME                      ");
gotoxy(2,3);
textcolor(BLUE);
cprintf("---------------------------------------------------------------------");
gotoxy(2,6);
textcolor(GREEN);
cprintf("1)------------>HIT  ENTER   TO  PLAY!!!!!!!!!!!!!!");
gotoxy(2,8);
textcolor(GREEN);
cprintf("               ");
gotoxy(2,12);
textcolor(BLUE);
gotoxy(20,12);
textcolor(RED);
cprintf("             INSTRUCTION                               ");
gotoxy(2,14);
textcolor(BLUE);
cprintf("-----------------------------------------------------------------------");
gotoxy(2,16);
textcolor(YELLOW);
cprintf("THIS IS A CARD SHUFFLING GAME IN WHICH CARD SHUFFLE 7 TIMES");
gotoxy(2,17);
cprintf("ALL U NEED TO DO IN THIS GAME IS TO TELL THE POSITION OF THE ");
gotoxy(2,18);
cprintf("MIDDLE CARD AFTER SHUFFLING OF ALL THE CARD .");
gotoxy(2,20);
cprintf("                 A YELLOW LIGHT WILL BLINK ON EACH CARD SO AS TO");
gotoxy(2,21);
cprintf("                 TELL THE SHUFFLING OF CARD");
gotoxy(2,23);
cprintf("                  BEST OF LUCK :)                           ");
gotoxy(2,25);
cprintf("                               GET READY TO PLAY---->        ");
getch();
closegraph();
game_swap(); //calling game function
break;
/**************starting of high low game*************************/
case 2:
clrscr();
gotoxy(2,2);
textcolor(RED);
cprintf("                           HIGH LOW GAME                      ");
gotoxy(2,3);
textcolor(BLUE);
cprintf("---------------------------------------------------------------------");
gotoxy(2,6);
textcolor(GREEN);
cprintf("1)------------>HIT  ENTER   TO  PLAY!!!!!!!!!!!!!!");
gotoxy(2,8);
textcolor(GREEN);
cprintf("               ");
gotoxy(2,12);
textcolor(BLUE);
gotoxy(20,12);
textcolor(RED);
cprintf("             INSTRUCTION                               ");
gotoxy(2,14);
textcolor(BLUE);
cprintf("-----------------------------------------------------------------------");
gotoxy(2,16);
textcolor(YELLOW);
cprintf("THIS IS A HIGH LOW GAME");
gotoxy(2,17);
cprintf("ALL U NEED TO DO IN THIS GAME IS THAT TELL THE NUMBER BETWEEN  ");
gotoxy(2,18);
textcolor(RED);
cprintf("0 TO 100 .");
gotoxy(2,20);
cprintf("                 YOU HAVE ONLY 7 TRIES TO COMPLETE THIS GAME");
gotoxy(2,21);
cprintf("                                                     ");
gotoxy(2,23);
cprintf("                  BEST OF LUCK :)                           ");
gotoxy(2,25);
cprintf("                               GET READY TO PLAY---->        ");
getch();
textcolor(BLUE);
high_low();
break;
/************************PICTURE************************/
case 3:
pic();
break;
case 4:
exit(0);
case 5:
regis();
}

getch();

}
