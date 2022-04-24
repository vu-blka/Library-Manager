void Normal () {
	SetColor(7);
	SetBGColor(0);
}
void HighLight () {
	SetColor(27);
	SetBGColor(1);
}
void VeHCN(int toaX,int toaY,int ngang,int doc, int mausac)
{
	 SetBGColor(mausac);
	for(int i=0;i<=ngang;i++)
	{
		gotoxy(toaX+i,toaY);
		cout<<" ";
		gotoxy(toaX+i,toaY+doc);
		cout<<" ";
		
	}
	for(int i=0;i<=doc;i++)	
	{
		gotoxy(toaX,toaY+i);
		cout<<" ";
		gotoxy(toaX+ngang,toaY+i);
		cout<<" ";
		
	}
	SetBGColor(16);
}

void LogoThuVien(int toaX,int toaY)
{                
	int h = toaY;
	int mamau=1;
	int i=0;
	string str;
	ifstream f;
	f.open("LogoThuVien.TXT",ios::in);
	while (true)
	{
		mamau = 1 + rand() % 15;
		SetColor(mamau);
		getline(f,str);
		gotoxy(toaX, h++);
		cout << str;
		if(f.eof())
		{
			break;
		}
	}
	f.close();
	SetColor(7);
}
void HCN_Menu(int toaX,int toaY,int ngang,int doc)
{	
	
	VeHCN(toaX,toaY,ngang, doc, 18);//HCN doc gia
	VeHCN(toaX+45,toaY,ngang,doc, 18);//HCN dau sach
	VeHCN(toaX+90,toaY,ngang, doc,18);//HCN muon tra
	
	SetBGColor(16);
	SetColor(1);
	gotoxy(toaX+9,toaY+2);//toa do x=19,y=17
	cout<<"  QUAN LY DOC GIA";
	gotoxy(toaX+55,toaY+2);
	cout<<"QUAN LY DAU SACH";
	gotoxy(toaX+100,toaY+2);
	cout<<"QUAN LY MUON TRA";
}
void XoaHCN(int toaX, int toaY, int cot, int dong)
{
	//gotoxy(toaX,toaY);
	ShowCur(0);
	SetColor(16);
	SetBGColor(16);
	for(int i=0;i<=dong;i++)
	{
		gotoxy(toaX,toaY+i);
		for(int j=0;j<=cot;j++)
	 	{
			cout<<" ";
		}
	}
	SetColor(7);
	SetBGColor(16);
}
void ToMau(int toaX, int toaY, int ngang, int doc, int mausac)
{
	SetBGColor(mausac);
	ShowCur(0);
	for(int i=1;i<=doc;i++)
	{
		for(int j=1;j<=ngang;j++)
		{
			gotoxy(toaX+j,toaY+i);
			cout<<" ";
		}
	}
}
void XuatText(string str, int toaX, int toaY, int mausac )
{
	gotoxy(toaX,toaY);
	SetColor(mausac);
	cout<<str;	
	SetColor(7);
}	
void XuatNum(int x, int toaX, int toaY, int mausac )
{
	gotoxy(toaX,toaY);
	SetColor(mausac);
	cout<<x;	
	SetColor(7);
}
void VeKhung(int toaX, int toaY, int ngang, int doc, int mausac ,int mauBG)
{
	ShowCur(0);
	SetColor(mausac);
	SetBGColor(mauBG);
	gotoxy(toaX,toaY);
	for(int i=0;i<=ngang;i++)
	{
		
		if(i==0 ) {
			gotoxy(toaX+i,toaY);
			cout<<(char)218;
			gotoxy(toaX+i,toaY+doc);
			cout<<(char)192;
		}
		else if(i==ngang){
			gotoxy(toaX+i,toaY);
			cout<<(char)191;
			gotoxy(toaX+i,toaY+doc);
			cout<<(char)217;
		}
		else{
			gotoxy(toaX+i,toaY);
		 	cout<<(char)196;	
			gotoxy(toaX+i,toaY+doc);
			cout<<(char)196;	}
	}
	for(int i=1;i<=doc-1;i++)
	{
		gotoxy(toaX,toaY+i);
		cout<<(char)179;
		gotoxy(toaX+ngang,toaY+i);
		cout<<(char)179;
	}
}
void KhungText(string str, int toaX, int toaY,int ngang, int doc, int mausac)
{
	XuatText(str,toaX,toaY,mausac);
	VeKhung(toaX+str.length(),toaY-1, ngang, doc, mausac ,16);
}
void HuongDan(string str1 ,string str2 ,string str3)		
{
	XoaHCN(92,2,50,8);
	XuatText("HUONG DAN",114,2,13);
	XuatText(str1,118-(str1.length()/2),4,14);
	XuatText(str2,118-(str2.length()/2),6,14);
	XuatText(str3,118-(str3.length()/2),8,14);
}	
//==================CAC PHIM DUYET CO KIEU BOOL====================					
bool PhimDuyet(int toaX, int toaY)
{
	XuatText("Apply",toaX,toaY,1);
	VeKhung(toaX-1, toaY-1, 6, 2, 1,16 );
	XuatText("Cancel",toaX+15,toaY,1);
	VeKhung(toaX+14, toaY-1, 7, 2, 1 ,16);
	
	ShowCur(0);
	bool isApply=TRUE;
	XuatText("Apply",toaX,toaY,12);
		char chon;
		do{
			
			chon=getch();
			if (chon==0) chon = getch();
			switch(chon){
				case Right:if(isApply){
					XuatText("Apply",toaX,toaY,1);
					XuatText("Cancel",toaX+15,toaY,12);
					isApply=FALSE;
					
				}break;
				case Left:if(!isApply){
					XuatText("Cancel",toaX+15,toaY,1);
					XuatText("Apply",toaX,toaY,12);
					isApply=TRUE;
				
				}	break;
				case Enter:{
					return isApply;		
					}
				
			}
		}while(1);
	}

