#ifndef __ASM_H__
#define __ASM_H__


#define int70(eax,ebx,ecx,edx)({\
         unsigned int ret_val;\
          __asm__ __volatile__("\
          int $0x70":"=a"(ret_val):"a"((eax)),"b"(ebx),"c"(ecx),"d"(edx));\
        ret_val;\
})






#endif

