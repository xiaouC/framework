package org.weilan;

import android.content.Intent;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.app.Notification;
import android.app.NotificationManager;
import android.app.PendingIntent;

public class AlarmReceiver extends BroadcastReceiver
{
    @Override
    public void onReceive( Context context, Intent intent )
    {
        // 创建一个通知  
        Notification mNotification = new Notification();  

        // 设置属性值  
        mNotification.icon = R.drawable.ic_launcher;  
        mNotification.tickerText = "NotificationTest";  
        mNotification.when = System.currentTimeMillis();

        // 添加声音效果  
        mNotification.defaults |= Notification.DEFAULT_SOUND;  

        // 添加震动,后来得知需要添加震动权限 : Virbate Permission  
        //mNotification.defaults |= Notification.DEFAULT_VIBRATE ;   

        //添加状态标志   

        //FLAG_AUTO_CANCEL          该通知能被状态栏的清除按钮给清除掉  
        //FLAG_NO_CLEAR             该通知能被状态栏的清除按钮给清除掉  
        //FLAG_ONGOING_EVENT      通知放置在正在运行  
        //FLAG_INSISTENT             通知的音乐效果一直播放  
        mNotification.flags = Notification.FLAG_INSISTENT;  

        //将该通知显示为默认View  
        PendingIntent contentIntent = PendingIntent.getActivity( context, 0, new Intent( "android.settings.SETTINGS" ), 0 );
        mNotification.setLatestEventInfo( context, "通知类型：默认View", "一般般哟。。。。", contentIntent );  

        // 设置setLatestEventInfo方法,如果不设置会App报错异常  
        NotificationManager mNotificationManager = (NotificationManager)context.getSystemService( Context.NOTIFICATION_SERVICE );

        //注册此通知   
        // 如果该NOTIFICATION_ID的通知已存在，会显示最新通知的相关信息 ，比如tickerText 等  
        mNotificationManager.notify( 2, mNotification );  
    }
}
