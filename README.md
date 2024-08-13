# mik32v2-shared

The repository contains header files, startup files, linking scripts and some basic libraries related to MIK32 V2

  * include/ - header files of the controller core
    * mik32_memory_map.h - memory map, bus clocking masks, interrupt lines and DMA
  * ldscripts/ - linker scripts
    * eeprom.ld - loading from ROM
    * ram.ld - loading from RAM
    * spifi.ld - loading from SPIFI
  * libs/ - periphery libraries
  * periphery/ - periphery register header files
  * runtime/crt0.S - start file
