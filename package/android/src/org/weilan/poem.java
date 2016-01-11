/****************************************************************************
  Copyright (c) 2010-2012 cocos2d-x.org

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
 ****************************************************************************/
package org.weilan;

import android.os.Handler;
import android.os.Message;


import org.cocos2dx.lib.Cocos2dxActivity;

import org.json.JSONObject;
import org.json.JSONException;
import android.app.Activity;
import android.os.Bundle;
import android.content.Intent;
import android.content.IntentFilter;
import android.net.Uri;
import android.net.ConnectivityManager;
import android.util.Log;
import android.view.Gravity;
import android.view.KeyEvent;
import android.view.MotionEvent;
import android.view.View;
import android.view.View.OnKeyListener;
import android.view.View.OnTouchListener;
import android.view.Window;
import android.view.WindowManager;
import android.view.View.OnClickListener;
import android.view.WindowManager.LayoutParams;
import android.view.inputmethod.InputMethodManager;
import android.widget.Button;
import android.widget.EditText;
import android.widget.FrameLayout;
import android.widget.LinearLayout;
import android.os.Build;
import android.content.Context;
import android.telephony.TelephonyManager;
import android.os.PowerManager;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager.NameNotFoundException;
import android.app.Dialog;
import android.app.ProgressDialog;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.graphics.drawable.ColorDrawable;

import java.io.UnsupportedEncodingException;
import android.content.ActivityNotFoundException;

import java.util.Map;
import java.util.HashMap;
import java.util.Calendar;
import java.util.Date;
import java.lang.Integer;
import java.text.SimpleDateFormat;

import android.app.PendingIntent;

import java.io.FileOutputStream;
import java.io.FileInputStream;
import java.io.ByteArrayOutputStream;
import java.util.Iterator;
import java.io.File;

import android.net.wifi.WifiManager;
import android.net.wifi.WifiInfo;
import android.net.NetworkInfo;
import android.text.Editable;
import android.text.InputFilter;
import android.text.InputType;
import android.text.TextWatcher;
import android.text.method.PasswordTransformationMethod;

import android.app.ActivityManager;
import android.app.ActivityManager.MemoryInfo;
import android.text.format.Formatter;

import android.app.Notification;
import android.app.NotificationManager;
import android.app.AlarmManager;
import android.text.format.Time;

import com.umeng.analytics.game.UMGameAgent;

public class poem extends Cocos2dxActivity {

    static {
        System.loadLibrary("game");
    }

    private ProgressDialog loadingDialog;

    private static String deviceId;
    private static PowerManager.WakeLock wakeLock;
    private static PowerManager powerManager;
    private static boolean lockAcquired = false;

    protected static Handler handler;
    private final static int SHOW_LOADING = 1;
    private final static int HIDE_LOADING = 2;
    private final static int QUIT_CONFIRM = 3;
    private final static int FINISH = 4;
    private final static int SHOW_LOGIN = 5;
    protected final static int PAY = 7;
    protected final static int LOGOUT = 8;
    protected final static int UNZIP_FILE = 13;
    protected final static int SDK_INIT = 14;
    private final static int SUBMIT_EXTEND_DATA = 15;
    private final static int OPEN_CUSTOM_KEYBOARD = 16;
    private final static int CLOSE_CUSTOM_KEYBOARD = 18;

    private final static int SET_EXT_DATA = 17;


    private final static int CB_LOGIN_SUCCESS   = 0;
    private final static int CB_LOGIN_FAIL      = 1;
    private final static int CB_LOGOUT_SUCCESS  = 2;
    private final static int CB_LOGOUT_FAIL     = 3;
    private final static int CB_PAY_SUCCESS     = 4;
    private final static int CB_PAY_FAIL        = 5;
    private final static int CB_EXIT_CUSTOM     = 6;
    private final static int CB_DONT_SUPPORT_LOGIN     = 7;
    private final static int CB_SDK_INIT_END   = 11;


    private static int versionCode = 0;

    public static Context ctx = null;
    public static poem app;