bool ThongBao(string str, string str2,int toaX, int toaY)
{
	ToMau(toaX,toaY,35,1,4);
	XuatText("Xac Nhan",toaX+15,toaY+1,71);
	ToMau(toaX,toaY+1,35,6,15);
	XuatText(str,(toaX+20)-str.length()/2,toaY+3,16);
	XuatText(str2,(toaX+20)-str2.length()/2,toaY+4,16);
	VeKhung(toaX+8, toaY+5, 5, 2, 9,15 );
	XuatText("YES",toaX+10,toaY+6,16);
	VeKhung(toaX+23, toaY+5, 5, 2, 9 ,15);
	XuatText("NO",toaX+25,toaY+6,16);
	ShowCur(0);
	bool isYes=TRUE;
	XuatText("YES",toaX+10,toaY+6,12);
	char chon;
	do{
			
		chon=getch();
		if (chon==0) chon = getch();
		switch(chon){
			case Right:if(isYes){
				XuatText("YES",toaX+10,toaY+6,16);
				XuatText("NO",toaX+25,toaY+6,12);
				isYes=FALSE;
				
			}break;
			case Left:if(!isYes){
				XuatText("NO",toaX+25,toaY+6,16);
				XuatText("YES",toaX+10,toaY+6,12);
				isYes=TRUE;
				
			}break;
			case Enter:{
				XoaHCN(toaX+1,toaY+1,34,6);
				return isYes;
			}
	}}while(1);
}
void BaoLoi(string str, string str2, int toaX,int toaY)
{
	ShowCur(0);
	ToMau(toaX,toaY,35,1,4);
	XuatText("Thong Bao",toaX+15,toaY+1,71);
	ToMau(toaX,toaY+1,35,5,15);
	XuatText(str,(toaX+20)-str.length()/2,toaY+3,16);
	XuatText(str2,(toaX+20)-str2.length()/2,toaY+4,16);
	getch();
	XoaHCN(toaX,toaY+1,35,5);
}
///========DO HOA CUA DOC GIA===============
void GiaoDienThemDocGia()
{
	
	XuatText("THEM DOC GIA",70,13,14);
	VeKhung(10, 14, 125, 24, 15 ,16);//khung them doc gia
	KhungText("Ho:",47,19,21, 2, 15 );
	KhungText("Ma The:",75,19,10, 2, 70 );
	KhungText("Ten:",46,23,15, 2, 15 );
	XuatText("Gioi Tinh:" , 40, 27,15 );
	gotoxy(53,27); cout<<"Nam   /    Nu";
	KhungText("Trang Thai The:" , 35, 31,15, 2, 70);
	XuatText("Apply",60,36,1);
	VeKhung(59, 35, 6, 2, 1,16 );
	XuatText("Cancel",75,36,1);
	VeKhung(74, 35, 7, 2, 1 ,16);
	SetColor(7);
	SetBGColor(0);
				}
