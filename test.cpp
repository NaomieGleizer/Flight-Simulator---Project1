#include "ReadLines.h"

int main() {
    ReadLines r;
    vector<string> s= r.lexer("openDataServer 3*(-4)+5 10");
    r.parser(s);
    return 0;
}