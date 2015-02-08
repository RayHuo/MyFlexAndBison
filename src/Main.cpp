#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include "Tokens.h"

using namespace std;

extern FILE* yyin;      // yyin是lex的默认输入文件，这里可以用于指向自定义的输入文件，
                        // 同时注意不要自己再去定义yyin，因为yyin将在lex.cpp中定义，
                        // 所以在这里声明它会在某个.cpp中定义即可，其他的让链接器去完成。
extern int yyparse(void);

int main() {
    printf("Start\n");
    // yyin在lex.cpp中有定义，这里直接使用即可，它是一个extern修饰的变量，即全局变量。
    yyin = fopen("inputs/sample.in", "r+");
    printf("File Opened\n");
    yyparse();
    printf("Done Parser\n");
    Tokens::Instance().print();
    
    fclose(yyin);
    
    return 0;
}