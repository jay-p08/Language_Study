public class Main {
	public static void main ( String [ ] args ) {
	//byte 127 ~ -128
	//short 32767 ~ -32768
	//int 2147483647 ~ -2147483648
	//long 9223372036854775807L ~ -9223372036854775808L
		long val = 9223372036854775807L;
		System.out.println ( Byte.MAX_VALUE );
		System.out.println ( Byte.MIN_VALUE );
		System.out.println ( Byte.SIZE );
		System.out.println ( Short.MAX_VALUE );
		System.out.println ( Short.MIN_VALUE );
		System.out.println ( Byte.SIZE );
		System.out.println ( Long.MAX_VALUE );
		System.out.println ( Long.MIN_VALUE );
		
		System.out.println ( Integer.MAX_VALUE );
		System.out.println ( Integer.MIN_VALUE );
		System.out.println ( Integer.SIZE );
	}
}