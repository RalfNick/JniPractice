package com.example.ralf.jnitest_cmake;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

class MainActivity extends AppCompatActivity{

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
    }

}
