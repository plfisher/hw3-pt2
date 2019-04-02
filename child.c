
for(i=0;i<5;i++)
    {
      printf("%d\n",(i+1));
      sleep(1);
    }
    while(i<10)
    {
      printf("%d\n", (i+1));
      sleep(1);
      i++;
    }
    sigprocmask(SIG_UNBLOCK, &signalset, NULL);
