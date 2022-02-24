#include "GiaoDien.h"
// Ki tu
#define KiTuNgang 196
#define KiTuDoc 179

// PHIM
const int MuiTenLen = 72, MuiTenXuong = 80, MuiTenTrai = 75, MuiTenPhai = 77;
const int PhimESC = 27, PhimENTER = 13;
//CONSOL
const int wight = 1500, hight = 800;
// TOA DO
const int xBatDau = 5, xKetThuc = 175;
const int yBatDau = 5, yKetThuc = 50;
const int yKetThuc_Menu = 20;
const int yMid = 11, xMid = 70;
const int xMeNu = 20, yMeNu = 28;
const char* Menu[100] = {
	"DOC FILE TU DIEN",
	"XUAT DANH SACH CAC TU DIEN HIEN CO",
	"TIM NGHIA CUA 1 TU TIENG ANH",
	"THEM 1 TU DIEN VAO DANH SACH",
	"DOC VAO 1 DOAN VAN TIENG ANH",
	"XOA 1 TU DIEN RA KHOI DANH SACH TU DIEN",
	"DIEU CHINH NGHIA CUA 1 TU"
};
const int Max_MeNU = 7;
HashTable ht;
void XuLy()
{
	resizeConsole(wight, hight);
	KhoiTao(ht, 10);
	ShowCur(false);
	vetuong();
	XuatMeNu();
	Control();
}
void VeKhungXuatMenu()
{
	textcolor(8);
	for (int x = xBatDau + 5; x <= xMid - 5; x++)
	{
		gotoXY(x, yMid + 12);
		cout << char(219);
		gotoXY(x, 40);
		cout << char(219);
	}
	//In hai cot
	for (int y = yMid + 12; y <= 40; y++)
	{
		gotoXY(xBatDau + 5, y);
		cout << char(219);
		gotoXY(xMid - 5, y);
		cout << char(219);
	}
}
void vetuong()
{
	textcolor(11);
	// in hai hang
	for (int x = xBatDau; x <= xKetThuc; x++)
	{
		gotoXY(x, yBatDau);
		cout << char(219);
		gotoXY(x, yKetThuc);
		cout << char(219);


	}
	//In hai cot
	for (int y = yBatDau; y <= yKetThuc; y++)
	{
		gotoXY(xBatDau, y);
		cout << char(219);
		gotoXY(xKetThuc, y);
		cout << char(219);
	}
	// In Hang ngang mid
	for (int x = xBatDau + 1; x < xMid; x++)
	{
		gotoXY(x, yBatDau + 14);
		cout << char(219);
	}
	//// In Thanh doc mid
	for (int y = yBatDau; y <= yKetThuc; y++)
	{
		gotoXY(xMid, y);
		cout << char(219);
	}
	//ThanhVien();
	ThanhVien();
	HuongDan();
}
void ThanhVien()
{

	textcolor(31);
	gotoXY(27, yBatDau + 2);
	cout << "THANH VIEN NHOM 4";
	textcolor(6);
	gotoXY(19, yBatDau + 4);
	cout << "2001200504 - Nguyen Bach Long (Nhom truong)";
	gotoXY(19, yBatDau + 6);
	cout << "2001200771 - Pham Tran Tan Dat";
	gotoXY(19, yBatDau + 8);
	cout << "2001200513 - Pham Vu Huy";
	gotoXY(19, yBatDau + 10);
	cout << "2001200591 - Lu Hoang Duy";
	gotoXY(19, yBatDau + 12);
	cout << "2001200213 - Huynh Nguyen Thanh Cong";
}
void XuatMeNu()
{
	VeKhungXuatMenu();
	textcolor(47);
	gotoXY(xMeNu + 13, yMeNu - 2);
	cout << "MENU";
	for (int i = 0; i < Max_MeNU; i++)
	{
		setColorBGTextXY(xMeNu - 3, yMeNu + i, 14, 0, Menu[i]);
	}
}
void Control()
{
	ResetColor();
	int i_menu = 0;
	setColorBGTextXY(xMeNu - 3, yMeNu + i_menu, 14, 8, Menu[i_menu]);
	int tam = i_menu;
	while (true)
	{
		tam = i_menu;
		if (_kbhit())
		{
			char c = _getch();
			if (c == PhimESC)
			{
				break;
			}
			else if (c == PhimENTER)
			{
				XoaManHinhChinh();
				ThucHienChuongTrinh(i_menu);
			}
			else if (c == -32)
			{
				c = _getch();
				if (c == MuiTenLen) // mui ten di len
				{
					if (i_menu == 0)
					{
						i_menu = Max_MeNU - 1;
					}
					else
					{
						i_menu--;
					}
				}
				else if (c == MuiTenXuong) // mui ten di xuong
				{
					if (i_menu == Max_MeNU - 1)
					{
						i_menu = 0;
					}
					else
					{
						i_menu++;
					}
				}
			}
		}
		if (tam != i_menu)
		{
			setColorBGTextXY(xMeNu - 3, yMeNu + tam, 14, 0, Menu[tam]);
			setColorBGTextXY(xMeNu - 3, yMeNu + i_menu, 14, 8, Menu[i_menu]);
		}
	}
}
void HuongDan()
{
	gotoXY(xBatDau + 5, yKetThuc - 5);
	cout << "EXIT: ESC";
	gotoXY(xBatDau + 24, yKetThuc - 5);
	cout << "ENTER: CHON";
	gotoXY(xBatDau + 48, yKetThuc - 5);
	cout << char(30) << ',' << char(31) << " :Di chuyen";
}
void ThucHienChuongTrinh(int i_menu)
{
	DemSoLuongPhanTuBucker(ht); // set lai so phan tu
	ResetColor();
	//*************************Chuc nang 1***********************
	if (i_menu == 0)
	{
		ChucNang0();
	}
	if (i_menu == 1)
	{
		ChucNang1();
	}
	if (i_menu == 2)
	{
		ChucNang2();
	}
	if (i_menu == 3)
	{
		ChucNang3();
	}
	if (i_menu == 4)
	{
		ChucNang4();
	}
	if (i_menu == 5)
	{
		ChucNang5();
	}
	if (i_menu == 6)
	{
		ChucNang6();
	}

}

