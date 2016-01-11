package org.weilan;

import org.weilan.poem;
import android.content.Intent;
import android.os.Bundle;
import android.widget.Toast;
import android.util.Log;
import android.os.IBinder;
import android.app.Service;
import android.app.Notification;
import android.app.NotificationManager;
import java.text.SimpleDateFormat;
import android.app.PendingIntent;
import java.util.List;
import java.util.Map;
import java.util.HashMap;
import java.util.Calendar;
import java.util.Date;
import java.lang.Integer;
import java.util.Iterator;
import java.io.UnsupportedEncodingException;
import java.io.FileOutputStream;
import java.io.FileInputStream;
import java.io.ByteArrayOutputStream;
import android.os.Handler;
import android.os.Handler.Callback;
import android.os.HandlerThread;
import android.os.Looper;
import android.os.Message;
import android.app.ActivityManager;
import android.app.ActivityManager.RunningTaskInfo;
import android.content.IntentFilter;
import android.content.Context;
import android.content.SharedPreferences;

public class PushService extends Service {
    private final static String notification_file_name = "notification.gson";

    private int notificationID = 1000;

    private PendingIntent messagePendingIntent = null;

    private static String gameName;

    private static Map<String,Notice> noticeMap = new HashMap<String,Notice>();

    public final static int ADD_NOTIFICATION = 1;
    public final static int REMOVE_NOTIFICATION = 2;
    public final static int REMOVE_ALL_NOTIFICATION = 3;
    public static Handler notification_handler;

    @Override
    public IBinder onBind( Intent arg0 ) {
        Log.v( "notification", "onBind" );
        return null;
    }

    @Override
    public void onCreate() {
        super.onCreate();

        gameName = this.getString( R.string.app_name );

        Intent messageIntent = new Intent( PushService.this, poem.class );
        messagePendingIntent = PendingIntent.getActivity( PushService.this, 0, messageIntent, PendingIntent.FLAG_UPDATE_CURRENT );
        Log.v( "notification", "onCreate" );

        // 再次动态注册广播
        IntentFilter localIntentFilter = new IntentFilter( "android.intent.action.USER_PRESENT" );
        localIntentFilter.setPriority( Integer.MAX_VALUE );
        PushReceiver searchReceiver = new PushReceiver();
        registerReceiver( searchReceiver, localIntentFilter );

        loadSharedPreferences();

        HandlerThread handlerThread = new HandlerThread( "threadone" );
        handlerThread.start();

        notification_handler = new Handler( handlerThread.getLooper(), new Callback() {
            @Override
            public boolean handleMessage( Message msg ) {
                Bundle bb = msg.getData();
                switch( msg.what ) {
                    case ADD_NOTIFICATION : {
                       String nDaysLater = bb.getString( "nDaysLater" );
                       String nHour = bb.getString( "nHour" );
                       String nMinute = bb.getString( "nMinute" );
                       String nSecond = bb.getString( "nSecond" );
                       String szContent = bb.getString( "szContent" );
                       String key = bb.getString( "key" );
                       String nType = bb.getString( "nType" );

                       String date = "";
                       if( nType.equals( "EveryDay" ) ) {      //每日通知存儲時間格式HH:mm:ss
                           date = nHour + ":" + nMinute + ":" + nSecond;
                       } else if( nType.equals( "Once" ) ) {   //事件通知存儲時間格式yyyy-MM-dd HH:mm:ss
                           Calendar cal = Calendar.getInstance();
                           cal.add( Calendar.DAY_OF_MONTH, Integer.parseInt( nDaysLater ) );
                           String date_prefix = new SimpleDateFormat( "yyyy-MM-dd" ).format( cal.getTime() );

                           date = date_prefix + " " + nHour + ":" + nMinute + ":" + nSecond;
                       }

                       Notice notice = new Notice( date, szContent, nType );
                       noticeMap.put( key, notice );

                       saveSharedPreferences();
                    }
                    break;
                    case REMOVE_NOTIFICATION : {
                       String delKey = bb.getString( "key" );
                       Notice notice = noticeMap.get( delKey );
                       if( notice != null ) {
                           noticeMap.remove( delKey );
                       }

                       saveSharedPreferences();
                    }
                    break;
                    case REMOVE_ALL_NOTIFICATION : {
                       noticeMap.clear();

                       saveSharedPreferences();
                    }
                    break;
                }

                return true;
            }
        });
        notification_handler.post( new Runnable() {
            @Override
            public void run() {
                Log.v( "notification", "run ++++++++++++++++++++++++++++++++=" );
                try {
                    String msg = getServerMessage();
                    if( msg != null && !"".equals( msg ) ) {
                        if( !isMainActivityRunning() ) {
                            Notification noti = new Notification.Builder( PushService.this )
                                .setContentTitle( gameName )
                                .setContentText( msg )
                                .setSmallIcon( R.drawable.ic_launcher )
                                .setContentIntent( messagePendingIntent )
                                //.setLargeIcon( R.drawable.ic_launcher )
                                .setAutoCancel( true )
                                .build();

                            NotificationManager notificationManager = (NotificationManager)getSystemService( PushService.this.NOTIFICATION_SERVICE );
                            notificationManager.notify( notificationID, noti );
                            notificationID++;
                        }
                    }
                } catch ( Exception e ) {
                    e.printStackTrace();
                }

                notification_handler.postDelayed( this, 1000 );
            }
        });
    }

