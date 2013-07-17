#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <stack>

using namespace std;


void replaceAll(std::string& str, const std::string& from, const std::string& to) 
{
    if(from.empty())
        return;
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); 
    }
}

bool parenthetically_correct(string str)
{
	stack<char> st;
	for(int i=0; i<str.size(); i++) {
		if(str[i] == '(') st.push(str[i]);
		if(str[i] == ')') {
			if(st.empty() || st.top() != '(')
				return false;
			st.pop();
		}
	}
	return st.empty();
}

bool wellformed(string str) 
{
	string s1 = str;
	replaceAll(s1, ":)", "  ");
	replaceAll(s1, ":(", "  ");
	
	if(parenthetically_correct(s1))
		return true;

	string s2 = str;
	replaceAll(s2, ":", " ");

	if(parenthetically_correct(s2))
		return true;

	return false;
}

int main() 
{
	int ncases;
	cin>>ncases;
	string str;
	getline(cin,str);

	for(int i=0; i<ncases; i++) {
		getline(cin, str);
		cout<<"Case #"<<i+1<<": "<< ( wellformed(str) ? "YES" : "NO" )<<endl;
	}

	return 0;
}