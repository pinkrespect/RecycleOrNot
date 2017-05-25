/**
 * Created by maisie on 17. 5. 25.
 */

// Divisor: X^5 + X^4 + X^2 + 1 = 110101
// Dividend: x^9 + x^7 + x^3 + x^2 + 1 = 1010001101
    //Test Divisor: 1011
    //Test Dividend: 1001 + 000

class Encoder{
    private int[] divisor; // Fixed-number array
    private int[] dividend; // Flexible-number array - It changes as the calculation progresses.
    private int[] result;

    public Encoder(int array[]){
        setDivisor();
        setDividend(array);
        setResult();
    }

    private void setDivisor(){
        this.divisor = new int[6];
        for(int i = 0; i < this.divisor.length; i++)
            if((i == 0)||(i == 1)||(i == 3)||(i == 5))
                this.divisor[i] = 1;
    }

    private void setDividend(int array[]){
        dividend = new int[array.length + divisor.length - 1];
        for(int i = 0 ; i < array.length; i++) {
            dividend[i] = array[i];
        }
    }

    private void setResult(){
        this.result = new int[this.divisor.length - 1];
    }

    private int XOR(int x, int y){
        if(x == y){
            return 0;
        }else{
            return 1;
        }
    }

    public int[] calculate(){
        for(int i = 0; i + divisor.length -1 < this.dividend.length; i++) {
            System.out.println("dividend:" + dividend[i] + dividend[i + 1] + dividend[i + 2] + dividend[i + 3] + dividend[i+4] + dividend[i+5]);
            int j = 0;
            if (dividend[i] == 0) {
                for (; j < this.divisor.length; j++) {
                        System.out.println("divisor: 0!!");
                        dividend[i + j] = XOR(0, dividend[i + j]);
                        System.out.println("dividend[" + (i + j) + "]: " + dividend[i + j]);
                }
            } else {
                for (; j < this.divisor.length; j++) {
                    System.out.println("divisor: " + divisor[j]);
                    dividend[i + j] = XOR(divisor[j], dividend[i + j]);
                }
            }
        }

        for(int i = 0; i < dividend.length;i++){
            System.out.print(dividend[i] + " ");
        }
        return this.result;
    }
}

public class CRC {
    public static void main(String args[]){
        int[] array = {1, 0, 1, 0, 0, 0, 1, 1, 0, 1};
        Encoder encoder = new Encoder(array);
        encoder.calculate();
    }
}
