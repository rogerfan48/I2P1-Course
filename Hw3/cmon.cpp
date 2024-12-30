#include<bits/stdc++.h>
using namespace std;
int ans;
string str; 
void f1(int pos){
    int l=pos-1, r=pos+1;
    while(l>=0 && r<str.size()){
        if(str[l]==str[r]){
            if(r-l<2){
                l--;
                r++;
                continue;
            }
            ans++;
            l--;
            r++;
        }
        else
            return;
    }
    return;
}
void f2(int pos){
    int l = pos, r = pos + 1;
    while(l>=0 && r<str.size()){
        if(str[l]==str[r]){
            if(r-l<=2){
                l--;
                r++;
                continue;
            }
            ans++;
            l--;
            r++;
        }
        else
            return;
    }
    return;
}
int main(){
    cin >> str;
    for (int i{}; i < str.size(); ++i){
        f1(i);
        f2(i);
    }
    cout << ans;
    return 0;
}