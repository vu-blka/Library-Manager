
void SwapMaDG(int a[])
{
	for(int i=1;i<MAXDG;i++)
	{
		a[i]=i;
	}
	int ramdom ;
	for(int i=1;i<MAXDG/2;i++)
		{
			ramdom=1+rand()%(MAXDG-1);
			if(ramdom!=i)
			{
				int temp=a[ramdom];
				a[ramdom]=a[i];
				a[i]=temp;}	
		}
}
void LoadMaDocGia()
{
	fstream f;
	f.open("MaDocGia.TXT", ios::in );
	if(f.fail()|| f.eof())
	{
		f.open("MaDocGia.TXT", ios::out );
		SwapMaDG(mathe);
		for(int i=1;i<MAXDG;i++)
		{
			f<<mathe[i]<<" ";
		}
		ma_chua_dung=MAXDG-1;
		f.close();
	}
	else{
		while(!f.eof())
		{
			++ma_chua_dung;
			f>>mathe[ma_chua_dung];
		}
		f.close();
	}	
}
int LayMaDG()
{
	fstream f;
	int maDG;
	maDG=mathe[1];//lay phan tu dau tien
	for(int i=1;i<ma_chua_dung;i++)// bo phan tu dau tien
	{
		mathe[i]=mathe[i+1];
	}
	f.open("MaDocGia.TXT", ios::out);
	for(int i=1;i<ma_chua_dung;i++)//dua len file sau khi bo phan tu dau tien
	{
		f<<mathe[i]<<" ";
		if(mathe[i+1]==0)break;
	}
	f.close();
	return maDG;
}
void SaveDocGia(TREE t, ofstream &f, ofstream &f2)
{
	if(t==NULL)
	{
		return;
	}
	else{
			f<<t->data.ma_the<<",";
			f<<t->data.ho<<",";
			f<<t->data.ten<<",";
			f<<t->data.phai<<",";
			f<<t->data.trang_thai<<endl;
			for (NODE_MUON_TRA* k = t->data.DS_MuonTra.First; k != NULL; k = k->right)
			{
			f2 << t->data.ma_the << "," << k->data.ma_sach << ",";
			f2 << k->data.ngay_muon.Ngay << "/" << k->data.ngay_muon.Thang << "/" << k->data.ngay_muon.Nam << ",";
			f2 << k->data.ngay_tra.Ngay << "/" << k->data.ngay_tra.Thang << "/" << k->data.ngay_tra.Nam << ",";
			f2 << k->data.trang_thai << endl;
			}
			SaveDocGia(t->pLeft,f,f2);
			SaveDocGia(t->pRight,f,f2);
		}	
}
void SaveToFile(TREE t)
{
	ofstream f, f2;
	f.open("DanhSachDocGia.TXT",ios::out);
	f2.open("DanhSachMuonTra.TXT",ios::out);
	SaveDocGia(t,f,f2);
	f.close();
	f2.close();
}
void ThemDocGiaVaoFile(TREE t)
{
	ofstream f;
	f.open("DanhSachDocGia.TXT", ios :: out | ios::app);
	f<<t->data.ma_the<<",";
	f<<t->data.ho<<",";
	f<<t->data.ten<<",";
	f<<t->data.phai<<",";
	f<<t->data.trang_thai<<endl;
	f.close();
}
void Load1DocGia(TREE &t, ifstream &f ,int mathe)
{
	if(t==NULL)
	{
		NODE_DOCGIA *p= new NODE_DOCGIA;
		p->data.ma_the=mathe;
		f.ignore();
		getline(f,p->data.ho,',');
		getline(f,p->data.ten,',');
		getline(f,p->data.phai,',');
		f>>p->data.trang_thai;
		f.ignore();
		p->data.SoNgayQuaHan=0;
		p->data.SoSachDangMuon=0;
		p->data.DS_MuonTra.First=NULL;
		p->data.DS_MuonTra.Last=NULL;	
		p->pLeft=NULL;
		p->pRight=NULL;
		t=p;
	}
	else{
		if(t->data.ma_the > mathe)
		{
			Load1DocGia(t->pLeft,f,mathe);
		}
		else if(t->data.ma_the < mathe)
		{
			Load1DocGia(t->pRight,f,mathe);
		}
	}
}
void LoadDocGiaFromFile(TREE &t)
{
	int lay_ma;
	ifstream f;
	f.open("DanhSachDocGia.TXT",ios::in);
	if(f.fail()){
		return;
	}
	while(!f.eof())
	{
		lay_ma=0;
		f>>lay_ma;
		if(lay_ma==0){
			break;
		}
		++sl_docgia;
		Load1DocGia(t ,f ,lay_ma);
	}
	f.close();
}
void ChuanHoaChu(string &str)
{
	//khoang trang dau va cuoi
	while(str[0]==' ')
	{
		str.erase(str.begin()+0);
	}
	while(str[str.length()-1]==' ')
	{
		str.erase(str.begin()+str.length()-1);
	}
	//khooang trang giua
	for(int i=0;i<str.length();i++)
	{
		if(str[i]==' ' && str[i+1]==' ')
		{
			str.erase(str.begin()+i);
			i--;
		}
	}
	//viet hoa ky tu dau
	if(str[0]>=97 && str[0]<=122)
	{
		str[0]-=32;
	}
	for(int i=1;i<str.length();i++)
	{
		if(str[i]==' ')
		{
			i++;
			if(str[i]>=97 &&str[i]<=122)
			{
				str[i]-=32;
			}
		}
		else{
				if(str[i]>=65 &&str[i]<=90)
				{
					str[i]+=32;
				}
		}
	}
}
string TrangThaiDocGia(int n)
{
	if (n == 1)
		return "Hoat Dong";
	else
		return "Khoa";
}
void KhoiTaoDG(TREE &t)
{
	t=NULL;
}
string ChonGioiTinh(bool &Thoat,int toaX, int toaY)
{
	XuatText("Nu",toaX+11,toaY,7);
	XuatText("Nam",toaX,toaY,12);
	ShowCur(1);
	string gt="Nam";
	char chon;
		do{
			
			chon=getch();
			if (chon==0) chon = getch();
			switch(chon){
				case Right:if(gt=="Nam"){
					XuatText("Nam",toaX,toaY,7);
					XuatText("Nu",toaX+11,toaY,12);
					gt="Nu";
					
				}break;
				case Left:if(gt=="Nu"){
					XuatText("Nu",toaX+11,toaY,7);
					XuatText("Nam",toaX,toaY,12);
					gt="Nam";
				
				}	break;
				case Up:{
					gotoxy(45,toaY-4);
					return gt;		
					}
				case Down:{
					gotoxy(45,toaY+4);
					return gt;		
					}
				case Enter:{
					gotoxy(45,toaY+4);
					return gt;	
					}
				case Esc:{
					Thoat=TRUE;
					return gt;	
					}
				
			}
		}while(1);
	
}
void ThemDocGia(TREE &t, int x,bool &Exit)
{
	
	if(t==NULL)
	{
		NODE_DOCGIA *p=new NODE_DOCGIA;
		
		XuatNum(x,85,19,15);
		int a[3]={19,23,27};
		gotoxy(52,19);//cho con tro nhay toi toa do cua ham nhap ho
		
		while(1){
		//cout<<"Nhap ho: ";
			if(wherey()==19){
	Nhapho:			
				XuLiNhapDocGia(52, 19,p->data.ho,18,Exit);
				if(Exit){
					Exit=ThongBao("Du lieu se khong duoc luu","Ban co muon thoat ?",65,21);
					if(Exit){
						delete p;
						return;
					}
					else goto Nhapho;
					
				}
			}
			
			
			//cout<<"Nhap ten: ";
			if(wherey()==23){
	Nhapten:
				XuLiNhapDocGia(52,23,p->data.ten,12,Exit);
				if(Exit){
					Exit=ThongBao("Du lieu se khong duoc luu","Ban co muon thoat ?",65,21);
					if(Exit){
						delete p;
						return;
					}
					else goto Nhapten;
				}
	 	}
			
			//cout<<"Nhap phai: ";
			if(wherey()==27){
	Chongioitinh:
				p->data.phai=ChonGioiTinh(Exit,53,27);
				if(Exit){
					Exit=ThongBao("Du lieu se khong duoc luu","Ban co muon thoat ?",65,21);
					if(Exit){
						delete p;
						return;
					}
					else goto Chongioitinh;
				}
			}	
			if(wherey()==31){
				p->data.trang_thai=1;// cap nhap trang thai the
				gotoxy(52,31);
				cout<<TrangThaiDocGia(p->data.trang_thai);
				ShowCur(0);
				Exit=PhimDuyet(60,36);
				break;
			}
		}
		if(Exit){
			Exit=!ThongBao("Da them thanh cong.","Ban co muon tiep tuc ?",65,21);
			ChuanHoaChu(p->data.ho);
			ChuanHoaChu(p->data.ten);
			ChuanHoaChu(p->data.phai);
			p->data.ma_the=LayMaDG();
			p->data.SoSachDangMuon=0;
			p->data.SoNgayQuaHan=0;
			p->data.DS_MuonTra.First=NULL;
			p->data.DS_MuonTra.Last=NULL;
			p->pLeft=NULL;
			p->pRight=NULL;
			t=p;
			sl_docgia++;
			ThemDocGiaVaoFile(p);
						
		}
		else {
			Exit=ThongBao("Du lieu se khong duoc luu","Ban co muon thoat ?",65,21);
			if(Exit){
				delete p;
				return;
				}
				else goto Nhapho;
		}
	}
	else{
		if(t->data.ma_the > x){
			ThemDocGia(t->pLeft, x,Exit);
		}
		if(t->data.ma_the < x){
			ThemDocGia(t->pRight, x, Exit);
		}
	}
}
TREE TimDocGia(TREE t,int mathe)
{
	if(t==NULL)
	{
		return t;
	}
	else{
		if(t->data.ma_the> mathe)
		{
			TimDocGia(t->pLeft,mathe);
		}
		else if(t->data.ma_the < mathe)
		{
			TimDocGia(t->pRight,mathe);
		}
		else
		{
			return t;
		}
	}
}
void NodeThayThe(TREE &rp,  TREE &p)//      tim diem cuc trai cua p, swap t vs rp
{
	if(p->pLeft!=NULL)
	{
		NodeThayThe(rp,p->pLeft);	
	}
	else{
		rp->data=p->data;
		rp=p;
		p=rp->pRight;
		
	}
}
void XoaDocGia(TREE &t, int x, bool &Thoat)
{
	if(t==NULL)
	{
		Thoat=!ThongBao("Khong tim thay thong tin","Ban co muon tiep tuc",55,21);
		gotoxy(62,20);cout<<"     ";
		return;
	}
	else{
		if(t->data.ma_the > x){
			XoaDocGia(t->pLeft,x,Thoat);
		}
		else if(t->data.ma_the < x)
		{
			XoaDocGia(t->pRight,x,Thoat);
		}
		else{
			GiaoDienXuat1Docgia(t->data.ma_the,t->data.ho,t->data.ten,t->data.phai,TrangThaiDocGia(t->data.trang_thai));
			Thoat=PhimDuyet(60,36);	
			if(!Thoat)
			{
				Thoat=ThongBao("Huy xoa","Ban co muon thoat",55,21);
				XoaHCN(11, 15, 123, 22);
				return;
			}
			
			NODE_DOCGIA *rp=t;
			if(t->pLeft==NULL) t=t->pRight;
			else{
				if(t->pRight==NULL) t=t->pLeft;
				else {
					
					NodeThayThe(rp,t->pRight);
					
				}
			} 
			delete rp;
			sl_docgia--;
			Thoat=!ThongBao("Da xoa","Ban co muon tiep tuc",55,21);
			XoaHCN(11, 15, 123, 22);
		}
	}
}

