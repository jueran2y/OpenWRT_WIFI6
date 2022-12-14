#include <sys/types.h>
#include <fcntl.h>
#include <syslog.h>
#include <signal.h>
#include <stdio.h>
#include <sys/ioctl.h>

#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>
#include <limits.h>
#include <stdarg.h>
#include <assert.h>
#include <stdint.h>
#include <errno.h>

#include <unistd.h>

#include <sys/msg.h>

#include "des.h"
#include "sha.h"

#ifndef uchar
#define uchar unsigned char
#endif
#ifndef uint
#define uint unsigned int
#endif
#ifndef ushort
#define ushort unsigned short
#endif
#ifndef ulong
#define ulong unsigned long
#endif

#define TIM_SET

#define TIM_DEBUG(fmt, arg...) printf(fmt, ##arg)
#define TIM_TRACE() printf("In:%s(%d)\r\n", __FUNCTION__, __LINE__)
#define TIM_ERROR(fmt, arg...) printf(fmt, ##arg)

#define perror printf

extern unsigned char* flash_read2(int offset, int count);

#define dprintf

uchar key1[] = {
	0xBC, 0xAE, 0x8E, 0xB0, 0x10, 0xF9, 0x02, 0x99,
	0xC2, 0x6D, 0xBA, 0x1C, 0x7B, 0x5B, 0x28, 0xF2};

uchar key2[] = {
	0x9C, 0x96, 0x67, 0x02, 0xE1, 0x83, 0x78, 0xB2,
	0x98, 0x45, 0xD9, 0x2F, 0x5C, 0x04, 0x3B, 0x91,
	0xB8, 0xB5, 0x22, 0x49, 0x96, 0x58, 0x61, 0x48

};

uchar key22[] = {
	0x9E, 0xB3, 0x5A, 0xD8, 0x45, 0x01, 0xB9, 0xF6,
	0x7D, 0x0D, 0x1C, 0xB2, 0x8F, 0xE9, 0x66, 0x1b};

#define po0 0xf8
#define po1 0x91
#define po2 0xef
#define po3 0x26
#define po4 0x4c
#define po5 0x41
#define po6 0x74
#define po7 0x90

#define po10 0x4b
#define po11 0xc6
#define po12 0xfc
#define po13 0x28
#define po14 0x1b
#define po15 0x6a
#define po16 0x09
#define po17 0x97

#define po210 0x12
#define po211 0x2c
#define po212 0xf3
#define po213 0x77
#define po214 0x5a
#define po215 0xb3
#define po216 0x87
#define po217 0xdd

#define TIM_BASE1 0X234F200
#define TIM_BASE2 0X234F700
#define TIM_BASE3 0X234FC00

void mac_get_test(uchar *p)
{
	uchar i;
	for (i = 0; i < 6; i++)
	{
		p[i] = i;
	}
}

void mac_get_test2(uchar *p)
{

	uchar i;
	for (i = 0; i < 8; i++)
	{
		p[i] = i;
	}
}

uchar tim1[8];
uchar tim2[8];
uchar tim3[8];

void tim_print(uchar *p)
{

	uchar i;
	for (i = 0; i < 8; i++) {
		TIM_DEBUG("%02x ", p[i]);
	}

	TIM_DEBUG("\r\n");
}

unsigned char *flash_read2(int offset, int count);

int flash_write(int offset, int value);

void get_mac1(uchar *p)
{
	mac_get_test(p);

	{
		uint base = 0;
		uchar *px;

		volatile uint x = 4 + 4;

		base = ((x << 16) - 12); //0x3FFF4

		px = flash_read2(base + 0, 1);
		if (px) {
			p[0] = *px;
			free(px);
		}
		px = flash_read2(base + 1, 1);
		if (px) {
			p[1] = *px;
			free(px);
		}
		px = flash_read2(base + 2, 1);
		if (px) {
			p[2] = *px;
			free(px);
		}
		px = flash_read2(base + 3, 1);
		if (px) {
			p[3] = *px;
			free(px);
		}
		px = flash_read2(base + 4, 1);
		if (px) {
			p[4] = *px;
			free(px);
		}
		px = flash_read2(base + 5, 1);
		if (px) {
			p[5] = *px;
			free(px);
		}
	}

	TIM_DEBUG("MAC1:");
	tim_print(p);
}

