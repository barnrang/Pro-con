#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;


unordered_map<string,int> bucket;
void add_to_bucket(string s){
	bucket[s]++; // aaa.ddd = 1
	int i=0;  // s.length() = 7
	for(;i<s.length();i++){
		if(s[i]=='.') break; // i =3
	}
	if(i==s.length()) return; // return
	string sub = s.substr(i+1); // 3+1 -> ddd
	add_to_bucket(sub);
	return;
} 
void print_sub_domain(vector<string> list) {
	for(auto const& s:list){
		add_to_bucket(s);
	}
	//cout << "someshit” << endl;
	for(auto const& i:bucket){
		cout << i.first << ": " << i.second << endl;
}
	return ;
}

int main() {
    vector<string> test_input  = {"aaa.bbb.ccc.ddd", "bbb.ccc.ddd", "aaa.ccc", "google.ccc"};

    print_sub_domain(test_input);

    char a;
    cin >> a;

    return 0;
}


