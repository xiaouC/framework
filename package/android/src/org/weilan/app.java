package org.weilan;
import android.app.Application;

public class app extends Application {

    static {
        System.loadLibrary("game");
    }

    @Override
    public void onCreate() {
        super.onCreate();
    }
}
