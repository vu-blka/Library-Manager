#define MAXNODES 1000
#define TRUE 1
#define FALSE 0
string TaoMaDanhMuc(string a,LIST_DMS dms)
{
	
	if(dms==NULL)
	{
		return a + "_" + "01";
	}
	else
	{
		string str;
		str = dms->data.ma_sach;
		if(dms->data.ma_sach[19]!=57)
		{
			str[19]++;
		}
		else
		{
			str[18]++;
			str[19]= 48;
		}
		return str;
	}
}
	
//=======CAU C NHAP THONG TIN SACH====
void ThemDMS(MCONTRO DauS, string vitri)
{
	for(int i = 0 ; i < DauS.nodesDauSach[DauS.SoluongdauS]->so_luong_sach ; i++)
	{
		Node_Dms *p= new Node_Dms;
		p->data.ma_sach = TaoMaDanhMuc(DauS.nodesDauSach[DauS.SoluongdauS]->ISBN,DauS.nodesDauSach[DauS.SoluongdauS]->dms);
		p->data.vi_tri=vitri;
		p->data.trang_thai = 0;
		p ->next = DauS.nodesDauSach[DauS.SoluongdauS]->dms;
		DauS.nodesDauSach[DauS.SoluongdauS]->dms = p;
	}
}
//======DOC-GHI FILE DAU SACH + DANH MUC SAC=======
void ghithongtindausachvaofile(DauSach *DauS)
{
	ofstream fileout("inputDauSach.TXT",ios::app);															// cau c										
	fileout <<'\n'<< DauS->ISBN << "," << DauS->ten_sach << "," << DauS->so_trang<< "," << DauS->tac_gia   << "," << DauS->nam_xb << "," << DauS->the_loai << ","<< DauS->dms->data.vi_tri<< ","  << DauS->so_luong_sach;
	fileout.close();
}	
void doc1dongtrongfile(ifstream &filein,MCONTRO &ds)
{
	string temp;
	
	getline (filein,ds.nodesDauSach[ds.SoluongdauS]->ISBN,',');
	getline (filein,ds.nodesDauSach[ds.SoluongdauS]->ten_sach,',');
	filein>>ds.nodesDauSach[ds.SoluongdauS]->so_trang;
	getline(filein,temp,',');
	getline (filein,ds.nodesDauSach[ds.SoluongdauS]->tac_gia,',');
	filein>>ds.nodesDauSach[ds.SoluongdauS]->nam_xb;
	getline(filein,temp,',');
	getline (filein,ds.nodesDauSach[ds.SoluongdauS]->the_loai,',');
	string vitri;
	getline (filein,vitri,',');
	filein>>ds.nodesDauSach[ds.SoluongdauS]->so_luong_sach;
	ds.nodesDauSach[ds.SoluongdauS]->dms=NULL;
	
	ThemDMS(ds, vitri);
	filein.ignore();
	ds.SoluongdauS++;
}
void docfilevaomang(MCONTRO &ds)
{	
	ifstream filein("inputDauSach.TXT",ios_base::in);
	filein.ignore();
	while(filein.eof()==0)
	{
		ds.nodesDauSach[ds.SoluongdauS] = new DauSach;
		doc1dongtrongfile(filein,ds);
	}
	filein.close();
}
string TrangThaiSach(int n)
{
	if (n == 1)
	{
		return "Da Muon";
	}
	else if (n == 0)
	{
		return "Duoc Muon";
	}
	else
		return "Da Thanh Li";
}
bool kiemtratrungmaISBN(MCONTRO ds, string ma)
{
	for(int i=0;i<ds.SoluongdauS;i++)
	{
		if(ds.nodesDauSach[i]->ISBN == ma)
		{
			return 1;
		}
	}
	return 0;
}
void laysothu13(string &a)
{
	//char* a = c_str(a);
	string so13;
	int sumchan=0;
	int sumle=0;
	for(int i = 0 ; i < a.length()-2;i++)
	{
		if(a[i]!='-')
		{
			int tam=a[i]-'0';
			if(i==0||i==2||i==5||i==8||i==11||i==13)
			{
				sumle+=tam;
			}
			else
			{
				sumchan+=tam;
			}
	}
}
	int b = (sumchan*3 + sumle)%10;
	if(b==0){
		a[16]='0';
	}
	else
	{
		stringstream doi;
		doi << (10-b);
		so13 = doi.str();
		a[16]=so13[0];
	}
}
string laymaISBN(MCONTRO ds)
{
	string a;
	a = "978-604-00-0000-0";
	do
	{
	for (int i = 8 ; i < 15 ; i++) // random 2 so sau so 604
	{
		if(a[i]!='-')
		{
		a[i]=48+ rand()%10;
		}
	}
	}while(kiemtratrungmaISBN(ds, a));
	laysothu13(a);
	return a;
}


