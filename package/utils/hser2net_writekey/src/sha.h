/********************************************************************************* 
Copyright (C) 2006 ViewAt Technology Co., LTD.                         
                                                                                 
System Name    :  vos                                            
Module Name    :  Hash Algorithm driver                            
File   Name    :  sha.h                                                  
Revision       :  01.00                                                     
Date           :  2006/12/1           
Dir            :  drv\encrypt
error code     :                                                                                              
***********************************************************************************/
#ifndef SHA_H
#define SHA_H

//#include "global.h"

typedef unsigned char BYTE;


#define SHA_VERSION 1

//in PC or C51 it is 1234
//#define SHA_BYTE_ORDER 1234
//in MC68Kvz328 it is 4321
#define SHA_BYTE_ORDER 1234


/* Useful defines & typedefs */
//typedef unsigned char BYTE; /* 8-bit quantity */
typedef unsigned long LONG;   /* 32-or-more-bit quantity */

#define SHA_BLOCKSIZE         64
#define SHA_DIGESTSIZE        20


typedef struct //__attribute__ ((__packed__))
{
    LONG digest[5];      
    LONG count_lo, count_hi;  
    BYTE data[SHA_BLOCKSIZE]; 
    int local;           
} SHA_INFO;

void sha_init(SHA_INFO *);
void sha_update(SHA_INFO *, BYTE *, int);
void sha_final(unsigned char [20], SHA_INFO *);
void Lib_Hash(BYTE* DataIn,unsigned int DataInLen,BYTE* DataOut);

#endif