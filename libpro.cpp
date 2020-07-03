/*SOFTWARE FOR THE USE IN LIBRAY
***INTRODUCTION***

NAME:- SHOUVICK PAUL
COLLEGE:-NARASINHA DUTT COLLEGE

#########################
## MILAN MANDIR LIBRAY ##
#########################
*/
//***************************************************************
// HEADER FILE USED IN PROJECT
//****************************************************************
#include<fstream.h>  //for reading and writing files
#include<conio.h>    //for clrscr()
#include<stdio.h>    //for gets and puts function
#include<stdlib.h>  //for exit function
#include<string.h>   //for string characters
#include<iomanip.h>  //for setw function
//***************************************************************
// CLASS USED IN PROJECT
//****************************************************************
class Book
{
	char bid[6];     // var bid stands for book id
	char bnm[50];    // var bnm stands for book name
	char anm[20];    // var anm stands for author name
	int qty;         // var qty stands for quantity

	public:

	void create_book();    // function to get data from user

	void show_book();      //function to show data on screen

	void modify_book();    // function to get new data from user

	char* retbid()         //function to return book id
	{
		return bid;
	}

	int retqty();          // function to return quantity of the book

	void report();			  // function to show data in a tabular format

}; //class ends here

class Member
{
	char mid[6];           		//  var mid stands for member id
	char nm[25];               //  var nm stands for  name of the member
	char mob_no[11],add[35];   //  var mob_no stands for  contact no. of the member &  var add stands for address of the member
	public:
	void create_member();      // function to get data from user

	void show_member();       // function to show data on screen

	void modify_member();       // function to get new data from user

	char* retmid()             // function to return member id
	{
		return mid;
	}
	void report();             // function to show data in a tabular format

}; //class end here

class issue
{
	char mn[6],bn[6];
	int found=0,flag=0;
	int token=0,m_bno;
	public:
	void book_issue();        // function to issue a book to a member
	{
		clrscr();
		cout<<"\n\nBOOK ISSUE …";
		cout<<"\n\n\tEnter The member id";
		cin>>mn;
		fp.open("mem.dat",ios::in|ios::out);
		fp1.open("bk.dat",ios::in|ios::out);
		while(fp.read((char*)&mem,sizeof(mem)) && found==0)
		{
			if(strcmpi(mem.retmid(),mn)==0)
			{
				found=1;
				if(mem.rettoken()==0)
				{
					cout<<"\n\n\tEnter the book no. ";
					cin>>bn;
					while(fp1.read((char*)&bk,sizeof(bk))&& flag==0)
					{
						if(strcmpi(bk.retbid(),bn)==0)
						{
							if(bk.qty>0)
							{
								bk.show_book();
								flag=1;
								mem.addtoken();
								mem.getm_bno(bk.retbid());
								int pos=-1*sizeof(mem);
								fp.seekp(pos,ios::cur);
								fp.write((char*)&st,sizeof(student));
								cout<<"\n\n\t Book issued successfully\n\nPlease Note: Write the current date in backside of your book and submit within 15 days fine Rs. 1 for each day after 15 days period";
							}
						}
					}
					if(flag==0)
					cout<<"Book id. does not exist";
				}
				else
				cout<<"You have not returned the last book ";
			}
		}
		if(found==0)
		cout<<"member record not exist…";
		getch();
		fp.close();
		fp1.close();
	}
};             //class end here

void Book::create_book()
{
		cout<<"\nNEW BOOK ENTRY…\n";
		cout<<"\nEnter the Book id.";
		cin>>bid;
		cout<<"\n\nEnter the Name of the Book ";
		gets(bnm);
		cout<<"\n\nEnter the Author’s Name ";
		gets(anm);
		cout<<"\n\nEnter the Quantity of the Book";
		cin>>qty;
		cout<<"\n\n\nBook Created..";
}

void Book::show_book()
{
		cout<<"\nBook id. : "<<bid<<endl;
		cout<<"\nBook Name : "<<bnm<<endl;
		cout<<"\nAuthor Name : "<<anm<<endl;
		cout<<"\nQuantity of the Book : "<<qty<<endl;
}