bool KtTrungSach(MCONTRO &DauS)
{
	for(int i=0;i<DauS.SoluongdauS;i++)
	{
		if(DauS.nodesDauSach[i]->ten_sach==DauS.nodesDauSach[DauS.SoluongdauS]->ten_sach)
		{
			return TRUE;
		}
	}
	return FALSE;
}
void themdausach(MCONTRO &DauS, bool &Exit)
{
	if (DauS.SoluongdauS >= MAXNODES)
	{
		Exit=ThongBao("So luong sach da full","Khong the them",55,21);
		Exit=true;
		return ;
	}
	else
	{
	DauS.nodesDauSach[DauS.SoluongdauS] = new DauSach;
	DauS.nodesDauSach[DauS.SoluongdauS]->dms=NULL;
	string vitri;
	//"Ma ISBN: ";
	DauS.nodesDauSach[DauS.SoluongdauS]->ISBN=laymaISBN(DauS);
	XuatText(DauS.nodesDauSach[DauS.SoluongdauS]->ISBN,97,17,15);
	gotoxy(49,17);
	while(1){
		if(wherex()<81 && wherey()==17){
Nhaptensach:
			XuLiNhapTenSach(49,17,DauS.nodesDauSach[DauS.SoluongdauS]->ten_sach,32,Exit);
			if(Exit){
				Exit=ThongBao("Du lieu se khong duoc luu","Ban co muon thoat ?",55,21);
				delete DauS.nodesDauSach[DauS.SoluongdauS];
				return;
			}
			ChuanHoaChu(DauS.nodesDauSach[DauS.SoluongdauS]->ten_sach);
			if(KtTrungSach(DauS)){
				gotoxy(49,19);SetColor(4);cout<<"Sach da ton tai";SetColor(7);
				goto Nhaptensach;
			}	
			else {
				gotoxy(49,19);cout<<"                 ";
				gotoxy(49,22);
			}
		}
		if(wherex()<81 && wherey()==22){
			//"Nhap tac gia: " ;
			XuLiNhapSach(49,22,DauS.nodesDauSach[DauS.SoluongdauS]->tac_gia,27,Exit);
			if(Exit){
				Exit=ThongBao("Du lieu se khong duoc luu","Ban co muon thoat ?",55,21);
				delete DauS.nodesDauSach[DauS.SoluongdauS];
				return;
			}
		}
		if(wherex()>=97 && wherey()==22){
			//"\nNhap so trang: " ;
			gotoxy(97,22);cout<<"     ";
			XuLiNhapSoTrongSach(97,22,DauS.nodesDauSach[DauS.SoluongdauS]->so_trang,5,Exit);
			if(Exit){
				Exit=ThongBao("Du lieu se khong duoc luu","Ban co muon thoat ?",55,21);
				delete DauS.nodesDauSach[DauS.SoluongdauS];
				return;
			}
		}
		if(wherex()<81 && wherey()==27){
			// "Nhap the loai: " ;
			XuLiNhapSach(49,27,DauS.nodesDauSach[DauS.SoluongdauS]->the_loai,15,Exit);
			if(Exit){
				Exit=ThongBao("Du lieu se khong duoc luu","Ban co muon thoat ?",55,21);
				delete DauS.nodesDauSach[DauS.SoluongdauS];
				return;
			}
		}
		if(wherex()>=97 && wherey()==27){
			// "Nhap nam xuat ban: " ;
			gotoxy(97,27);cout<<"     ";
			XuLiNhapSoTrongSach(97,27,DauS.nodesDauSach[DauS.SoluongdauS]->nam_xb,5,Exit);
			if(Exit){
				Exit=ThongBao("Du lieu se khong duoc luu","Ban co muon thoat ?",55,21);
				delete DauS.nodesDauSach[DauS.SoluongdauS];
				return;
			}
		}	
		if(wherex()<81 && wherey()==32){
	Nhapsoluong:
			//"Nhap so luong sach: " ;
			gotoxy(49,32);cout<<"     ";
			XuLiNhapSoTrongSach(49,32,DauS.nodesDauSach[DauS.SoluongdauS]->so_luong_sach,5,Exit);
			if(Exit){
				Exit=ThongBao("Du lieu se khong duoc luu","Ban co muon thoat ?",55,21);
				delete DauS.nodesDauSach[DauS.SoluongdauS];
				return;
			}
			if(DauS.nodesDauSach[DauS.SoluongdauS]->so_luong_sach>30)
			{
				gotoxy(49,34);;SetColor(4);cout<<"So luong khong qua 30";SetColor(7);
				goto Nhapsoluong;
			}else{
				gotoxy(49,34);cout<<"                        ";
				gotoxy(97,32);
			}
		}
		if(wherex()>=97 && wherey()==32){
			//them dms
			XuLiNhapSach(97,32,vitri,15,Exit);
			if(Exit){
				Exit=ThongBao("Du lieu se khong duoc luu","Ban co muon thoat ?",55,21);
				delete DauS.nodesDauSach[DauS.SoluongdauS];
				return;
			}
		}
		if(wherey()==37){
			Exit=PhimDuyet(60,36);
			break;
		}
		
	}
	//ShowCur(0);
	
	if(Exit){
		Exit=!ThongBao("Da them thanh cong.","Ban co muon tiep tuc ?",55,21);
	}
	else{
		Exit=ThongBao("Du lieu se khong duoc luu","Ban co muon thoat ?",55,21);
		delete DauS.nodesDauSach[DauS.SoluongdauS];
		return;
	}
	ThemDMS(DauS,vitri);
	ChuanHoaChu(DauS.nodesDauSach[DauS.SoluongdauS]->tac_gia);
	ChuanHoaChu(DauS.nodesDauSach[DauS.SoluongdauS]->the_loai);
	
	
	ghithongtindausachvaofile(DauS.nodesDauSach[DauS.SoluongdauS]);
	DauS.SoluongdauS ++;
	}
}
//=======================SAP XEP DAU SACH THEO TEN=========================
void Sapxepdausachtheotensach(MCONTRO &DauS)											//	ap dung cho cau d thu tu sach tang dan
{
	DauSach* tam =NULL ;
	for (int i = 0 ; i < DauS.SoluongdauS - 1 ; i++)
	{
		for (int j = i+1 ; j < DauS.SoluongdauS ; j++)
		{
			if(DauS.nodesDauSach[i]->ten_sach > DauS.nodesDauSach[j]->ten_sach)
			{
				tam = DauS.nodesDauSach[i];
				DauS.nodesDauSach[i] = DauS.nodesDauSach[j];
				DauS.nodesDauSach[j] = tam;
			}
		}
	}
}

