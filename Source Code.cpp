#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;

class Project{   
	public:
		void ProjectInfo()
		{
			cout<<"\t\t\t\t===== WELCOME TO STUDENT DATABASE MANAGEMENT PROJECT===="
				<<"\n\n\t Presented By:\n  \t\t\t Abdul Rehman Sarfaraz / 2012203 \n"
				<<"\t\t\t Muqadus Khalid /  2012233 \n"
				<<"\t\t\t Muhammad Arham  /  2012225\n"
				<<"\t\t\t Mouhammad Nouman Khan /  2012227 \n"
				<<"\n\n\t Submitted to:\n  \t\t\t Sir Atif Bajwa \n\n\t\t\t\t\t";
			system("pause");
			system("CLS");
		}
};

class StudentDetails{
	public:
		friend class Student;          //to store data permanently.
		int studentRollNum;
		char sName[50];
		char Department[50];
		char instName[50];
		char instAddress[50];
		int age;
		int phoneNo;
};

class Student : protected StudentDetails{
	public:
		StudentDetails SD;
		int i;
		friend class Filing;
		
		int getALL(char temp)
		{
			if(temp == 'M')
			{      										//this condition true only when we Modify Data.
				goto skip_roll;
			}
			again:
				
			cout << "\t\t\t\t\t\tEnter Roll Number: ";
			cin>>SD.studentRollNum;
			
			if(SD.studentRollNum == 0)
			{
				cout << "\t\t\t\t\t\tRoll No cant be zero";
				goto again;
			}
			
			skip_roll:
				
			cout << "\t\t\t\t\t\tEnter Name: ";
			cin>>SD.sName;
			cout << "\t\t\t\t\t\tAge: ";
			cin>>SD.age;
			cout << "\t\t\t\t\t\tEnter Phone Number: ";
			cin>>SD.phoneNo;
			cout << "\t\t\t\t\t\tEnter your Course Department: ";
			cin>>SD.Department;
			cout << "\t\t\t\t\t\tEnter your Institute Name: ";
			cin>>SD.instName;
			cout << "\t\t\t\t\t\tInstitute Address: ";
			cin>>SD.instAddress; 
		}
		
		int Delete()
		{
			SD.studentRollNum=0;
		}
		
		int Searchdata(int R_rollno)
		{
			if(R_rollno == SD.studentRollNum)
			{
				return R_rollno;
			}
		}

		int Disp_SearchData()
		{
				cout << "\t\t\t\t\t\tStudent ID: "<<SD.studentRollNum<<endl;
				cout << "\t\t\t\t\t\tName: "<<SD.sName<<endl;
				cout << "\t\t\t\t\t\tAge: "<<SD.age<<endl;
				cout << "\t\t\t\t\t\tPhone Number: "<<SD.phoneNo<<endl;
				cout << "\t\t\t\t\t\tDepartment: "<<SD.Department<<endl;
				cout << "\t\t\t\t\t\tIntitute Name: "<<SD.instName<<endl;
				cout << "\t\t\t\t\t\tInstitute Address: "<<SD.instAddress<<endl;
		}
		
		int Disp_List_Only()
		{
			if(SD.studentRollNum == 0){
			}else{
			cout<<"\t\t\t  "<<SD.studentRollNum<<"\t\t\t\t"<<SD.sName<<"\t\t\t"<<SD.Department<<endl;
			cout<<"\t\t\t----------------------------------------------------------------------"<<endl;
			}
		}
			
};

class Filing{
	public:
		int write(Student S)
		{
			ofstream record_in("Record_Log.txt",ios::app);
			record_in<<S.SD.studentRollNum<<"\t\t"<<S.SD.sName<<"\t\t"<<S.SD.age<<"\t\t"<<S.SD.phoneNo<<"\t\t"
					 <<S.SD.Department<<"\t\t"<<S.SD.instName<<"\t\t"<<S.SD.instAddress<<endl;
			record_in.close();
		}
		
};

