#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <time.h>

int
main (int argc, char *argv[])
{

  if (argc != 5)
    {
      printf ("salah bangeeet\n");
      exit (EXIT_FAILURE);
}
      time_t rawtime;
      struct tm *info;

      pid_t pid, sid;        // Variabel untuk menyimpan PID

      pid = fork ();        // Menyimpan PID dari Child Process

      /* Keluar saat fork gagal
       * (nilai variabel pid < 0) */
      if (pid < 0)
    {
      exit (EXIT_FAILURE);
    }

      /* Keluar saat fork berhasil
       * (nilai variabel pid adalah PID dari child process) */
      if (pid > 0)
    {
      exit (EXIT_SUCCESS);
    }

      umask (0);

      sid = setsid ();
      if (sid < 0)
    {
      exit (EXIT_FAILURE);
    }

      if ((chdir ("home/nabella")) < 0)
    {
      exit (EXIT_FAILURE);
    }

      close (STDIN_FILENO);
      close (STDOUT_FILENO);
      close (STDERR_FILENO);

      while (1)
    {

      time_t rawtime;
      struct tm *info;
      time (&rawtime);
      info = localtime (&rawtime);

      if
      
     ((atoi (argv[1]) == info->tm_sec || ( strcmp (argv[1],"*")==0))
      	&&
      	(atoi (argv[2]) == info->tm_min || ( strcmp (argv[2],"*")==0))
           &&
           (atoi (argv[3]) == info->tm_hour || ( strcmp (argv[3],"*")==0)))
               
	{
               pid_t child_id;
               child_id = fork ();
               int status; 
	
	if (child_id == 0) 
	{
	char *bella[] = {"bash", argv[4], NULL}; 
	execv ("bin/bash", bella);}
	}

               sleep (2);
               time (&rawtime); info = localtime (&rawtime);
	}
      
     }



