package org.weilan;

import java.util.Date;
import java.util.Calendar;
import java.text.SimpleDateFormat;
import android.util.Log;
import android.text.format.Time;

public class Notice
{
    private String time;
    private String date;
    private String content;
    private boolean status;
    private String nType;

    public Notice()
    {
    }

    public Notice(String date, String content, String nType)
    {
        this.content = content;
        this.status = true;
        this.nType = nType;
        if( nType.equals( "EveryDay" ) ) {
            this.time = date;
            this.date = null;
            this.checkDateTime(new Date());
        } else {
            this.date = date;
        }
    }


    public Notice(String date, String content, boolean status)
    {
        this.date = date;
        this.content = content;
        this.status = status;
    }

    public void setNType(String nType)
    {
        this.nType = nType;
    }

    public String getNType()
    {
        return nType;
    }

    public void setDate(String date)
    {
        this.date = date;
    }

    public String getDate()
    {
        return date;
    }

    public void setConent(String content)
    {
        this.content = content;
    }

    public String getContent()
    {
        return content;
    }

    public void setStatus(boolean status)
    {
        this.status = status;
    }

    public boolean getStatus()
    {
        if( nType.equals( "EveryDay" ) ) {
            return true;
        } else {
            return status;
        }
    }

    public String toString()
    {
        return "date:" + date + " content:" + content + " status:" + status + " nType:" + nType;
    }

    public boolean checkDateTime( Date cur_date ) {
        if( !status ) {
            return false;
        }

        Log.v( "notification", toString() );

        try {
            SimpleDateFormat df = new SimpleDateFormat( "yyyy-MM-dd HH:mm:ss" );

            if( nType.equals( "EveryDay" ) ) {
                if( date == null ) {
                    date = new SimpleDateFormat("yyyy-MM-dd").format(cur_date);
                }

                String date_time = String.format( "%s %s", date, time );
                Date d_notice = df.parse( date_time );

                boolean ret = cur_date.getTime() > d_notice.getTime();
                if( ret ){
                    Calendar c = Calendar.getInstance();
                    c.setTime(cur_date);
                    int day = c.get(Calendar.DATE);
                    c.set(Calendar.DATE, day + 1);
                    date = new SimpleDateFormat("yyyy-MM-dd").format(c.getTime());
                }
                return ret;
            }

            // "Once"
            Date d_notice = df.parse( date );
            return cur_date.getTime() > d_notice.getTime();
        } catch ( Exception e ) {
            return false;
        }
    }
}