void LoadGiaoDienThemDG()
{
	SetColor(0);
	gotoxy(52,19);cout<<"                     ";
	gotoxy(85,19);cout<<"          ";
	gotoxy(52,23);cout<<"               ";
	gotoxy(52,31);cout<<"               ";
	SetColor(7);
	gotoxy(53,27);cout<<"Nam   /    Nu";	
	XuatText("Apply",60,36,1);
	VeKhung(59, 35, 6, 2, 1,16 );
	XuatText("Cancel",75,36,1);
	VeKhung(74, 35, 7, 2, 1 ,16);
		}		
void GiaoDienXuat1Docgia(int mathe, string ho, string ten, string gioitinh, string trangthai)
{
	XoaHCN(10, 14, 125, 24);
	//======Load Giao Dien De Xuat Doc Gia Da Tim Duoc==========
	VeKhung(10, 14, 125, 24, 2 ,16);
	KhungText("Ho:",47,19,21, 2, 70 );
	XuatText(ho,52,19,15);
	KhungText("Ma The:",75,19,10, 2, 70 );
	XuatNum(mathe,85,19,15);
	KhungText("Ten:",46,23,15, 2, 70 );
	XuatText(ten,52,23,15);
	KhungText("Gioi Tinh:" , 40, 27,6, 2, 70 );
	XuatText(gioitinh,52,27,15);
	KhungText("Trang Thai The:" , 35, 31,15, 2, 70);
	XuatText(trangthai,52,31,15);
	XuatText("Apply",60,36,1);
	VeKhung(59, 35, 6, 2, 1,16 );
	XuatText("Cancel",75,36,1);
	VeKhung(74, 35, 7, 2, 1 ,16);
	}	
void GiaoDienXoaDocGia()
{
	XuatText("XOA DOC GIA",70,13,14);
	VeKhung(10, 14, 125, 24, 2 ,16);//khung xoa doc gia
	KhungText("Nhap ma the :",47,20,10, 2, 14 );
			}	
void GiaoDienHieuChinhDocGia()	
{
	ShowCur(0);
	XuatText("HIEU CHINH DOC GIA",65,13,14);
	VeKhung(10, 14, 125, 24, 2,16 );//khung hieu chinh doc gia
	KhungText("Nhap Ma Doc Gia:",55,17,10, 2, 14 );
	KhungText("Ho:",47,21,21, 2, 14 );
	KhungText("Ten:",46,25,15, 2, 14 );
	XuatText("Gioi Tinh:" , 40, 29,14 );
	gotoxy(53,29); cout<<"Nam   /    Nu";
	KhungText("Trang Thai The:" , 35, 33,15, 2, 70);
	XuatText("Apply",60,36,1);
	VeKhung(59, 35, 6, 2, 1,16 );
	XuatText("Cancel",75,36,1);
	VeKhung(74, 35, 7, 2, 1 ,16);
	}
