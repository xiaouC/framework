package org.weilan;

import android.app.Activity;
import android.content.pm.ActivityInfo;
import android.media.MediaPlayer;
import android.net.Uri;
import android.os.Bundle;
import android.view.Window;
import android.view.WindowManager;
import android.widget.MediaController;
import android.widget.VideoView;
import android.content.Intent;
import android.util.Log;
import java.io.InputStream;
import java.io.FileOutputStream;
import java.io.File;

public class VideoActivity extends Activity {
    @Override
    protected void onCreate( Bundle savedInstanceState ) {
        super.onCreate( savedInstanceState );

        requestWindowFeature( Window.FEATURE_NO_TITLE );

        getWindow().setFlags( WindowManager.LayoutParams.FLAG_FULLSCREEN, WindowManager.LayoutParams.FLAG_FULLSCREEN );
        getWindow().addFlags( WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON );

        //setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_LANDSCAPE);//强制为横屏

        setContentView( R.layout.videoview );

        // 
        Intent i = getIntent(); 
        String path = i.getStringExtra( "video_path" );  
        Log.i( "cocos", "path : " + path );

        final VideoView videoView = (VideoView)findViewById( R.id.VideoView01 );
        //videoView.setVideoURI( Uri.parse( "android.resource://" + getPackageName() + "/" + R.raw.cg ) );
        videoView.start();

        // 视频播控制条设置 
        MediaController controller = new MediaController( VideoActivity.this );
        videoView.setMediaController( controller );
        // 播放完成监听 
        videoView.setOnCompletionListener( new MediaPlayer.OnCompletionListener() {
            @Override
            public void onCompletion( MediaPlayer mp ) {
                //播放结束后的动作,返回点击播放视频的那个页面
                finish();
            }
        });
    }
}
