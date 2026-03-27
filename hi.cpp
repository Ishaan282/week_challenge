#include <iostream> 
#include <vector>
#include <stack>
using namespace std;

int main(){
    vector<int> daily_temperatures;
    int x;
    while(cin >> x) // use ";" in the end of the input to exit the loop 
        daily_temperatures.push_back(x);

    int size = daily_temperatures.size();
    vector<int> output(size,0);

    //the easy solution 
        // for(int i = 0 ; i < size - 1; i++){
        //     int count = 0;
        //     for(int j = i; j < size; j++){
        //         if(daily_temperatures[i] < daily_temperatures[j]){
        //             count = j - i;
        //             break;
        //         }
        //     }
        //     output.push_back(count);
        // }
    
    //! solution for nerds ^_~
    stack<int> st;
    for(int i = 0 ; i < size ; i++){
        while(!st.empty() && daily_temperatures[i] > daily_temperatures[st.top()]){
            int p = st.top();
            st.pop();
            output[p] = i - p;
        }
        st.push(i);
    }

    for(int it : output)
        cout << it << " ";
}