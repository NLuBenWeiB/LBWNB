#include<bits/stdc++.h>
using namespace std;
int main(){
    char a[20000];
    cin>>a;
    int n= strlen(a);
    for(int i=0;i<n;i++)
    cout<<a[i]-'0';
}