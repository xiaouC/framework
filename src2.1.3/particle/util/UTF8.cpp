#include <string.h>
#include <stdlib.h>
#include "UTF8.h"

namespace particle {

    int UTF8Len(char *utf8) {
        int count;
        for(count = 0; *utf8; count++) {
            int x = *utf8;
            utf8 += (x & 0x80) ? ((x & 0x20) ? 3 : 2) : 1;
        }
        return count;
    }
    void ConvertUtf8(char *utf8, unsigned short *buff) {
        while(*utf8)
            GET_UTF8_CHAR(utf8, *buff++);
    }
    
    int UTF8Hash(const char *utf8) {
        int hash = 0;
        while(*utf8) 
        {
            unsigned short c;
            GET_UTF8_CHAR(utf8, c);
            hash = hash * 31 + c;
        }
        return hash;
    }
    
    bool UTF8Comp(char *ptr, char *ptr2) {
        while(*ptr && *ptr2) {
            unsigned short c, c2;
            GET_UTF8_CHAR(ptr, c);
            GET_UTF8_CHAR(ptr2, c2);
            if(c != c2)
                return false;
        }
        if(*ptr || *ptr2)
            return false;
        
        return true;
    }
    int UTF8CharLen(unsigned short *unicode, int len) {
        int count = 0;
        for(; len > 0; len--) {
            unsigned short c = *unicode++;
            count += c == 0 || c > 0x7f ? (c > 0x7ff ? 3 : 2) : 1;
        }
        return count;
    }
    char *Unicode2UTF8(unsigned short *unicode, int len, char *utf8) {
        char *ptr = utf8;
        for(; len > 0; len--) {
            unsigned short c = *unicode++;
            if((c == 0) || (c > 0x7f)) {
                if(c > 0x7ff) {
                    *ptr++ = (c >> 12) | 0xe0;
                    *ptr++ = ((c >> 6) & 0x3f) | 0x80;
                } else
                    *ptr++ = (c >> 6) | 0xc0;
                *ptr++ = (c&0x3f) | 0x80;
            } else
                *ptr++ = (char)c;
        }
        
        *ptr = '\0';
        return utf8;
    }
    
}
