// ---------------------------------------------------------
// Writes a list of objects.
// Precondition: The linked list is referenced by nextNode.
// Postcondition: The list is displayed. The linked list
// and nextNode are unchanged.
// ---------------------------------------------------------
  if (nextNode != null) {
    // write the first data object
    System.out.println(nextNode.item);
    // write the list minus its first node
    writeList(nextNode.next);
  }  // end if
}  // end writeList

Write the last character of string s
Write string s minus its last character backward

Write string s minus its first character backward
Write the first character of string s

Write the last node of the list
Write the list minus its last node backward

Write the list minus its first node backward
Write the first node of the list

private static void writeListBackward2(Node nextNode) {
// ----------------------------------------------------
// Writes a list of objects backwards.
// Precondition: The linked list is referenced by
// nextNode.
// Postcondition: The list is displayed backwards. The
// linked list and nextNode are unchanged.
// ----------------------------------------------------
  if (nextNode != null) {
    // write the list minus its first node backward
    writeListBackward2(nextNode.next);
    // write the data object in the first node
    System.out.println(nextNode.item);
  } // end if
}  // end writeListBackward2

private static Node insertRecursive(Node headNode,
                        java.lang.Comparable newItem) {
  if ( (headNode == null) ||
       (newItem.compareTo(headNode.item) < 0) ) {
    // base case: insert newItem at the beginning of the
    // linked list that nextNode references
    Node newNode = new Node(newItem, headNode);
    headNode = newNode;
  }
  else { //insert into rest of linked list
    Node nextNode = insertRecursive(headNode.next,newItem);
    headNode.next = nextNode;
  } // end if
  return headNode;
}  // end insertRecursive
package practice;

private static void writeList(Node nextNode) {

