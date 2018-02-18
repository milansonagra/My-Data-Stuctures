
/**
 *
 * @author Milan
 */
class SinglyLinkedList {

    private Node First;
    public int length;

    private class Node {

        private int data;
        private Node Pointer;

        public Node(int data) {
            this.data = data;
            Pointer = null;
        }

        public int getData() {
            return data;
        }

        public void setData(int NewData) {
            data = NewData;
        }

        public void setPointer(Node Pointer) {
            this.Pointer = Pointer;
        }

        public Node getPointer() {
            return Pointer;
        }
    }

    public void insertNode(int index, int data) {
        length++;

        Node node = new Node(data);
        if (index == 0) {
            node.setPointer(First);
            First = node;
        } else {
            Node PrivousNode = nodeOfIndex(index - 1);
            node.setPointer(PrivousNode.getPointer());
            PrivousNode.setPointer(node);
        }
    }

    public Node deleteNode(int index) {
        length--;

        Node DeleteNode;

        if (index == 0) {
            DeleteNode = nodeOfIndex(index);
            First = DeleteNode.getPointer();
        } else {
            Node BeforeDeleteNode = nodeOfIndex(index - 1);
            DeleteNode = BeforeDeleteNode.getPointer();
            BeforeDeleteNode.setPointer(DeleteNode.getPointer());
        }

        return DeleteNode;
    }

    public void updateNode(int index, int data) {
        Node ChangingNode = nodeOfIndex(index);
        ChangingNode.setData(data);
    }

    public void printLinkedList() {
        if (First == null) {
            System.out.println("Linked List is empty!");
        } else {
            printLinkedList(First);
        }
    }

    public int getFirstNode() {
        return First.getData();
    }

    public int getLastNode() {
        return this.nodeOfIndex(length - 1).getData();
    }

    /*
    *
    *
    *       ALL THE PRIVATE METHOD FOR SUPPORT
    *
    * 
     */
    private Node nodeOfIndex(int index) {
        if (First != null) {
            return nodeOfIndex(index, First, 0);
        }
        return null;
    }

    private Node nodeOfIndex(int index, Node node, int CurrentIndex) {
        if (index == CurrentIndex) {
            return node;
        }
        return nodeOfIndex(index, node.getPointer(), CurrentIndex + 1);
    }

    private int indexOfNode(Node FindNode) {
        return indexOfNode(0, FindNode, First);
    }

    private int indexOfNode(int index, Node FindNode, Node CompareNode) {
        if (CompareNode.getData() == FindNode.getData()) {
            return index;
        }
        return indexOfNode(index + 1, FindNode, CompareNode.getPointer());
    }

    private void printLinkedList(Node node) {
        if (node.getPointer() == null) {
            System.out.println("||" + node.getData() + " |" + "null ||");
        } else {
            System.out.print("||" + node.getData() + " |" + (node.getPointer()) + " ||--> ");
            printLinkedList(node.getPointer());
        }
    }
}

public class Singly_LinkedList {

    public static void main(String[] args) {
        SinglyLinkedList Linked_List = new SinglyLinkedList();

        Linked_List.printLinkedList();

        Linked_List.insertNode(0, 5);
        Linked_List.insertNode(0, 4);
        Linked_List.insertNode(0, 3);
        Linked_List.insertNode(0, 2);
        Linked_List.insertNode(0, 1);
        Linked_List.printLinkedList();

        Linked_List.insertNode(4, 10);
        Linked_List.printLinkedList();

        Linked_List.deleteNode(0);
        Linked_List.printLinkedList();

        Linked_List.updateNode(2, 20);
        Linked_List.printLinkedList();

        System.out.println("Length of LinkedList is: " + Linked_List.length);

        System.out.println("First node in Linked_list: " + Linked_List.getFirstNode());

        System.out.println("Last node in Linked_list: " + Linked_List.getLastNode());
    }
}
