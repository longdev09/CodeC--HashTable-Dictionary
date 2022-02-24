#include "Mylib.h"
#define DEAULT_LOAD_FACTOR 0.7
struct TuDien
{
	string Anh, Viet;
	string TuLoai;
	int stt = 0;
};
struct Node
{
	TuDien value;
	int  key;
	Node *next;
};
typedef Node* NodePtr;
struct HashTable {
	NodePtr *bucket;
	int size; //kich thuoc bang bam (so luong bucket)
	int n; //so luong phan tu tren bang bam
};
bool DocFile(string Name, HashTable &ht);

Node *CreateNode(int key, TuDien x);


void KhoiTaoList(Node *&Head);
void AddHead(Node *&Head, Node *q);
void KhoiTao(HashTable& ht, int capacity);

Node *CheckList(Node *Head, Node *p);
int TinhKey(string a);
int Hash(int key, int Size);
void XuatBucket(HashTable ht);
void removeAllHT(HashTable &ht);
void rehashing(HashTable &ht, int capacity_new);
void AddPhanTuVaoBangBam(HashTable &ht, Node *q);

void ChuanHoaChuoi(string &a);
int DemSoLuongPhanTuBucker(HashTable ht);
Node *TraTuDien(HashTable ht, string TuCanTim);
void Them1Tu(HashTable &ht, TuDien x);

bool DocVaoVanBan(string file, string &VanBan);
void XoaPhanTu(HashTable &ht, string x);
void ThayNghia(HashTable &ht, TuDien x);
