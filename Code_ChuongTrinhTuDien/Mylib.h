// tránh đụng độ thư viện khi gọi chồng file lên nhau
#include <iomanip>
#include <fstream>
#include<iostream>
#include <string>
#include <conio.h>	
#include<ctime> /* thư viện hỗ trợ về thời gian thực */
#include "windows.h" // thư viện này bá đạo lắm nhé - chứa nhiều đồ chơi nek - cứ tìm hiểu dần dần s
using namespace std;
//======= lấy tọa độ x của con trỏ hiện tại =============
#define KEY_NONE	-1
int whereX();

//========= lấy tọa độ y của con trỏ hiện tại =======
int whereY();

//============== dịch con trỏ hiện tại đến điểm có tọa độ (x,y) ==========
void gotoXY(int x, int y);

//============= đặt màu cho chữ =========

//============== làm ẩn trỏ chuột ===========
void ShowCur(bool CursorVisibility);

//======= trả về mã phím người dùng bấm =========
int inputKey();

void textcolor(int x);

void resizeConsole(int width, int height);

void XoaManHinh();


void setBackgroundColor(WORD color);

 //Ham in mau chu va thay doi mai nen hien thi theo vi tri x, y.
void setColorBGTextXY(int x, int y, int color, int bg_color, string text);
void ResetColor();