void Book::modify_book()
{
	cout<<"\nBook no. : "<<bid;
	cout<<"\nModify Book Name : ";
	gets(bnm);
	cout<<"\nModify Author’s Name of Book : ";
	gets(anm);
	cout<<"\nModify Quantity of Book : ";
	cin>>qty;
}


int Book::retqty()
{
	return qty;
}

void Book::report()
{
	cout<<bid<<setw(27)<<bnm<<setw(27)<<anm<<setw(15)<<qty<<endl;
}

void Member::create_member()
{
	clrscr();
	cout<<"\nNEW Member ENTRY…\n";
	cout<<"\nEnter the Member Id ";
	cin>>mid;
	cout<<"\n\nEnter the Name of the Member ";
	gets(nm);
	cout<<"Enter the Address of the Member\n";
	gets(add);
	cout<<"Enter the contact No. of the member\n";
	gets(mob_no);
	cout<<"\n\nMember Record Created..";
}

void Member::show_member()
{
	cout<<"\nMember Id. : "<<mid<<endl;
	cout<<"\nMember Name : "<<nm<<endl;
	cout<<"\nMember's Address : "<<add<<endl;
	cout<<"\nMember's Contact No. : "<<mob_no<<endl;
}

void Member::modify_member()
{
	cout<<"\nMember Id. : "<<mid;
	cout<<"\nModify Member Name : ";
	gets(nm);
	cout<<"\nMember's Contact No.";
	gets(mob_no);
	cout<<"\n member's address";
	gets(add);
}

void Member::report()
{
	cout<<"\t"<<mid<<setw(20)<<nm<<setw(10)<<mob_no<<setw(20)<<add<<endl;
}

/****************************************************************
 global declaration for stream object, object
****************************************************************/
Book bk;
fstream fp,fp1;
Member mem;

/***************************************************************
 function to write in file
****************************************************************/
void write_book()
{
char ch;
fp.open("bk.dat",ios::out|ios::app);
do{
clrscr();
bk.create_book();
fp.write((char*)&bk,sizeof(bk));
cout<<"\n\nDo you want to add more record..(y/n?)";
cin>>ch;
}while(ch=='y'||ch=='Y');
fp.close();
}

void write_member()
{
char ch;
fp.open("mem.dat",ios::out|ios::app);
do{
mem.create_member();
fp.write((char*)&mem,sizeof(mem));
cout<<"\n\ndo you want to add more record..(y/n?)";
cin>>ch;
}while(ch=='y'||ch=='Y');
fp.close();
}

//***************************************************************
// function to read specific record from file
//***************************************************************
void display_spb(char n[])
{
cout<<"\nBOOK DETAILS\n";
int flag=0;
fp.open("bk.dat",ios::in);
while(fp.read((char*)&bk,sizeof(bk)))
{
if(strcmpi(bk.retbid(),n)==0)
{
bk.show_book();
flag=1;
}
}
fp.close();
if(flag==0)
cout<<"\n\nBook does not exist";
getch();
}

void display_spm(char n[])
{
cout<<"\nMember DETAILS\n";
int flag=0;
fp.open("mem.dat",ios::in);
while(fp.read((char*)&mem,sizeof(mem)))
{
if((strcmpi(mem.retmid(),n)==0))
{
mem.show_member();
flag=1;
}
}
fp.close();
if(flag==0)
cout<<"\n\nmember does not exist";
getch();
}
/***************************************************************
 function to modify record of file
****************************************************************/
void modify_book()
{
char n[6];
int found=0;
clrscr();
cout<<"\n\n\tMODIFY BOOK REOCORD…. ";
cout<<"\n\n\tEnter The book no. of The book";
cin>>n;
fp.open("bk.dat",ios::in|ios::out);
while(fp.read((char*)&bk,sizeof(bk)) && found==0)
{
if(strcmpi(bk.retbid(),n)==0)
{
bk.show_book();
cout<<"\nEnter The New Details of book"<<endl;
bk.modify_book();
int pos=-1*sizeof(bk);
fp.seekp(pos,ios::cur);
fp.write((char*)&bk,sizeof(bk));
cout<<"\n\n\t Record Updated";
found=1;
}
}
fp.close();
if(found==0)
cout<<"\n\n Record Not Found ";
getch();
}