void get_mac2(uchar *p)
{
	mac_get_test(p);
	{
		uint base = 0;
		uchar *px;

		volatile uint x = 4 + 4;

		base = ((x << 16) - 6); //0x3FFFA

		px = flash_read2(base + 0, 1);
		if (px) {
			p[0] = *px;
			free(px);
		}
		px = flash_read2(base + 1, 1);
		if (px) {
			p[1] = *px;
			free(px);
		}
		px = flash_read2(base + 2, 1);
		if (px)
		{
			p[2] = *px;
			free(px);
		}
		px = flash_read2(base + 3, 1);
		if (px)
		{
			p[3] = *px;
			free(px);
		}
		px = flash_read2(base + 4, 1);
		if (px)
		{
			p[4] = *px;
			free(px);
		}
		px = flash_read2(base + 5, 1);
		if (px)
		{
			p[5] = *px;
			free(px);
		}
	}
}

//void Lib_Hash(uchar *DataIn, unsigned int DataInLen, uchar *DataOut);

extern char **argv_;

void get_mac3(uchar *p)
{
	mac_get_test(p);

	{
		FILE *fp;

		uchar x = 10;

	again1:

		if ((fp = fopen("/bin/readme", "r")))
		{
			//	if ((fp = fopen("/bin/ser2net", "r"))) {

			//			fseek(fd, o, SEEK_SET);
			fread(p, 7, 1, fp);
			fclose(fp);
		}
		else
		{
			if (x--)
				goto again1;
		}
	}

	{
		uchar out[20];
		uchar *buf;
		uint len;

		uchar x = 10;

		FILE *fp;
	//		if ((fp = fopen("/bin/readme", "r"))) {
	again2:

#if 0
#ifdef TIM_SET

if ((fp = fopen("/bin/ser2net", "r"))) {

#else

if ((fp = fopen(argv_[0], "r"))) {

#endif

#else
		if ((fp = fopen("/bin/readme", "r")))
		{

#endif

		//			fseek(fd, o, SEEK_SET);

		fseek(fp, 0, SEEK_END);
		len = ftell(fp); //return NULL;

		fseek(fp, 0, SEEK_SET);

		buf = (unsigned char *)malloc(len);
		if (buf == NULL)
		{
			fprintf(stderr, "fail to alloc memory for %d bytes\n", len);
			fclose(fp);
			return;
		}

		fread(buf, sizeof(char), len, fp);

		fclose(fp);

		tim_print(p);

		Lib_Hash(buf, len, out);

		p[3] = out[3];
		p[4] = out[7];
		p[5] = out[9];
		p[6] = out[11];

		tim_print(p);

		free(buf);
	}
	else
	{
		if (x--)
			goto again2;
	}
}
}

void get_m1(uchar *p)
{

	{
		uchar i;
		for (i = 0; i < 8; i++)
		{
			p[i] = tim1[i];
		}
	}

	{
		uint base = 0;
		uchar *px;

		base = (TIM_BASE1);

		px = flash_read2(base + po0, 1);
		if (px)
		{
			p[0] = *px;
			free(px);
		}
		px = flash_read2(base + po1, 1);
		if (px)
		{
			p[1] = *px;
			free(px);
		}
		px = flash_read2(base + po2, 1);
		if (px)
		{
			p[2] = *px;
			free(px);
		}
		px = flash_read2(base + po3, 1);
		if (px)
		{
			p[3] = *px;
			free(px);
		}
		px = flash_read2(base + po4, 1);
		if (px)
		{
			p[4] = *px;
			free(px);
		}
		px = flash_read2(base + po5, 1);
		if (px)
		{
			p[5] = *px;
			free(px);
		}
		px = flash_read2(base + po6, 1);
		if (px)
		{
			p[6] = *px;
			free(px);
		}
		px = flash_read2(base + po7, 1);
		if (px)
		{
			p[7] = *px;
			free(px);
		}

		TIM_DEBUG("MAC1:");
		tim_print(p);
	}
}

void tim_error2(void)
{
	TIM_ERROR("ERROR:%s(%d)\r\n", "", __LINE__);
	//	while(1)sleep(3600);
	exit(0);
}

void get_m2(uchar *p)
{
	{
		uchar i;
		for (i = 0; i < 8; i++)
		{
			p[i] = tim2[i];
		}

		{
			uint base = 0;
			uchar *px;

			base = (TIM_BASE2);

			px = flash_read2(base + po10, 1);
			if (px)
			{
				p[0] = *px;
				free(px);
			}
			px = flash_read2(base + po11, 1);
			if (px)
			{
				p[1] = *px;
				free(px);
			}
			px = flash_read2(base + po12, 1);
			if (px)
			{
				p[2] = *px;
				free(px);
			}
			px = flash_read2(base + po13, 1);
			if (px)
			{
				p[3] = *px;
				free(px);
			}
			px = flash_read2(base + po14, 1);
			if (px)
			{
				p[4] = *px;
				free(px);
			}
			px = flash_read2(base + po15, 1);
			if (px)
			{
				p[5] = *px;
				free(px);
			}
			px = flash_read2(base + po16, 1);
			if (px)
			{
				p[6] = *px;
				free(px);
			}
			px = flash_read2(base + po17, 1);
			if (px)
			{
				p[7] = *px;
				free(px);
			}
		}
	}
}

void get_m3(uchar *p)
{
	{
		uchar i;
		for (i = 0; i < 8; i++)
		{
			p[i] = tim3[i];
		}

		{
			uint base = 0;
			uchar *px;

			base = (TIM_BASE3);

			px = flash_read2(base + po210, 1);
			if (px)
			{
				p[0] = *px;
				free(px);
			}
			px = flash_read2(base + po211, 1);
			if (px)
			{
				p[1] = *px;
				free(px);
			}
			px = flash_read2(base + po212, 1);
			if (px)
			{
				p[2] = *px;
				free(px);
			}
			px = flash_read2(base + po213, 1);
			if (px)
			{
				p[3] = *px;
				free(px);
			}
			px = flash_read2(base + po214, 1);
			if (px)
			{
				p[4] = *px;
				free(px);
			}
			px = flash_read2(base + po215, 1);
			if (px)
			{
				p[5] = *px;
				free(px);
			}
			px = flash_read2(base + po216, 1);
			if (px)
			{
				p[6] = *px;
				free(px);
			}
			px = flash_read2(base + po217, 1);
			if (px)
			{
				p[7] = *px;
				free(px);
			}
		}
	}
}

void tim_error3(void)
{
	TIM_ERROR("ERROR:%s(%d)\r\n", "", __LINE__);
	sleep(76);
	exit(0);
}

void tim_error1(void);
void tim_error2(void);
void tim_error3(void);

uchar hlk_check1()
{
	uchar i;
	uchar mac[8];
	uchar mac2[8];
	uchar key[24];

	uchar m1[8];

	uint ii;

	uchar xxx = 0;

#if keyCHECKdisable
	return 0;
#endif

again:

	get_mac1(mac);
	get_m1(m1);
	mac[6] = 0x19;
	mac[7] = 0x77;
	for (i = 0; i < 8; i++)
	{
		ii = mac[i] ^ key1[8 + i];
		mac[i] = ii & 0xff;
	}

	for (i = 0; i < 8; i++)
	{
		ii = key1[i] ^ key1[8 + i];
		mac2[i] = ii & 0xff;
	}

	Lib_DES(m1, mac2, 0);

	Lib_DES(m1, mac2, 0);

	tim_print(mac);
	tim_print(m1);

	for (i = 0; i < 2; i++)
	{
		if (mac[i] != m1[i])
		{
			if (xxx++ > 3)
			{

				//error
				tim_error1();
			}
			else
				goto again;
		}
	}

	for (i = 4; i < 6; i++)
	{
		if (mac[i] != m1[i])
		{
			if (xxx++ > 3)
			{

				//error
				tim_error1();
			}
			else
				goto again;
		}
	}
}

#ifdef TIM_SET

typedef struct key_b_
{
	unsigned int addr;
	unsigned int value;
} key_b;

void set_m1(uchar *p)
{
	uchar i;
	for (i = 0; i < 8; i++) {
		tim1[i] = p[i];
	}

	uint base = 0;
	uchar *px;
	key_b buf[8];

	buf[0].addr = po0;
	buf[0].value = p[0];

	buf[1].addr = po1;
	buf[1].value = p[1];

	buf[2].addr = po2;
	buf[2].value = p[2];

	buf[3].addr = po3;
	buf[3].value = p[3];

	buf[4].addr = po4;
	buf[4].value = p[4];

	buf[5].addr = po5;
	buf[5].value = p[5];

	buf[6].addr = po6;
	buf[6].value = p[6];

	buf[7].addr = po7;
	buf[7].value = p[7];

	flash_write_key(TIM_BASE1, buf, 8);
}

void set_m2(uchar *p)
{
	tim_print(p);
	{
		uchar i;
		for (i = 0; i < 8; i++)
		{
			tim2[i] = p[i];
		}
	}

	{
		uint base = 0;
		uchar *px;
		key_b buf[8];

		buf[0].addr = po10;
		buf[0].value = p[0];

		buf[1].addr = po11;
		buf[1].value = p[1];

		buf[2].addr = po12;
		buf[2].value = p[2];

		buf[3].addr = po13;
		buf[3].value = p[3];

		buf[4].addr = po14;
		buf[4].value = p[4];

		buf[5].addr = po15;
		buf[5].value = p[5];

		buf[6].addr = po16;
		buf[6].value = p[6];

		buf[7].addr = po17;
		buf[7].value = p[7];

		flash_write_key(TIM_BASE2, buf, 8);
	}
}

void set_m3(uchar *p)
{
	tim_print(p);

	{
		uchar i;
		for (i = 0; i < 8; i++)
		{
			tim3[i] = p[i];
		}
	}
	{
		uint base = 0;
		uchar *px;
		key_b buf[8];

		buf[0].addr = po210;
		buf[0].value = p[0];

		buf[1].addr = po211;
		buf[1].value = p[1];

		buf[2].addr = po212;
		buf[2].value = p[2];

		buf[3].addr = po213;
		buf[3].value = p[3];

		buf[4].addr = po214;
		buf[4].value = p[4];

		buf[5].addr = po215;
		buf[5].value = p[5];

		buf[6].addr = po216;
		buf[6].value = p[6];

		buf[7].addr = po217;
		buf[7].value = p[7];

		flash_write_key(TIM_BASE3, buf, 8);
	}
}

uchar hlk_check1_set()
{
	uchar i;
	uchar mac[8];
	uchar mac2[8];
	uchar key[24];

	uint ii;

	get_mac1(mac);
	mac[6] = 0x19;
	mac[7] = 0x77;
	for (i = 0; i < 8; i++) {
		ii = mac[i] ^ key1[8 + i];
		mac[i] = ii & 0xff;
	}

	for (i = 0; i < 8; i++) {
		ii = key1[i] ^ key1[8 + i];
		mac2[i] = ii & 0xff;
	}

	Lib_DES(mac, mac2, 1);

	Lib_DES(mac, mac2, 1);

	set_m1(mac);

	tim_print(mac);
}

uchar hlk_check2_set()
{
	uchar i;
	uchar mac[8];
	uchar mac2[8];

	uchar m1[8];

	uint ii;

	get_mac2(mac);
	mac[6] = 0x19;
	mac[7] = 0x77;

	for (i = 0; i < 8; i++)
	{
		ii = mac[i] + key1[8 + i];
		mac[i] = ii & 0xff;
	}

	for (i = 0; i < 8; i++)
	{
		mac[i] = ~mac[i];
	}

	for (i = 0; i < 8; i++)
	{
		ii = key1[i] ^ key1[8 + i];
		mac2[i] = ii & 0xff;
	}

	for (i = 0; i < 8; i++)
	{
		mac2[i] = ~mac2[i];
	}

	Lib_DES(mac, mac2, 1);

	for (i = 0; i < 8; i++)
	{
		mac2[i] = ~mac2[i];
	}

	Lib_DES(mac, mac2, 1);

	set_m2(mac);
}

uchar hlk_check3_set()
{
	uchar i;
	uchar mac[8];
	uchar mac2[8];

	uint ii;

	get_mac3(mac);
	mac[7] = 0x77;

	for (i = 0; i < 8; i++)
	{
		mac[i] ^= key1[8 + i];
	}

	for (i = 0; i < 8; i++)
	{
		mac[i] ^= key22[8 + i];
	}

	Lib_DES3_24(mac, key2, 1);

	set_m3(mac);
}

uchar hlk_check1_return()
{
	uchar i;
	uchar mac[8];
	uchar mac2[8];
	uchar key[24];

	uchar m1[8];

	uint ii;

	uchar xxx = 0;

again:

	get_mac1(mac);
	get_m1(m1);
	mac[6] = 0x19;
	mac[7] = 0x77;
	for (i = 0; i < 8; i++)
	{
		ii = mac[i] ^ key1[8 + i];
		mac[i] = ii & 0xff;
	}

	for (i = 0; i < 8; i++)
	{
		ii = key1[i] ^ key1[8 + i];
		mac2[i] = ii & 0xff;
	}

	Lib_DES(m1, mac2, 0);

	Lib_DES(m1, mac2, 0);

	tim_print(mac);
	tim_print(m1);

	for (i = 0; i < 2; i++) {
		if (mac[i] != m1[i]) {
			if (xxx++ > 3) {
				return 1;
				tim_error1();
			} else {
				goto again;
			}
		}
	}

	for (i = 4; i < 6; i++) {
		if (mac[i] != m1[i]) {
			if (xxx++ > 3) {
				//error
				return 1;
				tim_error1();
			} else {
				goto again;
			}
		}
	}

	return 0;
}

uchar hlk_check2_return()
{
	uchar i;
	uchar mac[8];
	uchar mac2[8];

	uchar m1[8];

	uint ii;

	uchar xxx = 0;

again:

	get_mac2(mac);
	get_m2(m1);
	mac[6] = 0x19;
	mac[7] = 0x77;
	for (i = 0; i < 8; i++)
	{
		ii = key1[i] ^ key1[8 + i];
		mac2[i] = ii & 0xff;
	}

	Lib_DES(m1, mac2, 0);

	for (i = 0; i < 8; i++)
	{
		mac2[i] = ~mac2[i];
	}

	Lib_DES(m1, mac2, 0);

	for (i = 0; i < 8; i++)
	{
		ii = mac[i] + key1[8 + i];
		mac[i] = ii & 0xff;
	}

	for (i = 0; i < 8; i++)
	{
		mac[i] = ~mac[i];
	}

	tim_print(mac);
	tim_print(m1);

	for (i = 0; i < 2; i++)
	{
		if (mac[i] != m1[i])
		{
			if (xxx++ > 3)
			{

				//error
				return 1;
				tim_error2();
			}
			else
				goto again;
		}
	}

	for (i = 4; i < 6; i++)
	{
		if (mac[i] != m1[i])
		{
			if (xxx++ > 3)
			{

				//error
				return 1;
				tim_error2();
			}
			else
				goto again;
		}
	}

	return 0;
}

uchar hlk_check3_return()
{
	uchar ret = 0;
	uchar i;
	uchar mac[8];
	uchar mac2[8];

	uchar m1[8];

	uint ii;

	uchar xxx = 0;

again:

	get_mac3(mac);
	get_m3(m1);
	mac[7] = 0x77;

	tim_print(m1);

	for (i = 0; i < 8; i++)
	{
		mac[i] ^= key1[8 + i];
	}

	for (i = 0; i < 8; i++)
	{
		mac[i] ^= key22[8 + i];
	}

	Lib_DES3_24(m1, key2, 0);

	tim_print(mac);
	tim_print(m1);

	for (i = 2; i < 6; i++)
	{
		if (mac[i] != m1[i])
		{
			if (xxx++ > 3)
			{

				//error
				return 1;
				tim_error3();
				ret = 1;
			}
			else
				goto again;
		}
	}

	return 0;

	//	return ret;
}

#endif

void tim_error1(void)
{
	TIM_ERROR("ERROR:%s(%d)\r\n", "", __LINE__);
	//	exit(0);
	while (1)
		sleep(3600);
}

uchar hlk_check2()
{
	uchar i;
	uchar mac[8];
	uchar mac2[8];

	uchar m1[8];

	uint ii;

	uchar xxx = 0;

#if keyCHECKdisable
	return 0;
#endif

again:

	get_mac2(mac);
	get_m2(m1);
	mac[6] = 0x19;
	mac[7] = 0x77;
	for (i = 0; i < 8; i++)
	{
		ii = key1[i] ^ key1[8 + i];
		mac2[i] = ii & 0xff;
	}

	Lib_DES(m1, mac2, 0);

	for (i = 0; i < 8; i++)
	{
		mac2[i] = ~mac2[i];
	}

	Lib_DES(m1, mac2, 0);

	for (i = 0; i < 8; i++)
	{
		ii = mac[i] + key1[8 + i];
		mac[i] = ii & 0xff;
	}

	for (i = 0; i < 8; i++)
	{
		mac[i] = ~mac[i];
	}

	tim_print(mac);
	tim_print(m1);

	for (i = 0; i < 2; i++)
	{
		if (mac[i] != m1[i])
		{
			if (xxx++ > 3)
			{

				//error
				tim_error2();
			}
			else
				goto again;
		}
	}

	for (i = 4; i < 6; i++)
	{
		if (mac[i] != m1[i])
		{
			if (xxx++ > 3)
			{

				//error
				tim_error2();
			}
			else
				goto again;
		}
	}
}

uchar hlk_check3()
{
	uchar ret = 0;
	uchar i;
	uchar mac[8];
	uchar mac2[8];

	uchar m1[8];

	uint ii;

	uchar xxx = 0;

#if keyCHECKdisable
	return 0;
#endif

again:

	get_mac3(mac);
	get_m3(m1);
	mac[7] = 0x77;

	tim_print(m1);

	for (i = 0; i < 8; i++)
	{
		mac[i] ^= key1[8 + i];
	}

	for (i = 0; i < 8; i++)
	{
		mac[i] ^= key22[8 + i];
	}

	Lib_DES3_24(m1, key2, 0);

	tim_print(mac);
	tim_print(m1);

	for (i = 2; i < 6; i++)
	{
		if (mac[i] != m1[i])
		{
			if (xxx++ > 3)
			{
				tim_error3();
				ret = 1;
			}
			else
				goto again;
		}
	}

	return ret;
}

#ifdef TIM_SET

#define MAX_TRY 3

void check_test(void)
{

	int i = 0;


	hlk_check1_set();
	hlk_check1_return();
	hlk_check2_set();
	hlk_check2_return();
	hlk_check3_set();
	hlk_check3_return();
#if 0
	for (i = 0; i < MAX_TRY; i++) {

		hlk_check2_set();
		if (hlk_check2_return() == 0)
		{
			break;
		}
	}
	if (i >= MAX_TRY)
		exit(1);

	for (i = 0; i < MAX_TRY; i++)
	{

		hlk_check3_set();
		if (hlk_check3_return() == 0)
		{
			break;
		}
	}
	if (i >= MAX_TRY)
		exit(1);

	TIM_ERROR("in:%s(%d)\r\n", __FUNCTION__, __LINE__);

	exit(0);

	hlk_check1_set();
	hlk_check2_set();
	hlk_check3_set();

	hlk_check1();
	hlk_check2();
	hlk_check3();

	hlk_check1();
	hlk_check2();
	hlk_check3();

	{

		uchar mac[8];

		TIM_DEBUG("\r\n\r\n\r\n\r\n\r\n\r\n");

		get_mac1(mac);

		TIM_DEBUG("MAC1:");
		tim_print(mac);

		get_mac2(mac);

		TIM_DEBUG("MAC2:");
		tim_print(mac);

		TIM_DEBUG("\r\n\r\n\r\n\r\n\r\n\r\n");
	}
	#endif
}

#endif

int main(int argc, char **argv)
{
	init_info();
	check_test();

	printf("secret write success\n");
}
