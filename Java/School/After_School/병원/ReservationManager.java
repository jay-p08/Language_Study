import java.util.ArrayList;

class ReservationManager {
    private ArrayList<Patient> reservationList;

    public ReservationManager() {
        reservationList = new ArrayList<>();
    } // ReservationManager()

    public void addReservation( Patient p ) {
        reservationList.add( p );
    } // addReservation()

    public void updateReservation( int index, Patient p ) {
        if( index >= 0 && index < reservationList.size() ) {
            reservationList.set( index, p );
            System.out.println( "예약 수정됨 : " + p.getName() );
        } // if
    } // updateReservation()

    public void removeReservation( int index ) {
        if( index >= 0 && index < reservationList.size() ) {
            Patient p = reservationList.remove( index );
            System.out.println( "예약 삭제됨 : " + p.getName() );
        }
    } // removeReservation()

    public ArrayList<Patient> getReservations() {
        return reservationList;
    } // getReservations()

} // Class ReservationManager