void modify_member()
{
char n[6];
int found=0;
clrscr();
cout<<"\n\n\tMODIFY MEMBER RECORD… ";
cout<<"\n\n\tEnter The member id. of The member";
cin>>n;
fp.open("mem.dat",ios::in|ios::out);
while(fp.read((char*)&mem,sizeof(mem)) && found==0)
{
if(strcmpi(mem.retmid(),n)==0)
{
mem.show_member();
cout<<"\nEnter The New Details of member"<<endl;
mem.modify_member();
int pos=-1*sizeof(mem);
fp.seekp(pos,ios::cur);
fp.write((char*)&mem,sizeof(mem));
cout<<"\n\n\t Record Updated";
found=1;
}
}
fp.close();
if(found==0)
cout<<"\n\n Record Not Found ";
getch();
}
/***************************************************************
 function to delete record of file
****************************************************************/
void delete_book()
{
char n[6];
clrscr();
cout<<"\n\n\n\tDELETE BOOK …";
cout<<"\n\nEnter The Book no. of the Book You Want To Delete : ";
cin>>n;
fp.open("bk.dat",ios::in|ios::out);
fstream fp2;
fp2.open("Temp.dat",ios::out);
fp.seekg(0,ios::beg);
while(fp.read((char*)&bk,sizeof(bk)))
{
if(strcmpi(bk.retbid(),n)!=0) //change later
{
fp2.write((char*)&bk,sizeof(bk));
}
}
fp2.close();
fp.close();
remove("bk.dat");
rename("Temp.dat","bk.dat");
cout<<"\n\n\tRecord Deleted ..";
getch();
}

void delete_member()
{
char n[6];
int flag=0;
clrscr();
cout<<"\n\n\n\tDELETE MEMBER…";
cout<<"\n\nEnter The member id. of the Member You Want To Delete : ";
cin>>n;
fp.open("mem.dat",ios::in|ios::out);
fstream fp2;
fp2.open("Temp.dat",ios::out);
fp.seekg(0,ios::beg);
while(fp.read((char*)&mem,sizeof(mem)))
{
if(strcmpi(mem.retmid(),n)!=0)
fp2.write((char*)&mem,sizeof(mem));
else
flag=1;
}
fp2.close();
fp.close();
remove("mem.dat");
rename("Temp.dat","mem.dat");
if(flag==1)
cout<<"\n\n\tRecord Deleted ..";
else
cout<<"\n\nRecord not found";
getch();
}
//***************************************************************
// function to display all Books list
//****************************************************************
void display_allb()
{
clrscr();
fp.open("bk.dat",ios::in);
if(!fp)
{
cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
getch();
return;
}
cout<<"\n\n\t\tBook LIST\n\n";
cout<<"=========================================================================\n";
cout<<"Book Id"<<setw(20)<<"Book Name"<<setw(25)<<"Author"<<setw(20)<<"Quantity\n";
cout<<"=========================================================================\n";
while(fp.read((char*)&bk,sizeof(bk)))
{
bk.report();
}
fp.close();
getch();
}

//***************************************************************
// function to display all students list
//****************************************************************
void display_allm()
{
clrscr();
fp.open("mem.dat",ios::in);
if(!fp)
{
cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
getch();
return;
}
cout<<"\n\n\t\tMEMBER LIST\n\n";
cout<<"==================================================================\n";
cout<<"\tMember Id."<<setw(10)<<"Name"<<setw(20)<<"Contact no"<<setw(20)<<"Add\n";
cout<<"==================================================================\n";
while(fp.read((char*)&mem,sizeof(mem)))
{
mem.report();
}
fp.close();
getch();
}

//***************************************************************
// ADMINISTRATOR MENU FUNCTION
//****************************************************************

