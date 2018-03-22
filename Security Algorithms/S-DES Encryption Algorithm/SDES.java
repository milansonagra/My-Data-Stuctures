package PR_4_SDES;

/**
 *
 * @author Milan
 */


public class SDES {

    //  COMPONENTS
    private static int[] P4 = new int[4];
    private static int[] P8 = new int[8];
    private static int[] P10 = new int[10];
    private static int[] IP = new int[8];
    private static int[][] S1
            = {
                {0, 1, 2, 3},
                {2, 0, 1, 3},
                {3, 0, 1, 0},
                {2, 1, 0, 3}
            };

    private static int[][] S0
            = {
                {1, 0, 3, 2},
                {3, 2, 1, 0},
                {0, 2, 1, 3},
                {3, 1, 3, 2}
            };
    private int[] EP = new int[8];

    //  KEYS
    private int[] K1 = new int[8];
    private int[] K2 = new int[8];

    public SDES(int[] InputKey) {
        //  DEFAULT VALUES FOR COMPONENTS
        int[] p4 = {1, 3, 2, 0};
        int[] p8 = {5, 2, 6, 3, 7, 4, 9, 8};
        int[] p10 = {2, 4, 1, 6, 3, 9, 0, 8, 7, 5};
        int[] ip = {1, 5, 2, 0, 3, 7, 4, 6};
        int[] ep = {3, 0, 1, 2, 1, 2, 3, 0};

        //  ASSIGN DEFAULT VALUE FOR COMPONENTS
        setP4(p4);
        setP8(p8);
        setP10(p10);
        setIP(ip);
        setEP(ep);

        //  GENERATE KEYS K1 AND K2 
        generateKeys(InputKey);
    }

    /*  METHODS FOR SET COMPONENTS*/
    public void setP4(int[] p4) {
        this.P4 = p4;
    }

    public void setP8(int[] p8) {
        this.P8 = p8;
    }

    public void setP10(int[] p10) {
        this.P10 = p10;
    }

    public void setIP(int[] ip) {
        this.IP = ip;
    }

    public void setEP(int[] ep) {
        this.EP = ep;
    }

    public int[] getK1() {
        return K1;
    }

    public int[] getK2() {
        return K2;
    }

    private void generateKeys(int InputKey[]) {
        //  CURRENT WORKING COMPONENTS
        int[] Crr_Work1 = new int[5];
        int[] Crr_Work2 = new int[5];
        /*
         
            FOR GENERATING K1
         
         */

        //  APPLY P-10 ON GIVEN KEY
        for (int i = 0; i < 10; i++) {
            if (i < 5) {
                Crr_Work1[i] = InputKey[P10[i]];
            } else {
                Crr_Work2[i - 5] = InputKey[P10[i]];
            }
        }

        //  LIFT-SHIFT BY 1 OF GENERATED OUTPUT
        Crr_Work1 = leftShift(Crr_Work1, 1);
        Crr_Work2 = leftShift(Crr_Work2, 1);

        //  APPLY P-8 TO OUTPUT LEFT-SHIFTED BY 1
        for (int i = 0; i < 8; i++) {
            if (P8[i] < 5) {
                K1[i] = Crr_Work1[P8[i]];
            } else {
                K1[i] = Crr_Work2[P8[i] - 5];
            }
        }

        /*
         
            FOR GENERATING K2
         
         */
        //  LIFT-SHIFT BY 2 OF GENERATED OUTPUT
        Crr_Work1 = leftShift(Crr_Work1, 2);
        Crr_Work2 = leftShift(Crr_Work2, 2);

        //  APPLY P-8 TO OUTPUT OF LEFT-SHIFTED BY 2
        for (int i = 0; i < 8; i++) {
            if (P8[i] < 5) {
                K2[i] = Crr_Work1[P8[i]];
            } else {
                K2[i] = Crr_Work2[P8[i] - 5];
            }
        }
    }

