#include "ReadLines.h"

int main() {
    ReadLines r;
    vector<string> s= r.lexer("openDataServer -4 * 8");
    r.parser(s);
    return 0;
}