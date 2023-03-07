package com.asysbang.zinnia;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;
import androidx.core.content.ContextCompat;

import android.Manifest;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;

import java.io.File;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    private ZinniaHelper mZinniaHelper;

    private Button mRecognize, mClear;


    private MyView mMyView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mMyView= findViewById(R.id.my_view);
        mRecognize = findViewById(R.id.recognize);
        mRecognize.setOnClickListener(this);
        mClear = findViewById(R.id.clear);
        mClear.setOnClickListener(this);
//        File f = new File("/sdcard/handwriting-zh_CN.model");
//        Log.e("", "======" + f.exists());
//        requestPermission();
//        mZinniaHelper = new ZinniaHelper();
//        Log.e("", "========" + mZinniaHelper.stringFromJNI());
//        mZinniaHelper.createRecognizer();
//        mZinniaHelper.addCharacterTest();
//        mZinniaHelper.getResult();
//        Log.e("","===============new add ");
//        mZinniaHelper.addCharacterTest1();
//        mZinniaHelper.getResult();
//        mZinniaHelper.destroyRecognizer();
    }

    private void requestPermission() {
        if (ContextCompat.checkSelfPermission(this, Manifest.permission.READ_EXTERNAL_STORAGE) != PackageManager.PERMISSION_GRANTED) {
            ActivityCompat.requestPermissions(this, new String[]{Manifest.permission.WRITE_EXTERNAL_STORAGE, Manifest.permission.READ_EXTERNAL_STORAGE}, 9);
            Log.e("", "==========requestPermission");
        } else {
            Log.e("", "==========requestPermission ok");
        }
    }

    @Override
    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults);
        Log.e("", "==========onRequestPermissionsResult");
    }

    @Override
    public void onClick(View view) {
        int id = view.getId();
        switch (id) {
            case R.id.recognize:
                recognize();
                break;
            case R.id.clear:
                clear();
                break;
            default:
                break;
        }
    }

    private void clear() {
        mMyView.clear();
    }

    private void recognize() {
        mMyView.getResult();
    }
}