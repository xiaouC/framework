package org.weilan;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.net.ConnectivityManager;
import android.net.NetworkInfo;
import android.util.Log;

public class ConnectionChangeReceiver extends BroadcastReceiver {
    private final static int CB_REACHABILITY_CHANGED     = 10;
    @Override
    public void onReceive( Context context, Intent intent ) {
        ConnectivityManager connectMgr = (ConnectivityManager)context.getSystemService( Context.CONNECTIVITY_SERVICE );
        NetworkInfo info = connectMgr.getActiveNetworkInfo();
        if( info != null )
        {
            if( info.getType() == ConnectivityManager.TYPE_WIFI )
                sdk.platformCallback( CB_REACHABILITY_CHANGED, "WIFI" );
            else
                sdk.platformCallback( CB_REACHABILITY_CHANGED, "MOBILE" );
        }
        else
        {
            sdk.platformCallback( CB_REACHABILITY_CHANGED, "" );
        }
    }
}

/*
switch( info.getType() )
{
    case ConnectivityManager.TYPE_MOBILE:
        {
            switch( info.getSubtype() )
            {
                case NETWORK_TYPE_CDMA:
                    {
                        json.put( "type", "2G" );       // 电信 2G
                    }
                case NETWORK_TYPE_EDGE:
                    {
                        json.put( "type", "2G" );       // 移动和联通 2G
                    }
                case NETWORK_TYPE_EVDO_0:
                    {
                        json.put( "type", "3G" );       // 电信 3G
                    }
                case NETWORK_TYPE_EVDO_A:
                    {
                        json.put( "type", "3G" );       // 电信 3G
                    }
                case NETWORK_TYPE_GPRS:
                    {
                        json.put( "type", "2G" );       // 移动和联通 2G
                    }
                case NETWORK_TYPE_HSDPA:
                    {
                        json.put( "type", "3G" );       // 联通 3G
                    }
                case NETWORK_TYPE_HSPA:
                    {
                    }
                case NETWORK_TYPE_HSUPA:
                    {
                    }
                case NETWORK_TYPE_UMTS:
                    {
                        json.put( "type", "3G" );       // 联通 3G
                    }
                default:
                    {
                    }
            }
        }
    default:
        {
            json.put( "type", "WIFI" );
        }
}
*/
