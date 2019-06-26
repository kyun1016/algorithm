package com.example.basicmap;

import androidx.annotation.NonNull;
import androidx.annotation.RequiresApi;
import androidx.core.app.ActivityCompat;
import androidx.fragment.app.FragmentActivity;

import android.Manifest;
import android.content.pm.PackageManager;
import android.location.Location;
import android.os.Build;
import android.os.Bundle;
import android.view.View;
import android.widget.Toast;

import com.google.android.gms.location.FusedLocationProviderClient;
import com.google.android.gms.location.LocationServices;
import com.google.android.gms.maps.CameraUpdateFactory;
import com.google.android.gms.maps.GoogleMap;
import com.google.android.gms.maps.OnMapReadyCallback;
import com.google.android.gms.maps.SupportMapFragment;
import com.google.android.gms.maps.model.LatLng;
import com.google.android.gms.maps.model.Marker;
import com.google.android.gms.maps.model.MarkerOptions;
import com.google.android.gms.tasks.OnSuccessListener;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class MapsActivity extends FragmentActivity implements OnMapReadyCallback {

    private static final int REQUEST_CODE_PERMISSIONS = 1000;
    private GoogleMap mMap;
    private FusedLocationProviderClient mFusedLocationClient;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_maps);
        // Obtain the SupportMapFragment and get notified when the map is ready to be used.
        SupportMapFragment mapFragment = (SupportMapFragment) getSupportFragmentManager()
                .findFragmentById(R.id.map);
        mapFragment.getMapAsync(this);

        mFusedLocationClient = LocationServices.getFusedLocationProviderClient(this);
    }


    /**
     * Manipulates the map once available.
     * This callback is triggered when the map is ready to be used.
     * This is where we can add markers or lines, add listeners or move the camera. In this case,
     * we just add a marker near Sydney, Australia.
     * If Google Play services is not installed on the device, the user will be prompted to install
     * it inside the SupportMapFragment. This method will only be triggered once the user has
     * installed Google Play services and returned to the app.
     */
    @Override
    public void onMapReady(GoogleMap googleMap) {
        mMap = googleMap;

        // Add a marker in Sydney and move the camera
        LatLng sydney = new LatLng(37.2664398, 126.9994077);
        mMap.addMarker(new MarkerOptions().position(sydney).title("it's me!!!"));
        mMap.moveCamera(CameraUpdateFactory.newLatLng(sydney));
        mMap.animateCamera(CameraUpdateFactory.zoomTo(17.0f));

        mMap.setOnInfoWindowClickListener(new GoogleMap.OnInfoWindowClickListener() {
            @Override
            public void onInfoWindowClick(Marker marker) {
                //Toast.makeText(this,"내가 경계 내부인지 외부인지 출력한다.", Toast.LENGTH_SHORT).show();
                //algorithm();
            }


        });
    }


    @RequiresApi(api = Build.VERSION_CODES.M)
    public void onLastLocationButtonClicked(View view) {
        if (checkSelfPermission(Manifest.permission.ACCESS_FINE_LOCATION) != PackageManager.PERMISSION_GRANTED && checkSelfPermission(Manifest.permission.ACCESS_COARSE_LOCATION) != PackageManager.PERMISSION_GRANTED) {
            // TODO: Consider calling
            //    Activity#requestPermissions
            // here to request the missing permissions, and then overriding
            //   public void onRequestPermissionsResult(int requestCode, String[] permissions,
            //                                          int[] grantResults)
            // to handle the case where the user grants the permission. See the documentation
            // for Activity#requestPermissions for more details.
            ActivityCompat.requestPermissions(this,new String[] {Manifest.permission.ACCESS_FINE_LOCATION, Manifest.permission.ACCESS_COARSE_LOCATION}, REQUEST_CODE_PERMISSIONS);
            return;
        }
        mFusedLocationClient.getLastLocation().addOnSuccessListener(this, new OnSuccessListener<Location>() {
            @Override
            public void onSuccess(Location location) {
                if(location != null){
                    LatLng myLocation = new LatLng(location.getLatitude(), location.getLongitude());
                    mMap.addMarker(new MarkerOptions().position(myLocation).title("현재 위치"));
                    mMap.moveCamera(CameraUpdateFactory.newLatLng(myLocation));
                    mMap.animateCamera(CameraUpdateFactory.zoomTo(17.0f));
                }
            }
        });
    }

    @RequiresApi(api = Build.VERSION_CODES.M)
    @Override
    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults);
        switch (requestCode){
            case REQUEST_CODE_PERMISSIONS:
                if (checkSelfPermission(Manifest.permission.ACCESS_FINE_LOCATION) != PackageManager.PERMISSION_GRANTED && checkSelfPermission(Manifest.permission.ACCESS_COARSE_LOCATION) != PackageManager.PERMISSION_GRANTED){
                    Toast.makeText(this,"권한 체크 거부됨",Toast.LENGTH_SHORT).show();
                }
        }

    }

    //convex hull algorithm을 활용해서 영역 내부인지 확인한다.
//    public static void algorithm() {
//        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//        StringTokenizer st = null;
//        st = new StringTokenizer(br.readLine());
//        int N = Integer.parseInt(st.nextToken());
//        ArrayList<Point> listpoint = new ArrayList<>();
//        int minx = Integer.MAX_VALUE;
//        int miny = Integer.MAX_VALUE;
//        for (int n = 0; n < N; n++) {
//            st = new StringTokenizer(br.readLine());
//            int x = Integer.parseInt(st.nextToken());
//            int y = Integer.parseInt(st.nextToken());
//            listpoint.add(new Point(x, y));
//            if(miny > y || (miny == y && minx > x)) {
//                minx = x;
//                miny = y;
//            }
//        }
//
//        Point minPoint = new Point(minx, miny);
//        listpoint.add(minPoint);
//        Point p1 = minPoint;
//        ArrayList<Point> anslist = new ArrayList<>();
//        Point p2 = null;
//        do {
//            p2 = listpoint.get(0);
//            anslist.add(p1);
//            for (int i = 1; i < listpoint.size(); i++) {
//                Point p3 = listpoint.get(i);
//                int ccw = ccw(p1, p2, p3);
//                if(ccw == 0) {
//                    long d1 = dist(p1, p2);
//                    long d2 = dist(p1, p3);
//                    if(d1 < d2) {
//                        p2 = p3;
//                    }
//                }else if(ccw>0) {
//                    p2 = p3;
//                }
//            }
//            p1 = p2;
//        } while (!(minPoint.x==p1.x && minPoint.y==p1.y));
//
//        System.out.println(anslist.size());
//    }
//
//    private static long dist(Point p1, Point p2) {
//        return (p2.x-p1.x)*(long)(p2.x-p1.x) + (p2.y-p1.y)*(long)(p2.y-p1.y);
//    }
//
//    private static int ccw(Point p1, Point p2, Point p3) {
//        long ccw = ccw(p2.x-p1.x, p2.y-p1.y, p3.x-p1.x, p3.y-p1.y);
//        if(ccw == 0) return 0;
//        else if(ccw < 0) return -1;
//        else return 1;
//    }
//
//    private static long ccw(int x1, int y1, int x2, int y2) {
//        return (long)x1*y2 - (long)x2*y1;
//    }
}
