
/**
 *
 * @author Milan
 */
class DoublyLinkedList {

    private Node First;
    public int length;

    private class Node {

        private int data;
        private Node LPTR;
        private Node RPTR;

        public Node(int data) {
            this.data = data;
            LPTR = null;
            RPTR = null;
        }

        public int getData() {
            return data;
        }

        public void setData(int NewData) {
            data = NewData;
        }

        public void setLPTR(Node LPTR) {
            this.LPTR = LPTR;
        }

        public void setRPTR(Node RPTR) {
            this.RPTR = RPTR;
        }

        public Node getLPTR() {
            return LPTR;
        }

        public Node getRPTR() {
            return RPTR;
        }
    }

    public void insertNode(int index, int data) {
        if (index > length) {
            System.out.println("Cann't Insert at this index.");
            return;
        }
        Node node = new Node(data);

        if (First == null) {
            First = node;
        }
        if (index == 0) {
            node.setLPTR(null);
            node.setRPTR(First);
            First = node;
        } else {
            Node NewLeftNode = getNodeAtIndex(index - 1);
            Node NewRightNode = NewLeftNode.getRPTR().getRPTR();
            node.setLPTR(NewLeftNode);
            node.setRPTR(NewRightNode);
            NewLeftNode.setLPTR(node);
            NewRightNode.setRPTR(NewRightNode);
        }
        length++;
    }

    public Node deleteNode(int index) {
        if (index >= length) {
            System.out.println("Deletion Not Done!");
            return null;
        }

        Node DeleteNode = getNodeAtIndex(index);
        if (index == 0) {
            First = DeleteNode.getRPTR();
            First.setLPTR(null);
        } else {
            DeleteNode.LPTR.setRPTR(DeleteNode.RPTR);
            DeleteNode.RPTR.setLPTR(DeleteNode.LPTR);
        }

        length--;
        return DeleteNode;
    }

    public void updateNode(int index, int data) {
        Node ChangingNode = getNodeAtIndex(index);
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

    /*
    *
    *
    *       ALL THE PRIVATE METHOD FOR SUPPORT
    *
    * 
     */
    private Node getNodeAtIndex(int index) {
        if (index == 0) {
            return getNodeAtIndex(index, First, 0);
        }
        return null;
    }

    private Node getNodeAtIndex(int index, Node node, int CurrentIndex) {
        if (index == CurrentIndex) {
            return node;
        }
        return getNodeAtIndex(index, node.getLPTR(), CurrentIndex + 1);
    }

    private int getIndexOfNode(Node FindNode) {
        return getIndexOfNode(0, FindNode, First);
    }

    private int getIndexOfNode(int index, Node FindNode, Node CompareNode) {
        if (CompareNode.equals(FindNode)) {
            return index;
        }
        return getIndexOfNode(index + 1, FindNode, CompareNode.getLPTR());
    }

    private void printLinkedList(Node node) {
        if (node.getRPTR() == null) {
            System.out.println("||" + node.getData() + " |" + "null ||");
        } else {
            System.out.print("||" + node.LPTR + " |" + node.getData() + " |" + node.RPTR + " ||<--> ");
            printLinkedList(node.getRPTR());
        }
    }
}

public class Doubly_LinkedList {

    public static void main(String[] args) {
        DoublyLinkedList Linked_List = new DoublyLinkedList();

        Linked_List.insertNode(0, 10);
        Linked_List.insertNode(1, 20);
        Linked_List.insertNode(1, 30);
        Linked_List.insertNode(2, 40);
        Linked_List.insertNode(3, 50);

        Linked_List.printLinkedList();
//
//        Linked_List.printLinkedList();
//
//        Linked_List.insertNode(0, 5);
//        Linked_List.insertNode(0, 40);
//        Linked_List.insertNode(0, 30);
//        Linked_List.insertNode(0, 20);
//        Linked_List.insertNode(0, 10);
//        Linked_List.printLinkedList();
//
//        //Linked_List.insertNode(3, 10);
//        Linked_List.printLinkedList();
//        System.out.println("-------");
//        Linked_List.deleteNode(5);
//        Linked_List.printLinkedList();
//        System.out.println("-------");
////Linked_List.updateNode(2, 25);
//        Linked_List.printLinkedList();
//
//        System.out.println("Length of LinkedList is: " + Linked_List.length);
//        System.out.println("First node in Linked_list: " + Linked_List.getFirstNode());
//        Linked_List.insertNode(3, 600);
//        Linked_List.printLinkedList();
//
//        //  System.out.println("Last node in Linked_list: " + Linked_List.getLastNode());
    }
}
