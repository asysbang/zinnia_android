package com.asysbang.myapplication;

import androidx.appcompat.app.AppCompatActivity;
import android.content.res.AssetManager;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;

public class MainActivity extends AppCompatActivity implements View.OnClickListener, MyView.Listener {

    private Button mRecognize, mClear;

    private MyView mMyView;
    private TextView mResultView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mMyView = findViewById(R.id.my_view);
        mMyView.setListener(this);
        mRecognize = findViewById(R.id.recognize);
        mRecognize.setOnClickListener(this);
        mClear= findViewById(R.id.clear);
        mClear.setOnClickListener(this);

        mResultView = findViewById(R.id.result);

        File appFile = new File(getFilesDir(), "handwriting-zh_CN.model");
        if (!appFile.exists()) {
            AssetManager am =getAssets();
            try {
                InputStream open = am.open("handwriting-zh_CN.model");
                FileOutputStream fos = new FileOutputStream(appFile);
                byte[] buf = new byte[2048];
                int count =-1;
                while ( (count = open.read(buf))  != -1){
                    fos.write(buf,0,count);
                }
                fos.flush();
                fos.close();
                open.close();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }else {
            Log.e("","====exist");
        }
        Log.e("","===="+appFile.getAbsolutePath());
//        ZinniaHelper helper = new ZinniaHelper();
//        helper.testZinnia();
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

        }
    }

    private void clear() {
        mMyView.clear();
    }

    private void recognize() {
        mMyView.getResult();
    }

    @Override
    public void onResults(String[] results) {
        StringBuilder sb = new StringBuilder();
        for (String str : results) {
            sb.append(str);
            sb.append(" , ");
        }
        mResultView.setText(sb.toString());
    }
}