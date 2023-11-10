#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
FILE *input,*symtab,*optab,*assembly,*object;
int locctr,start,operandno;
char opcode[20],label[20],optab_code[20],hex[20],operand[20],address[20];
char symtablabel[20],symtablabeladdress[20];
int len=0,flag=0;
char start_address[20];
char length[20]="000018";
input=fopen("output.txt","r");
optab=fopen("optab.txt","r");
symtab=fopen("symtab.txt","r");
assembly=fopen("assembly.txt","w");
object=fopen("object.txt","w");
fscanf(input,"%s %s %s %s",address,label,opcode,operand);
strcpy(start_address,operand);
fprintf(assembly,"**\t%s\t%s\t%s\t**\n",label,opcode,operand);
fprintf(object,"H^%s^00%s^%s\n",label,operand,length);
fscanf(input,"%s %s %s %s",address,label,opcode,operand);
while(strcmp(opcode,"END")!=0)
{
if(strcmp(label,"**")!=0)
{
if(strcmp(opcode,"WORD")==0)
{
fprintf(assembly,"%s\t%s\t%s\t%s\t00000%s\n",address,label,opcode,operand,operand);
fprintf(object,"T^00%s^03^00000%s\n",address,operand);
}
else if(strcmp(opcode,"RESW")==0)
{
fprintf(assembly,"%s\t%s\t%s\t%s\t**\n",address,label,opcode,operand);
}
}
else
{
while(!feof(optab))
{
fscanf(optab,"%s%s",optab_code,hex);
if(strcmp(opcode,optab_code)==0)
{


while(!feof(symtab))
{
fscanf(symtab,"%s %s",symtablabel,symtablabeladdress);
if(strcmp(operand,symtablabel)==0)
{
strcat(hex,symtablabeladdress);
fprintf(assembly,"%s\t%s\t%s\t%s\t%s\n",address,label,opcode,operand,hex);
fprintf(object,"T^00%s^03^%s\n",address,hex);
flag=1;
break;
}
}
}
if(flag==1)
break;
}
}
fscanf(input,"%s %s %s %s",address,label,opcode,operand);
}
fprintf(assembly,"%s\t%s\t%s\t%s\t00%s\n",address,label,opcode,operand,operand);
fprintf(object,"E^00%s",start_address);
fclose(optab);
fclose(input);
fclose(symtab);
fclose(assembly);
}
