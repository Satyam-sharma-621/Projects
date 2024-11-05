#include<iostream>
#include<fstream>
#include<sstream>
#include<windows.h>
using namespace std;

class PhoneBook{
	
	private:
		string Name,PhNo,Address;
	public:
	PhoneBook():Name(""),PhNo(""),Address(""){}
	
	void setname(string name){
		Name=name;
	}
	
	void setphno(string phno){
		PhNo=phno;
	}
	
	void setaddress(string address){
		Address=address;
	}
	
	string getname(){
		return Name;
	}
	
	string getphno(){
		return PhNo;
	}
	
	string getaddress(){
		return Address;
	}	
};


addNo(PhoneBook user){
	system("cls");
	
	string name,phno,address;
	
	cout<<"\n\tEnter your Name:";
	cin>>name;
	user.setname(name);
	
	start:
	cout<<"\n\tEnter your Phone Number:";
	cin>>phno;
	
	if(phno.length()==10){	
	user.setphno(phno);
    }
    else{
    	cout<<"\n\tEnter 10 Digit!\n";
    goto start;	
	}
	
	cout<<"\n\tEnter your Address:";
	cin>>address;
	user.setaddress(address);
	
	ofstream outfile("C:\\Users\\Dell\\Documents\\phonerecord.txt",ios::app);
	if(!outfile){
		cout<<"\n\tFILE DOESN'T OPEN!!!";
	}
	else{
		outfile<<"\t"<<user.getname()<<" : "<<user.getphno()<<" : "<<user.getaddress()<<"\n\n";
		cout<<"\n\n\tPHONE NUMBER ADDED TO PHONE BOOK!!!";
	}
	outfile.close();
	
	Sleep(3000);
}

searchNo(){
	system("cls");
	
	string  name;
	cout<<"\n\tEnter the Name of User:";
	cin>>name;
	
	ifstream infile("C:\\Users\\Dell\\Documents\\phonerecord.txt");
	if(!infile){
		cout<<"\n\tFile doesn't Open!!!";
	}
	else{
		string line;
		bool found=false;
		while(getline(infile,line)){
			stringstream ss;
			ss<<line;
			string userName,userPhno,userAddress;
			char delimiter;
			ss>>userName>>delimiter>>userPhno>>delimiter>>userAddress;
			
			if(name==userName){
				found=true;
				cout<<"\n\n\t"<<userName<<"\t"<<userPhno<<"\t"<<userAddress<<endl;
			}
		}
		if(!found){
			cout<<"\n\tUSER NOT FOUND IN PHONE BOOK!!!";
		}
	}
	
	infile.close();
	
	Sleep(3000);
}

int main(){
	PhoneBook user;
	
	bool exit=false;
	
	while(!exit)
	{
		system("cls");
		int val;
		cout<<"\n\n\t!!!\tWELCOME TO PHONE MANAGEMENT SYSTEM\t!!!\n";
		cout<<"\t***************************************************\n";
		cout<<"\n\t1.ADD NUMBER\n";
		cout<<"\t2.SEARCH NUMBER\n";
		cout<<"\t3.EXIT\n";
		cout<<"\n\tEnter Your Choice:";
		cin>>val;
		
		if(val==1){
			addNo(user);
		}
		else if(val==2){
			searchNo();
		}
		else if(val==3){	
			exit=true;
			cout<<"\n\tTHANK YOU FOR YOUR VISIT!!!";
			cout<<"\n\t\t HAVE A NICE DAY!!!";
		}
		else{
			cout<<"\n\tPlease Enter from 1-3 Only!";
		}
		//Sleep(3000);
	}
	return 0;
}

