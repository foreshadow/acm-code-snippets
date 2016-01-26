// anti stack overflow
void expandStack(int size = 67108864) // 64 megabytes
{
#ifdef __GNUC__ // be careful of memory limit exceeding
    char *p = (char*) malloc(size) + size;
#ifdef __i386__
    __asm__("movl %0, %%esp\n" :: "r"(p));
#else
    __asm__("movq %0, %%rsp\n" :: "r"(p));
#endif
#else
#pragma comment(linker, "/STACK:1024000000,1024000000") // < 1G
#endif
}