void admin_menu()
{
for(;;)
{
clrscr();
int ch2;
cout<<"\n\n\n\tADMINISTRATOR MENU";
cout<<"\n\n\t1.CREATE BOOK ";
cout<<"\n\n\t2.DISPLAY ALL BOOKS ";
cout<<"\n\n\t3.DISPLAY SPECIFIC BOOK ";
cout<<"\n\n\t4.MODIFY BOOK ";
cout<<"\n\n\t5.DELETE BOOK ";
cout<<"\n\n\t6.CREATE MEMBER ";
cout<<"\n\n\t7.DISPLAY ALL MEMBERS ";
cout<<"\n\n\t8.DISPLAY SPECIFIC MEMBER RECORD ";
cout<<"\n\n\t9.MODIFY MEMBER RECORD ";
cout<<"\n\n\t10.DELETE MEMBER ";
cout<<"\n\n\t11.Exit";
cout<<"\n\n\tPlease Enter Your Choice (1-11) ";
cin>>ch2;
switch(ch2)
{

case 1:
{
clrscr();
write_book();
break;
}
case 2:
{
 display_allb();
 break;
}
case 3:
{
char num[6];
clrscr();
cout<<"\n\n\tPlease Enter The book No. ";
cin>>num;
display_spb(num);
break;
}
case 4:
{
 modify_book();
 break;
}
case 5:
{
 delete_book();
 break;
}
case 6:
{
clrscr();
write_member();
break;
}
case 7:
{
 display_allm();
 break;
}
case 8:
{
char num[6];
clrscr();
cout<<"\n\n\tPlease Enter The Member Id. ";
cin>>num;
display_spm(num);
break;
}
case 9:
{
 modify_member();
 break;
}
case 10:
{
 delete_member();
 break;
}
case 11:
{
 return;
}
default:
{
 cout<<"\a";
 break;
}
}//end of switch
}//end of loop
}

//***************************************************************
// INTRODUCTION FUNCTION
//****************************************************************

void intro()
{
clrscr();
gotoxy(36,8);
cout<<"LIBRARY";
gotoxy(35,11);
cout<<"MANAGEMENT";
gotoxy(36,14);
cout<<"SYSTEM";
cout<<"\n\n"<<setw(130)<<"MILAN MANDIR LIBRAY";
cout<<"\n\n\n"<<setw(130)<<"MADE BY : SHOUVICK PAUL";
getch();
}

/****************************************
			 Function for welcom
*****************************************/

void welcome()
{
cout<<"\n\n\t w	 w  e e e e e e   l ";
cout<<"\n\n\t w   w   w  e 		  l ";
cout<<"\n\n\t w  w w  w  e e e e e e   l ";
cout<<"\n\n\t w  w w  w  e e e e e e   l ";
cout<<"\n\n\t w w   w w  e 		  l ";
cout<<"\n\n\t  w     w   e e e e e e   l l l l l ";
cout<<endl;
cout<<"\n\n\t c c c c c  o o o o o  m       m  e e e e e   ";
cout<<"\n\n\t c	    o 	    o  m m   m m  e ";
cout<<"\n\n\t c 	    o 	    o  m  m m  m  e e e e e    ";
cout<<"\n\n\t c 	    o 	    o  m   m   m  e e e e e  ";
cout<<"\n\n\t c 	    o 	    o  m       m  e ";
cout<<"\n\n\t c c c c c  o o o o o  m       m  e e e e e    ";
getch();
clrscr();
}

/*int check_pass();
{
	int pwd;
	cout<<"Please Enter The Password"<<endl;
	cin>>pwd;
	if(pwd==2014)
} */

/*********************************************************
				  Main Function
********************************************************/

void main()
{
	char ch;
	int pwd;
	cout<<"Please Enter The Password"<<endl;
	cin>>pwd;
	if(pwd==2014)
	{
	welcome();
	intro();
	do
	{
		clrscr();
		cout<<"\n\n\n\tMAIN MENU";
		cout<<"\n\n\t01. BOOK ISSUE";
		cout<<"\n\n\t02. BOOK DEPOSIT";
		cout<<"\n\n\t03. ADMINISTRATOR MENU";
		cout<<"\n\n\t04. EXIT";
		cout<<"\n\n\tPlease Select Your Option (1-4) ";
		ch=getche();
		switch(ch)
		{
			case '1': clrscr();
			cout<<"\a";//book_issue();
			break;
			case '2': cout<<"\a";//book_deposit();
			break;
			case '3':admin_menu();
			break;
			case '4':exit(0);
			default :cout<<"\a";
		}
	}while(ch!='4');
	}
	else
	cout<<"login failed";
}
//***************************************************************
// END OF PROJECT
//***************************************************************