int main()
{
	Project P;
	P.ProjectInfo();
	
	int n,i, require_rollno, temp_rollno, temp=0, require_index;
	Student s1[50];
	Filing F;
	char op, b;
	while(true)
	{
		
		back:
		system("CLS");
		cout<<"n\n\n\t\t\t===========================================================\n"<<endl;
		cout<<"\t\t\t################### STUDENT DATA BASE ######################\n"<<endl;
		cout<<"\t\t\t===========================================================\n"<<endl;
		cout<<"\n\t\t\t\t\t\t"<<"Add Student Data [A]"<<endl;
		cout<<"\n\t\t\t\t\t\t"<<"Find Student Data [F]"<<endl;
		cout<<"\n\t\t\t\t\t\t"<<"Modify Data [M]"<<endl;
		cout<<"\n\t\t\t\t\t\t"<<"Delete Data [D]"<<endl;
		cout<<"\n\t\t\t\t\t\t"<<"List Data [L]"<<endl;
		cout<<"\n\t\t\t\t\t\t"<<"Logout [O]"<<endl;
		cout<<"\t\t\t============================================================\n"
			<<"\t\t\t\t\t\t ";
			
		cin>>op;
		
			if(op=='A'||op=='a')
			{
				cout<<"\t\t\t\t\t\t"
					<<"How many Data You want to Enter: ";
				cin>>n;
				
				for(i=1; i<=n; i++)
				{
					temp++;
					s1[i].getALL('I');
					F.write(s1[i]);           //Filing
					
					cout<<"\n"<<"\t\t\t\t\t\t"<<"Student "<<"\" "<<i<<" \" "<<"Data Saved Successfully..."<<endl<<endl;
				}
				
				cout<<"\n"<<"\t\t\t\t\t\t"<<"Total"<<"\" "<<i-1<<" \" "<<"Student Data Saved Successfully..."<<endl<<endl;
				cout<<"\t\t\t\t\t\t"
					<<"Press Y to go Back: ";
				cin>>b;
				if(b=='y'||'Y')
				{
					goto back;
				}

			}
			
			
			if(op=='F'||op=='f')
			{
				cout<<"\t\t\t\t\t\t"
					<<"Enter Roll No : ";
				cin >>  require_rollno;
				
				for(i=0 ; i<=temp ; i++){
				 temp_rollno = s1[i].Searchdata(require_rollno);
				 if(temp_rollno == require_rollno)
				 {
				 	require_index = i;
				 	s1[require_index].Disp_SearchData();
				 	
				 	cout<<"\t\t\t\t\t\t"
						<<"Press Y to go Back: ";
					cin>>b;
					if(b=='y'||'Y')
					{
						goto back;
					}
					
				 	goto here;              //this is used for doesnot exist , so that it wont repeat in loop
				 }
				}
				cout<<"\t\t\t\t\t\t"
					<<"Data doesnot exist !";
				here:
				getch();	
			}
			
			if(op =='M'||op=='m')
			{
				cout<<"\t\t\t\t\t\t"
					<<"Enter Roll No : ";
				cin>>require_rollno;
				for(i=0 ; i<=temp ; i++)
				{
				 temp_rollno = s1[i].Searchdata(require_rollno);
				 if(temp_rollno == require_rollno)
				 {
				 	require_index = i;
				 	break;
				 }
				}
				s1[require_index].getALL('M');
			}
			
			
			if(op=='D'||op=='d')
			{
				cout<<"\t\t\t\t\t\t"
					<<"Enter Roll No : ";
				cin >>  require_rollno;
				for(i=0 ; i<=temp ; i++)
				{
				 temp_rollno = s1[i].Searchdata(require_rollno);
				 if(temp_rollno == require_rollno)
				 {
				 	require_index = i;
				 	s1[require_index].Delete();
				 	
				 	cout<<"\n\t\t\t\t\t\t"
				 		<<"Record Deleted Successfully..."<<endl;
				 	getch();
				 	break;
					
				 }
				}	
			}

			if(op == 'L'||op=='l'){
			cout<<"\t\t\t=========================== STUDENT RECORD ==========================="<<endl;
	    		cout<<"\t\t\tStudent ID                  Student Name                    Department"<<endl;
	    		cout<<"\t\t\t======================================================================"<<endl;
	    		require_rollno = 0;
				for(i=0 ; i<=temp ; i++)
				{
					
					s1[i].Disp_List_Only();
				}
				getch();
			}
			
			
			if(op=='O'||op=='o')
			{
				system("CLS");
				cout<<"\t\t\t\t\t\t"
					<<"Logging off..."<<endl;
				system("pause");
				return 0;
				
			}
	}

}
