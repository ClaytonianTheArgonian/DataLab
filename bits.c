/* 
 * CS:APP Data Lab 
 * 
 * <Clayton Cathey - 0996142>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 8.0.0.  Version 8.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2014, plus Amendment 1 (published
   2015-05-15).  */
/* We do not support C11 <threads.h>.  */
/* Total of 80 points  -- 32 puzzles*/
/* Rating 1 ==> 7 points */
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
    /*In Computer Systems: A programmer's perspective on page 66 it gives properties of TMax and Tmin I use
     * The idea is to use the fact that Tmax + 1 is Tmin, I am also utilizing the fact Tmax + Tmin = -1 and
     * I then take this result and negate it */

    int y = x + 1;      // Create TMin
    x = y + x;         // This should make x -1 if X is Tmax
    x = (~x) | (!y);  // Not Y should be 0 since y is a number and ~x Should be all 0 as well if its Umax
    return !x;       // The or we preformed will make x 0 if it was originally Tmax any other number will be 1
                    // Thus when we return !x it will return 1 if x was 0 or 0 if x was any other number.
}
/*
 * isTmin - returns 1 if x is the minimum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmin(int x) {
    /*In Computer Systems: A programmer's perspective on page 66 it gives the property that Umax = 2Tmax + 1
     * I take advantage of this by the fact that ~Tmin is Tmax and then if Tmax is created then creating Umax this
     * approach only functions if x was Tmin*/

    int y = (~x);             // Create TMax
    y = (y + y) + 1;         // Create UMax
    return !((~y) | (!x));  // Check if Umax was created by using !x or all 0's and the ~y which should be all -> 
                            // -> 0's as well. We test this by or'ing whatever value ~y is with 0
}
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
    /* Hackers delight: page 29 talks about bit Xor and implementing it with deMorgans law,
     * it also gives an example of bit Xor that I experimented with, this example was ((x|y) & ¬(x&y)).
     * We can not use bit or so I experimented with alternatives and looked between pages 25 and 28 in Hackers 
     * delight*/

    return (~((~x)&(~y))) & ~(x & y); //~(x|y) = ~x & ~y, I negate the expression to get to the original Or
                                      // ~~(x|y) = ~((~x)&(~y)), this is the logic I used 
}
/* 
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) {
    /*I came to the realization that I can create TMin easily through shifts then with a simple negate 
     * I could create TMax!*/

    int x = 0x01;       // Create a 32 bit representation of 1
    return ~(x << 31); // Shift the 1 bit all the way to the most significant posistion and create Tmin
                      // Then though a simple negate we create TMax!
}
/*
 * isZero - returns 1 if x == 0, and 0 otherwise 
 *   Examples: isZero(5) = 0, isZero(0) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int isZero(int x) {
    /*The only time the logical not of a int will be 1 or true is if the int is 0
     * otherwise the value will be 0 since not true is false or 0.*/

  return !(x);
}
/* 
 * minusOne - return a value of -1 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int minusOne(void) {
    /*This is a simple problem when you think about the bit composistion of -1
     * The composistion is a string of all 1's since int 0 is all 0's then the ~0 is -1!*/

  return ~(0); // 0 is all 0 in the 32 bit string and -1 is all ones sp ~0 os -1
}
/* 
 * fitsShort - return 1 if x can be represented as a 
 *   16-bit, two's complement integer.
 *   Examples: fitsShort(33000) = 0, fitsShort(-32768) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int fitsShort(int x) {
    /*This function looks tricky but turns out to be relatively simple, I solved this by making y the original
     * argument and then shifting it the left 16 times. If it would fit in a short it will not overflow however 
     * if it is too long it will overflow and become a different number when shifted 16 back to the right.
     * In computer Systems: a programmers perspective one exercise was to recreate == with bitwise operators
     * the solution i found was !(x^y) since if they are the same number it will make all 0 with the xor and the
     * negate will return a 1.*/

    int y = x;                     // Make a copy of the original argument
    y = (y << 16) >> 16;          // Do the shifts to check for overflow
    return !(x^y);               // Check for equality with original arugment if the same the xor will be 0 and !0 is 1
}
/* Rating 2 ==> 18 points */
/* 
 * isNegative - return 1 if x < 0, return 0 otherwise 
 *   Example: isNegative(-1) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNegative(int x) {
    /* This problem has a very simple approach when you think about how negative numbers are represnted
     * the most significant bit of an odd number is 1 and an even is 0. I shift this number into the least
     * significant spot with an arithmatic right shift. If the number was odd we will have the int of -1 and if 
     * it was evenall 0's the mask of & 0x01 will return 0 if even or 1 if negative!*/

    int y = x >> 31;    // Put most significant bit into least significant spot
    return (y & 0x01); // And with a mask of 0x01 to get either 1 for negative or 0 for even  
}
/* 
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int byteSwap(int x, int n, int m) {
    /*This is a tricky problem to approach at first glance but realizing the we can isolate the bytes we want by a 
     * << 3 to get the number of bytes needed to shift the original value to have the byte we want in the 0 
     * posistion and mask off the rest with 0xff preserving that first byte after that we just need to get Umax 
     * and clear holes in the spots we want then use this modified Umax to make holes in the original x
     * once the holes are created in the original number we or in the mask we made of the two bytes swapped 
     *  and or it into the empty holes in the modified x*/

    // Find out how many bits we need to shift x to get the byte we want into 0'th slot 
    // This first two steps gets whatever byte we are swapping into posistion and masks off the rest
    int zn = (x >> (n << 3)) & 0xFF; //isolate and mask off the nth byte << 3 is mult by 8 telling how many bits over the 
                                     // byte we want is 
    int zm = (x >> (m << 3)) & 0xFF;             // isoalte and mask off the mth byte 
    int mask = (0x01 << 31) >> 31;              // This should create Umax and will be used to preserve no swap bytes
    int smask = (zn << (m << 3)) | (zm << (n << 3)); // Create a mask with the bytes swapped
    int holepunch = ((((0xFF << (n << 3)) | (0xFF << (m << 3))) ^ mask) & x); // create original number with blanks
                                                                              // in the spots we want to swap
    return (smask | holepunch); // insert the swapped bytes into the empty slot in original number
}
/* 
 * allEvenBits - return 1 if all even-numbered bits in word set to 1
 *   Examples allEvenBits(0xFFFFFFFE) = 0, allEvenBits(0x55555555) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allEvenBits(int x) {
    /*This problem became obvios to me almost immediately with your example of 0x55555555. This showed a mask of 
     * all even bits i could create. Once the mask is created we and it with the original number if it has 
     * all even bits set to 1 it will produce the same number as the mask we created i then return the comparison
     * of the mask and the and'ed number*/

    int mask = (((0x55 << 24) + (0x55 << 16) + (0x55  << 8) + 0x55)); // Create even bit mask
    int eventest = mask & x; // Compare with the original number
    return !(eventest ^ mask); // check if the comapred number is equal to the mask
}
/* 
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int copyLSB(int x) {
    /*This is a very simple problem when you stop to consider that if you put the LSB into the MSB slot 
     * by shifting it 31 << then shifting >> 31 this performs a right arithmetic shift and this copies the 
     * most significant bit into the new empty slot behind it ever shift*/

    return ((x << 31) >> 31); // Shift the LSB Into the MSB and then back to LSB
}
/* 
 * implication - return x -> y in propositional logic - 0 for false, 1
 * for true
 *   Example: implication(1,1) = 1
 *            implication(1,0) = 0
 *   Legal ops: ! ~ ^ |
 *   Max ops: 5
 *   Rating: 2
 */
