#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <wait.h>

int StatD(const char *path){
  struct stat path_Directory;
  stat(path, &path_Directory);
  return S_ISDIR(path_Directory.st_mode); //Melakukan cek direktori
}

int main(){
	pid_t NC1 = fork();
	int NC2 = fork(); 
	int NC3 = fork(); 
	int status; //buffer

	if (NC2 > 0 && NC3 > 0)
    {
		while ((wait(&status)) > 0);
		DIR *directory;
		struct dirent *direct;
		chdir("/home/achsanymous/Desktop/jpg/");//membuat file jpg
		directory = opendir(".");

		if (directory){
      		while ((direct = readdir(directory)) != NULL){
	    if(strcmp(direct->d_name, ".") == 0 || strcmp(direct->d_name, "..") == 0)
		      continue;
		    if(StatD(direct->d_name)){
		      if(fork() == 0) {
		        char stage[999];
		        sprintf(stage,"/home/achsanymous/Desktop/jpg/%s",direct->d_name);
		        char* statement[] = {"mv", stage,"/home/achsanymous/Desktop/indomie/", NULL};execv("/bin/mv", statement);
          		}
          	else{
            	while ((wait(&status)) > 0);
            	if(fork() == 0){
            	  	if(fork() == 0){
            	    	char stage1[999];
            	    	FILE *clap;
		        	    sprintf(stage1,"/home/achsanymous/Desktop/indomie/%s/coba1.txt",direct->d_name);//membuat txt ke-1
		        	    clap = fopen(stage1, "w");
		        	    fclose(clap);
		        	  	}
              		else{
		            	while ((wait(&status)) > 0);
		            	sleep(3);
		            	char stage2[999];
		            	FILE *clap;
		            	sprintf(stage2,"/home/achsanymous/Desktop/indomie/%s/coba2.txt",direct->d_name);//membuat txt ke-2
		            	clap = fopen(stage2, "w");
		            	fclose(clap);
		            	exit(0);
		          		}}
            	else{
				 while ((wait(&status)) > 0);
					printf("loading . . . ");
					printf(" ");
				      exit(0);
				    }}}
        else{
     		while ((wait(&status)) > 0);
          	if(fork() == 0){
            	while ((wait(&status)) > 0);
            	char stage3[999];
            	sprintf(stage3,"/home/achsanymous/Desktop/jpg/%s",direct->d_name);
            	char* statement[] = {"mv", stage3,"/home/achsanymous/Desktop/sedaap/", NULL};//memindahkan file ke sedaap
            	execv("/bin/mv", statement);
			}}}}}
	else if (NC2 == 0 && NC3 > 0){
    while ((wait(&status)) > 0);
    if (NC1 == 0){
	printf("create file indomie");
      char *statement[] = {"mkdir", "-p","/achsanymous/Desktop/indomie", NULL};//membuat file indomie
      execv("/bin/mkdir", statement);
	
   }
    else{
      while ((wait(&status)) > 0);
	printf("create file sedaap");
      sleep(5);
      char *statement[] = {"mkdir", "-p","/home/achsanymous/Desktop/sedaap", NULL};//membuat file sedaap
      execv("/bin/mkdir", statement);
}} 
	else if (NC2 > 0 && NC3 == 0){
    char* statement[] = {"unzip", "-oq","/home/achsanymous/Desktop/jpg.zip", NULL};
	printf("opening package . . .");
    execv("/usr/bin/unzip", statement);
	}
	return 0;
}
