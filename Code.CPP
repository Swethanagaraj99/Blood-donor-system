 #include<stdio.h>
 #include<conio.h>
 #include<process.h>
 #include<fstream>
 #include<iostream>
 #include<string.h>
 #include<ctype.h> 
 using namespace std;
struct otherinfo
 {
 char mobno[15]; 
 char bloodgroup[5];
 char status;
 };
 //name structure
 struct nameinfo
 {
 char fname[20];
 int age;
 }; 
// address structure
 struct address
 { 
 char city[35];
 char state[15];
 }
;
 //date structure
 struct dateinfo
 {
 int dd;
 int mm;
 int yy;
 };
 struct donardate
 {
 char donarreg[25];
 dateinfo dt;
 };
 //******************FUNCTION PROTOTYPE****************
 void intromain();
 int getdonarno();
 int checkpass();
 void donar_new_old();
 void admin_menu();
 void donar_menu();
 char *getreg();
 char *getpatno();
 void donar_report_menu();
 void display_bloodstock();
 void write_donars();
 void patients_menu();
 void write_donar_ALREDYREG(char rgno[15]);
 void displaydonarwithlist(char rgno[15]);
 void displaybloodgroupwise(char bgp[5]);
 void searchdonarcitywise(char city[15]);
 void display_bloodavailable(char blgrp[5]);
 int display_bloodavailable2(char blgrp[5]);
 void modify_donarinfo(char regno[5]);
 void patients_menu(char brg[5]);
 void write_bloodstock(char bldgr[5]);
 void decrease_bloodstock(char bldgr[5]);
 void patients_menu(char brg[5]);
 void displaypatientdetails(dateinfo bgp);
 void delete_donarinfo(char regno[5]);
 //******************FUNCTION PROTOTYPE****************
 //****************CREATE FUNTION TO DISPLAY LIST OF DONARS BLOOD DONATION 
void donarlist(donardate donardt,int y,int no)
 {
 int xx[3]={2,26,50};
 cout<<"||-"<<no<<". - "<<donardt.dt.dd<<"/"<<donardt.dt.mm<<"/"<<donardt.dt.yy<<"||\n"; 
}
 //blood stock class
 struct storeblood
 {
 char blno[10];
 char bloodgroup[5];
 int qty; 
};
 //FILE NAME bloodstock.dat
 void stockbloodonetime() 
{
 storeblood stockbl[8]={{"BL01","A+",1},{"BL02","A-",1},{"BL03","B+",1},{"BL04","B-",1},{"BL05","AB+",1},{"BL06","AB-",1}, {"BL07","O+",1},{"BL08","O-",1}}; 
ifstream objiff("bloodstock.dat",ios::binary);
 storeblood st;
 if(!objiff)
 {
 cout<<"File could not be open !! Press any Key...\n";
 getch();
 ofstream objoff("bloodstock.dat",ios::binary);
 intromain();
 for(int x=0;x<8;x++) 
{
 st=stockbl[x];
 objoff.write((char*)&st,sizeof(storeblood));
 } 
objoff.close();
 }
 cout<<"-------------BLOOD GROUP SYSTEM--------------------";
 objiff.close();
 }
 //***************donar's class**********************************
 class donar
 { 
int dono; 
char donar_regist[15];
 nameinfo nm;
 address add;
 dateinfo date1;
 otherinfo other;
 
 public: 
donar() 
{
 dono=0; 
};
 //*********set all the variables
 void setfullname(nameinfo n)
 {
 strcpy(nm.fname,n.fname);
 }
 void setage(int ag)
 {
 nm.age=ag; 
}
 void setaddress(address ad1)
 {
strcpy(add.city,ad1.city);
 strcpy(add.state,ad1.state);
 }
 void setmobileno(char mb[15])
 {
 strcpy(other.mobno,mb);
 }
void setblodgrp(char bg[5])
 {
 strcpy(other.bloodgroup,bg);
 }
 //*********set all the variables
 char *getdonarreg()
 {
 return donar_regist;
 }
 dateinfo getdate() 
{
 return date1;
 }
 char *getbloodname()
 {
 return other.bloodgroup;
 }
 //input fuction for donar information 
void create_donar(int dn1) 
{
 cout<<"\n DONAR NO:"; 
dono=dn1;
 cout<<dono;
 fflush(stdin);
 cout<<"\n DONAR/'S REGISTRATION:";
 cin>>donar_regist;
 fflush(stdin);
 cout<<"\n FIRST NAME:";
 cin>>nm.fname;
 fflush(stdin); 
 cout<<"\n AGE:";
 cin>>nm.age;
 fflush(stdin);
 cout<<"\n city:"; 
 cin>>add.city;
 fflush(stdin);
 cout<<"\n STATE:"; 
 cin>>add.state;
 fflush(stdin);
 cout<<"\n----DATE OF BLOOD DONATION----\n";
 cout<<"\n DATE(dd/mm/yyyy):";
 cin>>date1.dd;
 fflush(stdin);
 cout<<"/";
 cin>>date1.mm;
 fflush(stdin);
 cout<<"/";
 cin>>date1.yy;
fflush(stdin);
 cout<<"\n MOBILE NO:"; 
  cin>>other.mobno;
  fflush(stdin);
 cout<<"\n BLOOD GROUP:";
 cin>>other.bloodgroup;
 fflush(stdin);
  other.status='Y';
  }
 //input fuction for donar information 
//****************display donars information in a box
 void display_donar_rectangle()
 {
 cout<<"\n DONAR REG-->"<<donar_regist;
 cout<<"\n";
 cout<<"NAME-->"<<nm.fname;
 cout<<"\n";
 cout<<"AGE-->"<<nm.age;
cout<<"\n";
 cout<<"ADDRESS-->"<<add.city<<","<<add.state ;
 cout<<"\n";
 cout<<"MOBILE NO-->>"<<other.mobno;
 cout<<"\n";
 cout<<"BLOOD GROUP-->"<<other.bloodgroup;
 cout<<"\n";
}
 //****************show all donars with blood groups row wise
 void showalldonarsrowwise() 
{  
cout<<donar_regist<<"-----"<<nm.fname<<"------" <<nm.age <<"------"<<add.city<<","<<add.state<<"------"<<other.mobno<<"------"<<other.bloodgroup<<endl;
 }
 //****************show all donars with blood groups row wise
 int getdono() 
{ 
return dono;
 }
 char *getfname()
 {
 return nm.fname;
 }
 char *getgroup()
 {
 return other.bloodgroup; 
}
 char *getcity()
 {
 return add.city;
 }
 char getstatus()
 {
 return other.status;
 }
 };
 //***************donar's class**********************************
 //************** 
