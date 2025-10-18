import java.util.*;

public class HashMapScoreEx {
    public static void main(String[] args) {
        // 사용자 이름과 점수를 기록하는 HashMap 컬렉션 생성
        HashMap<String, Integer> javaScore = new HashMap<String, Integer>();
        // 5 개의 점수 저장
        javaScore.put("김은비", 97);
        javaScore.put("하여린", 88);
        javaScore.put("전아린", 98);
        javaScore.put("이동건", 70);
        javaScore.put("양승연", 99);
        System.out.println("HashMap의 요소 개수:" + javaScore.size());
        // 모든 사람의 점수 출력.
        // javaScore에 들어 있는 모든 (key, value) 쌍 출력
        // key 문자열을 가진 집합 Set 컬렉션 리턴
        Set<String> keys = javaScore.keySet();
        // key 문자열을 순서대로 접근할 수 있는 Iterator 리턴
        Iterator<String> it = keys.iterator();
        while (it.hasNext()) {
            String name = it.next();
            int score = javaScore.get(name);
            System.out.println(name + " : " + score);
        }
    }
}