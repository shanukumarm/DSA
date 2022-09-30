//{ Driver Code Starts
// driver code

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool isLoop(Node* head)
{
    if(!head) return false;
    
    Node* fast = head->next;
    Node* slow = head;
    
    while( fast != slow)
    {
        if( !fast || !fast->next ) return false;
        fast=fast->next->next;
        slow=slow->next;
    }
    
    return true;
}

int length(Node* head)
{
    int ret = 0;
    while(head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}


// } Driver Code Ends
/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

class Solution
{
    void only_for_positive_numbers(Node* head)
    {
        Node* temp = head;
        Node* temp_pre;
        const int INT_MIN = 1000000009;
        
        while(temp)
        {
            if(temp->data > 0)
            {
                temp->data += INT_MIN;
                temp_pre = temp;
                temp = temp->next;
            }
            else
            {
                temp_pre->next = NULL;
                break;
            }
        }
        
        temp = head;
        while(temp)
        {
            temp->data -= INT_MIN;
            temp = temp->next;
        }
    }
    
    void remove(Node* head, Node* loop_node)
    {
        Node* iterator = loop_node->next;
        int k=0;
        while(iterator != loop_node)
        {
            iterator = iterator->next;
            k++;
        }
        
        iterator = head;
        Node* loop_iterator = head;
        while(k)
        {
            loop_iterator = loop_iterator->next;
            k--;
        }
        
        while(iterator != loop_iterator->next)
        {
            iterator = iterator->next;
            loop_iterator = loop_iterator->next;
        }
        loop_iterator->next = NULL;
    }
    
public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        
        // only_for_positive_numbers(head);
        
        Node* fast = head;
        Node* slow = head;
        
        while(slow && fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            
            if(fast == slow)
            {
                remove(head, slow);
                return;
            }
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        Solution ob;
        ob.removeLoop(head);
        
        if( isLoop(head) || length(head)!=n )
            cout<<"0\n";
        else
            cout<<"1\n";
    }
	return 0;
}

// } Driver Code Ends