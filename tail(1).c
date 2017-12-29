#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char * argv[])
{
	char buffer[3072];	
	char tempbuff[512];
	char temp[1];
	char * number = argv[1];
	int c,i,j=0,count=0,value=0;
	int file;
	if(argc > 2)
	{
		file = open(argv[2],0);
		i=1;
		while(number[i]>='0' && number[i]<='9')
		{
			value = (value*10) + (number[i] - '0');
			i++;	
		}
		while((c =read(file,tempbuff,sizeof(tempbuff)))>0)
		{
			for(i=0;i<c;i++)
			{
				if(tempbuff[i] == '\n')
				{
					count++;
				}
			}
		}
		close(file);
		file = open(argv[2],0);
		while((read(file,temp,sizeof(temp))) > 0)
		{
			if(temp[0] == '\n')
			{
				count--;
			}
			if(count<=value)
			{
				printf(1,"%c",temp[0]);	
			}
		}
		close(file);
	}
	else if(argc == 2)
	{
		if(number[0] == '-')
		{
			i=1;
			while(number[i]>='0' && number[i]<='9')
			{
				value = (value*10) + (number[i] - '0');
				i++;	
			}
			while ((c = read(0,tempbuff,sizeof(tempbuff)))>0)
			{
				for (i=0;i<c;i++)
				{
					buffer[j]=tempbuff[i];
					j++;
					if(tempbuff[i] == '\n')
						count++;
				}
			}
			for (i=0;i<j;i++)
			{
				if(buffer[i] == '\n')
				{
					count--;	
				}
				if(count<=value)
				{
					printf(1,"%c",buffer[i]);
				}
			}
		}
		else
		{
			file = open(argv[1],0);
			while ((c = read(file,tempbuff,sizeof(tempbuff)))>0)
			{
				for (i=0;i<c;i++)
				{
					buffer[j]=tempbuff[i];
					j++;
					if(tempbuff[i] == '\n')
						count++;
				}
			}
			for (i=0;i<j;i++)
			{
				if(buffer[i] == '\n')
				{
					count--;	
				}
				if(count<=10)
				{
					printf(1,"%c",buffer[i]);
				}
			}
		}
	}
	else
	{
		while ((c = read(0,tempbuff,sizeof(tempbuff)))>0)
			{
				for (i=0;i<c;i++)
				{
					buffer[j]=tempbuff[i];
					j++;
					if(tempbuff[i] == '\n')
						count++;
				}
			}
			for (i=0;i<j;i++)
			{
				if(buffer[i] == '\n')
				{
					count--;	
				}
				if(count<=10)
				{
					printf(1,"%c",buffer[i]);
				}
			}
	}
	exit();
}