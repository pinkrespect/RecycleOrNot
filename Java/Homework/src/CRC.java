import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;

/**
 * Created by maisie on 17. 5. 24.
 */

class Encoder{
    public int limit;
    private int[] divisor; // p(x) = x^5 + x^4 + X^2 + 1
    private int[] dividend; // x^9 + x^7 + X^3 + X^2 + 1
    private int[] result;
    private BlockingQueue<Integer> register;

    public Encoder(int[] array) throws InterruptedException {
        this.limit = 6;
        this.divisor = new int[this.limit];
        /*
        Resets divisor array to a fixed divisor that p(x) = x^5 + x^4 + x^2 + 1.
        Each divisor array index means exponent.
        */
        for(int i = 0; i < this.limit; i++){
            if((i == 0)||(i == 2)||(i == 4)||(i == 5)) {
                this.divisor[i] = 1;
            }else{
                this.divisor[i] = 0;
            }
        }
        // Reset dividend array to a fixed data that x^9 + x^7 + X^3 + X^2 + 1.
        setDividend(array);
        // array.length means input data's length.
        setResult(array);
        // Resets Queue register to 0.
        setRegister(array);
        Shifter(array);
    }

    public void setDividend(int[] array){
        // Resets the dividend array to given array.
        this.dividend = array;
    }

    private void setResult(int[] array){
        /*
        Resets the result array's size to given size.
        The given size equals input data's size.
        */
        this.result = new int[array.length];
    }

    private void setRegister(int[] array){
        /*
        Resets the register queue's size and contents to divisor's size and contents.
        The content of the Register Queue changes as the calculation proceeds.
        */
        this.register = new ArrayBlockingQueue<Integer>(array.length);
        while (this.register.size() != array.length) {
            this.register.add(0);
        }
    }

    public int setRegister(int number) throws InterruptedException {
        /*
        Add next integer number in register queue
        and return a number that takes from register queue.
         */
        int takeNumber = this.register.take();
        this.register.add(number);
        return takeNumber;
    }

    private void Shifter(int[] array) throws InterruptedException {
        System.out.println("divisor: " + this.divisor);

        for (int j = 0; j < this.limit; j++) {
            for (int i = 0; i < array.length; i++) {
                if (divisor[j] == 0) {
                    System.out.println("divisor[" + j + "]: " + divisor[j]);
                    System.out.println("setRegister: " + this.setRegister(array[i]));
                } else {
                    System.out.println("divisor[" + j + "]: " + divisor[j]);
                    System.out.println("setRegister ^ 1: " + this.setRegister(array[i] ^ divisor[j]));
                }
            }
            System.out.println("Queue: " + this.register);
        }
    }

    public int[] getResult(){
        return this.result;
    }
}

public class CRC {
    public static void main(String args[]) throws InterruptedException {
        int[] array = {1, 0, 1, 0, 0, 0, 1, 1, 0, 1};
        Encoder encoder = new Encoder(array);
    }
}
