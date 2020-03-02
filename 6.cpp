#include<iostream>
#include<map>
#include<string.h>
using namespace std;
int main(){
	string text,pttr;
	cout << "\nEnter the text:";
	cin >> text;
	//cout << text << endl;
	cout << "\nEnter the pattern:";
	cin >> pttr;

	pair<char,int> temp;
	map<char,int> table;

	map<char,int>::iterator it;

	int l = pttr.length();

	for (int i= l-2 ; i>=0 ; i++){
		try{
			it=table.find(pttr[i]);
		}
		catch(map<char,int>::iterator x){
			temp.first = pttr[i];
			temp.second = (l-1) - i;
			table.insert(temp);
		}
	}

	for(it = table.begin() ; it !=table.end() ; it++)
		cout<< (*it).first << (*it).second <<endl;

}

