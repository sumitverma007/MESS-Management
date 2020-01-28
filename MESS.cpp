/*
AUTHOR :SUMIT KUMAR VERMA(21) SHAILESH SHEKHAR(22)
  LATEST COMMIT: 29 JAN 2019 
*/
#include<bits/stdc++.h>
#include<fstream>
#include<stdlib.h>
#include<ctime>
using namespace std;
void menu_admin();
/*MESS CLASS DEC*/
class MESS{
     public:
  char fname[50]={};
  char lname[50]={};
  int scholar_no;
  float balance;
  int room_no;
  MESS(){};
  ~MESS(){};
        void set_record(std::string in1,std::string in2);
        void add_student();
        void disp_details();
        
        void disp_single_student();
        void take_attendance();

};
class menu_details
{
	 public:
	 	int day_id;
	 	char breakfast[50];
	 	char lunch[50];
	 	char snacks[50];
	 	char dinner[50];
	 	
	 	void set_menu();
	 	void see_menu();
};
void menu_details::set_menu()
{
	 ofstream outfile;
	 outfile.open("Menu_details.txt",ios::out);
	 menu_details test;
	
	 test.day_id=0;
	 strcpy(test.breakfast,"TEA,MILK,BANANA,SPROUT");
	 strcpy(test.lunch,"ROTI,RICE,SALAD,ACHAAR,GHEE");
	 strcpy(test.snacks,"TEA");
	 strcpy(test.dinner,"ROTI,RICE,ACHAAR,SALAD,DAL");
	 outfile.write((char *)&test,sizeof(test));
	 
	 //day1 mon
	  test.day_id=1;
	 strcpy(test.breakfast,"POHA,JALEBI");
	 strcpy(test.lunch,"RAJMA,RAITA");
	 strcpy(test.snacks,"PAKODA,CHUTNEY");
	 strcpy(test.dinner,"SEASONAL VEG,GHEE");
	 outfile.write((char *)&test,sizeof(test));
	 
	 //day 2 tue
	  test.day_id=2;
	 strcpy(test.breakfast,"PARATHA,ALOO SABJI");
	 strcpy(test.lunch,"SEASONAL VEG,DAHI");
	 strcpy(test.snacks,"MANCHURIAN RICE");
	 strcpy(test.dinner,"ALOO MATAR,PURI,KHEER");
	 outfile.write((char *)&test,sizeof(test));
	 
	 //day 3 wed
	  test.day_id=3;
	 strcpy(test.breakfast,"IDLI,SAMBHAR,CHUTNEY");
	 strcpy(test.lunch,"ALOO BAINGAN,RAITA");
	 strcpy(test.snacks,"MAGGI");
	 strcpy(test.dinner,"PANEER PARATHA");
	 outfile.write((char *)&test,sizeof(test));
	 
	 //day 4 thu
	  test.day_id=4;
	 strcpy(test.breakfast,"PAV BHAJI");
	 strcpy(test.lunch,"SOYABEAN,SEV TAMATAR");
	 strcpy(test.snacks,"SAMOSA,CHUTNEY");
	 strcpy(test.dinner,"MIX VEG,GHEE");
	 outfile.write((char *)&test,sizeof(test));
	 
	 //day 5 fri
	  test.day_id=5;
	 strcpy(test.breakfast,"METHI PURI,SABJI");
	 strcpy(test.lunch,"SEASONAL VEG,RAITA");
	 strcpy(test.snacks,"PATTIES");
	 strcpy(test.dinner,"EGG CURRY,KOFTA");
	 outfile.write((char *)&test,sizeof(test));
	 
	 //day 6 sat
	  test.day_id=6;
	 strcpy(test.breakfast,"DOSA,SAMBHAR,CHUTNEY");
	 strcpy(test.lunch,"DAL BAFLA,GULAB JAMUN");
	 strcpy(test.snacks,"MESS CLOSED");
	 strcpy(test.dinner,"MESS CLOSED");
	 outfile.write((char *)&test,sizeof(test));
	 
	 //day 7 sun
	  test.day_id=7;
	 strcpy(test.breakfast,"ALOO PARATHA,DAHI");
	 strcpy(test.lunch,"ALOO JEERA,KADHI");
	 strcpy(test.snacks,"BISCUITS");
	 strcpy(test.dinner,"CHICKEN,PANEER");
	 outfile.write((char *)&test,sizeof(test));
	 
}
void menu_details::see_menu()
{
	 system("cls");
	 menu_details test1,test2;
	 	vector<string> days={"DAILY","Monday","Tuesday","wednesday","Thrusday","Friday","Saturday","Sunday"};
	 	time_t now=time(0);

	 tm *itm=localtime(&now);
	 int id=itm->tm_wday;
	 ifstream infile;
	 infile.open("Menu_details.txt",ios::in);
	 infile.read((char *)&test1,sizeof(test1));
	 while(!infile.eof())
	 {
	 	 cout<<days[test1.day_id]<<" :: "<<test1.breakfast<<"       "<<test1.lunch<<"        "<<test1.snacks<<"       "<<test1.dinner<<"\n";
	 	 cout<<"-----------------------------------------------------------------------------------------------------------------------\n";
		  if(test1.day_id==id)
	 	 {
	 	 	 test2=test1;
		  }
		   infile.read((char *)&test1,sizeof(test1));
	 }
	 cout<<"\n\n--------------------------TODAY'S MENU-----------------------------------------------------------\n\n";
	 cout<<days[test2.day_id]<<" :: "<<test2.breakfast<<"   "<<test2.lunch<<"   "<<test2.snacks<<"   "<<test2.dinner;
	 cout<<"\n--------------------------------------------------------------------------------------------------\n";
	 system("pause");
}
void MESS::set_record(std::string in1,std::string in2)
{
      memset(fname,0,sizeof(fname));
      memset(lname,0,sizeof(lname));
      if(in1.size()<50)
      {
            memcpy(fname,in1.c_str(),in1.size());
      }
      else{
            memcpy(fname,in1.c_str(),sizeof(fname)-1);
      }

      if(in2.size()<50)
      {
            memcpy(lname,in2.c_str(),in2.size());
      }
      else{
            memcpy(lname,in2.c_str(),sizeof(lname)-1);
      }
}
void MESS::disp_single_student()
{  system("cls");
	 int r_no,flag=0;
	 cout<<"Enter Your Room Number ::";cin>>r_no;
	 ifstream infile;
	 infile.open("MESS.txt",ios::in);
	 MESS stu;
	 infile.read((char *)&stu,sizeof(stu));
	 while(!infile.eof())
	 {
	 	 if(stu.room_no==r_no)
	 	 {
	 	 	 flag=1;
	 	 	 cout<<"\n\nHello "<<stu.fname<<" "<<stu.lname;
	 	 	 cout<<"\nRoom Number::"<<stu.room_no;
	 	 	 cout<<"\nScholar Number::"<<stu.scholar_no;
	 	 	 cout<<"\n---------------------------------\n";
	 	 	 cout<<"Balance Left in your Account::"<<stu.balance;
	 	 	 cout<<"\n----------------------------------\n";
	 	 	 break;
		  }
		  infile.read((char *)&stu,sizeof(stu));
	 }
if(flag==0)
{
	 cout<<"\nSorry No Records found\n";
	 }	 
	 system("pause");
}
void MESS::add_student()
{
     system("cls");
     MESS stu;
     ofstream outfile;
     outfile.open("MESS.txt",ios::app);
     if(!outfile){
         cout<<"Error in opening File\n";
         exit(0);
     }
     string f_name,l_name;
     int s_no,r_no;
     float bal;
     cout<<"Enter Student's First name ::";cin>>f_name;
     cout<<"\nEnter Student's last name ::";cin>>l_name;
     cout<<"\nEnter Student's schlolar number ::";cin>>s_no;
     cout<<"\nEnter Student's Balance::";cin>>bal;
     cout<<"\nEnter Student's Room number::";cin>>r_no;
     stu.set_record(f_name,l_name);
     stu.scholar_no=s_no;
     stu.balance=bal;
     stu.room_no=r_no;
     outfile.write((char *)&stu,sizeof(stu));
     outfile.close();
     cout<<"\nRecords Added Successfully\n";
     system("pause");
     
}
void MESS::disp_details()
{
     system("cls");
     MESS stu;
     ifstream infile;
     infile.open("MESS.txt",ios::in);
     if(!infile)
     {
          cout<<"Error in opening file..Exiting....\n";
          exit(0);
     }
    infile.read((char *)&stu,sizeof(stu));
    while(!infile.eof())
    {
          cout<<"\n\nName::"<<stu.fname<<" "<<stu.lname;
          cout<<"\nScholar Number ::"<<stu.scholar_no;
          cout<<"\nRoom Number ::"<<stu.room_no;
          cout<<"\nBalance Left::"<<stu.balance;

          infile.read((char *)&stu,sizeof(stu));
    }
    cout<<"\n\n";
system("pause");

}
void MESS::take_attendance()
{
	system("cls");
int room;
cout<<"ENTER YOUR ROOM NUMBER ::";cin>>room;
MESS mess_obj;
ofstream fout("temp.txt",ios::out);
ifstream fin("MESS.txt",ios::in);
fin.read((char *)&mess_obj,sizeof(mess_obj));
while(!fin.eof())
{
	 if(room==mess_obj.room_no)
	 {
	 	 mess_obj.balance=mess_obj.balance-50;
	 }
	 fout.write((char *)&mess_obj,sizeof(mess_obj));
	 fin.read((char *)&mess_obj,sizeof(mess_obj));
	 }	 
	 fin.close();
	 fout.close();
	 remove("MESS.txt");
	 rename("temp.txt","MESS.txt");
}
int checkadmin()
{
	 system("cls");
	 string uname,pwd,name,pass;
	 ifstream infile;
	 infile.open("admin_details.txt",ios::in);
	 
	 infile>>name;
	 infile>>pass;
	 
	 cout<<"Enter Username::";cin>>uname;
	 cout<<"\nEnter Password::";cin>>pwd;
	 if(name==uname && pass==pwd)
	 { 
	    cout<<"Logged in successfully\n\n";
		system("pause");
	 	 return 1;
	 }
	 else{
	 	 cout<<"\nEither username or password is incorrect\n\n";
	 	 system("pause");
	 	 return 0;
	 }
	 return 0;
	 
	 
	 
}

