package com.asysbang.myapplication;

public class ZinniaHelper {

    static {
        System.loadLibrary("myapplication");
    }

    public String[] getResultsWithCallback() {
        return null;
    }


    public native int testZinnia();


    public native int destroyRecognizer();
    public native int getResult();

    public native String[] getResults();

    public native int createRecognizer() ;

    public native int addCharacter(int mIndex, int x, int y) ;
}
