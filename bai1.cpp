#include<iostream>
#include<vector>
#include <string.h>
using namespace std;
typedef struct Contact{

	char ten[20];
	char sdt[11];
	char gmail[20],diachi[50];
	bool gioitinh;
}Contact;
vector <Contact> db;
void GhiVaodb();
void DocVaodb();
//thêm moi 1 danh ba(contact) vào danh ba
void ThemMoi(Contact C);
//them vao db
//ghi db vao file(danhba.dat)
void LietKe();// in cac phan tu cua db ra man hinh
void Xuat(Contact c);
void CapNhat(char sdt[]);
//tim contact m co sdt c.sdt
//cap nhat c vao m
//ghi db vao file
void XoaContact(char*sdt);
/*tim contact m co sdt trong db
xoa contact m
ghi db vao file*/
void TimTheoten(char t[]);
/* tim contact m co theo ten ten
them m vao bien vector
tra ve bien vector*/
int main(){
	DocVaodb();
	LietKe();
	Contact c;
	strcpy(c.ten,"pipi");
	strcpy(c.sdt,"354");
	strcpy(c.gmail,"asdas@gmail.com");
	strcpy(c.diachi,"fafafadfa");
	c.gioitinh=0;
	ThemMoi(c);
	Contact c1;
	strcpy(c1.ten,"thu");
	strcpy(c1.sdt,"789");
	strcpy(c1.gmail,"asdaxzzs@gmail.com");
	strcpy(c1.diachi,"nha trang");
	c1.gioitinh=1;
	ThemMoi(c1);
	Contact c2;
	strcpy(c2.ten,"tram");
	strcpy(c2.sdt,"123");
	strcpy(c2.gmail,"tramtram@gmail.com");
	strcpy(c2.diachi,"nha trang");
	c2.gioitinh=1;
	ThemMoi(c2);
	cout<<endl;
	cout<<" danh ba moi "<<endl<<endl;
	
	//
	cout << "Danh ba sau khi cap nhat " << endl;
	CapNhat("354");
	//
	cout<<"ban cap nhat sau khi xoa"<<endl;
	XoaContact("789");
	//
	cout<<"contact tim kiem"<<endl;
	TimTheoten("tram");
	
}
// ghi danh ba vao file .dat(nhi phan)
void GhiVaodb( ){
	FILE*f=fopen("db.dat","wb");// mo file de viet
	Contact c;
	for(int i = 0 ; i < db.size() ; i++) // vong lap for i < kick thuoc file db.dat
		fwrite(&db[i],sizeof(db),1,f);	//ghi contact vao file db.dat
		fclose(f);
}
void DocVaodb(){// doc danh ba tu file nhi phan
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
void ThemMoi(Contact c)// them cac contact c vao file .dat
{
	  db.push_back(c); // them mot gia tri cho vector
	  GhiVaodb();
}

void LietKe(){// liet ke cac contact c 
	Contact c;
	for(int i=0 ; i <db.size() ;i++){
		cout<<"ten la: "<<db[i].ten<<endl;
		cout<<"sdt la: "<<db[i].sdt<<endl;
		cout<<"dia chi la: "<<db[i].diachi<<endl;
		cout<<"gmail la: "<<db[i].gmail<<endl;
		cout<<"gioi tinh la: "<<db[i].gioitinh<<endl;
	}

}
void Xuat(Contact c){// in ra man hinh contact c
		cout<<"ten la: "<<c.ten<<endl;
		cout<<"sdt la: "<<c.sdt<<endl;
		cout<<"dia chi la: "<<c.diachi<<endl;
		cout<<"gmail la: "<<c.gmail<<endl;
		cout<<"gioi tinh la: "<<c.gioitinh<<endl;
}
void CapNhat(char sd[])// cap nhat danh ba theo sdt
//tim contact m co sdt c.sdt
//cap nhat c vao m
//ghi db vao file
{
	
for(int i = 0; i < db.size(); i++)
		{if(strcmp(db[i].sdt, sd) == 0)
			strcpy(db[i].ten, "Uyen Phuong");
			Xuat(db[i]);}
	
}
void XoaContact(char sd[])// xoa contact theo sdt
// tim contact m co sdt trong db
//xoa contact m
//ghi db vao file
{
for(int i=0;i<db.size();i++)
			if(strcmp(db[i].sdt,sd)==0)// so sanh db.sdt voi sdt can tim strcmp chuoi
				db.erase(db.begin()+i);//xoa 
		
	cout<<"cac gia tri con lai ";
	LietKe();	
}
void TimTheoten(char t[])// tim contact theo ten
{
	for(int i=0;i<db.size();i++)
			if(strcmp(db[i].ten,t)==0)// so sanh de tim ten trong danh sach voi ten nhap
				Xuat(db[i]);
}