//***************patient's class********************************** 
class patient
 {
 char pno[15];
 nameinfo pnm;
 address padd;
 otherinfo pother;
 int no_of_bottle;
 dateinfo pdate1;
 public: 
//****************show all donars with blood groups row wise 
void showallpatientsrowwise()
 {
cout<<pno  <<pnm.fname<<"--"<<pnm.age   <<padd.city<<","<<padd.state   <<pother.mobno   <<pother.bloodgroup<<endl;
 }
 //****************show all donars with blood groups row wise
 //input fuction for patients information 
void create_patient(char bloodgr[5])
 {
 
 cout<<"\t====================PATIENT'S INFORMATION=============================="; 
 cout<<"\n PAT.NO:";
 cin>>pno;
 fflush(stdin);
 cout<<"\n FIRST NAME:";
 cin>>pnm.fname;
 fflush(stdin); 
 cout<<"\n AGE:";
 cin>>pnm.age; 
 fflush(stdin);
 cout<<"\n ADDRESS:"; 
 cin>>padd.city;
 fflush(stdin);
 cout<<"\n STATE:";
 cin>>padd.state;
 fflush(stdin);
cout<<"\n ----DATE OF BLOOD GIVEN TO PATIENT----";
 cout<<"\n DATE(dd/mm/yyyy):";
 cin>>pdate1.dd;
 fflush(stdin);
cout<<"/";
 cin>>pdate1.mm; 
 fflush(stdin);
 cout<<"/";
 cin>>pdate1.yy;
 fflush(stdin);
 cout<<"\n MOBILE NO:";
 cin>>pother.mobno;
 fflush(stdin);
 no_of_bottle=1;
 strcpy(pother.bloodgroup,bloodgr);;
 pother.status='Y';
 } 
//input fuction for patients information 
char *getpno()
 {
 return pno;
 }
 dateinfo getdate()
 {
 return pdate1;
 }
 int pdd()
 {
 return pdate1.dd;
 }
 int pmm() 
{
 return pdate1.mm;
 }
 int pyy() 
{
 return pdate1.yy; 
}
 char getstatus()
 {
 return pother.status;
 } };
 //***************patient's class********************************** 
//***************blood storage class********************************** 
class bloodstore 
{
 int blstno;
 char bloodgroup[5]; 
int qty;
 char status;
 public: 
void add_bloodstore(int blno,char blgr[5],int qtty)
 { 
blstno=blno;
 strcpy(bloodgroup,blgr);
 qty=qtty;
 status='Y';
 }
 void setbloodqty()
 {
 qty=qty+1;
 }
 int getblstno()
 {
 return blstno;
 }
 int getqty() 
{
 return qty;
 }
 char getstatus()
 {
 return status;
 }
 char *getbloodgroup()
 {
 return bloodgroup;
 } };
 //***************blood storage class********************************** //***************************************************************
 // THE MAIN FUNCTION OF PROGRAM 
//**************************************************************** 
int main()
 {
 char ch;
 if(checkpass()==0)
 {
 do 
{ 
//****************TEMPORARY***********************
cout<<"n\n";
intromain(); 
 cout<<"\t=================MAIN MENU====================\n";
 cout<<"\t 01. ADMINISTRATOR\n";
 cout<<"\t 02. EXIT\n"; 
 cout<<"\t Please Select Your Option (1-3) :";
ch=getche();
 switch(ch)
 {
 case '1':
 admin_menu(); 
break;
 case '2':
exit(0);
 default :cout<<"a";
 }
 }
while(ch!='3');
 }
else
 {
 exit(0);
 }
 }
 //*************************************************************** 
// THE MAIN FUNCTION OF PROGRAM 
//**************************************************************** 
//***************main intro 
void intromain()
 {
cout<<"\t **************BLOOD DONAR SYSTEM************\n"; 
 }
 //******************************login name and password**************** 
int checkpass() 
{
 char nm[20];
 char pass[10];
 intromain();
 cout<<"\n PLEASE ENTER THE USER NAME:";
 cin>>nm; 
 cout<<"\n PLEASE ENTER THE PASSWORD:"; 
 pass[0]=getch();
 cout<<"*";
 pass[1]=getch();
 cout<<"*";
 pass[2]=getch();
 cout<<"*";
 pass[3]=getch();
 cout<<"*";
 pass[4]=getch();
 cout<<"*";
 pass[5]='\0';
 getch();
if(strcmp(nm,"admin")==0 && strcmp(pass,"blood")==0)
 {
 return 0; 
}
else 
{ 
return 1; 
} 
} 

