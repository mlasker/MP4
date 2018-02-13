#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int romanToNumConversion(string s) {
    
    int x = 0;
    string::iterator it;
    
    for(it = s.begin(); it < s.end(); it++){
        
        switch (*it){
            case 'M': 
                x += 1000;
                break;
            case 'D': 
                x += 500;
                break;
            case 'C': 
                x += 100;
                break;
            case 'L': 
                x += 50;
                break;
            case 'X': 
                x += 10;
                break;
            case 'V': 
                x += 5;
                break;
            case 'I': 
                x += 1;
                break;
        }
    }
    
    return x;
    
}

string numToRomanConversion (int x) {
    
    
    
    string s = "";
    
    if (x >= 1000){
        
        for(int i = 0; i < (x / 1000); i++){
        
        s.append("M");
        }
        x -= ((x/1000) * 1000);
    }
    if(x >= 500) {
        for (int i = 0; i < (x / 500); i++) {
                
            s.append("D");
        }
        x -= ((x/500) * 500);

    }
    if (x >= 100) {
        for (int i = 0; i < (x / 100); i++) {
                
            s.append("C");
        }
        x -= ((x/100) * 100);

    }
    if(x >= 50) {
        for (int i = 0; i < (x / 50); i++) {
                
            s.append("L");
        }
        x -= ((x/50) * 50);
    }
    if(x >= 10) {
        for (int i = 0; i < (x / 10); i++) {
                
            s.append("X");
        }
        x -= ((x/10) * 10);
    }
    if(x >= 5) {
        for (int i = 0; i < (x / 5); i++) {
                
            s.append("V");
        }
        x -= ((x/5) * 5);
    }
    if(x >= 1) {
        for (int i = 0; i < (x / 1); i++) {
                
            s.append("I");
        }
    }
    
    return s;
}

int doCalculation (int x, int y, char c) {
    
    if (c == '+'){
        
        return x + y;
    }
    else if (c == '-'){
        
        return x - y;
    }
    else if (c == '*'){
        
        return x * y;
    }
    else if (c == '/'){
        
        return x / y;
    }
}


int main() {

    string str1;
    string str2;
    char c;
    
    ifstream infile;
    infile.open("mp4romanletrdata.txt");
    
    while (infile){
        
        infile >> str1;
        infile >> str2;
        infile >> c;
        
        int x = romanToNumConversion(str1);
        int y = romanToNumConversion(str2);
        
        cout << x << " "  << c << " " << y << " = ";
        
        string test = numToRomanConversion((doCalculation(x, y, c)));
        cout << doCalculation(x, y, c) << "(" << test << ")" << endl;
     
    }
    
    return 0;
}



