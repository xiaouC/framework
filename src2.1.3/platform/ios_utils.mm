#include <sys/socket.h> // Per msqr
#include <sys/sysctl.h>
#include <net/if.h>
#include <net/if_dl.h>
#include "PlatformUtils.h"
#include "platform/sdk.h"
#include "Common/LuaApi.h"
#include "CCString.h"
#import <AdSupport/ASIdentifierManager.h>
#import <Reachability/Reachability.h>
#include "CHkeychain.h"
#include "CCLuaEngine.h"
USING_NS_CC;

#import "SDKLoginUtilsForIOS.h"
#import "IOSVideoController.h"
#import <mach/mach.h>

#ifdef GF_APPSTORE
#import <Yunyue/StoreIAP.h>
#endif

const char* macaddress()
{
    int                    mib[6];
    size_t                len;
    char                *buf;
    unsigned char        *ptr;
    struct if_msghdr    *ifm;
    struct sockaddr_dl    *sdl;
    
    mib[0] = CTL_NET;
    mib[1] = AF_ROUTE;
    mib[2] = 0;
    mib[3] = AF_LINK;
    mib[4] = NET_RT_IFLIST;
    
    if ((mib[5] = if_nametoindex("en0")) == 0) {
        printf("Error: if_nametoindex error\n");
        return NULL;
    }
    
    if (sysctl(mib, 6, NULL, &len, NULL, 0) < 0) {
        printf("Error: sysctl, take 1\n");
        return NULL;
    }
    
    if ((buf = (char*)malloc(len)) == NULL) {
        printf("Could not allocate memory. error!\n");
        return NULL;
    }
    
    if (sysctl(mib, 6, buf, &len, NULL, 0) < 0) {
        printf("Error: sysctl, take 2\n");
        return NULL;
    }
    
    ifm = (struct if_msghdr *)buf;
    sdl = (struct sockaddr_dl *)(ifm + 1);
    ptr = (unsigned char *)LLADDR(sdl);
    // NSString *outstring = [NSString stringWithFormat:@"%02x:%02x:%02x:%02x:%02x:%02x", *ptr, *(ptr+1), *(ptr+2), *(ptr+3), *(ptr+4), *(ptr+5)];
    char strbuf[128] = {0};
    snprintf(strbuf, sizeof(strbuf)-1, "%02x%02x%02x%02x%02x%02x", *ptr, *(ptr+1), *(ptr+2), *(ptr+3), *(ptr+4), *(ptr+5));
    
    cocos2d::CCString *ret = new cocos2d::CCString(strbuf);
    free(buf);
    ret->autorelease();
    return ret->m_sString.c_str();
}

const char* getDeviceId()
{
//    return macaddress();
    
//    NSString *openUDID = [OpenUDID value];
//    cocos2d::CCString *ret = new cocos2d::CCString([openUDID UTF8String]);
//    ret->autorelease();
//    return ret->m_sString.c_str();
    
    NSString * const KEY_LOLUDID = @"com.zhangqu.yunyue.app.yunyuelol";
    NSString * const KEY_NAME = @"com.zhangqu.yunyue.app.yunyuelol.id";
    
    NSMutableDictionary *keyword = (NSMutableDictionary*)[CHkeychain load:KEY_LOLUDID];
    NSString* tmpudid = [keyword objectForKey:KEY_NAME];
    
    NSString *UUID = tmpudid;
    if ( tmpudid == NULL )
    {
        NSMutableDictionary *keywordsave = [NSMutableDictionary dictionary];
        CFUUIDRef theUUID = CFUUIDCreate(kCFAllocatorDefault);
        CFStringRef string = CFUUIDCreateString(kCFAllocatorDefault, theUUID);
        CFRelease(theUUID);
        UUID = [(NSString*)string stringByReplacingOccurrencesOfString:@"-" withString:@""];
        [keywordsave setObject:UUID forKey:KEY_NAME];
        [CHkeychain save:KEY_LOLUDID data:keywordsave];
    }
    
    cocos2d::CCString *ret = new cocos2d::CCString([UUID UTF8String]);
    ret->autorelease();
    return ret->m_sString.c_str();
}

const char* getUUID()
{
    return "";
}

