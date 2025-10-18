package exceptionTest;

public class ExceptionTest2 {
    public static void main(String[] args) {
        /*int[] arData = new int[5];
        System.out.println(arData[10]);*/

        int[] arData = new int[5];
        try{
            System.out.println(arData[10]);
            System.out.println("성공");
        } catch (ArrayIndexOutOfBoundsException e){
            System.out.println("실패");
        } catch (Exception e){
            e.printStackTrace();
        }
    }
}
