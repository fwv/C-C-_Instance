#include<iostream>
#include<fstream>
using namespace std;

int a[1000];
int n,r;
fstream f("F:\\data.txt", ios::out);

void dfs(int sum){
	if(sum==r+1){
		for(int i=1;i<=r;i++){
			cout<<" "<<a[i];
			f<<" "<<a[i];
		}
			cout<<endl;
			f<<endl;
			return; 
	}
	for(int i=a[sum-1]+1;i<=n;i++){
		a[sum]=i;
		dfs(sum+1);
	}
}

void output() {
    n = 10;
    for(int i=1;i<=10;i++) {
        r = i;
        dfs(1);
    }
    f.close();
}


