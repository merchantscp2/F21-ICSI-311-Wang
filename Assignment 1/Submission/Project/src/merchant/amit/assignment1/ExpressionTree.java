package merchant.amit.assignment1;

import java.util.Stack;

/**
 * A tree which will take an infix and create a tree of nodes which represents it
 * @author Amit Merchant
 * @version 0.0.0.01
 */
class ExpressionTree {
    /**
     * Readable representation of PREORDER, INORDER, and POSTORDER
     */
    enum ORDER {
        PREORDER,
        INORDER,
        POSTORDER
    }

    // Instance fields
    private Node rootNode = new Node<>();
    private String infix;

    /**
     * Default constructor. Creates new instance of Expression tree with empty/null fields
     */
    public ExpressionTree() {
    }

    /**
     * Creates a new expression tree from an infix string
     * @param infix a string, fully parenthesized infix without any spaces.
     */
    public ExpressionTree(String infix) { // Overloaded constructor - check
        // Assign the infix to our member
        this.infix = infix;
        // Convert the infix to postfix and set postfix member
        this.rootNode = postfixToTree(infixToPostfix(infix));
    }

    public Node postfixToTree(String postfix) {
        // Create a new stack to hold the nodes
        Stack treeStack = new Stack<Node>();
        // Split the postfix by spaces
        String[] tokens = postfix.split("\\s+");

        // Iterate through each token
        for(String t: tokens) {
            // If the token is an operator
            if(isStringOperator(t)) {
                // Pop the last two entries (operands)
                Node topNode = (Node)treeStack.pop();
                Node nextNode = (Node)treeStack.pop();
                // Create a new node
                Node newNode = new Node(t);
                // Set the leaves of the new node to the old top entries
                newNode.setRightLeaf(topNode);
                newNode.setLeftLeaf(nextNode);
                // Push the new parent node to the stack
                treeStack.push(newNode);
            } else { // If the token is an operand
                // Create a node with the operand
                Node newNode = new Node(t);
                // Push it to the stack
                treeStack.push(newNode);
            }
        }
        // Set the top node in the stack as the root node
        return (Node)treeStack.pop();
    }

    /**
     * Helper for infixToPostfix to determine operator precedence.
     * @param operator The character/operator we're checking
     * @return 1 if the operator is + or -, 2 if operator is * or / and -1 if neither
     */
    private int precedence(char operator){
        return (operator == '+' || operator == '-') ? 1 : (operator == '*' || operator == '/') ? 2 : -1;
    }

    /**
     * Convert an infix expression String to a postfix String
     * @param infix a string containing an infix expression
     * @return a string containing the expression in postfix
     */
    public String infixToPostfix(String infix) { // FIXME Need to take precedence into account here.. Oops!!
        // Remove all whitespace character from the expression
        infix = infix.replaceAll("\\\\s+", "");

        // Create a new stack to hold the operators
        Stack<Character> operators = new Stack<Character>();
        // Create a new stringbuffer that we can append to
        StringBuilder postfix = new StringBuilder();

        // For each character in the infix string
        for(int i = 0; i < infix.length(); i++) {
            // Placeholder variable for the character at index i
            char character = infix.charAt(i);

            // If the character at i is a number or part of a number
            if(Character.isDigit(character) || infix.charAt(i) == '.') {
                l("Found digit");
                // Set the temp string to the first character of the int
                StringBuilder tempIntString = new StringBuilder();
                tempIntString.append(infix.charAt(i));
                // For each of the next characters that are digits with support for decimals
                while(i+1 < infix.length() && (Character.isDigit(infix.charAt(i+1)) || infix.charAt(i+1) == '.')) {
                    l("Multi-character number found");
                    // Add the character to the temporary string
                    // and increase the counter to skip it for the next iteration
                    tempIntString.append(infix.charAt(++i));
                }
                // Add the full number now to the postfix string with a space
                postfix.append(tempIntString);
                postfix.append(" ");
            } else
            // If we find a parenthetical and it's open, push it to the stack
            if(character == '(') operators.push(character);
            else
            // And if its the close paren
            if(character == ')') {
                l("Adding operator to postfix");
                // Add all the operators to the output till we get to a (
                while(operators.peek() != '(' && !operators.isEmpty()) {
                    postfix.append(operators.pop());
                    postfix.append(" ");
                }
                // Clear the ( from the stack
                operators.pop();
            }
            else
            // Otherwise, if the character is not an operand, but an operator
            if(isCharacterOperator(character)) {
                l("Found operator " + character);
                // Check the precedence and if its less or equal, add it to the output
                while(!operators.isEmpty() && precedence(character) <= precedence(operators.peek())) {
                    postfix.append(operators.pop());
                }
                // Add it to the stack of operators
                operators.push(character);
            }

        } // Close for

        // Flush any remaining operators
        while(!operators.isEmpty()) {
            // Add remaining operators to the postfix string
            postfix.append(operators.pop());
        }
        // Return the full trimmed postfix string
        return postfix.toString().trim();
    }

