package vector;

import java.util.HashMap;

public class HashMapTest {
    public static void main(String[] args) {
        HashMap<String, Integer> shoplist = new HashMap<String, Integer>();
        shoplist.put("computer", 36700000);
        shoplist.put("avante", 36000000);
        shoplist.put("avante", 36000000);

        System.out.println( shoplist.get("computer") );
    }
}