//=====================KIEM TRA TRUNG THE LOAI======================
bool KiemTraTrungTheLoai(MCONTRO DauS,string TheLoai[], int i, int a)
{
	for (int j = 0 ; j < a; j++)
	{
		if (DauS.nodesDauSach[i]->the_loai == TheLoai[j] )
		{
			return TRUE;
		}
	}
	return FALSE;
}

//==================LIET KE CAC THE LOAI====================
void Lietkecactheloai(MCONTRO DauS,bool &Thoat)
{
	if (DauS.SoluongdauS == 0)
	{
		Thoat=ThongBao("Chua co cuon sach nao","Nhan Enter de thoat",55,21); 
		return;
	}
		Sapxepdausachtheotensach(DauS);
		string TheLoai[100];
		int a = 1;
		TheLoai[0] = DauS.nodesDauSach[0]->the_loai;
		for (int i = 1 ; i < DauS.SoluongdauS ; i++)
		{
			if(!KiemTraTrungTheLoai(DauS,TheLoai,i,a))
			{
				TheLoai[a++] = DauS.nodesDauSach[i]->the_loai;
			}
		}
//=======================XUAT CAC THE LOAI=================
	SetBGColor(16);
	XuatText("XUAT DAU SACH",70,13,14);
	int chon=0,ngang=0,doc=0,i;
	do{
		chon=LuaChonXuatSach(TheLoai,a,chon,doc,ngang);
		if(chon==-1){
			Thoat=TRUE;
			return;
		}
		i=18;
		GiaoDienXuatPageDauS();
		for (int k = 0 ; k < DauS.SoluongdauS ; k++)
		{
			if(DauS.nodesDauSach[k]->the_loai == TheLoai[chon])
			{
				XuatText(DauS.nodesDauSach[k]->ISBN,13,i,16);
				XuatText(DauS.nodesDauSach[k]->ten_sach,48-DauS.nodesDauSach[k]->ten_sach.length()/2,i,16);
				XuatNum(DauS.nodesDauSach[k]->so_trang,70,i,16);
				XuatText(DauS.nodesDauSach[k]->tac_gia,90-DauS.nodesDauSach[k]->tac_gia.length()/2,i,16);
				XuatNum(DauS.nodesDauSach[k]->nam_xb,111,i,16);
				XuatNum(DauS.nodesDauSach[k]->so_luong_sach,124,i,16);			
				i=i+3;
			}
		}
		while(getch()!=27){
			getch();
		}
		XoaHCN(12,14,121,23);
	}while(1);	
}
string TachLayMaDauSach(string str)
{
	string str1;
	for (int i =0; i<str.length(); i++)
	{
		if (str[i] == '_')
		{
			break;
		}
		str1.push_back(str[i]);
	}
	return str1;
}
string LayTenSach(MCONTRO DauS, string MaSach)
{
	for(int i = 0 ; i < DauS.SoluongdauS ; i++)
	{
		if(DauS.nodesDauSach[i]->ISBN ==TachLayMaDauSach(MaSach) )
		{
			return DauS.nodesDauSach[i]->ten_sach;
		}
	}
}

