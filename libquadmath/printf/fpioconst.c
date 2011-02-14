/* Table of MP integer constants 10^(2^i), used for floating point <-> decimal.
   Copyright (C) 1995, 1996, 1997, 1998, 1999, 2002, 2003
   Free Software Foundation, Inc.
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
   License along with the GNU C Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.  */

#include "gmp-impl.h"		/* This defines BITS_PER_MP_LIMB.  */
#include "fpioconst.h"

/* First page	: 32-bit limbs
   Second page	: 64-bit limbs
   Last page	: table of pointers
 */

#if BITS_PER_MP_LIMB == 32

/* Table with constants of 10^(2^i), i=0..12 for 32-bit limbs.	*/

const mp_limb_t __tens[] =
{
#define TENS_P0_IDX	0
#define TENS_P0_SIZE	3
  [TENS_P0_IDX] = 0x00000000, 0x00000000, 0x0000000a,

#define TENS_P1_IDX	(TENS_P0_IDX + TENS_P0_SIZE)
#define TENS_P1_SIZE	3
  [TENS_P1_IDX] = 0x00000000, 0x00000000, 0x00000064,

#define TENS_P2_IDX	(TENS_P1_IDX + TENS_P1_SIZE)
#define TENS_P2_SIZE	3
  [TENS_P2_IDX] = 0x00000000, 0x00000000, 0x00002710,

#define TENS_P3_IDX	(TENS_P2_IDX + TENS_P2_SIZE)
#define TENS_P3_SIZE	3
  [TENS_P3_IDX] = 0x00000000, 0x00000000, 0x05f5e100,

#define TENS_P4_IDX	(TENS_P3_IDX + TENS_P3_SIZE)
#define TENS_P4_SIZE	4
  [TENS_P4_IDX] = 0x00000000, 0x00000000, 0x6fc10000, 0x002386f2,

#define TENS_P5_IDX	(TENS_P4_IDX + TENS_P4_SIZE)
#define TENS_P5_SIZE	6
  [TENS_P5_IDX] = 0x00000000, 0x00000000, 0x00000000, 0x85acef81, 0x2d6d415b,
  0x000004ee,

#define TENS_P6_IDX	(TENS_P5_IDX + TENS_P5_SIZE)
#define TENS_P6_SIZE	9
  [TENS_P6_IDX] = 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xbf6a1f01,
  0x6e38ed64, 0xdaa797ed, 0xe93ff9f4, 0x00184f03,

#define TENS_P7_IDX	(TENS_P6_IDX + TENS_P6_SIZE)
#define TENS_P7_SIZE	16
  [TENS_P7_IDX] = 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x2e953e01, 0x03df9909, 0x0f1538fd, 0x2374e42f, 0xd3cff5ec,
  0xc404dc08, 0xbccdb0da, 0xa6337f19, 0xe91f2603, 0x0000024e,

#define TENS_P8_IDX	(TENS_P7_IDX + TENS_P7_SIZE)
#define TENS_P8_SIZE	29
  [TENS_P8_IDX] = 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x982e7c01,
  0xbed3875b, 0xd8d99f72, 0x12152f87, 0x6bde50c6, 0xcf4a6e70, 0xd595d80f,
  0x26b2716e, 0xadc666b0, 0x1d153624, 0x3c42d35a, 0x63ff540e, 0xcc5573c0,
  0x65f9ef17, 0x55bc28f2, 0x80dcc7f7, 0xf46eeddc, 0x5fdcefce, 0x000553f7,

#ifndef __NO_LONG_DOUBLE_MATH
# define TENS_P9_IDX	(TENS_P8_IDX + TENS_P8_SIZE)
# define TENS_P9_SIZE	56
  [TENS_P9_IDX] = 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0xfc6cf801, 0x77f27267, 0x8f9546dc, 0x5d96976f, 0xb83a8a97,
  0xc31e1ad9, 0x46c40513, 0x94e65747, 0xc88976c1, 0x4475b579, 0x28f8733b,
  0xaa1da1bf, 0x703ed321, 0x1e25cfea, 0xb21a2f22, 0xbc51fb2e, 0x96e14f5d,
  0xbfa3edac, 0x329c57ae, 0xe7fc7153, 0xc3fc0695, 0x85a91924, 0xf95f635e,
  0xb2908ee0, 0x93abade4, 0x1366732a, 0x9449775c, 0x69be5b0e, 0x7343afac,
  0xb099bc81, 0x45a71d46, 0xa2699748, 0x8cb07303, 0x8a0b1f13, 0x8cab8a97,
  0xc1d238d9, 0x633415d4, 0x0000001c,

# define TENS_P10_IDX	(TENS_P9_IDX + TENS_P9_SIZE)
# define TENS_P10_SIZE	109
  [TENS_P10_IDX] = 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x2919f001,
  0xf55b2b72, 0x6e7c215b, 0x1ec29f86, 0x991c4e87, 0x15c51a88, 0x140ac535,
  0x4c7d1e1a, 0xcc2cd819, 0x0ed1440e, 0x896634ee, 0x7de16cfb, 0x1e43f61f,
  0x9fce837d, 0x231d2b9c, 0x233e55c7, 0x65dc60d7, 0xf451218b, 0x1c5cd134,
  0xc9635986, 0x922bbb9f, 0xa7e89431, 0x9f9f2a07, 0x62be695a, 0x8e1042c4,
  0x045b7a74, 0x1abe1de3, 0x8ad822a5, 0xba34c411, 0xd814b505, 0xbf3fdeb3,
  0x8fc51a16, 0xb1b896bc, 0xf56deeec, 0x31fb6bfd, 0xb6f4654b, 0x101a3616,
  0x6b7595fb, 0xdc1a47fe, 0x80d98089, 0x80bda5a5, 0x9a202882, 0x31eb0f66,
  0xfc8f1f90, 0x976a3310, 0xe26a7b7e, 0xdf68368a, 0x3ce3a0b8, 0x8e4262ce,
  0x75a351a2, 0x6cb0b6c9, 0x44597583, 0x31b5653f, 0xc356e38a, 0x35faaba6,
  0x0190fba0, 0x9fc4ed52, 0x88bc491b, 0x1640114a, 0x005b8041, 0xf4f3235e,
  0x1e8d4649, 0x36a8de06, 0x73c55349, 0xa7e6bd2a, 0xc1a6970c, 0x47187094,
  0xd2db49ef, 0x926c3f5b, 0xae6209d4, 0x2d433949, 0x34f4a3c6, 0xd4305d94,
  0xd9d61a05, 0x00000325,

# define TENS_P11_IDX	(TENS_P10_IDX + TENS_P10_SIZE)
# define TENS_P11_SIZE	215
  [TENS_P11_IDX] = 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x1333e001, 0xe3096865, 0xb27d4d3f, 0x49e28dcf, 0xec2e4721,
  0xee87e354, 0xb6067584, 0x368b8abb, 0xa5e5a191, 0x2ed56d55, 0xfd827773,
  0xea50d142, 0x51b78db2, 0x98342c9e, 0xc850dabc, 0x866ed6f1, 0x19342c12,
  0x92794987, 0xd2f869c2, 0x66912e4a, 0x71c7fd8f, 0x57a7842d, 0x235552eb,
  0xfb7fedcc, 0xf3861ce0, 0x38209ce1, 0x9713b449, 0x34c10134, 0x8c6c54de,
  0xa7a8289c, 0x2dbb6643, 0xe3cb64f3, 0x8074ff01, 0xe3892ee9, 0x10c17f94,
  0xa8f16f92, 0xa8281ed6, 0x967abbb3, 0x5a151440, 0x9952fbed, 0x13b41e44,
  0xafe609c3, 0xa2bca416, 0xf111821f, 0xfb1264b4, 0x91bac974, 0xd6c7d6ab,
  0x8e48ff35, 0x4419bd43, 0xc4a65665, 0x685e5510, 0x33554c36, 0xab498697,
  0x0dbd21fe, 0x3cfe491d, 0x982da466, 0xcbea4ca7, 0x9e110c7b, 0x79c56b8a,
  0x5fc5a047, 0x84d80e2e, 0x1aa9f444, 0x730f203c, 0x6a57b1ab, 0xd752f7a6,
  0x87a7dc62, 0x944545ff, 0x40660460, 0x77c1a42f, 0xc9ac375d, 0xe866d7ef,
  0x744695f0, 0x81428c85, 0xa1fc6b96, 0xd7917c7b, 0x7bf03c19, 0x5b33eb41,
  0x5715f791, 0x8f6cae5f, 0xdb0708fd, 0xb125ac8e, 0x785ce6b7, 0x56c6815b,
  0x6f46eadb, 0x4eeebeee, 0x195355d8, 0xa244de3c, 0x9d7389c0, 0x53761abd,
  0xcf99d019, 0xde9ec24b, 0x0d76ce39, 0x70beb181, 0x2e55ecee, 0xd5f86079,
  0xf56d9d4b, 0xfb8886fb, 0x13ef5a83, 0x408f43c5, 0x3f3389a4, 0xfad37943,
  0x58ccf45c, 0xf82df846, 0x415c7f3e, 0x2915e818, 0x8b3d5cf4, 0x6a445f27,
  0xf8dbb57a, 0xca8f0070, 0x8ad803ec, 0xb2e87c34, 0x038f9245, 0xbedd8a6c,
  0xc7c9dee0, 0x0eac7d56, 0x2ad3fa14, 0xe0de0840, 0xf775677c, 0xf1bd0ad5,
  0x92be221e, 0x87fa1fb9, 0xce9d04a4, 0xd2c36fa9, 0x3f6f7024, 0xb028af62,
  0x907855ee, 0xd83e49d6, 0x4efac5dc, 0xe7151aab, 0x77cd8c6b, 0x0a753b7d,
  0x0af908b4, 0x8c983623, 0xe50f3027, 0x94222771, 0x1d08e2d6, 0xf7e928e6,
  0xf2ee5ca6, 0x1b61b93c, 0x11eb962b, 0x9648b21c, 0xce2bcba1, 0x34f77154,
  0x7bbebe30, 0xe526a319, 0x8ce329ac, 0xde4a74d2, 0xb5dc53d5, 0x0009e8b3,

# define TENS_P12_IDX	(TENS_P11_IDX + TENS_P11_SIZE)
# define TENS_P12_SIZE	428
  [TENS_P12_IDX] = 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x2a67c001,
  0xd4724e8d, 0x8efe7ae7, 0xf89a1e90, 0xef084117, 0x54e05154, 0x13b1bb51,
  0x506be829, 0xfb29b172, 0xe599574e, 0xf0da6146, 0x806c0ed3, 0xb86ae5be,
  0x45155e93, 0xc0591cc2, 0x7e1e7c34, 0x7c4823da, 0x1d1f4cce, 0x9b8ba1e8,
  0xd6bfdf75, 0xe341be10, 0xc2dfae78, 0x016b67b2, 0x0f237f1a, 0x3dbeabcd,
  0xaf6a2574, 0xcab3e6d7, 0x142e0e80, 0x61959127, 0x2c234811, 0x87009701,
  0xcb4bf982, 0xf8169c84, 0x88052f8c, 0x68dde6d4, 0xbc131761, 0xff0b0905,
  0x54ab9c41, 0x7613b224, 0x1a1c304e, 0x3bfe167b, 0x441c2d47, 0x4f6cea9c,
  0x78f06181, 0xeb659fb8, 0x30c7ae41, 0x947e0d0e, 0xa1ebcad7, 0xd97d9556,
  0x2130504d, 0x1a8309cb, 0xf2acd507, 0x3f8ec72a, 0xfd82373a, 0x95a842bc,
  0x280f4d32, 0xf3618ac0, 0x811a4f04, 0x6dc3a5b4, 0xd3967a1b, 0x15b8c898,
  0xdcfe388f, 0x454eb2a0, 0x8738b909, 0x10c4e996, 0x2bd9cc11, 0x3297cd0c,
  0x655fec30, 0xae0725b1, 0xf4090ee8, 0x037d19ee, 0x398c6fed, 0x3b9af26b,
  0xc994a450, 0xb5341743, 0x75a697b2, 0xac50b9c1, 0x3ccb5b92, 0xffe06205,
  0xa8329761, 0xdfea5242, 0xeb83cadb, 0xe79dadf7, 0x3c20ee69, 0x1e0a6817,
  0x7021b97a, 0x743074fa, 0x176ca776, 0x77fb8af6, 0xeca19beb, 0x92baf1de,
  0xaf63b712, 0xde35c88b, 0xa4eb8f8c, 0xe137d5e9, 0x40b464a0, 0x87d1cde8,
  0x42923bbd, 0xcd8f62ff, 0x2e2690f3, 0x095edc16, 0x59c89f1b, 0x1fa8fd5d,
  0x5138753d, 0x390a2b29, 0x80152f18, 0x2dd8d925, 0xf984d83e, 0x7a872e74,
  0xc19e1faf, 0xed4d542d, 0xecf9b5d0, 0x9462ea75, 0xc53c0adf, 0x0caea134,
  0x37a2d439, 0xc8fa2e8a, 0x2181327e, 0x6e7bb827, 0x2d240820, 0x50be10e0,
  0x5893d4b8, 0xab312bb9, 0x1f2b2322, 0x440b3f25, 0xbf627ede, 0x72dac789,
  0xb608b895, 0x78787e2a, 0x86deb3f0, 0x6fee7aab, 0xbb9373f4, 0x27ecf57b,
  0xf7d8b57e, 0xfca26a9f, 0x3d04e8d2, 0xc9df13cb, 0x3172826a, 0xcd9e8d7c,
  0xa8fcd8e0, 0xb2c39497, 0x307641d9, 0x1cc939c1, 0x2608c4cf, 0xb6d1c7bf,
  0x3d326a7e, 0xeeaf19e6, 0x8e13e25f, 0xee63302b, 0x2dfe6d97, 0x25971d58,
  0xe41d3cc4, 0x0a80627c, 0xab8db59a, 0x9eea37c8, 0xe90afb77, 0x90ca19cf,
  0x9ee3352c, 0x3613c850, 0xfe78d682, 0x788f6e50, 0x5b060904, 0xb71bd1a4,
  0x3fecb534, 0xb32c450c, 0x20c33857, 0xa6e9cfda, 0x0239f4ce, 0x48497187,
  0xa19adb95, 0xb492ed8a, 0x95aca6a8, 0x4dcd6cd9, 0xcf1b2350, 0xfbe8b12a,
  0x1a67778c, 0x38eb3acc, 0xc32da383, 0xfb126ab1, 0xa03f40a8, 0xed5bf546,
  0xe9ce4724, 0x4c4a74fd, 0x73a130d8, 0xd9960e2d, 0xa2ebd6c1, 0x94ab6feb,
  0x6f233b7c, 0x49126080, 0x8e7b9a73, 0x4b8c9091, 0xd298f999, 0x35e836b5,
  0xa96ddeff, 0x96119b31, 0x6b0dd9bc, 0xc6cc3f8d, 0x282566fb, 0x72b882e7,
  0xd6769f3b, 0xa674343d, 0x00fc509b, 0xdcbf7789, 0xd6266a3f, 0xae9641fd,
  0x4e89541b, 0x11953407, 0x53400d03, 0x8e0dd75a, 0xe5b53345, 0x108f19ad,
  0x108b89bc, 0x41a4c954, 0xe03b2b63, 0x437b3d7f, 0x97aced8e, 0xcbd66670,
  0x2c5508c2, 0x650ebc69, 0x5c4f2ef0, 0x904ff6bf, 0x9985a2df, 0x9faddd9e,
  0x5ed8d239, 0x25585832, 0xe3e51cb9, 0x0ff4f1d4, 0x56c02d9a, 0x8c4ef804,
  0xc1a08a13, 0x13fd01c8, 0xe6d27671, 0xa7c234f4, 0x9d0176cc, 0xd0d73df2,
  0x4d8bfa89, 0x544f10cd, 0x2b17e0b2, 0xb70a5c7d, 0xfd86fe49, 0xdf373f41,
  0x214495bb, 0x84e857fd, 0x00d313d5, 0x0496fcbe, 0xa4ba4744, 0xe8cac982,
  0xaec29e6e, 0x87ec7038, 0x7000a519, 0xaeee333b, 0xff66e42c, 0x8afd6b25,
  0x03b4f63b, 0xbd7991dc, 0x5ab8d9c7, 0x2ed4684e, 0x48741a6c, 0xaf06940d,
  0x2fdc6349, 0xb03d7ecd, 0xe974996f, 0xac7867f9, 0x52ec8721, 0xbcdd9d4a,
  0x8edd2d00, 0x3557de06, 0x41c759f8, 0x3956d4b9, 0xa75409f2, 0x123cd8a1,
  0xb6100fab, 0x3e7b21e2, 0x2e8d623b, 0x92959da2, 0xbca35f77, 0x200c03a5,
  0x35fcb457, 0x1bb6c6e4, 0xf74eb928, 0x3d5d0b54, 0x87cc1d21, 0x4964046f,
  0x18ae4240, 0xd868b275, 0x8bd2b496, 0x1c5563f4, 0xc234d8f5, 0xf868e970,
  0xf9151fff, 0xae7be4a2, 0x271133ee, 0xbb0fd922, 0x25254932, 0xa60a9fc0,
  0x104bcd64, 0x30290145, 0x00000062
#endif	/* !__NO_LONG_DOUBLE_MATH */
};

