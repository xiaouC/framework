#ifndef __SDK_H__
#define __SDK_H__
#include "platform.pb.h"

void OpenPlatformLogin();
void OpenPlatformLoginout();
void OpenPayInterface(char* szSerialNo, float money);
void EnterPlatform();
framework::SDKType GetSdkType();

void payWithAndroidSDK(char *orderID, char *serverID, char *roleID, char *roleName, char *roleLevel, char *loginName, char *pbID );
#endif
