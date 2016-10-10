#ifndef _syscalls_h_
#define _syscalls_h_ 1

#include "kostypes.h"

#include <cerrno>
#include <cstdlib>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define STDDBG_FILENO 3

#define MAP_FAILED  ((void *) -1)
extern "C" void* mmap(void* addr, size_t len, int prot, int flags, int filedes, off_t off);
extern "C" int munmap(void* addr, size_t len);

extern "C" pid_t getcid();

extern "C" int privilege(void*, mword, mword, mword, mword);

extern "C" int syscallSummation(int a, int b);

extern "C" bool isEven(long n);

extern "C" int sched_setaffinity(pid_t pid, size_t cpusetsize, cpu_set_t *mask);
	
extern "C" int sched_getaffinity(pid_t pid, size_t cpusetsize, cpu_set_t *mask); 
	
extern "C" int get_core_count();

namespace SyscallNum {

enum : mword {
  _exit = 0,
  syscallSummationEnum,
  isEvenImpl,
  sched_setaffinityEnum,
  sched_getaffinityEnum,
  getCoreCountEnum,
  open,
  close,
  read,
  write,
  lseek,
  getpid,
  getcid,
  usleep,
  _mmap,
  _munmap,
  _pthread_create,
  pthread_exit,
  pthread_join,
  pthread_kill,
  pthread_self,
  semCreate,
  semDestroy,
  semP,
  semV,
  privilege,
  _init_sig_handler,
  max
};

};

extern "C" ssize_t syscallStub(mword x, mword a1 = 0, mword a2 = 0, mword a3 = 0, mword a4 = 0, mword a5 = 0);

#endif /* _syscalls_h_ */