    protected Dialog   edit_dialog;
    protected EditText edit_talk;
    protected Button btn_confirm;
    protected AlertDialog dialog;


    private ConnectionChangeReceiver connChangeReceiver;

    protected void onCreate(Bundle savedInstanceState){
        super.onCreate(savedInstanceState);

        UMGameAgent.init(this);

        GameProxy.getInstance().applicationInit(this);
        GameProxy.getInstance().onCreate(this);

        ctx = this;
        app = this;
        // get the packageName,it's used to set the resource path
        String packageName = getApplication().getPackageName();
        //super.setPackageName(packageName);

        try
        {
            PackageInfo pkgManager = getPackageManager().getPackageInfo(packageName, 0);
            versionCode = pkgManager.versionCode;
        }catch (NameNotFoundException e) {
            ;
        }

        loadingDialog = new ProgressDialog(this);
        loadingDialog.setProgressStyle(ProgressDialog.STYLE_SPINNER);
        loadingDialog.setCancelable(false);

        powerManager = (PowerManager) getSystemService(Context.POWER_SERVICE);
        //wakeLock = powerManager.newWakeLock(PowerManager.FULL_WAKE_LOCK, "poem");
        wakeLock = powerManager.newWakeLock(PowerManager.SCREEN_DIM_WAKE_LOCK | PowerManager.ON_AFTER_RELEASE, "poem");

        TelephonyManager telephonyManager = (TelephonyManager)getSystemService(Context.TELEPHONY_SERVICE);
        deviceId = telephonyManager.getDeviceId();
        if (deviceId==null || deviceId=="")
            deviceId = genPseudoId();
        if (deviceId==null)
            deviceId = "";

        handler = new Handler(){
            public void handleMessage(Message msg){
                switch(msg.what){
                    case SHOW_LOADING:
                        doShowLoading((String)msg.obj);
                        break;
                    case HIDE_LOADING:
                        doHideLoading();
                        break;
                    case UNZIP_FILE:
                        doUnZipFile(msg.getData());
                        break;
                    case SDK_INIT:
                        doSdkInit();
                        break;
                    case OPEN_CUSTOM_KEYBOARD:
                        doOpenCustomKeyBoard(msg.getData());
                        break;
                    case CLOSE_CUSTOM_KEYBOARD:
                        doCloseCustomKeyBoard();
                        break;
                }
            }
        };

        GameProxy.getInstance().setUserListener(this, new UserListener() {
            @Override
            public void onLoginFailed(String reason, Object customParams) {
                Log.v("poem", "onLoginFailed");
                sdk.platformCallback(CB_LOGIN_FAIL, "");
                // 登录失败
            }
            @Override
            public void onLoginSuccess(User user, Object params) {
                // 登录成功
                Log.v("poem", "onLoginSuccess");
                try {
                    JSONObject json = new JSONObject();
                    json.put("username", user.username);
                    json.put("userID", user.userID);
                    json.put("token", user.token);
                    sdk.platformCallback(CB_LOGIN_SUCCESS, json.toString());
                } catch (JSONException e) {
                    Log.v("poem", "onloginSuccess, JSONError");
                }
            }
            @Override
            public void onLogout(Object params) {
                // 登出
                Log.v("poem", "onLogout");
                sdk.platformCallback(CB_LOGOUT_SUCCESS, "");
            }
            @Override
            public void onDontSupportLogin(Object params) {
                Log.v("poem", "onDontSupportLogin");
                sdk.platformCallback(CB_DONT_SUPPORT_LOGIN, "");
            }
        });

        // 监听网络改变
        IntentFilter filter = new IntentFilter( ConnectivityManager.CONNECTIVITY_ACTION );
        connChangeReceiver = new ConnectionChangeReceiver();
        this.registerReceiver( connChangeReceiver, filter );

        //
        Intent intent = new Intent( this, PushService.class );
        startService( intent );
    }

