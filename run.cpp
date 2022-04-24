//#pragma once
using namespace std;

#include"KhaoBao.h"
#include"DoHoa.h"
#include"Nhap.h"
#include"DocGia.h"
#include"Dausach.h"
#include"MuonTra.h"
#include"GiaiPhongBoNho.h"


char danhsach [12][50] = {	"   Dang ky the doc gia     ",
							"     Xoa the doc gia        ",
							" Hieu chinh the doc gia    ",
							"  In danh sach doc gia     ",
							"  Nhap thong tin dau sach  ",
							"      In DS dau sach       ",
							"          Tim sach         ",
							" Liet ke sach doc gia muon ",	
							"          Muon sach        ",
							"          Tra sach         ",
							"     Mo va Khoa the doc gia ",
							"  Top 10 sach duoc muon nhieu"
							};
int Menu(char a [12][50],int &chon, int &ngang, int &doc){
  /*system("cls");*/  // int doc =0, ngang=0,chon=0;
  int i, cot=16,dong=19;
  int tempX=cot,tempY=dong;
  Normal ();
  for ( i=0; i< 4 ; i++)
  { gotoxy(tempX, tempY);
    cout << a[i];
    tempY+=2;
  }
  
  tempX=cot+43;
  tempY=dong;
  for ( i=4; i< 8 ; i++)
  { gotoxy(tempX, tempY);
    cout << a[i];
    tempY+=2;
  }
  
  tempX=cot+43*2;
  tempY=dong;
  for ( i=8; i< 12 ; i++)
  { gotoxy(tempX, tempY);
    cout << a[i];
    tempY+=2;
  }
  HighLight();
  gotoxy(cot+ngang,dong+doc);
  cout << a[chon];
  char kytu;
do {
  kytu = getch();
  if (kytu==0) kytu = getch();
  switch (kytu) {
    case Up :if (doc-2>=0)
  			  {
  			  	Normal();
              	gotoxy(cot+ngang,dong+doc);
              	cout << a[chon];
              	doc-=2;
              	chon--;
              	HighLight();
              	gotoxy(cot+ngang,dong+doc);
              	cout << a[chon];
  				
  			  }
  			  break;
  	case Right :if (ngang+43<=43*2)
  			  {
  			  	Normal();
              	gotoxy(cot+ngang,dong+doc);
              	cout << a[chon];
              	ngang+=43;
              	
              	HighLight();
        
  					chon+=4;
  					gotoxy(cot+ngang,dong+doc);
  					cout<<a[chon];
				
  			  }
  			  break; 
  	case Left :if (ngang-43 >=0)
  			  {
  			  	Normal();
              	gotoxy(cot+ngang,dong+doc);
              	cout << a[chon];
              	ngang-=43;
              	HighLight();
  					chon-=4;
  					gotoxy(cot+ngang,dong+doc);
  					cout<<a[chon];
				  
  			  }
  			  break;
  	case Down : if (doc+2<=6)
	  			 	 {
	  		        Normal();
	              	gotoxy(cot+ngang,dong+doc);
	              	cout << a[chon];
	              	doc +=2;
	              	chon++;
	              	HighLight();
	              	gotoxy(cot+ngang,dong+doc);
	              	cout << a[chon];
	  			}
  			  break;
  	case Enter : return chon;
  	case Esc : return -1;
  }  
  } while (1);
}