void ChepDmsRaMang(LIST_DMS dms,DanhMucSach danhmuc[])
{
	int i=0;
	for (LIST_DMS p=dms; p!= NULL; p=p->next)
	{
		danhmuc[i++]=p->data;
	}
}
void TimSach(MCONTRO DauS, bool &Thoat)
{
	string tensach;
	GiaoDienTimSach();
	a:
	XuLiNhapTenSach(59,18,tensach,35,Thoat);
	if(Thoat){
		Thoat=ThongBao("","Ban muon thoat?",55,21);
		if(Thoat){
			return;
		}
		else {
			goto a ;
		}
	}
	if(tensach.empty())
		{
			goto a;
		}
	ChuanHoaChu(tensach);
	for(int k=0;k<DauS.SoluongdauS;k++)
	{
		if(DauS.nodesDauSach[k]->ten_sach==tensach)
		{
			GiaoDienXuat1DauS(DauS.nodesDauSach[k]->ISBN, DauS.nodesDauSach[k]->ten_sach, DauS.nodesDauSach[k]->tac_gia, DauS.nodesDauSach[k]->nam_xb, DauS.nodesDauSach[k]->the_loai);
			DanhMucSach danhmuc[DauS.nodesDauSach[k]->so_luong_sach];
			ChepDmsRaMang(DauS.nodesDauSach[k]->dms,danhmuc);
			int ngang=0;
			for(int i=0;i<4 && (i+ngang)<DauS.nodesDauSach[k]->so_luong_sach;i++)
			{
				XuatText(danhmuc[i].ma_sach,50-danhmuc[i].ma_sach.length()/2,27+i*3,0);
				XuatText(TrangThaiSach(danhmuc[i+ngang].trang_thai),70-TrangThaiSach(danhmuc[i+ngang].trang_thai).length()/2,27+i*3,0);
				XuatText(danhmuc[i].vi_tri,90-danhmuc[i].vi_tri.length()/2,27+i*3,0);
			}
			
			char kytu;
			do{
				kytu=getch();
				switch(kytu)
				{
					case Right :if (ngang+4<DauS.nodesDauSach[k]->so_luong_sach)
	  			  	{
	  			  		//soPage++;
//		  			  	ToMau(60,19,32,10,30);
						ngang=ngang+4;
						LoadPageXuat1DauS();
						for(int i=0;i<4 && (i+ngang)<DauS.nodesDauSach[k]->so_luong_sach;i++)
						{
							XuatText(danhmuc[i+ngang].ma_sach,50-danhmuc[i+ngang].ma_sach.length()/2,27+i*3,0);
							XuatText(TrangThaiSach(danhmuc[i+ngang].trang_thai),70-TrangThaiSach(danhmuc[i+ngang].trang_thai).length()/2,27+i*3,0);
							XuatText(danhmuc[i+ngang].vi_tri,90-danhmuc[i+ngang].vi_tri.length()/2,27+i*3,0);
						}		
		  			  	}
		  			 	break; 
	  				case Left :if (ngang-4 >=0)
	  			 	 {
		  			  	//soPage--;
//						ToMau(60,19,32,10,30);
						ngang=ngang-4;
						LoadPageXuat1DauS();
						for(int i=0;i<4 && (i+ngang)<DauS.nodesDauSach[k]->so_luong_sach;i++)
						{
							XuatText(danhmuc[i+ngang].ma_sach,50-danhmuc[i+ngang].ma_sach.length()/2,27+i*3,0);
							XuatText(TrangThaiSach(danhmuc[i+ngang].trang_thai),70-TrangThaiSach(danhmuc[i+ngang].trang_thai).length()/2,27+i*3,0);
							XuatText(danhmuc[i+ngang].vi_tri,90-danhmuc[i+ngang].vi_tri.length()/2,27+i*3,0);
						}			
	  			  }
	  			  break; 
					case 27:{
						XoaHCN(13,13,120,25);
						return ;
					}
				}
			}while(1);
		}
	}
	Thoat=!ThongBao("Sach khong co trong thu vien","Ban muon tiep tuc",55,21);
	XoaHCN(57,18,35,0);
	
}
void XuatPageMuonSach(MCONTRO DauS, LIST_MUON_TRA sachmuon,int toaX,int toaY)
{
	PageMuonTra(toaX,toaY);
	int tami=0;
	for(NODE_MUON_TRA *p = sachmuon.First ; p!=NULL ; p=p->right)
	{
		if(p->data.trang_thai==0) // 0 la dang muon 
		{
			XuatText( p->data.ma_sach,toaX+2,toaY+4+tami*2,0);
			XuatText(LayTenSach(DauS,p->data.ma_sach),toaX+38-LayTenSach(DauS,p->data.ma_sach).length()/2,toaY+4+tami*2,0);												
			gotoxy(toaX+56,toaY+4+tami*2);SetColor(0);cout << p->data.ngay_muon.Ngay << "/" << p->data.ngay_muon.Thang << "/" << p->data.ngay_muon.Nam;
			tami++;
		}
	}
}
void XuatCacSach1DocGiaDangMuon(TREE t,MCONTRO DauS,bool Thoat)     // cau h
{
	XuatText("SACH MUON CUA DOC GIA",68,13,14);
	KhungText("Nhap ma the :",47,20,10, 2, 14 );
	int mathe;
	TREE tam;
Nhapma:
	XuLiNhapSo(62,20,mathe,5,Thoat);
	if(Thoat){
		Thoat=ThongBao("","Ban muon thoat !",55,21);
		if(!Thoat){
			gotoxy(62,20);cout<<"      ";
			goto Nhapma;
		}
		else return;
	}
	tam=TimDocGia(t,mathe);
	if(tam==NULL){
		BaoLoi("Ma the khong ton tai","Hay Nhap Lai",55,21);
		gotoxy(62,20);cout<<"      ";
		goto Nhapma;
	}
	//ma doc gia ok
	XoaHCN(46,19,25,4);
	KhungText("Doc Gia:",57,16,30,2,70);
	XuatText(tam->data.ho+" "+tam->data.ten,67,16,15);
	KhungText("Ma The:",58,19,8,2,70);
	XuatNum(tam->data.ma_the,67,19,15);
	KhungText("Trang Thai The:",75,19,15,2,70);
	XuatText(TrangThaiDocGia(tam->data.trang_thai),92,19,15);
	KhungText("So Sach Muon:",52,22,7,2,70);
	XuatNum(tam->data.SoSachDangMuon,66,22,15);
	
	XuatPageMuonSach(DauS,tam->data.DS_MuonTra,50,26);
	
	char nhap;
	while(1){
		nhap=getch();
		if(nhap==27){
			XoaHCN(5, 13, 135, 25);
			KhungText("Nhap ma the :",47,20,10, 2, 14 );
			goto Nhapma;
			break;
		}
		
	}
}

