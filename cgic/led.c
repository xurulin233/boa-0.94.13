#include "cgic.h"
#include <stdio.h>
#include <string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include <stdlib.h>
#include <unistd.h>


// cgic程序以cgiMain作为入口点, cgic的函数库会自动把cgiMain连接到相应的main()上去
int cgiMain() 
{ 
	int pfd;
	char led1[10];  
	char led2[10];
	char led3[10];
	char led4[10];
	int action;
	char ON[3]="on";

	cgiFormString("led1",  led1, 10);    // 从表单中的led_num字段获取值存入到led_num
	cgiFormString("led2",  led2, 10);// 从表单中的led_state字段获取值存入到led_state
	cgiFormString("led3",  led3, 10);    // 从表单中的led_num字段获取值存入到led_num
	cgiFormString("led4",  led4, 10);    // 从表单中的led_num字段获取值存入到led_num
	cgiHeaderContentType("text/html");         // 设定输出的内容格式 这里我们要输出HTML


	fprintf(cgiOut,"<title>LED Test</title>");   
	fprintf(cgiOut,"<p>recv from arm:</p>");
	fprintf(cgiOut,"led1: %s", led1);
	fprintf(cgiOut,"<br>");                    
	fprintf(cgiOut,"led2: %s", led2);
	fprintf(cgiOut,"<br>");                    
	fprintf(cgiOut,"led3: %s", led3);
	fprintf(cgiOut,"<br>");                    
	fprintf(cgiOut,"led4: %s", led4);


	pfd = open("/dev/led",O_RDWR);

	if (pfd < 0)
	{
	 return -1;
	}

	if(strcmp(led1,ON) == 0)
		action = 2;
	else
	       action = 1;
	write(pfd,&action,4);
	
	if(strcmp(led2,ON) == 0)
		action = 4;
	else
	       action = 3;
	write(pfd,&action,4);

	if(strcmp(led3,ON) == 0)
		action = 6;
	else
	       action = 5;
	write(pfd,&action,4);

	if(strcmp(led4,ON) == 0)
		action = 8;
	else
	       action = 7;
	write(pfd,&action,4);

	close(pfd);

	return 0;
}

