%{
 #include <cstdio>
 #include <cstdlib>
 #include <string>
 #include <cstring>
 #include "Tokens.h"

 extern "C" {
	void yyerror(char *s);
	extern int yylex(void);
 }

%}

%token NUMBER
%token ADD SUB MUL DIV
%token EOL

%%

calclist:
        | calclist exp EOL { printf(" = %d\n", $2);  }
        ;
exp: factor  { $$ = $1; }
   | exp ADD factor { $$ = $1 + $3; printf("add\n"); cout << "ADD_" << endl;}
   | exp SUB factor { $$ = $1 - $3; printf("sub\n"); cout << "SUB_" << endl;}
   ;
factor: term { $$ = $1; }
      | factor MUL term { $$ = $1 * $3; printf("mul\n"); cout << "MUL_" << endl;}
      | factor DIV term { $$ = $1 / $3; printf("div\n"); cout << "DIV_" << endl;}
      ;
term: NUMBER { $$=$1; 
               printf("number: %d\n", $$);
               Tokens::Instance().addToken($$);
             }
    |
    ;
%%


void yyerror(char *s) {
    printf("Parse Error: %s\n", s);
}