// Chuc Nang 
void ChucNang0()
{
	char str[21] = "";
	char c;
	while (true)
	{
		VeKhungNhap(108, 17, 150, 19, "NHAP VAO TEN FILE");
		ResetColor();
		bool check = true;
		bool KtNhap = true;
		KtNhap = NhapKiTu(str, 20);
		if (KtNhap == false)
		{
			XoaManHinhChinh();
			return;
		}
		if (strcmpi(str, "") == 0)
		{
			textcolor(4);
			gotoXY(113, 30);
			cout << "KHONG DUOC BO TRONG!";
			gotoXY(100, 31);
			cout << "NHAN ENTER DE NHAP LAI HOAC ESC DE THOAT";
			while (true)
			{
				char c = _getch();
				if (c == PhimENTER)
				{
					XoaManHinhChinh();
					break;
				}
				else if (c == PhimESC)
				{
					XoaManHinhChinh();
					return;
				}
			}
		}
		else
		{
			check = DocFile(str, ht);
			if (check == false)
			{

				textcolor(4);

				gotoXY(113, 30);
				cout << "DOC FILE THAT BAI";
				gotoXY(100, 31);
				cout << "NHAN ENTER DE NHAP LAI HOAC ESC DE THOAT";
				while (true)
				{
					char c = _getch();
					if (c == PhimENTER)
					{
						break;
					}
					else if (c == PhimESC)
					{
						XoaManHinhChinh();
						return;
					}
				}
				XoaManHinhChinh();
				Xoa_Chuoi(str);
			}
			else
			{
				gotoXY(113, 30);
				cout << "DOC FILE THANH CONG";
				gotoXY(115, 31);
				cout << "ESC DE THOAT";
				while (true)
				{
					char c = _getch();
					if (c == PhimESC)
					{
						XoaManHinhChinh();
						return;
					}
				}
			}
		}

	}
}
void ChucNang1()
{
	ResetColor();

	/*int xDlieu = 84, yDlieu = 13, xDlieuKt = 165, yDlieuKt = 45;*/
	int DemTu = DemSoLuongPhanTuBucker(ht);
	ResetColor();
	// In Tieu De

	// Cac Thong So
	int MaxShow = 27;
	int MaxPage = (DemTu - 1) / MaxShow + 1;
	int page = 1;
	int z = 1;
	int i = 0;
	Node *d = NULL;
	while (true)
	{
		textcolor(87);
		gotoXY(118, 10);
		cout << "DANH SACH TU DIEN";
		VeKhungXuatDanhSach(84, 13, 165, 45);
		while (true)
		{

			int Show = (page - 1) * MaxShow;
			int GioiHan = (DemTu - Show >= MaxShow) ? MaxShow : DemTu - Show;
			int c = 1;
			int x = 15;
			for (; i < ht.size; i++)
			{
				Node * q;
				if (c <= GioiHan)
				{
					if (d != NULL)
					{
						q = d;
						d = NULL;
						i--;
					}
					else
						q = ht.bucket[i];
					if (q != NULL)
					{
						XuatDuLieu(q, d, z, GioiHan, x, c);
					}
				}
				else
				{
					break;
				}

			}
			gotoXY(122, 44);
			cout << "Trang :" << page << "/" << MaxPage;
			while (true)
			{
				if (_kbhit())
				{
					char c = _getch();
					if (c == 27)
					{
						XoaManHinhChinh();
						return;
					}
					//else if (c == 75)//trai
					//{
					//	if (page > 1)
					//	{
					//		page--;
					//		break;
					//	}
					//}
					else if (c == 77) //phai
					{
						if (page < MaxPage)
						{
							page++;
							break;
						}
					}
				}
			}
			XoaManHinhChinh();
			break;
		}
	}
}
void ChucNang2()
{
	//int xDlieu = 110, yDlieu = 17, xDlieuKt = 160, yDlieuKt = 19;
	char str[50] = "";
	while (true)
	{

		VeKhungNhap(110, 17, 160, 19, "NHAP VAO TU DIEN CAN TIM: ");
		ResetColor();
		bool check = true;
		bool KtNhap = true;
		KtNhap = NhapKiTu(str, 50);
		if (KtNhap == false)
		{
			XoaManHinhChinh();
			return;
		}
		if (strcmpi(str, "") == 0)
		{
			textcolor(4);
			gotoXY(113, 45);
			cout << "KHONG DUOC BO TRONG!";
			gotoXY(100, 47);
			cout << "NHAN ENTER DE NHAP LAI HOAC ESC DE THOAT";
			while (true)
			{
				char c = _getch();
				if (c == PhimENTER)
				{
					XoaManHinhChinh();
					break;
				}
				else if (c == PhimESC)
				{
					XoaManHinhChinh();
					return;
				}
			}
		}
		else
		{
			string TuCanTim = str;
			ChuanHoaChuoi(TuCanTim);
			Node *q = TraTuDien(ht, TuCanTim);
			check = q; // Kiem tra tu có kh
			if (check == false)
			{
				textcolor(4);
				gotoXY(113, 45);
				cout << "TU BAN TIM KHONG CO TRONG TU DIEN\n";
				gotoXY(110, 47);
				cout << "NHAN ENTER DE NHAP LAI HOAC ESC DE THOAT";
				while (true)
				{
					char c = _getch();
					if (c == PhimENTER)
					{
						XoaManHinhChinh();
						break;
					}
					else if (c == PhimESC)
					{
						XoaManHinhChinh();
						return;
					}
				}
				Xoa_Chuoi(str);
			}
			else
			{
				/*int xDlieu = 84, yDlieu = 13, xDlieuKt = 165, yDlieuKt = 20;*/
				// Xuat Nghia
				VeKhungXuatDanhSach(84, 30, 165, 45);
				textcolor(14);
				gotoXY(84, 32);
				cout << q->value.stt;
				gotoXY(95, 32);
				cout << q->value.Anh;
				gotoXY(125, 32);
				cout << q->value.TuLoai;
				gotoXY(134, 32);
				cout << q->value.Viet;
				while (true)
				{
					char c = _getch();
					if (c == PhimESC)
					{
						XoaManHinhChinh();
						return;
					}
					if (c == PhimENTER)
					{
						XoaManHinhChinh();
						Xoa_Chuoi(str);
						break;
					}
				}
			}
		}
	}
}
void ChucNang3()
{
	TuDien x;
	string TiengAnh, TuLoai, Nghia;
	char str[50] = "";
	while (true)
	{
		//int xDlieu = 110, yDlieu = 17, xDlieuKt = 160, yDlieuKt = 19;
		//int xDlieu = 110, yDlieu = 21, xDlieuKt = 160, yDlieuKt = 23;
		//int xDlieu = 110, yDlieu = 25, xDlieuKt = 160, yDlieuKt = 27;
		VeKhungNhap(110, 17, 160, 19, "NHAP VAO TU TIENG ANH :");
		VeKhungNhap(110, 21, 160, 23, "NHAP VAO TU LOAI : ");
		VeKhungNhap(110, 25, 160, 27, "NHAP VAO NGHIA TIENG VIET : ");
		ResetColor();
		bool KtNhap = true;
		KtNhap = NhapKiTu(str, 50);
		if (KtNhap == false)
		{
			XoaManHinhChinh();
			return;
		}
		if (strcmpi(str, "") == 0)
		{
			textcolor(4);
			gotoXY(113, 45);
			cout << "KHONG DUOC BO TRONG!";
			gotoXY(100, 47);
			cout << "NHAN ENTER DE NHAP LAI HOAC ESC DE THOAT";
			while (true)
			{
				char c = _getch();
				if (c == PhimENTER)
				{
					XoaManHinhChinh();
					break;
				}
				else if (c == PhimESC)
				{
					XoaManHinhChinh();
					return;
				}
			}
		}
		else
		{
			TiengAnh = str;
			ChuanHoaChuoi(TiengAnh);
			Node *q = TraTuDien(ht, TiengAnh);
			if (q != false)
			{
				textcolor(4);
				gotoXY(113, 45);
				cout << "TU DA TOAN TAI TRONG TU DIEN\n";
				gotoXY(100, 47);
				cout << "NHAN ENTER DE NHAP LAI HOAC ESC DE THOAT";
				while (true)
				{
					char c = _getch();
					if (c == PhimENTER)
					{
						XoaManHinhChinh();
						break;
					}
					else if (c == PhimESC)
					{
						XoaManHinhChinh();
						return;
					}
				}
				Xoa_Chuoi(str);
			}
			else
			{
				gotoXY(114, 22);
				getline(cin, TuLoai);
				gotoXY(114, 26);
				getline(cin, Nghia);
				ChuanHoaChuoi(TiengAnh);
				x.Anh = TiengAnh;
				x.TuLoai = TuLoai;
				x.Viet = Nghia;
				Them1Tu(ht, x);
				gotoXY(120, 45);
				cout << "THEM THANH CONG!";
				gotoXY(105, 47);
				cout << "NHAN ESC DE THOAT HOAC ENTER DE THEM TU MOI!";
				while (true)
				{
					char c = _getch();
					if (c == PhimESC)
					{
						XoaManHinhChinh();
						return;
					}
					if (c == PhimENTER)
					{
						XoaManHinhChinh();
						Xoa_Chuoi(str);
						break;
					}
				}
			}

		}
	}
}
void ChucNang4()
{
	string VanBan;
	int Sl = 0;
	textcolor(6);
	gotoXY(xMid + 45, yBatDau + 2);
	cout << "VAN BAN SAU KHI DOC!";
	DocVaoVanBan("VanBan.txt", VanBan);

	string TuVanBan[1000]; // 
	LayTuVanBan(VanBan, TuVanBan, Sl); // Tach tu ra khoi van ban
	ResetColor();
	int MaxShow = 11;
	int MaxPage = (Sl - 1) / MaxShow + 1;
	int page = 1;
	while (true)
	{
		while (true)
		{
			VeKhungXuatTuChuaThem();
			int ToaDoaBatDau = 32;
			int Show = (page - 1) * MaxShow;
			int GioiHan = (Sl - Show >= MaxShow) ? MaxShow : Sl - Show;
			int tmp = 0;
			for (int i = 0; i < GioiHan && i + Show < Sl; i++)
			{

				gotoXY(107, ToaDoaBatDau + tmp);
				cout << i + Show + 1;
				gotoXY(115, ToaDoaBatDau + tmp);
				cout << TuVanBan[i + Show];
				tmp += 1;
			}
			gotoXY(110, 47);
			cout << "ENTER DE THEM HOAC ESC DE THOAT";
			gotoXY(118, 44);
			cout << "Trang :" << page << "/" << MaxPage;
			while (true)
			{
				if (_kbhit())
				{
					char c = _getch();
					if (c == 27)
					{
						XoaManHinhChinh();
						return;
					}
					if (c == PhimENTER)
					{
						TuDien x;
						XoaManHinhChinh();
						for (int i = 0; i < Sl; i++)
						{
							VeKhungNhap(110, 21, 160, 23, "NHAP VAO TU LOAI : ");
							VeKhungNhap(110, 25, 160, 27, "NHAP VAO NGHIA TIENG VIET : ");
							ResetColor();
							x.Anh = TuVanBan[i];
							gotoXY(75, 19);
							cout << "Tu tieng anh: ";
							gotoXY(114, 19);
							cout << x.Anh;
							gotoXY(114, 22);
							getline(cin, x.TuLoai);
							gotoXY(114, 26);
							getline(cin, x.Viet);
							Them1Tu(ht, x);
							gotoXY(120, 45);
							cout << "THEM THANH CONG!";
							gotoXY(105, 47);
							cout << "NHAN ESC DE THOAT HOAC ENTER DE THEM TU MOI!";
							while (true)
							{
								char c = _getch();
								if (c == PhimESC)
								{
									XoaManHinhChinh();
									return;
								}
								if (c == PhimENTER)
								{
									XoaManHinhChinh();
									break;
								}
							}
						}
					}
					else if (c == 75)//trai
					{
						if (page > 1)
						{
							page--;
							break;
						}
					}
					else if (c == 77) //phai
					{
						if (page < MaxPage)
						{
							page++;
							break;
						}
					}
				}
			}
			XoaManHinh2();
			break;
		}
	}
}
void ChucNang5()
{

	string TuCanXoa;
	char str[50] = "";
	while (true)
	{
		VeKhungNhap(110, 17, 160, 19, "NHAP VAO TU TIENG ANH :");
		ResetColor();
		bool check = true;
		bool KtNhap = true;
		KtNhap = NhapKiTu(str, 50);
		if (KtNhap == false)
		{
			XoaManHinhChinh();
			return;
		}
		if (strcmpi(str, "") == 0)
		{
			textcolor(4);
			gotoXY(113, 45);
			cout << "KHONG DUOC BO TRONG!";
			gotoXY(100, 47);
			cout << "NHAN ENTER DE NHAP LAI HOAC ESC DE THOAT";
			while (true)
			{
				char c = _getch();
				if (c == PhimENTER)
				{
					XoaManHinhChinh();
					break;
				}
				else if (c == PhimESC)
				{
					XoaManHinhChinh();
					return;
				}
			}
		}
		else
		{
			TuCanXoa = str;
			ChuanHoaChuoi(TuCanXoa);
			Node *q = TraTuDien(ht, TuCanXoa);
			check = q; // Kiem tra tu có kh
			if (check == false)
			{
				textcolor(4);
				gotoXY(113, 45);
				cout << "TU BAN TIM KHONG CO TRONG TU DIEN\n";
				gotoXY(100, 47);
				cout << "NHAN ENTER DE NHAP LAI HOAC ESC DE THOAT";
				while (true)
				{
					char c = _getch();
					if (c == PhimENTER)
					{
						XoaManHinhChinh();
						break;
					}
					else if (c == PhimESC)
					{
						XoaManHinhChinh();
						return;
					}
				}
				Xoa_Chuoi(str);
			}
			else
			{
				XoaPhanTu(ht, TuCanXoa);
				gotoXY(120, 45);
				cout << "XOA THANH CONG!";
				gotoXY(105, 47);
				cout << "NHAN ESC DE THOAT HOAC ENTER DE XOA NUA!";
				while (true)
				{
					char c = _getch();
					if (c == PhimESC)
					{
						XoaManHinhChinh();
						return;
					}
					if (c == PhimENTER)
					{
						XoaManHinhChinh();
						Xoa_Chuoi(str);
						break;
					}
				}
			}
		}
	}

}
void ChucNang6()
{
	TuDien x;
	string TuCanSua;
	string Nghia;
	char str[50] = "";
	while (true)
	{
		ResetColor();
		VeKhungNhap(110, 17, 160, 19, "NHAP VAO TU TIENG ANH :");
		bool check = true;
		bool KtNhap = true;
		KtNhap = NhapKiTu(str, 50);
		if (KtNhap == false)
		{
			XoaManHinhChinh();
			return;
		}
		if (strcmpi(str, "") == 0)
		{
			textcolor(4);
			gotoXY(113, 30);
			cout << "KHONG DUOC BO TRONG!";
			gotoXY(100, 31);
			cout << "NHAN ENTER DE NHAP LAI HOAC ESC DE THOAT";
			while (true)
			{
				char c = _getch();
				if (c == PhimENTER)
				{
					XoaManHinhChinh();
					break;
				}
				else if (c == PhimESC)
				{
					XoaManHinhChinh();
					return;
				}
			}
		}
		else
		{
			TuCanSua = str;
			ChuanHoaChuoi(TuCanSua);
			Node *q = TraTuDien(ht, TuCanSua);
			check = q; // Kiem tra tu có kh
			if (check == false)
			{
				textcolor(4);
				gotoXY(113, 30);
				cout << "TU BAN TIM KHONG CO TRONG TU DIEN\n";
				gotoXY(100, 31);
				cout << "NHAN ENTER DE NHAP LAI HOAC ESC DE THOAT";
				while (true)
				{
					char c = _getch();
					if (c == PhimENTER)
					{
						XoaManHinhChinh();
						break;
					}
					else if (c == PhimESC)
					{
						XoaManHinhChinh();
						return;
					}
				}
				Xoa_Chuoi(str);
			}
			else
			{
				// Xuat Nghia
				VeKhungNhap(110, 25, 160, 27, "NHAP VAO NGHIA TIENG VIET : ");
				gotoXY(114, 26);
				getline(cin, Nghia);
				x.Anh = TuCanSua;
				x.Viet = Nghia;
				ThayNghia(ht, x);
				gotoXY(120, 45);
				cout << "DIEU CHINH NGHIA THANH CONG!";
				gotoXY(105, 47);
				cout << "NHAN ESC DE THOAT HOAC ENTER DE DIEU CHINH 1 TU KHAC NUA!";
				while (true)
				{
					char c = _getch();
					if (c == PhimESC)
					{
						XoaManHinhChinh();
						return;
					}
					if (c == PhimENTER)
					{
						XoaManHinhChinh();
						Xoa_Chuoi(str);
						break;
					}
				}
			}
		}
	}
}
void Xoa_Chuoi(char str[])
{
	int lenght = strlen(str);
	for (int i = lenght - 1; i >= 0; i--)
		str[i] = '\0';
}
void VeKhungNhap(int xDlieu, int yDlieu, int xDlieuKt, int yDlieuKt, string Text)
{
	textcolor(11);
	//int xDlieu = 110, yDlieu = 17, xDlieuKt = 160, yDlieuKt = 19;
	for (int x = xDlieu; x < xDlieuKt; x++)
	{
		// Thanh ngang tren
		gotoXY(x, yDlieu);
		cout << char(196);
		// Thanh ngang duoi
		gotoXY(x, yDlieuKt);
		cout << char(196);
	}
	for (int y = yDlieu; y <= yDlieuKt; y++)
	{
		//Thanh doc dau
		gotoXY(xDlieu, y);
		cout << char(179);
		//Thanh doc cuoi
		gotoXY(xDlieuKt, y);
		cout << char(179);
	}
	gotoXY(xDlieu, yDlieu);
	cout << char(218);
	gotoXY(xDlieuKt, yDlieu);
	cout << char(191);
	gotoXY(xDlieu, yDlieuKt);
	cout << char(192);
	gotoXY(xDlieuKt, yDlieuKt);
	cout << char(217);
	textcolor(9);
	gotoXY(xDlieu - 35, yDlieu + 1);
	cout << Text;
}
void VeKhungXuatDanhSach(int xDlieu, int yDlieu, int xDlieuKt, int yDlieuKt)
{

	ResetColor();

	// In Cac Tieu De
	textcolor(3);
	gotoXY(xDlieu + 1, yDlieu);
	cout << "STT";
	gotoXY(xDlieu + 20, yDlieu);
	cout << "ANH";
	gotoXY(xDlieu + 38, yDlieu);
	cout << "TU LOAI";
	gotoXY(xDlieu + 55, yDlieu);
	cout << "NGHIA TIENG VIET";
	textcolor(11);
	//-------------------In Khung Cho Tieu De-----------
	for (int x = xDlieu - 2; x < xDlieuKt; x++)
	{
		// Thanh ngang tren
		gotoXY(x, yDlieu - 1);
		cout << char(KiTuNgang);
		// Thanh ngang duoi
		gotoXY(x, yDlieu + 1);
		cout << char(KiTuNgang);
	}

	// -----------In Thanh Doc Hai Ben-------
	for (int y = yDlieu - 1; y <= yDlieuKt; y++)
	{
		//Thanh doc dau
		gotoXY(xDlieu - 2, y);
		cout << char(KiTuDoc);
		//Thanh doc cuoi
		gotoXY(xDlieuKt, y);
		cout << char(KiTuDoc);
	}
	//-------Thanh Ngang Cuoi Khung------------
	for (int x = xDlieu - 2; x < xDlieuKt; x++)
	{
		// Thanh ngang tren
		gotoXY(x, yDlieuKt - 2);
		cout << char(KiTuNgang);
		// Thanh ngang duoi
		gotoXY(x, yDlieuKt);
		cout << char(KiTuNgang);
	}
	//----------- In Cac Thanh Doc Ben Trong Khung
	// Doc STT
	for (int y = yDlieu - 1; y <= yDlieuKt - 2; y++)
	{
		//Thanh doc dau
		gotoXY(xDlieu + 7, y);
		cout << char(KiTuDoc);
		//Thanh doc cuoi
	}
	// Doc Tieng Anh
	for (int y = yDlieu - 1; y <= yDlieuKt - 2; y++)
	{
		//Thanh doc dau
		gotoXY(xDlieu + 37, y);
		cout << char(KiTuDoc);
		//Thanh doc cuoi
	}
	// Doc Loai
	for (int y = yDlieu - 1; y <= yDlieuKt - 2; y++)
	{
		//Thanh doc dau
		gotoXY(xDlieu + 47, y);
		cout << char(KiTuDoc);
		//Thanh doc cuoi
	}
	//-------Bo cac goc-----------
	gotoXY(xDlieu - 2, yDlieu - 1);
	cout << char(218);
	gotoXY(xDlieu - 2, yDlieu + 1);
	cout << char(195);
	gotoXY(xDlieuKt, yDlieu - 1);
	cout << char(191);
	gotoXY(xDlieuKt, yDlieu + 1);
	cout << char(180);
	BoGocGiuaTren(xDlieu + 7, yDlieu - 1);
	BoGocGiuaDuoi(xDlieu + 7, yDlieu + 1);
	BoGocGiuaTren(xDlieu + 37, yDlieu - 1);
	BoGocGiuaDuoi(xDlieu + 37, yDlieu + 1);
	BoGocGiuaTren(xDlieu + 47, yDlieu - 1);
	BoGocGiuaDuoi(xDlieu + 47, yDlieu + 1);

	// bo cac goc duoi

	BoGocGiuaCuoi(xDlieu + 7, yDlieuKt - 2);
	BoGocGiuaCuoi(xDlieu + 37, yDlieuKt - 2);
	BoGocGiuaCuoi(xDlieu + 47, yDlieuKt - 2);

	gotoXY(xDlieu - 2, yDlieuKt - 2);
	cout << char(195);
	gotoXY(xDlieuKt, yDlieuKt - 2);
	cout << char(180);
	gotoXY(xDlieu - 2, yDlieuKt);
	cout << char(192);
	gotoXY(xDlieuKt, yDlieuKt);
	cout << char(217);
}
void XuatDuLieu(Node *q, Node *&d, int &z, int GioiHan, int &x, int &c)
{
	textcolor(14);
	for (Node *p = q; p != NULL; p = p->next)
	{
		if (c <= GioiHan)
		{
			gotoXY(86, x);
			cout << z;
			gotoXY(93, x);
			cout << p->value.Anh;
			gotoXY(125, x);
			cout << p->value.TuLoai;
			gotoXY(133, x);
			cout << p->value.Viet;
			x += 1;
			z += 1;
			c += 1;
		}
		else
		{
			if (p != NULL)
				d = p;
			return;
		}

	}
}
string Tao_Chuoi(int SoLuong_KyTu, char kytu)
{
	if (SoLuong_KyTu <= 0)
		return "";
	string str = "";
	int tam = 0;
	while (tam < SoLuong_KyTu)
	{
		str.insert(str.begin() + tam++, kytu);
	}
	return str;
}
void XoaManHinhChinh()
{
	ResetColor();
	ShowCur(1);

	string str = Tao_Chuoi(xKetThuc - xMid - 1, ' ');
	for (int i = yMid - 4; i < yKetThuc; i++)
	{
		gotoXY(xMid + 1, i);
		cout << str;
		ShowCur(false);
	}
}
void BoGocGiuaTren(int xDlieu, int yDlieu)
{
	gotoXY(xDlieu, yDlieu);
	cout << char(194);

}
void BoGocGiuaDuoi(int xDlieu, int yDlieu)
{
	gotoXY(xDlieu, yDlieu);
	cout << char(197);
}
void BoGocGiuaCuoi(int xDlieu, int yDlieuKt)
{
	gotoXY(xDlieu, yDlieuKt);
	cout << char(193);
}
bool NhapKiTu(char str[], int SoLuongKyTu)
{

	int xDlieu = 114, yDlieu = 18;
	while (true)
	{

		char c = _getch();
		ShowCur(true);
		if ((strlen(str) >= 0 && strlen(str) < SoLuongKyTu) /*&& ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')*/)
		{
			gotoXY(xDlieu + 1 + strlen(str), yDlieu);
			cout << c;
		}
		if (c == PhimENTER) // ENTER
		{
			return true;
		}
		else
			if (c == PhimESC)// ESC
			{
				return false;
			}
			else if (c == 8) // BACKSPACE
			{
				if (strlen(str) > 0)
				{
					gotoXY(xDlieu + 1 + strlen(str) - 1, yDlieu);
					cout << " ";
					gotoXY(xDlieu + 1 + strlen(str) - 1, yDlieu);
					str[strlen(str) - 1] = '\0';
				}
			}
			else
			{
				if (strlen(str) < SoLuongKyTu /*((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))*/)
				{
					str[strlen(str)] = c;
					str[strlen(str)] = '\0';
				}
			}

	}
}
void VeKhungXuatTuChuaThem()
{

	ResetColor();
	int xDlieu = 105, yDlieu = 30, xDlieuKt = 140, yDlieuKt = 45;
	// In Cac Tieu De
	gotoXY(xDlieu + 1, yDlieu);
	cout << "STT";
	gotoXY(xDlieu + 20, yDlieu);
	cout << "ANH";
	//-------------------In Khung Cho Tieu De-----------
	for (int x = xDlieu - 2; x < xDlieuKt; x++)
	{
		// Thanh ngang tren
		gotoXY(x, yDlieu - 1);
		cout << char(KiTuNgang);
		// Thanh ngang duoi
		gotoXY(x, yDlieu + 1);
		cout << char(KiTuNgang);
	}

	// -----------In Thanh Doc Hai Ben-------
	for (int y = yDlieu - 1; y <= yDlieuKt; y++)
	{
		//Thanh doc dau
		gotoXY(xDlieu - 2, y);
		cout << char(KiTuDoc);
		//Thanh doc cuoi
		gotoXY(xDlieuKt, y);
		cout << char(KiTuDoc);
	}
	//-------Thanh Ngang Cuoi Khung------------
	for (int x = xDlieu - 2; x < xDlieuKt; x++)
	{
		// Thanh ngang tren
		gotoXY(x, yDlieuKt - 2);
		cout << char(KiTuNgang);
		// Thanh ngang duoi
		gotoXY(x, yDlieuKt);
		cout << char(KiTuNgang);
	}
	//----------- In Cac Thanh Doc Ben Trong Khung
	// Doc STT
	for (int y = yDlieu - 1; y <= yDlieuKt - 2; y++)
	{
		//Thanh doc dau
		gotoXY(xDlieu + 7, y);
		cout << char(KiTuDoc);
		//Thanh doc cuoi
	}
	//Doc Tieng Anh
	//-------Bo cac goc-----------
	gotoXY(xDlieu - 2, yDlieu - 1);
	cout << char(218);
	gotoXY(xDlieu - 2, yDlieu + 1);
	cout << char(195);
	gotoXY(xDlieuKt, yDlieu - 1);
	cout << char(191);
	gotoXY(xDlieuKt, yDlieu + 1);
	cout << char(180);
	BoGocGiuaTren(xDlieu + 7, yDlieu - 1);
	BoGocGiuaDuoi(xDlieu + 7, yDlieu + 1);
	// bo cac goc duoi
	BoGocGiuaCuoi(xDlieu + 7, yDlieuKt - 2);
	gotoXY(xDlieu - 2, yDlieuKt - 2);
	cout << char(195);
	gotoXY(xDlieuKt, yDlieuKt - 2);
	cout << char(180);
	gotoXY(xDlieu - 2, yDlieuKt);
	cout << char(192);
	gotoXY(xDlieuKt, yDlieuKt);
	cout << char(217);
}
void XoaManHinh2()
{
	ResetColor();
	ShowCur(1);

	string str = Tao_Chuoi(39, ' ');
	for (int i = 29; i < yKetThuc; i++)
	{
		gotoXY(103, i);
		cout << str;
		ShowCur(false);
	}
}
void LayTuVanBan(string VanBan, string CTChuKoTimThay[], int &Sl)
{

	int n = 0;
	char c[50]; // LayKiTu
	VanBan.push_back(' '); // Them 1 Khoang de lam khoang trang cuoi
	int f = VanBan.length();
	for (int i = 0; i < f; i++)
	{

		if ((VanBan[i] >= 97 && VanBan[i] <= 122) || (VanBan[i] >= 65 && VanBan[i] <= 90))
		{
			c[n++] = VanBan[i];
		}
		else
		{
			c[n++] = '\0';
			if (c[0] != NULL && c[0] != ',' && c[0] != ' ')
			{
				string d = c;// Copy tu char sang string 
				ChuanHoaChuoi(d);
				if ((TraTuDien(ht, d) == NULL))
				{
					CTChuKoTimThay[Sl++] = d;
				}
			}
			n = 0;
		}
	}
}
