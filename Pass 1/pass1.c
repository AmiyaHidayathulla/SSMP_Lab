#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
FILE *p1,*p2,*output,*symtab;
int locctr,start,length,operandno;
char opcode[20],label[20],optab_code[20],hex[20],operand[20];
p1=fopen("input.txt","r");
p2=fopen("optab.txt","r");
output=fopen("output.txt","w");
symtab=fopen("symtab.txt","w");
fscanf(p1,"%s\t%s\t%d",label,opcode,&operandno);
if(strcmp(opcode,"START")==0)
{
start=operandno;
locctr=start;
fprintf(output,"\tPRGM1\t%s\t%d\n",opcode,operandno);
}
else
{
locctr=0;
}
fscanf(p1,"%s\t%s\t%s",label,opcode,operand);
while(strcmp(opcode,"END")!=0)
{
fprintf(output,"%d\t",locctr);
if(strcmp(label,"**")==0)
{
int flag=0;

while(!feof(p2))
{
fscanf(p2,"%s\t%s\n",optab_code,hex);
if(strcmp(opcode,optab_code)==0)
{
locctr=locctr+3;
flag=1;
break;
}
}
if(flag==0)
{
printf("Opcode not found !!  ERROR !!\n Exiting....");
exit(0);
}
}
else
{
fprintf(symtab,"%s\t%d\n",label,locctr);
}
if(strcmp(opcode,"WORD")==0)
{
locctr=locctr+3;
}
else if(strcmp(opcode,"RESW")==0)
{
locctr=3*atoi(operand)+locctr;
}
else if(strcmp(opcode,"RESB")==0)
{
locctr=locctr+atoi(operand);
}
fprintf(output,"%s\t%s\t%s\n",label,opcode,operand);

fscanf(p1,"%s\t%s\t%s",label,opcode,operand);
}
fprintf(output,"%d\t%s\t%s\t%d\n",locctr,label,opcode,start);
length=locctr-start;
fprintf(output,"Program length = %d",length);
}