void menu()
{
	 do{
	 
    system("cls");
    int choice;
     
     cout<<"**************************************************************************************\n";
     cout<<"\n\n";
     cout<<"        **     **  *******   ********    *******          ***    ***    *********     \n";
     cout<<"        **  *  **  *         *           *                ***    ***    **     **     \n";
     cout<<"        **     **  *****     ********    *******    ****  **********    *********     \n";
     cout<<"        **     **  *                *          *    ****  ***    ***           **     \n";
     cout<<"        **     **  ********  ********    *******          ***    ***    *********     ";
     cout<<"\n\n";
     cout<<"***************************************************************************************\n";
     cout<<"--------------------------CHOOSE ANY OPTION--------------------------------------------\n";
     cout<<"               1.ADMIN LOGIN\n";
     cout<<"               2.STUDENT DETAILS\n";
     cout<<"               3.TODAY'S MENU\n";
     cout<<"               4.EXIT\n\n";
     cout<<"ENTER ANY CHOICE::";
     cin>>choice;
     if(choice==1){
           //admin login section
           if(checkadmin()){
           	menu_admin();
		   }
     }
     else if(choice==2)
     {
            //student details option'
            MESS stu;
            stu.disp_single_student();
            
     }
     else if(choice==3)
     {
             //today's menu
             menu_details test;
             test.set_menu();
             test.see_menu();
     }
     else if(choice==4)
     {
          exit(0);
     }
     else{
          cout<<"INVALID CHOICE";
     }
 }while(true);
 }
     
