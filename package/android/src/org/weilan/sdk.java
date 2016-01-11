package org.weilan;

public class sdk {
    public static native boolean platformCallback(int type, String args);
    public static native boolean sendTalkStr(String str);
    public static native boolean checkTalkStr(String str, int length);
}
