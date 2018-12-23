#include "ReadLines.h"

int main() {
    ReadLines r;
    vector<string> v = { "openDataServer 2+(8/5)+10 10" };
    vector<string> s= r.lexer(v);
    r.parser(s);
    return 0;
}