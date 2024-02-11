package javatest;
public class Main {
    public static void main(String[] args) {
        // Number of iterations to approximate pi
        int iterations = 100000;

        double pi = calculatePi(iterations);

        // Print the calculated value of pi
        System.out.println("Approximation of Pi: " + pi);
    }

    public static double calculatePi(int iterations) {
        double pi = 0;
        double sign = 1.0;
        double denominator = 1.0;

        for (int i = 0; i < iterations; i++) {
            pi += sign * 4.0 / denominator;
            sign = -sign; // alternate between adding and subtracting
            denominator += 2.0; // increment denominator by 2 for each iteration
        }
        return pi;
    }
}