    public static void quitConfirm(){
        if (app != null) {
            app.runOnUiThread(new Runnable() {
                public void run() {
                    GameProxy.getInstance().exit(app, new ExitCallback() {
                        //以下2个回调请勿留空或者照搬Demo，必须全部实现
                        @Override
                        public void onNo3rdExiterProvide(){
                            sdk.platformCallback(CB_EXIT_CUSTOM, "");
                            // 调用lua退出窗口
                        }
                        @Override
                        public void onExit(){
                            quitApplication();
                            //退出窗口由渠道提供，游戏只须实现资源回收，杀死进程等退出逻辑
                            //1.调用游戏退出逻辑
                        }
                    });
                }
            });
        }
    }

    public static void quitApplication()
    {
        if (app != null) {
            app.finish();
            //GameProxy.getInstance().onDestroy(app);
            android.os.Process.killProcess(android.os.Process.myPid());
        }
    }


    public static void talkDataRegister(String username){
        app.doTalkDataRegister(username);
    }

    public void doTalkDataRegister(String username){

    }

    public static void talkDataLogin(String username){
        app.doTalkDataLogin(username);
    }

    public void setImmersionMode(){
        if( Build.VERSION.SDK_INT >= Build.VERSION_CODES.KITKAT ) {
            View decorView = getWindow().getDecorView();
            int uiFlags = View.SYSTEM_UI_FLAG_LAYOUT_STABLE
                | View.SYSTEM_UI_FLAG_LAYOUT_HIDE_NAVIGATION
                //| View.SYSTEM_UI_FLAG_LAYOUT_FULLSCREEN
                | View.SYSTEM_UI_FLAG_HIDE_NAVIGATION // hide nav bar
                | View.SYSTEM_UI_FLAG_FULLSCREEN; // hide status bar

            if( android.os.Build.VERSION.SDK_INT >= 19 ){
                uiFlags |= 0x00001000;    //SYSTEM_UI_FLAG_IMMERSIVE_STICKY: hide navigation bars - compatibility: building API level is lower thatn 19, use magic number directly for higher API target level
            } else {
                uiFlags |= View.SYSTEM_UI_FLAG_LOW_PROFILE;
            }

            decorView.setSystemUiVisibility( uiFlags );
        }
    }

    @Override
    public boolean onTouchEvent(MotionEvent event)
    {
        setImmersionMode();
        return true;
    }

    public void doTalkDataLogin(String username ){
    }

    public static void talkDataCreateRole(String rolename){
        app.doTalkDataCreateRole(rolename);
    }

    public void doTalkDataCreateRole(String rolename ){
    }

    public static int getVersionCode()
    {
        return versionCode;
    }

    public static String getMetaData(String name)
    {
        try {
            ApplicationInfo ai = ctx.getPackageManager().getApplicationInfo(ctx.getPackageName(),PackageManager.GET_META_DATA);
            if (ai.metaData == null) {
                return "";
            }

            String result = null;
            int n = ai.metaData.getInt(name);
            if (n==0) {
                result = ai.metaData.getString(name);
            }
            else {
                result = Integer.toString(n);
            }

            if (result == null) {
                return "";
            }

            return result;
        } catch(NameNotFoundException exc) {
            return "";
        }
    }

    public static void openURL(String url) {
        if ( app == null )
        {
            return;
        }

        Intent i = new Intent(Intent.ACTION_VIEW);
        i.setData(Uri.parse(url));
        app.startActivity(i);
    }

    public static String getDeviceId() {
        return deviceId;
    }

    public static String genPseudoId()
    {
        return "" + //we make this look like a valid IMEI
            Build.BOARD.length()%10+ Build.BRAND.length()%10 +
            Build.CPU_ABI.length()%10 + Build.DEVICE.length()%10 +
            Build.DISPLAY.length()%10 + Build.HOST.length()%10 +
            Build.ID.length()%10 + Build.MANUFACTURER.length()%10 +
            Build.MODEL.length()%10 + Build.PRODUCT.length()%10 +
            Build.TAGS.length()%10 + Build.TYPE.length()%10 +
            Build.USER.length()%10 ; //13 digits
    }

