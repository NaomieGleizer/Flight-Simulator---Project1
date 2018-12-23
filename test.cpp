#include "ReadLines.h"

int main() {
    ReadLines r;
    vector<string> v = { "openDataServer 5-8+3 10" };
    vector<string> s= r.lexer(v);
    r.parser(s);
    return 0;
}