    @Override
    public void onDestroy() {
        super.onDestroy();
        Log.v( "notification", "onDestroy" );

        Intent localIntent = new Intent();
        localIntent.setClass( this, PushService.class ); // 销毁时重新启动Service
        this.startService( localIntent );
    }

    @Override
    public void onStart( Intent intent, int startId ) {
        Log.v( "notification", "onStart1" );
        super.onStart( intent, startId );
    }

    @Override
    public int onStartCommand( Intent intent, int flags, int startId ) {
        flags = START_STICKY;
        return super.onStartCommand( intent, flags, startId );
    }

    public String getServerMessage() {
        Date date = new Date();
        for( Map.Entry<String,Notice> item_entry : noticeMap.entrySet() ) {
            Notice notice = item_entry.getValue();

            if( notice.checkDateTime( date ) ) {
                notice.setStatus( false );
                String ret = notice.getContent();
                saveSharedPreferences();
                return ret;
            }
        }

        return "";
    }

    public boolean isMainActivityRunning() {
        String packageName = getPackageName();

        ActivityManager am = (ActivityManager)getSystemService( ACTIVITY_SERVICE );
        List<RunningTaskInfo> taskInfoList = am.getRunningTasks( 1 );
        if( packageName.equals( taskInfoList.get( 0 ).topActivity.getPackageName() ) ) {
            Log.v( "notification", "isMainActivityRunning : true" );
            return true;
        }

        Log.v( "notification", "isMainActivityRunning : false" );
        return false;
    }

    //
    private static String LOCAL_PREFER_NAME = "push_date";
    public void loadSharedPreferences() {
        SharedPreferences share = getSharedPreferences( LOCAL_PREFER_NAME, Context.MODE_WORLD_READABLE );

        int nKeyCount = share.getInt( "key_count", 0 );
        for( int i=1; i <= nKeyCount; ++i ) {
            String key = share.getString( String.format( "key_%d", i ), "" );
            if( !key.equals( "" ) ) {
                String date = share.getString( String.format( "%s-date", key ), "" );
                String content = share.getString( String.format( "%s-content", key ), "" );
                String nType = share.getString( String.format( "%s-nType", key ), "" );

                Notice notice = new Notice( date, content, nType );
                noticeMap.put( key, notice );
            }
        }
    }

    public void saveSharedPreferences() {
        SharedPreferences share = getSharedPreferences( LOCAL_PREFER_NAME, Context.MODE_WORLD_READABLE );
        SharedPreferences.Editor editor = share.edit();

        int nKeyCount = 0;

        for( Map.Entry<String,Notice> item_entry : noticeMap.entrySet() ) {
            String key = item_entry.getKey();
            Notice notice = item_entry.getValue();

            if( notice.getStatus() ) {
                nKeyCount = nKeyCount + 1;
                editor.putString( String.format( "key_%d", nKeyCount ), key );

                editor.putString( String.format( "%s-date", key ), notice.getDate() );
                editor.putString( String.format( "%s-content", key ), notice.getContent() );
                editor.putString( String.format( "%s-nType", key ), notice.getNType() );
            }
        }

        editor.putInt( "key_count", nKeyCount );

        editor.commit();
    }

}