void GiaoDienHieuChinh(string ho, string ten)
{
	KhungText("Ho:",47,21,21, 2, 14 );
	KhungText("Ten:",46,25,15, 2, 14 );
	XuatText(ho,52, 21,15);
	XuatText(ten,52, 25,15);
}
int LuaChonXuatDG(int &chon)/// 0: Xuat theo ma , 1: Xuat theo ten+ ho, 2:Theo tgian qua han giam dan
{
	char luachon[3][30]={
						"  Theo ma the tang dan     ",
						"  Theo ten + ho tang dan   ",
						"Theo tgian qua han giam dan"
						};
	ShowCur(0);
	SetBGColor(16);
	XuatText("XUAT DOC GIA",70,13,14);
	ToMau(55,15,40,3,10);
	XuatText("LUA CHON",72,17,14);
	ToMau(55,18,40,12,30);
	VeKhung(60,20,30, 2, 0,30);
	VeKhung(60,23,30, 2, 0,30);
	VeKhung(60,26,30, 2, 0,30);
	for(int i=0;i<3;i++)
	{
		gotoxy(62,21+i*3);cout<<luachon[i];
	}
	
	SetColor(1);
	gotoxy(62,21+chon*3);cout<<luachon[chon];
	char kytu;
	do{
			
		kytu=getch();
		if (kytu==0) kytu = getch();
		switch(kytu){
			case Down:if(chon<2){
				SetColor(0);
				gotoxy(62,21+chon*3);cout<<luachon[chon];
				++chon;
				SetColor(1);
				gotoxy(62,21+chon*3);cout<<luachon[chon];
				
			}break;
			case Up:if(chon>0){
				SetColor(0);
				gotoxy(62,21+chon*3);cout<<luachon[chon];
				--chon;
				SetColor(1);
				gotoxy(62,21+chon*3);cout<<luachon[chon];
				
			}break;
			case Enter:{
				return chon;
			}
			case Esc:{
				return -1;
			}
		}
	}while(1);	
}
void GiaoDienXuatPageDG(int soPage,int sl_docgia)
{
		//=========XUAT CAC TIEU DE=================
	ToMau(13,13,120,3,3);//to mau thanh tieu de
	XuatText("Ma The",16,15,16);
	XuatText("Ho va Ten",42,15,16);
	XuatText("Phai",74,15,16);
	XuatText("Trang Thai",86,15,16);
	XuatText("So Sach",105,14,16);
	XuatText("Dang Muon",104,15,16);
	XuatText("So Ngay",122,14,16);
	XuatText("Qua Han",122,15,16);
	ToMau(13,16,120,21,30);// to mau cho bang
	Normal();
	gotoxy(72,38);cout<<soPage<<"/"<<((sl_docgia%7==0)?(sl_docgia/7):(sl_docgia/7+1));// (so trang truy cap)/(tong so trang)
	//====================KE COT DOC=========================
	SetColor(16);
	SetBGColor(3);
	int vitri_kedoc[6]={23,70,80,100,115};//khoang cach cua tung cot doc a[i]->a[i+1]=a[i+1]-a[i]
	for(int i=0;i<5;i++)
	{
			
			for(int j=1;j<=3;j++)
			{
				gotoxy(vitri_kedoc[i],13+j);
				cout<<(char)179;// ky tu '|' 
			}	
	}
	SetColor(16);
	SetBGColor(30);
	for(int i=0;i<5;i++)
	{
		for(int j=1;j<=21;j++)
			{
				gotoxy(vitri_kedoc[i],16+j);
				cout<<(char)179;
			}
	}
	
	//======================KE COT NGANG=====================
	for(int i=19;i<=34;i+=3)//i=20,23,26,29,32,35 la vi tri cua cac cot ngang, cac cot lien tiep cach nhau 3
	{
		for(int j = 1 ; j <= 120 ; j++)
		{
			gotoxy(13+j,i);
			
			if(13+j==vitri_kedoc[0]||13+j==vitri_kedoc[1]||13+j==vitri_kedoc[2]||13+j==vitri_kedoc[3]||13+j==vitri_kedoc[4])//neu gotoxy den diem giao cach cua cot ngang va cot doc
			{
				cout<<(char)197;//xuat ky tu '+'
			}
			else cout << (char)196;//xuat ky tu '-'
		}
	}
}