    public static boolean acquireWakeLock() {
        if( lockAcquired )
            return true;
        if( wakeLock != null ) {
            try {
                wakeLock.acquire();
                lockAcquired = true;
            }
            catch( SecurityException e )
            {
                Log.e( "cocos2d", "can't acquire wake lock:" + e.toString() );
            }

            return true;
        }
        return false;
    }

    public static boolean releaseWakeLock() {
        if( wakeLock != null ) {
            try {
                wakeLock.setReferenceCounted(false);
                wakeLock.release();
                lockAcquired = false;
            }
            catch( SecurityException e )
            {
                Log.e( "cocos2d", "can't release wake lock:" + e.toString() );
            }
            return true;
        }
        return false;
    }

    public static void showLoading() {
        showLoading(null);
    }

    public static void showLoading(String sMsg) {
        Message msg = new Message();
        msg.what = SHOW_LOADING;
        msg.obj = sMsg;
        handler.sendMessage(msg);
    }

    public void doShowLoading(String sMsg) {
        loadingDialog.setMessage(sMsg);
        loadingDialog.show();
    }

    public static void hideLoading() {
        Message msg = new Message();
        msg.what = HIDE_LOADING;
        handler.sendMessage(msg);
    }


    public void doHideLoading() {
        loadingDialog.hide();
    }

    public static void accountLogin(final String arg) {
        if (app != null) {
            app.runOnUiThread(new Runnable() {
                public void run() {
                    GameProxy.getInstance().login(app, arg);
                }
            });
        }
    }

    public static void accountLogout() {
        if (app != null) {
            app.runOnUiThread(new Runnable() {
                public void run() {
                    GameProxy.getInstance().logout(app, null);
                }
            });
        }
    }

    public static void accountSwitch() {
        if (app != null) {
            app.runOnUiThread(new Runnable() {
                public void run() {
                    GameProxy.getInstance().switchAccount(app, null);
                }
            });
        }
    }

    public static void submitExtendData(final String json) {
        Log.v("sdk", json);
        if (app != null)
            app.runOnUiThread(new Runnable() {
                public void run() {
                    GameProxy.getInstance().setExtData(app, json);
                }
            });
    }

    public static void pay(final String goodID, final String goodName, final String orderID, final float goodPrice, final String callBackInfo, final String roleInfo)
    {
        if (app != null) {
            app.runOnUiThread(new Runnable() {
                public void run() {
                    JSONObject b = null;
                    try {
                        GameProxy.getInstance().pay(
                            app,
                            goodID,                          // 商品名
                            goodName,                        // 商品名
                            orderID,
                            goodPrice,     // 商品价格
                            callBackInfo,
                            new JSONObject(roleInfo),
                            new PayCallBack() {
                                @Override
                                public void onSuccess(String successInfo) {
                                    sdk.platformCallback(CB_PAY_SUCCESS, "");
                                }
                                @Override
                                public void onFail(String failInfo){
                                    sdk.platformCallback(CB_PAY_FAIL, "");
                                }
                        });
                    } catch(JSONException e) {
                        Log.e("poem", "roleInfo json parse failed: " + roleInfo);
                        return;
                    }
                }
            });
        }
    }

    public static void playVideo( String url ) {
        if( app == null )
            return;

        try {
            Intent i = new Intent( app, VideoActivity.class );
            i.putExtra( "video_path", url );
            app.startActivity( i );
        } catch ( ActivityNotFoundException e ) {
            e.printStackTrace();
        }
    }

