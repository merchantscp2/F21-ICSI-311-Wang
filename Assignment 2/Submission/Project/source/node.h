// Generic node
template<typename T>
struct Node {
    T *data; // The data
    Node<T> *left, *right; // Its leaves
    Node<T>() = default; // default construcor
    explicit Node<T>(T data) { // construcor with data
        this->data = &data;
        left=right=NULL;
    }
};