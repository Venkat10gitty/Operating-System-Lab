Nil_FAT.C
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int
main ()
{
    int i, status;
      pid_t pid;
      pid = fork ();
      if (pid == 0)
    {
      printf ("\n Child executing: \n\n");
      int count, j, n, time, remain, flag = 0, time_quantum;
      int wait_time = 0, turnaround_time = 0, bt[10], rt[10];
      int at = 0;
      printf ("Enter Total Process:\t ");
      scanf ("%d", &n);
      remain = n;
      for (count = 0; count < n; count++)
	{
	  printf ("Enter Burst Time for Process Process Number %d :",
		  count + 1);
	  scanf ("%d", &bt[count]);
	  rt[count] = bt[count];
	}
      printf ("Enter Time Quantum:\t");
      scanf ("%d", &time_quantum);
      printf ("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
      for (time = 0, count = 0; remain != 0;)
	{
	  if (rt[count] <= time_quantum && rt[count] > 0)
	    {
	      time += rt[count];
	      rt[count] = 0;
	      flag = 1;
	    }
	  else if (rt[count] > 0)
	    {
	      rt[count] -= time_quantum;
	      time += time_quantum;
	    }
	  if (rt[count] == 0 && flag == 1)
	    {
	      remain--;
	      printf ("P[%d]\t|\t%d\t|\t%d\n", count + 1, time - at,
		      time - at - bt[count]);
	      wait_time += time - at - bt[count];
	      turnaround_time += time - at;
	      flag = 0;
	    }
	  if (count == n - 1)
	    count = 0;
	  else if (at <= time)
	    count++;
	  else
	    count = 0;
	}
      printf ("\nAverage Waiting Time= %f\n", wait_time * 1.0 / n);
      printf ("Avg Turnaround Time = %f\n", turnaround_time * 1.0 / n);
    }
  else
    {
      if (pid > 0)
	pid = waitpid (pid, &status, 0);
      printf ("\n\nParent executing: ");
      printf ("\nDone\n");
    }
  return 0;
}