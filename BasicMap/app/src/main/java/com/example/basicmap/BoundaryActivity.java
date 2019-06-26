package com.example.basicmap;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Toast;

public class BoundaryActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_boundary);
    }

    public void moveMapsActivity(View view){
        startActivity(new Intent(this, MainActivity.class));
    }

    public void addBoundary(View view) {
        Toast.makeText(this,"등록되었습니다",Toast.LENGTH_SHORT).show();
    }
}
