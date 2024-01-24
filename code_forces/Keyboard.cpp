#include<bits/stdc++.h>

using namespace std;

int main()
{
    string keyboard = "qwertyuiopasdfghjkl;zxcvbnm,./";
    char shift;
    string text; 
    cin >> shift;
    cin >> text;

    string actual_text;
    for(auto t : text){
        if(shift == 'R')
            actual_text += keyboard[keyboard.find(t) - 1];
        else 
            actual_text += keyboard[keyboard.find(t) + 1];
    }

    cout << actual_text;
    return 0;
}
