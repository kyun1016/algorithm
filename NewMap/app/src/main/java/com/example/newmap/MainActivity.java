package com.example.newmap;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    //클릭시 이동을 하도록 onclick을 구현해주었다.
    public void moveMaps(View view) {
        startActivity(new Intent(this, MapsActivity.class));
    }

    public void moveMarkerAdd(View view) {
        startActivity(new Intent(this, MarkerAddActivity.class));
    }

    public void moveMarkerList(View view) {
        startActivity(new Intent(this, MarkerListActivity.class));
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.main_menu, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(@NonNull MenuItem item) {
        switch (item.getItemId()){
            case R.id.action_menu_1:
                Toast.makeText(this, "첫 번째 메뉴", Toast.LENGTH_SHORT).show();
                startActivity(new Intent(this, MarkerAddActivity.class));
                return true;
            case R.id.action_menu_2:
                Toast.makeText(this, "두 번째 메뉴", Toast.LENGTH_SHORT).show();
                return true;
        }

        return super.onOptionsItemSelected(item);
    }


}