void HieuChinhDocGia(TREE &t,int mathe,bool &Thoat)
{
	NODE_DOCGIA *q;
	q=TimDocGia(t, mathe);
	if(q==NULL)
	{
		BaoLoi("Khong tim thay thong tin","Hay nhap lai",55,21);
		KhungText("Ho:",47,21,21, 2, 14 );
		KhungText("Ten:",46,25,15, 2, 14 );
		return;
	}
	else{
		NODE_DOCGIA *p=new NODE_DOCGIA;
		p->data=q->data;
		
		XuatText(p->data.ho,52, 21,15);
		XuatText(p->data.ten,52, 25,15);
		if(p->data.phai=="Nam"){
			XuatText(p->data.phai,53,29,12);
		}
		else{
			XuatText(p->data.phai,64,29,12);
		}
		XuatText(TrangThaiDocGia(p->data.trang_thai),52,33,70);
		gotoxy(52,21);
		while(!Thoat)
		{
			if(wherey()==21)
			{
				XuLiNhapDocGia(52, 21,p->data.ho,18,Thoat);
				if(Thoat){
					Thoat=ThongBao("","Ban co muon thoat ?",55,21);
					if(Thoat){
						delete p;
						return;
					}
					else GiaoDienHieuChinh(p->data.ho, p->data.ten);gotoxy(52,21);
				}
			}	
				//cout<<"Nhap ten: ";
			if(wherey()==25)
			{
				XuLiNhapDocGia(52,25,p->data.ten,13,Thoat);
				if(Thoat){
					Thoat=ThongBao("","Ban co muon thoat ?",55,21);
					if(Thoat){
						delete p;
						return;
					}
					else GiaoDienHieuChinh(p->data.ho, p->data.ten);gotoxy(52,25);
				}
			}
			
			//cout<<"Nhap phai: ";
			if(wherey()==29)
			{
				p->data.phai=ChonGioiTinh(Thoat,53,29);
				if(Thoat){
					Thoat=ThongBao("","Ban co muon thoat ?",55,21);
					if(Thoat){
						delete p;
						return;
					}
					else GiaoDienHieuChinh(p->data.ho, p->data.ten);gotoxy(52,29);
				}
			}
			if(wherey()==33)
			{
				ShowCur(0);
				Thoat=PhimDuyet(60,36);
				break;
			}	
		}	
		if(Thoat){
			Thoat=!ThongBao("Da hieu chinh thanh cong.","Ban co muon tiep tuc ?",55,21);
			ChuanHoaChu(p->data.ho);
			ChuanHoaChu(p->data.ten);
			ChuanHoaChu(p->data.phai);
			q->data=p->data;
			p->data=q->data;
			delete p;	
			SaveToFile(t);					
		}
		else {
			Thoat=ThongBao("Du lieu se khong duoc luu","Ban co muon thoat ?",55,21);
			delete p;
		}
	}
}
void ChepDGVaoMang(TREE t, TheDocGia p[],int &k)
{
	if(t==NULL){
		return ;
	}
	else{
		ChepDGVaoMang(t->pLeft,p,k);
		p[k]=t->data;
		k++;
		ChepDGVaoMang(t->pRight,p,k);
	}
}
void SapXepTheoHoTen(TheDocGia p[],int &n)
{
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			//int kt1=strcmp(p[i].ten.c_str(),p[j].ten.c_str());
			if(p[i].ten>p[j].ten){
				TheDocGia tam=p[i];
				p[i]=p[j];
				p[j]=tam;
			}
			else if(p[i].ten==p[j].ten){
			//	int kt2=strcmp(p[i].ho.c_str(),p[j].ho.c_str());
				if(p[i].ho>p[j].ho){
					TheDocGia tam=p[i];
					p[i]=p[j];
					p[j]=tam;
				}
			}
		}
	}
}
void ChuyenDanhSachDocGiaQuaHanSangMang(TREE t, TheDocGia a[] , int &i)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		ChuyenDanhSachDocGiaQuaHanSangMang(t->pLeft, a , i );
		if(t->data.SoNgayQuaHan > 0)
		{
			a[i++] = t->data;
		}
		ChuyenDanhSachDocGiaQuaHanSangMang(t->pRight, a , i );
	}
}

