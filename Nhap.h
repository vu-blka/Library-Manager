void XuLiNhapDocGia(int toaX, int toaY,string &str,int max_nhap,bool &Thoat)
{
	ShowCur(1);
	Normal();
	char nhap;
	int i=str.length()-1;
Nhaplai:
	gotoxy(toaX+str.length(),toaY);
	do{
		if(wherex()<=max_nhap+toaX+1)
		{
			nhap=getch();
			
			
			if((nhap>=97 && nhap<=122) || (nhap>=65 && nhap<=90) || nhap==32) // chu thuong: [97, 122],chu hoa: [65,90], 32 = phim Khoang trang
			{
				++i;
				str.insert(str.begin()+i,nhap);
				if(wherex()<max_nhap+toaX+1){
					cout<<str[i];
				}
			}
			if(nhap==8 && wherex()>toaX||wherex()==max_nhap+toaX+1)
			{
				
				str.erase(str.begin()+i);
				gotoxy(wherex()-1,toaY);			
				cout<<" ";
				gotoxy(wherex()-1,toaY);
				i--;
				
			}
			
			if(nhap==Enter)
			{
				if(str.empty()){
						gotoxy(toaX,toaY+2);SetColor(4);cout<<"Du lieu ko duoc de trong";SetColor(7);
			  			goto Nhaplai;
					  }
				else {
						gotoxy(toaX,toaY+2);cout<<"                        ";
						gotoxy(toaX,toaY);
					}
				gotoxy(toaX,toaY+4);
				return;
			}
			if(nhap==Esc)
			{
					Thoat=TRUE;
					return;			
			}
			if(nhap==-32 )// mui ten len
			{
				nhap=getch();
				if(nhap== Up && wherey()>21){
					if(str.empty()){
						gotoxy(toaX,toaY+2);SetColor(4);cout<<"Du lieu ko duoc de trong";SetColor(7);
			  			goto Nhaplai;
					  }
				else {
						gotoxy(toaX,toaY+2);cout<<"                        ";
						gotoxy(toaX,toaY);
					}
				gotoxy(toaX,toaY-4);
				return ;	
				}
			  	else if(nhap==Down){
			  		if(str.empty()){
						gotoxy(toaX,toaY+2);SetColor(4);cout<<"Du lieu ko duoc de trong";SetColor(7);
			  			goto Nhaplai;
					  }
					else {
						gotoxy(toaX,toaY+2);cout<<"                        ";
						gotoxy(toaX,toaY);
					}
					//nhap=13;
					gotoxy(toaX,toaY+4);
					return ;	
				}
				
			}
		}
		
		
	}while(1);
}
void XuLiNhapTenSach(int toaX, int toaY,string &str,int max_nhap,bool &Thoat)
{
	ShowCur(1);
	Normal();
	char nhap;
	int i=str.length()-1;
Nhaplai:
	gotoxy(toaX+str.length(),toaY);
	do{
		if(wherex()<=max_nhap+toaX+1)
		{
			nhap=getch();
			
			if((nhap>=97 && nhap<=122) || (nhap>=65 && nhap<=90) || nhap==32|| (nhap>=48 && nhap<=57) || nhap=='+'|| nhap=='-'|| nhap=='*'|| nhap=='/'|| nhap=='.'|| nhap==','|| nhap=='?'|| nhap=='!') // chu thuong: [97, 122],chu hoa: [65,90], 32 = phim Khoang trang
			{
				++i;
				str.insert(str.begin()+i,nhap);
				if(wherex()<max_nhap+toaX+1){
					cout<<str[i];
				}
			}
			if(nhap==8 && wherex()>toaX||wherex()==max_nhap+toaX+1)
			{
				
				str.erase(str.begin()+i);
				gotoxy(wherex()-1,toaY);			
				cout<<" ";
				gotoxy(wherex()-1,toaY);
				i--;
				
			}
			
			if(nhap==Enter)
			{
				if(str.empty()){
						gotoxy(toaX,toaY+2);SetColor(4);cout<<"Du lieu ko duoc de trong";SetColor(7);
			  			goto Nhaplai;
					  }
				if(!str.empty()) {
						gotoxy(toaX,toaY+2);cout<<"                        ";
						gotoxy(toaX,toaY);
					}
				gotoxy(49,toaY+5);
				return;
				
			
			}
			if(nhap==Esc)
			{
					Thoat=TRUE;
					return;			
			}
			if(nhap==-32 )// mui ten len
			{
				nhap=getch();
				if(nhap==Down){
			  		if(str.empty()){
						gotoxy(toaX,toaY+2);SetColor(4);cout<<"Du lieu ko duoc de trong";SetColor(7);
			  			goto Nhaplai;
					 }
					if(!str.empty()) {
						gotoxy(toaX,toaY+2);cout<<"                        ";
						gotoxy(toaX,toaY);
					}
					gotoxy(49,toaY+5);
					return;
				}
				
			}
		}
		
		
	}while(1);
}
void XuLiNhapSach(int toaX, int toaY,string &str,int max_nhap,bool &Thoat)
{
	ShowCur(1);
	Normal();
	char nhap;
	int i=str.length()-1;
Nhaplai:
	gotoxy(toaX+str.length(),toaY);
	do{
		if(wherex()<=max_nhap+toaX+1)
		{
			nhap=getch();
			
			if((nhap>=97 && nhap<=122) || (nhap>=65 && nhap<=90) || nhap==32) // chu thuong: [97, 122],chu hoa: [65,90], 32 = phim Khoang trang
			{
				++i;
				str.insert(str.begin()+i,nhap);
				if(wherex()<max_nhap+toaX+1){
					cout<<str[i];
				}
			}
			if(nhap==8 && wherex()>toaX||wherex()==max_nhap+toaX+1)
			{
				
				str.erase(str.begin()+i);
				gotoxy(wherex()-1,toaY);			
				cout<<" ";
				gotoxy(wherex()-1,toaY);
				i--;
				
			}
			
			if(nhap==Enter)
			{
				if(str.empty()){
						gotoxy(toaX,toaY+2);SetColor(4);cout<<"Du lieu ko duoc de trong";SetColor(7);
			  			goto Nhaplai;
					  }
				if(!str.empty()) {
					gotoxy(toaX,toaY+2);cout<<"                        ";
					gotoxy(toaX,toaY);
				}
				if(wherex()<=82){
						gotoxy(97,toaY);
						return;
					}
				if(wherex()>=97)
					{
						gotoxy(49,toaY+5);
						return;
					}
			}
			if(nhap==Esc)
			{
					Thoat=TRUE;
					return;			
			}
			if(nhap==-32 )// mui ten
			{
				nhap=getch();
				if(nhap==Up ){
					if(str.empty()){
						gotoxy(toaX,toaY+2);SetColor(4);cout<<"Du lieu ko duoc de trong";SetColor(7);
			  			goto Nhaplai;
					  }
					if(!str.empty()) {
						gotoxy(toaX,toaY+2);cout<<"                        ";
						gotoxy(toaX,toaY);
					}
					if(wherex()<=82 && wherey()==22)
					{
							gotoxy(49,toaY-5);
						return ;
					}
					if(wherex()<=82){
						gotoxy(97,toaY-5);
						return ;	
					}
					if(wherex()>=97){
						gotoxy(49,toaY);
						return ;
					}	
				}
			  	else if(nhap==Down){
			  		if(str.empty()){
						gotoxy(toaX,toaY+2);SetColor(4);cout<<"Du lieu ko duoc de trong";SetColor(7);
			  			goto Nhaplai;
					  }
					if(!str.empty()) {
						gotoxy(toaX,toaY+2);cout<<"                        ";
						gotoxy(toaX,toaY);
					}
					if(wherex()<=82){
						gotoxy(97,toaY);
						return;
					}
					if(wherex()>=97)
					{
						gotoxy(49,toaY+5);
						return;
					}	
				}
			}	
		}
	}while(1);
}
void XuLiNhapSoTrongSach(int toaX, int toaY,int &a,int max_nhap,bool &Thoat)
{
	ShowCur(1);
	char nhap;
	int i=10;
	a=0;
Nhaplaiso:
	gotoxy(toaX,toaY);
	do{
		
		
		if(wherex()<=max_nhap+toaX+1)
		{
			nhap=getch();
			if(nhap=='0' || nhap=='1' || nhap=='2' ||nhap=='3' ||nhap=='4' ||nhap=='5' ||nhap=='6' ||nhap=='7' ||nhap=='8' || nhap=='9')
			{
				if(wherex()<=max_nhap+toaX+1){
					a=a*i+(nhap-'0');
					cout<<(nhap-'0');
				}
				
			}
			
			if(nhap==8 && wherex()>toaX||wherex()==max_nhap+toaX+1)
			{
				a/=10;
				gotoxy(wherex()-1,toaY);			
				cout<<" ";
				gotoxy(wherex()-1,toaY);	
			}
			
			if(nhap==Enter)
			{
				if(a==0){
						gotoxy(toaX,toaY+2);SetColor(4);cout<<"Du lieu ko duoc de trong";SetColor(7);
			  			goto Nhaplaiso;
					  }
				if(a>0) {
					gotoxy(toaX,toaY+2);cout<<"                        ";
					gotoxy(toaX,toaY);
				}
				if(wherex()<=82){
						gotoxy(97,toaY);
						return;
					}
				if(wherex()>=97)
					{
						gotoxy(49,toaY+5);
						return;
					}
			}
			if(nhap==Esc)
			{
				Thoat=TRUE;
					return;
			}
			if(nhap==-32 )// mui ten
			{
				nhap=getch();
				if(nhap==Up ){
					if(a==0){
						gotoxy(toaX,toaY+2);SetColor(4);cout<<"Du lieu ko duoc de trong";SetColor(7);
			  			goto Nhaplaiso;
					  }
					if(a>0) {
						gotoxy(toaX,toaY+2);cout<<"                        ";
						gotoxy(toaX,toaY);
					}
					if(wherex()<=82){
						gotoxy(97,toaY-5);
						return ;	
					}
					if(wherex()>=97){
						gotoxy(49,toaY);
						return ;
					}	
				}
			  	else if(nhap==Down){
			  		if(a==0){
						gotoxy(toaX,toaY+2);SetColor(4);cout<<"Du lieu ko duoc de trong";SetColor(7);
			  			goto Nhaplaiso;
					  }
					if(a>0) {
						gotoxy(toaX,toaY+2);cout<<"                        ";
						gotoxy(toaX,toaY);
					}
					if(wherex()<=82){
						gotoxy(97,toaY);
						return;
					}
					if(wherex()>=97)
					{
						gotoxy(49,toaY+5);
						return;
					}	
				}
				
			}
		}
		
		
	}while(1);
}
void XuLiNhapSo(int toaX, int toaY,int &a,int max_nhap,bool &Thoat)
{
	ShowCur(1);
	char nhap;
	int i=10;
	a=0;
	gotoxy(toaX,toaY);
	do{
		
		
		if(wherex()<=max_nhap+toaX+1)
		{
			nhap=getch();
			if(nhap=='0' || nhap=='1' || nhap=='2' ||nhap=='3' ||nhap=='4' ||nhap=='5' ||nhap=='6' ||nhap=='7' ||nhap=='8' || nhap=='9')
			{
				if(wherex()<=max_nhap+toaX+1){
					a=a*i+(nhap-'0');
					cout<<(nhap-'0');
				}
				
			}
			
			if(nhap==8 && wherex()>toaX||wherex()==max_nhap+toaX+1)
			{
				a/=10;
				gotoxy(wherex()-1,toaY);			
				cout<<" ";
				gotoxy(wherex()-1,toaY);	
			}
			
			if(nhap==Enter)
			{
				return;
			}
			if(nhap==Esc)
			{
				Thoat=TRUE;
					return;
			}
			
		}
		
		
	}while(1);
}
void NhapMaSach(int toaX, int toaY,string &str,int max_nhap,bool &Thoat)
{
	ShowCur(1);
	Normal();
	char nhap;
	int i=str.length()-1;
Nhaplai:
	gotoxy(toaX+str.length(),toaY);
	do{
		if(wherex()<=max_nhap+toaX+1)
		{
			nhap=getch();
			
			
			if(nhap=='0' || nhap=='1' || nhap=='2' ||nhap=='3' ||nhap=='4' ||nhap=='5' ||nhap=='6' ||nhap=='7' ||nhap=='8' || nhap=='9' || nhap=='_' || nhap=='-')			{
				++i;
				str.insert(str.begin()+i,nhap);
				if(wherex()<max_nhap+toaX+1){
					cout<<str[i];
				}
				if(i+1==3||i+1==7||i+1==10||i+1==3||i+1==15){
					++i;
					str.insert(str.begin()+i,'-');
					cout<<str[i];
				}
				if(i+1==17){
					++i;
					str.insert(str.begin()+i,'_');
					cout<<str[i];
				}
			}
			if(nhap==8 && wherex()>toaX||wherex()==max_nhap+toaX+1)
			{
				str.erase(str.begin()+i);
				gotoxy(wherex()-1,toaY);			
				cout<<" ";
				gotoxy(wherex()-1,toaY);
				i--;	
			}
			if(nhap==Enter)
			{
				return;	
			}
			if(nhap==Esc)
			{
				Thoat=TRUE;
				return;
			}
		}
		
		
	}while(1);
}