int main()
{
	srand((int)time(NULL));
  	GiaoDienChinh();
	TREE t;
	KhoiTaoDG(t);
	LoadDocGiaFromFile(t);

	
	MCONTRO DauS;
	DauS.SoluongdauS=0;
	docfilevaomang(DauS);
	
	LoadFileDanhSachSachMuonTra(t,DauS);
	
	Date ngayhientai;
	LayNgayHienTai(ngayhientai);
	KiemTraQuaHan(t, ngayhientai);
	
	int chon=0,ngang=0,doc=0 ;
  do
  {
  	bool exit=FALSE;
  	HuongDan("Nhan ESC - Thoat", "Nhan cac phim mui ten de dieu khien", "Enter de chon");
	HCN_Menu(10,15,35,18);
	chon = Menu(danhsach,chon,ngang,doc);
    switch (chon ){
    case 0: {
    	XoaHCN(10, 15, 125, 18);
    	LoadMaDocGia();
    	HuongDan("Nhan phim mui ten de tuy chinh", "Apply: Luu du lieu | Cancel: Huy thao tac", "Nhan ESC - Thoat");
    	while(!exit)
		{ 
			GiaoDienThemDocGia();
			int x=mathe[1];
			ThemDocGia(t,x,exit);
			LoadGiaoDienThemDG();
		}
		XoaHCN(5, 13, 135, 25);// Xoa GiaoDienThemDocGia();
		break;}
    case 1:{
    	ShowCur(1);
    	XoaHCN(10, 15, 125, 18);
    	HuongDan("Nhan phim mui ten de tuy chinh", "Apply: Luu du lieu | Cancel: Huy thao tac", "Nhan ESC - Thoat");
  		int ma;
    	while(!exit)
		{ 
			GiaoDienXoaDocGia();
	Nhaplaima:
			XuLiNhapSo(62,20,ma,5,exit);
			if(exit){
				exit=ThongBao("","Ban co muon thoat ?",55,21);
				if(exit){
					XoaHCN(5, 13, 135, 25);// Xoa GiaoDienXoaDocGia();
					break;
				}
			}
			if(ma==0)
			{
				gotoxy(62,20);cout<<"     ";
				goto Nhaplaima;
			}
			XoaDocGia(t,ma,exit);
			SaveToFile(t);		
		}
		XoaHCN(5, 13, 135, 25);
		break;}
    case 2: { 
    	ShowCur(1);
    	XoaHCN(10, 15, 125, 18);
    	HuongDan("Nhan phim mui ten de tuy chinh", "Apply: Luu du lieu | Cancel: Huy thao tac", "Nhan ESC - Thoat");
    	int n;
    	while(!exit)
		{ 
			GiaoDienHieuChinhDocGia();
	Nhaplaima2:
			XuLiNhapSo(73,17,n,5,exit);
			if(exit){
				exit=ThongBao("","Ban co muon thoat ?",55,21);
				if(exit){
					XoaHCN(5, 13, 135, 25);// Xoa GiaoDien();
					break;
				}
			}
			if(n==0)
			{
				gotoxy(73,17);cout<<"     ";
				KhungText("Ho:",47,21,21, 2, 14 );
				KhungText("Ten:",46,25,15, 2, 14 );
				goto Nhaplaima2;
			}
			HieuChinhDocGia(t,n,exit);
			XoaHCN(11, 15, 123, 22);
		}
		XoaHCN(5, 13, 135, 25);// Xoa GiaoDien();
		break;
	}
	case 3:{
		XoaHCN(10, 15, 125, 18);
		int luachon=0;
		while(!exit)
		{ 
			XuatDocGiaRaPage(t,exit,luachon);
		}
		XoaHCN(5, 13, 135, 25);
		break;
	}
	case 4:{
		XoaHCN(10, 15, 125, 18);
		
    	HuongDan("Nhan phim mui ten de tuy chinh", "Apply: Luu du lieu | Cancel: Huy thao tac", "Nhan ESC - Thoat");
    	while(!exit)
		{ 
			GiaoDienThemSach();
			themdausach(DauS, exit);
			XoaHCN(5, 13, 135, 25);
		}break;
	}
	case 5:{
		XoaHCN(10, 15, 125, 18);	
		HuongDan("Nhan phim mui ten de tuy chinh", "Enter - chon", "Nhan ESC - Thoat");
		while(!exit){
		Lietkecactheloai(DauS,exit);
		}
		XoaHCN(5, 13, 135, 25);
		break;
	}
	case 6:{
		XoaHCN(10, 15, 125, 18);
		HuongDan("Hay nhap dung ten sach", "Enter - tim ket qua", "Nhan ESC - Thoat");
		while(!exit){
			TimSach(DauS, exit);
			if(exit){
				XoaHCN(5, 13, 135, 25);// Xoa GiaoDienXoaDocGia();
				break;
			}
		}
		XoaHCN(5, 13, 135, 25);
		break;
	}
	case 7:{
		XoaHCN(10, 15, 125, 18);	
		HuongDan("vui long dung ma the", "Enter - tim ket qua", "Nhan ESC - Thoat");
		XuatCacSach1DocGiaDangMuon( t, DauS, exit);
		XoaHCN(5, 13, 135, 25);
		break;
	}
	case 8:{
		XoaHCN(10, 15, 125, 18);	
		MuonSach(t, DauS, exit);
		XoaHCN(5, 13, 135, 25);
		break;
	}
	case 9:{
		XoaHCN(10, 15, 125, 18);
		TraSach(t,DauS,exit);	
		XoaHCN(5, 13, 135, 25);
		break;
	}
	case 10:{
		XoaHCN(10, 15, 125, 18);
		MoKhoaVaKhoaTheDocGia(t,exit);
		XoaHCN(5, 13, 135, 25);
		break;
	}
	case 11:{
		XoaHCN(10, 15, 125, 18);
		HuongDan("", "Enter hoac ESC - Thoat ", "");
		In10SachCoSoLuotMuonNhieuNhat(DauS);
		XoaHCN(5, 13, 135, 25);
		break;
	}
	case -1:{
		DeleteAll(t, DauS);
		Normal();
		system("cls");
		return 0;
	} 
}
  } while (1);
	clreol();
}

