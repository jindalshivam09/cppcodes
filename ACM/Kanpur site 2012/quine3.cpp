#include<stdio.h>
#include<math.h>
const char *prog[] = {
"NULL};\n",
"void print(const char *str) {\n",
"printf(\"\\\"\");\n",
"const char *ptr;\n",
"for (ptr = str ; *ptr ; ptr++) {\n",
"if (*ptr == '\\n')\n",
"printf(\"\\\\n\");\n",
"else if(*ptr == '\"')\n",
"printf(\"\\\\\\\"\");\n",
"else if(*ptr == '\\\\')\n",
"printf(\"\\\\\\\\\");\n",
"else\n",
"printf(\"%c\",*ptr);\n",
"}\n",
"printf(\"\\\",\");\n",
"printf(\"\\n\");\n",
"} \n",
"int prime[1000009];\n",
"void sieve(int n) {\n",
"int s=sqrt(n);\n",
"int a;\n",
"int i;\n",
"for(i=2;i<=s;i++)\n",
"{\n",
"a=i;\n",
"int j;\n",
"if(!prime[i])\n",
"for(j=a*a;j<=n;j+=2*i)\n",
"{\n",
"prime[j]=1;\n",
"}\n",
"}\n",
"}\n",
"int main() {\n",
"sieve(1000009);\n",
"int n;\n",
"scantf(\"%d\",&n);\n",
"if (n%2 && !prime[n])\n",
"printf(\"YES\");\n",
"else{",
"\nprintf(\"#include<stdio.h>\\n\");\n",
"printf(\"#include<math.h>\\n\");\n",
"printf(\"char *prog[] = {\\n\");\n",
"const char **ptr;\n",
"for(ptr = prog ; *ptr ; ptr++ )\n",
"print(*ptr);\n",
"for(ptr = prog ; *ptr ; ptr++ )\n",
"printf(\"%s\",*ptr);\n",
"}\n",
"return 0;\n",
"}",
NULL};
void print(const char *str) {
printf("\"");
const char *ptr;
for (ptr = str ; *ptr ; ptr++) {
if (*ptr == '\n')
printf("\\n");
else if(*ptr == '"')
printf("\\\"");
else if(*ptr == '\\')
printf("\\\\");
else
printf("%c",*ptr);
}
printf("\",");
printf("\n");
}
int prime[1000009];
void sieve(int n) {
int s=sqrt(n);
int a;
int i;
for(i=2;i<=s;i++)
{
a=i;
int j;
if(!prime[i])
for(j=a*a;j<=n;j+=2*i)
{
prime[j]=1;
}
}
}
int main() {
sieve(1000009);
int n;
scanf("%d",&n);
if (n%2 && !prime[n])
printf("YES");
else{
printf("#include<stdio.h>\n");
printf("#include<math.h>\n");
printf("const char *prog[] = {\n");
const char **ptr;
for(ptr = prog ; *ptr ; ptr++ )
print(*ptr);
for(ptr = prog ; *ptr ; ptr++ )
printf("%s",*ptr);
}
return 0;
}
