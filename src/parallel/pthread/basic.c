#include "_parallel_.h"
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <assert.h>

#define N_THREAD 4

typedef struct thread_in_s
{
  pthread_t tid;
  long sn;
} thread_in_t;


void *
echo(void *arg)
{
  thread_in_t *in = (thread_in_t*) arg;
	fprintf(stderr, "Hello, sn=%li\n", in->sn);
  assert(in->tid == pthread_self() && "calling thread id");
  assert(pthread_equal(in->tid, pthread_self()) && "same as above");
  return &in->sn;
}

int
main(int argc, char **argv)
{
	_unused_(argc);
	_unused_(argv);

  thread_in_t *tinfo = 0;
  tinfo = calloc(N_THREAD, sizeof(thread_in_t));
  if (!tinfo)
    {
      perror(0);
      return 1;
    }

	for (long i = 0; i < N_THREAD; i++)
    {
      fprintf(stdout, "creating thread %ld\n", i);
      tinfo[i].sn = i;
      int r = pthread_create(&tinfo[i].tid, 0, echo, &tinfo[i]);
      if (r)
        {
          perror("!panic, when create");
          goto clean_exit;
        }
    }

  void *retval;
  for (long i = 0; i < N_THREAD; i++)
    {
      int r = pthread_join(tinfo[i].tid, &retval);
      if (r)
        {
          perror("!panic, when join");
          continue;
        }
      fprintf(stderr, "tid=0x%016zx, return %li\n",
              (unsigned long) tinfo[i].tid,
              *(long*) retval);
    }
  
 clean_exit:
  free(tinfo);
	
	return 0;
}