void LoadPageDG(int soPage,int sl_docgia)
{
	int vitri_kedoc[6]={23,70,80,100,115};
	for(int i=17;i<=35;i+=3)
	{
		ToMau(14,i,8,1,30);
		ToMau(24,i,45,1,30);
		ToMau(71,i,8,1,30);
		ToMau(81,i,18,1,30);
		ToMau(101,i,13,1,30);
		ToMau(116,i,16,1,30);	
	}
	Normal();
	gotoxy(72,38);cout<<soPage<<"/"<<((sl_docgia%7==0)?(sl_docgia/7):(sl_docgia/7+1));// (so trang truy cap)/(tong so trang)
	SetBGColor(30);
}
//=======DO HOA CUA DAU SACH============ 
void GiaoDienThemSach()
{
	XuatText("THEM SACH",68,13,14);
	VeKhung(10, 14, 125, 24, 2 ,16);//khung them doc gia
	KhungText("Ten sach:",38,17,35, 2, 14 );
	KhungText("Ma ISBN:",87,17,20, 2, 70 );
	KhungText("Tac gia:",39,22,30, 2, 14 );
	KhungText("So trang:",86,22,8, 2, 14 );
	KhungText("The loai:" , 38, 27,19, 2, 14);
	KhungText("Nam xuat ban:" , 82, 27,10, 2, 14 );
	KhungText("So luong:" , 38, 32,8, 2, 14);
	KhungText("Vi tri:" , 88, 32,19, 2, 14);
	XuatText("Apply",60,36,1);
	VeKhung(59, 35, 6, 2, 1,16 );
	XuatText("Cancel",75,36,1);
	VeKhung(74, 35, 7, 2, 1 ,16);
	SetColor(7);
	SetBGColor(0);
}
int LuaChonXuatSach(string theloai[],int soluong,int &chon, int &doc,int &ngang)/// YES: Xuat theo ma , NO: Xuat theo ten+ ho
{
	int soPage=(ngang/5)+1;
	ToMau(58,15,35,3,10);
	XuatText("CAC THE LOAI",71,17,14);
	ToMau(58,18,35,13,30);
	VeKhung(59,19,34,12,10,30);
	
	for(int i=0;i<5 && (i+ngang)<soluong;i++)
	{
		XuatText(theloai[ngang+i],77-theloai[ngang+i].length()/2,20+i*2,0);
	}
	HighLight();
	gotoxy(77-theloai[chon].length()/2,20+doc);
	cout<<theloai[chon];	
	char kytu;
	do {
		SetColor(0);
	  	SetBGColor(30);
		gotoxy(75,30);cout<<soPage<<"/"<<((soluong%5==0)?(soluong/5):(soluong/5+1));
	  kytu = getch();
	  if (kytu==0) kytu = getch();
	  switch (kytu) {
	    case Up :if (doc-2>=0)
	  			  {
	  			  	SetColor(0);
	  			  	SetBGColor(30);
	              	gotoxy(77-theloai[chon].length()/2,20+doc);
	              	cout<<theloai[chon];
	              	doc-=2;
	              	chon--;
	              	HighLight();
	              	gotoxy(77-theloai[chon].length()/2,20+doc);
	              	cout<<theloai[chon];
	  				
	  			  }
	  			  break;
	  	case Right :if (ngang+5<soluong)
	  			  {
	  			  	soPage++;
	  			  	ToMau(60,19,32,10,30);
	  			  	doc=0;
					ngang=ngang+5;
					chon=ngang;
					for(int i=0;i<5 && (i+ngang)<=soluong;i++)
					{
						XuatText(theloai[ngang+i],77-theloai[ngang+i].length()/2,20+i*2,0);
					}
					HighLight();
					gotoxy(77-theloai[chon].length()/2,20+doc);
					cout<<theloai[chon];		
	  			  }
	  			  break; 
	  	case Left :if (ngang-5 >=0)
	  			  {
	  			  	soPage--;
					ToMau(60,19,32,10,30);
					ngang=ngang-5;
					doc=0;
					chon=ngang;
					for(int i=0;i<5 && (i+ngang)<soluong;i++)
					{
						XuatText(theloai[ngang+i],77-theloai[ngang+i].length()/2,20+i*2,0);
					}	
					HighLight();
					gotoxy(77-theloai[chon].length()/2,20+doc);
					cout<<theloai[chon];		
	  			  }
	  			  break; 
	  	case Down : if ((doc+2<=8) && (chon+1<soluong))
		  			 	 {
		  		        SetColor(0);
	  			  		SetBGColor(30);
		              	gotoxy(77-theloai[chon].length()/2,20+doc);
	              		cout<<theloai[chon];
		              	doc +=2;
		              	chon++;
		              	HighLight();
		              	gotoxy(77-theloai[chon].length()/2,20+doc);
	              		cout<<theloai[chon];
		  			  	}
	  			  break;
	  	case Enter :return chon;
	  	case Esc : return -1;
	  }  
	} while (1);	
}
void GiaoDienXuatPageDauS()
{
	ToMau(12,13,121,3,3);//to mau thanh tieu de
	XuatText("Ma ISBN",17,15,16);
	XuatText("Ten dau sach",43,15,16);
	XuatText("So",71,14,16);
	XuatText("trang",70,15,16);
	XuatText("Tac gia",88,15,16);
	XuatText("Nam",112,14,16);
	XuatText("xuat ban",110,15,16);
	XuatText("So luong",122,15,16);
	ToMau(12,16,121,21,30);// to mau cho bang
	Normal();
	//====================KE COT DOC=========================
	SetColor(16);
	SetBGColor(3);
	int vitri_kedoc[6]={30,69,75,108,118};//khoang cach cua tung cot doc a[i]->a[i+1]=a[i+1]-a[i]
	for(int i=0;i<5;i++)
	{
			
			for(int j=1;j<=3;j++)
			{
				gotoxy(vitri_kedoc[i],13+j);
				cout<<(char)179;// ky tu '|' 
			}	
	}
	SetColor(16);
	SetBGColor(30);
	for(int i=0;i<5;i++)
	{
		for(int j=1;j<=21;j++)
			{
				gotoxy(vitri_kedoc[i],16+j);
				cout<<(char)179;
			}
	}
	
	//======================KE COT NGANG=====================
	for(int i=19;i<=34;i+=3)//i=20,23,26,29,32,35 la vi tri cua cac cot ngang, cac cot lien tiep cach nhau 3
	{
		for(int j = 1 ; j <= 120 ; j++)
		{
			gotoxy(12+j,i);
			
			if(12+j==vitri_kedoc[0]||12+j==vitri_kedoc[1]||12+j==vitri_kedoc[2]||12+j==vitri_kedoc[3]||12+j==vitri_kedoc[4])//neu gotoxy den diem giao cach cua cot ngang va cot doc
			{
				cout<<(char)197;//xuat ky tu '+'
			}
			else cout << (char)196;//xuat ky tu '-'
		}
	}
}
void Page10DauSLuotMuonMax()
{
	ToMau(10,14,123,3,3);//to mau thanh tieu de
	XuatText("Ma ISBN",17,16,16);
	XuatText("Ten dau sach",43,16,16);
	XuatText("So",73,15,16);
	XuatText("trang",72,16,16);
	XuatText("Tac gia",88,16,16);
	XuatText("Nam",114,15,16);
	XuatText("xuat ban",112,16,16);
	XuatText("So",125,15,16);
	XuatText("Luot muon",122,16,16);
	ToMau(10,17,123,20,30);// to mau cho bang
	Normal();
	//====================KE COT DOC=========================
	SetColor(16);
	SetBGColor(3);
	int vitri_kedoc[6]={32,71,77,110,120};//khoang cach cua tung cot doc a[i]->a[i+1]=a[i+1]-a[i]
	for(int i=0;i<5;i++)
	{
			
			for(int j=1;j<=3;j++)
			{
				gotoxy(vitri_kedoc[i],14+j);
				cout<<(char)179;// ky tu '|' 
			}	
	}
	SetColor(16);
	SetBGColor(30);
	for(int i=0;i<5;i++)
	{
		for(int j=1;j<=20;j++)
			{
				gotoxy(vitri_kedoc[i],17+j);
				cout<<(char)179;
			}
	}
	
	//======================KE COT NGANG=====================
	for(int i=19;i<=36;i+=2)//i=20,23,26,29,32,35 la vi tri cua cac cot ngang, cac cot lien tiep cach nhau 3
	{
		for(int j = 1 ; j <= 122 ; j++)
		{
			gotoxy(10+j,i);
			
			if(10+j==vitri_kedoc[0]||10+j==vitri_kedoc[1]||10+j==vitri_kedoc[2]||10+j==vitri_kedoc[3]||10+j==vitri_kedoc[4])//neu gotoxy den diem giao cach cua cot ngang va cot doc
			{
				cout<<(char)197;//xuat ky tu '+'
			}
			else cout << (char)196;//xuat ky tu '-'
		}
	}
}
void GiaoDienTimSach()
{
	SetBGColor(0);
	XuatText("TIM SACH",70,13,14);
	VeKhung(10, 14, 125, 24, 2 ,16);//khung xoa doc gia
	KhungText("Ten sach:",47,18,35, 2, 14 );
}	
void GiaoDienXuat1DauS(string maISBN, string tensach, string tacgia, int namxb, string theloai)
{
	XoaHCN(10, 14, 125, 24);
	//======Load Giao Dien De Xuat Doc Gia Da Tim Duoc==========
	VeKhung(10, 14, 125, 24, 2 ,16);
	KhungText("Ten sach:",38,16,35, 2, 70 );
	XuatText(tensach,49,16,31);
	KhungText("Ma ISBN:",87,16,20, 2, 70 );
	XuatText(maISBN,96,16,31);
	KhungText("Tac gia:",39,19,30, 2, 70 );
	XuatText(tacgia,49,19,31);
	KhungText("The loai:" , 86, 19,19, 2, 70);
	XuatText(theloai,96,19,31);
	KhungText("Nam xuat ban:" , 34, 22,10, 2, 70 );
	XuatNum(namxb,50,22,31);

//=====KE BANG===============
	ToMau(38,23,60,3,3);//to mau thanh tieu de
	XuatText("Ma sach",48,24,0);
	XuatText("Trang thai",65,24,0);
	XuatText("Vi tri",88,24,0);
	ToMau(38,25,60,11,30);// to mau cho bang
	SetColor(16);
	SetBGColor(3);
	int vitri_kedoc[]={60,80};//khoang cach cua tung cot doc a[i]->a[i+1]=a[i+1]-a[i]
	for(int i=0;i<2;i++)
	{
			
			for(int j=1;j<=3;j++)
			{
				gotoxy(vitri_kedoc[i],23+j);
				cout<<(char)179;// ky tu '|' 
			}	
	}
	SetColor(16);
	SetBGColor(30);
	for(int i=0;i<2;i++)
	{
		for(int j=1;j<=11;j++)
			{
				gotoxy(vitri_kedoc[i],25+j);
				cout<<(char)179;
			}
	}
	
	//======================KE COT NGANG=====================
	for(int i=28;i<=34;i+=3)//i=20,23,26,29,32,35 la vi tri cua cac cot ngang, cac cot lien tiep cach nhau 3
	{
		for(int j = 39 ; j <= 98 ; j++)
		{
			gotoxy(j,i);
			
			if(j==vitri_kedoc[0]||j==vitri_kedoc[1])//neu gotoxy den diem giao cach cua cot ngang va cot doc
			{
				cout<<(char)197;//xuat ky tu '+'
			}
			else cout << (char)196;//xuat ky tu '-'
		}
	}
	}	
