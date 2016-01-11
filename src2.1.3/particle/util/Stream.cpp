#include <string>
#include "Stream.h"
#include <assert.h>
#include <fcntl.h>
#ifndef WIN32
#include <sys/mman.h>
#include <sys/types.h>
#include <unistd.h>
#endif
#include <CCStdC.h>
namespace particle
{
    CONSTANT_Utf8::CONSTANT_Utf8():length(0),data(NULL)
    {
    }
    CONSTANT_Utf8::~CONSTANT_Utf8()
    {
        delete[] data;
    }
    CONSTANT_Utf8::CONSTANT_Utf8(const CONSTANT_Utf8& other):length(0),data(NULL)
    {
        this->Set(other.data);
    }
    CONSTANT_Utf8::CONSTANT_Utf8(const char* other):length(0),data(NULL)
    {
        this->Set(other);
    }
    const CONSTANT_Utf8& CONSTANT_Utf8::operator=(const CONSTANT_Utf8& other)
    {
        if(&other!=this)
        {
            this->Set(other.data);
        }
        return *this;
    }
    const CONSTANT_Utf8& CONSTANT_Utf8::operator=(const char* other)
    {
        this->Set(other);
        return *this;
    }
    void CONSTANT_Utf8::Read(InputStream& is)
    {
        int newLength=is.ReadShort();
        if(data==NULL||newLength>length)
        {
            delete[] data;
            data=new char[newLength+1];
        }
        is.Read(data, newLength);
        length=newLength;
        data[newLength]=0;
    }
    void CONSTANT_Utf8::Read4HeadUTF(InputStream& is)
    {
        int newLength=is.ReadInt();
        if(data==NULL||newLength>length)
        {
            delete data;
            data=new char[newLength+1];
        }
        is.Read(data, newLength);
        length=newLength;
        data[newLength]=0;
    }
	void CONSTANT_Utf8::Write(OutputStream& os)
    {
        os.WriteShort(length);
        os.Write(data, length);
    }
    void CONSTANT_Utf8::Set(const char* value)
    {
        if(value==NULL)
        {
            value="";
        }
        int newLength=strlen(value);
        if(data==NULL||newLength>length)
        {
            delete[] data;
            data=new char[newLength+1];
        }
        memcpy(data, value, newLength);
        length=newLength;
        data[newLength]=0;
    }
    bool   CONSTANT_Utf8::Equal(const CONSTANT_Utf8* other)
    {
        if(other->length==this->length&&memcmp(data, other->data, this->length)==0)
        {
            return true;
        }
        return false;
    }
    bool  CONSTANT_Utf8::Equal(const char* other)
    {
        int otherLength=strlen(other);
        if(otherLength==this->length&&memcmp(data, other, this->length)==0)
        {
            return true;
        }
        return false;
    }
    int CONSTANT_Utf8::IndexOf(char ch)
    {
        for(int i=0;i<length;i++)
        {
            if(data[i]==ch)
            {
                return i;
            }
        }
        return -1;
    }
    int CONSTANT_Utf8::LastIndexOf(char ch)
    {
        for(int i=length-1;i>=0;i--)
        {
            if(data[i]==ch)
            {
                return i;
            }
        }
        return -1;
    }
    
    
    