int implication(int x, int y) {
    /*This one at first seemed simple but took some pen on paper work the only time we get false is when 
     * 1 -> 0 or true implies false so realzing that the first element is the one in this puzzle that makes the 
     * real change i worked out some examples use the | and !. I knew xor wouldn't work because 1^1 =0 and negate
     * did not make sense. This works since !1 is 0 and !1 | 0 = 0 however !0|1=1, !1|1 = 1 and finally 
     * !0|0 =1 so it fits the truth table*/

    return ((!x)|y);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
    /*I remember using this in Assembly very often. This was one of the first things you taught us that you diddle
     * all the bits and add one to negate a two's complement number!*/

  return (~x)+1;
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
    /* I found the solution to this problem in hackers delight page 64. It shows (x >> 31) & n-1
     * this rounds a power of 2 towards 0 when needed as shown in Hackers delight.
     *  var mult2 is where I calculate the n-1 by multiplying 1 by 2^n, after this i add the negation of 0 or -1 
     *  to calculate n-1. This calculation is just a bias that we are adding*/

    int mult2 = (1 << n) + ~0; // Find the number n-1 that we will and to x >> 31
    return (x + ((x >> 31) & mult2)) >> n; // Apply the number (1 or 0) and perform the division
}
/* 
 * float_abs - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_abs(unsigned uf) {
    /*The first step I take is to create Nan So when we create the number we can make sure that it is not > than
     * NaN. Next we need to create the toggler to toggle the MSB and then just check to make sure it is not NaN 
     * and return the number with its MSB toggled if it was negative. We achieve this toggle with a mask 
     * of 0x7fffffff to save all values but the first bit ensuring it willbe 0*/

    int Nan = ((((0x7f) << 1) + 1)<< 23 ); // This shoud  create Nan 
    int toggler = (~(1 << 31)); // This should create a mask of 0x7fffffff to preserve all bits but the sign bit
    int toggled = (uf & toggler); // This will toggle the MSB to create the positive of whatever number
    if (toggled > Nan) { // If this number is greater than our base NaN it is not a number
        return uf; // Specs state if NaN then return original number
    }
    else {
        return toggled; // If it is less than that NaN we just return
    }
}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
    /*I first create NaN to check against after we toggle the bit then we just toggle the MSB by xoring with
     * tMin to toggle 1 to 0 and 0 to 1 changing the sign but NaN must have 0 in the sign bit so i created the
     * another variable taking off the sign bit to defualt to 0 to check for NaN if NaN return original arg 
     * if not returned toggled bit*/

    int NaN = (((((0x7f) << 1) + 1)<< 23 )); // This shoud  create Nan
    int toggler = (1 << 31); // This should create a mask I will use to toggle the MSB of uf to 1
    int toggled = (uf ^ toggler); // Toggles the MSB if 1 goes to 0 if 0 goes to 1
    int toggle = (~toggler & uf); // Create a check for NaN we must drop any leading ones
    if ( toggle > NaN ) {
        return uf;
    }
    else {
        return toggled;
   } 
}
/* Rating 3 ==> 27 points */
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
    /* Refrence material, Hackers delight pages 116->118 helped get my mind going but no direct solution found
     * We want to check for ASCII digits, these are numbers that are 0x2f < x < 0x3A so we want numbers bounded 
     * between these two values. The solution quickly becomes obvios with addition x should be bigger than numbers
     * smaller than 0x2f so if we subtract 0x2f it from x this should be a positive number and its the other way 
     * around for the upper bound if we subtract x from the upper bound it should be positive if it is less than
     * the upper bound we move the sign bit into posistion with a shift and the or the two values togethor. 
     * if the calculations are within the range it will be 0 and the negation will return 1 if not itll be 1
     * and the negation will return 0!
     * When we negate the numbers we dont add 1 since the largest ascii digit is hex 57 and the smallest is hex
     * 48 if we added one to truly negate the bound this would mistake the smallest ascii digit and largest as 
     * a mistake*/

    int y = (x + (~0x2f)) >> 31; // Check if x is larger than the lower bound we dont add 1 because we want -48
    int z = (0x3A + ~x) >> 31; // Check if the upper bound is larger than x, we dont add 1 because we want -57
    return !(y|z); // return the answer
}
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
    /*This was slightly ticky at first glance i thought just toggle MSB with 0x80000000 and then >> 31 and
     * toggle off the rest with & 0x01 this would work except 0 was not considered positive,
     * after some consideration I realized the if its any other number !x would be 0 and it would be 1 
     * if x was 0! So I then shift the sign bit into the LSB and mask off the rest of the number with &1
     * if it was negative the number here will be 1 and 0 if positive i or against the check0 to change the positive
     * marker to 1 if it was 0 and then return the negation*/

    int check0 = !x; // This is to check for the probability that x is 0 it will be 1 if 0, and 0 if anything else
    int check = (x >> 31) & 0x01; //Move the MSB into the LSB posistion and mask off the rest
    return !(check|check0); // The or will be 1 if positive because !(0|0) will be 1 but if it was originally 0
}
/* 
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y) {
    /* I consulted page 92 of Computer Systems for descriptions of behaviour for two's complement addidtion.
     * We know an overflow condition occured if we add two numbers with the same sign and get a number with a 
     * different sign. So we isolate the sign of x and isolate the sign of y and then isolate the sign of x + y
     *  we then xor the sign of x and y to check if they are the same or different we use logical not to get a 
     *  1 or 0 for the and we then compare the sign of sumxy and xor it to either the sign of x or y both will 
     *  work this work since if the xor of sum and y is differnt then the xor of signx and y we know an overflow 
     *  will  occur*/
    
    int sumxy = (x+y) >> 31; // Calculate the sum and get the sign bit
    int sign_x = (x >> 31) ; // Pull the sign bit for x we do these as seperate steps as to use sign_y later
    int sign_y = (y >> 31); // Pull the sign bit for y
    return !((!(sign_x ^ sign_y)) & (sumxy ^ sign_y)); // This is the final step to compare the sign of x and y
                                                       // With the sign of the sum we use xor as operators as to 
                                                       // clear 1^1 to 0 and maintain 1 when they are differnt signs
}
/* 
 * rotateRight - Rotate x to the right by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateRight(0x87654321,4) = 0x76543218
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3 
 */
