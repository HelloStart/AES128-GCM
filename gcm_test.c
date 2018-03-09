
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <string.h>
#include "aes128e.h"
#include "aes128gcm.h"

int main()
{

/* Test vector from https://csrc.nist.gov/CSRC/media/Projects/Cryptographic-Algorithm-Validation-Program/documents/mac/gcmtestvectors.zip
[Keylen = 128]
[IVlen = 96]
[PTlen = 256]
[AADlen = 384]
[Taglen = 120]

Count = 0
Key = 98fff67e64e46be5ee2e05cc9af6d012
IV = 2dfb429a48697c34006da886
PT = 29b91b4a68a99f97c41c7508f17a5c7a7afc9e1aca83e129b085bd637ff67c01
AAD = a0ca5861c0226c5b5a6514c82b77815a9e0eb359d0d46d0333c3f2bae14da0c40330c00216b4aa64b7c1edb871c328f6
CT = c22feeb3e27dc3299345030139ee816719a8a89939037895d74965fa0240af5b
Tag = f196ec546c4c0af08be088bab97191

*/
	const unsigned char key[16] = {0x98,0xff,0xf6,0x7e,0x64,0xe4,0x6b,0xe5,0xee,0x2e,0x05,0xcc,0x9a,0xf6,0xd0,0x12};
	const unsigned char IV[12] ={0x2d,0xfb,0x42,0x9a,0x48,0x69,0x7c,0x34,0x00,0x6d,0xa8,0x86};
	const unsigned char plaintext[32]={0x29,0xb9,0x1b,0x4a,0x68,0xa9,0x9f,0x97,0xc4,0x1c,0x75,0x08,0xf1,0x7a,0x5c,0x7a,
				      				   0x7a,0xfc,0x9e,0x1a,0xca,0x83,0xe1,0x29,0xb0,0x85,0xbd,0x63,0x7f,0xf6,0x7c,0x01};
	
	const unsigned char aad[48]={0xa0,0xca,0x58,0x61,0xc0,0x22,0x6c,0x5b,0x5a,0x65,0x14,0xc8,0x2b,0x77,0x81,0x5a,
						  		 0x9e,0x0e,0xb3,0x59,0xd0,0xd4,0x6d,0x03,0x33,0xc3,0xf2,0xba,0xe1,0x4d,0xa0,0xc4,
						         0x03,0x30,0xc0,0x02,0x16,0xb4,0xaa,0x64,0xb7,0xc1,0xed,0xb8,0x71,0xc3,0x28,0xf6};
	
	const unsigned char ciphertext_expected[32]={0xc2,0x2f,0xee,0xb3,0xe2,0x7d,0xc3,0x29,0x93,0x45,0x03,0x01,0x39,0xee,0x81,0x67,
				  								 0x19,0xa8,0xa8,0x99,0x39,0x03,0x78,0x95,0xd7,0x49,0x65,0xfa,0x02,0x40,0xaf,0x5b};
	const unsigned char tag_expected[15] = {0xf1,0x96,0xec,0x54,0x6c,0x4c,0x0a,0xf0,0x8b,0xe0,0x88,0xba,0xb9,0x71,0x91};

	unsigned char ciphertext[32];
	unsigned char tag[16];
	 

    int i = 0;
	printf("---------------INPUT----------\r\n");
	printf("KEY =  ");
	for (i = 0;i < 16;i++)
		printf("%02x",key[i]);
	printf("\r\n");

	printf("IV = ");
	for (i = 0;i < 12;i++)
		printf("%02x",IV[i]);
	printf("\r\n");

	printf("Plaintext = ");
	for (i = 0;i < 32;i++)
		printf("%02x",plaintext[i]);
	printf("\r\n");

	printf("AAD = ");
	for (i = 0;i < 48;i++)
		printf("%02x",aad[i]);
	printf("\r\n");

    
	aes128gcm(ciphertext,tag, key, IV, plaintext, 2, aad, 3);

	printf("------------OUPUT------------\r\n");
	printf("Ciphertext = ");
	for (i = 0;i < 32;i++)
		printf("%02x",ciphertext[i]);
	printf("\r\n");
	
    printf("TAG = ");
	for (i = 0;i < 15;i++)
		printf("%02x",tag[i]);
	printf("\r\n");
	
	return 0;
}

