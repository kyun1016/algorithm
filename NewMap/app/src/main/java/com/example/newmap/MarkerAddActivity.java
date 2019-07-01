package com.example.newmap;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.content.ContentValues;
import android.content.Intent;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

public class MarkerAddActivity extends AppCompatActivity {
    //화면에 적은 글자를 활용하도록 전역변수로 선언해준다.
    private EditText mTitleEditText;
    private EditText mLatEditText;
    private EditText mLngEditText;
    private long mMemoId = -1;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_marker_add);
        //위에 선언한 변수와 layout에 존재하는 edittext를 연결해준다.
        mTitleEditText = findViewById(R.id.title_edit);
        mLatEditText = findViewById(R.id.lat_edit);
        mLngEditText = findViewById(R.id.lng_edit);

        //이부분은 db를 연동하는 부분이다.
        Intent intent = getIntent();
        if(intent != null){

            //이후에 db에 데이터를 저장하면서 관리하기 쉽게 id를 부여해준다.
            mMemoId = intent.getLongExtra("id", -1);
            String title = intent.getStringExtra("title");
            String lat = intent.getStringExtra("lat");
            String lng = intent.getStringExtra("lng");

            mTitleEditText.setText(title);
            mLatEditText.setText(lat);
            mLngEditText.setText(lng);
        }
    }

    public void addMarker(View view) {
        //editText에 적혀있는 글을 string으로 읽어온다.
        String title = mTitleEditText.getText().toString();
        String lat = mLatEditText.getText().toString();
        String lng = mLngEditText.getText().toString();

        //db에 저장하는 형식으로 데이터를 변환해준다.
        ContentValues contentValues = new ContentValues();
        contentValues.put(MemoContract.MemoEntry.COLUMN_NAME_TITLE, title);
        contentValues.put(MemoContract.MemoEntry.COLUMN_NAME_LAT, lat);
        contentValues.put(MemoContract.MemoEntry.COLUMN_NAME_LNG, lng);

        //db를 write형식으로 가져오자.
        SQLiteDatabase db = MemoDbHelper.getInstance(this).getWritableDatabase();

        //이부분은 음... 수정을 위한 부분이다.
        if(mMemoId == -1){
            //db에 데이터를 넣어준다.
            long newRowId = db.insert(MemoContract.MemoEntry.TABLE_NAME,null, contentValues);

            //제대로 들어갔는지 toast메시지로 확인하자.
            if(newRowId == -1){
                Toast.makeText(this, "저장에 문제가 발생하였습니다.", Toast.LENGTH_SHORT).show();
            }
            else{
                Toast.makeText(this, "경계가 추가되었습니다", Toast.LENGTH_SHORT).show();
                setResult(RESULT_OK);

                startActivity(new Intent(this, MarkerListActivity.class));
            }
        }
        else{
            //수정을 해주는 모습을 볼 수 있다.
            int count = db.update(MemoContract.MemoEntry.TABLE_NAME, contentValues, MemoContract.MemoEntry._ID + "=" + mMemoId, null);

            if(count == 0) {
                Toast.makeText(this, "수정에 문제가 발생하였습니다.", Toast.LENGTH_SHORT).show();
            }
            else {
                Toast.makeText(this, "경계가 수정되었습니다", Toast.LENGTH_SHORT).show();
                setResult(RESULT_OK);
            }
        }





    }

    //메뉴 연결
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.marker_add_menu, menu);
        return true;
    }

    //메뉴 버튼이 눌리면 동작을 하도록
    @Override
    public boolean onOptionsItemSelected(@NonNull MenuItem item) {
        switch (item.getItemId()){
            case R.id.marker_add_menu_1:
                Toast.makeText(this, "모든 경계가 삭제되었습니다.", Toast.LENGTH_SHORT).show();
                startActivity(new Intent(this, MainActivity.class));
                return true;
            case R.id.marker_add_menu_2:
                Toast.makeText(this, "두 번째 메뉴", Toast.LENGTH_SHORT).show();
                startActivity(new Intent(this, MarkerListActivity.class));
                return true;
        }

        return super.onOptionsItemSelected(item);
    }
}
