#ifndef __LOADING_DIALOG_H__
#define __LOADING_DIALOG_H__

//void showLoading(const char* sMsg=0);
//void hideLoading();
//bool isLoadingShowing();
#include<string>

void quitConfirm();
void quitApplication();
void hideWindow();
bool isETC1Supported();

const char* getDeviceId();
const char* getIMSI();
const char* getUUID();
const char* getPlatform();
const char* getOSVersion();
const char* getResolution();
const char* getUA();
const char* getMetaData(const char*);
const char* getdeviceUniqueID();
const char* getMAC();
const char* getidfa();
const char* getIMEI();

bool acquireWakeLock();
bool releaseWakeLock();
bool userActivity();

int getPackageVersion();
std::string getPackageName();
const char* getNetworkTypeName();

void openURL(const char* sUrl);

void initLog();
void finiLog();

void useConsole(); //  π”√øÿ÷∆Ã®

void setResourceVersion( const char* szResVersion );
const char* getResourceVersion();

void playMedia( const char* szPath );
void stopMedia();


void createLocalNotification( const char* nDaysLater, const char* nHour, const char* nMinute, const char* nSecond, const char* szContent, const char* key, const char* nType );
void releaseLocalNotification( const char* key = "" );
void releaseAllLocalNotification();

const char* getAvailMemory();

#endif
