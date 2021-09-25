package merchant.amit.assignment1;

/**
 * Generic Node class. Holds two leaves will be used to build binary tree
 * @param <T> A generic type which is the root data for the node
 * @author Amit Merchant
 * @version 0.0.0.01
 */
public class Node<T> { // Generic class - check

    // Class fields
    private T data; // generic element - Check
    private Node<T> leftLeaf;
    private Node<T> rightLeaf;

    /**
     * Creates a new instance of Node where all data is null, default constructor
     */
    public Node() {

    }

    /**
     * Creates a new instance of Node and set it's data
     * @param data The data to store in the Node
     */
    public Node(T data) { // Overloaded constructor - Check
        this.data = data;
    }

    // Getters and setters - check
    /**
     * Setter for the data
     * @param data The node's data
     */
    public void setData(T data) {
        this.data = data;
    }

    /**
     * Sets the left leaf
     * @param leftLeaf a Node which will be linked as the left leaf
     */
    public void setLeftLeaf(Node<T> leftLeaf) {
        this.leftLeaf = leftLeaf;
    }

    /**
     * Setter for the right leaf
     * @param rightLeaf a Node which will be linked as the right leaf
     */
    public void setRightLeaf(Node<T> rightLeaf) {
        this.rightLeaf = rightLeaf;
    }

    /**
     * Getter for the data field
     * @return the data field
     */
    public T getData() {
        return data;
    }

    /**
     * Getter for the left leaf
     * @return the node which is the left leaf
     */
    public Node<T> getLeftLeaf() {
        return leftLeaf;
    }

    /**
     * Getter for the right leaf
     * @return the node which is the right leaf
     */
    public Node<T> getRightLeaf() {
        return rightLeaf;
    }

    /**
     * Helper method for equals to do recurrence on two nodes
     * @param node1 the node we're checking against
     * @param node2 the node to check
     * @return Whether every data in each node contains the same value
     */
    private boolean isEqual(Node node1, Node node2) {
        // Check if they're the same reference. If they are, then all of their following nodes will be equal
        if (node1 == node2) {
            return true;
        }
        // Check if either is null. If there is no node, it's not equal to anything
        if (node1 == null || node2 == null) {
            return false;
        }
        // recursion to check if the data is equal for each node and their subsequent leaves
        return node1.getData().equals(node2.getData()) &&
                isEqual(node1.getLeftLeaf(), node2.getLeftLeaf()) &&
                isEqual(node1.getRightLeaf(), node2.getRightLeaf());
    }

    /**
     * Checks equality of the node and another node
     * @param o the node we're comparing with
     * @return returns true if both nodes contain the same values in subleaf tree
     */
    @Override
    public boolean equals(Object o) { // Overridden .equals - check
        // A node is equal to another node first if its a node
        if(o.getClass() != this.getClass()) {
            // If they're not both nodes, they can't be equal
            return false;
        }

        // Call helper function to do recurrence check on this node and the node we're checking
        return isEqual(this, (Node)o);
    }

    /**
     * A string representation of the Node
     * @return a json string representing the instance
     */
    @Override
    public String toString() { // Overridden .toString - check
        return "Node{" +
                "data=" + data +
                ", leftLeaf=" + leftLeaf.getClass().getSimpleName() +
                ", rightLeaf=" + rightLeaf.getClass().getSimpleName() +
                '}';
    }
}