void admin_menu() 
{ 
 char ch2;
 cout<<"\n\n";
 cout<<"\t=================ADMIN MENU====================\n";
 cout<<"\t 1.DONAR INFORMATION\n";
 //cout<<"\t 2.BLOOD TO PATIENTS INFORMATION\n"; 
 cout<<"\t 2.REPORTS\n";
 cout<<"\t 3.BACK TO MAIN MENU\n";
 cout<<"\t Please Enter Your Choice (1-3):";
 ch2=getche();
 switch(ch2) 
{
 case '1':
 donar_menu(); 
break; 
/*case '2':
 //*****************search for blood 
char bldgroup[15];
 cout<<"\n ENTER THE BLOOD GROUP(QTY) TO BE SEARCHED(WITH COMPATIBILITY):";
 cin>>bldgroup;
 if(display_bloodavailable2(bldgroup)==0)
 {
 patients_menu(bldgroup);
 }
else 
{
 cout<<"\n\t SORRY BLOOD NOT IN STOCK \n";
 } 
break; 
*/
case '2':
 donar_report_menu();
 break; 
default: cout<<"a";
 }
 }
 
 
 // DONARS INFORMATION ADD / MODIFY / DELETE
void donar_menu()
 {
 char ch2;
 char regno[5]; 
 cout<<"\n";
 cout<<"\t=================DONAR'S MENU====================\n";
 cout<<"\t 1.ADD DONAR INFORMATION\n";
 cout<<"\t 2.MODIFY DONAR INFORMATION\n";
 cout<<"\t 3.DELETE DONAR INFORMATION\n";
 cout<<"\t 4.BACK TO MAIN MENU\n"; 
 cout<<"\t Please Enter Your Choice (1-4) :";
 ch2=getche();
 switch(ch2)
 {
 case '1':
 donar_new_old();
 break;
 case '2':
 cout<<"\n";
 cout<<"\n ENTER THE REG. NO. OF DONAR TO BE SEARCHED:";
 cin>>regno; 
modify_donarinfo(regno); 
break; 
case '3':
 intromain(); 
 cout<<"\n ENTER THE REG. NO. OF DONAR TO BE SEARCHED AND DELETE:";
 cin>>regno; 
delete_donarinfo(regno);
 break; 
case '4':
admin_menu();
 }
 }


 //*************donars registration or already registered 
void donar_new_old()
 {
 char ch2;
 char regno[15]; 
 cout<<"\n";
 cout<<"\t=================DONAR'S MENU====================\n";
 cout<<"\t 1.NEW DONAR REGISTRATION\n";
 cout<<"\t 2.ALREADY REGISTERED\n";
 cout<<"\t 3.BACK TO MAIN MENU\n";
 cout<<"\t Please Enter Your Choice (1-4):";
 ch2=getche();
 switch(ch2)
 {
 case '1':
 write_donars();
 break; 
case '2': 
 intromain();
 cout<<"\t =========ALREADY REGISTERED=========\n";
 cout<<"\n ENTER THE DONARS REGISTERED NO:";
 cin>>regno; 
write_donar_ALREDYREG(regno);
 break;
 case '3':
 	donar_menu();
 }
 }
 
void donar_report_menu() 
{
 char ch2;
 char regno[15];
 char bldgroup[5],cty[35];
 dateinfo dtvalue2;
 cout<<"\n";
 intromain();
 cout<<"\t=================REPORTS====================\n";
 cout<<"\t 1.ALL DONAR INFORMATION BLOOD GROUP WISE\n";
 cout<<"\t 2.ALL DONAR INFORMATION CITY WISE\n";
 //cout<<"\t 3.ALL BLOOD GROUP WITH AVAILABILITY\n"; 
 cout<<"\t 3.DISPLAY DONAR INFORMATION WITH DATE OF DONATIONS\n";
//cout<<"\t 5.DISPLAY PATIENTS INFORMATION WITH BLOOD INFO. DATE WISE\n";
//cout<<"\t 6.DISPLAY BLOOD GROUP WITH QUANTITY\n"; 
 cout<<"\t 4.BACK TO MAIN MENU\n";
 cout<<"\n Please Enter Your Choice (1-4): ";
ch2=getche();
 switch(ch2)
 {
 case '1':
 cout<<"\n ENTER THE BLOOD GROUP TO BE SEARCHED(WITH COMPATIBILITY):";
 cin>>bldgroup; 
displaybloodgroupwise(bldgroup);
 break; 
case '2': 
 cout<<"\n ENTER THE CITY WISE SEARCH OF DONARS:";
 cin>>cty; 
searchdonarcitywise(cty);
 break;
 /*case '3':
 display_bloodstock(); 
  break;
  */
 case '3':
 cout<<"\n ENTER THE REG. NO. OF DONAR TO BE SEARCHED:";
 cin>>regno;
 displaydonarwithlist(regno);
 break; 
/*case '5': 
cout<<"\n ENTER THE DATE OF BLOOD GIVEN TO PATIENTS:"; 
cout<<"\n DATE(dd/mm/yyyy):";
 cin>>dtvalue2.dd; 
 cout<<"/"; 
 cin>>dtvalue2.mm;
 cout<<"/"; 
 cin>>dtvalue2.yy;
 displaypatientdetails(dtvalue2);
 break;
/* case '6': 
 cout<<"\n ENTER THE BLOOD GROUP(QTY) TO BE SEARCHED(WITH COMPATIBILITY):";
 cin>>bldgroup;
 display_bloodavailable(bldgroup);
 break;
 */
case '4':
donar_new_old();
}
 }


 //*****************add new registered donars information
 void write_donars()
 {
 ofstream objoff;
 donar donarobj;
 donardate donalist;
objoff.open("donars.dat",ios::binary|ios::app); 
ofstream objofflist("donarlist.dat",ios::binary|ios::app); 
 int rnn=getdonarno();
 char getprv_regno[15];
 strcpy(getprv_regno,getreg());
 if(strcmp(getprv_regno,"NULL")!=0)
 {
 cout<<"\n Previous REGNO: "<<getprv_regno;
 }
 if(rnn>10000) 
{
 rnn=1;
 }
 donarobj.create_donar(rnn); 
objoff.write((char*)&donarobj,sizeof(donarobj));
 //************write to donar list also
 strcpy(donalist.donarreg,donarobj.getdonarreg());
 donalist.dt=donarobj.getdate();
 objofflist.write((char*)&donalist,sizeof(donalist));
 objoff.close(); 
objofflist.close();
cout<<"\n ***************DONARS RECORD SAVED******************* \n";
 //********send the blood group to the bloodstock file
 write_bloodstock(donarobj.getbloodname());
 //************************************************ 
cin.ignore();
 getch();
 }
 //*****************add new registered donars information 


