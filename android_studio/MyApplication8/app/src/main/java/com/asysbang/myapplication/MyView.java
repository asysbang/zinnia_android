package com.asysbang.myapplication;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Path;
import android.os.Handler;
import android.os.Looper;
import android.os.Message;
import android.util.AttributeSet;
import android.util.Log;
import android.view.MotionEvent;
import android.view.View;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

public class MyView extends View {

    private Paint mPaint;
    private Bitmap mBitmap;
    private Canvas mCanvas;
    private Path mPath;
    private Paint mBitmapPaint;

    private int mIndex = 0;

    private Listener mListener;

    public void getResult() {
        if (mIndex == 0 ) {
            return;
        }
        mHandler.removeMessages(MSG_GET_RESULTS);
        Log.e("","==============getResult========");
        String[] results = mZinniaHelper.getResults();
        Log.e("","==============getResult========"+results.length);
        if (mListener!=null) {
            mListener.onResults(results);
        }
        mIndex = 0;
    }

    public void setListener(Listener listener) {
        mListener = listener;
    }

    public interface Listener {
        public void onResults(String[] results);
    }

    public void clear() {
        mBitmap.eraseColor(0xFFAAAAAA);
        mCanvas = new Canvas(mBitmap);
        invalidate();
        mIndex= 0;
    }

    private  Handler mHandler = new  Handler(Looper.myLooper()){
        @Override
        public void handleMessage(@NonNull Message msg) {
            if(MSG_GET_RESULTS == msg.what) {
                Log.e("","=======MSG_GET_RESULTS");
                getResult();
            }
        }
    };

    private ZinniaHelper mZinniaHelper;
    public MyView(Context context, @Nullable AttributeSet attrs) {
        super(context, attrs);
        setBackgroundColor(Color.BLUE);
        mZinniaHelper = new ZinniaHelper();
        mZinniaHelper.createRecognizer();
        mPath = new Path();
        mBitmapPaint = new Paint(Paint.DITHER_FLAG);
        mPaint = new Paint();
        mPaint.setAntiAlias(true);
        mPaint.setDither(true);
        mPaint.setColor(0xFFFF0000);
        mPaint.setStyle(Paint.Style.STROKE);
        mPaint.setStrokeJoin(Paint.Join.ROUND);
        mPaint.setStrokeCap(Paint.Cap.ROUND);
        mPaint.setStrokeWidth(6);
    }

    @Override
    protected void onSizeChanged(int w, int h, int oldw, int oldh) {
        super.onSizeChanged(w, h, oldw, oldh);
        mBitmap = Bitmap.createBitmap(w, h, Bitmap.Config.ARGB_8888);
        mCanvas = new Canvas(mBitmap);
    }

    private float mX, mY;
    private static final float TOUCH_TOLERANCE = 5;

    private static final int MSG_GET_RESULTS =1001;

    private void touch_start(float x, float y) {
        mHandler.removeMessages(MSG_GET_RESULTS);
        mPath.reset();
        mPath.moveTo(x, y);
        mX = x;
        mY = y;
        //zinnia_character_add(character, 0,87,45);
        mZinniaHelper.addCharacter(mIndex,(int)x,(int)y);
        //Log.e("","zinnia_character_add(character,"+mIndex+","+(int)x+","+(int)y+");");
    }

    private void touch_move(float x, float y) {
        float dx = Math.abs(x - mX);
        float dy = Math.abs(y - mY);
        if (dx >= TOUCH_TOLERANCE || dy >= TOUCH_TOLERANCE) {
            mPath.quadTo(mX, mY, (x + mX) / 2, (y + mY) / 2);
            mX = x;
            mY = y;
            mZinniaHelper.addCharacter(mIndex,(int)x,(int)y);
            //Log.e("","zinnia_character_add(character,"+mIndex+","+(int)x+","+(int)y+");");
        }
    }

    private void touch_up(float x, float y) {
        //Log.e("","zinnia_character_add(character,"+mIndex+","+(int)x+","+(int)y+");");
        mPath.lineTo(mX, mY);
        // commit the path to our offscreen
        mCanvas.drawPath(mPath, mPaint);
        // kill this so we don't double draw
        mPath.reset();
        mIndex++;
        mHandler.sendEmptyMessageDelayed(MSG_GET_RESULTS,1000);
    }

    @Override
    protected void onDraw(Canvas canvas) {
        canvas.drawColor(0xFFAAAAAA);
        canvas.drawBitmap(mBitmap, 0, 0, mBitmapPaint);
        canvas.drawPath(mPath, mPaint);
    }

    @Override
    public boolean onTouchEvent(MotionEvent event) {
        float x = event.getX();
        float y = event.getY();
        switch (event.getAction()) {
            case MotionEvent.ACTION_DOWN:
                touch_start(x, y);
                invalidate();
                break;
            case MotionEvent.ACTION_MOVE:
                touch_move(x, y);
                invalidate();
                break;
            case MotionEvent.ACTION_UP:
                touch_up(x,y);
                invalidate();
                break;
        }
        return true;
    }
}
