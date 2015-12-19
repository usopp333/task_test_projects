// hello.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <stdint.h>
// #include <iostream>
// 
// #define MALLOC(p,s)\
// 	if (!(p = malloc(s))) {\
// 	fprintf(stderr, "Insufficient memory");\
// 	exit(EXIT FAILURE);\
// 	}
// 
// void main ()
// {
// 	int i, *pi;
// 	float f,*pf;
// 	//pi = (int *)malloc(sizeof(int));
// 	//pf = (float *)malloc(sizeof(float));
// 	//pi = &i;
// 	//pf = &f;
// 	MALLOC( pi, sizeof(int));
// 	MALLOC( pf, sizeof(float));
// 
// 	*pi = 1024;
// 	*pf = 3.14;
// 	printf("an integer = %d, a float = %f\n",*pi, *pf);
// 	free(pi);
// 	free(pf);
// }

#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>

int main(int argc, char *argv[])
{
	QApplication app(argc,argv);	
	QLabel *lbl = new QLabel("<h2><font color=red>Qt5</font></h2>");

	lbl->show();
	return app.exec();
}