
void ThemDanhSachSachMuonTraTuFile(TREE& t, int x, ifstream& FileIn, MCONTRO& DauS)
{
	if (t == NULL)
	{
		return;
	}
	else if (t->data.ma_the == x)
	{
		NODE_MUON_TRA* p = new NODE_MUON_TRA;
		if (p == NULL)
		{
			ThongBao("Cap nhap that bai","Enter de thoat",55,21);
			return;
		}
		getline(FileIn, p->data.ma_sach, ',');
		FileIn >> p->data.ngay_muon.Ngay;
		FileIn.ignore();
		
		FileIn >> p->data.ngay_muon.Thang;
		FileIn.ignore();
		
		FileIn >> p->data.ngay_muon.Nam;
		FileIn.ignore();
		
		FileIn >> p->data.ngay_tra.Ngay;
		FileIn.ignore();
		
		FileIn >> p->data.ngay_tra.Thang;
		FileIn.ignore();
		
		FileIn >> p->data.ngay_tra.Nam;
		FileIn.ignore();
		
		FileIn >> p->data.trang_thai;
		if (p->data.trang_thai == 0)
		{
			t->data.SoSachDangMuon++;
		}
		else if (p->data.trang_thai == 3)
		{
			t->data.trang_thai = 0;
		}
		p->right = NULL;
		p->left = NULL;

		for (int i = 0; i < DauS.SoluongdauS; i++)
		{
			if (TachLayMaDauSach(p->data.ma_sach) == DauS.nodesDauSach[i]->ISBN)
			{
				for (Node_Dms* k = DauS.nodesDauSach[i]->dms; k != NULL; k = k->next)
				{
					if (p->data.ma_sach == k->data.ma_sach)
					{
						DauS.nodesDauSach[i]->so_lan_muon++;
						if (p->data.trang_thai == 0) // dang muon
						{
							k->data.trang_thai = 1; //da co doc gia muon
						}
						else if (p->data.trang_thai == 2 ||p->data.trang_thai == 3 )// lam mat
						{
							k->data.trang_thai = 2; //da thanh li
						}
						break;
					}
				}
				break;
			}
		}
		
		if (t->data.DS_MuonTra.First == NULL)
		{
			t->data.DS_MuonTra.First = t->data.DS_MuonTra.Last = p;
		}
		else
		{
			t->data.DS_MuonTra.Last->right = p;
			p->left = t->data.DS_MuonTra.Last;
			t->data.DS_MuonTra.Last = p;
		}
		return;
	}
	else if (t->data.ma_the > x)
	{
		ThemDanhSachSachMuonTraTuFile(t->pLeft, x, FileIn, DauS);
	}
	else
	{
		ThemDanhSachSachMuonTraTuFile(t->pRight, x, FileIn, DauS);
	}
}
void LoadFileDanhSachSachMuonTra(TREE& t, MCONTRO& DauS)
{
	int x;
	ifstream FileIn;
	FileIn.open("DanhSachMuonTra.TXT", ios::in);
	while (1)
	{
		x = 0;
		FileIn >> x;
		FileIn.ignore();
		//FileIn.seekg(1, ios::cur);
		if (x == 0)
		{
			break;
		}
		ThemDanhSachSachMuonTraTuFile(t, x, FileIn, DauS);
		if (FileIn.eof())
		{
			break;
		}
	}
	FileIn.close();
}