//************get thje donars last number****************
 char *getreg()
 {
 ifstream objiff;
 donar st; 
int count=0;
 char tmpregno[15];
 objiff.open("donars.dat",ios::binary);
 objiff.seekg(0,ios::beg); 
if(!objiff)
 {
 getch(); 
}
 //**************temporary hiding these lines 
while(objiff.read((char *) &st, sizeof(donar)))
 {
 count++; 
}
 //***********jump to the last line
 objiff.seekg(count-sizeof(st),ios::beg);
 objiff.read((char *) &st, sizeof(donar));
 strcpy(tmpregno,st.getdonarreg());
 objiff.close();
 if(count!=0)
 return tmpregno; 
else 
return "NULL";
 }
 //************get thje donars last number**************** 
//******************all the donars fuction details**************************** 


//******************generate the number
 int getdonarno() 
{ 
ifstream objiff;
 donar st;
 int count=0; 
objiff.open("donars.dat",ios::binary);
 objiff.seekg(0,ios::beg); 
if(!objiff)
 {
 getch();
 }
 //**************temporary hiding these lines
 while(objiff.read((char *) &st, sizeof(donar)))
 {
 count++;
 }
 //***********jump to the last line
 objiff.seekg(count-sizeof(st),ios::beg);
 objiff.read((char *) &st, sizeof(donar));
 count=st.getdono();
 count++;
 objiff.close();
 return count;
 }
 //****************generate the donars number

 //**************write the donars dates who is already registered 
void write_donar_ALREDYREG(char rgno[15])
 {
 /* 
 struct donardate
 { 
char donarreg[25]; 
dateinfo dt;
 };
 */
 dateinfo date1;
 donar dr;
 int flag=0;
 donardate donalist;
 ifstream fp;
 fp.open("donars.dat",ios::binary);
 ofstream objoff("donarlist.dat",ios::binary|ios::app);
 if(!fp)
 {
 getch(); 
return;
 }
 while(fp.read((char*)&dr,sizeof(donar))) 
{ 
if(strcmp(dr.getdonarreg(),rgno)==0) 
{
 dr.display_donar_rectangle();
 flag=1; 
strcpy(donalist.donarreg,dr.getdonarreg());
 }
 }
 fp.close();
 if(flag==0)
 {
cout<<" Donar record does not exist\n";
 getch();
 }
else 
{ 
cout<<"\n ENTER THE DATE OF BLOOD DOATION:";
 cout<<"\n DATE(dd/mm/yyyy):";
 cin>>date1.dd;
 cout<<"/";
 cin>>date1.mm; 
 cout<<"/"; 
 cin>>date1.yy;
 donalist.dt.dd=date1.dd; 
donalist.dt.mm=date1.mm; 
donalist.dt.yy=date1.yy;
 objoff.write((char*)&donalist,sizeof(donalist));
 objoff.close();
 //********send the blood group to the bloodstock file 
write_bloodstock(dr.getbloodname());
 //************************************************ 
}
 }
 //**************write the donars dates who is already registered 
  
  
  //**********donar name and list of blood donation
 void displaydonarwithlist(char rgno[15])
 {
 ifstream fp; fp.open("donars.dat",ios::binary);
 ifstream objiff("donarlist.dat",ios::binary);
 donardate donalist;
 donar dr;
 int flag=-1;
 if(!fp) 
{
 getch();
 return;
 }
 while(fp.read((char*)&dr,sizeof(donar)))
 {
 if(strcmp(dr.getdonarreg(),rgno)==0) 
{ 
dr.display_donar_rectangle();
 flag=1;
 strcpy(donalist.donarreg,dr.getdonarreg());
 }
 }
 fp.close();
 if(flag==1) 
{ 
 cout<<"\n ----------LIST OF BLOOD DONATED BY DONAR-------------";
 int no1=1; 
int y1=0;
 while(objiff.read((char*)&donalist,sizeof(donardate)))
 { 
if(strcmp(rgno,donalist.donarreg)==0) 
{
 if(y1<=2)
 {
 donarlist(donalist,y1,no1);
 y1++;
 no1++;
 }
else
{
 y1=0;
 no1++; 
}
 }
 }
 }
 objiff.close();
 getch();
 }
 //**********donar name and list of blood donation
 
 
 //************blood stock list
 void display_bloodstock() 
{ 
ifstream objiff("bloodstock.dat",ios::binary);
 storeblood blstk;
 if(!objiff)
 {
 getch();
 return; 
} 
cout<<"\n";
 cout<<" BLOODNO : "<<"BLOOD GROUP : "<<"QUANTITY :";
while(objiff.read((char*)&blstk,sizeof(blstk)))
 { 
 cout<<blstk.blno<<"-"<< blstk.bloodgroup<<"-"<<blstk.qty;
 }
 objiff.close();
 getch();
 }
 //************blood stock list 



