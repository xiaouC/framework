#pragma once

char* encrypt( char* data, int length, int& ret_length );
char* decrypt( char* data, int length, int& ret_length );
char* encrypt_data( char* data, int length, int& ret_length );
char* decrypt_data( char* data, int length, int& ret_length );

extern "C" { 
    void encrypt_file( const char* in_file_name, const char* out_file_name );
    void decrypt_file( const char* in_file_name, const char* out_file_name );
}
