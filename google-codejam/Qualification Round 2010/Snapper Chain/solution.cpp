#include<bits/stdc++.h>
using namespace std;

int main() {

	fstream fin, fout;
	fin.open("A-test-practice.txt", ios::in);
	fout.open("A-test-practice-output.txt", ios::out);

	long t;
	fin>>t;

	

	for(long c = 1; c<=t;c++) {

		long n,k;
		fin>>n>>k;
		long val = (1<<(n));
		if(k==0) 
			fout<<"Case #"<<c<<": OFF\n";
		else if(k%val==val-1)
			fout<<"Case #"<<c<<": ON\n";
		else
			fout<<"Case #"<<c<<": OFF\n";
	}
	return 0;
}