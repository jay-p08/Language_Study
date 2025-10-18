//public class RectangleModel {
//    public static void main(String[] args) {
//        Rectangle rectangle = new Rectangle();
//        rectangle.setWidth(3); rectangle.setHeight(5);
//        System.out.printf("가로 : %d\n", rectangle.getWidth());
//        System.out.printf("세로 : %d\n", rectangle.getHeight());
//        System.out.printf("둘레 : %d\n", rectangle.calculatePerimeter());
//        System.out.printf("면적 : %d\n", rectangle.calculateArea());
//
//    }
//}
//class Rectangle {
//    int W;
//    int H;
//    public Rectangle() {
//        this.W = 1;
//        this.H = 1;
//    }
//    int calculatePerimeter() {
//        return (W+H)*2;
//    }
//    int calculateArea() {
//        return W * H;
//    }
//    int getWidth() {
//        return W;
//    }
//    int getHeight() {
//        return H;
//    }
//    void setHeight(int H) {
//        if ( H <= 0 || H >= 20 ) {
//            System.out.println("범위를 넘었습니다.");
//        } else {
//            this.H = H;
//        }
//    }
//    void setWidth(int W) {
//        if ( W <= 0 || W >= 20 ) {
//            System.out.println("범위를 넘었습니다.");
//        } else {
//            this.W = W;
//        }
//    }
//}