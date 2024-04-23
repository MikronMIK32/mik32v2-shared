
OUTPUT_FORMAT("elf32-littleriscv", "elf32-littleriscv", "elf32-littleriscv")
OUTPUT_ARCH(riscv)

ENTRY(_start)


MEMORY {
  spifi (RX): ORIGIN = 0x80000000, LENGTH = 2*1024M
  ram (RWX): ORIGIN = 0x02000000, LENGTH = 16K
}

STACK_SIZE = 1024;

CL_SIZE = 16;

REGION_ALIAS("REGION_TEXT", spifi);
REGION_ALIAS("REGION_RAM", ram);

INCLUDE sections.lds
