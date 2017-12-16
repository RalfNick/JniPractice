package com.example.ralf.cmake;

import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity{

    static {
        System.loadLibrary("native-lib");
    }

    private native int resultFromJNI();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        final TextView addTextView = findViewById(R.id.add_text);
        Button button = findViewById(R.id.button);

        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                addTextView.setText("相加结果为：" + resultFromJNI());
            }
        });

        Button nextJni = findViewById(R.id.next_jni_button);
        nextJni.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(MainActivity.this,JniActivity.class);
                startActivity(intent);
            }
        });
    }

}