int DoiThangSangSo(string str)
{
	if (str == "Jan")
	{
		return 1;
	}
	else if (str == "Feb")
	{
		return 2;
	}
	else if (str == "Mar")
	{
		return 3;
	}
	else if (str == "Apr")
	{
		return 4;
	}
	else if (str == "May")
	{
		return 5;
	}
	else if (str == "Jun")
	{
		return 6;
	}
	else if (str == "Jul")
	{
		return 7;
	}
	else if (str == "Aug")
	{
		return 8;
	}
	else if (str == "Sep")
	{
		return 9;
	}
	else if (str == "Oct")
	{
		return 10;
	}
	else if (str == "Nov")
	{
		return 11;
	}
	else if (str == "Dec")
	{
		return 12;
	}
}
void LayNgayHienTai(Date& d)
{
	// tra ve date/time hien tai dua tren system hien tai
	time_t hientai = time(0);
	// chuyen doi hientai thanh dang chuoi
	char* dt = ctime(&hientai);
	string str1, str2, str3;
	//ngay
	for (int i = 8; i < 10; i++)
	{
		str1.push_back(dt[i]);
	}
	d.Ngay = atoi(str1.c_str());
	// thang
	for (int i = 4; i < 7; i++)
	{
		str2.push_back(dt[i]);
	}
	d.Thang = DoiThangSangSo(str2);
	//nam
	for (int i = 20; i < 24; i++)
	{
		str3.push_back(dt[i]);
	}
	d.Nam = atoi(str3.c_str());
}
// Xu Ly Ngay
bool KTNamNhuan(int nam)
{
	if ((nam % 4 == 0 && nam % 100 != 0) || nam % 400 == 0)
	{
		return true;
	}
	else
		return false;
}
	// 1:ngay > ngay1; 2:ngay < ngay1; 3:ngay=ngay1