void menu_admin()
{
	do{
	
	 MESS tempo;
	 system("cls");
	 int choice;
	 cout<<"-------------------------ADMIN AREA--------------------\n";
	 cout<<"\n\n                  1.ADD STUDENT\n";
	 cout<<"\n                  2.DISPLAY STUDENT DETAILS\n\n";
	 cout<<"                  3.TAKE ATTENDANCE\n";
	 cout<<"\n                  4.MAIN MENU\n";
	 cout<<"\n                  5.EXIT\n";
	 cout<<"--------------------------------------------------------\n";
	 cout<<"ENTER YOUR CHOICE::";cin>>choice;
	 cout<<"\n---------------------------------------------------------\n";
	 int num;
	 if(choice==1){
	 	 system("cls");
	 	 cout<<"Enter Number of student you want to add::";
	 	 cin>>num;
	 	 for(int i=0;i<num;i++)
	 	 {
	 	 	tempo.add_student(); 
		  }
	 }
	 else if(choice==2)
	 {
	 	system("cls");
	 	 tempo.disp_details();
	 }
	 else if(choice==3)
	 {
	 	 tempo.take_attendance();
	 }
	 else if(choice==4)
	 {
	 	 menu();
	 }
	 else if(choice==5)
	 {
	 	 exit(0);
	 }
	 else{
	 	 cout<<"\nInvalid Choice\n";
	 }
}while(true);
}





/*MAIN FUNCTION*/
int main()
{
     
 menu();
 return 0;

}
