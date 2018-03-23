package PR_3_RSA.REAL_TIME_ALGO;

import java.math.BigInteger;
import java.util.Random;

/**
 *
 * @author Milan
 */
public class RSA {

    //  PRIME NUMBERS
    private final BigInteger P;
    private final BigInteger Q;

    //  KEYS
    private final BigInteger N;      //
    private final BigInteger E;      //      PUBLIC-KEY

    private final BigInteger D;      //      PRIVATE-KEY

    //  fy(N)
    private final BigInteger fy_N;

    public RSA(int bitLength) {
        //  KEY GENERATION 

        Random rnd = new Random();
        P = BigInteger.probablePrime(bitLength, rnd);
        BigInteger temp_Q;
        do {
            //  CHECKING FOR P != Q
            temp_Q = BigInteger.probablePrime(bitLength, rnd);
        } while (P == temp_Q);
        Q = temp_Q;

        N = P.multiply(Q);      //  N = P * Q
        fy_N = P.subtract(BigInteger.ONE).multiply(Q.subtract(BigInteger.ONE));     //  fy_N = (P-1)(Q-1)

        E = BigInteger.probablePrime(bitLength, rnd);

        D = E.modInverse(fy_N);

        //  PUBLIC-KEY: (E,N) and PRIVATE-KEY: D
    }

    public String[] getPublicKey() {
        //  SEND PUBLIC-KEY
        String[] PublicKey = {E.toString(), N.toString()};
        return PublicKey;
    }

    public String encrypt(String msg) {
        //  ENCRYPT 'msg' AND RETURN ENCRYPTED-TEXT(as number formate) AS STRING

        BigInteger Cypher;
        String ASCII = asciiOf(msg);    //  CONVERT TEXT INTO NUMBER FORMATE(useing ASCII-values)
        Cypher = new BigInteger(ASCII).modPow(E, N);
        return Cypher.toString();
    }

    public String decrypt(String cypher) {
        //  DECRYPT 'cypher' AND RETRUN PALIN-TEXT

        BigInteger Plain;
        Plain = new BigInteger(cypher).modPow(D, N);    //  GENERATE PALIN TEXT AS NUMBER FORMATE(ASCII value)
        String msg = getString(Plain.toString());       //  CONVERT ASCII-VALUE TO STRING
        return msg;
    }

    private String asciiOf(String msg) {
        //  CONVERT EACH CHARACTURE INTO ASCII-VALUE AND CREATE A STRING OF THEM

        String ASCII = "";
        char[] temp_msg = msg.toCharArray();

        for (int i = 0; i < temp_msg.length; i++) {
            ASCII += Integer.toString((int) temp_msg[i]);
        }
        return ASCII;
    }

    private String getString(String ASCII) {
        //  GENERATE PLAIN-TEXT OF INPUTED ASCII-VALUE IN STRING FORMATE

        String msg = "";
        char[] temp_ascii = ASCII.toCharArray();

        for (int i = 0; i < temp_ascii.length - 1; i += 2) {
            int a = temp_ascii[i] - '0', b = temp_ascii[i + 1] - '0';
            msg += Character.toString((char) (a * 10 + b));
        }
        return msg;
    }
}
