%{
 #include <cstdio>
 #include <cstdlib>
 #include "parser.h"
 #include "Tokens.h"
 
 extern "C" { 
	int yywrap(void);
	int yylex(void);
 }

%}

digit  [0-9]+

%%

{digit}    { yylval = atoi(yytext);
             printf("digit\n");
             return NUMBER;  }
"+"        { printf("ADD\n"); return ADD; }
"-"        { printf("SUB\n"); return SUB; }
"*"        { printf("MUL\n"); return MUL; }
"/"        { printf("DIV\n"); return DIV; }
\n         { printf("EOL\n"); return EOL; }
.          { /* do nothing */  }
%%

int yywrap() {
  return 1;
}
