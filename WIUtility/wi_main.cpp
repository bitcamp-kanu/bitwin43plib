#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include "WIUtility.h"

using namespace std;
void main()
{
	//class WIUtility 사용 방법.
	//static 멤버 함수는 class 선언 없이 아래와 같은 형식으로 사용하면 됩니다.
	//WIUtility::함수명.
	string str = "한국,미국,영국";	
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