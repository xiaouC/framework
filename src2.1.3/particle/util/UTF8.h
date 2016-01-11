#ifndef OurpalmSDK_UTF8_H
#define OurpalmSDK_UTF8_H

namespace particle {

#ifdef __cplusplus
extern "C" {
#endif

#define GET_UTF8_CHAR(ptr, c)                         \
{                                                     \
    int x = *ptr++;                                   \
    if(x & 0x80) {                                    \
        int y = *ptr++;                               \
        if(x & 0x20) {                                \
            int z = *ptr++;                           \
            c = ((x&0xf)<<12)+((y&0x3f)<<6)+(z&0x3f); \
        } else                                        \
            c = ((x&0x1f)<<6)+(y&0x3f);               \
    } else                                            \
        c = x;                                        \
}
int		UTF8Len(char *utf8);
void	ConvertUtf8(char *utf8, unsigned short *buff);
int		UTF8Hash(const char *utf8);
bool	UTF8Comp(char *ptr, char *ptr2);
int		UTF8CharLen(unsigned short *unicode, int len);
char*	Unicode2UTF8(unsigned short *unicode, int len, char *utf8);

#ifdef __cplusplus
}
#endif
    
}
#endif