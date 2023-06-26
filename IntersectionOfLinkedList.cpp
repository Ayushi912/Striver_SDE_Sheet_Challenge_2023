/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };

*****************************************************************/

Node* findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    Node *p1 = firstHead, *p2 = secondHead;
    while(p1 != p2)
    {
        p1 = p1 -> next;
        if(p1 == nullptr)
            p1 = secondHead;
        p2 = p2 -> next;
        if(p2 == nullptr)
            p2 = firstHead;
    }
    return p1;
}