//*******************display blood group wise with compatibility
 void displaybloodgroupwise(char bgp[5]) 
{ 
ifstream fp;
 fp.open("donars.dat",ios::binary);
 donar dr;
 if(!fp)
 {
 getch();
 return;
 }
 cout<<"\n REG No:"<<"NAME OF DONAR:"<<"AGE:"<<"--ADDRESS--:"<<" MOBILE NO:"<<"BLOOD GROUP:\n";
  cout<<"\n";
 while(fp.read((char*)&dr,sizeof(donar)))
 {
 if(strcmp(dr.getbloodname(),bgp)==0)
{
 dr.showalldonarsrowwise();
 }
 }
 fp.close();
 fp.open("donars.dat",ios::binary);
 cout<<"=======================================\n";
 cout<<"=======OTHER COMPATIBLE BLOOD GROUPS==================\n";
 //-------for A+ 
if(strcmp(bgp,"A+")==0) 
{
 while(fp.read((char*)&dr,sizeof(donar))) 
{
 if(strcmp(dr.getbloodname(),"A-")==0 ||strcmp(dr.getbloodname(),"O-")==0 || strcmp(dr.getbloodname(),"O+")==0) 
{
 dr.showalldonarsrowwise();
 }
 }
 }
 ///for A- 
else if(strcmp(bgp,"A-")==0 ) 
{ 
while(fp.read((char*)&dr,sizeof(donar)))
 {
 if(strcmp(dr.getbloodname(),"O-")==0)
 {
 dr.showalldonarsrowwise();
 }
 }
 }
 //for B+ 
else if(strcmp(bgp,"B+")==0) 
{
 while(fp.read((char*)&dr,sizeof(donar)))
 {
 if(strcmp(dr.getbloodname(),"B-")==0 ||strcmp(dr.getbloodname(),"O-")==0 || strcmp(dr.getbloodname(),"O+")==0) 
{
 dr.showalldonarsrowwise();
 }
 }
 }
 //**for B-
 else if(strcmp(bgp,"B-")==0) 
{
 while(fp.read((char*)&dr,sizeof(donar)))
 {
 if(strcmp(dr.getbloodname(),"B-")==0 ||strcmp(dr.getbloodname(),"O-")==0) 
{ 
dr.showalldonarsrowwise();
 }
 }
 }
 //**for AB+
 else if(strcmp(bgp,"AB+")==0)
{
 while(fp.read((char*)&dr,sizeof(donar)))
 {
 if(strcmp(dr.getbloodname(),"A+")==0 || strcmp(dr.getbloodname(),"A-")==0 || strcmp(dr.getbloodname(),"B+")==0 || strcmp(dr.getbloodname(),"B-")==0 || strcmp(dr.getbloodname(),"O+")==0 || strcmp(dr.getbloodname(),"O-")==0 || strcmp(dr.getbloodname(),"AB-")==0) 
{
 dr.showalldonarsrowwise();
 }
 }
 }
 //**for AB-
 else if(strcmp(bgp,"AB-")==0)
 {
 while(fp.read((char*)&dr,sizeof(donar)))
 {
 if(strcmp(dr.getbloodname(),"O-")==0 ||strcmp(dr.getbloodname(),"A-")==0 ||strcmp(dr.getbloodname(),"B-")==0 || strcmp(dr.getbloodname(),"AB-")==0) 
{ 
dr.showalldonarsrowwise(); 
 }
 }
 }
 //**for O+ 
else if(strcmp(bgp,"O+")==0) 
{ 
while(fp.read((char*)&dr,sizeof(donar)))
 {
 if(strcmp(dr.getbloodname(),"O-")==0) 
{ 
dr.showalldonarsrowwise();
 }
 }
 }
 //**for O- 
else if(strcmp(bgp,"O-")==0) 
{
	cout<<"\n";
 cout<<"*****************ONLY O - *************************\n";
 }
 //**************************ends here************************
 fp.close();
 getch();
 }
 //*******************display blood group wise with compatibility


 //***************donars information city wise 
void searchdonarcitywise(char city[15]) 
{
 ifstream fp;
 fp.open("donars.dat",ios::binary);
 donar dr;
 if(!fp)
 {
 getch();
 return;
 }
cout<<"\n REG No:"<<"NAME OF DONAR:"<<" AGE:"<<"--- ADDRESS--:"<<"MOBILE NO--"<<"BLOOD GROUP:\n";
 while(fp.read((char*)&dr,sizeof(donar)))
 {
 if(strcmp(dr.getcity(),city)==0) 
{ 
dr.showalldonarsrowwise();
 }
 }
 fp.close();
 getch();
 }
 //***************donars information city wise 



