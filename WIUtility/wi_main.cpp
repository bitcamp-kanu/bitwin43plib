#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include "WIUtility.h"

using namespace std;
void main()
{
	//class WIUtility ��� ���.
	//static ��� �Լ��� class ���� ���� �Ʒ��� ���� �������� ����ϸ� �˴ϴ�.
	//WIUtility::�Լ���.
	string str = "�ѱ�,�̱�,����";	
	vector<string> vetCountry;
	vetCountry = WIUtility::Tokenize(str,string(","));
	//vector<string> vetCountry;
	//WIUtility::Tokenize(str,vetCountry,",");

	for(int i = 0 ; i < vetCountry.size() ; i++ )
	{
		cout << vetCountry[i] << endl;
	}

	system("pause");
}