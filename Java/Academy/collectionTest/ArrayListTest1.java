package collectionTest;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;

public class ArrayListTest1 {
    public static void main(String[] args) {
        ArrayList<Integer> datas = new ArrayList<Integer>();

//        datas.add(1);
        datas.add(100);
        datas.add(300);
        datas.add(200);
        datas.add(400);
        datas.add(800);
        datas.add(600);
        datas.add(700);
        datas.add(500);

        /*System.out.println(datas);

        Collections.sort(datas);
        System.out.println(datas);

        Collections.reverse(datas);
        System.out.println(datas);

        Collections.shuffle(datas);
        System.out.println(datas);*/

        System.out.println(datas);

        if (datas.contains(400))
            datas.add(datas.indexOf(400)+1, 4000);
        System.out.println(datas);

        datas.set(datas.indexOf(4000), 40);
        System.out.println(datas);

        System.out.println(datas.remove(Integer.valueOf(400)));
    }
}
