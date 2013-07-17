/*
 * stringtest.cc
 *
 *  Created on: Apr 4, 2011
 *      Author: biswasra
 */


#include <iostream>
#include <string>

using namespace std;

void stringtest_run()
{
	string s(100, ' ');
	int i = 0;
	s[i++] = 'b';
	s[i++] = 'a';
	cout<<"String: "<<s;
}
