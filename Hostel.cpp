#include<iostream>
#include<fstream>
#include<sstream>
#include<windows.h>
using namespace std;

class Hostel{
	private:
		string Name;
		int Rent,Bed;
	public:
	Hostel(string name,int rent, int bed){
		Name=name;
		Rent=rent;
		Bed=bed;
	}
	string getname(){
		return Name;
	}
	int getrent(){
		return Rent;
	}
	int getbed(){
		return Bed;
	}	
	reserve(){
		ifstream in("C:\\Users\\Dell\\Documents\\projects\\Hostel.txt");
		ofstream out("C:\\Users\\Dell\\Documents\\projects\\Hostel Temp.txt");
		
		string line;
		while(getline(in,line)){
			int pos = line.find("5:Star");
			if(pos != string::npos){
				int bed=Bed-1;
				Bed=bed;
				stringstream ss;
				ss<<bed;
				string strBed = ss.str();
				
				int bedpos = line.find_last_of(':');
				line.replace(bedpos+1, string::npos,strBed);
			}
			out<<line<<endl;
		}
		out.close();
		in.close();
		remove("C:\\Users\\Dell\\Documents\\projects\\Hostel.txt");
		rename("C:\\Users\\Dell\\Documents\\projects\\Hostel Temp.txt","C:\\Users\\Dell\\Documents\\projects\\Hostel.txt");
		cout<<"\tBED RESEVED SUCCESSFULY!!!\n";
	} 
};

class student{
	private:
		string Name,RollNo,Address;
	public:
	student():Name(""),RollNo(""),Address(""){}
	
	void setname(string name){
		Name=name;
	}
	void setRollNo(string rollno){
		RollNo=rollno;
	}
	void setaddress(string address){
		Address=address;
	}
	string getName(){
		return Name;
	}
	string getRollNo(){
		return RollNo;
	}
	string getAddress(){
		return Address;
	}
};
int main(){
	Hostel H1("5:Star",2000,25);
	ofstream out("C:\\Users\\Dell\\Documents\\projects\\Hostel.txt");
	out<<"\t"<<H1.getname()<<" : "<<H1.getrent()<<" : "<<H1.getbed()<<"\n\n";
	cout<<"HOSTEL DATA SAVED\n";
	out.close();
	
	student s1;
	
	bool exit=false;
	while(!exit){
		system("cls");
		int val;
		
		cout<<"\n\t!!!\tWELCOME TO HOSTEL ACCOMMODATION SYSTEM\t!!!\n";
		cout<<"\t***************************************************";
		cout<<"\n\n\t1.RESERVE BED";
		cout<<"\n\t2.EXIT";
		cout<<"\n\tEnter Choice:";
		cin>>val;
		
		if(val==1){
			system("cls");
			string name,rollno,address;
			
			cout<<"\tEnter Student Name:";
			cin>>name;
			s1.setname(name);
			
			cout<<"\tEnter Student RollNo.:";
			cin>>rollno;
			s1.setRollNo(rollno);
			
			cout<<"\tEnter Student Address:";
			cin>>address;
			s1.setaddress(address);
			
			if(H1.getbed()>0){
				H1.reserve();
			}
			else if(H1.getbed()==0){
				cout<<"\tSORRY, BED NOT AVAILABLE!\n";
			}
			
			ofstream outfile("C:\\Users\\Dell\\Documents\\projects\\Student.txt",ios::app);
			outfile<<"\t"<<s1.getName()<<" : "<<s1.getRollNo()<<" : "<<s1.getAddress()<<"\n\n";	
			
			Sleep(5000);
		}
		else if(val==2){
			system("cls");
			exit=true;
			cout<<"\n\tTHANK YOU FOR YOUR VISIT!!!";
			Sleep(3000);
		}
	}
}


