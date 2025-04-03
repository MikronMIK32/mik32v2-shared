#ifndef BOOT_MANAGER_H_INCLUDED
#define BOOT_MANAGER_H_INCLUDED

#define BOOT_EEPROM                  0
#define BOOT_RAM                     1
#define BOOT_SPIFI                   2

#ifndef __ASSEMBLER__

#ifdef __cplusplus
extern "C" {
#endif

#include <inttypes.h> 
typedef struct
{   
    volatile uint32_t BOOT;
} BOOT_MANAGER_TypeDef;

#ifdef __cplusplus
}
#endif

#endif // __ASSEMBLER__
#endif // BOOT_MANAGER_H_INCLUDED

