#include "CTDL.h"
void AddPhanTuVaoBangBam(HashTable &ht, Node *q)
{
	//bam khoa de xac dinh bucket
	int h = Hash(q->key, ht.size);
	//chen khoa tai bucket da xac dinh
	//kiem tra khoa co ton tai hay khong
	
	if (CheckList(ht.bucket[h], q) != NULL)
	{
		return;
	}
	else
	{
		//gia su chon theo cach them dau
		AddHead(ht.bucket[h], q);
		//tang kich thuoc n
		ht.n++;
	}
	//kiem tra chi so tai tren bang bam
	double loadFactor = ht.n *1.0 / ht.size;
	if (loadFactor > DEAULT_LOAD_FACTOR)
	{
		//THUC HIEN BAM LAI VOI KICH THUOC MOI
		rehashing(ht, ht.size * 2);
	}
}

void rehashing(HashTable &ht, int capacity_new)
{
	//tao ban bam moi voi kich thuoc moi
	HashTable ht_new;
	KhoiTao(ht_new, capacity_new);
	//chuyen du lieu tu ht cu sang ht moi
	for (int i = 0; i < ht.size; i++)
	{
		for (Node* p = ht.bucket[i]; p != NULL; p = p->next)
		{
			//lay key va value tu ht cu
			int key = p->key;
			TuDien value = p->value;
			Node *q = CreateNode(key, value);
			int h = Hash(key, ht_new.size);
			AddHead(ht_new.bucket[h], q);
			//tang kich thuoc n
			ht_new.n++;
		}
	}

	//giai phong ht cu
	HashTable ht_old = ht;
	ht = ht_new;
	removeAllHT(ht_old);
}
void removeHead(Node*& head)
{
	if (head != NULL)
	{
		Node* tmp = head;
		head = tmp->next;
		delete tmp;
	}
}
void removeAllList(Node*& head)
{
	while (head != NULL)
		removeHead(head);
}
void removeAllHT(HashTable &ht)
{
	for (int i = 0; i < ht.size; i++)
	{
		removeAllList(ht.bucket[i]);
	}
	ht.n = 0;
	//thu hoi lai vung nho
	delete[] ht.bucket;
	ht.size = 0;
}

Node *CreateNode(int key, TuDien x)
{
	Node *q = new(Node);
	if (q == NULL)
		cout << "Khong The Cap Phat";
	else
	{
		q->key = key;
		q->value = x;
		q->next = NULL;
	}
	return q;
}
void KhoiTaoList(Node *&Head)
{
	Head = NULL;
}
void AddHead(Node *&Head, Node *q)
{
	if (Head == NULL)
	{
		Head = q;
	}
	else
	{
		q->next = Head;
		Head = q;
	}
}
Node *CheckList(Node *Head, Node *p)
{
	for (Node *q = Head; q != NULL; q = q->next)
	{
		if (q->value.Anh == p->value.Anh)
			return q;
	}
	return NULL;
}


// Ham Bam
void KhoiTao(HashTable& ht, int capacity)
{
	ht.size = capacity;
	ht.n = 0;
	ht.bucket = new NodePtr[capacity];
	for (int i = 0; i < ht.size; i++)
	{
		KhoiTaoList(ht.bucket[i]);
	}
}

int Hash(int key, int Size)
{
	return key % Size;
}
void ChuanHoaChuoi(string &a)
{
	if (a[0] >= 97 && a[0] <= 122)
	{
		a[0] -= 32;
	}
	for (int i = 1; i < a.length(); i++)
	{
		if (a[i] >= 65 && a[i] <= 90)
		{
			a[i] += 32;
		}
	}
}
bool DocFile(string Name, HashTable &ht)
{

	TuDien x;
	ifstream in;
	in.open(Name, ios::in);

	if (in.fail())
	{
		return false;
	}
	while (!in.eof())
	{

		getline(in, x.Anh, ':');
		getline(in, x.TuLoai, ':');
		getline(in, x.Viet, '\n');
		ChuanHoaChuoi(x.Anh);
		ChuanHoaChuoi(x.Viet);
		int key = TinhKey(x.Anh);
		Node *q = CreateNode(key, x);
		AddPhanTuVaoBangBam(ht, q);
	}
	return true;

}
int TinhKey(string a)
{
	int key = 0;
	for (int i = 0; i < a.length(); i++)
	{
		key += a[i];
	}
	return key;
}
int DemSoLuongPhanTuBucker(HashTable ht)
{
	int Dem = 0;
	for (int i = 0; i < ht.size; i++)
	{
		if (ht.bucket[i] != NULL)
		{
			for (Node *p = ht.bucket[i]; p != NULL; p = p->next)
			{
				p->value.stt = Dem += 1;
			}
		}
	}
	return Dem;
}
Node *TraTuDien(HashTable ht, string TuCanTim)
{
	TuDien a;
	a.Anh = TuCanTim;
	int key = TinhKey(a.Anh);
	Node *q = CreateNode(key, a);
	int h = Hash(key, ht.size);
	Node *p = CheckList(ht.bucket[h], q);
	if (p == NULL)
	{
		return false; // Khong tim thay tu dien

	}
	else
	{
		return p;
	}
}

void Them1Tu(HashTable &ht, TuDien x)
{
	int key = TinhKey(x.Anh);
	Node *q = CreateNode(key, x);
	AddPhanTuVaoBangBam(ht, q);
}
bool DocVaoVanBan(string file, string &VanBan)
{

	ResetColor();
	string tmp;
	int i = 9;
	ifstream in;
	in.open(file, ios::in);
	if (in.fail())
	{
		return false;
	}
	else
	{
		while (!in.eof())
		{
			getline(in, tmp);
			gotoXY(80, i);
			cout << tmp;
			VanBan += tmp;
			i += 1;
		}
	}
}
void XoaDau(Node *&head)
{
	if (head == NULL)
		return;
	else
	{
		Node* t = head;
		head = head->next;
		t->next = NULL;
		delete t;
	}

}
void XoaNodepSauq(Node *&head, Node *p)
{
	Node* q = head;
	while (q->next != p)
	{
		q = q->next;
	}
	q->next = p->next;
	p->next = NULL;
	delete(p);
}
void removeNode(Node *&head, string x)
{
	for (Node * q = head; q != NULL; q = q->next)
	{
		if (q->value.Anh == x)
		{
			if (q == head)
				XoaDau(head);
			else
				XoaNodepSauq(head, q);
			break;
		}
	}
}
void XoaPhanTu(HashTable &ht, string x)
{
	int key = TinhKey(x);
	int h = Hash(key, ht.size);
	removeNode(ht.bucket[h], x);
}
void ThayNghia(HashTable &ht, TuDien x)
{
	int key = TinhKey(x.Anh);
	int h = Hash(key, ht.size);
	for (Node *q = ht.bucket[h]; q != NULL; q = q->next)
	{
		if (q->value.Anh == x.Anh)
		{
			q->value.Viet = x.Viet;
			break;
		}
	}
}