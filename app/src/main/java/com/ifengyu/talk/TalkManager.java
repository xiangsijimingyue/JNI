package com.ifengyu.talk;


import android.os.Build;
import android.util.Log;

public class TalkManager {

    static {
        String TAG = "FyManager";
        System.loadLibrary("talk");
        Log.i(TAG, "JNI loadLibrary");
    }

    // 单例模式
    private static TalkManager instance = new TalkManager();

    public static TalkManager getInstance() {
        return instance;
    }


    /************************ 异步事件通知监听方法 ************************/

    // 全局回调引用
    //private static NetworkEventCallback sNetWorkCallback = null;


    /************************ 初始化SDK ************************/

//    public int initWithServer(String address, int port, FyLogLevel level, NetworkEventCallback networkEventCallback) {
//        // TODO 其他空异常判断
//
//        sNetWorkCallback = networkEventCallback;
//
//        NetworkConfig config = new NetworkConfig();
//        config.setSignalling_server_ip(address);
//        config.setSignalling_port(port);
//        config.setHeartbeat_interval(30000);
//        config.setHeartbeat_timeout(90000);
//
//        return network_init(config, networkEventCallback);
//    }
    public void release() {

    }

    /************************ 登录/注销 ************************/

//    public FyResult loginPocServerWithUsername(String username, String password) {
//
//        // TODO 其他空异常判断
//        UserInfo userInfo = new UserInfo();
//        userInfo.setUsername(username);
//        userInfo.setPassword(password);
//        userInfo.setOs_type("android");
//        userInfo.setBrand(Build.BRAND);
//        userInfo.setDevice_id("");
//        userInfo.setModel(Build.MODEL);
//        userInfo.setOs_version(Build.VERSION.RELEASE);
//
//        return sdk_login(userInfo);
//    }

//    public FyResult loginPocServerWithToken(String token) {
//
//        // TODO 其他空异常判断
//        UserInfo userInfo = new UserInfo();
//        userInfo.setToken(token);
//        return sdk_login(userInfo);
//    }
//
//    public FyResult logoutService() {
//
//        return sdk_logout();
//    }

    /************************ 群组操作 ************************/


    /************************ 供 JNI 调用的回调分发方法 处理CallBack ************************/
//    private static void dispatchEvent(int eventType, byte[] data, long time) {
//        if (sNetWorkCallback != null) {
//            sNetWorkCallback.onEvent(eventType, data, time);
//        }
//    }


    /************************ Native 方法声明 ************************/

    public native String stringFromJNI();

    /**
     * A native method that is implemented by the 'talk' native library,
     * which is packaged with this application.
     */
//    public static native String stringFromJNI();

//    private static native int network_init(NetworkConfig config, NetworkEventCallback callback);
//
//
//    private static native FyResult sdk_login(UserInfo userInfo);
//
//
//    private static native FyResult sdk_logout();


}
