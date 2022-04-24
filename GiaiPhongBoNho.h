void XoaListDms(LIST_DMS& l)
{
	if (l == NULL)
	{
		return;
	}
	Node_Dms* t = l;
	l = l->next;
	delete t;
}
void XoaListMuonTra(LIST_MUON_TRA &l)
{
	if (l.First == NULL)
	{
		return;
	}
	else
	{
		NODE_MUON_TRA* t = l.First;
		if (l.First->right == NULL)
		{
			l.First = NULL;
		}
		else
		{
			l.First = l.First->right;
			l.First->left = NULL;
		}
		delete t;
	}
}
void DeleteTree(TREE& t)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		DeleteTree(t->pLeft);
		DeleteTree(t->pRight);
		// xoa danh sach muon tra
		while (t->data.DS_MuonTra.First != NULL)
		{
			XoaListMuonTra(t->data.DS_MuonTra);
		}
		delete t;
	}
}
void DeleteAll(TREE& t, MCONTRO& DauS)
{
	delete[]mathe;
	//Xoa Doc Gia
	DeleteTree(t);
	// Xoa Danh Muc Sach
	for (int i = 0; i < DauS.SoluongdauS; i++)
	{
		while (DauS.nodesDauSach[i]->dms != NULL)
		{
			XoaListDms(DauS.nodesDauSach[i]->dms);
		}
		// Xoa Dau Sach
		delete DauS.nodesDauSach[i];
	}
}
