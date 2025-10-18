// �������̵�(�޼��� ������) ����
public class Overriding {
    public static void main( String[] args ) {
        Weapon weapon; // Weapon Ÿ���� ���� ���� ����

        // Weapon ��ü ���� �� fire() ȣ��
        weapon = new Weapon(); 
        System.out.printf( "�⺻ ������ ��� �ɷ��� %d\n", weapon.fire() ); // �⺻ ���� fire() ȣ��

        // Cannon ��ü ���� �� fire() ȣ��
        weapon = new Cannon(); 
        System.out.printf( "������ ��� �ɷ��� %d\n", weapon.fire() ); // ���� fire() ȣ��
    }
}

// ���� Ŭ���� (�⺻ Ŭ����)
class Weapon {
    // �⺻ fire() �޼���: ������ ��� �ɷ��� �⺻������ 1
    protected int fire() {
        return 1; // �⺻ ���⿡�� �Ѹ� ���
    }
}

// ���� Ŭ���� (Weapon�� ��ӹ���)
class Cannon extends Weapon {
    // fire() �޼��带 �������̵��Ͽ� ������ ��� �ɷ��� 10���� ����
    @Override
    protected int fire() {
        return 10; // ������ �� ���� 10���� ���
    }
}
