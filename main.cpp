#include <iostream>
#include <fstream>
#include "StringStack.h"
using namespace std;

int main() {

    ifstream din;
    din.open("input.html");
    if (din.fail()) return -1;

    ofstream dout;
    dout.open("output.html");
    if (din.fail()) return -1;

    bool isTag = false;
    bool isClosing = false;
    string tagName;

    char last = ' ';
    char ch = din.get();
    while (ch != EOF) {
        if (ch == '<' && last != '\n') {

            isTag = true;
            tagName = "";

            dout << endl;
            last = '\n';

        }

        if (ch != '\n' && ch != '\r') {

            if (isTag && ch != '<' && ch != '>') {

                if (ch == '/' && last == '<') {
                    isClosing = true;
                } else {
                    tagName += ch;
                }

            }

            dout << ch;
            last = ch;

        }

        if (ch == '>' && last != '\n') {

            isTag = false;
            cout << tagName;
            cout << endl;

            if (isClosing) {
                // if matches top of stack, pop
                // otherwise print error
            } else {
                // push
            }

            dout << endl;
            last = '\n';
        }

        ch = din.get();

    }

    din.close();
    dout.close();

    return 0;

}