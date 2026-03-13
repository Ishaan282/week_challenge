#include <bits/stdc++.h>
using namespace std;

void s(int n){
    while(n > 0){
        if(n % 10 == 7) cout << "boom ";
        n = n/10;
    }
}

int main(){
    vector<int> v = {2, 75, 60, 97, 86};
    for(int it : v)
        s(it);
}