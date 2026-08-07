#if 0

#endif
//1
/* 
 * thirdBits - return word with every third bit (starting from the LSB) set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int thirdBits(void) {
   // Base pattern: 01001001 (bits 0, 3, 6 set)
   int x = 0x49; 
   
   // Replicate: bits 0,3,6 + 9,12,15 + 18,21,24
   x = (x << 9) | x;
   x = (x << 18) | x; 
   
   // Result has every 3rd bit set up to bit 30
   return x;
}
//2
/* 
 * dividePower2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: dividePower2(15,1) = 7, dividePower2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int dividePower2(int x, int n) {
   int y;

   // Create bias: all 1s in lower n bits if x is negative
   y = (x >> 31) & ((1 << n) + ~0);

   // Add bias before shifting to achieve round toward zero
   return (x + y) >> n;
}
//3
/* 
 * isNonNegative - return 1 if x >= 0, return 0 otherwise 
 *   Example: isNonNegative(-1) = 0.  isNonNegative(0) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNonNegative(int x) {
   int y, z;

   // All 0s if x >= 0, all 1s if x < 0
   y = x >> 31;
   // Isolate sign bit (0 or 1)
   z = y & 1;
   // Flip: 1 if non-negative, 0 if negative
   return z ^ 1;
}
//4
/* 
 * remainderPower2 - Compute x%(2^n), for 0 <= n <= 30
 *   Negative arguments should yield negative remainders
 *   Examples: remainderPower2(15,2) = 3, remainderPower2(-35,3) = -3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int remainderPower2(int x, int n) {
   int mask, rem, sign, hasRem, conditionMask;

   // mask = 2^n - 1
   mask = (1 << n) + ~0;
   // low n bits (positive remainder form)
   rem = x & mask;
   // 0 if positive, -1 if negative
   sign = x >> 31;
   // 1 if remainder != 0
   hasRem = !!rem;

   // If x negative AND remainder != 0, subtract 2^n
   conditionMask = sign & ((hasRem << 31) >> 31);
   return rem | (conditionMask << n);
}
//5
/* 
 * replaceByte(x,n,c) - Replace byte n in x with c
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: replaceByte(0x12345678,1,0xab) = 0x1234ab78
 *   You can assume 0 <= n <= 3 and 0 <= c <= 255
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 3
 */
int replaceByte(int x, int n, int c) {
   int y, z, w;

   // Mask with 0s in byte n
   y = ~(0xFF << (n << 3));
   // Clear byte n in x
   z = x & y;
   // Shift new byte into position
   w = c << (n << 3);

   // Insert new byte
   return z | w;
}
//6
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
   int b16, b8, b4, b2, b1, b0;
   int sign = x >> 31;

   // If negative, flip bits so we measure magnitude
   x = (sign & ~x) | (~sign & x);

   // Binary search for highest 1 bit
   b16 = !!(x >> 16) << 4;
   x = x >> b16; 
   b8 = !!(x >> 8) << 3;
   x = x >> b8;
   b4 = !!(x >> 4) << 2; 
   x = x >> b4;
   b2 = !!(x >> 2) << 1; 
   x = x >> b2;
   b1 = !!(x >> 1); 
   x = x >> b1;
   // Last remaining bit
   b0 = x;

   // Sum shifts + 1 sign bit
   return b16 + b8 + b4 + b2 + b1 + b0 + 1;
}
