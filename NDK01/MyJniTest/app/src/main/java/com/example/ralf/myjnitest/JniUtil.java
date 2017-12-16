package com.example.ralf.myjnitest;

/**
 * 作者：Ralf on 2017/11/30 14:59
 * 邮箱：wang_lxin@163.com
 * desc：
 */

public class JniUtil {

    static {
        System.loadLibrary("myjni");
    }

    public static native String getStrFromJni();
}
