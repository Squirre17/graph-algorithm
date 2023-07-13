#ifndef __COMMON_H__
#define __COMMON_H__

#include <iostream>
#include <vector>
#include <cstdint> 
#include <limits>   
#include <tuple>   
#include <queue>   
#include <memory>   
#include <algorithm>   

#define fn auto
#define self (*this)

using std::vector;
using std::queue;
using std::pair;
using std::tuple;
using std::sort;
using std::unique_ptr;
using std::make_unique;
using std::cout;
using std::endl;

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t   i8;
typedef int16_t  i16;
typedef int32_t  i32;
typedef int64_t  i64;



#define cBLK "\x1b[0;30m"  /* black  */    
#define cRED "\x1b[0;31m"  /* red    */   
#define cGRE "\x1b[0;32m"  /* green  */   
#define cORA "\x1b[0;33m"  /* orange */   
#define cBLU "\x1b[0;34m"  /* blue   */   
#define cPUR "\x1b[0;35m"  /* purple */   
#define cCYA "\x1b[0;36m"  /* cyan   */   
#define cWHI "\x1b[0;37m"  /* white  */   

#define cBLKp "\x1b[1;90m"  /* black  plus */ 
#define cREDp "\x1b[1;91m"  /* red    plus */ 
#define cGREp "\x1b[1;92m"  /* green  plus */ 
#define cORAp "\x1b[1;93m"  /* orange plus */ 
#define cBLUp "\x1b[1;94m"  /* blue   plus */ 
#define cPURp "\x1b[1;95m"  /* purple plus */ 
#define cCYAp "\x1b[1;96m"  /* cyan   plus */ 
#define cWHIp "\x1b[1;97m"  /* white  plus */ 
#define cRST  "\x1b[0m"      /* reset       */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* wrap of printf */

#define say(x...)     printf(x) 
#define sayl(x...)    { printf(x); puts(""); }

/* Show a prefixed warning. */

#define warn(x...) do {                        \
    say(cORA "[!] " cWHIp "WARNING: " cRST x); \
    say(cRST "\n");                            \
  } while (0)

/* Show a prefixed "doing something" message. */

#define act(x...) do {                        \
    say(cBLU "[*] " cRST x);                  \
    say(cRST "\n");                           \
  } while (0)

/* Show a prefixed "success" message. */

#define ok(x...) do {                         \
    say(cGRE "[+] " cRST x);                  \
    say(cRST "\n");                           \
  } while (0)

/* Show a prefixed "debug" message. */

#define dbg(x...) do {                        \
    say(cPUR "[x] " cRST);                    \
    say("%s(), %s:%u : ",                     \
        __FUNCTION__, __FILE__, __LINE__ );   \
    sayl(x);                                  \
  } while (0)

/* Show a prefixed fatal error message . */

#define err(x...) do {                        \
    say(cRED "\n[-] " cRST);                  \
    say("%s(), %s:%u : ",                     \
        __FUNCTION__, __FILE__, __LINE__ );   \
    sayl(x);                                  \
  } while (0)
/* Die with a verbose non-OS fatal error message. */

#define fatal(x...) do { \
    say(cRED "\n[-] PROGRAM abort : " cWHI x);                \
    say(cRED "\n         Location : " cRST "%s(), %s:%u\n\n", \
         __FUNCTION__, __FILE__, __LINE__);                   \
    exit(1); \
  } while (0)

/* Die by calling abort() to provide a core dump. */

#define abort(x...) do { \
    say(cREDp "\n[-] PROGRAM abort : " cWHI x);                \
    say(cREDp "\n    Stop location : " cRST "%s(), %s:%u\n\n", \
         __FUNCTION__, __FILE__, __LINE__);                    \
    abort(); \
  } while (0)

/* Die with a verbose OS fatal error message. */

#define panic(x...) do {                                            \
    fflush(stdout);                                                 \
    say(cREDp "\n[-]  SYSTEM ERROR : " cWHI x);                     \
    say(cREDp "\n    Stop location : " cRST "%s(), %s:%u\n",        \
         __FUNCTION__, __FILE__, __LINE__);                         \
    say(cREDp "       OS message : " cRST "%s\n", strerror(errno)); \
    exit(1);                                                        \
  } while (0)

#endif