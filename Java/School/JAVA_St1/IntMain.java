public class IntMain {
	public static void main ( String [ ] args ) {
	//byte 127 ~ -128
	//short 32767 ~ -32768
	//int 2147483647 ~ -2147483648
	//long 9223372036854775807L ~ -9223372036854775808L
	//Float 3.4028235E38 ~ 1.4E-45
	//Double 1.7976931348623157E308 ~ 4.9E-324
		System.out.println ( Byte.MAX_VALUE + "\n" + Byte.MIN_VALUE + "\n" + Byte.SIZE + "\n" );
		
		System.out.println ( Short.MAX_VALUE + "\n" + Short.MIN_VALUE + "\n" + Short.SIZE + "\n" );
		
		System.out.println ( Integer.MAX_VALUE + "\n" + Integer.MIN_VALUE + "\n" + Integer.SIZE + "\n" );
		
		System.out.println ( Long.MAX_VALUE + "\n" + Long.MIN_VALUE + "\n" + Long.SIZE + "\n" );
		
		System.out.println ( Float.MAX_VALUE + "\n" + Float.MIN_VALUE + "\n" + Float.SIZE + "\n" );
		
		System.out.println ( Double.MAX_VALUE + "\n" + Double.MIN_VALUE + "\n" + Double.SIZE + "\n" );
	}
}