int rotateRight(int x, int n) {
    /* Reference used: Hackers delight page 47 however I could only use a bit of the logic since the rotate right they
     * show is works only for unsigned, the rest of the logic I borrowed from my byte swap function.
     * This function  gets the bits we want into their posistion with the first step , creates a mask to clear the slot
     * in the original number and then shifts the original number over clears the hole and inserts the bits into the hole*/
    
    int isobit = x << ((~n+1) + 32); // get the bits we are rotating, this was shown in Hackers delight
    int holepunch = ~(1<<31) >> (n+(~0)); // create a mask to save the bits to keep and clear a hole for rotated bits
                                          // When 0 the mask is -1 and the and preserves all the original bits
    return (((x >> n) & holepunch) | isobit); // The final and most important step shift the original number over n times
                                              // to get the numbers the numbers into there new spots we then and with
                                              // holepunch to clear the numbers that we are going to replace then just or 
                                              // the isolated bits into the slot!
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
    /*This problem takes a different appraoch then rotateRight did, however I modeled my holepunch after what I used
     * in rotate right we create the mask in much a similiar way however we must pay more attention to the case of when 0
     * is passed as an argument. the mask produces all ones in 0 is passed to not change any values*/

    int holepunch = ~(((1<<31) >> n) << 1); // create a mask to save the bits we we want and clear the logical shift holes
                                            // When it is 0 this mask is -1 or 0xffffffff
    return ((x >> n) & holepunch); // The final and most important step shift the original number over n times and mask
                                   // the bits that we don't want  
}
/*
 * ezThreeFourths - multiplies by 3/4 rounding toward 0,
 *   Should exactly duplicate effect of C expression (x*3/4),
 *   including overflow behavior.
 *   Examples: ezThreeFourths(11) = 8
 *             ezThreeFourths(-9) = -6
 *             ezThreeFourths(1073741824) = -268435456 (overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 3
 */