//**************search and display the avaliblity of blood 
void display_bloodavailable(char blgrp[5]) 
{
 ifstream objiff("bloodstock.dat",ios::binary); 
storeblood blstk;
 if(!objiff)
 { 
getch();
 return;
 } 
 cout<<"\n";
 cout<<" BLOODNO:"<<"BLOOD GROUP:"<<"QUANTITY:\n";
 while(objiff.read((char*)&blstk,sizeof(blstk))) 
{
 if( strcmp(blstk.bloodgroup,blgrp)==0) 
{
 cout<<blstk.blno<<"-"<<blstk.bloodgroup<<"-"<<blstk.qty; 
} 
} 
objiff.close();
 //*******************main ends here 
ifstream fp;
 fp.open("bloodstock.dat",ios::binary);
 storeblood dr;
 cout<<"=================================================\n";
 cout<<"==============OTHER COMPATIBLE BLOOD GROUPS==============\n";
 //-------for A+ 
if(strcmp(blgrp,"A+")==0)
 {
 while(fp.read((char*)&dr,sizeof(storeblood)))
 {
 if(strcmp(dr.bloodgroup,"A-")==0 ||strcmp(dr.bloodgroup,"O-")==0 || strcmp(dr.bloodgroup,"O+")==0)
 {
 cout<<dr.blno<<"-"<<dr.bloodgroup<<"-"<<dr.qty;
 }
 }
 }
 ///for A- 
else if(strcmp(blgrp,"A-")==0 ) 
{
 while(fp.read((char*)&dr,sizeof(storeblood)))
 {
 if(strcmp(dr.bloodgroup,"O-")==0)
 {
 cout<<dr.blno<<"-"<<dr.bloodgroup<<"-"<<dr.qty;
 }
 }
 }
 //for B+ 
else if(strcmp(blgrp,"B+")==0)
 {
 while(fp.read((char*)&dr,sizeof(storeblood))) 
{
 if(strcmp(dr.bloodgroup,"B-")==0 ||strcmp(dr.bloodgroup,"O-")==0 || strcmp(dr.bloodgroup,"O+")==0)
 { 
 cout<<dr.blno<<"-"<<dr.bloodgroup<<"-"<<dr.qty;
 }
 }
 }
 //**for B- 
else if(strcmp(blgrp,"B-")==0) 
{
 while(fp.read((char*)&dr,sizeof(storeblood))) 
{ 
if(strcmp(dr.bloodgroup,"B-")==0 ||strcmp(dr.bloodgroup,"O-")==0) 
{
  cout<<dr.blno<<"-"<<dr.bloodgroup<<"-"<<dr.qty;
}
 }
 }
 //**for AB+
 else if(strcmp(blgrp,"AB+")==0) 
{
 while(fp.read((char*)&dr,sizeof(storeblood)))
 {
 if(strcmp(dr.bloodgroup,"A+")==0 || strcmp(dr.bloodgroup,"A-")==0 || strcmp(dr.bloodgroup,"B+")==0 || strcmp(dr.bloodgroup,"B-")==0 || strcmp(dr.bloodgroup,"O+")==0 || strcmp(dr.bloodgroup,"O-")==0 || strcmp(dr.bloodgroup,"AB-")==0) 
{ 
 cout<<dr.blno<<"-"<<dr.bloodgroup<<"-"<<dr.qty;
 }
 }
 }
 //**for AB-
 else if(strcmp(blgrp,"AB-")==0)
 { while(fp.read((char*)&dr,sizeof(storeblood))) 
{ 
if(strcmp(dr.bloodgroup,"O-")==0 ||strcmp(dr.bloodgroup,"A-")==0 ||strcmp(dr.bloodgroup,"B-")==0 ||strcmp(dr.bloodgroup,"AB-")==0) 
{
 cout<<dr.blno<<"-"<<dr.bloodgroup<<"-"<<dr.qty;
 }
 }
 }
 //**for O+ else 
 if(strcmp(blgrp,"O+")==0) 
{ 
while(fp.read((char*)&dr,sizeof(storeblood)))
 {
 if(strcmp(dr.bloodgroup,"O-")==0) 
{
  cout<<dr.blno<<"-"<<dr.bloodgroup<<"-"<<dr.qty;
}
 }
 }
 //**for O- 
else if(strcmp(blgrp,"O-")==0) 
{ 
cout<<"\n";
 cout<<"**********ONLY O - ********\n";
 }
 //**************************ends here************************ 
fp.close();
 getch();
 //******************compatibility ends here
 }
 //**************search and display the avaliblity of blood




 //***************delete donars information 
void delete_donarinfo(char regno[5])
 {
 ifstream fp; 
 donar dr;
 int flag=0;
 fp.open("donars.dat",ios::binary);
 if(!fp) 
{ 
 getch();
 return; 
}
 while(fp.read((char*)&dr,sizeof(donar))) 
{
 if(strcmp(dr.getdonarreg(),regno)==0)
 {
 flag=1;
 break; 
} 
}
 char ch;
 if(flag==0) 
{ cout<<"donar record not exist\n";
 fp.close();
 }
else
 {
 // fp.seekp(fpos-sizeof(donar),ios::beg);
 dr.display_donar_rectangle(); 
fp.close();
 //*******deletion of the records starts from here gotoxy(1,15); 
cout<<"\n\n"; 
 cout<<"\n ======DO YOU WANT TO DELETE THE RECORDS GIVEN ABOVE[YES(Y) OR NO (N)]========\n";
 cin>>ch;
 if (toupper(ch)=='Y') 
{ 
ofstream outFile;
 outFile.open("Temp1.dat",ios::binary);
 ifstream objiff("donars.dat",ios::binary);
 objiff.seekg(0,ios::beg);
 while(objiff.read((char *) &dr, sizeof(donar))) 
{
 if(strcmp(dr.getdonarreg(),regno)!=0) 
{
 outFile.write((char *) &dr, sizeof(donar));
 }
 }
 outFile.close();
 objiff.close();
 remove("donars.dat"); 
rename("Temp1.dat","donars.dat");
 //againopenandclose();
  cout<<"\n ----------------------Record Deleted---------------------------\n"; 
getch();
 }
 }
 //***********************delete record ends************************************ 
}
 //***************delete donars information 



