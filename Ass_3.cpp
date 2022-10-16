/*
NAME - Vishesh Indora
SID - 21105056
BRANCH - ECE
*/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main(){
    int n=1,j=0;
    int array[10]={2,98,200,12,89,0,-89,-980,-8,78};
    int find_element;
    cin>>find_element;
    int i=0;
    while(i<sizeof(array)){
        if(array[i]==find_element){
            cout<<"Found at index "<<i;
            return 0;
        }
        i++;
    }
    cout<<"not found!";
}