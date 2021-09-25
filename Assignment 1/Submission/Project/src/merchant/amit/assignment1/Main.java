package merchant.amit.assignment1;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;


/**
 * Driver class to test the program.
 * @author Amit Merchant
 * @version 0.0.0.01
 */
public class Main {

    /**
     * Main method executed from the command line without any arguments.
     * Reads in a list of fully parenthesized infix expressions from "test.txt"
     * creates and outputs ExpressionTrees for them as well as describing and
     * testing their .equals method
     * @param args Arguments passed to the program - none used.
     */
    public static void main(String[] args) {
        String[] testDescriptors = {
                "(Single and multi-digit numbers, nested parenthesis)",
                "(Addition and multiplication, precedence)",
                "(Division and multiplication, precedence)",
                "(All operators, decimal numbers)",
                "","","","","","",
                "(Decimal not starting with digit)",
                "","","", "","","","","",""
        };
        // Open and read the file
        BufferedReader reader;
        try{ // Try to open the file "tests.txt" in the user directory
            reader = new BufferedReader(new FileReader(System.getProperty("user.dir") + "\\tests.txt"));
            System.out.println("""
                    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                    Creating and printing trees from tests.txt
                    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~""");
            // Get the initial infix line
            String infix = reader.readLine();
            // Counter variable for the output
            int i = 1;
            // While there is another infix
            while(infix != null) {
                // Create a new ExpressionTree from the infix
                ExpressionTree tree = new ExpressionTree(infix);
                // Print counter to keep track of expression then print the expression
                System.out.printf("\nExpression %2d:\n", i++);
                // Output descriptors for special test cases
                if(!testDescriptors[i-2].equals("")) System.out.println(testDescriptors[i-2]);
                System.out.println(tree);
                // Get the next line from the file
                infix = reader.readLine();
            }
        } catch(IOException e) {
            // Catch any IO exceptions (most likely if it can't find the file or can't open it)
            // Print the stack trace and exit.
            e.printStackTrace();
            // Let the user know where they should place the tests.txt if we're throwing an error
            System.out.printf("\n\nPlace tests.txt in %s if it can't find it.",  System.getProperty("user.dir"));
            System.exit(1);
        }

        System.out.println("""
                
                
                
                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                Testing .equals with three trees; Tree1, Tree2, and Tree3
                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                """);
        // Create 3 trees to test equality with
        ExpressionTree Tree1 = new ExpressionTree("(1+(2*3))+(((4*55)+66)*77)");
        ExpressionTree Tree2 = new ExpressionTree("(1+(2*3))+(((4*55)+66)*77)");
        ExpressionTree Tree3 = new ExpressionTree("(1+(2*3))+(((4*55)+66)*99.99)");
        System.out.println("""
                Tree1 and Tree2 have the same infix and should yield a true value for equals.
                Printing Tree1::""");
        System.out.println(Tree1);
        System.out.println("\nPrinting Tree2::");
        System.out.println(Tree2);
        System.out.println("""


                Tree 3 has a different final operand (99.99 instead of 77)
                
                Printing Tree3::""");
        System.out.println(Tree3);
        System.out.println("\nChecking equality of Tree1 and Tree2\n" +
                "Result: " + (Tree1.equals(Tree2) ? "True" : "False"));

        System.out.println("\nChecking equality of Tree1 and Tree3\n" +
                "Result: " + (Tree1.equals(Tree3) ? "True" : "False"));


        System.out.println("\nChecking equality of Tree2 and Tree3\n" +
                "Result: " + (Tree2.equals(Tree3) ? "True" : "False"));
    }
}