void SapXepDanhSachDocGiaQuaHanGiamDan(TREE t, TheDocGia a[],int &n)
{
 	n = 0;
	ChuyenDanhSachDocGiaQuaHanSangMang(t,a,n);
	TheDocGia tam;
	
	for(int i = 0 ; i < n-1 ; i++)
	{
		for(int j = i+1 ; j < n ; j++)
		{
			if (a[i].SoNgayQuaHan < a[j].SoNgayQuaHan)
			{
			tam = a[i];
			a[i] = a[j];
			a[j] = tam;
			}
		}
	}
	
}
void XuatDocGiaRaPage(TREE t, bool &Thoat,int &luachon)
{
	int i=0, stt=0,temp;
	int soPage=1;
	int n=sl_docgia;
	TheDocGia *p=new TheDocGia[sl_docgia];
	XoaHCN(13,13,120,25);
	ChepDGVaoMang(t, p,i);
	luachon=LuaChonXuatDG(luachon);
	if(luachon==-1) {
		Thoat=TRUE;
		return;
	}
	 else if(luachon==1)
	{
		SapXepTheoHoTen(p,sl_docgia);
	}
	else if(luachon==2)
	{
		SapXepDanhSachDocGiaQuaHanGiamDan(t, p,n);
	}
	//===LOAD GIAO DIEN NOI DUNG======
	GiaoDienXuatPageDG(soPage,n);
	i=18;
	temp=stt;
	for(temp;(temp<stt+7)&& temp<n;temp++)
	{
		XuatNum(p[temp].ma_the,16,i,16);
		XuatText(p[temp].ho+' '+p[temp].ten,35,i,16);
		XuatText(p[temp].phai,74,i,16);
		XuatText(TrangThaiDocGia(p[temp].trang_thai),87,i,16);
		XuatNum(p[temp].SoSachDangMuon,108,i,16);
		XuatNum(p[temp].SoNgayQuaHan,124,i,16);			
		i=i+3;
	}
	char kytu;
	do{
		kytu=getch();
		switch(kytu)
		{
			case 77:{if(stt+7<n){
				++soPage;
				LoadPageDG(soPage,n);
//				GiaoDienXuatPageDG();
				stt+=7;
				i=18;
				temp=stt;
				for(temp;(temp<stt+7)&&temp<n;temp++)
				{
					
						XuatNum(p[temp].ma_the,16,i,16);
	    				XuatText(p[temp].ho+' '+p[temp].ten,35,i,16);
	    				XuatText(p[temp].phai,74,i,16);
					    XuatText(TrangThaiDocGia(p[temp].trang_thai),87,i,16);
						XuatNum(p[temp].SoSachDangMuon,108,i,16);
					    XuatNum(p[temp].SoNgayQuaHan,124,i,16);
					
					i=i+3;
				}
			}	
				break;
		}
			case 75:{if(stt>=7){
					--soPage;
					LoadPageDG(soPage,n);
//					GiaoDienXuatPageDG();
					stt=stt-7;
					i=18;
					temp=stt;
					for(temp;(temp<stt+7)&&temp<n;temp++)
					{
						
							XuatNum(p[temp].ma_the,16,i,16);
		    				XuatText(p[temp].ho+' '+p[temp].ten,35,i,16);
		    				XuatText(p[temp].phai,74,i,16);
						    XuatText(TrangThaiDocGia(p[temp].trang_thai),87,i,16);
							XuatNum(p[temp].SoSachDangMuon,108,i,16);
						    XuatNum(p[temp].SoNgayQuaHan,124,i,16);
						
						i=i+3;
					}	
				}
				break;
			}
			case 27:{
				delete[] p;
				return ;
			}
		}
	}while(1);
	
}

