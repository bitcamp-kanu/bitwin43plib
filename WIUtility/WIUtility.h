#pragma once

#pragma comment(lib,"Ws2_32.lib") //winsock 2.2 ���̺귯��
#define WINVER 0x0501
#define _WIN32_WINNT 0x0501

#include <WinSock2.h> //Winsock 2 ���� Header

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <string>
#include <vector>
using namespace std;
/*
	class WIUtility
	1. ���� ��� �ϴ� �Լ� ����
	2. ��� �Լ��� static �� ����
	   �Լ� ���ٽ� WIUtility::�Լ��� ���·� ȣ�� �ϸ� ��.
	   <ex>WIUtility::Gotoxy(10,10);
	   class �� ������ �ʿ� ����.
*/

typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;

class WIUtility
{
public:
	WIUtility(void);
	~WIUtility(void);	
	
	/*
	�ۼ���:DSurfer
	���� �ð��� ���ڿ� ���·� ��ȯ �Ѵ�.
	YYYYMMDDHHMM -> 2016-12-23 12:01:23
	YYYYMMDDHHMM -> 2016-12-23 12:01
	YYYYMMDD -> 2016-12-23
	*/
	static string GetCurTime(const string& str = "YYYYMMDDHHMMSS");
	
	/*
	�ۼ���:DSurfer
	����ð��� ��ȯ �Ѵ�. (20161223121212  ����)
	*/
	static string GetCurTime();
	
	/*
	�ۼ���:DSurfer
	����ð��� ��ȯ �Ѵ�. 
	*/
	static void  GetCurTime(int& y,int& m,int& d);

	/*
	�ۼ���:DSurfer
	����ð��� ������ ��ȯ �Ѵ�. (��,��,ȭ,��,��,��)
	*/
	static string GetWeek();
	
	/*
	�ۼ���:DSurfer
	����� ���ڿ� ������ ���� ���ڿ� �������� ��ȯ �Ѵ�.
	20161224 -> 2016-12-24
	20161224121212 -> 2016-12-24 12:12:12
	*/
	static string ToDateFormat(string day);


	/*
	�ۼ���:turboc
	ȭ���� ��� ������ �����.
	*/
	static void Clrscr();
	
	/*
	�ۼ���:turboc
	Curser ��ġ�� �̵� ��Ų��.
	*/
	static void Gotoxy(int x, int y);
	
	/*
	�ۼ���:turboc
	���� Ŀ�� ��ġ�� �����´�.
	*/
	static int WhereX();
	
	/*
	�ۼ���:turboc
	���� Ŀ�� ��ġ�� �����´�.
	*/
	static int WhereY();

	/*
	�ۼ���:turboc
	���� Ŀ���� �����Ѵ�.
	*/
	static void SetCursorType(CURSOR_TYPE c);

	/*
	�ۼ���:turboc
	Sleep �� �ش�.
	*/
	static void Delay(int n);


	/*
	�ۼ���:turboc
	���ڿ��� �����ڷ� �и� �Ѵ�.
	*/
	static void Tokenize(const string& str,vector<string>& tokens,const string& delimiters = " ");
	static vector<string> Tokenize(const string& str,const string& delimiters = " ");
	

	/*
	�ۼ���:DSurfer
	Text Color �� �����Ѵ�.
	*/
	static void TextColor(int color_number = 7);

	//SOCKADDR_IN ���� 127.0.0.1 ������ IP ���ڿ� ���·� ��ȯ �Ѵ�. (bossfamily)
	static string GetSocketIP(const SOCKADDR_IN&  SockAddress);
	//SOCKADDR_IN ���� Port �� ���� ��ȯ �ϳ�.					(bossfamily)
	static int GetSocketPORT(const SOCKADDR_IN&  SockAddress);

	//2016.12.29 GetFormatString �������� ����(static) ���� ����  ChoRong33	
	static string GetFormatString(char* format,...);
	//���� �޼����� ��ȯ �Ѵ�. (found75)
	static string GetErrorMessage(int errorCode);
	//������ �߻��� ErrorCode  �� ��ȯ �Ѵ�. (found75)
	static string GetLastErrorMessage();
	//���� �������� ��ȯ �Ѵ�.
	static string GetCurrentDir();
};

