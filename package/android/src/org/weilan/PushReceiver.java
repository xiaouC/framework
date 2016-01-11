package org.weilan;

import android.content.Intent;
import android.content.BroadcastReceiver;
import android.content.Context;

public class PushReceiver extends BroadcastReceiver
{
    @Override
    public void onReceive( Context context, Intent intent )
    {
        context.startService( new Intent( context, PushService.class ) );
    }
}