    public static void createLocalNotification(String nDaysLater, String nHour, String nMinute, String nSecond, String szContent, String key, String nType ) {
        //Time t = new Time();
        //t.setToNow();
        //int nYear = t.year;
        //int nMonth = t.month;
        //int nDate = t.monthDay;

        //Calendar c=Calendar.getInstance();
        //c.set( nYear, nMonth, nDate, 0, 0, 30 );

        //Intent intent = new Intent( "cn.pocketdigi.update.alarm" );
        //intent.setClass( app, AlarmReceiver.class );

        //PendingIntent pi=PendingIntent.getBroadcast( app, 0, intent, 0 );
        ////设置一个PendingIntent对象，发送广播
        //AlarmManager am = (AlarmManager)app.getSystemService( ALARM_SERVICE );
        ////获取AlarmManager对象
        ////am.set( AlarmManager.RTC_WAKEUP, c.getTimeInMillis(), pi );
        //am.setRepeating( AlarmManager.RTC_WAKEUP, c.getTimeInMillis(), 10000, pi );
        //
        ////时间到时，执行PendingIntent，只执行一次
        ////AlarmManager.RTC_WAKEUP休眠时会运行，如果是AlarmManager.RTC,在休眠时不会运行
        ////am.setRepeating(AlarmManager.RTC_WAKEUP, c.getTimeInMillis(), 10000, pi);
        ////如果需要重复执行，使用上面一行的setRepeating方法，倒数第二参数为间隔时间,单位为毫秒





        ////// 定义Notication的各种属性
        ////long when = System.currentTimeMillis();
        ////Notification noti = new Notification( R.drawable.ic_launcher, "神奇小精灵", when + 10000 );
        ////noti.flags = Notification.FLAG_INSISTENT;

        //// 创建一个通知
        //Notification mNotification = new Notification();

        //// 设置属性值
        //mNotification.icon = R.drawable.ic_launcher;
        //mNotification.tickerText = "NotificationTest";
        //mNotification.when = System.currentTimeMillis() + 20000; // 立即发生此通知

        //// 带参数的构造函数,属性值如上
        //// Notification mNotification = = new Notification(R.drawable.icon,"NotificationTest", System.currentTimeMillis()));

        //// 添加声音效果
        //mNotification.defaults |= Notification.DEFAULT_SOUND;

        //// 添加震动,后来得知需要添加震动权限 : Virbate Permission
        ////mNotification.defaults |= Notification.DEFAULT_VIBRATE ;

        ////添加状态标志

        ////FLAG_AUTO_CANCEL          该通知能被状态栏的清除按钮给清除掉
        ////FLAG_NO_CLEAR             该通知能被状态栏的清除按钮给清除掉
        ////FLAG_ONGOING_EVENT      通知放置在正在运行
        ////FLAG_INSISTENT             通知的音乐效果一直播放
        //mNotification.flags = Notification.FLAG_INSISTENT ;

        ////将该通知显示为默认View
        //PendingIntent contentIntent = PendingIntent.getActivity( app, 0, new Intent( "android.settings.SETTINGS" ), 0 );
        //mNotification.setLatestEventInfo( app, "通知类型：默认View", "一般般哟。。。。", contentIntent );

        //// 设置setLatestEventInfo方法,如果不设置会App报错异常
        //NotificationManager mNotificationManager = (NotificationManager)app.getSystemService( Context.NOTIFICATION_SERVICE );

        ////注册此通知
        //// 如果该NOTIFICATION_ID的通知已存在，会显示最新通知的相关信息 ，比如tickerText 等
        //mNotificationManager.notify( 2, mNotification );

        Message msg = new Message();
        msg.what = PushService.ADD_NOTIFICATION;
        Bundle b = msg.getData();
        b.putString( "nDaysLater", nDaysLater );
        b.putString( "nHour", nHour );
        b.putString( "nMinute", nMinute );
        b.putString( "nSecond", nSecond );
        b.putString( "szContent", szContent );
        b.putString( "key", key );
        b.putString( "nType", nType );

        PushService.notification_handler.sendMessage( msg );
    }

    public static void releaseLocalNotification(String key) {
        Message msg = new Message();
        msg.what = PushService.REMOVE_NOTIFICATION;
        Bundle b = msg.getData();
        b.putString("key", key);

        PushService.notification_handler.sendMessage( msg );
    }

    public static void releaseAllLocalNotification() {
        Message msg = new Message();
        msg.what = PushService.REMOVE_ALL_NOTIFICATION;

        PushService.notification_handler.sendMessage( msg );
    }

    public static void unZipFile(String fullFileName) {
        Message msg = new Message();
        msg.what = UNZIP_FILE;
        Bundle b = msg.getData();
        b.putString("fullFileName", fullFileName);
        handler.sendMessage(msg);
    }

