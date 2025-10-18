package 병원;

class Patient {
    private String name;
    private String phone;
    private String date;
    private String doctor;
    private String department;

    public Patient( String name, String phone, String date, String doctor, String department ) {
        this.name = name;
        this.phone = phone;
        this.date = date;
        this.doctor = doctor;
        this.department = department;
    } // Patient()

    public String getName() { return name; } // getName()
    public String getPhone() { return phone; } // getPhone()
    public String getDate() { return date; } // getDate()
    public String getDoctor() { return doctor; } // getDoctor()
    public String getDepartment() { return department; } // getDepartment()

    public void setName( String name ) { this.name = name; } // setName()
    public void setPhone( String phone ) { this.phone = phone; } // setPhone()
    public void setDate( String date ) { this.date = date; } // setDate()
    public void setDoctor( String doctor ) { this.doctor = doctor; } // setDoctor()
    public void setDepartment( String department ) { this.department = department; } // setDepartment()

} // Class Patient