#include<bits/stdc++.h>
#include<unordered_map>
#include <iterator> 
using namespace std;
class Blood_group
{
protected:
    string blood_group;
public:
    Blood_group(string n)
    {
        blood_group=n;
    }
	void set_Blood_group(string n)
	{
	    blood_group=n;
	}
	string get_Blood_group()
	{
	    return blood_group;
	}

};
class User
{
protected:
	string phone_no;
	string email;
	string aadhar_no;
public:
    User(string a,string b,string c)
    {
        phone_no=a;
        email=b;
        aadhar_no=c;
    }
    void set_phone_no(string p)
	{
    		phone_no=p;
	}
    void set_email(string e){
    	email=e;
	}
    void set_aadhar(string h){
	aadhar_no=h;
	}	

    string get_phone_no(){
    	return phone_no;
	}

    string get_email(){
    	return email;
	}
    string get_aadhar(){
    	return aadhar_no;
	}

};
class Department
{
protected:
    string department;
public:
    Department(string d)
    {
        department=d;
    }
    string get_department(string d)
	{
    		return department;
	}
    void set_department(string d){
    		department=d;
	}
};
class Name
{
protected:
    string name;
public:
    Name(string n)
    {
        name=n;
    }
	void set_name(string n)
	{
	    name=n;
	}
	string get_name()
	{
	    return name;
	}

};
class Roll
{
protected:
    long int roll;
public:
    Roll(long int n)
    {
        roll=n;
    }
	void set_roll(long int  r)
	{
	    roll=r;
	}
	long int get_roll()
	{
	    return roll;
	}

};

class Donor:public Roll,public Name,public Department,public Blood_group,public User
{
protected:
    int no_of_blood_donate;
    string last_date_of_blood_donation;
public:
	Donor(string name,long int rollnum,string phone_no,string email,string aadhar_no,string blood_group,string dept,int num_of_blood,string lst_dt_of_bd):Roll(rollnum),User(phone_no,email,aadhar_no),Name(name),Department(dept),Blood_group(blood_group)
    {
        no_of_blood_donate=num_of_blood;
        last_date_of_blood_donation=lst_dt_of_bd;
	}
        void set_no_of_blood_donate(int n)
	{
	    no_of_blood_donate=n;
	}
	void set_last_date_of_blood_donation(string d)
	{
	    last_date_of_blood_donation=d;
	}
	int get_no_of_blood_donate()
	{
	    return no_of_blood_donate;
	}
	string get_last_date_of_blood_donation()
	{
	    return last_date_of_blood_donation;
	}
	void print(){
		cout<<endl;
		cout<<"Name: "<<name<<endl;
		cout<<"Email: "<<email<<endl;
		cout<<"Phone No.: "<<phone_no<<endl;
		cout<<"Aadhar No.: "<<aadhar_no<<endl;
		cout<<"Roll No.: "<<roll<<endl;
		cout<<"Blood Group: "<<blood_group<<endl;
		cout<<"Department: "<<department<<endl;
		cout<<"Amount of blood donated: "<<no_of_blood_donate<<endl;
		cout<<"Last Date of Blood Donation: "<<last_date_of_blood_donation<<endl;
		cout<<endl;
	}

};
int main(){
    	cout<<"           WELCOME TO  BLOOD BANK MANAGEMENT SYSTEM    " <<endl;
	cout<<"include all the users in a file to get filled initially into the system"<<endl;
	int num;
	cout<<"Enter number of donors:"<<endl;
	cin>>num;
	unordered_map<string,Donor> name_donors;
	unordered_map<string,Donor> aadhar_donors;
	while(num--){
		string name,phonenum,email,addhar_no,blood_group,dept,lst_dt_of_bd;
		long int rollnum;
		int num_of_blood;		
		cout<<"enter name=";
		cin>>name;
		cout<<"enter phonenum:";
        cin>>phonenum;
		cout<<"enter email:";
		cin>>email;
		cout<<"enter addhar_no:";
		cin>>addhar_no;
		cout<<"enter blood group:";
		cin>>blood_group;
		cout<<"Enter dept:";
		cin>>dept;
		cout<<"enter rollnum:";
		cin>>rollnum;
		cout<<"Enter blood in ml:";
		cin>>num_of_blood;
		cout<<"Enter the last donation:";
		cin>>lst_dt_of_bd;
		name_donors.insert({name,Donor(name,rollnum,phonenum,email,addhar_no,blood_group,dept,num_of_blood,lst_dt_of_bd)});
		aadhar_donors.insert({aadhar_no,Donor(name,rollnum,phonenum,email,addhar_no,blood_group,dept,num_of_blood,lst_dt_of_bd)});
	}			
	unordered_map<string,Donor>::iterator p;
	unordered_map<string,Donor>::iterator t;
	for(p=name_donors.begin();p!=name_donors.end();p++){
		p->second.print();
	}
	
	string temp;
	int ch;
	while(1)
	{
		cout << "1->Search by name \n2->Search by Aadhar Number\n3->Exit\nEnter your choice\n";
		cin >> ch;
		switch(ch)
		{
			case 1:
			cout<<"Enter the name to be searched:"<<endl;
			cin>>temp;
			
			if (name_donors.find(temp) == name_donors.end()) 
			cout << "Element Not Present\n"; 
		    	else
			{
				p=name_donors.find(temp);
				p->second.print();
			}
			break;
			case 2:
			cout<<"Enter the Aadhar Number to be searched:"<<endl;
			cin>>temp;
			
			if (aadhar_donors.find(temp) == aadhar_donors.end()) 
			cout << "Element Not Present\n"; 
		    	else
			{
				t=aadhar_donors.find(temp);
				t->second.print();
			}
			break;
			case 3:
				exit(1);
		}
        }        	
}