    public int[] generateCypherText(int[] PlainText) {
        int[] CypherText = new int[8];

        int[] Array8 = new int[8];
        int[] Array4 = new int[4];
        int[] Array2 = new int[2];
        //
        //
        /*      ITERATION - 1       */
        //
        //
        //  CURRENT WORKING COMPONENTS
        int[] Crr_Work1 = new int[4];
        int[] Crr_Work2 = new int[4];
        int[] Copy_Work2 = new int[4];

        //  IP 
        for (int i = 0; i < 8; i++) {
            Array8[i] = PlainText[IP[i]];
        }

        //  PUT PLANE TEXT IN CURRENT WORKING COMPONENTS
        for (int i = 0; i < 8; i++) {
            if (i < 4) {
                Crr_Work1[i] = Array8[i];
            } else {
                Crr_Work2[i % 4] = Array8[i];
                Copy_Work2[i % 4] = Array8[i];
            }
        }

        //  [EP] + [(ANS) {EX-OR} K1]
        for (int i = 0; i < 8; i++) {
            Array8[i] = Crr_Work2[EP[i]] ^ K1[i];
        }

        //  APPLY S-BOXES:-
        int op_s0, op_s1;
        op_s0 = S0[(Array8[0] * 2 + Array8[3])][(Array8[1] * 2 + Array8[2])];
        op_s1 = S1[(Array8[4] * 2 + Array8[7])][(Array8[5] * 2 + Array8[6])];

        Crr_Work2[0] = op_s0 / 2;
        Crr_Work2[1] = op_s0 % 2;   //  CONVERT INTO BINARY
        Crr_Work2[2] = op_s1 / 2;
        Crr_Work2[3] = op_s1 % 2;

        //  [P4] + [(ANS) {EX-OR} Crr_Work-1]
        for (int i = 0; i < 4; i++) {
            Array4[i] = Crr_Work1[i] ^ Crr_Work2[P4[i]];
        }
        //
        //
        /*      ITERATION - 2       */
        //
        //

        //  SWAP Crr_Work-2 & (ANS)
        for (int i = 0; i < 8; i++) {
            if (i < 4) {
                Array8[i] = Copy_Work2[i];
            } else {
                Array8[i] = Array4[i % 4];
            }
        }

        //  PUT PLANE TEXT IN CURRENT WORKING COMPONENTS
        for (int i = 0; i < 8; i++) {
            if (i < 4) {
                Crr_Work1[i] = Array8[i];
            } else {
                Crr_Work2[i % 4] = Array8[i];
                Copy_Work2[i % 4] = Array8[i];
            }
        }

        //  [EP] + [(ANS) {EX-OR} K2]
        for (int i = 0; i < 8; i++) {
            Array8[i] = Crr_Work2[EP[i]] ^ K2[i];
        }

        //  APPLY S-BOXES:-
        op_s0 = S0[(Array8[0] * 2 + Array8[3])][(Array8[1] * 2 + Array8[2])];
        op_s1 = S1[(Array8[4] * 2 + Array8[7])][(Array8[5] * 2 + Array8[6])];

        Crr_Work2[0] = op_s0 / 2;
        Crr_Work2[1] = op_s0 % 2;
        Crr_Work2[2] = op_s1 / 2;
        Crr_Work2[3] = op_s1 % 2;

        //  [P4] + [(ANS) {EX-OR} Crr_Work-1]
        for (int i = 0; i < 4; i++) {
            Array4[i] = Crr_Work1[i] ^ Crr_Work2[P4[i]];
        }

        //  GENERATE IP inverse
        int[] IPinv = new int[IP.length];
        for (int i = 0; i < 8; i++) {
            IPinv[IP[i]] = i;
        }

        for (int i = 0; i < 8; i++) {
            if (i < 4) {
                Array8[i] = Array4[i];
            } else {
                Array8[i] = Copy_Work2[i % 4];
            }
        }

        for (int i = 0; i < 8; i++) {
            CypherText[i] = Array8[IPinv[i]];
        }
        return CypherText;
    }

    private int[] leftShift(int[] array, int lf) {

        //  LIFT-SHIFT THE 'array' BY 'lf' BIT
        int[] LiftShiftedArray = new int[array.length];
        for (int i = 0; i < array.length; i++) {
            if (i + lf < array.length) {
                LiftShiftedArray[i] = array[i + lf];
            } else {
                LiftShiftedArray[i] = array[(i + lf) - array.length];
            }
        }
        return LiftShiftedArray;
    }
}