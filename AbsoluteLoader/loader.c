#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
		FILE *rec;
		char prg_name[30],rec_line[100],temp[30];
		int index,i,j,addr;
		rec=fopen("record.txt","r");
		printf("Enter the program name: ");
		scanf("%s",prg_name);
		fscanf(rec,"%s",rec_line);
		if(rec_line[0]=='H')
		{
			j=0;
			i=2;
			while(rec_line[i]!='^')
			{
				temp[j]=rec_line[i];
				i++;
				j++;
			}
			temp[j]='\0';
		}
		if(strcmp(prg_name,temp)==0)
		{
			while((!feof(rec)) && (rec_line[0]!='E'))
			{
				fscanf(rec,"%s",rec_line);
				if(rec_line[0]=='T')
				{
					j=0;
					i=2;
					while(rec_line[i]!='^')
					{
						temp[j]=rec_line[i];
						i++;
						j++;
					}
					i++;
					temp[j]='\0';
					addr=atoi(temp);
					while(rec_line[i]!='^')
					{
						i++;
					}
					while(rec_line[i]!='$')
					{
						if(rec_line[i]=='^')
						{
							i++;
						}
						else
						{
							printf("%d: %c%c\n",addr,rec_line[i],rec_line[i+1]);
							i+=2;
							addr++;
						}
					}
				}
			}
		}
		else
		{
			printf("\nProgram name does not match\n");
		}
}
