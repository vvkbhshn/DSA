/problem link: https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

class Solution
{
    public:
    bool carry1=true;
    
    void solve(Node *head){
        if(head==NULL) return;
        addOne(head->next);
        if(carry1){
            if(head->data==9) head->data=0;
            else{
                head->data++;
                carry1=false;
            }
        }
        else return;
    }
    
    Node* addOne(Node *head) 
    {
        if(head==NULL) return NULL;
        solve(head);
        if(head->data==0){
            Node *temp=new Node(1);
            temp->next=head;
            head=temp;
        }
        return head;
    }
};