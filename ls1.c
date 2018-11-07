/*
file: ls1.c
author: 2017116167_김지민
datetime: 2018-09-21 12:00
description: 간단한 ls 작성. 디렉토리 내의 파일명들을 출력한다.
*/

#include<stdio.h>
#include<sys/types.h>
#include<dirent.h>

void do_ls(char []);

main(int ac, char *av[]){
	if(ac==1)
		do_ls(".");
	else
		while(--ac){
			printf("%s:\n",*++av);
			do_ls(*av);
		}
}

void do_ls(char dirname[]){
	DIR *dir_ptr;
	struct dirent *direntp;

	if((dir_ptr=opendir(dirname))==NULL)
		fprintf(stderr,"ls1: cannot open %s\n",dirname);
	else{
		while((direntp=readdir(dir_ptr))!=NULL)
				printf("%s\n",direntp->d_name);
		closedir(dir_ptr);
	}
}
