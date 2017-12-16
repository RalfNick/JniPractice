package com.example.ralf.cmake;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.text.TextUtils;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

public class JniActivity extends AppCompatActivity {

    static {
        System.loadLibrary("MyJni");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        ToastUtil.register(this);
        setContentView(R.layout.java_call_native_layout);

        final TextView textView = findViewById(R.id.show_text_view);

        final EditText editText = findViewById(R.id.text_edit);

        Button getFromJniButton = findViewById(R.id.get_from_jni_button);
        getFromJniButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String content = editText.getText().toString();
                if (!TextUtils.isEmpty(content)){
                    textView.setText(getContentFromJni(content));
                }
                else {
                    Toast.makeText(JniActivity.this,"请输入内容",Toast.LENGTH_SHORT).show();
                }
            }
        });

        Button callJavaMethodButton = findViewById(R.id.jni_call_java_button);
        callJavaMethodButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String content = editText.getText().toString();
                if (!TextUtils.isEmpty(content)){
                    textView.setText(callJavaMethod(content));
                }
                else {
                    Toast.makeText(JniActivity.this,"请输入内容",Toast.LENGTH_SHORT).show();
                }
            }
        });

        Button callJavaStaticMethodButton = findViewById(R.id.jni_call_java_static_button);
        callJavaStaticMethodButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String content = editText.getText().toString();
                if (!TextUtils.isEmpty(content)){
                    textView.setText(callJavaStaticMethod(content));
                }
                else {
                    String str = TestClass.javaStaticMethod();
                    Toast.makeText(JniActivity.this,"请输入内容",Toast.LENGTH_SHORT).show();
                }
            }
        });
    }

    public native String getContentFromJni(String content);
    public native String callJavaMethod(String content);
    public native String callJavaStaticMethod(String content);

}