int getPackageVersion()
{
    return floor([[[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleVersion"] floatValue] * 100000);
}

const char* getNetworkTypeName()
{
    Reachability *reach = [Reachability reachabilityForInternetConnection];
    NetworkStatus status = [reach currentReachabilityStatus];
    if (status == ReachableViaWiFi) {
        return "WIFI";
    } else if (status == ReachableViaWWAN) {
        return "MOBILE";
    } else {
        return "";
    }
}

std::string getPackageName()
{
    const char* s = getMetaData("YYPackageName");
    std::string ret = "";
    if (s==NULL || s[0]=='\0')
    {
        ret = std::string([[[NSBundle mainBundle] bundleIdentifier] UTF8String]);
    }
    else
    {
        ret = s;
    }

    return ret;
}

void OpenPlatformLogin()
{
    [SDKLoginUtilsForIOS start];
}

void OpenPlatformLoginout()
{
    [SDKLoginUtilsForIOS end];
}

void EnterPlatform()
{
    [SDKLoginUtilsForIOS enterPlatform];
}

const char* getOSVersion()
{
    return [[[UIDevice currentDevice] systemVersion] UTF8String];
}

const char* getResolution()
{
    CGRect screenRect = [[UIScreen mainScreen] bounds];
    CGFloat scale = [[UIScreen mainScreen] scale];
    return [[NSString stringWithFormat:@"%d,%d", (NSInteger)(screenRect.size.width * scale), (NSInteger)(screenRect.size.height * scale)] UTF8String];
}

const char* getUA()
{
    UIWebView *webView = [[[UIWebView alloc] init] autorelease];
    return [[webView stringByEvaluatingJavaScriptFromString:@"navigator.userAgent"] UTF8String];
}

const char* getMetaData(const char* name) {
    NSString *_name =[NSString stringWithUTF8String:name];
    NSString *val = [[[NSBundle mainBundle] infoDictionary] objectForKey:_name];
    return [val UTF8String];
}

const char* getIMSI()
{
    return "";
}

const char* getIMEI()
{
    return "";
}

const char* getidfa()
{
    if ( [[UIDevice currentDevice].systemVersion floatValue] < 6.0)
    {
        return "";
    }
    
    NSString *adId = [[[ASIdentifierManager sharedManager] advertisingIdentifier] UUIDString];
    cocos2d::CCString *ret = new cocos2d::CCString([adId UTF8String]);
    ret->autorelease();
    return ret->m_sString.c_str();
}

const char* getMAC()
{
    if ( [[UIDevice currentDevice].systemVersion floatValue] < 7.0)
    {
        return macaddress();
    }
    
    return "";
}

const char* getdeviceUniqueID()
{
    return "";
}

bool idleTimerDisabled(bool state) {
    [UIApplication sharedApplication].idleTimerDisabled = state;
    NSLog(@"idleTimerDisabled: %d", [UIApplication sharedApplication].idleTimerDisabled);
    return [UIApplication sharedApplication].idleTimerDisabled;
}

void openURL(const char* sUrl)
{
    NSString *url = [NSString stringWithUTF8String:sUrl];
    [[UIApplication sharedApplication] openURL:[NSURL URLWithString:url]];
}

bool acquireWakeLock()
{
    [UIApplication sharedApplication].idleTimerDisabled=YES;//not let iphone go to sleep
    return true;
}

bool releaseWakeLock()
{
    [UIApplication sharedApplication].idleTimerDisabled=NO;//not let iphone go to sleep
    return true;
}

void createLocalNotification( const char* nDaysLater, const char* nHour, const char* nMinute, const char*  nSecond, const char* szContent, const char* name, const char* nType )
{
    // 创建一个本地推送
    UILocalNotification* notification = [[[UILocalNotification alloc] init] autorelease];
    NSString *_name = [NSString stringWithUTF8String:name];
    
    NSString *_nType = [NSString stringWithUTF8String:nType];


    if( notification != nil )
    {
        // 获取系统当前时间
        NSCalendar* calendar = [[[NSCalendar alloc] initWithCalendarIdentifier:NSGregorianCalendar] autorelease];
        NSDateComponents* comps = [[[NSDateComponents alloc] init] autorelease];
        NSInteger unitFlags = NSYearCalendarUnit | NSMonthCalendarUnit | NSDayCalendarUnit | NSWeekdayCalendarUnit | NSHourCalendarUnit | NSMinuteCalendarUnit | NSSecondCalendarUnit;
        NSDate* now = [NSDate date];
        comps = [calendar components:unitFlags fromDate:now];
        int year = [comps year];
        int month = [comps month];
        int day = [comps day];
        [comps setSecond:[[NSString stringWithUTF8String:szContent] intValue]];
        [comps setMinute:[[NSString stringWithUTF8String:nMinute] intValue]];
        [comps setHour:[[NSString stringWithUTF8String:nHour] intValue]];
        [comps setDay:day];
        [comps setMonth:month];
        [comps setYear:year];

        NSCalendar* gregorian = [[[NSCalendar alloc] initWithCalendarIdentifier:NSGregorianCalendar] autorelease];
        NSDate* tempDate = [gregorian dateFromComponents:comps];

        NSTimeInterval seconds = 24 * 60 * 60 * [[NSString stringWithUTF8String:nDaysLater] intValue];
        NSDate* pushDate = [tempDate addTimeInterval:seconds];

        NSTimeInterval nInterval = [now timeIntervalSince1970];
        NSTimeInterval pInterval = [pushDate timeIntervalSince1970];
        if( nInterval > pInterval )
            return;

        // 设置推送时间
        notification.fireDate = pushDate;
        // 设置时区
        notification.timeZone = [NSTimeZone defaultTimeZone];
        // 设置重复间隔
        
        if ([_nType isEqualToString:@"EveryDay"]) {
            notification.repeatInterval = kCFCalendarUnitDay;
        }else{
            notification.repeatInterval = 0;
        }
        
        // 推送声音
        notification.soundName = UILocalNotificationDefaultSoundName;
        // 推送内容
        notification.alertBody = [NSString stringWithUTF8String:szContent];
        //显示在icon上的红色圈中的数子
        notification.applicationIconBadgeNumber = 1;
        //设置userinfo 方便在之后需要撤销的时候使用
        NSDictionary* info = [NSDictionary dictionaryWithObject:_name forKey:@"name"];
        notification.userInfo = info;
        //添加推送到UIApplication
        UIApplication *app = [UIApplication sharedApplication];
        [app scheduleLocalNotification:notification];
    }
}

void releaseLocalNotification( const char* name )
{
    NSString *_name = [NSString stringWithUTF8String:name];
    for (UILocalNotification *n in [[UIApplication sharedApplication] scheduledLocalNotifications]) {
        if ([[n.userInfo objectForKey:@"name"] isEqualToString:_name]) {
            [[UIApplication sharedApplication] cancelLocalNotification:n];
        }
    }
}

void releaseAllLocalNotification()
{
    [[UIApplication sharedApplication] cancelAllLocalNotifications];
    [UIApplication sharedApplication].applicationIconBadgeNumber = 0;
}

void playMedia( const char* szPath )
{
    // char* 转化为 NSString 
    NSString* audioname = [NSString stringWithUTF8String:szPath];
    IOSVideoController* app = [[IOSVideoController alloc] init];
    [app playVideo:audioname :NULL];
}

void stopMedia()
{
}

void quitApplication()
{
    [[NSNotificationCenter defaultCenter] postNotificationName:@"EXIT_APPLICATION" object:nil];
}

const char* getAvailMemory()
{
    vm_statistics_data_t vmStats;
    mach_msg_type_number_t infoCount = HOST_VM_INFO_COUNT;
    kern_return_t kernReturn = host_statistics( mach_host_self(), HOST_VM_INFO, (host_info_t)&vmStats, &infoCount );
    if( kernReturn != KERN_SUCCESS )
        return "50.0";

    NSString* avail_mem = [NSString stringWithFormat:@"%f", ( ( vm_page_size * vmStats.free_count ) / 1024.0) / 1024.0];

    cocos2d::CCString *ret = new cocos2d::CCString( [avail_mem UTF8String] );
    ret->autorelease();

    return ret->m_sString.c_str();
}