int SoSanhNgay(Date d, Date t) 
{
	if (d.Nam == t.Nam)
	{
		if (d.Thang == t.Thang)
		{
			if (d.Ngay > t.Ngay)
			{
				return 1;
			}
			else if (d.Ngay < t.Ngay)
			{
				return 2;
			}
			else
				return 3;
		}
		else if (d.Thang > t.Thang)
		{
			return 1;
		}
		else
			return 2;
	}
	else if (d.Nam > t.Nam)
	{
		return 1;
	}
	else
	{
		return 2;
	}
}
int SoNgayCuaThang(int thang)
{
	if (thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 8 || thang == 10 || thang == 12)
	{
		return 31;
	}
	else if (thang == 2)
	{
		if (KTNamNhuan)
		{
			return 29;
		}
		else
			return 28;
	}
	else
		return 30;
}
int SoNgayQuaHan(Date d)
{
	Date d1;
	LayNgayHienTai(d1);
	if (SoSanhNgay(d1, d) == 1)
	{
		if (d.Nam == d1.Nam)
		{
			if (d.Thang == d1.Thang)
			{
				return d1.Ngay - d.Ngay;
			}
			else
			{
				return SoNgayCuaThang(d.Thang) - d.Ngay + d1.Ngay;
			}
		}
		else
		{
			int SoNgayConLaiCuaNam = 0;
			for (int i = 1; i < d.Thang; i++)
			{
				SoNgayConLaiCuaNam = SoNgayConLaiCuaNam + i * SoNgayCuaThang(i);
			}
			if (KTNamNhuan(d.Nam))
			{
				return 366 - SoNgayConLaiCuaNam - d.Ngay + d1.Ngay;
			}
			else
			{
				return 365 - SoNgayConLaiCuaNam - d.Ngay + d1.Ngay;
			}
		}
	}
	else
		return 0;
}
Date CongNgay(Date t,int SoNgay)
{
	Date d = t;
	d.Ngay = d.Ngay + SoNgay;
	if (d.Ngay > SoNgayCuaThang(d.Thang))
	{
		if (d.Thang == 12)
		{
			d.Thang = 1;
			d.Nam = d.Nam + 1;
		}
		else
		{
			d.Thang = d.Thang + 1;
		}
		d.Ngay = d.Ngay - SoNgayCuaThang(t.Thang);
	}
	return d;
}
string TrangThaiMuonTra(int n)
{
	if (n == 0)
		return "Dang Muon";
	else if (n == 1)
		return "Da Tra";
	else if (n == 2)
		return "Da Mat(Da Den)";
	else if (n == 3)
		return "Da Mat(Chua Den)";
}
// Kiem Tra Qua Han
void KiemTraQuaHan1DocGia(TREE &t, Date NgayHienTai)
{
	bool KTKhoaDG=false;
	Date Max;
	LayNgayHienTai(Max);
	for (NODE_MUON_TRA *k = t->data.DS_MuonTra.First; k != NULL; k = k->right)
	{
		if (k->data.trang_thai == 0 && SoSanhNgay(NgayHienTai, CongNgay(k->data.ngay_muon,SoNgayDcMuon)) == 1)
		{
			KTKhoaDG = true;
			t->data.trang_thai = 0;
			if (SoSanhNgay(Max, k->data.ngay_muon) == 1)
			{
				Max = k->data.ngay_muon;
			}
		}
		else if (k->data.trang_thai == 3)
		{
			KTKhoaDG = true;
			t->data.trang_thai = 0;
		}
	}
	if (KTKhoaDG == false)
	{
		t->data.trang_thai = 1;
		t->data.SoNgayQuaHan = 0;
	}
	else
		t->data.SoNgayQuaHan = SoNgayQuaHan(CongNgay(Max,SoNgayDcMuon));
}
void KiemTraQuaHan(TREE& t, Date NgayHienTai)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		Date Max;
		LayNgayHienTai(Max);
		for (NODE_MUON_TRA *k = t->data.DS_MuonTra.First; k != NULL; k = k->right)
		{
			if (k->data.trang_thai == 0 && SoSanhNgay(NgayHienTai, CongNgay(k->data.ngay_muon,SoNgayDcMuon)) == 1)
			{
				t->data.trang_thai = 0;
				if (SoSanhNgay(Max, k->data.ngay_muon) == 1)
				{
					Max = k->data.ngay_muon;
				}
			}
			else if (k->data.trang_thai == 3)
			{
				t->data.trang_thai = 0;
			}
		}
		t->data.SoNgayQuaHan = SoNgayQuaHan(CongNgay(Max,SoNgayDcMuon));

		KiemTraQuaHan(t->pLeft, NgayHienTai);
		KiemTraQuaHan(t->pRight, NgayHienTai);
	}
}
bool TimDanhMuc(MCONTRO DauS,string masach,Node_Dms *&sachmuon, DauSach *&dauSmuon)
{
	for(int i=0;i<DauS.SoluongdauS;i++)
	{
		if(TachLayMaDauSach(masach)==DauS.nodesDauSach[i]->ISBN)
		{
			int kt=(masach[18]-'0')*10+(masach[19]-'0');//lay hai so cuoi cua ma sach dua ve int
			if( kt>0 && kt<=DauS.nodesDauSach[i]->so_luong_sach)// neu hai so cuoi thuoc [0, so danh muc sach] thi sach co ton tai
			{
				dauSmuon=DauS.nodesDauSach[i];
				for(Node_Dms* k=DauS.nodesDauSach[i]->dms;k!=NULL; k=k->next)
				{
					
					if(k->data.ma_sach==masach)
					{
						sachmuon=k;
						return 1;
					}
				}
			}
			else return 0;
		}
	}
	return 0;
}

void XuLyMuonSach(TREE &t,DauSach *dauSmuon,Node_Dms *dms,Date Ngay)
{
	t->data.SoSachDangMuon++;
	dms->data.trang_thai = 1;
	dauSmuon->so_lan_muon++;
	NODE_MUON_TRA* p = new NODE_MUON_TRA;
	if (p == NULL)
	{
		ThongBao("Cap phat that bai !","",55,21);
		return;
	}
	p->data.ma_sach = dms->data.ma_sach;
	p->data.ngay_muon=Ngay;
	p->data.ngay_tra.Ngay = 0;;
	p->data.ngay_tra.Thang = 0;
	p->data.ngay_tra.Nam = 0;
	p->data.trang_thai = 0;
	p->right = NULL;
	p->left = NULL;

	if (t->data.DS_MuonTra.First== NULL)
	{
		t->data.DS_MuonTra.First = p;
		t->data.DS_MuonTra.Last = p;
	}
	else
	{
		t->data.DS_MuonTra.Last->right = p;
		p->left = t->data.DS_MuonTra.Last;
		t->data.DS_MuonTra.Last = p;
	}
}

