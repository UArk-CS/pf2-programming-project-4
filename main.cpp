#include <iostream>
#include <fstream>
#include "StringStack.h"
using namespace std;

//void checkHTMLSyntax(string &htmlFile);

int main() {

    ifstream din;
    din.open("input.html");
    if (din.fail()) return -1;

    ofstream dout;
    dout.open("output.html");
    if (din.fail()) return -1;

    char last = ' ';
    char ch = din.get();
    while (ch != EOF)
    {
        if (ch == '<' && last != '\n')
        {
            dout << endl;
            last = '\n';
        }
        if (ch != '\n' && ch != '\r')
        {
            dout << ch;
            last = ch;
        }
        if (ch == '>' && last != '\n')
        {
            dout << endl;
            last = '\n';
        }
        ch = din.get();
    }
    din.close();
    dout.close();
    return 0;

}

//void checkHTMLSyntax(string &htmlFile) {
//
//    string test;
//
//    ifstream din;
//    din.open(htmlFile);
//    if (din.fail()) {
//        return;
//    }
//
//    if (din.is_open()) {
//
//        din >> test;
//        cout << test;
//
//    }
//
//}