void LoadPageXuat1DauS()
{
	for(int i=0;i<4;i++)
	{
		ToMau(39,26+i*3,20,1,30);
		ToMau(61,26+i*3,18,1,30);
		ToMau(81,26+i*3,17,1,30);
	}
}
void PageMuonTra(int toaX,int toaY)
{
	XuatText("Danh Sach Cac Sach Doc Gia Dang Muon",toaX+16,toaY,6);
	ToMau(toaX,toaY,68,3,3);//to mau thanh tieu de
	XuatText("Ma sach",toaX+8,toaY+2,0);
	XuatText("Ten Sach",toaX+32,toaY+2,0);
	XuatText("Thoi gian",toaX+54,toaY+2,0);
	ToMau(toaX,toaY+3,68,5,30);// to mau cho bang
	SetColor(16);
	SetBGColor(3);
	int vitri_kedoc[]={toaX+23,toaX+53};//khoang cach cua tung cot doc a[i]->a[i+1]=a[i+1]-a[i]
	for(int i=0;i<2;i++)
	{
			
			for(int j=1;j<=3;j++)
			{
				gotoxy(vitri_kedoc[i],toaY+j);
				cout<<(char)179;// ky tu '|' 
			}	
	}
	SetColor(16);
	SetBGColor(30);
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<5;j++)
			{
				gotoxy(vitri_kedoc[i],toaY+4+j);
				cout<<(char)179;
			}
	}
	
	//======================KE COT NGANG=====================
	for(int i=toaY+5;i<=toaY+7;i+=2)
	{
		for(int j = toaX+1 ; j <= toaX+68 ; j++)
		{
			gotoxy(j,i);
			
			if(j==vitri_kedoc[0]||j==vitri_kedoc[1])//neu gotoxy den diem giao cach cua cot ngang va cot doc
			{
				cout<<(char)197;//xuat ky tu '+'
			}
			else cout << (char)196;//xuat ky tu '-'
		}
	}
}
void GiaoDienMuonSach(string tenDG,int mathe, int trangthai)
{
	KhungText("Doc Gia:",19,16,30,2,70);
	XuatText(tenDG,29,16,15);
	KhungText("Ma The:",20,19,8,2,70);
	XuatNum(mathe,29,19,15);
	KhungText("Trang Thai The:",12,22,7,2,70);
	XuatNum(trangthai,29,22,15);
	
	KhungText("Ma Sach:",92,16,30,2,15);
	KhungText("Ten Sach:",91,19,30,2,70);
	KhungText("Trang Thai:",89,22,15,2,70);
	KhungText("Thoi Gian:",90,25,15,2,70);
	
	
	
}
void GiaoDienTraSach(string tenDG,int mathe, int trangthai,  int sl_sachmuon)
{
	KhungText("Doc Gia:",12,16,30,2,70);
	XuatText(tenDG,22,16,15);
	KhungText("Ma The:",13,19,8,2,70);
	XuatNum(mathe,22,19,15);
	KhungText("Trang Thai The:",30,19,16,2,70);
	XuatNum(trangthai,47,19,15);
	KhungText("So Sach Muon:",7,22,7,2,70);
	XuatNum(sl_sachmuon,21,22,15);

	KhungText("Ma Sach:",94,16,30,2,15);
	KhungText("Ten Sach:",93,19,30,2,70);
	KhungText("Thoi Gian:",92,22,15,2,70);
	KhungText("Trang Thai:",91,25,18,2,15);
//	int toaX=10,toaY=26;
//	XuatText("Danh Sach Cac Sach Doc Gia Dang Muon",toaX+16,toaY,6);
//	PageMuonTra(toaX,toaY);
}
void GiaoDienChinh()
{
	
	resizeConsole(1080, 720);
	SetBGColor(16);
	system("cls");
	ShowCur(0);
	//VeHCN(2,0,144,8,8);
	
	VeHCN(2,1,141,10,11);//Khung Logo
	LogoThuVien(2,3);
	
	VeHCN(91,1,52,10,11);//HCN huong dan
	
	VeHCN(2,1,141,39,11);// khung Main menu
	VeKhung(4, 12, 137, 27, 2 ,16);//khung phu
	SetBGColor(16);
	//ShowCur(0);
}
