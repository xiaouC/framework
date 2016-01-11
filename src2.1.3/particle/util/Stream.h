#ifndef OurpamlSDK_INPUTSTREAM_H
#define OurpamlSDK_INPUTSTREAM_H
#if (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
#include <string.h>
#else
#include <string>
#endif
#include <pthread.h>
namespace particle {
    
    enum Endian
    {
        Big_Endian,
        Little_Endian
    };
    class InputStream;
    class OutputStream;
    class CONSTANT_Utf8
    {
    private:
        unsigned int	length;
        char*			data;
    public:
        CONSTANT_Utf8();
        virtual ~CONSTANT_Utf8();
    public:
        CONSTANT_Utf8(const CONSTANT_Utf8& other);
        CONSTANT_Utf8(const char* other);
        const CONSTANT_Utf8& operator=(const CONSTANT_Utf8& other);
        const CONSTANT_Utf8& operator=(const char* other);
    public:
        void                Read(InputStream& is);
        void                Read4HeadUTF(InputStream& is);
        void                Write(OutputStream& os);
        inline const char*  Data() const {return data;}
        inline int          Length(){return length;}
        void                Set(const char* value);
        bool                Equal(const CONSTANT_Utf8* other);
        bool                Equal(const char* other);
        int                 IndexOf(char ch);
        int                 LastIndexOf(char ch);
    };
    class InputStream
    {
    protected:
        InputStream();
    public:
        InputStream(char* data,int length,Endian type=Big_Endian);
        virtual ~InputStream();
    public:
        void            Set(char* data,int length,Endian type=Big_Endian);
        inline char*    Data(){return data;}
        inline int		Offset(){return offset;}
        void            Offset(int of){offset=of;}
        char            ReadByte();
        bool            ReadBoolean();
        void            Read(char* buf,int length);
        void            Skip(int bytes);
        short           ReadShort();
        int             ReadUnsignedShort();
        int             ReadInt();
        float           ReadFloat();
        double          ReadDouble();
        long long       ReadLong();
        inline int      Available(){return dataLength-offset;}
        inline int 		Length(){return dataLength;}
    protected:
        char*   data;
        Endian  type;
        int     dataLength;
        int     offset;
    };
        
    
    class OutputStream
    {
    public:
        OutputStream(Endian type=Big_Endian);
        virtual ~OutputStream(){}
    public:
        virtual void    Write(char* buffer,int length)=0;
        inline void     Write(const char* str){Write((char*)str, strlen(str));}
        inline void     WriteByte(char b){Write(&b, 1);}
        inline void     WriteBoolean(bool b){WriteByte(b?1:0);}
        void			WriteShort(short s);
        void            WriteInt(int i);
        void            WriteFloat(float f);
        void            WriteDouble(double d);
        void            WriteLong(long long l);
    protected:
        Endian  type;
    };
    
    class ByteArrayOutputStream:public OutputStream
    {
    public:
        ByteArrayOutputStream(int capcity=64,Endian type=Big_Endian);
        ~ByteArrayOutputStream();
    public:
        void            Write(char* buffer,int length);
        inline char*    Data(){return buffer;}
        inline int      Length(){return length;}
        inline void     Clear(){length=0;}
        void            RemoveHead(int count);
    protected:
        char*   buffer;
        int     length;
        int     capcity;
    };
    
    class FileInputStream:public InputStream
    {
    public:
        FileInputStream(char* data,int length,Endian type=Big_Endian);
        FileInputStream(const char* file,Endian type=Big_Endian);
        ~FileInputStream();
    private:
#ifdef WIN32
		void* fileHandle;
		void* fileMapping;
#else
        int fd;
		char* fileData;
		int	  fileLength;
#endif
    };
}

#endif
