#include "ReadLines.h"

int main() {
    ReadLines r;
    vector<string> s= r.lexer("openDataServer 54*100 8+2");
    r.parser(s);
    return 0;
}