#include "cgic.h"
#include <stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include <stdlib.h>
#include <unistd.h>


// cgic程序以cgiMain作为入口点, cgic的函数库会自动把cgiMain连接到相应的main()上去
int cgiMain() 
{ 
	int value;
	int pfd;
	char led_num[10];  
	char led_state[10]; 
	int led;
	int action;

	cgiFormString("led_num",  led_num, 10);    // 从表单中的led_num字段获取值存入到led_num
	cgiFormString("led_state",  led_state, 10);// 从表单中的led_state字段获取值存入到led_state
	cgiHeaderContentType("text/html");         // 设定输出的内容格式 这里我们要输出HTML
	fprintf(cgiOut,"<title>LED Test</title>");   
	fprintf(cgiOut,"<p>recv from arm:</p>");
	fprintf(cgiOut,"led_num: %s", led_num);
	fprintf(cgiOut,"<br>");                    
	fprintf(cgiOut,"led_state: %s", led_state);

	pfd = open("/dev/led",O_RDWR);

	if (pfd < 0)
	{
	 return -1;
	}
	led = atoi(led_num);
	value=atoi(led_state);

	if(value == 0 && led == 1)
	{
		action = 1;
	}
	if(value == 1  && led == 1)
          {
                 action = 2;
          }

	if(value == 0  && led == 2)
          {      
                 action = 3;
          }
	if(value == 1  && led == 2)
          {
                 action = 4;
          }
	if(value == 0  && led == 3)
          {
                 action = 5;
     
	  }	 
		 	 
	if(value == 1  && led == 3)
          {
                 action = 6;
          }
        if(value == 0  && led == 4)
          {
                 action = 7;
          }
        if(value == 1  && led == 4)
          {
                 action = 8;
          }
        if(action > 0 && action < 9)
          {
		write(pfd,&action,4);
          }

	close(pfd);

	return 0;
}