    public void doUnZipFile(Bundle b) {

    }

    public static void sdkInit() {
        Message msg = new Message();
        msg.what = SDK_INIT;
        handler.sendMessage(msg);
    }

    public void doSdkInit() {

    }

    public static String getLocalMacAddress()
    {
        String str = "";
        try{
            WifiManager wifi = (WifiManager) app.getApplicationContext().getSystemService(Context.WIFI_SERVICE);
            WifiInfo info = wifi.getConnectionInfo();
            str = info.getMacAddress();
        }catch(Exception e){
            //Log.v("getLocalMacAddress", "Exception e: " + e);
        }

        return str;
    }

    public static void closeCustomKeyBoard(){
        if (handler!=null)
        {
            Message msg = new Message();
            msg.what = CLOSE_CUSTOM_KEYBOARD;
            handler.sendMessage(msg);
        }

    }

    public static void openCustomKeyBoard(String talkStr,String placeHolderStr, String maxLength, String inputFlag){
        if (handler!=null)
        {
            Message msg = new Message();
            msg.what = OPEN_CUSTOM_KEYBOARD;
            Bundle b = msg.getData();
            b.putString("talkStr", talkStr);
            b.putString("placeHolderStr", placeHolderStr);
            b.putString("maxLength", maxLength);
            b.putString("inputFlag", inputFlag);
            handler.sendMessage(msg);
        }

    }

    public static String querySDKFeature() {
        try {
            JSONObject result = new JSONObject();
            result.put("login", GameProxy.getInstance().supportLogin());
            result.put("community", GameProxy.getInstance().supportCommunity());
            result.put("pay", GameProxy.getInstance().supportPay());
            result.put("logout", GameProxy.getInstance().supportLogout());
            return result.toString();
        } catch (JSONException e) {
            return "{}";
        }
    }

    public static void enterPlatform() {
        if (app != null) {
            app.runOnUiThread(new Runnable() {
                public void run() {
                    GameProxy.getInstance().openCommunity(app);
                }
            });
        }
    }

    public void doCloseCustomKeyBoard() {
        if( edit_dialog != null )
        {
            try {
                edit_dialog.dismiss();
            } catch (Exception e) {
                e.printStackTrace();
            }
            edit_dialog = null;
        }
    }

    public void doOpenCustomKeyBoard(Bundle b) {
        String talkStr = b.getString("talkStr");
    	String placeHolderStr = b.getString("placeHolderStr");
    	String maxLength = b.getString("maxLength");
    	String inputFlag = b.getString("inputFlag");

    	Log.i("LLL", "onClick............");
    	Log.i("LLL", "placeHolderStr............"+ placeHolderStr);
    	Log.i("LLL", "maxLength............"+ maxLength);
    	Log.i("LLL", "inputFlag............"+ inputFlag);
    	final Dialog dialog = new Dialog(this, android.R.style.Theme_Translucent_NoTitleBar_Fullscreen);
        edit_dialog = dialog;
    	dialog.setContentView(R.layout.dialog);
    	dialog.getWindow().setSoftInputMode(WindowManager.LayoutParams.SOFT_INPUT_STATE_VISIBLE) ;

    	dialog.show();

    	dialog.findViewById(R.id.talk_dialog).setOnTouchListener(new OnTouchListener() {

			@Override
			public boolean onTouch(View view, MotionEvent event) {
	     		dialog.dismiss();
                edit_dialog = null;
				return false;
			}
    	});
		edit_talk = (EditText) dialog.findViewById(R.id.edit_talk);
		if ("1".endsWith(inputFlag)) {
			edit_talk.setTransformationMethod(PasswordTransformationMethod
					.getInstance());
		}
		edit_talk.setText(talkStr);
		edit_talk.setSelection(edit_talk.getText().length());

		edit_talk.addTextChangedListener(new TextWatcher() {
			public void afterTextChanged(Editable s) {
				try {
					String temp = s.toString();
					// String tem = temp.substring(temp.length()-1,
					// temp.length());
					// char[] temC = tem.toCharArray();
					// int mid = temC[0];

					int temp_utf8_length = temp.getBytes("UTF-8").length;

					if (sdk.checkTalkStr(temp, temp_utf8_length)) {
						Log.i("LLL", "checkTalkStr...........is true");
						String current_talk = edit_talk.getText().toString();
						Log.i("LLL", "btn_confirm ..........current_talk: "
								+ current_talk);
						sdk.sendTalkStr(current_talk);
						return;
					}

					Log.i("LLL", "checkTalkStr...........is false");

					s.delete(temp.length() - 1, temp.length());

					//
				} catch (Exception e) {

				}
			}

			public void beforeTextChanged(CharSequence s, int start, int count,
					int after) {
			}

			public void onTextChanged(CharSequence s, int start, int before,
					int count) {

			}

		});

		edit_talk.setOnKeyListener(new OnKeyListener() {
			@Override
			public boolean onKey(View v, int keyCode, KeyEvent event) {

				if (keyCode == KeyEvent.KEYCODE_ENTER){
		     		dialog.dismiss();
                    edit_dialog = null;

			    	return true;
				}

				return false;
			}

		});
    }


