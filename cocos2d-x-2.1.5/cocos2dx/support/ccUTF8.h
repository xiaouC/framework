//
//  ccUTF8.h
//  cocos2dx
//
//  Created by James Chen on 2/27/13.
//

#ifndef __cocos2dx__ccUTF8__
#define __cocos2dx__ccUTF8__

#include "platform/CCPlatformMacros.h"
#include <vector>

/* Code from GLIB gutf8.c starts here. */

#define UTF8_COMPUTE(Char, Mask, Len)        \
	if ((unsigned char)Char < 128)				\
		{						\
		Len = 1;					\
		Mask = 0x7f;				\
		}						\
	  else if (((unsigned char)Char & 0xe0) == 0xc0)		\
		{						\
		Len = 2;					\
		Mask = 0x1f;				\
		}						\
	  else if (((unsigned char)Char & 0xf0) == 0xe0)		\
		{						\
		Len = 3;					\
		Mask = 0x0f;				\
		}						\
	  else if (((unsigned char)Char & 0xf8) == 0xf0)		\
		{						\
		Len = 4;					\
		Mask = 0x07;				\
		}						\
	  else if (((unsigned char)Char & 0xfc) == 0xf8)		\
		{						\
		Len = 5;					\
		Mask = 0x03;				\
		}						\
	  else if (((unsigned char)Char & 0xfe) == 0xfc)		\
		{						\
		Len = 6;					\
		Mask = 0x01;				\
		}						\
	  else						\
	  Len = -1;

#define UTF8_LENGTH(Char)            \
	((Char) < 0x80 ? 1 :                \
	((Char) < 0x800 ? 2 :            \
	((Char) < 0x10000 ? 3 :            \
	((Char) < 0x200000 ? 4 :            \
	((Char) < 0x4000000 ? 5 : 6)))))


#define UTF8_GET(Result, Chars, Count, Mask, Len)    \
	(Result) = (Chars)[0] & (Mask);            \
	for ((Count) = 1; (Count) < (Len); ++(Count))        \
{                            \
	if (((Chars)[(Count)] & 0xc0) != 0x80)        \
{                        \
	(Result) = -1;                \
	break;                    \
}                        \
	(Result) <<= 6;                    \
	(Result) |= ((Chars)[(Count)] & 0x3f);        \
}

#define UNICODE_VALID(Char)            \
	((Char) < 0x110000 &&                \
	(((Char) & 0xFFFFF800) != 0xD800) &&        \
	((Char) < 0xFDD0 || (Char) > 0xFDEF) &&    \
	((Char) & 0xFFFE) != 0xFFFE)


NS_CC_BEGIN

CC_DLL int cc_wcslen(const unsigned short* str);

CC_DLL void cc_utf8_trim_ws(std::vector<unsigned short>* str);

/*
 * @ch is the unicode character whitespace?
 *
 * Reference: http://en.wikipedia.org/wiki/Whitespace_character#Unicode
 *
 * Return value: weather the character is a whitespace character.
 * */
CC_DLL bool isspace_unicode(unsigned short ch);

/*
 * cc_utf8_strlen:
 * @p: pointer to the start of a UTF-8 encoded string.
 * @max: the maximum number of bytes to examine. If @max
 *       is less than 0, then the string is assumed to be
 *       null-terminated. If @max is 0, @p will not be examined and
 *       may be %NULL.
 *
 * Returns the length of the string in characters.
 *
 * Return value: the length of the string in characters
 **/
CC_DLL long
cc_utf8_strlen (const char * p, int max);

/*
 * @str:    the string to search through.
 * @c:        the character to not look for.
 *
 * Return value: the index of the last character that is not c.
 * */
CC_DLL unsigned int cc_utf8_find_last_not_char(std::vector<unsigned short> str, unsigned short c);

CC_DLL std::vector<unsigned short> cc_utf16_vec_from_utf16_str(const unsigned short* str);

/*
 * cc_utf8_to_utf16:
 * @str_old: pointer to the start of a C string.
 *
 * Creates a utf8 string from a cstring.
 *
 * Return value: the newly created utf8 string.
 * */
CC_DLL unsigned short* cc_utf8_to_utf16(const char* str_old, int length = -1, int* rUtf16Size = NULL);

/**
 * cc_utf16_to_utf8:
 * @str: a UTF-16 encoded string
 * @len: the maximum length of @str to use. If @len < 0, then
 *       the string is terminated with a 0 character.
 * @items_read: location to store number of words read, or %NULL.
 *              If %NULL, then %G_CONVERT_ERROR_PARTIAL_INPUT will be
 *              returned in case @str contains a trailing partial
 *              character. If an error occurs then the index of the
 *              invalid input is stored here.
 * @items_written: location to store number of bytes written, or %NULL.
 *                 The value stored here does not include the trailing
 *                 0 byte.
 * @error: location to store the error occuring, or %NULL to ignore
 *         errors. Any of the errors in #GConvertError other than
 *         %G_CONVERT_ERROR_NO_CONVERSION may occur.
 *
 * Convert a string from UTF-16 to UTF-8. The result will be
 * terminated with a 0 byte.
 *
 * Return value: a pointer to a newly allocated UTF-8 string.
 *               This value must be freed with free(). If an
 *               error occurs, %NULL will be returned and
 *               @error set.
 **/
CC_DLL char *
cc_utf16_to_utf8 (const unsigned short  *str,
                  long             len,
                  long            *items_read,
                  long            *items_written);

CC_DLL unsigned int
cc_utf8_get_char (const char * p);

CC_DLL char* cc_utf8_next_char_help( char* p );

NS_CC_END

#endif /* defined(__cocos2dx__ccUTF8__) */
