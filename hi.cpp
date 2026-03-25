#include <bits/stdc++.h>
using namespace std;

int main(){
    //inilize the inputs and array 
    string a , b;
    cin >> a >> b;
    int aa = a.size(), bb = b.size(); 
    int big = (aa >= bb) ? aa : bb;
    vector<pair<char,char>> vec(big);

    //fill in the array 
    int i = 0 , j = 0, k = 0;
    while(i < aa && j < bb){
        vec[k] = {a[i],b[j]};
        i++; j++; k++;
    }

    //fill in remaining elements 
    if(i < aa - 1){
        while(i < aa){
            vec[k] = {a[i], ' '};
            k++; i++;
        }
    } else if(j < bb - 1){
        while(j < bb){
            vec[k] = {' ', b[j]};
            k++; j++;
        }
    }

    //printing the whole thing 
    cout << "output= [" << endl;
    for(int z = 0 ; z < big ; z++){
        cout << "[\"" << vec[z].first << "\", \"" << vec[z].second << "\"]," << endl;
    }
    cout << "]" << endl;

    return 0;

}