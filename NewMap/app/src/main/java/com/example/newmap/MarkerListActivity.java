package com.example.newmap;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.CursorAdapter;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

import com.google.android.material.floatingactionbutton.FloatingActionButton;

public class MarkerListActivity extends AppCompatActivity {

    private static final int REQUEST_CODE_INSERT = 1000;

    private MemoAdapter mAdapter;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_marker_list);

        FloatingActionButton fab = findViewById(R.id.fab);
        fab.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startActivityForResult(new Intent(MarkerListActivity.this, MarkerAddActivity.class), REQUEST_CODE_INSERT);
            }
        });

        //쿼리 항목을 리스트로 표현하기 위해서, xml에 있는 리스트 id에 등록을 하자.
        ListView listView = findViewById(R.id.memo_list);

        //쿼리를 가져오자.
        Cursor cursor = getMemoCursor();
        //query 항목을 처리를 해주자.
        mAdapter = new MemoAdapter(this, cursor);
        //처리한 데이터를 리스트에 등록한다.
        listView.setAdapter(mAdapter);

        //이 아이템이 눌리면, 수정을 하러 들어가자.
        listView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> adapterView, View view, int position, long id) {
                Intent intent = new Intent(MarkerListActivity.this, MarkerAddActivity.class);

                //데이터를 Cursor에 담아 가져오자. 이때, 아이템은 position을 통해 원하는 것을 골라 가져온다.
                Cursor cursor = (Cursor) mAdapter.getItem(position);

                //가져온 데이터의 TITLE, LAT, LNG을 string에 담아
                String title = cursor.getString(cursor.getColumnIndexOrThrow(MemoContract.MemoEntry.COLUMN_NAME_TITLE));
                String lat = cursor.getString(cursor.getColumnIndexOrThrow(MemoContract.MemoEntry.COLUMN_NAME_LAT));
                String lng = cursor.getString(cursor.getColumnIndexOrThrow(MemoContract.MemoEntry.COLUMN_NAME_LNG));

                //intent 내부에 넣어준다.(editText 부분)
                intent.putExtra("id", id);
                intent.putExtra("title", title);
                intent.putExtra("lat", lat);
                intent.putExtra("lng", lng);

                startActivityForResult(intent, REQUEST_CODE_INSERT);
            }
        });

        //리스트를 삭제하자.
        listView.setOnItemLongClickListener(new AdapterView.OnItemLongClickListener() {
            @Override
            public boolean onItemLongClick(AdapterView<?> adapterView, View view, int position, long id) {
                final long deleteId = id;
                //리스트를 삭제하는것은 알람 팝업을 따로 구현하여 추가적인 확인을 구하자.
                AlertDialog.Builder builder = new AlertDialog.Builder(MarkerListActivity.this);
                //내부에 들어갈 글을 적어주자.
                builder.setTitle("메모 삭제");
                builder.setMessage("메모를 삭제하시겠습니까?");
                //yes버튼이 눌리면
                builder.setPositiveButton("삭제", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        //db를 write 형식으로 수정이 가능하도록 가져온 다음.
                        SQLiteDatabase db = MemoDbHelper.getInstance(MarkerListActivity.this).getWritableDatabase();
                        //삭제할 id부분을 지워주자.(MemoDbHelper에 구현이 되어있다.)
                        //이때, return 값은 삭제한 data의 개수로 1이 반환이 된다.
                        int deletedCount = db.delete(MemoContract.MemoEntry.TABLE_NAME, MemoContract.MemoEntry._ID + " = " + deleteId, null);

                        //만일 삭제가 되지 않았다면 오류
                        if(deletedCount == 0){
                            Toast.makeText(MarkerListActivity.this, "삭제에 문제가 발생하였습니다.", Toast.LENGTH_SHORT).show();
                        }
                        else{
                            //
                            mAdapter.swapCursor(getMemoCursor());
                            Toast.makeText(MarkerListActivity.this, "삭제되었습니다.", Toast.LENGTH_SHORT).show();
                        }
                    }
                });
                builder.setNegativeButton("취소", null);
                builder.show();
                return true;
            }
        });
    }


    //쿼리를 가져오는 메소드
    private  Cursor getMemoCursor(){
        //db에서 instance를 가져온다.
        MemoDbHelper dbHelper = MemoDbHelper.getInstance(this);
        //query를 전부 가져오자.
        //MemoContract.MemoEntry._ID + "DESC"(마지막 순서에 적으면, 내림차순으로 정렬한다고 하는데, 어디에 이용할 지는 아직 고려중.)
        return dbHelper.getReadableDatabase().query(MemoContract.MemoEntry.TABLE_NAME, null, null, null,null,null,null,null);
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if(requestCode == REQUEST_CODE_INSERT && resultCode == RESULT_OK){
            //swapCursor는 cursor를 교체해주는 역할을 하는데,
            //지워져서 사라진 부분이 생기면 list를 다시 불러오는 기능을 한다.
            mAdapter.swapCursor(getMemoCursor());
        }
    }

    //cursor을 처리해주는 내부 클래스를 만들자.
    private static class MemoAdapter extends CursorAdapter{
        //가져온 데이터를 뿌려주기 위해서 cursor을 가져온다.
        public MemoAdapter(Context context, Cursor c) {
            super(context, c, false);
        }

        @Override
        public View newView(Context context, Cursor cursor, ViewGroup viewGroup) {
            //안드로이드 기본 리스트를 사용한다.
            return LayoutInflater.from(context).inflate(android.R.layout.simple_list_item_1, viewGroup, false);
        }

        @Override
        public void bindView(View view, Context context, Cursor cursor) {
            //textView에 연결해준다.
            TextView titleText = view.findViewById(android.R.id.text1);
            //커서에 담긴 항목중, title값을 가져와서 추가한다.
            titleText.setText(cursor.getString(cursor.getColumnIndexOrThrow(MemoContract.MemoEntry.COLUMN_NAME_TITLE)));
        }
    }
}
