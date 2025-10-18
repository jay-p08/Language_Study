/*
import java.util.Arrays;
import java.util.Comparator;

public class EmployeeDriver {
    public static void main(String[] args) {
        String[][] data = {{"MCTE11", "고영희", "D", "40", "5"}, {"MCRS12", "도민준", "A", "50"},
                          {"MCRM13", "채송화", "C", "30"}, {"MCRM14", "강연주", "B", "40" }};

        final int EmpNum = data.length;
        Employee[] pSm = new Employee[EmpNum];

        for (int i = 0; i < EmpNum; i++) {
            switch (data[i][0].substring(2, 4)) {
                case "TE" : pSm[i] = new Temporary(data[i][0], data[i][1], data[i][2].charAt(0), Integer.parseInt(data[i][3]), Integer.parseInt(data[i][4])); break;
                case "RS" : pSm[i] = new SalesMan(data[i][0], data[i][1], data[i][2].charAt(0), Integer.parseInt(data[i][3])); break;
                case "RM" : pSm[i] = new Manager(data[i][0], data[i][1], data[i][2].charAt(0), Integer.parseInt(data[i][3])); break;
            }
        }

        Employee[] SortOrder = new Employee[EmpNum];
        for (int i = 0; i < EmpNum; i++) {
            SortOrder[i] = new Employee();
            SortOrder[i] = pSm[i];
        }
        Employee temp = new Employee();
        for (int i = 0; i < EmpNum; i++) {
            int MinIndex = i;
            for (int j = i+1; j < EmpNum; j++) {
                if (SortOrder[MinIndex].getUniqueNumber().compareTo(SortOrder[j].getUniqueNumber()) > 0) MinIndex = j;
            }
            temp = SortOrder[MinIndex];
            SortOrder[MinIndex] = SortOrder[i];
            SortOrder[i] = temp;
        }

        String TempStr = SortOrder[0].getUniqueNumber().substring(2, 4);
        for (int i = 0; i < EmpNum; i++) {
            if (i==0 || !(SortOrder[i].getUniqueNumber().substring(2, 4).equals(TempStr))) {
                SortOrder[i].Title();
                TempStr = SortOrder[i].getUniqueNumber().substring(2, 4);
            }
            System.out.println(SortOrder[i].PrintEmployee());;
        }

Manager.Title();
        for (int i = 0 ; i < EmpNum ; i++) {
            if (data[i][0].substring(2, 4).equals("RM")) System.out.println(pSm[i].PrintEmployee());
        }
        Employee.Line();

        SalesMan.Title();
        for (int i = 0 ; i < EmpNum ; i++) {
            if (data[i][0].substring(2, 4).equals("RS")) System.out.println(pSm[i].PrintEmployee());
        }
        Employee.Line();

        Temporary.Title();
        for (int i = 0 ; i < EmpNum ; i++) {
            if (data[i][0].substring(2, 4).equals("TE")) System.out.println(pSm[i].PrintEmployee());
        }
        Employee.Line();


for (int i = 0; i < EmpNum; i++) {
            System.out.println(pSm[i].PrintEmployee());
        }

    }
}

class Employee {
    private int[] BasicSalaryList = {230, 210, 190, 170, 150};
    private String UniqueNumber; // 고유번호
    private String name;
    private char BasicSalary; // 기본수당

    public Employee() {;}
    public Employee(String uniqueNumber, String name, char basicSalary) {
        this.UniqueNumber = uniqueNumber;
        this.name = name;
        this.BasicSalary = basicSalary;
    }

    String getUniqueNumber() {
        return UniqueNumber;
    }
    String getEmployeeName() {
        return name;
    }
    char getBasicSalary() {
        return BasicSalary;
    }
    int getBasicSalaryList() {
        return BasicSalaryList[BasicSalary - 'A'];
    }

    int TotalAmountReceived(int BasicSalary, int Allowance) {
        return BasicSalary + Allowance;
    }

    String PrintEmployee() {
        return String.format("%s %s %d", getUniqueNumber(), getEmployeeName(), getBasicSalaryList());
    }
    static void Line() {
        System.out.println("***********************************************************************");
    }
    void Title() {

    }
}
class Manager extends Employee {
    private int ManagementAllowance; // 관리수당

    public Manager(String uniqueNumber, String name, char basicSalary, int managementAllowance) {
        super(uniqueNumber, name, basicSalary);
        ManagementAllowance = managementAllowance;
    }

    String PrintEmployee() {
        return String.format("%s %s %d %d %d", getUniqueNumber(), getEmployeeName(), getBasicSalaryList(), ManagementAllowance, TotalAmountReceived(getBasicSalaryList(), ManagementAllowance));
    }
    void Title() {
        System.out.println("Manager****************************************************************");
        System.out.println("사번     이름     기본급     관리수당     총수령액");
        Employee.Line();
    }
}
class SalesMan extends Employee {
    private int SalesAllowance; // 영업수당

    public SalesMan(String uniqueNumber, String name, char basicSalary, int salesAllowance) {
        super(uniqueNumber, name, basicSalary);
        SalesAllowance = salesAllowance;
    }

    String PrintEmployee() {
        return String.format("%s %s %d %d %d", getUniqueNumber(), getEmployeeName(), getBasicSalaryList(), SalesAllowance, TotalAmountReceived(getBasicSalaryList(), SalesAllowance));
    }
    void Title() {
        System.out.println("SalesMan***************************************************************");
        System.out.println("사번     이름     기본급     관리수당     총수령액");
        Employee.Line();
    }
}
class Temporary extends Employee {
    private int PerformanceAllowance; // 성과수당
    private int ContractPeriod; // 계약기간

    public Temporary(String uniqueNumber, String name, char basicSalary, int performanceAllowance, int ContractPeriod) {
        super(uniqueNumber, name, basicSalary);
        this.PerformanceAllowance = performanceAllowance;
        this.ContractPeriod = ContractPeriod;
    }

    String PrintEmployee() {
        return String.format("%s %s %d %d %d %d", getUniqueNumber(), getEmployeeName(), getBasicSalaryList(), PerformanceAllowance, TotalAmountReceived(getBasicSalaryList(), PerformanceAllowance), ContractPeriod);
    }
    void Title() {
        System.out.println("Temporary**************************************************************");
        System.out.println("사번     이름     기본급     관리수당     총수령액     영업기간");
        Employee.Line();
    }
}
*/