void MuonSach(TREE &t, MCONTRO & DauS,bool &Thoat)
{
	XuatText("MUON SACH",70,13,14);
	
	if (DauS.SoluongdauS == 0)
	{
		if (DauS.SoluongdauS == 0)
		{
			BaoLoi("Thu vien chua co sach nao","",55,21);
			Thoat=TRUE;
			return;
		}
	}
		// tat ca cac sach da cho muon
	bool KTSach = false; // kiem tra coi tat ca cac sach da cho muon chua
	for (int i = 0; i < DauS.SoluongdauS; i++)
	{
		for (LIST_DMS k = DauS.nodesDauSach[i]->dms; k != NULL; k = k->next)
		{
			if (k->data.trang_thai == 0)
			{
				KTSach = true;
				
				break;
			}
		}
		if (KTSach == true)
		{
			break;
		}
	}
	if (KTSach == false)
	{
		BaoLoi("Sach da duoc muon het","",55,21);
		Thoat=TRUE;
		return;
	}	
	
	KhungText("Nhap ma the :",47,20,10, 2, 14 );
	int maDG;
	TREE p=NULL;
NhapmaDG:
	HuongDan("Vui long nhap dung ma the", "Enter - tim ket qua", "Nhan ESC - Thoat");
	XuLiNhapSo(62,20,maDG,5,Thoat);
	if(Thoat){
		Thoat=ThongBao("","Ban co muon thoat",55,21);
		if(Thoat){
			return;
		}else{
			gotoxy(62,20);cout<<"      ";
			goto NhapmaDG;
		} 
	}
	if (maDG == 0)
	{
		gotoxy(62,20);cout<<"      ";
		goto NhapmaDG;
	}
	
	p=TimDocGia(t, maDG);
	if(p==NULL)
	{
		BaoLoi("Ma khong ton tai","Hay nhap lai",55,21);
		gotoxy(62,20);cout<<"      ";
		goto NhapmaDG;
	}
		//du dieu kien muon
	if (p->data.SoSachDangMuon < 3 && p->data.trang_thai == 1)//sl sach dang muon <3 va trang thai =1
	{
		///===Xuat cac sach doc gia dang muon====
		Date ngayhientai;
		LayNgayHienTai(ngayhientai);
		XoaHCN(46,19,25,4);
		GiaoDienMuonSach(p->data.ho+" "+p->data.ten,p->data.ma_the,p->data.trang_thai);
		XuatPageMuonSach(DauS,p->data.DS_MuonTra,10,26);
			
		Normal();//Xuat thoi gian hien tai
		gotoxy(102,25);cout<<ngayhientai.Ngay<<"/"<<ngayhientai.Thang<<"/"<<ngayhientai.Nam;
		string masach;
Nhapmasach:
		XoaHCN(101,19,28,0);
		XoaHCN(101,22,13,0);
		HuongDan("Hay nhap ma sach de muon", "Enter - tim ket qua", "Nhan ESC - Thoat");	
		NhapMaSach(102, 16,masach,20,Thoat);
		if(Thoat){
		Thoat=ThongBao("","Ban co muon thoat",50,18);
		if(Thoat){
			XoaHCN(10, 14, 125, 24);
			KhungText("Nhap ma the :",47,20,10, 2, 14 );
			Thoat=FALSE;
			goto NhapmaDG;
		}else{
				gotoxy(62,20);cout<<"      ";
				goto Nhapmasach;
			} 
		}
		
		if (masach.empty())
		{
			goto Nhapmasach;//quay lai nhap ma
		}
			// Ma Sach Ok
		DauSach* dauSmuon=NULL;
		Node_Dms* sachmuon=NULL;
		if (TimDanhMuc(DauS, masach, sachmuon, dauSmuon))
		{
			XuatText(dauSmuon->ten_sach,102,19,70);
			XuatText(TrangThaiSach(sachmuon->data.trang_thai),102,22,70);
			for (NODE_MUON_TRA* k = p->data.DS_MuonTra.First; k != NULL; k = k->right)
			{
				//Doc Gia Dang Muon Sach Nay Roi
				if (k->data.trang_thai == 0 && TachLayMaDauSach(k->data.ma_sach)== TachLayMaDauSach(masach))
				{
					BaoLoi("Doc Gia Dang Muon Sach Nay","Hay nhap sach khac",50,18);
					goto Nhapmasach;
				}
				//Doc Gia Vua Tra Sach Nay
				else if ((k->data.trang_thai == 1||k->data.trang_thai==2) && TachLayMaDauSach(k->data.ma_sach)== TachLayMaDauSach(masach) && SoSanhNgay(k->data.ngay_tra,ngayhientai)==3)
				{
					BaoLoi("Doc Gia Vua Tra Sach Nay","",50,18);
					goto Nhapmasach;
				}
			}

			//TH: Sach Dc Muon
			if (sachmuon->data.trang_thai == 0)
			{
				
				
				Thoat=PhimDuyet(102,28);
				if(!Thoat){
					goto Nhapmasach;
				}else{
					XuLyMuonSach(p, dauSmuon,sachmuon,ngayhientai);
					BaoLoi("","Muon Thanh Cong",50,18);
					SaveToFile(t);	
					XoaHCN(5, 13, 135, 25);
					KhungText("Nhap ma the :",47,20,10, 2, 14 );
					Thoat=FALSE;
					
					goto NhapmaDG;
				}
				
				
						
			}
			//TH: Sach Thanh Li
			else if(sachmuon->data.trang_thai == 2)
			{
				BaoLoi("Sach Nay Da Thanh Li", "",50,18);
				goto Nhapmasach;
			}
			//TH: Sach Dang Dc Muon
			else
			{
				BaoLoi("Sach Nay Da Dc Muon","",50,18);
				goto Nhapmasach;
			}
		}
		// Ma Sach Khong Ton Tai
		else
		{
			BaoLoi("Ma Sach Khong Ton Tai","",52,18);
			goto Nhapmasach;
		}
	} 
	else {
		BaoLoi("Doc Gia Khong Du ","Dieu Kien Muon Sach !",55,21);
		gotoxy(62,20);cout<<"      ";
		goto NhapmaDG;
	}
}
void XuLiTraSach(MuonTra &Mt, MCONTRO &DauS)
{
	for (int i = 0; i < DauS.SoluongdauS; i++)
	{
		if (TachLayMaDauSach(Mt.ma_sach) == DauS.nodesDauSach[i]->ISBN)
		{
			for (Node_Dms* k = DauS.nodesDauSach[i]->dms; k != NULL; k = k->next)
			{
				if (Mt.ma_sach == k->data.ma_sach)
				{
					if (Mt.trang_thai == 1)
					{
						k->data.trang_thai = 0;
					}
					else if (Mt.trang_thai == 2|| Mt.trang_thai == 3)
					{
						k->data.trang_thai = 2;
					}
					break;
				}
			}
			break;
		}
	}
	
} 
int ChonTrangThai(int trangthai, int toaX, int toaY)
{
	char luachon[3][20]={	"     Da Tra     ",
							" Da Mat(da den) ",
							"Da Mat(chua den)"
						};
	SetBGColor(0);
	XuatText(luachon[0],toaX,toaY,15);
	SetColor(0);
	SetBGColor(15);
	
	ShowCur(0);
	for(int i=0;i<3;i++)
	{
		Sleep(50);
		gotoxy(toaX-1,toaY+2+i);
		cout<<luachon[i];
	}
	SetColor(12);
	gotoxy(toaX-1,toaY+2);cout<<luachon[0];
	int chon=0;
	char nhap;
	while(1)
	{
		SetBGColor(15);
		nhap=getch();
		if(nhap==-32){
			nhap=getch();
			if(nhap==80 && chon<2){
				SetColor(0);
				gotoxy(toaX-1,toaY+2+chon);cout<<luachon[chon];
				++chon;
				SetColor(12);
				gotoxy(toaX-1,toaY+2+chon);cout<<luachon[chon];
				SetBGColor(0);
				XuatText(luachon[chon],toaX,toaY,15);
			}
			if(nhap==72 && chon>0){
				SetColor(0);
				gotoxy(toaX-1,toaY+2+chon);cout<<luachon[chon];
				--chon;
				SetColor(12);
				gotoxy(toaX-1,toaY+2+chon);cout<<luachon[chon];
				SetBGColor(0);
				XuatText(luachon[chon],toaX,toaY,15);
			}
		}
		if(nhap==27) return trangthai;
		if(nhap==13) return chon+1;
	}
	
}
void TraSach(TREE &t, MCONTRO & DauS, bool &Thoat)
{
	XuatText("TRA SACH",72,13,14);
	int maDG = 0;
	TREE p ;
NhapmaDG2:
	HuongDan("Vui long nhap dung ma the", "Enter - tim ket qua", "Nhan ESC - Thoat");		
	KhungText("Nhap ma the :",47,20,10, 2, 14 );
	XuLiNhapSo(62,20,maDG,5,Thoat);
	if(Thoat){
		Thoat=ThongBao("","Ban co muon thoat",55,21);
		if(Thoat){
			return;
		}else{
			gotoxy(62,20);cout<<"      ";
			goto NhapmaDG2;
		} 
	}
	if (maDG == 0)
	{
		goto NhapmaDG2;
	}
	

	p=TimDocGia(t, maDG);
	if(p==NULL)
	{
		BaoLoi("Ma khong ton tai","Hay nhap lai",55,21);
		gotoxy(62,20);cout<<"      ";
		goto NhapmaDG2;
	}
	
	bool ktSach=FALSE;//kiem tra co sach muon hay sach mat ko
	NODE_MUON_TRA* MTtam[3];
	int z = 0;
	for (NODE_MUON_TRA* k = p->data.DS_MuonTra.First; k != NULL; k = k->right)
	{
		if (k->data.trang_thai == 0 )
		{
			MTtam[z++] = k;
			ktSach=TRUE;
		}
	}
	if(!ktSach)
	{
		BaoLoi("Doc Gia Khong Co","Sach Tra",55,21);
		gotoxy(62,20);cout<<"      ";
		goto NhapmaDG2;	
	}

	
	Date ngayhientai;
	LayNgayHienTai(ngayhientai);
	XoaHCN(46,19,25,4);
	GiaoDienTraSach(p->data.ho+" "+p->data.ten,p->data.ma_the,p->data.trang_thai,p->data.SoSachDangMuon);
	//====Xuat Sach Muon======
	XuatPageMuonSach(DauS, p->data.DS_MuonTra,10,26);
	
	//Xuat thoi gian hien tai
	Normal();
	gotoxy(103,22);
	cout<<ngayhientai.Ngay<<"/"<<ngayhientai.Thang<<"/"<<ngayhientai.Nam;
	
	string masach;
Nhapmasach2:
	XoaHCN(103,19,28,0);
	XoaHCN(103,25,13,0);
	HuongDan("Hay nhap sach dang muon", "Enter - tim ket qua", "Nhan ESC - Thoat");	
	NhapMaSach(104, 16,masach,20,Thoat);
	if(Thoat){
	Thoat=ThongBao("","Ban co muon thoat",53,16);
	if(Thoat){
		XoaHCN(5, 13, 135, 25);
		VeKhung(10, 14, 125, 24, 2 ,16);//khung xoa doc gia
		KhungText("Nhap ma the :",47,20,10, 2, 14 );
		Thoat=FALSE;
		goto NhapmaDG2;
	}else{
			gotoxy(62,20);cout<<"      ";
			goto Nhapmasach2;
		} 
	}	
	if (masach.empty())
	{
		goto Nhapmasach2;//quay lai nhap ma
	}
	for(int i=0;i<z;i++)
	{
		if(masach==MTtam[i]->data.ma_sach)
		{
			XuatText(LayTenSach(DauS,masach),104,19,70);
			int trangthaitam=ChonTrangThai(MTtam[i]->data.trang_thai,103,25);
			Thoat=PhimDuyet(104,33);
				if(!Thoat){
					goto Nhapmasach2;
				}else{
					//==cap nhap ngay tra
					MTtam[i]->data.ngay_tra=ngayhientai;
					MTtam[i]->data.trang_thai=trangthaitam;
					
					//====xu li tra sach
					XuLiTraSach(MTtam[i]->data, DauS);
					
					//===cap nhap so sach muon va trang thai cua cay
					KiemTraQuaHan1DocGia(p, ngayhientai);
					p->data.SoSachDangMuon--;
					BaoLoi("","Tra Sach Thanh Cong",53,16);
					SaveToFile(t);	
					
					XoaHCN(5, 13, 135, 25);
					KhungText("Nhap ma the :",47,20,10, 2, 14 );
					Thoat=FALSE;
					goto NhapmaDG2;
				}
		}
	}	
	BaoLoi("Doc Gia Khong","Muon Sach Nay",53,16);	
	goto Nhapmasach2;
}//=========Cau j==========
bool KiemTraTrung(DauSach ds[], string str, int n)
{
	for(int i = n-1 ; i>=0;i--)
	{
		if(ds[i].ten_sach == str)
		{
			return TRUE;
		}
	}
	return FALSE;
}
void Xuat10DauSach(DauSach ds[],int n)
{
	Page10DauSLuotMuonMax();
	int k=18;
	for(int i = 0 ; i < n ; i++)
	{
		XuatText(ds[i].ISBN,12,k,0);
		XuatText(ds[i].ten_sach,34,k,0);
		XuatNum(ds[i].so_trang,73,k,0);
		XuatText(ds[i].tac_gia,79,k,0);
		XuatNum(ds[i].nam_xb,111,k,0);
		XuatNum(ds[i].so_lan_muon,122,k,0);
		k+=2;
	}
}

