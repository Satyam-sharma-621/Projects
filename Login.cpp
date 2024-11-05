#include <iostream>
#include <fstream>
#include <windows.h>
#include <sstream>
using namespace std;

class Login{
private:
string LoginID,Password;
public:
Login():LoginID(""),Password(""){}
	
void setID(string id){
LoginID=id;
}

void setPW(string pw){
Password=pw;
}

string getID(){
return LoginID;
}

string getPw(){
return Password;
}			
};

registration(Login log){
	system("cls");
	
	string id,pw;
	cout<<"\tEnter Login ID:";
	cin>>id;
	log.setID(id);
	
	start:
	cout<<"\tEnter a strong Password:";
	cin>>pw;
	if(pw.length()>=8)
	{
	    log.setPW(pw);
    }
    else{
    	cout<<"\tEnter Minimum 8 characters!\n";
    goto start;	
	}
	ofstream outfile("C:\\Users\\Dell\\Documents\\Login.txt",ios::app);
	if(!outfile){
		cout<<"\tFile doesn't Open!\n";
	}
	else{
		outfile<<"\t"<<log.getID()<<" : "<<log.getPw()<<"\n\n";
		cout<<"\tUser Registration successfuly!\n";
	}
	outfile.close();
	
	Sleep(3000);
}

login(){
	system("cls");
	
	string id,pw;
	cout<<"\tEnter Login ID:";
	cin>>id;
	
	cout<<"\tEnter your Password:";
	cin>>pw;
	
	ifstream infile("C:\\Users\\Dell\\Documents\\Login.txt");
	if(!infile){
		cout<<"\tError: file doesn't Open!";
	}
	else{
		string line;
		bool found= false;
		while(getline(infile,line))
		{
			stringstream ss;
			ss<<line;
			string userID,userPW;
			char delimiter;
			ss>>userID>>delimiter>>userPW;
		    if(id==userID && pw==userPW )
			{
			found=true;
			cout<<"\tPlease Wait!";
			for(int i=0;i<3;i++)
			{
			cout<<".";
			Sleep(800);
		    }
		    system("cls");
			cout<<"\tWelcome TO This Page!\n";
	    	}	
		}
		if(!found){
			cout<<"\tError: Incorrect ID or Password!\n";
		}
	}
	infile.close();
	Sleep(5000);
}

int main(){
	Login log;
	
	bool exit=false;
	
	
	while(!exit){
		system("cls");
		int val;
		cout<<"\n\n\tWelcome TO Registration & Login form"<<endl;
		cout<<"\t************************************"<<endl;
		cout<<"\n\t1.Register\n";
		cout<<"\t2.Login\n";
		cout<<"\t3.Exit\n";
		cout<<"\tEnter choice:";
		cin>>val;
		
		if(val==1){
			registration(log);
		}
		else if(val==2){
			login();
		}
		else{
			exit=true;
			cout<<"\n\t\tTHANK YOU FOR YOUR VISIT!!!";
		}
		Sleep(3000);
	}
	return 0;
}









