public class suhang2305_02 {
    public static void main(String[] args) {
        Employee[] emp = new Employee[3];
        emp[0] = new HourlyEmp( 1, "정선혜", 40, 5000 );
        emp[1] = new SalariedEmp( 2, "권웅지", 1000000 );
        emp[2] = new SalesPerson( 3, "임하진", 1000000, 10, 10000 );
        System.out.println("아이디\t이름\t총 급여 " );
        System.out.println("-----------------------------");
        for( int i = 0 ; i < 3 ; i++ ) {
            emp[i].Print();
        }
    }
}

class Employee {
    int id;
    String name;
    int hour;
    int payPerHour;

    public Employee( int id, String name ) {
        this.id = id;
        this.name = name;
    }

    public int CalculatePay() {
        return 0;
    }

    public void Print() {
        System.out.printf( "%d\t%s\t%d\n", id, name, CalculatePay() );
    }

}

class SalariedEmp extends Employee {
    int salary;
    public SalariedEmp(int id, String name, int salary ) {
        super(id, name);
        this.salary = salary;
    }
    public int CalculatePay() {
        return this.salary;
    }
}

class HourlyEmp extends Employee {
    int hours;
    int payPerHour;

    public HourlyEmp(int id, String name, int hours, int payPerHour) {
        super( id, name );
        this.hours = hours;
        this.payPerHour = payPerHour;
    }
    public int CalculatePay() {
        return this.hours * this.payPerHour;
    }
}

class SalesPerson extends SalariedEmp {
    int sales;
    int incentive;

    public SalesPerson( int id, String name, int salary, int sales, int incentive ) {
        super(id, name, salary);
        this.sales = sales;
        this.incentive = incentive;
    }

    public int CalculatePay() {
        return this.salary + this.sales * this.incentive;
    }
}