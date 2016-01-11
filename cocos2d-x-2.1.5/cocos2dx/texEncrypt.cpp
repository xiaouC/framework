#include <string.h>
#include <stdio.h>
#include "texEncrypt.h"

int key = 15;
int interval = 60;
int encrypt_length = 4;

char* encrypt( char* data, int length, int& ret_length )
{
    ret_length = length * 2;
    char* ret_data = new char[ret_length];
    for( int i=0; i < length; ++i )
    {
        int temp = data[i] ^ key;
        ret_data[i*2+0] = temp % 16 + 65;
        ret_data[i*2+1] = temp / 16 + 65;
    }

    return ret_data;
}

char* decrypt( char* data, int length, int& ret_length )
{
    if( length % 2 != 0 )
    {
        ret_length = length;
        char* ret_data = new char[ret_length];
        memcpy( ret_data, data, length );

        return ret_data;
    }

    ret_length = length / 2;
    char* ret_data = new char[ret_length];
    for( int i=0; i < ret_length; ++i )
    {
        int temp_1 = data[i*2+0] - 65;
        int temp_2 = data[i*2+1] - 65;

        ret_data[i] = ( temp_2 * 16 + temp_1 ) ^ key;
    }

    return ret_data;
}

char* encrypt_data( char* data, int length, int& ret_length )
{
    // 已经是加密的了，不需要再加密了
    if( length >= 2 && data[0] == 'Y' && data[1] == 'Y' )
    {
        ret_length = length;

        return data;
    }

    // 先计算出返回的长度
    ret_length = 2;
    int index = 0;
    while( index + encrypt_length + interval < length )
    {
        ret_length += encrypt_length * 2 + interval;
        index += encrypt_length + interval;
    }

    if( index < length )
        ret_length += length - index;

    // 
    char* ret_data = new char[ret_length];
    memcpy( ret_data, "YY", 2 );

    index = 0;
    int cur_ret_index = 2;
    while( index + encrypt_length + interval < length )
    {
        int encode_length = 0;
        char* encode_data = encrypt( data + index, encrypt_length, encode_length );
        memcpy( ret_data + cur_ret_index, encode_data, encode_length );
        cur_ret_index += encode_length;
        index += encrypt_length;

        memcpy( ret_data + cur_ret_index, data + index, interval );
        cur_ret_index += interval;
        index += interval;

        delete[] encode_data;
    }

    if( index < length )
        memcpy( ret_data + cur_ret_index, data + index, length - index );

    delete[] data;

    return ret_data;
}

char* decrypt_data( char* data, int length, int& ret_length )
{
    if( data[0] != 'Y' || data[1] != 'Y' )
    {
        ret_length = length;
        return data;
    }

    //
    ret_length = 0;
    int index = 2;
    while( index + encrypt_length * 2 + interval < length )
    {
        ret_length += encrypt_length + interval;
        index += encrypt_length * 2 + interval;
    }

    if( index < length )
        ret_length += length - index;

    char* ret_data = new char[ret_length];
    index = 2;
    int cur_ret_index = 0;
    while( index + encrypt_length * 2 + interval < length )
    {
        int decode_length = 0;
        char* decode_data = decrypt( data + index, encrypt_length * 2, decode_length );
        memcpy( ret_data + cur_ret_index, decode_data, decode_length );
        cur_ret_index += decode_length;
        index += encrypt_length * 2;

        memcpy( ret_data + cur_ret_index, data + index, interval );
        cur_ret_index += interval;
        index += interval;

        delete[] decode_data;
    }

    if( index < length )
        memcpy( ret_data + cur_ret_index, data + index, length - index );

    delete[] data;

    return ret_data;
}

extern "C" { 
    void encrypt_file( const char* in_file_name, const char* out_file_name )
    {
        FILE* fp = fopen( in_file_name, "rb" );
        if( !fp )
        {
            printf( "open %s failed !\n", in_file_name );
            return;
        }

        fseek( fp, 0, SEEK_END );
        int file_length = ftell( fp );
        fseek( fp, 0, SEEK_SET );

        char* file_data = new char[file_length];
        file_length = fread( file_data, sizeof(char), file_length, fp );
        fclose( fp );

        int ret_file_length = 0;
        char* ret_file_data = encrypt_data( file_data, file_length, ret_file_length );
        FILE* fp_save = fopen( out_file_name, "wb" );
        if( !fp_save )
        {
            printf( "open %s failed !\n", out_file_name );
        }
        else
        {
            ret_file_length = fwrite( ret_file_data, sizeof(char), ret_file_length, fp_save );
            fclose( fp_save );
        }

        delete[] ret_file_data;
    }

    void decrypt_file( const char* in_file_name, const char* out_file_name )
    {
        FILE* fp = fopen( in_file_name, "rb" );
        if( !fp )
        {
            printf( "open %s failed !\n", in_file_name );
            return;
        }

        fseek( fp, 0, SEEK_END );
        int file_length = ftell( fp );
        fseek( fp, 0, SEEK_SET );

        char* file_data = new char[file_length];
        file_length = fread( file_data, sizeof(char), file_length, fp );
        fclose( fp );

        int ret_file_length = 0;
        char* ret_file_data = decrypt_data( file_data, file_length, ret_file_length );
        FILE* fp_save = fopen( out_file_name, "wb" );
        if( !fp_save )
        {
            printf( "open %s failed !\n", out_file_name );
        }
        else
        {
            ret_file_length = fwrite( ret_file_data, sizeof(char), ret_file_length, fp_save );
            fclose( fp_save );
        }

        delete[] ret_file_data;
    }
}