#elif BITS_PER_MP_LIMB == 64

/* Table with constants of 10^(2^i), i=0..12 for 64-bit limbs.	*/

const mp_limb_t __tens[] =
{
#define TENS_P0_IDX	0
#define TENS_P0_SIZE	2
  [TENS_P0_IDX] = 0x0000000000000000ull, 0x000000000000000aull,

#define TENS_P1_IDX	(TENS_P0_IDX + TENS_P0_SIZE)
#define TENS_P1_SIZE	2
  [TENS_P1_IDX] = 0x0000000000000000ull, 0x0000000000000064ull,

#define TENS_P2_IDX	(TENS_P1_IDX + TENS_P1_SIZE)
#define TENS_P2_SIZE	2
  [TENS_P2_IDX] = 0x0000000000000000ull, 0x0000000000002710ull,

#define TENS_P3_IDX	(TENS_P2_IDX + TENS_P2_SIZE)
#define TENS_P3_SIZE	2
  [TENS_P3_IDX] = 0x0000000000000000ull, 0x0000000005f5e100ull,

#define TENS_P4_IDX	(TENS_P3_IDX + TENS_P3_SIZE)
#define TENS_P4_SIZE	2
  [TENS_P4_IDX] = 0x0000000000000000ull, 0x002386f26fc10000ull,

#define TENS_P5_IDX	(TENS_P4_IDX + TENS_P4_SIZE)
#define TENS_P5_SIZE	3
  [TENS_P5_IDX] = 0x0000000000000000ull, 0x85acef8100000000ull,
  0x000004ee2d6d415bull,

#define TENS_P6_IDX	(TENS_P5_IDX + TENS_P5_SIZE)
#define TENS_P6_SIZE	5
  [TENS_P6_IDX] = 0x0000000000000000ull, 0x0000000000000000ull,
  0x6e38ed64bf6a1f01ull, 0xe93ff9f4daa797edull, 0x0000000000184f03ull,

#define TENS_P7_IDX	(TENS_P6_IDX + TENS_P6_SIZE)
#define TENS_P7_SIZE	8
  [TENS_P7_IDX] = 0x0000000000000000ull, 0x0000000000000000ull,
  0x0000000000000000ull, 0x03df99092e953e01ull, 0x2374e42f0f1538fdull,
  0xc404dc08d3cff5ecull, 0xa6337f19bccdb0daull, 0x0000024ee91f2603ull,

#define TENS_P8_IDX	(TENS_P7_IDX + TENS_P7_SIZE)
#define TENS_P8_SIZE	15
  [TENS_P8_IDX] = 0x0000000000000000ull, 0x0000000000000000ull,
  0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull,
  0xbed3875b982e7c01ull, 0x12152f87d8d99f72ull, 0xcf4a6e706bde50c6ull,
  0x26b2716ed595d80full, 0x1d153624adc666b0ull, 0x63ff540e3c42d35aull,
  0x65f9ef17cc5573c0ull, 0x80dcc7f755bc28f2ull, 0x5fdcefcef46eeddcull,
  0x00000000000553f7ull,
#if FLT128_MAX_EXP > 1024
# define TENS_P9_IDX	(TENS_P8_IDX + TENS_P8_SIZE)
# define TENS_P9_SIZE	28
  [TENS_P9_IDX] = 0x0000000000000000ull, 0x0000000000000000ull,
  0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull,
  0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull,
  0x0000000000000000ull, 0x77f27267fc6cf801ull, 0x5d96976f8f9546dcull,
  0xc31e1ad9b83a8a97ull, 0x94e6574746c40513ull, 0x4475b579c88976c1ull,
  0xaa1da1bf28f8733bull, 0x1e25cfea703ed321ull, 0xbc51fb2eb21a2f22ull,
  0xbfa3edac96e14f5dull, 0xe7fc7153329c57aeull, 0x85a91924c3fc0695ull,
  0xb2908ee0f95f635eull, 0x1366732a93abade4ull, 0x69be5b0e9449775cull,
  0xb099bc817343afacull, 0xa269974845a71d46ull, 0x8a0b1f138cb07303ull,
  0xc1d238d98cab8a97ull, 0x0000001c633415d4ull,

# define TENS_P10_IDX	(TENS_P9_IDX + TENS_P9_SIZE)
# define TENS_P10_SIZE	55
  [TENS_P10_IDX] = 0x0000000000000000ull, 0x0000000000000000ull,
  0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull,
  0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull,
  0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull,
  0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull,
  0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull,
  0xf55b2b722919f001ull, 0x1ec29f866e7c215bull, 0x15c51a88991c4e87ull,
  0x4c7d1e1a140ac535ull, 0x0ed1440ecc2cd819ull, 0x7de16cfb896634eeull,
  0x9fce837d1e43f61full, 0x233e55c7231d2b9cull, 0xf451218b65dc60d7ull,
  0xc96359861c5cd134ull, 0xa7e89431922bbb9full, 0x62be695a9f9f2a07ull,
  0x045b7a748e1042c4ull, 0x8ad822a51abe1de3ull, 0xd814b505ba34c411ull,
  0x8fc51a16bf3fdeb3ull, 0xf56deeecb1b896bcull, 0xb6f4654b31fb6bfdull,
  0x6b7595fb101a3616ull, 0x80d98089dc1a47feull, 0x9a20288280bda5a5ull,
  0xfc8f1f9031eb0f66ull, 0xe26a7b7e976a3310ull, 0x3ce3a0b8df68368aull,
  0x75a351a28e4262ceull, 0x445975836cb0b6c9ull, 0xc356e38a31b5653full,
  0x0190fba035faaba6ull, 0x88bc491b9fc4ed52ull, 0x005b80411640114aull,
  0x1e8d4649f4f3235eull, 0x73c5534936a8de06ull, 0xc1a6970ca7e6bd2aull,
  0xd2db49ef47187094ull, 0xae6209d4926c3f5bull, 0x34f4a3c62d433949ull,
  0xd9d61a05d4305d94ull, 0x0000000000000325ull,

# define TENS_P11_IDX	(TENS_P10_IDX + TENS_P10_SIZE)
# define TENS_P11_SIZE	108
  [TENS_P11_IDX] = 0x0000000000000000ull, 0x0000000000000000ull,
  0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull,
  0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull,
  0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull,
  0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull,
  0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull,
  0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull,
  0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull,
  0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull,
  0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull,
  0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull,
  0x0000000000000000ull, 0xe30968651333e001ull, 0x49e28dcfb27d4d3full,
  0xee87e354ec2e4721ull, 0x368b8abbb6067584ull, 0x2ed56d55a5e5a191ull,
  0xea50d142fd827773ull, 0x98342c9e51b78db2ull, 0x866ed6f1c850dabcull,
  0x9279498719342c12ull, 0x66912e4ad2f869c2ull, 0x57a7842d71c7fd8full,
  0xfb7fedcc235552ebull, 0x38209ce1f3861ce0ull, 0x34c101349713b449ull,
  0xa7a8289c8c6c54deull, 0xe3cb64f32dbb6643ull, 0xe3892ee98074ff01ull,
  0xa8f16f9210c17f94ull, 0x967abbb3a8281ed6ull, 0x9952fbed5a151440ull,
  0xafe609c313b41e44ull, 0xf111821fa2bca416ull, 0x91bac974fb1264b4ull,
  0x8e48ff35d6c7d6abull, 0xc4a656654419bd43ull, 0x33554c36685e5510ull,
  0x0dbd21feab498697ull, 0x982da4663cfe491dull, 0x9e110c7bcbea4ca7ull,
  0x5fc5a04779c56b8aull, 0x1aa9f44484d80e2eull, 0x6a57b1ab730f203cull,
  0x87a7dc62d752f7a6ull, 0x40660460944545ffull, 0xc9ac375d77c1a42full,
  0x744695f0e866d7efull, 0xa1fc6b9681428c85ull, 0x7bf03c19d7917c7bull,
  0x5715f7915b33eb41ull, 0xdb0708fd8f6cae5full, 0x785ce6b7b125ac8eull,
  0x6f46eadb56c6815bull, 0x195355d84eeebeeeull, 0x9d7389c0a244de3cull,
  0xcf99d01953761abdull, 0x0d76ce39de9ec24bull, 0x2e55ecee70beb181ull,
  0xf56d9d4bd5f86079ull, 0x13ef5a83fb8886fbull, 0x3f3389a4408f43c5ull,
  0x58ccf45cfad37943ull, 0x415c7f3ef82df846ull, 0x8b3d5cf42915e818ull,
  0xf8dbb57a6a445f27ull, 0x8ad803ecca8f0070ull, 0x038f9245b2e87c34ull,
  0xc7c9dee0bedd8a6cull, 0x2ad3fa140eac7d56ull, 0xf775677ce0de0840ull,
  0x92be221ef1bd0ad5ull, 0xce9d04a487fa1fb9ull, 0x3f6f7024d2c36fa9ull,
  0x907855eeb028af62ull, 0x4efac5dcd83e49d6ull, 0x77cd8c6be7151aabull,
  0x0af908b40a753b7dull, 0xe50f30278c983623ull, 0x1d08e2d694222771ull,
  0xf2ee5ca6f7e928e6ull, 0x11eb962b1b61b93cull, 0xce2bcba19648b21cull,
  0x7bbebe3034f77154ull, 0x8ce329ace526a319ull, 0xb5dc53d5de4a74d2ull,
  0x000000000009e8b3ull,

# define TENS_P12_IDX	(TENS_P11_IDX + TENS_P11_SIZE)
# define TENS_P12_SIZE	214
  [TENS_P12_IDX] = 0x0000000000000000ull, 0x0000000000000000ull,
  0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull,
  0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull,
  0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull,
  0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull,
  0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull,
  0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull,
  0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull,
  0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull,
  0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull,
  0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull,
  0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull,
  0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull,
  0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull,
  0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull,
  0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull,
  0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull,
  0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull,
  0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull,
  0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull,
  0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull,
  0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull,
  0xd4724e8d2a67c001ull, 0xf89a1e908efe7ae7ull, 0x54e05154ef084117ull,
  0x506be82913b1bb51ull, 0xe599574efb29b172ull, 0x806c0ed3f0da6146ull,
  0x45155e93b86ae5beull, 0x7e1e7c34c0591cc2ull, 0x1d1f4cce7c4823daull,
  0xd6bfdf759b8ba1e8ull, 0xc2dfae78e341be10ull, 0x0f237f1a016b67b2ull,
  0xaf6a25743dbeabcdull, 0x142e0e80cab3e6d7ull, 0x2c23481161959127ull,
  0xcb4bf98287009701ull, 0x88052f8cf8169c84ull, 0xbc13176168dde6d4ull,
  0x54ab9c41ff0b0905ull, 0x1a1c304e7613b224ull, 0x441c2d473bfe167bull,
  0x78f061814f6cea9cull, 0x30c7ae41eb659fb8ull, 0xa1ebcad7947e0d0eull,
  0x2130504dd97d9556ull, 0xf2acd5071a8309cbull, 0xfd82373a3f8ec72aull,
  0x280f4d3295a842bcull, 0x811a4f04f3618ac0ull, 0xd3967a1b6dc3a5b4ull,
  0xdcfe388f15b8c898ull, 0x8738b909454eb2a0ull, 0x2bd9cc1110c4e996ull,
  0x655fec303297cd0cull, 0xf4090ee8ae0725b1ull, 0x398c6fed037d19eeull,
  0xc994a4503b9af26bull, 0x75a697b2b5341743ull, 0x3ccb5b92ac50b9c1ull,
  0xa8329761ffe06205ull, 0xeb83cadbdfea5242ull, 0x3c20ee69e79dadf7ull,
  0x7021b97a1e0a6817ull, 0x176ca776743074faull, 0xeca19beb77fb8af6ull,
  0xaf63b71292baf1deull, 0xa4eb8f8cde35c88bull, 0x40b464a0e137d5e9ull,
  0x42923bbd87d1cde8ull, 0x2e2690f3cd8f62ffull, 0x59c89f1b095edc16ull,
  0x5138753d1fa8fd5dull, 0x80152f18390a2b29ull, 0xf984d83e2dd8d925ull,
  0xc19e1faf7a872e74ull, 0xecf9b5d0ed4d542dull, 0xc53c0adf9462ea75ull,
  0x37a2d4390caea134ull, 0x2181327ec8fa2e8aull, 0x2d2408206e7bb827ull,
  0x5893d4b850be10e0ull, 0x1f2b2322ab312bb9ull, 0xbf627ede440b3f25ull,
  0xb608b89572dac789ull, 0x86deb3f078787e2aull, 0xbb9373f46fee7aabull,
  0xf7d8b57e27ecf57bull, 0x3d04e8d2fca26a9full, 0x3172826ac9df13cbull,
  0xa8fcd8e0cd9e8d7cull, 0x307641d9b2c39497ull, 0x2608c4cf1cc939c1ull,
  0x3d326a7eb6d1c7bfull, 0x8e13e25feeaf19e6ull, 0x2dfe6d97ee63302bull,
  0xe41d3cc425971d58ull, 0xab8db59a0a80627cull, 0xe90afb779eea37c8ull,
  0x9ee3352c90ca19cfull, 0xfe78d6823613c850ull, 0x5b060904788f6e50ull,
  0x3fecb534b71bd1a4ull, 0x20c33857b32c450cull, 0x0239f4cea6e9cfdaull,
  0xa19adb9548497187ull, 0x95aca6a8b492ed8aull, 0xcf1b23504dcd6cd9ull,
  0x1a67778cfbe8b12aull, 0xc32da38338eb3accull, 0xa03f40a8fb126ab1ull,
  0xe9ce4724ed5bf546ull, 0x73a130d84c4a74fdull, 0xa2ebd6c1d9960e2dull,
  0x6f233b7c94ab6febull, 0x8e7b9a7349126080ull, 0xd298f9994b8c9091ull,
  0xa96ddeff35e836b5ull, 0x6b0dd9bc96119b31ull, 0x282566fbc6cc3f8dull,
  0xd6769f3b72b882e7ull, 0x00fc509ba674343dull, 0xd6266a3fdcbf7789ull,
  0x4e89541bae9641fdull, 0x53400d0311953407ull, 0xe5b533458e0dd75aull,
  0x108b89bc108f19adull, 0xe03b2b6341a4c954ull, 0x97aced8e437b3d7full,
  0x2c5508c2cbd66670ull, 0x5c4f2ef0650ebc69ull, 0x9985a2df904ff6bfull,
  0x5ed8d2399faddd9eull, 0xe3e51cb925585832ull, 0x56c02d9a0ff4f1d4ull,
  0xc1a08a138c4ef804ull, 0xe6d2767113fd01c8ull, 0x9d0176cca7c234f4ull,
  0x4d8bfa89d0d73df2ull, 0x2b17e0b2544f10cdull, 0xfd86fe49b70a5c7dull,
  0x214495bbdf373f41ull, 0x00d313d584e857fdull, 0xa4ba47440496fcbeull,
  0xaec29e6ee8cac982ull, 0x7000a51987ec7038ull, 0xff66e42caeee333bull,
  0x03b4f63b8afd6b25ull, 0x5ab8d9c7bd7991dcull, 0x48741a6c2ed4684eull,
  0x2fdc6349af06940dull, 0xe974996fb03d7ecdull, 0x52ec8721ac7867f9ull,
  0x8edd2d00bcdd9d4aull, 0x41c759f83557de06ull, 0xa75409f23956d4b9ull,
  0xb6100fab123cd8a1ull, 0x2e8d623b3e7b21e2ull, 0xbca35f7792959da2ull,
  0x35fcb457200c03a5ull, 0xf74eb9281bb6c6e4ull, 0x87cc1d213d5d0b54ull,
  0x18ae42404964046full, 0x8bd2b496d868b275ull, 0xc234d8f51c5563f4ull,
  0xf9151ffff868e970ull, 0x271133eeae7be4a2ull, 0x25254932bb0fd922ull,
  0x104bcd64a60a9fc0ull, 0x0000006230290145ull
#endif
};