    /**
     * Prints the branches/leaves of a tree root in preorder, inorder, or postorder
     * @param root A root Node with leaves
     * @param order Traversal order: ORDER.PREORDER, ORDER.INORDER, ORDER.POSTORDER
     */
    public void traverseTreeWithOrderToString(Node root, ORDER order, StringBuilder stringRepresentation)
    { // preorder, inorder, and postorder traversal - check
        // If the node is empty/null
        if (root == null)
            // Quit function
            return;

        switch (order) {
            case PREORDER -> {
                // Print out the data of the node with a space
                stringRepresentation.append(root.getData());
                stringRepresentation.append(" ");
                // recur on the left leaf for preorder
                traverseTreeWithOrderToString(root.getLeftLeaf(), ORDER.PREORDER, stringRepresentation);
                // then recur on the right leaf
                traverseTreeWithOrderToString(root.getRightLeaf(), ORDER.PREORDER, stringRepresentation);
            }
            case INORDER -> {
                // recur on the left leaf first for inorder
                traverseTreeWithOrderToString(root.getLeftLeaf(), ORDER.INORDER, stringRepresentation);
                // Print out the data of the node with a space
                stringRepresentation.append(root.getData());
                stringRepresentation.append(" ");
                // then recur on the right leaf
                traverseTreeWithOrderToString(root.getRightLeaf(), ORDER.INORDER, stringRepresentation);
            }
            case POSTORDER -> {
                // recur on the left leaf then right leaf then print for postorder
                traverseTreeWithOrderToString(root.getLeftLeaf(), ORDER.POSTORDER, stringRepresentation);
                // then recur on the right leaf
                traverseTreeWithOrderToString(root.getRightLeaf(), ORDER.POSTORDER, stringRepresentation);
                // Print out the data of the node with a space
                stringRepresentation.append(root.getData());
                stringRepresentation.append(" ");
            }
        }
    }

    // Getters - check
    /**
     * Getter for the infix string
     * @return returns the infix string
     */
    public String getInfix() {
        return infix;
    }

    /**
     * Getter for the root node
     * @return returns the root node
     */
    public Node getRootNode() {
        return rootNode;
    }

    /* Setters not needed */

    /**
     * Checks if an object is equal to the tree. We define equal as having the
     * same nodes and elements. Since a tree is built from the postfix, if the
     * postfixes are equal then the nodes and elements are equal too.
     * @param o An object to test equality against
     * @return Returns whether the object is a Node and has the same elements and nodes
     */
    @Deprecated
    public boolean eequals(Object o) { // Overridden equals - check
        // If the object isn't also an expression tree
        if(o.getClass() != this.getClass())
            // It's not equal
            return false;
        // We're gonna check if they're equal if they have the same nodes & elements
        // Nodes and elements are created based on the postfix, so if the postfix's are equal,
        // then nodes, elements, and therefore, the tree is equal
        return infixToPostfix(infix).equals(infixToPostfix(((ExpressionTree)o).infix));
    }

    // OR If we strictly follow the pdf

    /**
     * Evaluates the equality of a tree based on equality of the node's elements
     * @param o The object we are testing
     * @return Returns true if all the elements of the root node in one tree are equal to that of another tree
     */
    @Override
    public boolean equals(Object o) { // Overridden equals - check
        // If the reference of the tree is the same as this one..
        if(this == o)
            // Then it's the same and all of its nodes will be the same
            return true;
        // If the object isn't also an expression tree
        if(o.getClass() != this.getClass())
            // It's not equal
            return false;
        // Use the Node class to evaluate equality between the root nodes.
        return this.rootNode.equals(((ExpressionTree) o).getRootNode());
    }

    /**
     * String representation of the tree. The class type, its infix, preorder, inorder, and postorder traversals
     * @return a string with the class type, infix, prefix, infix, and postfix via traversal
     */
    @Override
    public String toString() { // Overridden .toString - check
        // Create a StringBuilder for the output
        StringBuilder output = new StringBuilder();

        // Add the type to the output
        output.append("Type: ");
        output.append(getClass().getSimpleName());
        // Add the infix to the output
        output.append("\nInfix: ");
        output.append(infix);
        //System.out.print("Postfix: " + postfix);
        // Create a StringBuilder to be used by the traversal method
        StringBuilder builder = new StringBuilder();
        // Traver preorder and append it to the output
        traverseTreeWithOrderToString(getRootNode(), ORDER.PREORDER, builder);
        output.append("\nPreorder prefix: ");
        output.append(builder);
        builder.setLength(0); // Reset the builder
        // Traverse inorder and append it to the output
        traverseTreeWithOrderToString(getRootNode(), ORDER.INORDER, builder);
        output.append("\nInorder infix: ");
        output.append(builder);
        builder.setLength(0); // Reset the builder
        // Traverse postorder and append to the output
        traverseTreeWithOrderToString(getRootNode(), ORDER.POSTORDER, builder);
        output.append("\nPostorder postfix: ");
        output.append(builder);
        // Return the final output
        return output.toString();
    }

    /**
     * Helper function to determine if a string is an operator
     * @param string the input to test
     * @return true if the string is an operator (+, -, *, or /)
     */
    private boolean isStringOperator(String string) {
        // Remove all bookending whitespace
        string = string.trim();
        // Check if the string is a +, -, *, or /
        return (string.equals("+") || string.equals("-") || string.equals("*") || string.equals("/"));
    }

    /**
     * Helper function to determine if a character is an operator
     * @param character the char to test
     * @return true if the string is an operator (+, -, *, or /)
     */
    private boolean isCharacterOperator(char character) {
        // Check if the character is a +, -, *, or /
        return (character == '+' || character == '-' || character == '*' || character == '/');
    }

    /**
     * Helper debug function to make printing easier
     * @param s string to print
     */
    private void l(String s) {
        //System.out.println(s);
    }

}