int ezThreeFourths(int x) {
    /*I found the solution to this problem in hackers delight page 64. This shows how to round a number towards 0 when 
     * multiplying. I take the concept that x * 3/4 is essentailly x/1 * 3/4 or (x*3)/4. We round towards 0 by 
     * the method described in hackers delight page 64*/
 
    int mult3 = (x << 1) + x; // This is multiplying x by three by first multplying by 2 and adding x
    int round0 = ((1 << 2)+(~0)) & (mult3 >> 31); // This creates a mask of 3 so we can check our round to 0
    return (mult3 + round0) >> 2; // Apply the number (1 or 0) and perform the division    

}
/*
 * multFiveEighths - multiplies by 5/8 rounding toward 0.
 *   Should exactly duplicate effect of C expression (x*5/8),
 *   including overflow behavior.
 *   Examples: multFiveEighths(77) = 48
 *             multFiveEighths(-22) = -13
 *             multFiveEighths(1073741824) = 13421728 (overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 3
 */
int multFiveEighths(int x) {
    /*This is the same thing as ezThreeFourths using the same rounding technique and creating the numbers we need
     * is the same except we are multiplying by 5/8 instead of 3/4*/

    int mult5 = (x << 2) + x; // This is multiplying x by 5 by first multplying by 4 and adding x
    int round0 = ((1 << 3)+(~0)) & (mult5 >> 31); // This creates a mask of 7 so we can check our round to 0
    return (mult5 + round0) >> 3; // Apply the number (1 or 0) and perform the division        
}
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
    /*I used some ideas I discovered in working with swapBytes to come to this solution. the holepunch gets our mask of 
     * 0xff into posistion to clear all values except the slot we want and then negate to creat the mask we will use to
     * preserve all the other numbers with and clear the byte slot with. we get c into the right spot in the 32 bit 
     * number and then clear with hole with the holepunch and slip the new numer in with or. n << 3 works since 2^3 is
     * 8 and n * 8 tells how many bytes to move*/

    int holepunch = ~(0xff << (n << 3)); // This creates a mask to clear the byte slot we want and keep the rest
    int repla = c << (n << 3); // Get new byte into posistion 
    return ((x & holepunch) | repla); // Clear the hole and put new byte into the empty slot
}
/* 
 * rempwr2 - Compute x%(2^n), for 0 <= n <= 30
 *   Negative arguments should yield negative remainders
 *   Examples: rempwr2(15,2) = 3, rempwr2(-35,3) = -3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int rempwr2(int x, int n) {
    /*Resource used -> Hackers delight: page 189 gives the formula to calulate this with sign bit
     * First we use the same steps used in calculating the absValue. except we now also calculate 2^n - 1
     * Finally we and the Absolute value with 2^n -1 and xor with either 0 or -1 since 0 is all 1's or all
     * 0's ^ all 0's changes nothing and ^ of all ones toggles the bits then the + neg_t is 1 if the original number 
     * was negative or 0 if it was positive.*/

    int t = (x >> 31); // Get the sign bit
    int  neg_t = (~t) + 1; // Step in calculating the absolute value
    int z = (1 << n) + (~0); //  Calculate (2^n)-1
    int absval = (x ^ t) + neg_t; // finish calcualting the absoulte value
    return ((absval & z)^t)+neg_t; // toggle bits and add one if negative to change the answer back to - or does 
                                   // Nothing if it was originally positive.

}
/* Rating 4 ==> 28 points */
/* 
 * absVal - absolute value of x
 *   Example: absVal(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int absVal(int x) {
    /*This solution was taken from Hackers delight page 30. It takes the MSB or sign bit and stores it in a variable
     * next it finds -y so if x was positive this number will be 0 and -0 = 0 otherwise this number will be 1
     * and then x ^ y will either put out x if x was positive or x-1 if neative then add neg_y will be either one when 
     * it was negative and increment the number to abs or be +0 if it was originally positive
     * It is not a straight copy however it is very close checked the boundary cases with pen and paper to verify its
     * corectness!*/

    int y = x >> 31; // This will create either 0 or -1
    int neg_y = (~y) + 1; // this will stay zero if x was positive or it will become 1 it x was negative 
    return (x ^ y) + neg_y; // x ^ with 0 is x and -x ^ with -1 is x-1 thus adding the 1 at the end to equalize the
                            // absolute value very slick way to handle it1
}
/* 
 * float_f2i - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int float_f2i(unsigned uf) { 
    /*In Computer Systems: A programmers perspective page 116 gives a list of some numbers for an example float this showed
     * me that first ints have a frac of 0. Page 119 also show how to go from a int to a float
     * our frac field is 23 with and implied 1 so we can at most shift the implied 1 over 23 times to fill the LSB and 
     * create 1. Page 116 also showed me that a number with e < bias will be a number too small to create an integer
     * thus e must be at least tMax for 8 bits to create 1.
     * Realizing the smallest int 1 = 0x3f800000 is the floating point of 1 i tested and found a case that made it the 
     * float of 3f800000 into 1 int. Also i ran the calulations with 2 = 0x40000000 finally I wanted to test 
     * the largest case E = 30 the float representation of the larges int is 0x4e800000 = 2^30. 
     * We can't use an exponent bigger since any bigger would shift past the MSB of exp and change the sign since any
     * number with an exp greater than 22 needs to shift to the left*/

        int frac = (~((0xff << 24) | (1 << 23))) & uf; // isolate only the frac and mask off the rest               
	int integ = frac; // Create this to manipulate frac without changing original argument         
    	int sign = uf >> 31 & 1; // Isolate the sign bit we want and mask off the rest
	int exp = (uf >> 23) & 0xFF; // Isolate the exp and mask off the rest
	int bias = 0x7F; // create the bias of 2^(8-1)-1 or 127 for single precision floating point numbers
        int tMin = (1 << 31); // Return number when special cases 
        int E = 0; // This will be our exponent for now 0 is a placeholder
  
  
  // denormalized case and normalized exp less than Bias cases
  // The exp needs to be a min of 127 or tMax for 8 bits to create the first int 1 so any below this
  // fall outside the range of integers
  if (exp < bias) {
    return 0x00;
  }

  // This checks for NaN and Infinity since they have an exp of all 1's
  if (exp == 0xFF) { 
    return tMin; // Return unsigned tMin 
  }  
  
  // normalized cases
  E = exp + ((~bias)+1); // Compute E from the definion that the exponent is the e - bias since we know our number is 
                         // in a workable and normalized format

  frac = (1 << 23) | frac; //Since we know our number is normalized we add the implied one to the front of the frac 
                          // this works even if this is already 1, with the implied one technically frac is 24 long now

  
  // This will cause overflow becuase our biggest E we can have is 30 any 
  // larger will cause overflow for a single precision number
  if (31 <= E) {
    return tMin;
  }
  
  // We check to see if the number is 23 or greater since this is outside the range of representable integers,
  // if it is we need to bring it into the range of representable ints by subtracting 23 from the number. 
  // NOTE: This number will never be more than 30 because that's the most shifts we can make and still be in 
  // the exp field is 30 -23 = 7. thus it wont shift over into the sign bit slot. The if was originall the only 
  // statement I was using but after running tests dicovered this was lacking. I took that approach first since it is
  // close to 2^e * M
  if (E <= 22) { 
      // This works because we can shift the the leading one at most 23 times without falling off the end
      // and E can be 0 when it represents 1 float
      integ = frac >> (23 - E);      
  }
  else {
      // I discovered this when trying to create the biggest number 2^30 it worked for that and every number down
      // to 23 less than 23 the else works for every other value of E down to 0
      // I tried the boundary of 23 due to the fact Hackers delight page 339 shows float to int32 of integers being 2^23 
      // -2^23 the bounds are wrong but the pivot of 23 works.
      integ = frac << (E - 23);
      
  }

  if (sign){
    integ = (~integ) + 1; // If the original sign bit was neg the statment is true and we negate our int 
                          // Other wise the original argument was positive and our result is ok. it must be done like this
                          // since the sign bit is rotated off or out of posistion 
  }
  
  return integ; // Return the answer
}