    @Override
    protected void onStart() {
        super.onStart();
        GameProxy.getInstance().onStart(this);
    }

    @Override
    protected void onStop() {
        super.onStop();
        GameProxy.getInstance().onStop(this);
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        try {
            unregisterReceiver(connChangeReceiver);
        } catch (IllegalArgumentException e) {
            e.printStackTrace();
        }
        releaseWakeLock();
        GameProxy.getInstance().onDestroy(this);
        GameProxy.getInstance().applicationDestroy(this);
    }

    @Override
	public void onAttachedToWindow() {
		super.onAttachedToWindow();
        GameProxy.getInstance().onAttachedToWindow(this);
    }

    @Override
	public void onDetachedFromWindow() {
		super.onDetachedFromWindow();
        GameProxy.getInstance().onDetachedFromWindow(this);
    }

    @Override
    protected void onResume() {
        setImmersionMode();
        super.onResume();
        GameProxy.getInstance().onResume(this);
        UMGameAgent.onResume(this);
    }

    @Override
    protected void onPause() {
        super.onPause();
        GameProxy.getInstance().onPause(this);
        UMGameAgent.onPause(this);
    }

    @Override
    protected void onRestart() {
        super.onRestart();
        GameProxy.getInstance().onRestart(this);
    }

    @Override
    protected void onNewIntent(Intent intent) {
        super.onNewIntent(intent);
        GameProxy.getInstance().onNewIntent(this, intent);
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        GameProxy.getInstance().onActivityResult(this, requestCode, resultCode, data);
    }

    public static String getAvailMemory()
    {
        ActivityManager am = (ActivityManager)app.getApplicationContext().getSystemService( Context.ACTIVITY_SERVICE );
        MemoryInfo mi = new MemoryInfo();
        am.getMemoryInfo( mi );
        Float f = Float.parseFloat( String.valueOf( mi.availMem ) ) / 1024.0f / 1024.0f;
        //return Formatter.formatFileSize( app.getBaseContext(), mi.availMem );
        //return Long.toString( mi.availMem );
        return Float.toString( f );
    }

    public static String getNetworkType()
    {
        ConnectivityManager connectMgr = (ConnectivityManager)app.getApplicationContext().getSystemService( Context.CONNECTIVITY_SERVICE );
        NetworkInfo info = connectMgr.getActiveNetworkInfo();
        if( info == null )
            return "";

        // WIFI
        if( info.getType() == ConnectivityManager.TYPE_WIFI )
        {
            WifiManager wifi = (WifiManager)app.getApplicationContext().getSystemService( Context.WIFI_SERVICE );
            WifiInfo wifi_info = wifi.getConnectionInfo();
            String ssid = wifi_info.getSSID();

            return "WIFI-" + ssid;
        }

        // MOBILE
        int nSubType = info.getSubtype();
        return "MOBILE-" + nSubType;
    }
}