//****************modification of donar information 
void modify_donarinfo(char regno[5])
 {
 char ch2;
 fstream fp; 
fp.open("donars.dat",ios::binary|ios::in|ios::out); 
//donardate donalist;
 donar dr;
 nameinfo nminfo;
 address ad1;
 char mb[15],eid[75],bg[5];
 int fpos=-1,ag=0;
 int flag=-1,flagblood=-1;
 if(!fp) 
{
 getch();
 return;
 }
 while(fp.read((char*)&dr,sizeof(donar)))
 {
 if(strcmp(dr.getdonarreg(),regno)==0)
 {
 flag=1;
 fpos=(int)fp.tellg();
 break; 
} }
 // fp.close();
 if(flag==1) 
{
 fp.seekp(fpos-sizeof(donar),ios::beg);
 dr.display_donar_rectangle(); 
 cout<<"\t==========DONAR'S MODIFICATION MENU====================\n"; 
 cout<<"\t 1.MODIFY NAME\n";
 cout<<"\t 2.MODIFY AGE\n";
 cout<<"\t 3.MODIFY ADDRESS\n";
cout<<"\t 4.MODIFY MOBILE NO.\n";
 cout<<"\t 5.MODIFY BLOOD GROUP\n"; 
  cout<<"6.BACK TO MAIN MENU";
 cout<<"\t Please Enter Your Choice (1-5) :ad";
 //**********************************************************
 ch2=getche();
 dr.display_donar_rectangle();
 switch(ch2) 
{ 
case '1': 
 cout<<"\n ENTER THE FIRST NAME TO MODIFY:\n ";
cin>>nminfo.fname;
 dr.setfullname(nminfo); 
 break; 
case '2':
 cout<<"\n ENTER THE AGE TO MODIFY: ";
cin>>ag; 
dr.setage(ag);
 break;
 case '3':
 cout<<"\n ENTER THE CITY TO MODIFY: ";
cin>>ad1.city;
 cout<<"\n ENTER THE STATE TO MODIFY: ";
cin>>ad1.state;
 dr.setaddress(ad1); 
break;
 case '4': 
cout<<"\n ENTER THE MOBILE TO MODIFY: ";
cin>>mb;
 dr.setmobileno(mb);
 break; 
 case '5':
 cout<<"\n ENTER THE BLOOD GROUP TO MODIFY: ";
 cin>>bg;
 dr.setblodgrp(bg);
 flagblood=1;
 break;
 case '6':
 donar_menu();
  }
   fp.write((char *) &dr, sizeof(donar));
    }
     fp.close();
       if(flagblood==1)
   {
  cout<<" \n new blood::"<<bg;
  write_bloodstock(bg);
  decrease_bloodstock(dr.getbloodname());
  flagblood=-1;
   }
    cout<<"\n *****************modified the record******************\n";
    getch();
     }
     
	 
	 
	  //****************increase the blood qty by 1
      void write_bloodstock(char bldgr[5])
      {
       int fpos=-1;
       fstream File;
       storeblood st,tmp;
  File.open("bloodstock.dat",ios::binary|ios::in|ios::out);
   if(!File)
    {
     getch();
      return;
       }
	while(File)
	 {
	  File.read((char *) &st, sizeof(storeblood));
  if(strcmp(st.bloodgroup,bldgr)==0)
   {
    fpos=(int)File.tellg();
     break;
      }
       }
 File.seekp(fpos-sizeof(storeblood));
  tmp=st;
   tmp.qty=tmp.qty+1;
    File.write((char *) &tmp, sizeof(storeblood));
     File.close();
      }
       //**********************************************

