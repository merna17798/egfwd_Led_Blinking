#ifndef BITMATH_H_
#define BITMATH_H_


#define SET_BIT(P, B) (P |= (1 << B))
#define GET_BIT(P, B) ((P >> B) & 1)
#define TGL_BIT(P, B) (P ^= (1 << B))
#define CLR_BIT(P, B) (P &= ~(1 << B))
/* Check if a specific bit is set in any register and return true if yes */
#define BIT_IS_SET(REG,BIT) ( REG & (1<<BIT) )

/* Check if a specific bit is cleared in any register and return true if yes */
#define BIT_IS_CLEAR(REG,BIT) ( !(REG & (1<<BIT)) )
#endif
