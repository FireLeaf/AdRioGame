/*******************************************************************************
	FILE:		XMD5.h
	
	DESCRIPTTION:	md5
	
	CREATED BY: YangCao, 2014/11/19

	Copyright (C) - All Rights Reserved with Coconat
*******************************************************************************/

#ifndef __COCONAT_XMD5_H_
#define __COCONAT_XMD5_H_

#include "XPreDefine.h"
/* POINTER defines a generic pointer type */
typedef unsigned char * POINTER;

/* UINT2 defines a two byte word */
//typedef unsigned short int UINT2;

/* UINT4 defines a four byte word */
typedef unsigned long int UINT4;


/* MD5 context. */
 X_DLL typedef struct {
	UINT4 state[4];                                   /* state (ABCD) */
	UINT4 count[2];        /* number of bits, modulo 2^64 (lsb first) */
	unsigned char buffer[64];                         /* input buffer */
} MD5_CTX;

X_DLL void MD5Init (MD5_CTX *context);
X_DLL void MD5Update (MD5_CTX *context, unsigned char *input, unsigned int inputLen);
X_DLL void MD5UpdaterString(MD5_CTX *context,const char *string);
X_DLL int MD5FileUpdateFile (MD5_CTX *context,char *filename);
X_DLL void MD5Final (unsigned char digest[16], MD5_CTX *context);
X_DLL void MDString (char *string,unsigned char digest[16]);
X_DLL int MD5File (const char *filename, unsigned char digest[16]);
X_DLL int MD5Memory(unsigned char* input, int len, unsigned char digest[16]);

#endif