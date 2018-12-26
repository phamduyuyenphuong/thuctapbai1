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
void CapNhat(Contact C);
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
	cout<<" danh ba moi "<<endl;
	LietKe();

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
		cout<<"ten la: "<<c.ten<<"\n";
		cout<<"sdt la: "<<c.sdt<<"\n";
		cout<<"dia chi la: "<<c.diachi<<"\n";
		cout<<"gmail la: "<<c.gmail<<"\n";
		cout<<"gioi tinh la: "<<c.gioitinh<<"\n";
	}

}

