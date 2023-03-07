package com.asysbang.zinnia;

public class ZinniaHelper {

    static {
        System.loadLibrary("zinnia");
    }

    /**
     * A native method that is implemented by the 'zinnia' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    public native int createRecognizer();

    public native int destroyRecognizer();

    public native int addCharacterTest();
    public native int addCharacterTest1();

public native int getResult();

    public native void addCharacter(int index, int xPoi,int yPoi);
}