    InputStream::InputStream()
    {
        data=NULL;
        dataLength=0;
        offset=0;
    }
    InputStream::~InputStream()
    {
    }
    InputStream::InputStream(char* data,int length,Endian type):data(data),type(type),dataLength(length),offset(0)
    {
    }
    void InputStream::Set(char* data,int length,Endian type)
    {
        this->data=data;
        this->dataLength=length;
        this->offset=0;
        this->type=type;
    }
    char InputStream::ReadByte()
    {
        if(data==NULL)
        {
//            MY_THROW(NullPointerException, "InputStream::ReadByte");
            assert(false);
        }
        if((offset+1)>Length())
        {
            char buffer[64];
            snprintf(buffer, 64, "InputStream::ReadByte(offset:%d,length:%d)",offset,Length());
//            MY_THROW(IOException, buffer);
            assert(false);
        }
        return data[offset++];
    }
    bool InputStream::ReadBoolean()
    {
        if(data==NULL){
//            MY_THROW(NullPointerException, "InputStream::ReadBoolean");
            assert(false);
        }
        if((offset+1)>Length())
        {
            char buffer[64];
            snprintf(buffer, 64, "InputStream::ReadBoolean(offset:%d,length:%d)",offset,Length());
//            MY_THROW(IOException, buffer);
            assert(false);
        }
        
        return data[offset++]?true:false;
    }
    void InputStream::Read(char* buf,int length)
    {
        if(data==NULL||buf==NULL){
//            MY_THROW(NullPointerException, "InputStream::Read");
            assert(false);
        }
        if((offset+length)>Length()||length<0)
        {
            char buffer[128];
            snprintf(buffer, 128, "InputStream::Read(offset:%d,length:%d,available=%d,readLength:%d)",offset,Length(),Available(),length);
//            MY_THROW(IOException, buffer);
            assert(false);
        }
        
        
        memcpy(buf,data+offset,length);
        offset+=length;
    }
    void InputStream::Skip(int bytes)
    {
        int end=offset+bytes;
        if(end>Length()){
//            MY_THROW(IOException, "InputStream::Skip");
            assert(false);
        }
        offset=end;
    }
    short InputStream::ReadShort()
    {
        int b1=ReadByte()&0xFF;
        int b2=ReadByte()&0xFF;
        if(type==Big_Endian)
        {
            return (short)((b1<<8)|b2);
        }else
        {
            return (short)((b2<<8)|b1);
        }
    }
    int InputStream::ReadUnsignedShort()
    {
        int b1=ReadByte()&0xFF;
        int b2=ReadByte()&0xFF;
        if(type==Big_Endian)
        {
            return ((b1<<8)|b2);
        }else
        {
            return ((b2<<8)|b1);
        }
    }
    int InputStream::ReadInt()
    {
        int b1=ReadByte()&0xFF;
        int b2=ReadByte()&0xFF;
        int b3=ReadByte()&0xFF;
        int b4=ReadByte()&0xFF;
        if(type==Big_Endian)
        {
            return (b1<<24)|(b2<<16)|(b3<<8)|(b4<<0);
        }else
        {
            return (b4<<24)|(b3<<16)|(b2<<8)|(b1<<0);
        }
    }
    float InputStream::ReadFloat()
    {
        char buf[4];
        buf[0]=ReadByte()&0xFF;
        buf[1]=ReadByte()&0xFF;
        buf[2]=ReadByte()&0xFF;
        buf[3]=ReadByte()&0xFF;
        return *((float*)&buf);
    }
    double InputStream::ReadDouble()
    {
        char buf[8];
        buf[0]=ReadByte()&0xFF;
        buf[1]=ReadByte()&0xFF;
        buf[2]=ReadByte()&0xFF;
        buf[3]=ReadByte()&0xFF;
        buf[4]=ReadByte()&0xFF;
        buf[5]=ReadByte()&0xFF;
        buf[6]=ReadByte()&0xFF;
        buf[7]=ReadByte()&0xFF;
        return *(double*)&buf;
    }
    long long InputStream::ReadLong()
    {
        long long b0=ReadByte()&0xFF;
        long long b1=ReadByte()&0xFF;
        long long b2=ReadByte()&0xFF;
        long long b3=ReadByte()&0xFF;
        long long b4=ReadByte()&0xFF;
        long long b5=ReadByte()&0xFF;
        long long b6=ReadByte()&0xFF;
        long long b7=ReadByte()&0xFF;
        if(type==Big_Endian)
        {
            return (b0<<56)|(b1<<48)|(b2<<40)|(b3<<32)|(b4<<24)|(b5<<16)|(b6<<8)|(b7<<0);
        }else
        {
            return ((b7<<56)|(b6<<48)|(b5<<40)|(b4<<32))||((b3<<24)|(b2<<16)|(b1<<8)|(b0<<0));
        }
    }
    
    OutputStream::OutputStream(Endian type)
    {
        this->type=type;
    }
    