/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
    // float_f2i took me a solid 4 or 5 hours to get right and sadly I ran out of time before I could finish 
    // I feel like I could make a solution based on what we read in Computer Systems: A programmers perspective.
  return 2;
}
/*
 * trueThreeFourths - multiplies by 3/4 rounding toward 0,
 *   avoiding errors due to overflow
 *   Examples: trueThreeFourths(11) = 8
 *             trueThreeFourths(-9) = -6
 *             trueThreeFourths(1073741824) = 805306368 (no overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int trueThreeFourths(int x)
{
    // I ran out of time on this and was not 100% sure of the approach I would need to play with it more to 
    // to understand the solution but my time ran out.
  return 2;
}
/*
 * isPower2 - returns 1 if x is a power of 2, and 0 otherwise
 *   Examples: isPower2(5) = 0, isPower2(8) = 1, isPower2(0) = 0
 *   Note that no negative number is a power of 2.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int isPower2(int x) {
    /* Section 3.3 of hackers delight talked about some power of two properties
     * When experimenting with methods to solve logical negation 32 was number I used when working on examples when trying
     * and experiment of using & instead of or I noticed if you have 32 & -32 = 32. Trying with other powers of 2 we 
     * can observe similiar behaviour and if not a power of 2 we get 1 as the result of anding x & -x. This worked for most
     * cases however we have issuse when x is 0 and tMin was having problems so I had to take the sign bit into account.
     * I move the sign bit into the LSB spot if its positive this number is 0 and if negative -1 i want the logicalNeg
     * of this since if its positive I want 1 and -1 I want 0. I calculate the check so check when some power of 2 will 
     * be 1 and 0 otherwise becuase of the logical neg on check, we xor check with x since if its a power of 2 this will be
     * 0 and otherwise 1 when x is a power of 2 the sign bit will be 1 so 1 & 1 is 1 and since !!x =1 if x > 0 this is 
     * 1 & 1 again so we end with 1 however if we where passed 0 sbit is 1 check is 1 but !!x is 0 so this fixes that
     * issue and finally for tMin sBit becomes 0 so it makes the first and 0 and then fails fails the last !!x since
     * 0 & 1 = 0*/

    int sbit = !(x >> 31); // Gets 1 if positive 0 if negative
    int negx = (~x) + 1; // get the -x 
    int check = (negx & x); // and them to get either 1 or x
    return (!(check^x)) & sbit & (!!x); // check boundry cases to ensure no mistakes and return
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {
  return 2;
  // I did not have time to finish this. I found in Hackers delight some potential solutions but
  // sadly ran out of time before I could attempt this.
}
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
    /*This problem becomes easier when you think of some unique properties of 0 and numbers that aren't 0
     * if you have a x and a -x and you or them togethor if it isn't 0 then the sign bit should countaint a 1
     * except if its a 0 the sign bit remains zero. So we move the sign bit into LSB bit with a >> 31 if its positive
     * thw number we will have is -1 and if 0 it'll be 0 then we add one and the positive number will become 0 and
     * a 0 will become 1! I originall though xor instead of or but it fails on tMin I though xor would work since xor
     * sometimes works as a subtraction in the past.*/

  int negx = (~x) + 1; // Create the negative of the int we are passed 
  int mask = (x | negx) >> 31; // Or with the negative number and the move MSB to LSB
  return mask + 1; // add one to return the number we want
}
