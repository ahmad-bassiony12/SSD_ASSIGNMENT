#ifndef BIT_MATH_H_
#define BIT_MATH_H_
#define SET_BIT(x,Bit_Nu)     x|=(1<<Bit_Nu);
#define CLR_BIT(x,Bit_Nu)     x&=(~(1<<Bit_Nu));
#define TOGGLE_BIT(x,Bit_Nu)  x^=(1<<Bit_Nu);
#define GET_BIT(x,Bit_Nu)	   (x>>Bit_Nu)&1
#endif