//****************increase the blood qty by 1
void decrease_bloodstock(char bldgr[5])
 {
  int fpos=-1;
   fstream File;
    storeblood st,tmp;
     File.open("bloodstock.dat",ios::binary|ios::in|ios::out);
      if(!File)
       {
      getch();
       return;
	}
	 while(File.read((char *) &st, sizeof(storeblood)))
	  {
	   if(strcmp(st.bloodgroup,bldgr)==0)
	   {
    fpos=(int)File.tellg();
    break;
    }
    }
   File.seekp(fpos-sizeof(storeblood),ios::beg);
  tmp=st; tmp.qty=tmp.qty-1; File.write((char *) &tmp, sizeof(storeblood));
   File.close();
    } 
	//************************************************************************ 
	//*************function to search for blood and compatibility and return true 

	int display_bloodavailable2(char blgrp[5]) 
	{ 
	int returnvalue=-1;
	 ifstream objiff("bloodstock.dat",ios::binary);
	  storeblood blstk;
 if(!objiff)
 {
 getch();
//return; 
}  
cout<<"\n";
cout<<"BLOODNO:";
cout<<"BLOOD GROUP:";
cout<<"QUANTITY:\n";
 while(objiff.read((char*)&blstk,sizeof(blstk)))
{
 if( strcmp(blstk.bloodgroup,blgrp)==0 && blstk.qty>0)
 {
 cout<<blstk.blno<<"-"<<blstk.bloodgroup<<"-"<<blstk.qty;
returnvalue=0;
 }
 }
objiff.close();
 //*******************main ends here
 ifstream fp;
 fp.open("bloodstock.dat",ios::binary);
 storeblood dr;
 cout<<"=================================\n";
 cout<<"===============OTHER COMPATIBLE BLOOD GROUPS=================";
//-------for A+
if(strcmp(blgrp,"A+")==0)
{
 while(fp.read((char*)&dr,sizeof(storeblood)))
{
 if((strcmp(dr.bloodgroup,"A-")==0 ||strcmp(dr.bloodgroup,"O-")==0 || strcmp(dr.bloodgroup,"O+")==0) && dr.qty>0)
{
 cout<<dr.blno<<"-"<<dr.bloodgroup<<"-"<<dr.qty;
 returnvalue=0;
 }
 }
 }
 ///for A-
else if(strcmp(blgrp,"A-")==0 )
 {
 while(fp.read((char*)&dr,sizeof(storeblood)))
{
 if((strcmp(dr.bloodgroup,"O-")==0)&& dr.qty>0)
 {
 cout<<dr.blno<<"-"<<dr.bloodgroup<<"-"<<dr.qty;
returnvalue=0;
 }
 }
 }
 //for B+
else if(strcmp(blgrp,"B+")==0)
{
 while(fp.read((char*)&dr,sizeof(storeblood)))
 {
 if((strcmp(dr.bloodgroup,"B-")==0 ||strcmp(dr.bloodgroup,"O-")==0 || strcmp(dr.bloodgroup,"O+")==0)&& dr.qty>0)
{
  cout<<dr.blno<<"-"<<dr.bloodgroup<<"-"<<dr.qty;
returnvalue=0;
 }
 }
 }
 //**for B-
else if(strcmp(blgrp,"B-")==0)
{
 while(fp.read((char*)&dr,sizeof(storeblood)))
 {
 if((strcmp(dr.bloodgroup,"B-")==0 ||strcmp(dr.bloodgroup,"O-")==0)&& dr.qty>0)
 {
  cout<<dr.blno<<"-"<<dr.bloodgroup<<"-"<<dr.qty;
returnvalue=0;
 }
 }
 }
 //**for AB+
else if(strcmp(blgrp,"AB+")==0)
{ while(fp.read((char*)&dr,sizeof(storeblood)))
 {
 if((strcmp(dr.bloodgroup,"A+")==0 || strcmp(dr.bloodgroup,"A-")==0 || strcmp(dr.bloodgroup,"B+")==0 || strcmp(dr.bloodgroup,"B-")==0 || strcmp(dr.bloodgroup,"O+")==0 || strcmp(dr.bloodgroup,"O-")==0 || strcmp(dr.bloodgroup,"AB-")==0)&& dr.qty>0)
{
 cout<<dr.blno<<"-"<<dr.bloodgroup<<"-"<<dr.qty;
 returnvalue=0;
 }
 }
 }
 //**for AB-
else if(strcmp(blgrp,"AB-")==0)
{
 while(fp.read((char*)&dr,sizeof(storeblood)))
{
 if((strcmp(dr.bloodgroup,"O-")==0 ||strcmp(dr.bloodgroup,"A-")==0 ||strcmp(dr.bloodgroup,"B-")==0 || strcmp(dr.bloodgroup,"AB-")==0)&& dr.qty>0)
{
  cout<<dr.blno<<"-"<<dr.bloodgroup<<"-"<<dr.qty;

 returnvalue=0;
 }
 }
 }
 //**for O+
else if(strcmp(blgrp,"O+")==0)
{
 while(fp.read((char*)&dr,sizeof(storeblood)))
 {
 if((strcmp(dr.bloodgroup,"O-")==0)&& dr.qty>0)
 {
 
 cout<<dr.blno<<"-"<<dr.bloodgroup<<"-"<<dr.qty; 
 returnvalue=0;
  } 
  } 
  } 
  //**for O- else if((strcmp(blgrp,"O-")==0)&& dr.qty>0)
{
cout<<"\n";
  cout<<"*****************ONLY O - *************************\n";
returnvalue=0;
 }
 //**************************ends here************************
fp.close();
 return returnvalue;
 //******************compatibility ends here
 }
 //*************function to search for blood and compatibility and return true
//************function to display all patients details date wise
void displaypatientdetails(dateinfo bgp)
 {
 ifstream fp;
fp.open("patientsinfo.dat",ios::binary);
 patient dr;
 if(!fp)
 {
 getch();
 return;
 }
 intromain();
 //***********display date
 cout<<"\n DATE(dd/mm/yyyy):"<<bgp.dd<<"/"<<bgp.mm<<"/"<<bgp.yy; 
 cout<<"REG No."<<"NAME OF PATIENT"<<" AGE"<<"--ADDRESS--"<<"--MOBILE NO--"<<"BLOOD GROUP:\n"; 
while(fp.read((char*)&dr,sizeof(patient))) 
{
 if(dr.pdd()==bgp.dd && dr.pmm()==bgp.mm && dr.pyy()==bgp.yy) 
{
 dr.showallpatientsrowwise();
 }
 } fp.close();
 getch(); 
}
 //************function to display all patients details date wise //***************************************************************
 // patient's information //*************************************************************** 
void patients_menu(char brg[5])
 {
 patient patobj;
ofstream objoff;
 char getprv_patno[15];
 objoff.open("patientsinfo.dat",ios::binary|ios::app); 
 intromain();
 strcpy(getprv_patno,getpatno());
 if(strcmp(getprv_patno,"NULL")!=0)
{
cout<<"\n Previous REGNO: "<<getprv_patno;
 }
 //************************************** 
 patobj.create_patient(brg);
 objoff.write((char*)&patobj,sizeof(patient));
objoff.close();
 //*********now decrease one from the stock of blood clrscr();
intromain();
 //***********check the available with compatibility and decrease one from it
 display_bloodavailable(brg);
 char blgroup[5];
 //************************************************************************
 cout<<"\n Enter the blood group ::";
 cin>>blgroup;
decrease_bloodstock(blgroup);
 //*********now decrease one from the stock of blood getch();
}
 //**************patient previous no
 //************get thje donars last number****************
char *getpatno()
 {
 ifstream objiff;
patient st;
int count=0;
 char tmpregno[15];
 objiff.open("patientsinfo.dat",ios::binary);
 objiff.seekg(0,ios::beg);
 if(!objiff)
 {
 getch();
 }
 //**************temporary hiding these lines
while(objiff.read((char *) &st, sizeof(patient)))
{
count++;
}
 //***********jump to the last line
 objiff.seekg(count-sizeof(st),ios::beg);
 objiff.read((char *) &st, sizeof(patient)); 
 strcpy(tmpregno,st.getpno());
 objiff.close();
 if(count!=0)
return tmpregno;
else 
return "NULL";
}
 //************get the donars last number****************
//**************patient previous no
 //******************all the donars fuction details****************************