#else
# error "mp_limb_t size " BITS_PER_MP_LIMB "not accounted for"
#endif

/* Each of array variable above defines one mpn integer which is a power of 10.
   This table points to those variables, indexed by the exponent.  */

const struct mp_power _fpioconst_pow10[FLT128_MAX_10_EXP_LOG + 1] =
{
  { TENS_P0_IDX, TENS_P0_SIZE,		4,	     },
  { TENS_P1_IDX, TENS_P1_SIZE,		7,	   4 },
  { TENS_P2_IDX, TENS_P2_SIZE,		14,	  10 },
  { TENS_P3_IDX, TENS_P3_SIZE,		27,	  24 },
  { TENS_P4_IDX, TENS_P4_SIZE,		54,	  50 },
  { TENS_P5_IDX, TENS_P5_SIZE,		107,	 103 },
  { TENS_P6_IDX, TENS_P6_SIZE,		213,	 210 },
  { TENS_P7_IDX, TENS_P7_SIZE,		426,	 422 },
  { TENS_P8_IDX, TENS_P8_SIZE,  	851,	 848 },
#if FLT128_MAX_EXP > 1024
  { TENS_P9_IDX, TENS_P9_SIZE,	 	1701,	1698 },
  { TENS_P10_IDX, TENS_P10_SIZE,	3402,	3399 },
  { TENS_P11_IDX, TENS_P11_SIZE,	6804,	6800 },
  { TENS_P12_IDX, TENS_P12_SIZE, 	13607, 13604 }
#endif
};

#if LAST_POW10 > _LAST_POW10
# error "Need to expand 10^(2^i) table for i up to" LAST_POW10
#endif