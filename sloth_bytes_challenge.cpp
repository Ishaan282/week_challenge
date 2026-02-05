#include <bits/stdc++.h>
using namespace std;

//function to convert user-inputs because we don't know what they might enter 
string tolowers(string s);

//bingo_checker 
bool bingo_check(const vector<vector<string>>& board, int n);

//this is where program starts (da user input)
int main(){
    int n; cin >> n; //matrix size
    vector<vector<string>> board(n, vector<string>(n));
    cout << "\n enter the bingo board \n";

    for(int i = 0; i < n ; i++)
        for(int j = 0 ; j < n ; j++)
            cin >> board[i][j];

    (bingo_check(board, n)) ? cout << "True \n" : cout << "False \n";

    return 0;
    
}


string tolowers(string s){
    for(char& c : s)
        c = tolower(static_cast<unsigned char>(c));
    return s;
}


bool bingo_check(const vector<vector<string>>& board, int n){
    // check rows
    for(int i = 0; i < n; i++){
        bool ok = true;
        for(int j = 0; j < n; j++){
            if(tolowers(board[i][j]) != "x"){
                ok = false;
                break;
            }
        }
        if(ok) return true;
    }

    // check columns
    for(int j = 0; j < n; j++){
        bool ok = true;
        for(int i = 0; i < n; i++){
            if(tolowers(board[i][j]) != "x"){
                ok = false;
                break;
            }
        }
        if(ok) return true;
    }

    // main diagonal
    bool dig = true;
    for(int i = 0; i < n; i++){
        if(tolowers(board[i][i]) != "x"){
            dig = false;
            break;
        }
    }
    if(dig) return true;

    // anti-diagonal
    bool auntyDig = true;
    for(int i = 0; i < n; i++){
        if(tolowers(board[i][n - i - 1]) != "x"){
            auntyDig = false;
            break;
        }
    }
    if(auntyDig) return true;

    return false;
}

