#ifndef
#define BITS_H

#define BIT(register, bit) (register & (1<<bit))
#define SETBIT(register, bit) register |= (1<<bit)
#define CLRBIT(register, bit) register &= ~(1<<bit)
#endif
