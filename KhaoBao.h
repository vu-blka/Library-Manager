
#include<iostream>
#include<string>
#include<fstream>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>
#include<mylib.h>
#include<sstream>

#define Esc 27
#define Up  72
#define Right  77
#define Left  75
#define Down  80

const int MaxNode = 10000;
const int  MAXDG = 20001;
const int SoNgayDcMuon=7;

int *mathe=new int[MAXDG];//bien dung de luu tru ma doc gia "tao ngau nhien tu dong" chua dung den
int sl_docgia=0;

int ma_chua_dung=0;
struct date
{
	int Ngay;
	int Thang;
	int Nam;
};
typedef struct date Date;

//=============DANH MUC SACH===========
struct DanhMucSach
{
	string ma_sach;
	int trang_thai;// 0:Duoc muon , 1:Dang muon, 2:Thanh li
	string vi_tri;
};
struct NodeDanhMuc
{
	DanhMucSach data;
	struct NodeDanhMuc *next;
};
typedef struct NodeDanhMuc Node_Dms ;
typedef struct NodeDanhMuc* LIST_DMS ;

struct DauSach
{
	string ISBN;
	string ten_sach;
	int so_trang;
	string tac_gia;
	int nam_xb;
	string the_loai;
	int so_luong_sach;
	int so_lan_muon;
	LIST_DMS dms;
};

struct MANGCONTRO
{
	int SoluongdauS;
	DauSach *nodesDauSach[10000];
};
typedef struct MANGCONTRO MCONTRO;

//=============MUON TRA===========
struct MuonTra
{
	string ma_sach;
	Date ngay_muon;
	Date ngay_tra;
	int trang_thai;//0 dang muon, 1 da tra, 2 lam mat(da den), 3 lam mat(chua den)
};
struct NodeMuonTra
{
	MuonTra data;
	NodeMuonTra *left;
	NodeMuonTra *right;
};
typedef struct NodeMuonTra NODE_MUON_TRA;
struct ListMuonTra
{
	NODE_MUON_TRA *First;
	NODE_MUON_TRA *Last;
};
typedef struct ListMuonTra LIST_MUON_TRA;

//=============DOC GIA===========
struct TheDocGia
{
	int ma_the;
	string ho;
	string ten;
	string phai;
	int trang_thai;// 0: Khoa, 1: Hoat Dong
	int SoSachDangMuon;
	int SoNgayQuaHan;
	LIST_MUON_TRA DS_MuonTra;
};
struct NodeDocGia
{
	TheDocGia data;
	NodeDocGia *pLeft;
	NodeDocGia *pRight; 
};
typedef struct NodeDocGia NODE_DOCGIA;
typedef NODE_DOCGIA* TREE;



