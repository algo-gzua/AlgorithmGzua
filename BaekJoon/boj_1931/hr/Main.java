package boj_1931;

import java.io.*;
import java.util.*;

class Room{
    private int start;
    private int end;

    public Room(int start, int end){
        this.start = start;
        this.end = end;
    }
    public int getStart(){
        return start;
    }
    public int getEnd(){
        return end;
    }
};
public class Main {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
            StringBuilder sb = new StringBuilder();
            ArrayList<Room> arr = new ArrayList<>();
            StringTokenizer st;
            int tc = Integer.parseInt(br.readLine());
            for (int i = 0; i < tc; i++) {
                st = new StringTokenizer(br.readLine());
                int s = Integer.parseInt(st.nextToken());
                int e = Integer.parseInt(st.nextToken());
                arr.add(new Room(s,e));
            }
            Collections.sort(arr, (r1, r2) -> {
                if (r1.getEnd() < r2.getEnd()) {
                    return -1;
                } else if (r1.getEnd() > r2.getEnd()) {
                    return 1;
                } else if(r1.getEnd() == r2.getEnd()){
                    return r1.getStart() < r2.getStart() ? -1 : 1;
                }
                return 0;
            });

            int end = arr.get(0).getEnd();
            int cnt = 1;
            for(int j=1;j<tc;j++){
                if(arr.get(j).getStart() >= end){
                    end = arr.get(j).getEnd();
                    cnt++;
                }else{
                    continue;
                }

            }
            sb.append(cnt);
            bw.write(sb.toString());
            bw.flush();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
