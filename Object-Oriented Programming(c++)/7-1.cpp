//先实现命令行读入电话，查询，删除,然后是保存->读入
//同名：对于查询和删除，都是操作先读入的，如果需要更新号码，需要先删除，再新增。
#include <functional>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#define MaxLineChar 130
#define MaxContactsNum 1000
#define HashNum 900

using namespace std;

hash <string> Hash_String;

class c_Contact
{
	public:
		c_Contact() { name=""; phone=""; }
		c_Contact(const string& n,const string& p) { name=n; phone=p; }
		c_Contact(const c_Contact& a) { name=a.name; phone=a.phone; }
		string GetName() const { return name; }
		string GetPhone() const { return phone; }
		void SetContact(const string& n,const string& p) { name=n; phone=p; }
		bool CheckName(const string a) const { if (name==a) return 1; else return 0; }
	private:
		string name,phone;
};

c_Contact contacts[MaxContactsNum];      //哈希数组

int FindHolder(const string& a)			//为新联系人找储存的数组下标 成功返回下标 失败-1
{
	int i=Hash_String(a)%HashNum;
	while (i<=MaxContactsNum&&((contacts[i]).GetName()!="")) i++;
	if (i<=MaxContactsNum)
		return i;
	else 
		return -1;
}

int FindElement(const string& a)		//查找是否有姓名为 a 的联系人 成功返回下标 失败-1
{
	int i=Hash_String(a)%HashNum;
	while (i<=MaxContactsNum&&((contacts[i]).GetName()!="")&&(contacts[i]).CheckName(a)==false) i++;
	if (i<=MaxContactsNum&&((contacts[i]).GetName()!="")) 
		return i;
	else 
		return -1;
}

int AskQuery()							//读取请求
{
	cout<<"What can I do for you?"<<endl;
	int x;
	cin>>x;
	while (cin.fail()) 
	{
		cout<<"Need help? Enter 0 for help."<<endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin>>x;
	}
	return x;
}

void WelcomeInterface()					//欢迎界面
{
	system("clear");
	cout<<setw(MaxLineChar/5*3)<<"Phonebook System       "<<endl<<endl;
	cout<<setw(MaxLineChar)<<"Designed by YeWenting.   "<<endl;
	for (int i=0;i<MaxLineChar;i++) cout<<'*';
}

void AddContact()
{
	cout<<"Please input name and his phonenumber: "<<endl;
	string a,b;
	cin>>a>>b;
	int i=FindHolder(a);
	if (i>0)
	{
		(contacts[i]).SetContact(a,b);
		cout<<"Work successfully."<<endl;
	}
	else 
		cout<<"Memory is not enough:("<<endl;
}

void Find()
{
	cout<<"Please input contact's name:"<<endl;
	string a;
	cin>>a;
	int i=FindElement(a);
	if (i>0)
		cout<<"His phone is : "<<(contacts[i]).GetPhone()<<endl;
	else 
		cout<<"Sorry, There is nobody called \""<<a<<"\"."<<endl;
}

void DeleteContact()
{
	cout<<"Please input someone's name who you wanna delete:"<<endl;
	string a;
	cin>>a;
	int i=FindElement(a);
	if (i>0)
	{
		contacts[i].SetContact("","");
		cout<<"Delete successfully."<<endl;
	}
	else 
		cout<<"Sorry, There is nobody called \""<<a<<"\"."<<endl;
}

void Save()
{
	cout<<"Please input the name you wanna set this phonebook as:"<<endl;
	string a;
	cin>>a;
	ofstream MyFile;
	MyFile.open(a);
	if (MyFile.fail()) 
	{
		cout<<"There is no enough disk space, work unsuccessfully:("<<endl;
		return;
	}
	for (int i=0;i<=MaxContactsNum;i++)
		if ((contacts[i]).GetName()!="") MyFile<<(contacts[i]).GetName()<<' '<<(contacts[i]).GetPhone()<<endl;
	cout<<"Save successfully."<<endl;
	MyFile.close();
}

void LoadBook()
{
	cout<<"Please input the name of the phonebook:"<<endl;
	string a;
	cin>>a;
	ifstream MyFile;
	MyFile.open(a);
	if (MyFile.fail()) 
	{
		cout<<"There is no enough disk space, work unsuccessfully:("<<endl;
		return;
	}
	int error=0,tot=0;
	while (!MyFile.eof())
	{
		string n,p;
		MyFile>>n>>p;
		if (n=="") break; 
		tot++;
		int i=FindHolder(n);
		if (i>0)
			(contacts[i]).SetContact(n,p);
		else error++;
	}
	cout<<"There are "<<tot<<" operation, "<<tot-error<<" succeeded and "<<error<<" failed."<<endl;
	MyFile.close();
}

int main(int argc, char const *argv[])
{
	WelcomeInterface();
	int query=AskQuery();
	while (query!=-1)
	{
		if (query==0) cout<<"1:Add contact 2:Find phone number 3:Delete a contact " 
			<<"4.Save this phonebook 5.Add a existed phonebook -1:exit."<<endl;
		if (query==1) AddContact();
		if (query==2) Find();
		if (query==3) DeleteContact();
		if (query==4) Save();
		if (query==5) LoadBook();
		query=AskQuery();
	}
	cout<<"Thanks for using my product, goodbye:)"<<endl;
	return 0;
}