void In10SachCoSoLuotMuonNhieuNhat(MCONTRO &DauS)
{
	Sapxepdausachtheotensach(DauS);
	DauSach ds[10];
	for(int i=0;i<10;i++)
	{
		ds[i].so_lan_muon=0;
	}
	int dem=0;
	for(int i = 0 ; i < 10 ; i++)
	{
		for(int j = 0 ; j < DauS.SoluongdauS ; j++)
		{
			if(ds[i].so_lan_muon < DauS.nodesDauSach[j]->so_lan_muon && !KiemTraTrung(ds, DauS.nodesDauSach[j]->ten_sach,i))
			{
				ds[i] = *DauS.nodesDauSach[j];
				dem=i;
			}
			
		}
	}
	Xuat10DauSach(ds,dem);
	char thoat=getch();
	while(thoat!=Enter && thoat!=Esc){
		thoat=getch();
	}
	
}
bool ChonKhoaMo(string str[])
{
	ToMau(60,29,20,2,10);
	ToMau(60,31,20,5,30);
	SetColor(0);
	for(int i=0;i<2;i++)
	{
		gotoxy(68,33+i*2);cout<<str[i];
	}
	
	SetColor(1);
	XuatText(str[0],68,33,12);
	XuatText(str[1],68,35,0);
	ShowCur(0);
	bool isApply=TRUE;
		char chon;
		do{
			
			chon=getch();
			if (chon==0) chon = getch();
			switch(chon){
				case 80:if(isApply){
					XuatText(str[0],68,33,0);
					XuatText(str[1],68,35,12);
					isApply=FALSE;
					
				}break;
				case 72:if(!isApply){
					XuatText(str[1],68,35,0);
					XuatText(str[0],68,33,12);
					isApply=TRUE;
				
				}	break;
				case 13:{
					return isApply;		
					}
				
			}
		}while(1);
	
}
void MoKhoaVaKhoaTheDocGia(TREE &t,bool &Thoat)
{
	int MaThe  = 0;
	TREE tam;
	XuatText("MO KHOA VA KHOA",67,13,14);
	int maDG = 0;
NhapmaDG3:
	HuongDan("Vui long nhap dung ma the", "Enter - tim ket qua", "Nhan ESC - Thoat");	
	KhungText("Nhap ma the :",47,20,10, 2, 14 );
	XuLiNhapSo(62,20,maDG,5,Thoat);
	if(Thoat){
		Thoat=ThongBao("","Ban co muon thoat",55,21);
		if(Thoat){
			return;
		}else{
			gotoxy(62,20);cout<<"      ";
			goto NhapmaDG3;
		} 
	}
	if (maDG == 0)
	{
		goto NhapmaDG3;
	}

	tam=TimDocGia(t, maDG);
	if(tam==NULL)
	{
		BaoLoi("Ma khong ton tai","Hay nhap lai",55,21);
		gotoxy(62,20);cout<<"      ";
		goto NhapmaDG3;
	}
	//ma doc gia ok
	XoaHCN(46,19,25,4);
	HuongDan("Phim mui ten: Len-Xuong de chon", "Enter - chon ", "Nhan ESC - Thoat");
	KhungText("Doc Gia:",55,15,30,2,70);
	XuatText(tam->data.ho+" "+tam->data.ten,65,15,15);
	KhungText("Ma The:",56,18,8,2,70);
	XuatNum(tam->data.ma_the,65,18,15);
	KhungText("Trang Thai The:",73,18,15,2,70);
	XuatText(TrangThaiDocGia(tam->data.trang_thai),90,18,15);
	KhungText("So Sach Muon:",50,21,7,2,70);
	XuatNum(tam->data.SoSachDangMuon,64,21,15);
	
	string TrangThai[] = {"","Tro lai"};
	if(tam->data.trang_thai == 0)
	{
		TrangThai[0] = "Mo khoa";
	}
	else
	{
		TrangThai[0] = "Khoa";
	}
	bool chon=ChonKhoaMo(TrangThai);
	if(!chon){
		XoaHCN(5, 13, 135, 25);
		KhungText("Nhap ma the :",47,20,10, 2, 14 );
		goto NhapmaDG3;	
	}
	if(tam->data.trang_thai == 0)
	{
		if(tam->data.SoNgayQuaHan == 0)
		{
			for(NODE_MUON_TRA* k = tam->data.DS_MuonTra.First ; k!=NULL ; k=k->right)
			{
				if(k->data.trang_thai == 3)
				{
					
//					Neu tiep tuc nhan enter thi doi trang thai cac sach thanh da thanh li va mo khoa cho the
					bool c=ThongBao( "Doc gia van chua den tien","Ban co muon mo khoa?",58,22);
					if(c)
					{
						k->data.trang_thai = 2;
						for(NODE_MUON_TRA* h = k ; h!=NULL ; h = h->right)
						{
							if(h->data.trang_thai == 3 ) // mat sach chua den
							{
								h->data.trang_thai =2;
								
							}
						}
						break;
					}
					break;
				}
			}
			tam->data.trang_thai = 1;
			BaoLoi("Mo khoa thanh cong","",58,22) ;
			SaveToFile(t);
			XoaHCN(5, 13, 135, 25);
			KhungText("Nhap ma the :",47,20,10, 2, 14 );
			goto NhapmaDG3;
		}
		else{
			BaoLoi("Doc gia chua tra het ","sach qua han",58,22) ;
			XoaHCN(5, 13, 135, 25);
			KhungText("Nhap ma the :",47,20,10, 2, 14 );
			goto NhapmaDG3;	
		}
	
	}
	else
	{
		tam->data.trang_thai = 0;
		BaoLoi("Khoa thanh cong","",58,22);
		SaveToFile(t);
		XoaHCN(5, 13, 135, 25);
		KhungText("Nhap ma the :",47,20,10, 2, 14 );
		goto NhapmaDG3;
	}
}
