//problem link: https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1

class Solution
{
    public:
    int carry=0;
    
    Node* reverse(Node *head){
        Node *prev=NULL;
        while(head!=NULL){
            Node *next=head->next;
            head->next=prev;
            prev=head;
            head=next;
        }
        return prev;
    }

    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        int carry=0;
        Node *curr1=reverse(first), *curr2=reverse(second);
        Node *prev=NULL, *head=NULL;
        while(curr1 || curr2 || carry){
            int sum=0;
            if(curr1){
                sum+=curr1->data;
                curr1=curr1->next;
            }
            if(curr2){
                sum+=curr2->data;
                curr2=curr2->next;
            }
            sum+=carry;
            carry=sum/10;
            Node *newNode=new Node(sum%10);
            if(prev==NULL){
                head=prev=newNode;
            }
            else{
                prev->next=newNode;
                prev=prev->next;
            }
        }
        return reverse(head);
    }
};