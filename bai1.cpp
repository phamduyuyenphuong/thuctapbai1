#include<iostream>
#include<vector>
#include<iostream>
#include <string.h>
using namespace std;
typedef struct Contact{

	char ten[20];
	char sdt[11];
	char gmail[20],diachi[50];
	bool gioitinh;
}Contact;
vector <Contact> db;

//thêm moi 1 danh ba(contact) vào danh ba
void ThemMoi(Contact C);
//them vao db
//ghi db vao file(danhba.dat)

void LietKe();// in cac phan tu cua db ra man hinh
void CapNhat(Contact c);
//tim contact m co sdt c.sdt
//cap nhat c vao m
//ghi db vao file
void XoaContact(char*sdt);
// tim contact m co sdt trong db
//xoa contact m
//ghi db vao file
vector<Contact>
	TimTheoten(char*ten);
// tim contact m co theo ten ten
//them m vao bien vector
//tra ve bien vector
void GhiVaodb();
void DocVaodb();
int main(){
	DocVaodb();
	LietKe();
	Contact c;
	strcpy(c.ten,"pipi");
	strcpy(c.sdt,"2656565400");
	strcpy(c.gmail,"asdas@gmail.com");
	strcpy(c.diachi,"fafafadfa");
	c.gioitinh=0;
	ThemMoi(c);
	Contact c1;
	strcpy(c1.ten,"pipivdzvs");
	strcpy(c1.sdt,"265650056565");
	strcpy(c1.gmail,"asdaxzzs@gmail.com");
	strcpy(c1.diachi,"nha trang");
	c1.gioitinh=1;
	ThemMoi(c1);
	cout<<endl;
	cout<<" danh ba moi "<<endl<<endl;
	LietKe();
	cout<<"danh ba sau khi cap nhat"<<endl;
	Contact cmoi;
	strcpy(cmoi.ten,"uyen phuong");
	strcpy(cmoi.sdt,"0168435210");
	strcpy(cmoi.gmail,"uyenphuong@gmail.com");
	strcpy(cmoi.diachi,"quang nam");
	cmoi.gioitinh=0;
	CapNhat(cmoi);
	cout<<"ban cap nhat sau khi xoa"<<endl;
	XoaContact("0168435210");
	Contact TimTheoten("pipi");
	cout<<"contact tim kiem"<<endl;
}

void GhiVaodb( ){
	FILE*f=fopen("db.dat","wb");
	Contact c;
	for(int i = 0 ; i < db.size() ; i++)
		fwrite(&db[i],sizeof(db),1,f);	
		fclose(f);
}
void DocVaodb(){
	db.clear();
	FILE*f =fopen("db.dat","rb");
	if( f != NULL)
	{
		while(!feof(f)){
			Contact c;
			fread(&c,sizeof(Contact),1,f);	
			db.push_back(c);
		}
			fclose(f);
			db.pop_back();
	}
}
void ThemMoi(Contact c)
{
	  db.push_back(c);
	  GhiVaodb();
}

void LietKe(){
	Contact c;
	for(int i=0 ; i <db.size() ;i++){
		cout<<"ten la: "<<db[i].ten<<endl;
		cout<<"sdt la: "<<db[i].sdt<<endl;
		cout<<"dia chi la: "<<db[i].diachi<<endl;
		cout<<"gmail la: "<<db[i].gmail<<endl;
		cout<<"gioi tinh la: "<<db[i].gioitinh<<endl;
	}

}
void CapNhat(Contact c)
{
	FILE*f=fopen("db.dat","wb");
//	Contact cmoi;
	ThemMoi(c);
	LietKe();
	for(int i = 0 ; i < db.size() ; i++)
		fwrite(&db[i],sizeof(db),1,f);	
		fclose(f);
	
}
void XoaContact(char*sd)
// tim contact m co sdt trong db
//xoa contact m
//ghi db vao file
{
for(int i=0;i<db.size();i++)
		{
			if(strcmp(db[i].sdt,sd)==0)
				db.erase(db.begin()+i);
		}
	LietKe();	
}
Contact TimTheoten(char t[])
{
	for(int i=0;i<db.size();i++)
			if(strcmp(db[i].ten,t)==0)
				return db[i];
}