    void OutputStream::WriteShort(short v)
    {
        char buf[2];
        if(type==Big_Endian)
        {
            buf[0]=(v>>8);
            buf[1]=(v);
        }else
        {
            buf[0]=(v);
            buf[1]=(v>>8);
        }
        Write(buf, 2);
    }
    void OutputStream::WriteInt(int v)
    {
        char buf[4];
        if(type==Big_Endian)
        {
            buf[0]=(v>>24);
            buf[1]=(v>>16);
            buf[2]=(v>>8);
            buf[3]=(v);
        }else
        {
            buf[0]=(v);
            buf[1]=(v>>8);
            buf[2]=(v>>16);
            buf[3]=(v>>24);
        }
        Write(buf, 4);
    }
    void OutputStream::WriteFloat(float f)
    {
        char* buf=(char*)&f;
        Write(buf, 4);
    }
    void OutputStream::WriteDouble(double d)
    {
        char* buf=(char*)&d;
        Write(buf, 8);
    }
    void OutputStream::WriteLong(long long v)
    {
        char buf[8];
        if(type==Big_Endian)
        {
            buf[0]=(v>>56);
            buf[1]=(v>>48);
            buf[2]=(v>>40);
            buf[3]=(v>>32);
            buf[4]=(v>>24);
            buf[5]=(v>>16);
            buf[6]=(v>>8);
            buf[7]=(v);
        }else
        {
            buf[0]=(v);
            buf[1]=(v>>8);
            buf[2]=(v>>16);
            buf[3]=(v>>24);
            buf[4]=(v>>32);
            buf[5]=(v>>40);
            buf[6]=(v>>48);
            buf[7]=(v>>56);
        }
        Write(buf, 8);
    }
    
    ByteArrayOutputStream::ByteArrayOutputStream(int c,Endian type):OutputStream(type)
    {
        buffer=new char[c];
        this->capcity=c;
        this->length=0;
    }
    ByteArrayOutputStream::~ByteArrayOutputStream()
    {
        delete buffer;
        buffer=NULL;
    }
    void ByteArrayOutputStream::Write(char* b,int l)
    {
        int oLength=this->length+l;
        if(oLength>capcity)
        {
            int newCapcity=capcity*2+1;
            newCapcity=oLength<newCapcity?newCapcity:oLength+1;
            
            char* newBuffer=new char[newCapcity];
            memcpy(newBuffer, buffer, length);
            delete buffer;
            buffer=newBuffer;
            capcity=newCapcity;
        }
        memcpy(buffer+length, b, l);
        this->length+=l;
    }
    void ByteArrayOutputStream::RemoveHead(int count)
    {
        assert(count<=length);
        memmove(buffer, buffer+count, length-count);
        this->length-=count;
    }

    FileInputStream::FileInputStream(char* data,int length,Endian type)   
    : InputStream(data,length,type)
    {
    }
    FileInputStream::FileInputStream(const char* file,Endian t)
    {
        
#if defined(WIN32)||defined(ANDROID)
#define DOC_DIR         "../Documents"
#define DOC_DIR_LENTH   strlen(DOC_DIR)
#endif
        
#ifdef WIN32
    	if (memcmp(file, DOC_DIR, DOC_DIR_LENTH) == 0) {
            file += 3;
    	}
		fileHandle=NULL;
		fileMapping=NULL;
		fileHandle = CreateFileA(file, GENERIC_READ,FILE_SHARE_READ,NULL,OPEN_EXISTING,0,NULL);
		if(fileHandle!=NULL)
		{
			fileMapping = CreateFileMapping(fileHandle,NULL,PAGE_READONLY,0,0,NULL);
			if(fileMapping!=NULL)
			{
		        this->type=t;
				data = (char *) MapViewOfFile(fileMapping,FILE_MAP_READ,0,0,0);
				dataLength=GetFileSize(fileHandle,NULL);
			}
		}
#else
//#ifdef ANDROID
//        char changeFile[260];
//        if(memcmp(file,DOC_DIR,DOC_DIR_LENTH)==0)
//        {
//            snprintf(changeFile,260,"%s%s",GetDocumentPath(),file+DOC_DIR_LENTH);
//            file=changeFile;
//        }
//        
//#endif
        if((fd=open(file, O_RDONLY))!=-1)
        {        	
            dataLength=(int)lseek(fd, (off_t)0, SEEK_END);
            fileLength=dataLength;
            data=NULL;
            if(dataLength!=0)
            {
                data=(char*)mmap(NULL, dataLength, PROT_READ, MAP_FILE|MAP_PRIVATE, fd, 0);
                assert(data!=MAP_FAILED);
            }else{
//            	XCLOG("[FileInputStream::FileInputStream error][file length error === %s]",file);
            }
            fileData=data;
            offset=0;
            this->type=t;
            
        }else{
//        	XCLOG("[FileInputStream::FileInputStream error][file not found === %s]",file);
        }
        
        
#endif
    }
    FileInputStream::~FileInputStream()
    {
#ifdef WIN32
		UnmapViewOfFile(data);
		CloseHandle(fileMapping);
		CloseHandle(fileHandle);
        
#else
        if(fd!=-1)
        {
        	//XCLOG("Close file OK");
            munmap(fileData, fileLength);
            close(fd);
            fd=-1;
        }
#endif
    }

}
